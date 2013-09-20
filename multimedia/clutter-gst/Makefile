# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/multimedia/clutter-gst/Makefile,v 1.6 2010/06/29 21:14:02 kwm Exp $

PORTNAME=	clutter-gst
PORTVERSION=	1.3.4
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://source.clutter-project.org/sources/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter GStreamer integration

LIB_DEPENDS=	clutter-glx-1.0:${PORTSDIR}/graphics/clutter

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USES=		pathfix gmake pkgconfig
USE_GNOME=	ltverhack gnomeprefix
USE_GSTREAMER=	yes
USE_GL=		gl
USE_XORG=	xp x11
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

NO_STAGE=	yes
.include <bsd.port.mk>
