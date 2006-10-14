# New ports collection makefile for:	xfce4-genmon-plugin
# Date created:		2004-09-12
# Whom:			Matt Lancereau <ports@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/sysutils/xfce4-genmon-plugin/Makefile,v 1.1 2006/10/02 20:33:19 ahze Exp $

PORTNAME=	xfce4-genmon-plugin
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	sysutils xfce
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
DIST_SUBDIR=	xfce4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic Monitor XFce4 panel plugin

BUILD_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel
LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.3:${PORTSDIR}/x11-toolkits/libxfce4gui \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel

USE_GNOME=	gtk20 libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
