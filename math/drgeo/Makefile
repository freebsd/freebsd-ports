# New ports collection makefile for:	drgenius
# Date created:				11 January 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	drgenius
PORTVERSION=	0.8.4
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.ofset.org/drgenius/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Gnome Interactive Geometry Sofware

BUILD_DEPENDS=	gob:${PORTSDIR}/x11-toolkits/gob
LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget libglade
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
