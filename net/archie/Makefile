# New ports collection makefile for:	archie
# Version required:	1.4.1
# Date created:		20 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.4 1995/05/06 00:27:35 torstenb Exp $
#

DISTNAME=	c-archie-1.4.1-FIXED
PKGNAME=	archie-1.4.1
CATEGORIES+=	net
MASTER_SITES=	ftp://nic.sura.net/pub/archie/clients/
EXTRACT_SUFX=	.tar.Z

WRKSRC=		${WRKDIR}/archie-1.4.1-FIX

MAINTAINER=	torstenb@FreeBSD.ORG

post-install:
	gzip -9nf ${PREFIX}/man/man1/archie.1

.include <bsd.port.mk>
