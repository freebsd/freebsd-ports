# New ports collection makefile for:	gstreamermm
# Date created:		2008-02-23
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamermm/Makefile,v 1.2 2008/03/15 21:09:37 ahze Exp $

PORTNAME=	gstreamermm
PORTVERSION=	0.10.2
CATEGORIES=	multimedia
MASTER_SITES=	GNOME

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	C++ wrapper library for the multimedia library GStreamer

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GSTREAMER=	theora vorbis cdparanoia gio pango
USE_GNOME=	pkgconfig gnomeprefix gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docs --disable-examples
USE_LDCONFIG=	yes
PLIST_SUB=	GST_VERSION="${GST_VERSION}"

.include <bsd.port.mk>
