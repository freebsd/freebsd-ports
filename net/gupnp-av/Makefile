# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gupnp-av
PORTVERSION=	0.12.1
CATEGORIES=	net
MASTER_SITES=	GNOME

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Helpers for audio/video applications using GUPnP

LICENSE=	LGPL20

BUILD_DEPENDS=	gobject-introspection>=0.9.5:${PORTSDIR}/devel/gobject-introspection \
		gupnp>=0.19.0:${PORTSDIR}/net/gupnp
LIB_DEPENDS=	gupnp-1.0:${PORTSDIR}/net/gupnp
RUN_DEPENDS=	gupnp>=0.19.0:${PORTSDIR}/net/gupnp

CONFIGURE_ARGS=	--enable-introspection=yes
CONFIGURE_ENV=	VAPIGEN=""
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_XZ=		yes
USES=		pathfix

.include <bsd.port.mk>
