# New ports collection makefile for:	metamail
# Version required:	2.7
# Date created:		17 Oct 1994
# Whom:			torstenb
#
# $Id:$
#

DISTNAME=	mm2.7
WRKSRC=		${WRKDIR}/${DISTNAME}/src
MASTER_SITES=	ftp://thumper.bellcore.com/pub/nsb/
EXTRACT_SUFX=	.tar.Z

pre-install:
	   mkdir -p ${PREFIX}/bin
	   mkdir -p ${PREFIX}/etc
	   mkdir -p ${PREFIX}/man/man1
	   mkdir -p ${PREFIX}/man/man4

.include <bsd.port.mk>
