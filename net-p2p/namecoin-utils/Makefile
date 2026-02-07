MASTERDIR=	${.CURDIR}/../namecoin

PORTREVISION=	2
PKGNAMESUFFIX=	-utils

COMMENT=	Decentralized, open DNS and more (CLI and Utilities)
SLAVE_PORT=	yes

OPTIONS_DEFINE=		DEBUG HARDENING TESTS
OPTIONS_DEFAULT=	HARDENING TESTS

CONFIGURE_ARGS=	--without-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--with-utils \
		--disable-wallet \
		--disable-man

PLIST_FILES=	bin/namecoin-cli bin/namecoin-tx bin/namecoin-util

.include "${MASTERDIR}/Makefile"
