all: crex

crex: main.o crex.o ansi_escape_codes.o
	${CXX} ${LDFLAGS} -o crex main.o crex.o ansi_escape_codes.o ${LIBS}

install:
	${BSD_INSTALL_PROGRAM} crex ${DESTDIR}${PREFIX}/bin
