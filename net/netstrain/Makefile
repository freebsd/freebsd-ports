# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	netstrain
PORTVERSION=	3.0
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Tool to measure practical TCP throughput between two machines

PLIST_FILES=	bin/netstrain bin/netstraind
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/netstrain ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/netstraind ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
