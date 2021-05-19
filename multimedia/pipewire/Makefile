PORTNAME=	pipewire
DISTVERSION=	0.3.27
CATEGORIES=	multimedia

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Server and user space API to deal with multimedia pipelines

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

#TODO: xmltoman
BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libdbus-1.so:devel/dbus \
		libinotify.so:devel/libinotify \
		libepoll-shim.so:devel/libepoll-shim \
		libudev.so:devel/libudev-devd

USES=		compiler:c11 gettext-tools gnome localbase:ldflags meson pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	PipeWire

OPTIONS_DEFINE=	GSTREAMER MEDIASESSION VULKAN
OPTIONS_SUB=	yes

GSTREAMER_MESON_ENABLED=gstreamer
GSTREAMER_LIB_DEPENDS=	libgstreamer-1.0.so:multimedia/gstreamer1 \
			libgstaudio-1.0.so:multimedia/gstreamer1-plugins

MEDIASESSION_DESC=	Session manager support
MEDIASESSION_MESON_ENABLED=	alsa pipewire-alsa media-session pw-cat
MEDIASESSION_LIB_DEPENDS=	libsndfile.so:audio/libsndfile

VULKAN_DESC=		Enable Vulkan integration
VULKAN_MESON_ENABLED=	vulkan
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

MESON_ARGS=	-D bluez5=disabled \
		-D jack=disabled -D pipewire-jack=disabled \
		-D systemd=disabled \
		-D sdl2=disabled \
		-D udevrulesdir="${LOCALBASE}/lib/udev/rules.d"

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/pipewire.conf ${STAGEDIR}${ETCDIR}/pipewire.conf.sample

.include <bsd.port.mk>
