# New ports collection makefile for:	rkive
# Version required:	3.1
# Date created:		03 Jul 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	rkive3.1
PKGNAME=	rkive-3.1
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.sterling.com/rkive/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	torstenb@FreeBSD.org

NO_CDROM=	"Don't make money from it"

pre-patch:
	@${CP} ${WRKSRC}/Makefile.dst ${WRKSRC}/Makefile
	@${CP} ${WRKSRC}/rkive.h.dst ${WRKSRC}/rkive.h

.include <bsd.port.mk>
