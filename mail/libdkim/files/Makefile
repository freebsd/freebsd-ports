# $FreeBSD$

LIB = 	dkim
SRCS=	dkim.cpp dns.cpp dkimbase.cpp dkimsign.cpp dkimverify.cpp
INCS=	dkim.h

SHLIB_MAJOR=	%%SHLIB_MAJOR%%

LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include
CXXFLAGS+=	-DOPENSSL_FIPS -I${OPENSSLINC}
LDFLAGS+=	-lcrypto -L${OPENSSLLIB}

MK_PROFILE=	no

.include <bsd.lib.mk>
