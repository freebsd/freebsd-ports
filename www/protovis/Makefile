# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	protovis
PORTVERSION=	3.2
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE
EXTRACT_SUFX=	.zip

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	JavaScript graphical toolkit for data visualization

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_BUILD=	yes

PORTDOCS=	*
PORTEXAMPLES=	*

PROJECTHOST=	${PORTNAME}-js

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/ ${STAGEDIR}${EXAMPLESDIR}/ ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} *.js ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC}/jsdoc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
