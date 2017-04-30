# $FreeBSD$

MASTERDIR=	${.CURDIR}/../litecoin
PKGNAMESUFFIX=	-utils

COMMENT=	Virtual Peer-to-Peer Currency (CLI and Utilities)

SLAVE_PORT=	yes

NOT_FOR_ARCHS=		powerpc64 sparc64
NOT_FOR_ARCHS_REASON=	configure: error: Big Endian not supported

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
