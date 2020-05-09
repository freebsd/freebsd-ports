# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	farstream
PORTVERSION=	0.2.8
PORTREVISION=	1
CATEGORIES=	net-im devel
MASTER_SITES=	http://freedesktop.org/software/farstream/releases/farstream/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of GStreamer modules and libraries for videoconferencing

LICENSE=	LGPL21+

LIB_DEPENDS=	libnice.so:net-im/libnice
RUN_DEPENDS=	libnice-gst1>=0:net-im/libnice-gst1

USES=		gettext gmake gnome libtool localbase:ldflags pathfix \
		pkgconfig python
USE_LDCONFIG=	yes
USE_GNOME=	glib20 introspection:build
USE_GSTREAMER1=	good bad

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in -exec ${REINPLACE_CMD} \
		'/foreach/s/\\#include/#include/' {} +

.include <bsd.port.mk>
