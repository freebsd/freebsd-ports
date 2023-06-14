PORTNAME=	gstreamer1-rtsp-server
PORTVERSION=	1.22.4
CATEGORIES=	multimedia
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-rtsp-server/
DISTNAME=	gst-rtsp-server-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer library for building a RTSP server
WWW=		https://gstreamer.freedesktop.org/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		bison gnome gstreamer libtool meson ninja pathfix pkgconfig python:build tar:xz
USE_LDCONFIG=	yes
USE_GNOME=	glib20 introspection:build
USE_GSTREAMER=	good bad
MESON_ARGS=	-Ddoc=disabled

BINARY_ALIAS=	python3=${PYTHON_VERSION}

PLIST_SUB=	VERSION=1.0 SOVERSION=0.2204.0

.include <bsd.port.mk>
