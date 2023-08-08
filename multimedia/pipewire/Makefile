PORTNAME=	pipewire
DISTVERSION=	0.3.62
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	https://gitlab.freedesktop.org/pipewire/media-session/-/archive/${MEDIA_SESSION_VERSION}/:media_session
DISTFILES=	media-session-${MEDIA_SESSION_VERSION}${EXTRACT_SUFX}:media_session

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Server and user space API to deal with multimedia pipelines
WWW=		https://pipewire.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libinotify.so:devel/libinotify \
		libepoll-shim.so:devel/libepoll-shim \
		libsndfile.so:audio/libsndfile \
		libudev.so:devel/libudev-devd \
		libwebrtc_audio_processing.so:audio/webrtc-audio-processing0

USES=		compiler:c11 gettext-tools gnome localbase:ldflags meson \
		ncurses pkgconfig python:build readline ssl
USE_GNOME=	glib20
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	PipeWire

OPTIONS_DEFINE=		GSTREAMER PIPEWIRE_JACK MANPAGES MEDIASESSION PULSEAUDIO SDL VULKAN
OPTIONS_DEFAULT=	GSTREAMER PIPEWIRE_JACK MANPAGES MEDIASESSION
OPTIONS_SUB=	yes

GSTREAMER_USES=		gstreamer
GSTREAMER_MESON_ENABLED=gstreamer gstreamer-device-provider

PIPEWIRE_JACK_DESC=		Build pipewire-jack
PIPEWIRE_JACK_MESON_ENABLED=	pipewire-jack

MANPAGES_BUILD_DEPENDS=	rst2man:textproc/py-docutils
MANPAGES_MESON_ENABLED=	man

MEDIASESSION_DESC=		Session manager support
MEDIASESSION_LIB_DEPENDS=	libasound.so:audio/alsa-lib
MEDIASESSION_RUN_DEPENDS=	alsa-plugins>0:audio/alsa-plugins
MEDIASESSION_MESON_ENABLED=	alsa pipewire-alsa
MEDIASESSION_MESON_ON=		-Dsession-managers=media-session
MEDIASESSION_MESON_OFF=		-Dsession-managers=''
MEDIASESSION_SUB_FILES=		10-alsa-default.conf

PULSEAUDIO_MESON_ENABLED=	avahi libpulse
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio \
				libavahi-common.so:net/avahi-app \
				libavahi-client.so:net/avahi-app

SDL_MESON_ENABLED=	sdl2
SDL_USES=		sdl
SDL_USE=		sdl=sdl2

VULKAN_DESC=		Enable Vulkan integration
VULKAN_MESON_ENABLED=	vulkan
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

MEDIA_SESSION_VERSION=	0.4.1

MESON_ARGS=	-D pw-cat=enabled \
		-D v4l2=enabled \
		-D raop=enabled \
		-D avb=disabled \
		-D bluez5=disabled \
		-D jack=disabled \
		-D libcamera=disabled \
		-D libcanberra=disabled \
		-D lv2=disabled \
		-D media-session:systemd=disabled \
		-D roc=disabled \
		-D systemd=disabled \
		-D x11=disabled \
		-D x11-xfixes=disabled \
		-D pipewire-v4l2=disabled \
		-D udevrulesdir="${LOCALBASE}/lib/udev/rules.d"

# Fake pkg-config support before https://cgit.freebsd.org/src/commit/?id=396851c20aeb
# but only if devel/ncurses isn't installed
.if !exists(/usr/libdata/pkgconfig/ncursesw.pc)
CONFIGURE_ENV+=	${ncurses_ARGS:Mbase:C/.+/PKG_CONFIG_PATH="${FILESDIR}"/}
.endif

post-extract:
	${LN} -s ${WRKDIR}/media-session-${MEDIA_SESSION_VERSION} ${WRKSRC}/subprojects/media-session

post-patch-MEDIASESSION-on:
# alsa-seq is not supported & causes SIGSEGV with media session
	@${REINPLACE_CMD} 's| alsa-seq|\ #alsa-seq|g' \
		${WRKDIR}/media-session-${MEDIA_SESSION_VERSION}/media-session.d/media-session.conf
# start media session by default
	@${REINPLACE_CMD} '/manager_args/ s/@sm_comment@//g' \
		${WRKSRC}/src/daemon/pipewire.conf.in

post-install-MEDIASESSION-on:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.d
	${INSTALL_DATA} ${WRKDIR}/10-alsa-default.conf \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.d

.include <bsd.port.mk>
