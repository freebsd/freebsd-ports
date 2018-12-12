# $FreeBSD$

MASTERDIR=	${.CURDIR}/../bitcoin
PORTREVISION=	4
PKGNAMESUFFIX=	-daemon

COMMENT=	Virtual Peer-to-Peer Currency (Daemon)

SLAVE_PORT=	yes

NOT_FOR_ARCHS=		powerpc powerpc64 sparc64
NOT_FOR_ARCHS_REASON=	does not support big-endian architectures

OPTIONS_DEFINE=		DEBUG HARDENING TESTS UPNP ZMQ
# WALLET_BDBMODERN is a choice for WALLET, introduced via OPTIONS_RADIO=WALLET
# from ${MASTERDIR}/Makefile
OPTIONS_DEFAULT=	HARDENING UPNP WALLET_BDBMODERN

USERS=		bitcoin
GROUPS=		bitcoin

CONFIGURE_ARGS=	--with-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-utils

PLIST_FILES=	bin/bitcoind \
		man/man1/bitcoind.1.gz \
		"@sample %%ETCDIR%%.conf.sample"

USE_RC_SUBR=	bitcoind

post-install:
	${INSTALL_DATA} ${FILESDIR}/bitcoin.conf ${STAGEDIR}${PREFIX}/etc/bitcoin.conf.sample

.include "${MASTERDIR}/Makefile"
