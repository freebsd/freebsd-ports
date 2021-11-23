MASTERDIR=	${.CURDIR}/../namecoin

PKGNAMESUFFIX=	-daemon

COMMENT=	Decentralized, open DNS and more (Daemon)
SLAVE_PORT=	yes

CONFLICTS_INSTALL=	namecoin-stable namecoin-stable-daemon namecoin-stable-utils \
		namecoin-beta namecoin-beta-daemon namecoin-beta-utils

OPTIONS_DEFINE=		DEBUG HARDENING TESTS UPNP WALLET ZMQ
OPTIONS_DEFAULT=	HARDENING UPNP WALLET

CONFIGURE_ARGS=	--with-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-utils \
		--disable-man

PLIST_FILES=	bin/namecoind

USE_RC_SUBR=	namecoind

.include "${MASTERDIR}/Makefile"
