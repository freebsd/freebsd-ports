# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httpcore
DISTVERSION=	4.3.3
CATEGORIES=	www java
MASTER_SITES=	APACHE/httpcomponents/${PORTNAME}/binary
DISTNAME=	httpcomponents-core-${DISTVERSION}-bin

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java components implementing the base HTTP protocol

LICENSE=	APACHE20

OPTIONS_DEFINE=	DOCS EXAMPLES

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/httpcomponents-core-${DISTVERSION}

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar %%JAVAJARDIR%%/${PORTNAME}-nio.jar

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

do-install:
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}-${DISTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME}-nio.jar..."
	@${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}-nio-${DISTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-nio.jar
	@${ECHO_MSG} " [DONE]"
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${FIND} tutorial \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1
	@${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES.txt ${STAGEDIR}${DOCSDIR}/
	@${ECHO_MSG} " [DONE]"
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO_MSG} -n ">> Installing examples..."
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${FIND} . \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${EXAMPLESDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
