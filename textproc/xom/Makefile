# New ports collection makefile for:	xom
# Date created:		2004-10-26
# Whom:			Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xom
PORTVERSION=	1.0
PORTEPOCH=	1
CATEGORIES=	textproc java
MASTER_SITES=	http://www.cafeconleche.org/XOM/

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Open source (LGPL), tree-based API for processing XML with Java

RUN_DEPENDS=	${JAVALIBDIR}/xml-apis.jar:${PORTSDIR}/textproc/xerces-j \
		${JAVALIBDIR}/xalan.jar:${PORTSDIR}/textproc/xalan-j

USE_JAVA=	yes
JAVA_VERSION=	1.2+
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
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing samples in ${EXAMPLESDIR}..."
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/xom-samples.jar ${EXAMPLESDIR}/
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}/apidocs
	@cd ${WRKSRC}/ && ${FIND} ${PORTDOCS} \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
