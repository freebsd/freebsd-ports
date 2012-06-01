# New ports collection makefile for:	gupnp-igd
# Date created:		2009-12-26
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gupnp-igd
PORTVERSION=	0.1.6
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.gupnp.org/sites/all/files/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to handle UPnP IGD port mapping

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pygobject-2.0.pc:${PORTSDIR}/devel/py-gobject
LIB_DEPENDS=	gupnp-1.0:${PORTSDIR}/net/gupnp

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack libglade2 glib20
USE_LDCONFIG=	yes
USE_PYTHON=	yes

# For gmake >= 3.82 -- no idea where this line comes from, patching
# the Makefile.in seems to have no effect
post-configure:
	@${REINPLACE_CMD} -e 's|^\[|# \[|' ${WRKSRC}/python/Makefile

.include <bsd.port.mk>
