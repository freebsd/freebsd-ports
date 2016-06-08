# New ports collection makefile for:	pcbsd-role-science
#
# $FreeBSD$
#

PORTNAME=	pcbsd-role-science
PORTVERSION=	1416932776
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	joshms@pcbsd.org
COMMENT=	Includes scientific applications

RUN_DEPENDS=	galculator>=0:${PORTSDIR}/math/galculator \
		avogadro:${PORTSDIR}/science/avogadro \
		openbabel>=0:${PORTSDIR}/science/openbabel \
		mpqc>=0:${PORTSDIR}/science/mpqc \
		gnuplot>=0:${PORTSDIR}/math/gnuplot \
		open-axiom:${PORTSDIR}/math/open-axiom \
		geoserver>=0:${PORTSDIR}/graphics/geoserver \
		grass64:${PORTSDIR}/databases/grass

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
