# New ports collection makefile for:	rkive
# Version required:	3.1
# Date created:		03 Jul 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.3 1996/12/07 09:28:46 max Exp $
#

DISTNAME=	rkive3.1
PKGNAME=	rkive-3.1
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.sterling.com/rkive/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	torstenb@FreeBSD.ORG

NO_CDROM=	"Don't make money from it"

pre-patch:
	@cp ${WRKSRC}/Makefile.dst ${WRKSRC}/Makefile
	@cp ${WRKSRC}/rkive.h.dst ${WRKSRC}/rkive.h

.include <bsd.port.mk>
