# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gupnp-igd
PORTVERSION=	0.2.5
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to handle UPnP IGD port mapping

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gobject-introspection>=0.10:devel/gobject-introspection \
		gupnp>=0.18:net/gupnp
LIB_DEPENDS=	libgssdp-1.2.so:net/gssdp \
		libgupnp-1.2.so:net/gupnp
RUN_DEPENDS=	gupnp>=0.18:net/gupnp

USES=		compiler:c11 gmake gnome libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build

CONFIGURE_ARGS=	--disable-python --enable-introspection=yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
