# New ports collection makefile for:	archie
# Version required:	1.4.1
# Date created:		20 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.3 1995/04/15 05:41:18 asami Exp $
#

DISTNAME=	c-archie-1.4.1-FIXED
PKGNAME=	archie-1.4.1
CATEGORIES+=	networking
MASTER_SITES=	ftp://nic.sura.net/pub/archie/clients/
EXTRACT_SUFX=	.tar.Z

WRKSRC=		${WRKDIR}/archie-1.4.1-FIX

MAINTAINER=	torstenb@FreeBSD.ORG

post-install:
	gzip -9nf ${PREFIX}/man/man1/archie.1

.include <bsd.port.mk>
