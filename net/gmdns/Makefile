# New ports collection makefile for:	gmdns
# Date created:				05 June 2004
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gmdns
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.1
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNU implementation of multicast DNS, part of Zeroconf

USE_BZIP2=	yes
USE_GNOME=	gnomehack glib20
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
