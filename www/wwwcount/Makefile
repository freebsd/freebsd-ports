# New ports collection makefile for:    wwwcount
# WWW site: http://www.semcor.com/~muquit/Count.html
# For digit images look at:
# http://cervantes.learningco.com/kevin/digits/index.html
#
# Version required:     2.3
# Date created:         16 May 1996
# Whom:                 ache
#
# $Id: Makefile,v 1.4 1996/04/27 12:51:27 ache Exp $
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
	cd ${WRKSRC}; ./Gen-conf

do-install:
	cd ${WRKSRC}; yes "" | ./Count-install

.include <bsd.port.mk>
