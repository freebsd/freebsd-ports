# Ports collection makefile for:	Jakarta Commons Net
# Date created:			1 Oct 2006
# Whom:				Sergey Matveychuk <sem@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	commons-net
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	net java
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	commons/net/source
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	sem@FreeBSD.org
COMMENT=	Collection of network protocol implementations for Java

BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit \
		${JAVAJARDIR}/jakarta-regexp.jar:${PORTSDIR}/java/jakarta-regexp
RUN_DEPENDS=	${JAVAJARDIR}/jakarta-regexp.jar:${PORTSDIR}/java/jakarta-regexp

BROKEN=		Does not compile

USE_JAVA=	yes
JAVA_VERSION=	1.3+
USE_ANT=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_ARGS=	-cp ${JAVALIBDIR}/junit.jar -Dnoget=""
MAKE_ENV+=	LANG=C
ALL_TARGET=	dist
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

.if !defined(NOPORTDOCS)
PORTDOCS=	LICENSE.txt NOTICE.txt api
ALL_TARGET+=	javadoc
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${INSTALL_DATA} ${WRKSRC}/target/${PORTNAME}-${PORTVERSION}.jar \
		${JAVAJARDIR}/${PORTNAME}.jar

	@${ECHO_MSG} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/dist/docs && ${FIND} api \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${INSTALL_DATA} ${WRKSRC}/LICENSE.txt \
		${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/NOTICE.txt \
		${DOCSDIR}/
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
