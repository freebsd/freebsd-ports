# New ports collection makefile for:	metamail
# Version required:	2.7
# Date created:		17 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.1.1.1 1994/10/23 01:19:50 torstenb Exp $
#

DISTNAME=	mm2.7
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MASTER_SITES=	ftp://thumper.bellcore.com/pub/nsb/
CATEGORIES+=	mail
EXTRACT_SUFX=	.tar.Z

pre-install:
	   mkdir -p ${PREFIX}/bin
	   mkdir -p ${PREFIX}/etc
	   mkdir -p ${PREFIX}/man/man1
	   mkdir -p ${PREFIX}/man/man4

.include <bsd.port.mk>
