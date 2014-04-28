# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/net-im/farsight2/Makefile 19578 2014-04-25 21:50:30Z kwm $

PORTNAME=	farsight2
PORTVERSION=	0.0.31
PORTREVISION=	1
CATEGORIES=	net-im devel
MASTER_SITES=	http://www.freedesktop.org/software/farstream/releases/farsight2/ \
		http://miwibox.org/distfiles/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of GStreamer modules and libraries for videoconferencing

LIB_DEPENDS=	libnice.so:${PORTSDIR}/net-im/libnice
RUN_DEPENDS=	libnice-gst010>=0:${PORTSDIR}/net-im/libnice-gst010

USES=		gettext libtool:keepla gmake pathfix pkgconfig
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_GNOME=	glib20
USE_GSTREAMER=	core good bad python
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
