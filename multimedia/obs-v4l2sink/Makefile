# $FreeBSD$

PORTNAME=	obs-v4l2sink
DISTVERSION=	0.1.0-12
DISTVERSIONSUFFIX=	-g1ec3c8a
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OBS Studio Plugin: Output as Video4Linux2 device

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	fails to compile: unconditionally includes obs/sse-intrin.h

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=	libobs.so:multimedia/obs-studio

USES=		cmake compiler:c++11-lang qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	CatxFish
USE_QT=		core gui widgets buildtools_build qmake_build

CMAKE_ARGS=	-DLIBOBS_INCLUDE_DIR=${LOCALBASE}/include/obs

PLIST_FILES=	lib/obs-plugins/v4l2sink.so \
		share/obs/obs-plugins/v4l2sink/locale/de-DE.ini \
		share/obs/obs-plugins/v4l2sink/locale/en-US.ini \
		share/obs/obs-plugins/v4l2sink/locale/zh-TW.ini

.include <bsd.port.mk>
