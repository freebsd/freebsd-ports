# New ports collection makefile for:	xgraph
# Date created:		24 November 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	xgraph
PORTVERSION=	11.3.2.20000910
CATEGORIES=	math print
MASTER_SITES=	ftp://ftp.cs.utoronto.ca/pub/radford/
DISTNAME=	xgraph-11
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	A program that helps you plot graphs

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
MAN1=		xgraph.1

post-install:
	@${MKDIR} ${PREFIX}/share/examples/xgraph
	${INSTALL_DATA} ${WRKSRC}/examples/*.xg ${PREFIX}/share/examples/xgraph

.include <bsd.port.mk>
