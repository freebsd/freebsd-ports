# Created by: asami
# $FreeBSD$

PORTNAME=	xgraph
PORTVERSION=	11.3.2.20000910
PORTREVISION=	3
CATEGORIES=	math print
MASTER_SITES=	ftp://ftp.cs.utoronto.ca/pub/radford/
DISTNAME=	xgraph-11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program that helps you plot graphs

USES=		imake tar:Z
USE_XORG=	x11 xext
WRKSRC=		${WRKDIR}/${PORTNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/xgraph
	${INSTALL_DATA} ${WRKSRC}/examples/*.xg ${STAGEDIR}${PREFIX}/share/examples/xgraph

.include <bsd.port.mk>
