# New ports collection makefile for:	gtkglarea2
# Date created:		13 August 2002
# Whom:			Marc Recht <marc@informatik.uni-bremen.de>
#
# $FreeBSD$

PORTNAME=	gtkglarea
PORTVERSION=	1.99.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gtkglarea/1.99
DISTNAME=	gtkglarea-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	marc@informatik.uni-bremen.de

LIB_DEPENDS=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack
USE_BZIP2=	yes
USE_MESA=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-lib-GL

.include <bsd.port.mk>
