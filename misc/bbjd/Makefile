PORTNAME=	bbjd
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	SUNSITE/games/strategy

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Beat the blackjack dealer

USES=		gmake

WRKSRC=		${WRKDIR}/bbjd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bbjd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/simbj ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bbjd
	${INSTALL_DATA} ${WRKSRC}/Interactive ${STAGEDIR}${PREFIX}/share/bbjd
	${INSTALL_DATA} ${WRKSRC}/Simulation ${STAGEDIR}${PREFIX}/share/bbjd
	${INSTALL_DATA} ${WRKSRC}/Theory ${STAGEDIR}${PREFIX}/share/bbjd

.include <bsd.port.mk>
