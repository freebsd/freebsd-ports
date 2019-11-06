# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$

PORTNAME=	gstreamer1-vaapi
PORTVERSION=	1.14.4
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gstreamer-vaapi/
DISTNAME=	gstreamer-vaapi-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer hardware video decoding via VA-API plug-in

LICENSE=	LGPL21

LIB_DEPENDS=	libva.so:multimedia/libva

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		compiler:c11 gettext-runtime gl gmake gnome libtool \
		pkgconfig tar:xz xorg
USE_LDCONFIG=	yes
USE_GNOME=	glib20
USE_GSTREAMER1=	bad gl
USE_GL=		gl
USE_XORG=	x11 xrandr xrender xorgproto

OPTIONS_DEFINE=	DRM WAYLAND

DRM_DESC=	Raw KMS/DRM backend

DRM_CONFIGURE_ENABLE=	drm
DRM_LIB_DEPENDS=	libudev.so:devel/libudev-devd \
	libdrm.so:graphics/libdrm

WAYLAND_CONFIGURE_ENABLE=	wayland
WAYLAND_LIB_DEPENDS=	libva-wayland.so:multimedia/libva \
	libwayland-client.so:graphics/wayland

.include <bsd.port.mk>
