# $FreeBSD$

LIB = 	domainkeys
SRCS=	dns_txt.c domainkeys.c
INCS=	domainkeys.h

SHLIB_MAJOR=	%%SHLIB_MAJOR%%

LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include
CFLAGS+=	-DBIND_8_COMPAT -I${OPENSSLBASE}/include
#LIBS+=		-lcrypto -L${OPENSSLBASE}/lib

makeheader: makeheader.c

domainkeys.h: domainkeys.c makeheader
	./makeheader <domainkeys.c >domainkeys.h

.include <bsd.lib.mk>
