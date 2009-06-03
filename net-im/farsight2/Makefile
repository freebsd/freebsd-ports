# New ports collection makefile for:	farsight2
# Date created:				27 February 2009
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	farsight2
PORTVERSION=	0.0.12
PORTREVISION=	1
CATEGORIES=	net-im devel
MASTER_SITES=	http://farsight.freedesktop.org/releases/farsight2/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of GStreamer modules and libraries for videoconferencing

LIB_DEPENDS=	nice.0:${PORTSDIR}/net-im/libnice

USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack pkgconfig glib20 ltverhack gnometarget \
		pygtk2
USE_GSTREAMER=	core good bad python
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
