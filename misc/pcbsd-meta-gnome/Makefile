# New ports collection makefile for:	pcbsd-meta-gnome
#
# $FreeBSD$
#

PORTNAME=	pcbsd-meta-gnome
PORTVERSION=	1384912997
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	kris@pcbsd.org
COMMENT=	The meta-port pcbsd-meta-gnome

RUN_DEPENDS=	gnome3-lite>=0:${PORTSDIR}/x11/gnome3-lite \
		dconf-editor:${PORTSDIR}/devel/dconf-editor \
		gnome-terminal>=3.0.0:${PORTSDIR}/x11/gnome-terminal \
		gnome-calculator>=3.0.0:${PORTSDIR}/math/gnome-calculator \
		gnome-utils>=3.6.0:${PORTSDIR}/deskutils/gnome-utils \
		file-roller>=3.0.0:${PORTSDIR}/archivers/file-roller \
		gnome-system-monitor>=0:${PORTSDIR}/sysutils/gnome-system-monitor \
		gnome-shell-extensions>=3.0.0:${PORTSDIR}/x11/gnome-shell-extensions \
		gnome-tweak-tool:${PORTSDIR}/deskutils/gnome-tweak-tool

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
