# New ports collection makefile for:	archie
# Version required:	1.4.1
# Date created:		20 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.2 1995/04/01 12:47:44 jkh Exp $
#

DISTNAME=	c-archie-1.4.1-FIXED
PKGNAME=	archie-1.4.1
CATEGORIES+=	networking
MASTER_SITES=	ftp://nic.sura.net/pub/archie/clients/
EXTRACT_SUFX=	.tar.Z

WRKSRC=		${WRKDIR}/archie-1.4.1-FIX

pre-install:
	mkdir -p ${PREFIX}/bin
	mkdir -p ${PREFIX}/man/man1

.include <bsd.port.mk>
