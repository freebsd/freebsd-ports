# $FreeBSD$

PORTNAME=	obs-transition-matrix
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0-4
DISTVERSIONSUFFIX=	-g15f096e
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OBS Studio Plugin: OBS Transition Matrix

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libobs.so:multimedia/obs-studio

USES=		cmake qt:5 compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	admshao
USE_QT=		core gui widgets buildtools_build qmake_build

CMAKE_ARGS=	-DLIBOBS_INCLUDE_DIR=${LOCALBASE}/include

CXXFLAGS+=	-I${LOCALBASE}/include/obs

PLIST_FILES=	lib/obs-plugins/obs-transition-matrix.so \
		share/obs/obs-plugins/obs-transition-matrix/locale/en-US.ini

.include <bsd.port.mk>
