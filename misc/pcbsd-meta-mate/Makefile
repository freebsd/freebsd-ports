# New ports collection makefile for:	pcbsd-meta-mate
#
# $FreeBSD$
#

PORTNAME=	pcbsd-meta-mate
PORTVERSION=	1421269030
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	kris@pcbsd.org
COMMENT=	The meta-port pcbsd-meta-mate

RUN_DEPENDS=	mate-base>=0:${PORTSDIR}/x11/mate-base \
		mate-terminal>=0:${PORTSDIR}/x11/mate-terminal \
		mate-system-monitor>=0:${PORTSDIR}/sysutils/mate-system-monitor \
		mate-media>=0:${PORTSDIR}/audio/mate-media \
		mate-power-manager>=0:${PORTSDIR}/sysutils/mate-power-manager \
		mate-calc>=0:${PORTSDIR}/math/mate-calc \
		mate-applets>=0:${PORTSDIR}/x11/mate-applets \
		mate-utils>=1.8.1:${PORTSDIR}/deskutils/mate-utils \
		engrampa>=0:${PORTSDIR}/archivers/engrampa \
		atril>=0:${PORTSDIR}/graphics/atril \
		pluma>=0:${PORTSDIR}/editors/pluma
NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
