# New ports collection makefile for:		safesh
# Date created:					26 January 2002
# Whom:						eivind
#
# $FreeBSD$
#
# This port is self contained in the src directory.
#

PORTNAME=	safesh
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	eivind@FreeBSD.org

BROKEN="Incompatible upgrade coming shortly"

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SRC=		${.CURDIR}/src

MAN1=		${PORTNAME}.1

do-fetch:
	@${DO_NADA}

do-install:
	@${INSTALL_SCRIPT} ${SRC}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_SCRIPT} ${SRC}/cvs-safesh.sh ${PREFIX}/bin/cvs-safesh
	@${INSTALL_MAN} ${SRC}/${PORTNAME}.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
