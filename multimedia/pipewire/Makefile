PORTNAME=	pipewire
DISTVERSION=	0.3.36
PORTREVISION=	2
CATEGORIES=	multimedia

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Server and user space API to deal with multimedia pipelines

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libdbus-1.so:devel/dbus \
		libinotify.so:devel/libinotify \
		libepoll-shim.so:devel/libepoll-shim \
		libudev.so:devel/libudev-devd \
		libwebrtc_audio_processing.so:audio/webrtc-audio-processing0

USES=		compiler:c11 gettext-tools gnome localbase:ldflags meson \
		pkgconfig python:3.6+,build
USE_GNOME=	glib20
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	PipeWire

OPTIONS_DEFINE=		GSTREAMER MANPAGES MEDIASESSION PULSEAUDIO VULKAN
OPTIONS_DEFAULT=	GSTREAMER MANPAGES MEDIASESSION
OPTIONS_SUB=	yes

GSTREAMER_MESON_ENABLED=gstreamer
GSTREAMER_LIB_DEPENDS=	libgstreamer-1.0.so:multimedia/gstreamer1 \
			libgstaudio-1.0.so:multimedia/gstreamer1-plugins

MANPAGES_BUILD_DEPENDS=	rst2man:textproc/py-docutils
MANPAGES_MESON_ENABLED=	man

MEDIASESSION_DESC=	Session manager support
MEDIASESSION_MESON_ENABLED=	alsa pipewire-alsa pw-cat
MEDIASESSION_MESON_ON=		-Dsession-managers=media-session
MEDIASESSION_MESON_OFF=		-Dsession-managers=''
MEDIASESSION_LIB_DEPENDS=	libsndfile.so:audio/libsndfile

PULSEAUDIO_MESON_ENABLED=	libpulse
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio \
				libavahi-common.so:net/avahi-app \
				libavahi-client.so:net/avahi-app

VULKAN_DESC=		Enable Vulkan integration
VULKAN_MESON_ENABLED=	vulkan
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

MESON_ARGS=	-D bluez5=disabled \
		-D jack=disabled -D pipewire-jack=disabled \
		-D systemd=disabled \
		-D sdl2=disabled \
		-D udevrulesdir="${LOCALBASE}/lib/udev/rules.d"

post-patch-MEDIASESSION-on:
# alsa-seq is not supported & causes SIGSEGV with media session
	@${REINPLACE_CMD} 's| alsa-seq|\ #alsa-seq|g' \
		${WRKSRC}/src/daemon/media-session.d/media-session.conf
# start media session by default
	@${REINPLACE_CMD} '/manager_args/ s/@sm_comment@//g' \
		${WRKSRC}/src/daemon/pipewire.conf.in

.include <bsd.port.mk>
