# New ports collection makefile for:    xmitnin
# Version required:     1.9
# Date created:         29 Nov 1997
# Whom:                 Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

DISTNAME=	xmitBin-1.9
PKGNAME=	xmitbin-1.9
CATEGORIES=	news mail
MASTER_SITES=	ftp://ftp.cadence.com/utils/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dburr@FreeBSD.ORG

MAN1=		xmitBin.1
NO_WRKSUBDIR=	YES

post-install:
		@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
