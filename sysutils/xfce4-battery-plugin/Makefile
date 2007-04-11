# New ports collection makefile for:	xfce-battery-plugin
# Date created:		31 June 2003
# Whom:			Thorsten Greiner <thorsten.greiner@web.de>
#
# $FreeBSD$
#

PORTNAME=	xfce4-battery-plugin
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	sysutils xfce
MASTER_SITES=	http://goodies.xfce.org/releases/${PORTNAME}/
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Battery monitor panel plugin for XFce4

BUILD_DEPENDS=	xfce4-panel:${PORTSDIR}/x11-wm/xfce4-panel
RUN_DEPENDS=	${BUILD_DEPENDS}

ONLY_FOR_ARCHS=	i386

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel
USE_XLIB=	yes

.include <bsd.port.mk>
