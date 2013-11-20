# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/multimedia/clutter-gst/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTNAME=	clutter-gst
PORTVERSION=	2.0.2
CATEGORIES=	multimedia
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter GStreamer integration

LIB_DEPENDS=	libclutter-1.0.so:${PORTSDIR}/graphics/clutter

USE_XZ=		yes
USE_AUTOTOOLS=	libtool
USE_GL=		gl
USES=		gmake pathfix pkgconfig
USE_GNOME=	ltverhack gnomeprefix gnomehier introspection:build
USE_GSTREAMER1=	yes
USE_XORG=	xp x11
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
