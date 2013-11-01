# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gstreamer-plugins-fluendo-mpegdemux
PORTVERSION=	0.10.71
CATEGORIES=	multimedia
MASTER_SITES=	http://core.fluendo.com/gstreamer/src/gst-fluendo-mpegdemux/
DISTNAME=	gst-fluendo-mpegdemux-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	MPEG2 demuxing gstreamer plugin from fluendo

LICENSE=	MPL

CFLAGS:=	${CFLAGS} -O2
USES=		pkgconfig
USE_BZIP2=	yes
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
PLIST_FILES=	lib/gstreamer-0.10/libgstflumpegdemux.la \
		lib/gstreamer-0.10/libgstflumpegdemux.so

.include <bsd.port.mk>
