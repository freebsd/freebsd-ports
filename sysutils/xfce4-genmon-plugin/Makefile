# New ports collection makefile for:	xfce4-genmon-plugin
# Date created:		2004-09-12
# Whom:			Matt Lancereau <matt@bsdfly.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-genmon-plugin
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	sysutils xfce
MASTER_SITES=	http://download.berlios.de/xfce-goodies/ \
		http://matt.nerim.net/xfce-goodies/
DIST_SUBDIR=	xfce4

MAINTAINER=	matt@bsdfly.org
COMMENT=	Generic Monitor XFce4 panel plugin

BUILD_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel
LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel

USE_GNOME=	gtk20 libxml2
USE_X_PREFIX=	yes
USE_INC_LIBTOOL_VER=15
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
