PORTNAME=	librespot
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	8
CATEGORIES=	multimedia

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Open Source Spotify client library
WWW=		https://github.com/librespot-org/librespot

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bindgen:devel/rust-bindgen-cli

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	librespot-org

CARGO_FEATURES=	--no-default-features

PLIST_FILES=	bin/librespot

OPTIONS_DEFAULT=	PORTAUDIO
OPTIONS_MULTI=		BACKEND
OPTIONS_MULTI_BACKEND=	ALSA GSTREAMER JACK PORTAUDIO PULSEAUDIO SDL
ALSA_DESC=		Rodio audio backend using ALSA

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_VARS=		CARGO_FEATURES+=rodio-backend
GSTREAMER_USES=		gnome gstreamer
GSTREAMER_USE=		GNOME=glib20
GSTREAMER_VARS=		CARGO_FEATURES+=gstreamer-backend
JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_VARS=		CARGO_FEATURES+=jackaudio-backend
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_VARS=		CARGO_FEATURES+=portaudio-backend
PULSEAUDIO_LIB_DEPENDS=	libpulse-simple.so:audio/pulseaudio
PULSEAUDIO_VARS=	CARGO_FEATURES+=pulseaudio-backend
SDL_USES=		sdl
SDL_USE=		SDL=sdl2
SDL_VARS=		CARGO_FEATURES+=sdl-backend

.include <bsd.port.mk>
