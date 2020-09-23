# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gupnp-igd
PORTVERSION=	1.2.0
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to handle UPnP IGD port mapping

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gobject-introspection>=0.10:devel/gobject-introspection \
		gupnp>=1.2.0:net/gupnp \
		gssdp>=1.2.0:net/gssdp
LIB_DEPENDS=	libgssdp-1.2.so:net/gssdp \
		libgupnp-1.2.so:net/gupnp
RUN_DEPENDS=	gupnp>=1.2.0:net/gupnp \
		gssdp>=1.2.0:net/gssdp

USES=		compiler:c11 gnome meson pathfix pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build

MESON_ARGS=	-Dgtk_doc=false -Dintrospection=true
USE_CSTD=	c11
USE_LDCONFIG=	yes

.include <bsd.port.mk>
