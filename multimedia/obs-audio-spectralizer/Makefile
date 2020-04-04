# $FreeBSD$

PORTNAME=	obs-audio-spectralizer
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2-2
DISTVERSIONSUFFIX=	-ga34b9b7
CATEGORIES=	multimedia www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OBS Studio Plugin: Audio visualizer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libobs.so:multimedia/obs-studio

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	univrsal
GH_PROJECT=	spectralizer

CXXFLAGS+=	-I${LOCALBASE}/include/obs

PLIST_FILES=	lib/obs-plugins/spectralizer.so \
		share/obs/obs-plugins/spectralizer/locale/en-US.ini \
		share/obs/obs-plugins/spectralizer/locale/ko-KR.ini

.include <bsd.port.mk>
