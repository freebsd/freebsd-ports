# New ports collection makefile for:	pcbsd-meta-xfce
#
# $FreeBSD$
#

PORTNAME=	pcbsd-meta-xfce
PORTVERSION=	1401977013
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	kris@pcbsd.org
COMMENT=	The meta-port pcbsd-meta-xfce

RUN_DEPENDS=	xfce>=0:${PORTSDIR}/x11-wm/xfce4 \
		midori>=0:${PORTSDIR}/www/midori \
		xfburn>=0:${PORTSDIR}/sysutils/xfburn \
		ristretto>=0:${PORTSDIR}/graphics/ristretto \
		gtk-murrine-engine>=0:${PORTSDIR}/x11-themes/gtk-murrine-engine \
		xfce4-wm-themes>=0:${PORTSDIR}/misc/xfce4-wm-themes \
		xfce4-power-manager>=0:${PORTSDIR}/sysutils/xfce4-power-manager \
		xfce4-mixer>=0:${PORTSDIR}/audio/xfce4-mixer \
		xfce4-battery-plugin>=0:${PORTSDIR}/sysutils/xfce4-battery-plugin \
		thunar-archive-plugin>=0:${PORTSDIR}/archivers/thunar-archive-plugin \
		xarchiver:${PORTSDIR}/archivers/xarchiver \
		squeeze:${PORTSDIR}/archivers/squeeze \
		xscreensaver:${PORTSDIR}/x11/xscreensaver

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
