# Ports collection makefile for:	HttpClient
# Date created:			11 Jul 2008
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	httpclient
DISTVERSION=	4.0
CATEGORIES=	www java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	httpcomponents/${PORTNAME}/binary
DISTNAME=	httpcomponents-client-${DISTVERSION}-bin

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java components implementing an advanced HTTP client

RUN_DEPENDS=	${JAVAJARDIR}/httpcore.jar:${PORTSDIR}/www/httpcore \
		${JAVAJARDIR}/apache-mime4j.jar:${PORTSDIR}/mail/mime4j \
		${JAVAJARDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging \
		${JAVAJARDIR}/commons-codec.jar:${PORTSDIR}/java/jakarta-commons-codec

USE_JAVA=	yes
JAVA_VERSION=	1.5+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/httpcomponents-client-${DISTVERSION}

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar %%JAVAJARDIR%%/${PORTNAME:S/client/mime/}.jar

PORTDOCS=	*

do-install:
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}-${DISTVERSION}.jar \
		${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/${PORTNAME:S/client/mime/}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME:S/client/mime/}-${DISTVERSION}.jar \
		${JAVAJARDIR}/${PORTNAME:S/client/mime/}.jar
	@${ECHO_MSG} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${FIND} javadoc tutorial \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${INSTALL_DATA} ${WRKSRC}/RELEASE_NOTES.txt ${WRKSRC}/NTLM_SUPPORT.txt \
		${DOCSDIR}/
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
