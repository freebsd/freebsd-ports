# New ports collection makefile for:		safesh
# Date created:					26 January 2002
# Whom:						eivind
#
# $FreeBSD$
#
# This port is self contained in the src directory.
#

PORTNAME=	safesh
PORTVERSION=	1.5
CATEGORIES=	security
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	eivind@FreeBSD.org
COMMENT=	Authentication manager for OpenSSH (making secure auth easier)

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

SRC=		${.CURDIR}/src

# XXX Anybody that know how to create manlinks from ports easily, please
# contact me.
MAN1=		${PORTNAME}.1

do-fetch:
	@${DO_NADA}

do-install:
	@${INSTALL_SCRIPT} ${SRC}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_SCRIPT} ${SRC}/cvs-safesh.sh ${PREFIX}/bin/cvs-safesh
	@${INSTALL_MAN} ${SRC}/${PORTNAME}.1 ${PREFIX}/man/man1
	@${LN} ${PREFIX}/bin/${PORTNAME} ${PREFIX}/bin/scpsh
	@${LN} ${PREFIX}/bin/${PORTNAME} ${PREFIX}/bin/safeshinstall

.include <bsd.port.mk>
