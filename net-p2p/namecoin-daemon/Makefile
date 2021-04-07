MASTERDIR=	${.CURDIR}/../namecoin

PKGNAMESUFFIX=	-daemon

COMMENT=	Decentralized, open DNS and more (Daemon)
SLAVE_PORT=	yes

CONFLICTS_INSTALL=	namecoin-stable-[0-9]* namecoin-stable-daemon-[0-9]* namecoin-stable-utils-[0-9]* \
		namecoin-beta-[0-9]* namecoin-beta-daemon-[0-9]* namecoin-beta-utils-[0-9]*

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
