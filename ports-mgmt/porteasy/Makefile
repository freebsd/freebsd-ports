# New ports collection makefile for:		porteasy
# Date created:					September 19th 2000
# Whom:						des
#
# $FreeBSD$
#
# This port is self contained in the src directory.
#

PORTNAME=	porteasy
PORTVERSION=	2.8.3
CATEGORIES=	misc
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	des@FreeBSD.org
COMMENT=	A tool for fetching and building ports

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PERL5=	yes

SRC=		${.CURDIR}/src

MAN8=		porteasy.8

do-fetch:
	@${DO_NADA}

do-configure:
	@${SED} "s,%%PREFIX%%,${PREFIX}," ${SRC}/porteasy.pl >${WRKDIR}/porteasy
do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/porteasy ${PREFIX}/bin/porteasy
	@${INSTALL_MAN} ${SRC}/porteasy.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
