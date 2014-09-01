# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#    $MCom$

PORTNAME=	libnice
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	net-im devel
MASTER_SITES=	http://nice.freedesktop.org/releases/ \
		http://miwibox.org/distfiles/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library and transmitter that implements ICE-19

USES=		gettext gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	glib20
USE_GSTREAMER=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-gstreamer --with-gstreamer-0.10
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_GETIFADDRS
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
	    	's|-Wno-missing-field-initializers|#|g'
	@${REINPLACE_CMD} -e 's|-Wno-missing-field-initializers|#|g' \
	    	${WRKSRC}/common.mk

.include <bsd.port.mk>
