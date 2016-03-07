# $FreeBSD$

PORTNAME=	zenxml
PORTVERSION=	2.3
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	zenXml_${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Simple XML processing using C++

LICENSE=	GPLv3

USES=		dos2unix zip

NO_BUILD=	yes
WRKSRC=		${WRKDIR}

ZENINC=		${PREFIX}/include/${PORTNAME:S/xml//}

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${MKDIR} ${STAGEDIR}${ZENINC}
	(cd ${WRKSRC}/${PORTNAME} && \
	    ${COPYTREE_SHARE} \*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME})
	(cd ${WRKSRC}/${PORTNAME:S/xml//} && \
	    ${COPYTREE_SHARE} \*.h ${STAGEDIR}${ZENINC})

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
