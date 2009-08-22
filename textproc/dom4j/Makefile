# New ports collection makefile for:	dom4j
# Date created:		7 Oct 2005
# Whom:			<glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dom4j
PORTVERSION=	1.6.1
PORTREVISION=	2
CATEGORIES=	textproc java
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Source XML framework for Java

USE_JAVA=	yes
JAVA_VERSION=	1.2+
NO_BUILD=	yes

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR in ${JAVAJARDIR}..."
	@cd ${WRKSRC} && \
		${INSTALL_DATA} ${PORTNAME}-${PORTVERSION}.jar \
			${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${FIND} . | \
		${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > \
			/dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
