# New ports collection makefile for:	gtk-thinice-engine
# Date Created:				04 February 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk-thinice-engine
PORTVERSION=	2.0.2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.0
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.include <bsd.port.mk>
