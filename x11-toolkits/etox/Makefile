# New ports collection makefile for:	etox
# Date created:		05/09/2005
# Whom:			vanilla
#
# $FreeBSD$
#

PORTNAME=	etox
PORTVERSION=	0.9.0.004
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	vanilla

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	An evas based text layout library

LIB_DEPENDS=	evas.1:${PORTSDIR}/graphics/evas \
		ecore.1:${PORTSDIR}/x11/ecore \
		edb.1:${PORTSDIR}/databases/edb

USE_X_PREFIX=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomehack pkgconfig gnometarget
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
