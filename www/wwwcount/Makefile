# New ports collection makefile for:    wwwcount
# WWW site: http://www.semcor.com/~muquit/Count.html
# For digit images look at:
# http://cervantes.learningco.com/kevin/digits/index.html
#
# Version required:     2.3
# Date created:         16 May 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.1.1.1 1996/05/16 20:43:58 ache Exp $
#

DISTNAME=       wwwcount2.3
PKGNAME=        wwwcount-2.3
CATEGORIES+=    www
MASTER_SITES=   ftp://warm.semcor.com/pub/muquit/wwwcount2.3/
GNU_CONFIGURE=  yes
IS_INTERACTIVE= yes

MAINTAINER=     ache@FreeBSD.ORG

pre-configure:
	cd ${WRKSRC}; yes "" | PREFIX=${PREFIX} ./Count-config

post-build:
	cd ${WRKSRC}/utils; ${MAKE}
	cd ${WRKSRC}; ./Gen-conf

do-install:
	cd ${WRKSRC}; yes "" | ./Count-install
	cd ${WRKSRC}/utils; \
		${INSTALL} -s -c -m ${BINMODE} -o ${BINOWN} -g ${BINGRP} mkstrip ${PREFIX}/bin; \
		${INSTALL} -c -m ${MANMODE} -o ${MANOWN} -g ${MANGRP} mkstrip.1 ${PREFIX}/man/man1; \
		${INSTALL} -c -m ${BINMODE} -o ${BINOWN} -g ${BINGRP} mkstrip.sh ${PREFIX}/etc/Counter/digits

.include <bsd.port.mk>
