# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net-im/farstream/Makefile 19578 2014-04-25 21:50:30Z kwm $

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
USES=		gettext libtool:keepla gmake pathfix pkgconfig
USE_GNOME=	glib20 introspection:build
USE_GSTREAMER1=	good bad
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
