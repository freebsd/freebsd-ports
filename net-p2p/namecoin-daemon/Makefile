MASTERDIR=	${.CURDIR}/../namecoin

PORTREVISION=	2
PKGNAMESUFFIX=	-daemon

COMMENT=	Decentralized, open DNS and more (Daemon)
SLAVE_PORT=	yes

OPTIONS_DEFINE=		DEBUG HARDENING TESTS UPNP WALLET ZMQ
OPTIONS_DEFAULT=	HARDENING UPNP WALLET

USERS=          namecoin
GROUPS=		namecoin

CONFIGURE_ARGS=	--with-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-utils \
		--disable-man

PLIST_FILES=	bin/namecoind \
		"@sample %%ETCDIR%%.conf.sample"

USE_RC_SUBR=	namecoind

post-install:
	${INSTALL_DATA} ${FILESDIR}/namecoin.conf ${STAGEDIR}${PREFIX}/etc/namecoin.conf.sample

.include "${MASTERDIR}/Makefile"
