# New ports collection makefile for:    nettest
# Date created:         Mon Oct 20 14:30:06 CDT 1997
# Whom:                 proot@iaces.com
#
# $Id$
#

DISTNAME=       nettest.92.11.09
PKGNAME=	nettest-92.11.09
EXTRACT_SUFX=	.tar.Z
CATEGORIES=	net
NO_WRKSUBDIR=	1
MASTER_SITES=   ftp://ftp.cray.com/src/nettest/
MAN8=		nettest.8

MAINTAINER=	proot@iaces.com

do-install:
	$(INSTALL_PROGRAM) -s  $(WRKSRC)/nettest $(PREFIX)/bin/nettest
	$(INSTALL_PROGRAM) -s $(WRKSRC)/nettestd $(PREFIX)/bin/nettestd
	$(INSTALL_MAN) $(WRKSRC)/nettest.8 $(PREFIX)/man/man8/nettest.8

.include <bsd.port.mk>
