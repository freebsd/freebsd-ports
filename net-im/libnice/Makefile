# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libnice
PORTVERSION=	0.1.13
CATEGORIES=	net-im devel
MASTER_SITES=	http://nice.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library and transmitter that implements ICE-19

USES=		gettext gmake gnome libtool localbase:ldflags pathfix pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	glib20 introspection:build
GNU_CONFIGURE=	yes
CPPFLAGS+=	-DHAVE_GETIFADDRS
INSTALL_TARGET=	install-strip

.if !defined(LIBNICE_SLAVE)
OPTIONS_DEFINE=	GUPNP
GUPNP_DESC=	UPnP IGD port mapping support
GUPNP_LIB_DEPENDS+=	libgupnp-igd-1.0.so:net/gupnp-igd
GUPNP_CONFIGURE_ENABLE=	gupnp
.endif

#.include <bsd.port.options.mk>

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
	@${REINPLACE_CMD} -e 's|-Werror||g' ${WRKSRC}/configure

.include <bsd.port.mk>
