# New ports collection makefile for:	xfce4-weather-plugin
# Date created:		04 April 2004
# Whom:			Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-weather-plugin
PORTVERSION=	0.3.9.1
PORTREVISION=	2
CATEGORIES=	misc xfce
MASTER_SITES=	http://download.berlios.de/xfce-goodies/

MAINTAINER=	filippo@widestore.net
COMMENT=	XFce 4 weather module for xfce4-panel

BUILD_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel
LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_X_PREFIX=	yes
USE_INC_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
