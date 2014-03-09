# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/net-im/farsight2/Makefile,v 1.10 2012/06/13 09:31:14 kwm Exp $

PORTNAME=	farsight2
PORTVERSION=	0.0.31
CATEGORIES=	net-im devel
MASTER_SITES=	http://www.freedesktop.org/software/farstream/releases/farsight2/ \
		http://miwibox.org/distfiles/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of GStreamer modules and libraries for videoconferencing

LIB_DEPENDS=	nice:${PORTSDIR}/net-im/libnice

CONFLICTS=	farstream-[0-9]*

USES=		pkgconfig gettext gmake
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack glib20 ltverhack
USE_GSTREAMER=	core good bad python
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
