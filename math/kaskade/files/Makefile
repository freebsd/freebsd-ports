# $FreeBSD$

all:
	cd minigraph && $(MAKE)
	cd sources && $(MAKE)

install:
	$(BSD_INSTALL_PROGRAM) sources/k6-freebsd-cc $(PREFIX)/bin/k6
