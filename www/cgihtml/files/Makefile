# $FreeBSD$
# Makefile for cgihtml libraries

LIB = cgihtml
MAJ = 1
SHLIB_VER = $(MAJ)

OBJS = string-lib.o cgi-llist.o cgi-lib.o html-lib.o
HDRS =	${OBJS:.o=.h}
SRCS =	${OBJS:.o=.c}
SOBJS =	${OBJS:.o=.so}

.SUFFIXES:
.SUFFIXES: .o .so .c

.c.o:
	${CC} ${CFLAGS} -c ${.IMPSRC} -o ${.TARGET}
	@${LD} -O ${.TARGET} -x -r ${.TARGET}

.c.so:
	${CC} -fpic -DPIC ${CFLAGS} -c ${.IMPSRC} -o ${.TARGET}
	@${LD} -O ${.TARGET} -x -r ${.TARGET}

lib${LIB}.a: ${OBJS}
	@${ECHO} building standard ${LIB} library
	@rm -f ${.TARGET}
	@${AR} cr ${.TARGET} `lorder ${OBJS} | tsort -q`
	${RANLIB} ${.TARGET}

lib${LIB}.so.${SHLIB_VER}: ${SOBJS}
	@${ECHO} building shared ${LIB} library \(version ${SHLIB_VER}\)
	@rm -f ${.TARGET}
	${CC} -shared -Wl,-x -o ${.TARGET} `lorder ${SOBJS} | tsort -q`

all: depend lib${LIB}.a lib${LIB}.so.${SHLIB_VER}

install:
	@mkdir -p $(DESTDIR)${PREFIX}/lib
	@mkdir -p $(DESTDIR)${PREFIX}/include
	${INSTALL} -c -m 644 lib${LIB}.a $(DESTDIR)${PREFIX}/lib
#	${RANLIB} -t ${PREFIX}/lib/lib${LIB}.a
	${INSTALL} -c -m 644 lib${LIB}.so.${SHLIB_VER} $(DESTDIR)${PREFIX}/lib
	@ln -s lib${LIB}.so.${SHLIB_VER} $(DESTDIR)${PREFIX}/lib/lib${LIB}.so
.for file in ${HDRS}
	${INSTALL} -c -m 644 ${file} $(DESTDIR)${PREFIX}/include
.endfor

clean:
	rm -f *.o *.so lib${LIB}.a lib${LIB}.so.${SHLIB_VER}

distclean: clean
	rm -f .depend

depend:
	mkdep ${CFLAGS} ${SRCS}

