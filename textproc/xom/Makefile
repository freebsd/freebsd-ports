# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xom
PORTVERSION=	1.2.11
PORTEPOCH=	1
CATEGORIES=	textproc java
MASTER_SITES=	http://www.cafeconleche.org/XOM/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Open source (LGPL), tree-based API for processing XML with Java

RUN_DEPENDS=	${JAVALIBDIR}/xml-apis.jar:textproc/xerces-j \
		${JAVALIBDIR}/xalan.jar:textproc/xalan-j

USE_JAVA=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/XOM

OPTIONS_DEFINE=	DOCS EXAMPLES

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
PORTDOCS=	overview.html apidocs
PORTEXAMPLES=	xom-samples.jar

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xom-samples.jar ${STAGEDIR}${EXAMPLESDIR}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/apidocs
	cd ${WRKSRC}/ && ${FIND} ${PORTDOCS} \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1

.include <bsd.port.mk>
