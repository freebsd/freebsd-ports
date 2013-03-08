# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom$

PORTNAME=	libnice
PORTVERSION=	0.1.3
CATEGORIES=	net-im devel
MASTER_SITES=	http://nice.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library and transmitter that implements ICE-19

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack glib20 ltverhack
USE_PKGCONFIG=	build
USE_GSTREAMER=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--without-gstreamer --with-gstreamer-0.10
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_GETIFADDRS
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
	    	's|-Wno-missing-field-initializers|#|g'
	@${REINPLACE_CMD} -e 's|-Wno-missing-field-initializers|#|g' \
	    	${WRKSRC}/common.mk

.include <bsd.port.mk>
