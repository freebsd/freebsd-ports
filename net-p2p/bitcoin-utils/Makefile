# $FreeBSD$

MASTERDIR=	${.CURDIR}/../bitcoin
PKGNAMESUFFIX=	-utils

COMMENT=	Virtual Peer-to-Peer Currency (CLI and Utilities)
SLAVE_PORT=	yes

OPTIONS_DEFINE=		DEBUG HARDENING TESTS
OPTIONS_DEFAULT=	HARDENING TESTS

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	does not support big-endian architectures

CONFIGURE_ARGS=	--without-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--without-miniupnpc \
		--with-utils \
		--disable-wallet

PLIST_FILES=	bin/bitcoin-cli bin/bitcoin-tx \
		man/man1/bitcoin-cli.1.gz man/man1/bitcoin-tx.1.gz

.include "${MASTERDIR}/Makefile"
