# $FreeBSD$

LIB = 	domainkeys
SRCS=	dns_txt.c domainkeys.c dktrace.c
INCS=	domainkeys.h dktrace.h

SHLIB_MAJOR=	%%SHLIB_MAJOR%%

LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include
CFLAGS+=	-DBIND_8_COMPAT -I${OPENSSLBASE}/include
LDFLAGS+=	-lcrypto -L${OPENSSLBASE}/lib

NO_PROFILE=

makeheader: makeheader.c

domainkeys.h: domainkeys.c makeheader
	./makeheader <domainkeys.c >domainkeys.h

.include <bsd.lib.mk>
