# New ports collection makefile for:	gstreamer-plugins-fluendo-mpegdemux
# Date created:		2007-02-25
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer-plugins-fluendo-mpegdemux
PORTVERSION=	0.10.12
CATEGORIES=	multimedia
MASTER_SITES=	http://core.fluendo.com/gstreamer/src/gst-fluendo-mpegdemux/
DISTNAME=	gst-fluendo-mpegdemux-${PORTVERSION}

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	MPEG2 demuxing gstreamer plugin from fluendo

CFLAGS:=	${CFLAGS} -O2
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
PLIST_FILES=	lib/gstreamer-0.10/libgstflumpegdemux.a \
		lib/gstreamer-0.10/libgstflumpegdemux.la \
		lib/gstreamer-0.10/libgstflumpegdemux.so

.include <bsd.port.mk>
