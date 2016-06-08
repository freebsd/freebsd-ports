# New ports collection makefile for:	pcbsd-role-cad
#
# $FreeBSD$
#

PORTNAME=	pcbsd-role-cad
PORTVERSION=	1416510521
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	joshms@pcbsd.org
COMMENT=	Includes software for the cad role

RUN_DEPENDS=	librecad>=0:${PORTSDIR}/cad/librecad \
		leocad>=0:${PORTSDIR}/cad/leocad \
		brlcad>=0:${PORTSDIR}/cad/brlcad \
		qcad>=0:${PORTSDIR}/cad/qcad

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
