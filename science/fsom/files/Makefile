
# Use ?= to allow overriding from the env or command-line, e.g.
#
#       make CXXFLAGS="-O3 -fPIC" install
#
# Package managers will override many of these variables automatically, so
# this is aimed at making it easy to create packages (Debian packages,
# FreeBSD ports, MacPorts, pkgsrc, etc.)

CXX ?=		g++
CXXFLAGS ?=	-w -O3 -pipe -fomit-frame-pointer -ffast-math
AR ?=		ar
MKDIR ?=	mkdir
STRIP ?=	strip
DESTDIR ?=	stage
PREFIX ?=	/usr/local

BIN =	fsom
LIB =	libfsom.a
OBJS =	fsom.o split.o
MAIN =	main.o

all:	${BIN} ${LIB}

${BIN}:	${OBJS} ${MAIN}
	${CXX} -o fsom ${OBJS} ${MAIN} -lm

${LIB}:	${OBJS}
	${AR} -rs ${LIB} ${OBJS}

fsom.o:	fsom.c
	${CXX} ${CXXFLAGS} -c fsom.c

split.o: split.cpp
	${CXX} ${CXXFLAGS} -c split.cpp

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

install: all
	${MKDIR} -p ${DESTDIR}${PREFIX}/bin
	${MKDIR} -p ${DESTDIR}${PREFIX}/include/fsom
	${MKDIR} -p ${DESTDIR}${PREFIX}/lib
	${INSTALL} ${BIN} ${DESTDIR}${PREFIX}/bin
	${INSTALL} *.h ${DESTDIR}${PREFIX}/include/fsom
	${INSTALL} ${LIB} ${DESTDIR}${PREFIX}/lib

install-strip: install
	${STRIP} ${DESTDIR}${PREFIX}/bin/${BIN}

clean:
	rm -rf *.o ${BIN} ${LIB} ${DESTDIR}
