# New ports collection makefile for:	rdist
# Version required:	rdist-6.1.0
# Date created:		19 August 1995
# Whom:			peter
# Based on patches by:  Deborah Bennett <deborah@microunity.com>
#
# $Id: Makefile,v 1.1 1995/08/19 13:51:11 peter Exp $
#

DISTNAME=	rdist-6.1.0
PKGNAME=	rdist-6.1.0
MASTER_SITES=	ftp://usc.edu/pub/rdist/
CATEGORIES+=	networking
MAINTAINER=	peter@FreeBSD.org

NO_WRKSUBDIR=	yes

# Copy the list of FreeBSD sites
pre-patch:
	cp ${FILESDIR}/mf.freebsd2 ${WRKSRC}/config
	cp ${FILESDIR}/os-freebsd2.h ${WRKSRC}/config

.include <bsd.port.mk>
