# New ports collection makefile for:	archie
# Version required:	1.4.1
# Date created:		20 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.1.1.1 1994/10/23 01:24:26 torstenb Exp $
#

DISTNAME=	c-archie-1.4.1-FIXED
MASTER_SITES=	ftp://nic.sura.net/pub/archie/clients/
CATEGORIES+=	networking
WRKSRC=		${WRKDIR}/archie-1.4.1-FIX
EXTRACT_SUFX=	.tar.Z

pre-install:
	mkdir -p ${PREFIX}/bin
	mkdir -p ${PREFIX}/man/man1

.include <bsd.port.mk>
