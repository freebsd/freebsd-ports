PORTNAME=	gstreamer1-rtsp-server
PORTVERSION=	${_GST_VERSION}
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-rtsp-server/
DISTNAME=	gst-rtsp-server-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer library for building a RTSP server
WWW=		https://gstreamer.freedesktop.org/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison gnome gstreamer meson ninja pathfix pkgconfig python:build tar:xz
USE_GNOME=	glib20 introspection:build
USE_GSTREAMER=	bad good
USE_LDCONFIG=	yes

MESON_ARGS=	-Ddoc=disabled

BINARY_ALIAS=	python3=${PYTHON_VERSION}

PLIST_SUB=	SOVERSION=${_GST_SOVERSION} \
		VERSION=${_GST_LIB_VER}

.include <bsd.port.mk>
