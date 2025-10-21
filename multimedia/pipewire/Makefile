PORTNAME=	pipewire
DISTVERSION=	1.4.9
CATEGORIES=	multimedia

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Server and user space API to deal with multimedia pipelines
WWW=		https://pipewire.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat \
		${LOCALBASE}/include/fftw3.f:math/fftw3
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libinotify.so:devel/libinotify \
		libepoll-shim.so:devel/libepoll-shim \
		libfftw3f.so:math/fftw3-float \
		libopus.so:audio/opus \
		libsndfile.so:audio/libsndfile \
		libudev.so:devel/libudev-devd \
		libwebrtc-audio-processing-1.so:audio/webrtc-audio-processing

USES=		compiler:c11 gettext-tools gnome localbase:ldflags meson \
		ncurses pkgconfig python:build readline shebangfix ssl
USE_GNOME=	glib20
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org

SHEBANG_FILES=	doc/*.py
PORTDOCS=	*

OPTIONS_DEFINE=		ALSA AVAHI DOCS DOXYGEN EBUR GSTREAMER JACK LV2 PULSEAUDIO \
			VULKAN X11_BELL
OPTIONS_DEFAULT=	EBUR GSTREAMER JACK
OPTIONS_SUB=		yes

ALSA_MESON_ENABLED=	alsa pipewire-alsa
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_RUN_DEPENDS=	alsa-plugins>0:audio/alsa-plugins
ALSA_SUB_FILES=		10-alsa-default.conf

AVAHI_DESC=		Automatic service discovery for the Pulseaudio module via Avahi
AVAHI_IMPLIES=		PULSEAUDIO
AVAHI_MESON_ENABLED=	avahi
AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen
DOXYGEN_MESON_ENABLED=	docs
DOXYGEN_IMPLIES=	DOCS

EBUR_DESC=		Loudness normalization plugin based on ebur128
EBUR_MESON_ENABLED=	ebur128
EBUR_USES=		ebur128

GSTREAMER_USES=		gstreamer
GSTREAMER_MESON_ENABLED=gstreamer gstreamer-device-provider

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_MESON_ENABLED=	jack pipewire-jack

LV2_DESC=		Support lv2-based audio plugins via lilv
LV2_LIB_DEPENDS=	liblilv-0.so:audio/lilv
LV2_MESON_ENABLED=	lv2

PULSEAUDIO_DESC=		Enable PulseAudio emulation
PULSEAUDIO_MESON_ENABLED=	libpulse
PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio

VULKAN_DESC=		Enable Vulkan integration
VULKAN_MESON_ENABLED=	vulkan
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader \
			libdrm.so:graphics/libdrm

X11_BELL_DESC=		Support for X11 bell via libcanberra
X11_BELL_LIB_DEPENDS=	libcanberra.so:audio/libcanberra
X11_BELL_USES=		xorg
X11_BELL_USE=		xorg=x11,xfixes
X11_BELL_MESON_ENABLED=	libcanberra x11 x11-xfixes

MESON_ARGS=	-D pw-cat=enabled \
		-D v4l2=enabled \
		-D raop=enabled \
		-D session-managers='[]' \
		-D compress-offload=disabled \
		-D avb=disabled \
		-D bluez5=disabled \
		-D man=disabled \
		-D libcamera=disabled \
		-D roc=disabled \
		-D sdl2=disabled \
		-D selinux=disabled \
		-D systemd=disabled \
		-D logind=disabled \
		-D pipewire-v4l2=disabled \
		-D libmysofa=disabled \
		-D libffado=disabled \
		-D snap=disabled \
		-D gsettings-pulse-schema=disabled \
		-D udevrulesdir="${LOCALBASE}/lib/udev/rules.d"

PORTDOCS=	*

# Fake pkg-config support before https://cgit.freebsd.org/src/commit/?id=396851c20aeb
# but only if devel/ncurses isn't installed
.if !exists(/usr/libdata/pkgconfig/ncursesw.pc)
CONFIGURE_ENV+=	${ncurses_ARGS:Mbase:C/.+/PKG_CONFIG_PATH="${FILESDIR}"/}
.endif

post-patch:
	${REINPLACE_CMD} -e "s|find_installation('python3'|find_installation('python${PYTHON_VER}'|" \
		${WRKSRC}/meson.build

post-install-ALSA-on:
	${MKDIR} ${STAGEDIR}${DATADIR}/${PORTNAME}.conf.d
	${INSTALL_DATA} ${WRKDIR}/10-alsa-default.conf \
		${STAGEDIR}${DATADIR}/${PORTNAME}.conf.d

.include <bsd.port.mk>
