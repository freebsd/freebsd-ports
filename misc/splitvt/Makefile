# New ports collection makefile for:    Splitvt
# Version required:     1.6.1
# Date created:         Fri Oct 4, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.2 1996/11/11 05:50:11 obrien Exp $
#

DISTNAME=	splitvt-1.6.1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.cc.gatech.edu/pub/linux/utils/console/  \
		ftp://sunsite.unc.edu/pub/Linux/utils/console/  \
		ftp://ftp.funet.fi/pub/Linux/sunsite/utils/console/  \
		ftp://ftp.cs.cuhk.hk/pub/Linux/utils/console/
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
