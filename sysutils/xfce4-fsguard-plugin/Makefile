# New ports collection makefile for:	xfce4-fsguard-plugin
# Date created:		2003-12-20
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-fsguard-plugin
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	sysutils xfce
MASTER_SITES=	http://download.berlios.de/xfce-goodies/

MAINTAINER=	matt@rimasec.net
COMMENT=	XFce4 panel plugin to check a mountpoint for free disk space

BUILD_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel
LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.1:${PORTSDIR}/x11-toolkits/libxfce4gui \
		xml2.5:${PORTSDIR}/textproc/libxml2 \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel

USE_GNOME=	gtk20
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
