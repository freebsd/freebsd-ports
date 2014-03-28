# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/net-im/libnice/Makefile 19243 2014-03-23 09:49:52Z kwm $

PORTNAME=	libnice
PORTVERSION=	0.1.5
CATEGORIES=	net-im devel
MASTER_SITES=	http://nice.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library and transmitter that implements ICE-19

USES=		gettext gmake libtool pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_GETIFADDRS
LDFLAGS+=	-L${LOCALBASE}/lib

.if !defined(LIBNICE_SLAVE)
OPTIONS_DEFINE=	GUPNP
GUPNP_DESC=	UPnP IGD port mapping support
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUPNP}
LIB_DEPENDS+=	libgupnp-igd-1.0.so:${PORTSDIR}/net/gupnp-igd
.else
CONFIGURE_ARGS+=--disable-gupnp
.endif

.if defined(LIBNICE_SLAVE)
. if ${LIBNICE_SLAVE}==gstreamer010
USE_GSTREAMER=	yes
CONFIGURE_ARGS+=--without-gstreamer --with-gstreamer-0.10
. endif
. if ${LIBNICE_SLAVE}==gstreamer1
USE_GSTREAMER1=	yes
CONFIGURE_ARGS+=--with-gstreamer --without-gstreamer-0.10
. endif
.else
CONFIGURE_ARGS=	--without-gstreamer --without-gstreamer-0.10
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
	    	's|-Wno-missing-field-initializers|#|g'
	@${REINPLACE_CMD} -e 's|-Wno-missing-field-initializers|#|g' \
	    	${WRKSRC}/common.mk
	@${REINPLACE_CMD} -e 's|-Werror||g' ${WRKSRC}/configure

post-install:
.if !defined(LIBNICE_SLAVE)
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so*
.else
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*/lib*.so
.endif

.include <bsd.port.mk>
