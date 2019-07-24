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

OPTIONS_DEFINE=		DEBUG HARDENING TESTS UPNP WALLET ZMQ
OPTIONS_DEFAULT=	HARDENING WALLET ZMQ

USERS=		litecoin
GROUPS=		litecoin

CONFIGURE_ARGS=	--with-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-utils \
		--disable-reduce-exports

PLIST_FILES=	bin/litecoind
PLIST_FILES+=	man/man1/litecoind.1.gz
PLIST_FILES+=	"@sample etc/litecoin.conf.sample"

USE_RC_SUBR=	litecoind

post-install:
	${INSTALL_DATA} ${WRKSRC}/contrib/debian/examples/bitcoin.conf ${STAGEDIR}${PREFIX}/etc/litecoin.conf.sample

.include "${MASTERDIR}/Makefile"
