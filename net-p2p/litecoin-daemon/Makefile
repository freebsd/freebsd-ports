# $FreeBSD$

MASTERDIR=	${.CURDIR}/../litecoin
PKGNAMESUFFIX=	-daemon

COMMENT=	Virtual Peer-to-Peer Currency (Daemon)

SLAVE_PORT=	yes

NOT_FOR_ARCHS=		powerpc powerpc64 sparc64
NOT_FOR_ARCHS_REASON=	configure: error: Big Endian not supported

OPTIONS_DEFINE=		DEBUG HARDENING TESTS UPNP ZMQ
# WALLET_BDBMODERN is a choice for WALLET, introduced via OPTIONS_RADIO=WALLET
# from ${MASTERDIR}/Makefile
OPTIONS_DEFAULT=	HARDENING UPNP WALLET_BDBMODERN ZMQ

USES+=		cpe
CPE_VENDOR=	bitcoin
CPE_PRODUCT=	bitcoind
CPE_VERSION=	${PORTVERSION:R}

USERS=		litecoin
GROUPS=		litecoin

CONFIGURE_ARGS=	--with-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-utils

PLIST_FILES=	bin/litecoind
PLIST_FILES+=	man/man1/litecoind.1.gz
PLIST_FILES+=	"@sample etc/litecoin.conf.sample"

USE_RC_SUBR=	litecoind

post-install:
	${INSTALL_DATA} ${WRKSRC}/share/examples/litecoin.conf ${STAGEDIR}${PREFIX}/etc/litecoin.conf.sample

.include "${MASTERDIR}/Makefile"
