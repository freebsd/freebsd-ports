# New ports collection makefile for:	squidclients
# Version required:	1.6
# Date created:		05 January 1999
# Whom:			Dima Sivachenko
#
# $Id: Makefile,v 1.1.1.1 1999/01/28 23:35:37 billf Exp $
#

DISTNAME=	squidclients-1.6-freebsd.bin
PKGNAME=	squidclients-1.6
CATEGORIES=	www
MASTER_SITES=	http://www.cineca.it/~nico/binaries/
EXTRACT_SUFX=

MAINTAINER=	dima@chg.ru

NO_BUILD=	YES
NO_WRKSUBDIR=	YES

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.

STRIP=
do-install:
		@ ${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME} ${PREFIX}/bin/squidclients

post-install:
		@ ${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
