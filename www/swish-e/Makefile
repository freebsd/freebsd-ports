# New ports collection makefile for:    swish-e
# Version required:     		1.3.2
# Date created:         		23 Feb 98
# Whom:              			Daniel O'Connor <doconnor@gsoft.com.au>
#
# $FreeBSD$
#

DISTNAME=       swish-efiles.1.3.2
PKGNAME=        swish-e-1.3.2
CATEGORIES=     www textproc
MASTER_SITES=   ftp://sunsite.berkeley.edu/pub/swish-e/

MAINTAINER=	doconnor@gsoft.com.au

WRKSRC=		${WRKDIR}/src
USE_GMAKE=	yes

do-install:
	$(INSTALL_PROGRAM) ${WRKSRC}/swish-e ${PREFIX}/bin
	$(MKDIR) -p $(PREFIX)/share/examples/swish-e
	$(INSTALL_DATA) ${WRKSRC}/user.config ${PREFIX}/share/examples/swish-e
	$(INSTALL_DATA) ${WRKSRC}/test.html ${PREFIX}/share/examples/swish-e
	$(INSTALL_DATA) ${WRKSRC}/swishspider ${PREFIX}/share/examples/swish-e
	$(INSTALL_DATA) ${WRKSRC}/README-SWISH-E ${PREFIX}/share/examples/swish-e

.include <bsd.port.mk>
