# New ports collection makefile for:	squidtimes
# Version required:	1.12
# Date created:		31 January 1999
# Whom:			Dima Sivachenko
#
# $Id: $
#

DISTNAME=	squidtimes-1.12-freebsd.bin
PKGNAME=	squidtimes-1.12
CATEGORIES=	www
MASTER_SITES=	http://www.cineca.it/~nico/binaries/ \
		http://www.FreeBSD.org/~billf/
EXTRACT_SUFX=

MAINTAINER=	dima@chg.ru

NO_BUILD=	YES
NO_WRKSUBDIR=	YES

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.

do-install:
		@ ${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME} ${PREFIX}/bin/squidtimes

post-install:
		@ ${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
