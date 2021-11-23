MASTERDIR=	${.CURDIR}/../namecoin

PKGNAMESUFFIX=	-utils

COMMENT=	Decentralized, open DNS and more (CLI and Utilities)
SLAVE_PORT=	yes

CONFLICTS_INSTALL=	namecoin-stable namecoin-stable-daemon namecoin-stable-utils \
		namecoin-beta namecoin-beta-daemon namecoin-beta-utils

OPTIONS_DEFINE=		DEBUG HARDENING TESTS
OPTIONS_DEFAULT=	HARDENING TESTS

CONFIGURE_ARGS=	--without-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--with-utils \
		--disable-wallet \
		--disable-man

PLIST_FILES=	bin/namecoin-cli bin/namecoin-tx

.include "${MASTERDIR}/Makefile"
