# New ports collection makefile for:    gnomemm
# Date created:         18 Jun 2000
# Whom:                 Erich Zigler <erich@tacni.net>
#
# $FreeBSD$
#

PORTNAME=	gnomemm
PORTVERSION=	1.1.15
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtkmm

MAINTAINER=	erich@tacni.net

LIB_DEPENDS=	gtkmm.2:${PORTSDIR}/x11-toolkits/gtk--
BUILD_DEPENDS=	m4:${PORTSDIR}/devel/m4

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static

.include <bsd.port.mk>
