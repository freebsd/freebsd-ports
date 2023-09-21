PORTREVISION=	0
CATEGORIES=	net devel
PKGNAMESUFFIX=	-${LIBPROXY_SLAVE}

COMMENT=	Duktape JavaScript plug-in for libproxy

LIB_DEPENDS+=	libduktape.so:lang/duktape-lib

LIBPROXY_SLAVE=	duktape
MASTERDIR=	${.CURDIR}/../libproxy

.include "${MASTERDIR}/Makefile"
