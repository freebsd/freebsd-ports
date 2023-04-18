PORTNAME=	gupnp-igd
PORTVERSION=	1.6.0
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to handle UPnP IGD port mapping
WWW=		https://wiki.gnome.org/Projects/GUPnP

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gobject-introspection>=0.10:devel/gobject-introspection \
		gssdp>=1.6.0:net/gssdp \
		gupnp>=1.6.0:net/gupnp
LIB_DEPENDS=	libgssdp-1.6.so:net/gssdp \
		libgupnp-1.6.so:net/gupnp

USES=		compiler:c11 gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build

MESON_ARGS=	--default-library=both -Dgtk_doc=false -Dintrospection=true
USE_CSTD=	c11
USE_LDCONFIG=	yes

.include <bsd.port.mk>
