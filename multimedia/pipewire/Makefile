# $FreeBSD$

PORTNAME=	pipewire
DISTVERSION=	0.3.23
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

USES=		compiler:c11 gnome meson pkgconfig

OPTIONS_DEFINE=	GSTREAMER VULKAN

GSTREAMER_MESON_TRUE=	gstreamer
GSTREAMER_LIB_DEPENDS=	libgstreamer-1.0.so:multimedia/gstreamer1 \
			libgstaudio-1.0.so:multimedia/gstreamer1-plugins

VULKAN_DESC=	Enable Vulkan integration
VULKAN_MESON_TRUE=	vulkan
VULKAN_BUILD_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers
VULKAN_LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader

USE_GNOME=	glib20
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	PipeWire

MESON_ARGS=	-D gstreamer=false \
		-Dalsa=false -Dpipewire-alsa=false \
		-D bluez5=false \
		-D jack=false -D pipewire-jack=false \
		-D pipewire-pulseaudio=false \
		-D systemd=false

OPTIONS_SUB=	yes

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/pipewire.conf ${STAGEDIR}${ETCDIR}/pipewire.conf.sample

.include <bsd.port.mk>
