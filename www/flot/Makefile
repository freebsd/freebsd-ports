# $FreeBSD$

PORTNAME=	flot
PORTVERSION=	0.8.3
CATEGORIES=	www devel
MASTER_SITES=	http://www.flotcharts.org/downloads/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	JavaScript plotting library for jQuery

LICENSE=	MIT

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		zip

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.js \
		${STAGEDIR}${WWWDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.md \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} "*" \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
