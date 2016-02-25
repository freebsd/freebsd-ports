# $FreeBSD$

LIB = 	domainkeys
SRCS=	dns_txt.c domainkeys.c dktrace.c
INCS=	domainkeys.h dktrace.h

LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include
CFLAGS+=	-DBIND_8_COMPAT -I${OPENSSLBASE}/include
LDFLAGS+=	-lcrypto -L${OPENSSLBASE}/lib

NO_PROFILE=

makeheader: makeheader.c
	${CC} ${CFLAGS} makeheader.c -o makeheader

domainkeys.h: domainkeys.c makeheader
	./makeheader <domainkeys.c >domainkeys.h

.include <bsd.lib.mk>
