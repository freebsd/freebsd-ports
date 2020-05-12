# $FreeBSD$

PORTNAME=	simplescreenrecorder
DISTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Screen video recorder

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg

USES=		cmake compiler:c++11-lang pkgconfig qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	MaartenBaert
GH_PROJECT=	ssr
USE_QT=		core gui widgets x11extras buildtools_build linguisttools_build qmake_build
USE_XORG=	x11 xext xfixes xi xinerama

CMAKE_ON=	WITH_QT5
CMAKE_OFF=	WITH_GLINJECT  # doesn't yet work on FreeBSD: https://github.com/MaartenBaert/ssr/issues/586#issuecomment-343780107
CMAKE_OFF+=	WITH_OPENGL_RECORDING  # extra option requiried when GLInject is off, because this makes OpenGL recording dysfunctional

OPTIONS_DEFINE=		ALSA PULSEAUDIO JACK
OPTIONS_DEFAULT=	ALSA PULSEAUDIO

ALSA_CMAKE_BOOL=	WITH_ALSA
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib

PULSEAUDIO_CMAKE_BOOL=	WITH_PULSEAUDIO
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

JACK_CMAKE_BOOL=	WITH_JACK
JACK_LIB_DEPENDS=	libjack.so:audio/jack

post-install:  # https://github.com/MaartenBaert/ssr/issues/609
	@${RM} ${STAGEDIR}${PREFIX}/man/man1/ssr-glinject.*

.include <bsd.port.mk>
