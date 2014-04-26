# $FreeBSD$

PORTNAME=	flot
PORTVERSION=	0.8.2
CATEGORIES=	www devel
MASTER_SITES=	http://www.flotcharts.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JavaScript plotting library for jQuery

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		zip

USERS=	www
GROUPS=	www

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
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} "*" \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
