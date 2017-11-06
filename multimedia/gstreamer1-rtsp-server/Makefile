# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gstreamer1-rtsp-server
PORTVERSION=	1.12.3
CATEGORIES=	multimedia
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst-rtsp-server/
DISTNAME=	gst-rtsp-server-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	GStreamer library for building a RTSP server

USES=		gmake gnome libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 introspection:build
USE_GSTREAMER1=	good bad
INSTALL_TARGET=	install-strip

PLIST_SUB=	VERSION=1.0 SOVERSION=0.1203.0

.include <bsd.port.mk>
