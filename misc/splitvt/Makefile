# New ports collection makefile for:    Splitvt
# Version required:     1.6.1
# Date created:         Fri Oct 4, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id: Makefile,v 1.5 1995/04/24 03:38:04 asami Exp $
#

DISTNAME=	splitvt-1.6.1
CATEGORIES+=	misc
MASTER_SITES=	ftp://ftp.cc.gatech.edu/pub/linux/utils/console/  \
		ftp://sunsite.unc.edu/pub/Linux/utils/console/  \
		ftp://ftp.funet.fi/pub/Linux/sunsite/utils/console/  \
		ftp://ftp.cs.cuhk.hk/pub/Linux/utils/console/
EXTRACT_SUFX=	.tgz

MAINTAINER=     obrien@cs.ucdavis.edu

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
ALL_TARGET=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/splitvt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/splitvt.1 ${PREFIX}/man/man1

post-install:
	${COMPRESS_MAN} ${PREFIX}/man/man1/splitvt.1

.include <bsd.port.mk>
