# New ports collection makefile for:	xgraph
# Version required:	11.3.2
# Date created:		24 November 1994
# Whom:			asami
#
# $FreeBSD$
#

DISTNAME=	xgraph-11
PKGNAME=	xgraph-11.3.2
CATEGORIES=	math print
MASTER_SITES=	ftp://ftp.cs.utoronto.ca/pub/radford/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	sanpei@sanpei.org

USE_IMAKE=	yes
MAN1=		xgraph.1

post-install:
	@${MKDIR} ${PREFIX}/share/examples/xgraph
	${INSTALL_DATA} ${WRKSRC}/examples/*.xg ${PREFIX}/share/examples/xgraph

.include <bsd.port.mk>
