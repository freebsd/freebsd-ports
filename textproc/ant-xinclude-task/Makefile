# New ports collection makefile for:	XInclude task for Jakarta Ant
# Date created:				October 18, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xinclude-task
PORTVERSION=	0.2
CATEGORIES=	textproc java
MASTER_SITES=	http://people.freebsd.org/~znerd/xinclude-task/
PKGNAMEPREFIX=	ant-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XInclude task for Jakarta Ant

BUILD_DEPENDS=	${JAVAJARDIR}/xincluder.jar:${PORTSDIR}/textproc/xincluder

USE_JAVA=	yes
JAVA_VERSION=	1.1+
USE_ANT=	yes

ALL_TARGET=	jar
.if !defined(NOPORTDOCS)
ALL_TARGET+=	apidocs
PORTDOCS=	*
.endif
MAKE_ENV+=	CLASSPATH=${JAVAJARDIR}/xincluder.jar

PLIST_FILES+=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/build/${PORTNAME}.jar ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/build/apidocs && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} ";"
	@cd ${WRKSRC}/build/apidocs && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} ";"
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
