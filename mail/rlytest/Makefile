# New ports collection makefile for:	rlytest
# Version required:	1.15
# Date created:		16 January 1999
# Whom:			Paul Chvostek <paul@it.ca>
#
# $Id$
#

DISTNAME=	rlytest
PKGNAME=	rlytest-1.15
CATEGORIES=	mail security
MASTER_SITES=	http://www.unicom.com/sw/rlytest/

MAINTAINER=	paul@it.ca

MAN1=		rlytest.1

USE_PERL5=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=

post-patch:
	${MV} ${WRKSRC}/rlytest ${WRKSRC}/rlytest.chip; \
	${SED} 's:/usr/local/bin/perl:${PERL}:' < ${WRKSRC}/rlytest.chip > ${WRKSRC}/rlytest

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rlytest ${PREFIX}/bin/rlytest; \
	${INSTALL_MAN} ${WRKSRC}/rlytest.1 ${MANPREFIX}/man/man1/rlytest.1

post-install:
	${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
