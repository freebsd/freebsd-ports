# New ports collection makefile for:    nettest
# Date created:         Mon Oct 20 14:30:06 CDT 1997
# Whom:                 proot@iaces.com
#
# $FreeBSD$
#

PORTNAME=	nettest
PORTVERSION=	92.11.09
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.cray.com/src/nettest/
DISTNAME=	nettest.92.11.09
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Performs client and server functions for timing data throughput

NO_WRKSUBDIR=	yes
MAN8=		nettest.8

do-install:
	$(INSTALL_PROGRAM) -s  $(WRKSRC)/nettest $(PREFIX)/bin/nettest
	$(INSTALL_PROGRAM) -s $(WRKSRC)/nettestd $(PREFIX)/bin/nettestd
	$(INSTALL_MAN) $(WRKSRC)/nettest.8 $(PREFIX)/man/man8/nettest.8

.include <bsd.port.mk>
