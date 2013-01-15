# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	httpclient
DISTVERSION=	4.2.3
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	httpcomponents/${PORTNAME}/binary
DISTNAME=	httpcomponents-client-${DISTVERSION}-bin

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java components implementing an advanced HTTP client

LICENSE=	AL2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${JAVAJARDIR}/httpcore.jar:${PORTSDIR}/www/httpcore \
		${JAVAJARDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging \
		${JAVAJARDIR}/commons-codec.jar:${PORTSDIR}/java/jakarta-commons-codec

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
		${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME}-cache.jar..."
	@${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}-cache-${DISTVERSION}.jar \
		${JAVAJARDIR}/${PORTNAME}-cache.jar
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME:S/client/mime/}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME:S/client/mime/}-${DISTVERSION}.jar \
		${JAVAJARDIR}/${PORTNAME:S/client/mime/}.jar
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/fluent-hc.jar..."
	@${INSTALL_DATA} ${WRKSRC}/lib/fluent-hc-${DISTVERSION}.jar \
		${JAVAJARDIR}/fluent-hc.jar
	@${ECHO_MSG} " [DONE]"
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${FIND} javadoc tutorial \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES.txt ${DOCSDIR}/
	@${ECHO_MSG} " [DONE]"
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO_MSG} -n ">> Installing examples..."
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${FIND} . \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
