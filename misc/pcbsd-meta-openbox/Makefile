# New ports collection makefile for:	pcbsd-meta-openbox
#
# $FreeBSD$
#

PORTNAME=	pcbsd-meta-openbox
PORTVERSION=	1366133527
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	kris@pcbsd.org
COMMENT=	The meta-port pcbsd-meta-openbox

RUN_DEPENDS=	openbox>=0:${PORTSDIR}/x11-wm/openbox \
		obconf>=0:${PORTSDIR}/x11-wm/obconf \
		obkey>=0:${PORTSDIR}/x11-wm/obkey \
		openbox-themes>=0:${PORTSDIR}/x11-themes/openbox-themes \
		obmenu>=0:${PORTSDIR}/x11-wm/obmenu

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
