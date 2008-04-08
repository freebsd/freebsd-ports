

german.hash:
	gmake ispell/de_DE.aff ispell/de_DE.hash
	cp ispell/de_DE.hash german.hash
	cp ispell/de_DE.aff german.aff

install:
	gmake install

