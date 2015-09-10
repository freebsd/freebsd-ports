# $FreeBSD$

PORTNAME=	zillion
PORTVERSION=	0.1
PORTREVISION=	5
CATEGORIES=	net gnustep
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-0_1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distributed computing project

LICENSE=	BSD

USES=		gnustep
USE_GNUSTEP=	back build

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's|^CC=|# CC=|' ${WRKSRC}/GNUmakefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Library/Bundles/simpleZillionJob.bundle/simpleZillionJob
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Tools/zillion
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Tools/zillionClient
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Tools/zillionLoader

.include <bsd.port.mk>
