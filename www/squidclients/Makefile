# New ports collection makefile for:	squidclients
# Version required:	1.6
# Date created:		05 January 1999
# Whom:			Dima Sivachenko
#
# $Id$
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

do-install:
		@ ${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME} ${PREFIX}/bin/squidclients

post-install:
		@ ${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
