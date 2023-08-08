PORTNAME=	gupnp-igd
PORTVERSION=	1.2.0
CATEGORIES=	net
MASTER_SITES=	GNOME
PKGNAMESUFFIX=	12

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to handle UPnP IGD port mapping
WWW=		https://wiki.gnome.org/Projects/GUPnP

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gobject-introspection>=0.10:devel/gobject-introspection \
		gssdp14>=1.2.0:net/gssdp14 \
		gupnp14>=1.2.0:net/gupnp14
LIB_DEPENDS=	libgssdp-1.2.so:net/gssdp14 \
		libgupnp-1.2.so:net/gupnp14

USES=		compiler:c11 gnome meson pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build

MESON_ARGS=	--default-library=both -Dgtk_doc=false -Dintrospection=true
USE_CSTD=	c11
USE_LDCONFIG=	yes

PORTSCOUT=	limit:^1\.2\.

.include <bsd.port.mk>
