# New ports collection makefile for:	fontilus
# Date created:		15 February 2003
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fontilus
PORTVERSION=	0.4
CATEGORIES=	x11-fonts x11-fm
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.4
DIST_SUBDIR=	gnome2

MAINTAINER=	marcus@FreeBSD.org

LIB_DEPENDS=	nautilus.2:${PORTSDIR}/x11-fm/nautilus2

USE_BZIP2=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack gnomeprefix
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.include <bsd.port.mk>
