# New ports collection makefile for:	pcbsd-meta-nvidia
#
# $FreeBSD$
#

PORTNAME=	pcbsd-meta-nvidia
PORTVERSION=	1366133527
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	kris@pcbsd.org
COMMENT=	The meta-port pcbsd-meta-nvidia

RUN_DEPENDS=	nvidia-driver>=0:${PORTSDIR}/x11/nvidia-driver \
		nvidia-settings>=0:${PORTSDIR}/x11/nvidia-settings \
		nvidia-xconfig>=0:${PORTSDIR}/x11/nvidia-xconfig

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
