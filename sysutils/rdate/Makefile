# New ports collection makefile for: rdate
# Version required:     ....
# Date created:         19980128
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $Id: Makefile,v 1.1.1.1 1998/01/28 11:33:17 cracauer Exp $
#

DISTNAME=	rdate-1.0
CATEGORIES=     sysutils
MASTER_SITES=   http://www2.cons.org:8000/freebsd-distfiles/ \
		http://www.freebsd.org/~cracauer/freebsd-distfiles/

MAINTAINER=	cracauer@cons.org

MAN8=		rdate.8

post-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/rdate $(PREFIX)/bin/.
	$(INSTALL_MAN) $(WRKSRC)/rdate.8 $(PREFIX)/man/man8/.

.include <bsd.port.mk>
