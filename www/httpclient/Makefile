# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httpclient
DISTVERSION=	4.3.6
CATEGORIES=	www java
MASTER_SITES=	APACHE/httpcomponents/${PORTNAME}/binary
DISTNAME=	httpcomponents-client-${DISTVERSION}-bin

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java components implementing an advanced HTTP client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES+=	cpe
CPE_PRODUCT=	commons-httpclient
CPE_VENDOR=	apache
RUN_DEPENDS=	${JAVALIBDIR}/httpcore.jar:www/httpcore \
		${JAVALIBDIR}/commons-logging.jar:java/jakarta-commons-logging \
		${JAVALIBDIR}/commons-codec.jar:java/jakarta-commons-codec

OPTIONS_DEFINE=	DOCS EXAMPLES
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/httpcomponents-client-${DISTVERSION}

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar \
		%%JAVAJARDIR%%/${PORTNAME}-cache.jar \
		%%JAVAJARDIR%%/${PORTNAME:S/client/mime/}.jar \
		%%JAVAJARDIR%%/fluent-hc.jar

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

do-install:
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}-${DISTVERSION}.jar \
		${STAGEDIR}/${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME}-cache.jar..."
	@${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}-cache-${DISTVERSION}.jar \
		${STAGEDIR}/${JAVAJARDIR}/${PORTNAME}-cache.jar
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME:S/client/mime/}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME:S/client/mime/}-${DISTVERSION}.jar \
		${STAGEDIR}/${JAVAJARDIR}/${PORTNAME:S/client/mime/}.jar
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/fluent-hc.jar..."
	@${INSTALL_DATA} ${WRKSRC}/lib/fluent-hc-${DISTVERSION}.jar \
		${STAGEDIR}/${JAVAJARDIR}/fluent-hc.jar
	@${ECHO_MSG} " [DONE]"
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	@cd ${WRKSRC} && ${FIND} tutorial \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}/${DOCSDIR} > /dev/null 2>&1
	@${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES.txt ${STAGEDIR}/${DOCSDIR}/
	@${ECHO_MSG} " [DONE]"
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO_MSG} -n ">> Installing examples..."
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${FIND} . \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}/${EXAMPLESDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
