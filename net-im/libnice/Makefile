# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom$

PORTNAME=	libnice
PORTVERSION=	0.1.3
CATEGORIES=	net-im devel
MASTER_SITES=	http://nice.freedesktop.org/releases/ \
		http://miwibox.org/distfiles/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library and transmitter that implements ICE-19

USES=		pkgconfig gettext
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack glib20 ltverhack
USE_GSTREAMER=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--without-gstreamer --with-gstreamer-0.10
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_GETIFADDRS
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
	    	's|-Wno-missing-field-initializers|#|g'
	@${REINPLACE_CMD} -e 's|-Wno-missing-field-initializers|#|g' \
	    	${WRKSRC}/common.mk

.include <bsd.port.mk>
