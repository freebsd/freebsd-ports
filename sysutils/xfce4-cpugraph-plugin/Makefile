# New ports collection makefile for:	xfce4-cpugraph-plugin
# Date created:		2004-06-07
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-cpugraph-plugin
PORTVERSION=	0.2.0
CATEGORIES=	sysutils xfce
MASTER_SITES=	http://download.berlios.de/xfce-goodies/ \
		http://matt.nerim.net/xfce-goodies/ \
		http://www.bsd-blax.org/ports/mirrors/
DIST_SUBDIR=	xfce4

MAINTAINER=	matt@rimasec.net
COMMENT=	XFce4 systemload plugin with multiple CPU display modes

BUILD_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel
LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.1:${PORTSDIR}/x11-toolkits/libxfce4gui \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification
RUN_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel

USE_GCC=	3.3
USE_GNOME=	gtk20 libxml2
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.mk>
