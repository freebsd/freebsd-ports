# $FreeBSD$

LIB = 	domainkeys
SRCS=	dns_txt.c domainkeys.c dktrace.c
INCS=	domainkeys.h dktrace.h

LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include
CFLAGS+=	-DBIND_8_COMPAT -I${OPENSSLBASE}/include
LDFLAGS+=	-lcrypto -L${OPENSSLBASE}/lib

MK_PROFILE=	no

dktest: dktest.c
	${CC} ${CFLAGS} -I. dktest.c -o dktest libdomainkeys.a ${LDFLAGS}

check: dktest
	./test

makeheader: makeheader.c
	${CC} ${CFLAGS} makeheader.c -o makeheader

domainkeys.h: domainkeys.c makeheader
	./makeheader <domainkeys.c >domainkeys.h

.include <bsd.lib.mk>
