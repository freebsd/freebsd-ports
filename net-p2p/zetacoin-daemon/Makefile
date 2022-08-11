MASTERDIR=	${.CURDIR}/../zetacoin
PORTREVISION=	1
PKGNAMESUFFIX=	-daemon

COMMENT=	Peer-to-Peer crypto currency with quick transactions (Daemon)

SLAVE_PORT=	yes

RUN_DEPENDS+=	zetacoin-cli:net-p2p/zetacoin-utils

OPTIONS_DEFINE=		DEBUG HARDENING TESTS UPNP ZMQ
# WALLET_BDBMODERN is a choice for WALLET, introduced via OPTIONS_RADIO=WALLET
# from ${MASTERDIR}/Makefile
OPTIONS_DEFAULT=	HARDENING UPNP WALLET_BDBMODERN ZMQ

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

CONFIGURE_ARGS=	--with-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-utils

PLIST_FILES=	bin/${PORTNAME}d \
		"@sample %%ETCDIR%%.conf.sample"

USE_RC_SUBR=	${PORTNAME}
SUB_LIST+=	PORTNAME=${PORTNAME}
SUB_FILES=	pkg-message

post-install:
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include "${MASTERDIR}/Makefile"
