PORTNAME=	gstreamer1-vaapi
PORTVERSION=	1.20.5
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gstreamer-vaapi/
DISTNAME=	gstreamer-vaapi-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer hardware video decoding via VA-API plug-in
WWW=		https://github.com/GStreamer/gstreamer-vaapi

LICENSE=	LGPL21

LIB_DEPENDS=	libva.so:multimedia/libva

USES=		bison compiler:c11 gettext-runtime gl gnome gstreamer libtool \
		meson ninja pkgconfig python:3.8+,build tar:xz xorg
USE_LDCONFIG=	yes
USE_GNOME=	glib20
USE_GSTREAMER=	bad
USE_GL=		gl
USE_XORG=	x11 xrandr xrender xorgproto

BINARY_ALIAS=	python3=${PYTHON_VERSION}

OPTIONS_DEFINE=	DRM WAYLAND

DRM_DESC=	Raw KMS/DRM backend

DRM_MESON_OFF=	-Dwith_drm=no
DRM_LIB_DEPENDS=libudev.so:devel/libudev-devd \
		libdrm.so:graphics/libdrm

WAYLAND_MESON_OFF=	-Dwith_wayland=no
WAYLAND_LIB_DEPENDS=	libva-wayland.so:multimedia/libva \
			libwayland-client.so:graphics/wayland

.include <bsd.port.mk>
