# New ports collection makefile for:	rdist
# Version required:	rdist-6.1.0
# Date created:		19 August 1995
# Whom:			peter
# Based on patches by:  Deborah Bennett <deborah@microunity.com>
#
# $Id: Makefile,v 1.3 1995/08/21 02:41:46 asami Exp $
#

DISTNAME=	rdist-6.1.0
CATEGORIES+=	networking
MASTER_SITES=	ftp://usc.edu/pub/rdist/

MAINTAINER=	peter@FreeBSD.org

NO_WRKSUBDIR=	yes

# Copy the list of FreeBSD sites
pre-patch:
	cp ${FILESDIR}/mf.freebsd2 ${WRKSRC}/config
	cp ${FILESDIR}/os-freebsd2.h ${WRKSRC}/config

post-install:
	strip ${PREFIX}/bin/rdist6
	strip ${PREFIX}/bin/rdistd
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man1/rdist6.1
	gzip -9nf ${PREFIX}/man/man8/rdistd.8
.endif

.include <bsd.port.mk>
