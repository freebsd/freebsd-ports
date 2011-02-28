# New ports collection makefile for:	clutter-gst
# Date created:		2008-12-25
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/multimedia/clutter-gst/Makefile,v 1.6 2010/06/29 21:14:02 kwm Exp $

PORTNAME=	clutter-gst
PORTVERSION=	1.3.4
CATEGORIES=	multimedia
MASTER_SITES=	http://source.clutter-project.org/sources/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter GStreamer integration

LIB_DEPENDS=	clutter-glx-1.0:${PORTSDIR}/graphics/clutter

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomehack ltverhack gnomeprefix
USE_GSTREAMER=	yes
USE_XORG=	xp x11
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
