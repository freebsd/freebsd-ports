# Ports collection makefile for:	XStream
# Date created:			19 July 2006
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xstream
PORTVERSION=	1.1.3
CATEGORIES=	textproc java
MASTER_SITES=	http://dist.codehaus.org/xstream/distributions/

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A simple library to serialize Java objects to XML

USE_ZIP=	yes
USE_JAVA=	yes
USE_ANT=	yes
ALL_TARGET=	jar

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
.if !defined(NOPORTDOCS)
OTHERDOCS=	LICENSE.txt README.txt
PORTDOCS=	javadoc ${OTHERDOCS}
ALL_TARGET+=	javadoc
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/ && ${FIND} javadoc \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
