# $FreeBSD$

PORTNAME=	zenxml
PORTVERSION=	2.4
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	zenXml_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple XML processing using C++

LICENSE=	GPLv3

USES=		dos2unix zip

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

ZENINC=		${PREFIX}/include/${PORTNAME:S/xml//}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${ZENINC}
	cd ${WRKSRC}/${PORTNAME} && \
	    ${COPYTREE_SHARE} \*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/${PORTNAME:S/xml//} && \
	    ${COPYTREE_SHARE} \*.h ${STAGEDIR}${ZENINC}

do-install-DOCS-on:
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
