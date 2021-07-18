# Created by: Martin Wilke <miwi@FreeBSD.org>

PORTNAME=	clutter-gst
PORTVERSION=	2.0.18
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter GStreamer integration

LIB_DEPENDS=	libclutter-1.0.so:graphics/clutter

PORTSCOUT=	ignore:1

USES=		gl gmake gnome libtool localbase pathfix \
		pkgconfig tar:xz xorg
USE_GNOME=	introspection gnomeprefix
GNU_CONFIGURE=	yes
USE_GL=		gl
USE_GSTREAMER1=	yes
USE_XORG=	x11
USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CACHE_HOME=${WRKDIR}

LDFLAGS+=	-lpthread
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
