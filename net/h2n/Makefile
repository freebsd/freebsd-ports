# New ports collection makefile for:	h2n
# Version required:	1.29
# Date created:		27 Nov 1997
# Whom:			SADA Kenji <sada@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1998/11/22 17:39:56 sada Exp $
#

DISTNAME=	dns
PKGNAME=	h2n-1.29
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/published/oreilly/nutshell/dnsbind/ \
		ftp://ftp.uu.net/published/oreilly/nutshell/dnsbind/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	sada@FreeBSD.ORG

NO_BUILD=	YES
NO_WRKSUBDIR=	YES
RESTRICTED=	"Never get an approval yet."

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/h2n ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/h2n.man ${PREFIX}/man/cat8/h2n.8

.include <bsd.port.mk>
