# New ports collection makefile for:	pcbsd-meta-virtualbox
#
# $FreeBSD$
#

PORTNAME=	pcbsd-meta-virtualbox
PORTVERSION=	1429971087
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	kris@pcbsd.org
COMMENT=	The meta-port pcbsd-meta-virtualbox

RUN_DEPENDS=	virtualbox-ose>=0:${PORTSDIR}/emulators/virtualbox-ose \
		virtualbox-ose-kmod>=0:${PORTSDIR}/emulators/virtualbox-ose-kmod

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
