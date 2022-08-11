PORTNAME=	npc
PORTVERSION=	0.83
CATEGORIES=	www
MASTER_SITES=	http://www2.biglobe.ne.jp/%7Enir/soft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Animated web counter

WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKE_ARGS=	INDEX_DIR="${INDEX_DIR}"

INDEX_DIR=	${PREFIX}/etc/npc

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/cgi-bin
	${INSTALL_PROGRAM} ${WRKSRC}/npc.cgi ${STAGEDIR}${PREFIX}/www/cgi-bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/npc
	(cd ${WRKSRC}/../conf && \
		${INSTALL_DATA} sample1.idx sample2.idx ${STAGEDIR}${PREFIX}/share/examples/npc)
	${MKDIR} ${STAGEDIR}${INDEX_DIR}

.include <bsd.port.mk>
