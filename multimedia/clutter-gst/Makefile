# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	clutter-gst
PORTVERSION=	2.0.16
CATEGORIES=	multimedia
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter GStreamer integration

LIB_DEPENDS=	libclutter-1.0.so:graphics/clutter

PORTSCOUT=	ignore:1

USES=		gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	introspection gnomeprefix
GNU_CONFIGURE=	yes
USE_GL=		gl
USE_GSTREAMER1=	yes
USE_XORG=	xp x11
USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
