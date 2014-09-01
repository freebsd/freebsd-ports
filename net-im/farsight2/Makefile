# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net-im/farsight2/Makefile,v 1.10 2012/06/13 09:31:14 kwm Exp $

PORTNAME=	farsight2
PORTVERSION=	0.0.31
PORTREVISION=	1
CATEGORIES=	net-im devel
MASTER_SITES=	http://www.freedesktop.org/software/farstream/releases/farsight2/ \
		http://miwibox.org/distfiles/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of GStreamer modules and libraries for videoconferencing

LIB_DEPENDS=	libnice.so:${PORTSDIR}/net-im/libnice

CONFLICTS=	farstream-[0-9]*

USES=		gettext gmake libtool pathfix pkgconfig python
USE_LDCONFIG=	yes
USE_GNOME=	glib20
USE_GSTREAMER=	core good bad python
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
