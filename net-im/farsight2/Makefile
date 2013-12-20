# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/net-im/farsight2/Makefile 18965 2013-12-20 11:02:42Z kwm $

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

USES=		gettext gmake pathfix pkgconfig
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_GNOME=	glib20 ltverhack
USE_GSTREAMER=	core good bad python
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/farsight2-0.0/lib*.so
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/farsight.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgstfarsight-0.10.so.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gstreamer-0.10/lib*.so

.include <bsd.port.mk>
