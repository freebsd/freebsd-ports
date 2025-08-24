PORTNAME=	simplescreenrecorder
DISTVERSION=	0.4.4-73
DISTVERSIONSUFFIX=	-g232eac7
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Screen video/audio recorder
WWW=		https://www.maartenbaert.be/simplescreenrecorder/ \
		https://github.com/MaartenBaert/ssr

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libpipewire-0.3.so:multimedia/pipewire

USES=		cmake compiler:c++11-lang desktop-file-utils pkgconfig qt:5 xorg
USE_QT=		core gui widgets x11extras buildtools:build linguisttools:build qmake:build
USE_XORG=	x11 xext xfixes xi xinerama

USE_GITHUB=	yes
GH_ACCOUNT=	MaartenBaert
GH_PROJECT=	ssr

CMAKE_ON=	WITH_QT5
CMAKE_OFF=	WITH_GLINJECT  # doesn't yet work on FreeBSD: https://github.com/MaartenBaert/ssr/issues/586#issuecomment-343780107
CMAKE_OFF+=	WITH_OPENGL_RECORDING  # extra option requiried when GLInject is off, because this makes OpenGL recording dysfunctional

OPTIONS_DEFINE=		V4L
OPTIONS_MULTI=		AUDIO # MULTI because project doesn't allow to build with no backends
OPTIONS_MULTI_AUDIO=	ALSA PULSEAUDIO JACK
OPTIONS_DEFAULT=	PULSEAUDIO JACK V4L
AUDIO_DESC=		Audio backends:

ALSA_CMAKE_BOOL=	WITH_ALSA
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib

PULSEAUDIO_CMAKE_BOOL=	WITH_PULSEAUDIO
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

JACK_CMAKE_BOOL=	WITH_JACK
JACK_LIB_DEPENDS=	libjack.so:audio/jack

V4L_CMAKE_BOOL=		WITH_V4L2
V4L_BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
V4L_LIB_DEPENDS=	libv4l2.so:multimedia/libv4l

post-install:  # https://github.com/MaartenBaert/ssr/issues/609
	@${RM} ${STAGEDIR}${PREFIX}/man/man1/ssr-glinject.*

.include <bsd.port.mk>
