# New ports collection makefile for:    gnomemm
# Date created:         18 Jun 2000
# Whom:                 Erich Zigler <erich@tacni.net>
#
# $FreeBSD$
#

PORTNAME=      gnomemm
PORTVERSION=   1.1.10
CATEGORIES=    x11-toolkits
MASTER_SITES=  http://download.sourceforge.net/gtkmm/

MAINTAINER=    erich@tacni.net

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		gtkmm-1.2:${PORTSDIR}/x11-toolkits/gtk--
BUILD_DEPENDS=	m4:${PORTSDIR}/devel/m4

GTK_CONFIG?=    ${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=--enable-static=yes
CONFIGURE_ENV+=	GTK_CONFIG="${GTK_CONFIG}"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
