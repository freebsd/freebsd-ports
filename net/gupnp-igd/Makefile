# New ports collection makefile for:	gupnp-igd
# Date created:		2009-12-26
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gupnp-igd
PORTVERSION=	0.1.5
CATEGORIES=	net
MASTER_SITES=	http://www.gupnp.org/sources/${PORTNAME}/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Library to handle UPnP IGD port mapping

LIB_DEPENDS=	gupnp-1.0:${PORTSDIR}/net/gupnp

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack libglade2 glib20
USE_LDCONFIG=	yes

.include <bsd.port.mk>
