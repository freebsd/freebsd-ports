# $FreeBSD$

PORTNAME=	flot
PORTVERSION=	0.8.3
CATEGORIES=	www devel
MASTER_SITES=	http://www.flotcharts.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JavaScript plotting library for jQuery

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		zip
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES JQUERY
OPTIONS_DEFAULT=	JQUERY
OPTIONS_SUB=	yes

JQUERY_DESC=	Include provided JQuery 1.8.3

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/*.js ${STAGEDIR}${WWWDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
