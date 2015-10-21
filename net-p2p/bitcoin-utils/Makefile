# $FreeBSD$

MASTERDIR=	${.CURDIR}/../bitcoin
PORTREVISION=	0
PKGNAMESUFFIX=	-utils

COMMENT=	Virtual Peer-to-Peer Currency (CLI and Utilities)
SLAVE_PORT=	yes

OPTIONS_DEFINE=		DEBUG HARDENING TESTS
OPTIONS_DEFAULT=	HARDENING TESTS

ONLY_FOR_ARCHS=	amd64 i386 ia64
ONLY_FOR_ARCHS_REASON=	does not support big-endian architectures

CONFIGURE_ARGS=	--without-daemon \
		--without-gui \
		--without-libs \
		--without-qrencode \
		--with-utils \
		--disable-wallet \
		--disable-reduce-exports

PLIST_FILES=	bin/bitcoin-cli bin/bitcoin-tx

.include "${MASTERDIR}/Makefile"
