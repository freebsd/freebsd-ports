# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/net-im/farsight2/Makefile 19804 2014-08-13 14:55:11Z kwm $

PORTNAME=	farsight2
PORTVERSION=	0.0.31
PORTREVISION=	3
CATEGORIES=	net-im devel
MASTER_SITES=	http://www.freedesktop.org/software/farstream/releases/farsight2/ \
		http://miwibox.org/distfiles/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of GStreamer modules and libraries for videoconferencing

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

LIB_DEPENDS=	libnice.so:net-im/libnice
RUN_DEPENDS=	libnice-gst010>=0:net-im/libnice-gst010

USES=		gettext gmake gnome libtool pathfix pkgconfig python:2.7
USE_LDCONFIG=	yes
USE_GNOME=	glib20
USE_GSTREAMER=	core good bad python
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
