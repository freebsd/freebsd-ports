# New ports collection makefile for:	rkive
# Version required:	3.1
# Date created:		03 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id$
#

DISTNAME=	rkive3.1
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.sterling.com/rkive/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	torstenb@FreeBSD.ORG

# restrictive copyright
NO_PACKAGE=yes

pre-patch:
	@cp ${WRKSRC}/Makefile.dst ${WRKSRC}/Makefile
	@cp ${WRKSRC}/rkive.h.dst ${WRKSRC}/rkive.h

.include <bsd.port.mk>
