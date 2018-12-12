# $FreeBSD$

PORTNAME=	kvazaar
DISTVERSIONPREFIX=	v
DISTVERSION?=	1.2.0
PORTREVISION?=	3
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	93e1c9f1c39c.patch:-p1 \
		4f4bea749680.patch:-p1 \
		4b24cd03a24e.patch:-p1 \
		411276d6f2b2.patch:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	H.265/HEVC encoder implemented in C

LICENSE=	LGPL21+

USE_GITHUB=	yes
GH_ACCOUNT=	ultravideo
GH_TUPLE=	silentbicycle:greatest:v1.0.0:greatest/greatest

CONFLICTS_INSTALL?=	${PORTNAME}-devel

USES=		autoreconf compiler:c11 libtool pathfix
GNU_CONFIGURE=	yes
TEST_TARGET=	check
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	ASM CRYPTOPP DOCS
OPTIONS_DEFAULT=ASM

ASM_BUILD_DEPENDS=	${ASM_BUILD_DEPENDS_${ARCH}}
ASM_BUILD_DEPENDS_amd64=yasm:devel/yasm
ASM_BUILD_DEPENDS_i386=	yasm:devel/yasm
ASM_CONFIGURE_ENABLE=	asm

CRYPTOPP_DESC=		Selective encryption via Crypto++ library
CRYPTOPP_LIB_DEPENDS=	libcryptopp.so:security/cryptopp
CRYPTOPP_USES=		pkgconfig
CRYPTOPP_CONFIGURE_WITH=cryptopp

post-patch:
	@${REINPLACE_CMD} -e 's/x86_64/&|amd64/' \
		-e '/AM_INIT_AUTOMAKE/s/])/ serial-tests&/' \
		${WRKSRC}/configure.ac

pre-install:	do-test

.include <bsd.port.mk>

# XXX test_external_symbols.sh fails with CRYPTOPP=on
# XXX beefy5 (fails) vs. beefy4 (succeeds). Missed CPUID check?
do-test:	.IGNORE
