PORTNAME=	obs-waveform
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.0
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OBS Studio Plugin: Audio spectral analyser
WWW=		https://obsproject.com/forum/resources/waveform.1423/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cpu_features>0:devel/cpu_features
LIB_DEPENDS=	libcpu_features.so:devel/cpu_features \
		libfftw3f.so:math/fftw3-float \
		libobs.so:multimedia/obs-studio

USES=		cmake localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	phandasm
GH_PROJECT=	waveform

CMAKE_ON=	PACKAGED_INSTALL

LDFLAGS+=	-lcpu_features

PLIST_FILES=	lib/obs-plugins/waveform.so \
		share/obs/obs-plugins/waveform/gradient.effect \
		share/obs/obs-plugins/waveform/locale/en-US.ini \
		share/obs/obs-plugins/waveform/locale/it-IT.ini \
		share/obs/obs-plugins/waveform/locale/zh-CN.ini \
		share/obs/obs-plugins/waveform/locale/zh-TW.ini

.include <bsd.port.mk>
