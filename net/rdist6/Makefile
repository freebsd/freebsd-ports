# New ports collection makefile for:	rdist
# Version required:	rdist-6.1.2
# Date created:		19 August 1995
# Whom:			peter
#
# $Id: Makefile,v 1.5 1995/11/27 04:05:25 asami Exp $
#

DISTNAME=	rdist-6.1.2
CATEGORIES+=	net
MASTER_SITES=	ftp://usc.edu/pub/rdist/

MAINTAINER=	peter@FreeBSD.org

post-install:
	strip ${PREFIX}/bin/rdist6
	strip ${PREFIX}/bin/rdistd
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/rdist6.1
	gzip -9nf ${PREFIX}/man/man8/rdistd.8
.endif

.include <bsd.port.mk>
