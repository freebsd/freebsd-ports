# New ports collection makefile for:	rdist
# Version required:	rdist-6.1.3
# Date created:		19 August 1995
# Whom:			peter
#
# $Id: Makefile,v 1.6 1996/05/17 11:14:53 peter Exp $
#

DISTNAME=	rdist-6.1.3
CATEGORIES+=	net
MASTER_SITES=	ftp://usc.edu/pub/rdist/

MAINTAINER=	peter@FreeBSD.org

INSTALL_TARGET+=install.man

post-install:
	strip ${PREFIX}/bin/rdist6
	strip ${PREFIX}/bin/rdistd
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/rdist6.1
	gzip -9nf ${PREFIX}/man/man8/rdistd.8
.endif

.include <bsd.port.mk>
