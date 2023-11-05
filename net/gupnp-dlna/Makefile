PORTNAME=	gupnp-dlna
PORTVERSION=	0.10.3
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Helpers for DLNA-related tasks using GUPnP
WWW=		https://wiki.gnome.org/Projects/GUPnP

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Depends on deprecated port net/gupnp14
EXPIRATION_DATE=2023-11-30

BUILD_DEPENDS=	gupnp14>=0.19.0:net/gupnp14
LIB_DEPENDS=	libgupnp-1.2.so:net/gupnp14
RUN_DEPENDS=	gupnp14>=0.19.0:net/gupnp14

CONFIGURE_ARGS=	--enable-introspection \
		--enable-gstreamer-metadata-backend

USES=		gmake gnome gstreamer libtool pathfix pkgconfig tar:xz vala:build
USE_GNOME=	glib20 introspection:build libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
