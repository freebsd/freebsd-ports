# New ports collection makefile for:	xfce4-themes
# Date created:		7 July 2003
# Whom:			James Earl <jdearl@telus.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-panel-themes
PORTVERSION=	4.0.3
PORTREVISION=	1
CATEGORIES=	misc xfce
MASTER_SITES=	http://www.xfce.org/archive/xfce-${PORTVERSION}/src/ \
                ftp://ftp.berlios.de/pub/xfce-goodies/${PORTVERSION}/xfce-${PORTVERSION}/src/ \
                http://hannelore.f1.fhtw-berlin.de/mirrors/xfce4/${PORTVERSION}/ \
                http://www.efd.lth.se/~c03bk/xfce4/mirror/tarballs/${PORTVERSION}/
DISTNAME=	xfce4-themes-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Icon themes for the XFce 4 panel

BUILD_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel
LIB_DEPENDS=	xfce4util.1:${PORTSDIR}/x11/libxfce4util \
		xfcegui4.1:${PORTSDIR}/x11-toolkits/libxfce4gui
RUN_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

NO_BUILD=	yes

.include <bsd.port.mk>
