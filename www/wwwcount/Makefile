# New ports collection makefile for:    wwwcount
# Version required:     2.4
# Date created:         16 May 1996
# Whom:                 ache
#
# $FreeBSD$
#

# WWW site: http://www.fccc.edu/users/muquit/Count.html
# For digit images look at:
# http://www.digitmania.holowww.com/

DISTNAME=       wwwcount2.4
PKGNAME=        wwwcount-2.4
CATEGORIES=     www
MASTER_SITES=   http://www.fccc.edu/users/muquit/src/wwwcount2.4/

MAINTAINER=     dervish@ikhala.tcimet.net

GNU_CONFIGURE=  yes
IS_INTERACTIVE= yes
USE_GMAKE=      yes
MAN1=		mkstrip.1

pre-configure:
	cd ${WRKSRC}; yes "" | PREFIX=${PREFIX} ./Count-config

post-build:
	cd ${WRKSRC}; ./Gen-conf

do-install:
	cd ${WRKSRC}; yes "" | ./Count-install
	cd ${WRKSRC}/utils/mkstrip; \
		${INSTALL_PROGRAM} extdgts mkstrip ${PREFIX}/bin; \
		${INSTALL_MAN} mkstrip.1 ${PREFIX}/man/man1; \
		${INSTALL_SCRIPT} mkstrip.sh ${PREFIX}/lib/Counter/digits

.include <bsd.port.mk>
