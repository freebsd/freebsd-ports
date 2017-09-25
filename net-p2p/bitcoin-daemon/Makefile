# $FreeBSD$

MASTERDIR=	${.CURDIR}/../bitcoin
PORTREVISION=	2
PKGNAMESUFFIX=	-daemon

COMMENT=	Virtual Peer-to-Peer Currency (Daemon)

SLAVE_PORT=	yes

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	does not support big-endian architectures

OPTIONS_DEFINE=		DEBUG HARDENING TESTS UPNP WALLET ZMQ
OPTIONS_DEFAULT=	HARDENING UPNP WALLET

USERS=		bitcoin
GROUPS=		bitcoin

CONFIGURE_ARGS=	--with-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-utils

PLIST_FILES=	bin/bitcoind \
		man/man1/bitcoind.1.gz

USE_RC_SUBR=	bitcoind

post-install:
	${INSTALL_DATA} ${WRKSRC}/contrib/debian/examples/bitcoin.conf ${STAGEDIR}${PREFIX}/etc/bitcoin.conf.sample

.include "${MASTERDIR}/Makefile"
