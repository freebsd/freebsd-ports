# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gupnp-dlna
PORTVERSION=	0.10.3
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Helpers for DLNA-related tasks using GUPnP

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala \
		gupnp>=0.19.0:net/gupnp
LIB_DEPENDS=	libgupnp-1.0.so:net/gupnp
RUN_DEPENDS=	gupnp>=0.19.0:net/gupnp

CONFIGURE_ARGS=	--enable-introspection \
		--enable-gstreamer-metadata-backend

USES=		gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 introspection:build libxml2
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
