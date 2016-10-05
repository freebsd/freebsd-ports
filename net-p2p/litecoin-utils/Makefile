# $FreeBSD$

MASTERDIR=	${.CURDIR}/../litecoin
PKGNAMESUFFIX=	-utils

COMMENT=	Virtual Peer-to-Peer Currency (CLI and Utilities)

SLAVE_PORT=	yes

BROKEN_powerpc64=	Does not build
BROKEN_sparc64=		Does not build

OPTIONS_DEFINE=		DEBUG HARDENING TESTS
OPTIONS_DEFAULT=	HARDENING TESTS

CONFIGURE_ARGS=	--without-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--with-utils \
		--disable-wallet \
		--disable-reduce-exports

PLIST_FILES=	bin/litecoin-cli bin/litecoin-tx

.include "${MASTERDIR}/Makefile"
