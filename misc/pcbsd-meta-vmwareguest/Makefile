# New ports collection makefile for:	pcbsd-meta-vmwareguest
#
# $FreeBSD$
#

PORTNAME=	pcbsd-meta-vmwareguest
PORTVERSION=	1426698080
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	kris@pcbsd.org
COMMENT=	The meta-port pcbsd-meta-vmwareguest

RUN_DEPENDS=	vmtoolsd:${PORTSDIR}/emulators/open-vm-tools-nox11 \
		xf86-video-vmware>=0:${PORTSDIR}/x11-drivers/xf86-video-vmware

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
