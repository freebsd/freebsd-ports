
# Use ?= to allow overriding from the env or command-line, e.g.
#
#       make CXXFLAGS="-O3 -fPIC" install
#
# Package managers will override many of these variables automatically, so
# this is aimed at making it easy to create packages (Debian packages,
# FreeBSD ports, MacPorts, pkgsrc, etc.)

CC ?=		cc
CFLAGS ?=	-O -g
AR ?=		ar
MKDIR ?=	mkdir
INSTALL ?=	install -c
STRIP ?=	strip
DESTDIR ?=	stage
PREFIX ?=	/usr/local

OBJS=	filevercmp.o
MAIN =	main.o
BIN =	filevercmp
LIB =	libfilevercmp.a

all: ${BIN} ${LIB}

${BIN}: ${OBJS} ${MAIN}
	${CC} ${CFLAGS} -o ${BIN} ${OBJS} ${MAIN}

${LIB}: ${OBJS}
	${AR} -rs ${LIB} ${OBJS}

install: all
	${MKDIR} -p ${DESTDIR}${PREFIX}/bin
	${MKDIR} -p ${DESTDIR}${PREFIX}/include
	${MKDIR} -p ${DESTDIR}${PREFIX}/lib
	${INSTALL} ${BIN} ${DESTDIR}${PREFIX}/bin
	${INSTALL} *.h ${DESTDIR}${PREFIX}/include
	${INSTALL} ${LIB} ${DESTDIR}${PREFIX}/lib

install-strip: install
	${STRIP} ${DESTDIR}${PREFIX}/bin/${BIN}

clean:
	rm -rf ${BIN} ${LIB} ${OBJS} ${MAIN} ${DESTDIR}

.PHONY: all clean

filevercmp.o: filevercmp.c filevercmp.h
	${CC} ${CFLAGS} -c filevercmp.c

main.o: main.c filevercmp.h
	${CC} ${CFLAGS} -c main.c
