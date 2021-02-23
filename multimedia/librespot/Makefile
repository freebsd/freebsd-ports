# $FreeBSD$

PORTNAME=	librespot
PORTVERSION=	0.1.6
DISTVERSIONPREFIX=	v
CATEGORIES=	multimedia

MAINTAINER=	driesm.michiels@gmail.com
COMMENT=	Open Source Spotify client library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	librespot-org

CARGO_FEATURES=	--no-default-features

PLIST_FILES=	bin/librespot

OPTIONS_DEFINE=		TREMOR VORBIS
OPTIONS_DEFAULT=	PORTAUDIO TREMOR VORBIS
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	ALSA GSTREAMER JACK PORTAUDIO PULSEAUDIO SDL
ALSA_DESC=		Rodio audio backend using ALSA

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_VARS=		CARGO_FEATURES+=rodio-backend
GSTREAMER_USE=		GNOME=glib20 \
			GSTREAMER1=yes
GSTREAMER_VARS=		CARGO_FEATURES+=gstreamer-backend
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_VARS=		CARGO_FEATURES+=jackaudio-backend
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_VARS=		CARGO_FEATURES+=portaudio-backend
PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_VARS=	CARGO_FEATURES+=pulseaudio-backend
SDL_USE=		SDL=sdl2
SDL_VARS=		CARGO_FEATURES+=sdl-backend
TREMOR_LIB_DEPENDS=	libvorbisidec.so:audio/libtremor
TREMOR_VARS=		CARGO_FEATURES+=with-tremor
VORBIS_LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis
VORBIS_VARS=		CARGO_FEATURES+=with-vorbis

.include "Makefile.crates"

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/librespot

.include <bsd.port.mk>
