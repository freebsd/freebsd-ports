# New ports collection makefile for:	gupnp-igd
# Date created:		2009-12-26
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gupnp-igd
PORTVERSION=	0.2.1
CATEGORIES=	net
MASTER_SITES=	http://www.gupnp.org/sites/all/files/sources/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library to handle UPnP IGD port mapping

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pygobject-2.0.pc:${PORTSDIR}/devel/py-gobject \
		gobject-introspection>=0.10:${PORTSDIR}/devel/gobject-introspection \
		gupnp>=0.18:${PORTSDIR}/net/gupnp
LIB_DEPENDS=	gupnp-1.0:${PORTSDIR}/net/gupnp
RUN_DEPENDS=	gupnp>=0.18:${PORTSDIR}/net/gupnp

CONFIGURE_ARGS=	--enable-introspection=yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack
USE_LDCONFIG=	yes
USE_PYTHON=	yes

.include <bsd.port.mk>
