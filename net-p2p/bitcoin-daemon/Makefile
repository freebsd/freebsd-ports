MASTERDIR=	${.CURDIR}/../bitcoin
PKGNAMESUFFIX=	-daemon

COMMENT=	Virtual Peer-to-Peer Currency (Daemon)

SLAVE_PORT=	yes

OPTIONS_DEFINE=		DEBUG HARDENING TESTS UPNP WALLET ZMQ
OPTIONS_DEFAULT=	HARDENING UPNP WALLET ZMQ

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

PORTREVISION=	0

post-install:
	${INSTALL_DATA} ${FILESDIR}/bitcoin.conf ${STAGEDIR}${PREFIX}/etc/bitcoin.conf.sample

.include "${MASTERDIR}/Makefile"
