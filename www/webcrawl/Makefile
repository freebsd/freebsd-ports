# New ports collection makefile for:	webcrawl
# Version required:	1.00
# Date created:		31 January 1999
# Whom:			Dima Sivachenko
#
# $Id:$
#

DISTNAME=	webcrawl-1.00
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/www/mirroring
EXTRACT_SUFX=	.tgz

MAINTAINER=	dima@chg.ru

ALL_TARGET=

MAN1=		webcrawl.1

do-install:

		@ ${INSTALL_PROGRAM} ${WRKSRC}/webcrawl ${PREFIX}/bin/
		@ ${INSTALL_MAN} ${WRKSRC}/webcrawl.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
