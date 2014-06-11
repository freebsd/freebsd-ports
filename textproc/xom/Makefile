# Created by: Herve Quiroz <hq@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xom
PORTVERSION=	1.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	textproc java
MASTER_SITES=	http://www.cafeconleche.org/XOM/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source (LGPL), tree-based API for processing XML with Java

RUN_DEPENDS=	${JAVALIBDIR}/xml-apis.jar:${PORTSDIR}/textproc/xerces-j \
		${JAVALIBDIR}/xalan.jar:${PORTSDIR}/textproc/xalan-j

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/XOM

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
.if !defined(NOPORTDOCS)
PORTDOCS=	overview.html apidocs
PLIST_FILES+=	%%EXAMPLESDIR%%/xom-samples.jar
PLIST_DIRS=	%%EXAMPLESDIR%%
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing samples in ${EXAMPLESDIR}..."
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/xom-samples.jar ${STAGEDIR}${EXAMPLESDIR}/
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/apidocs
	@cd ${WRKSRC}/ && ${FIND} ${PORTDOCS} \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
