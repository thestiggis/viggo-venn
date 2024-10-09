def les_tekstfil(filnavn):
    ord_dict = {}  # Dictionary for å lagre ord og linjenummer
    with open(filnavn, 'r', encoding='utf-8') as fil:
        for linjenummer, linje in enumerate(fil, start=1):  # Går gjennom hver linje og teller linjenumre
            ord_liste = linje.split()  # Deler linja opp i ord
            for ord in ord_liste:
                ord = ord.lower().strip(",.!?\"':;")  # Normaliserer ord ved å gjøre de små bokstaver og fjerne tegnsetting
                if ord not in ord_dict:
                    ord_dict[ord] = linjenummer  # Registrerer ordet første gang det forekommer
    
    return ord_dict


def skriv_ut_ord_og_linjenummer(ord_dict):
    for ord, linjenummer in ord_dict.items():
        print(f"Ordet '{ord}' forekommer først på linje {linjenummer}")


# Brukerfunksjon for å kjøre programmet
if __name__ == "__main__":
    filnavn = 'DAT120 oving 1 intro til programmering.txt'  # Bytt til riktig filnavn her
    ord_dict = les_tekstfil(filnavn)
    skriv_ut_ord_og_linjenummer(ord_dict)
