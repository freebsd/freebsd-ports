# New ports collection makefile for:    Splitvt
# Version required:     1.6.1
# Date created:         Fri Oct 4, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.3 1996/11/13 12:41:23 asami Exp $
#

DISTNAME=	splitvt-1.6.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/console
EXTRACT_SUFX=	.tgz

MAINTAINER=     obrien@cs.ucdavis.edu

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
ALL_TARGET=
MAN1=		splitvt.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/splitvt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/splitvt.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
