# New ports collection makefile for:	pcbsd-role-devel
#
# $FreeBSD$
#

PORTNAME=	pcbsd-role-devel
PORTVERSION=	1416676585
CATEGORIES=	misc
MASTER_SITES=	# empty
DISTFILES=	# none

MAINTAINER=	joshms@pcbsd.org
COMMENT=	Includes application development software

RUN_DEPENDS=	eclipse>=0:${PORTSDIR}/java/eclipse \
		git>=0:${PORTSDIR}/devel/git \
		ninja-ide>=0:${PORTSDIR}/devel/ninja-ide \
		qtcreator>=0:${PORTSDIR}/devel/qtcreator \
		subversion>=0:${PORTSDIR}/devel/subversion \
		hs-haskell-platform>=0:${PORTSDIR}/devel/hs-haskell-platform

NO_BUILD=	yes

do-install:
	${DO_NADA}

.include <bsd.port.mk>
