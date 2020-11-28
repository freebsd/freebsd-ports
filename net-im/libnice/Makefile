# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libnice
PORTVERSION=	0.1.18
CATEGORIES=	net-im devel
MASTER_SITES=	http://nice.freedesktop.org/releases/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library and transmitter that implements ICE-19

LICENSE=	LGPL21 MPL11
LICENSE_COMB=	dual

LIB_DEPENDS=	libgnutls.so:security/gnutls
BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc

USES=		gettext gmake gnome libtool localbase:ldflags pathfix pkgconfig meson python
USE_LDCONFIG=	yes
USE_GNOME=	glib20 introspection:build
CPPFLAGS+=	-DHAVE_GETIFADDRS
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	GUPNP
GUPNP_MESON_ENABLED=	gupnp
GUPNP_DESC=	UPnP IGD port mapping support
GUPNP_LIB_DEPENDS+=	libgupnp-igd-1.0.so:net/gupnp-igd

MESON_ARGS+=-Dtests=disabled

.if defined(LIBNICE_SLAVE)
USE_GSTREAMER1=	yes
MESON_ARGS+=-Dgstreamer=enabled -Dgst_version=1.0
.else
MESON_ARGS+=-Dgstreamer=disabled -Dgtk_doc=enabled
.endif

.include <bsd.port.mk>
