# Created by: asami
# $FreeBSD$

PORTNAME=	xgraph
PORTVERSION=	11.3.2.20000910
PORTREVISION=	4
CATEGORIES=	math print
MASTER_SITES=	ftp://ftp.cs.utoronto.ca/pub/radford/
DISTNAME=	xgraph-11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program that helps you plot graphs

LICENSE=	XGRAPH
LICENSE_NAME=	xgraph license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		imake tar:Z xorg
USE_XORG=	x11 xext
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

post-extract:
	@${SED} -ne '2,19 {s|^ \* *||;p;}' < ${WRKSRC}/copyright.h > ${WRKSRC}/COPYING

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/xgraph
	${INSTALL_DATA} ${WRKSRC}/examples/*.xg ${STAGEDIR}${PREFIX}/share/examples/xgraph

.include <bsd.port.mk>
