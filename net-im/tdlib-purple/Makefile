PORTNAME=	tdlib-purple
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.1
PORTREVISION=	3
CATEGORIES=	net-im

PATCH_SITES=	https://github.com/ars3niy/tdlib-purple/commit/
PATCHFILES+=	8c87b899ddbec32.patch:-p1 # https://github.com/ars3niy/tdlib-purple/pull/154

MAINTAINER=	ports@virtual-estates.net
COMMENT=	Telegram plugin for libpurple, using tdlib
WWW=		https://github.com/ars3niy/tdlib-purple

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		fails to compile with the latest revision of net-im/tdlib

LIB_DEPENDS=	libfmt.so:devel/libfmt	\
		libtdapi.so:net-im/tdlib	\
		librlottie.so:graphics/rlottie	\
		libwebp.so:graphics/webp	\
		libpurple.so:net-im/libpurple	\
		libpng.so:graphics/png
TEST_LIB_DEPENDS=libgtest.so:devel/googletest

USES=		cmake localbase pkgconfig

USE_GITHUB=	yeah
GH_ACCOUNT=	ars3niy

OPTIONS_DEFINE=	NLS TEST
OPTIONS_DEFAULT=NLS
OPTIONS_SUB=	yes
TEST_DESC=	Do not enable, tests are broken

CMAKE_ON+=	NoVoip	# tgvoip is yet to be ported
CMAKE_ON+=	NoBundledLottie	# Using graphics/rlottie
NLS_CMAKE_OFF+=	-DNoTranslations=1
NLS_USES=	gettext-tools gettext-runtime

EXTRACT_AFTER_ARGS=--exclude rlottie --exclude fmt

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTEST}
WARNING+=	"Tests are stale at this time and are likely to fail to compile"
TEST_TARGET=	tests
.endif

.include <bsd.port.mk>
