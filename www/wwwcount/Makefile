# New ports collection makefile for:    wwwcount
# Version required:     2.3
# Date created:         16 May 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.4 1996/05/27 03:44:31 asami Exp $
#

# WWW site: http://www.fccc.edu/users/muquit/Count.html
# For digit images look at:
# http://www.digitmania.holowww.com/

DISTNAME=       wwwcount2.3
PKGNAME=        wwwcount-2.3
CATEGORIES+=    www
MASTER_SITES=   http://www.fccc.edu/users/muquit/src/wwwcount2.3/

MAINTAINER=     ache@FreeBSD.ORG

GNU_CONFIGURE=  yes
IS_INTERACTIVE= yes

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
		${INSTALL} -c -m ${BINMODE} -o ${BINOWN} -g ${BINGRP} mkstrip.sh ${PREFIX}/lib/Counter/digits

.include <bsd.port.mk>
