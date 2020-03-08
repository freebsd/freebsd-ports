# $FreeBSD$

PORTNAME=	pipewire
DISTVERSION=	0.3.1
CATEGORIES=	multimedia

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Server and user space API to deal with multimedia pipelines

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

#TODO: xmltoman
BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libdbus-1.so:devel/dbus \
		libepoll-shim.so:devel/libepoll-shim \
		libudev.so:devel/libudev-devd

USES=		gnome meson pkgconfig

USE_GNOME=	glib20
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	PipeWire

MESON_ARGS=	-D gstreamer=false \
		-D bluez5=false \
		-D jack=false -D pipewire-jack=false \
		-D vulkan=false \
		-D pipewire-pulseaudio=false \
		-D systemd=false

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/pipewire.conf ${STAGEDIR}${ETCDIR}/pipewire.conf.sample

.include <bsd.port.mk>
