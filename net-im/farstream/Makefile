# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net-im/farstream/Makefile 18869 2013-11-08 14:52:12Z kwm $

PORTNAME=	farstream
PORTVERSION=	0.2.3
CATEGORIES=	net-im devel
MASTER_SITES=	http://freedesktop.org/software/farstream/releases/farstream/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of GStreamer modules and libraries for videoconferencing

LIB_DEPENDS=	libnice.so:${PORTSDIR}/net-im/libnice
RUN_DEPENDS=	libnice-gst1>=0:${PORTSDIR}/net-im/libnice-gst1

USE_LDCONFIG=	yes
USE_PYTHON=	yes
USES=		gettext gmake pathfix pkgconfig
USE_GNOME=	glib20 ltverhack introspection:build
USE_GSTREAMER1=	good bad
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfarstream-0.2.so.2
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gstreamer-1.0/lib*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/farstream-0.2/lib*.so

.include <bsd.port.mk>
