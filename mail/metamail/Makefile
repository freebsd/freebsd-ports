# New ports collection makefile for:	metamail
# Version required:	2.7
# Date created:		17 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.2 1995/04/01 12:47:20 jkh Exp $
#

DISTNAME=	mm2.7
PKGNAME=	mm-2.7
CATEGORIES+=	mail
MASTER_SITES=	ftp://thumper.bellcore.com/pub/nsb/
EXTRACT_SUFX=	.tar.Z

WRKSRC=		${WRKDIR}/${DISTNAME}/src

pre-install:
	   mkdir -p ${PREFIX}/bin
	   mkdir -p ${PREFIX}/etc
	   mkdir -p ${PREFIX}/man/man1
	   mkdir -p ${PREFIX}/man/man4

.include <bsd.port.mk>
