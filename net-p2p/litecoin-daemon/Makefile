# $FreeBSD$

MASTERDIR=	${.CURDIR}/../litecoin
PKGNAMESUFFIX=	-daemon

COMMENT=	Virtual Peer-to-Peer Currency (Daemon)

SLAVE_PORT=	yes

NOT_FOR_ARCHS=		powerpc64 sparc64
NOT_FOR_ARCHS_REASON=	configure: error: Big Endian not supported

USES+=		cpe
CPE_VENDOR=	bitcoin
CPE_PRODUCT=	bitcoind
CPE_VERSION=	${PORTVERSION:R}

OPTIONS_DEFINE=		DEBUG HARDENING TESTS UPNP WALLET
OPTIONS_DEFAULT=	HARDENING WALLET

CONFIGURE_ARGS=	--with-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-utils \
		--disable-reduce-exports

PLIST_FILES=	bin/litecoind

.include "${MASTERDIR}/Makefile"
