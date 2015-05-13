# New ports collection makefile for:	pcbsd-role-office
#
# $FreeBSD$
#

PORTNAME=	pcbsd-role-office
PORTVERSION=	1416510521
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	joshms@pcbsd.org
COMMENT=	Includes office and productivity software

RUN_DEPENDS=	libreoffice>=0:${PORTSDIR}/editors/libreoffice \
		nano>=0:${PORTSDIR}/editors/nano \
		basket>=0:${PORTSDIR}/deskutils/basket \
		homebank>=0:${PORTSDIR}/finance/homebank \
		gnumeric>=0:${PORTSDIR}/math/gnumeric

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
