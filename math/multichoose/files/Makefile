
# Use ?= to allow overriding from the env or command-line, e.g.
#
#       make CXXFLAGS="-O3 -fPIC" install
#
# Package managers will override many of these variables automatically, so
# this is aimed at making it easy to create packages (Debian packages,
# FreeBSD ports, MacPorts, pkgsrc, etc.)

CC ?=		cc
CXX ?=		c++
DESTDIR ?=	stage
PREFIX ?=	/usr/local
MKDIR ?=	mkdir
INSTALL ?=	install -c
STRIP ?=	strip
AR ?=		ar

BINS =	multichoose cmultichoose multipermute

all: ${BINS}

#multichoose_recursive: multichoose_recursive.cpp
#	${CXX} multichoose_recursive.cpp -o multichoose_recursive

multichoose: multichoose.cpp multichoose.h
	${CXX} multichoose.cpp -o multichoose

multipermute: multipermute.cpp multipermute.h
	${CXX} multipermute.cpp -o multipermute

cmultichoose: multichoose.c
	${CC} multichoose.c -o cmultichoose

install: all
	${MKDIR} -p ${DESTDIR}${PREFIX}/bin
	${MKDIR} -p ${DESTDIR}${PREFIX}/include/multichoose
	${INSTALL} ${BINS} ${DESTDIR}${PREFIX}/bin
	${INSTALL} *.py ${DESTDIR}${PREFIX}/bin
	${INSTALL} *.h ${DESTDIR}${PREFIX}/include/multichoose

install-strip: install
	${STRIP} ${DESTDIR}${PREFIX}/bin/*e

clean:
	rm -rf ${BINS} ${DESTDIR}
