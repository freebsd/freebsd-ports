# $FreeBSD$

PORTNAME=	kvazaar
DISTVERSIONPREFIX=	v
DISTVERSION?=	1.0.0
PORTREVISION?=	2
CATEGORIES=	multimedia

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

OPTIONS_DEFINE=	ASM CRYPTOPP
OPTIONS_DEFAULT=ASM

ASM_BUILD_DEPENDS=	${ASM_BUILD_DEPENDS_${ARCH}}
ASM_BUILD_DEPENDS_amd64=yasm:devel/yasm
ASM_BUILD_DEPENDS_i386=	yasm:devel/yasm
ASM_CONFIGURE_ENABLE=	asm

CRYPTOPP_DESC=		Selective encryption via Crypto++ library
CRYPTOPP_LIB_DEPENDS=	libcryptopp.so:security/cryptopp
CRYPTOPP_USES=		localbase pkgconfig
CRYPTOPP_CONFIGURE_ENV=	cryptopp_CFLAGS=" " cryptopp_LIBS="-lcryptopp"
CRYPTOPP_CONFIGURE_WITH=cryptopp

post-patch:
	@${REINPLACE_CMD} 's/x86_64/&|amd64/' ${WRKSRC}/configure.ac

post-patch-CRYPTOPP-on:
# XXX Force C++ linking to avoid error with Clang
	@${ECHO_CMD} nodist_EXTRA_kvazaar_tests_SOURCES \
		= dummy.cpp >>${WRKSRC}/tests/Makefile.am

post-patch-CRYPTOPP-off:
# XXX autoconf cannot ignore unexpanded but unused m4 macros
	@${REINPLACE_CMD} -i .cryptopp.bak \
		-e '/PKG_CHECK_MODULES/,/^[[:space:]]*)/d' \
		${WRKSRC}/configure.ac

pre-install:	do-test

.include <bsd.port.mk>
