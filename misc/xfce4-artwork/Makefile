# New ports collection makefile for:	xfwm4-artwork
# Date created:				3 August 2003
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-artwork
PORTVERSION=	0.0.4
PORTREVISION=	4
CATEGORIES=	misc xfce
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
DIST_SUBDIR=	xfce4

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Additional artwork for the XFce4 desktop environment

RUN_DEPENDS=	${X11BASE}/bin/xfdesktop:${PORTSDIR}/x11-wm/xfce4-desktop

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
