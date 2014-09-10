# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/multimedia/clutter-gst/Makefile,v 1.6 2010/06/29 21:14:02 kwm Exp $

PORTNAME=	clutter-gst
PORTVERSION=	1.3.4
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://source.clutter-project.org/sources/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Clutter GStreamer integration

LIB_DEPENDS=	libclutter-glx-1.0.so:${PORTSDIR}/graphics/clutter

USES=		gmake libtool pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix
USE_GSTREAMER=	yes
USE_GL=		gl
USE_XORG=	xp x11
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-silent-rules

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/clutter-gst/Makefile.in

.include <bsd.port.mk>
