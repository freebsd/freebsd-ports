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

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	XInclude task for Jakarta Ant

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant \
		${JAVASHAREDIR}/classes/xincluder.jar:${PORTSDIR}/textproc/xincluder

BROKEN=		Install fails

USE_JAVA=	1.1+

ANT?=		${LOCALBASE}/bin/ant
.if defined(NOPORTDOCS)
ANT_TARGET=	jar
.else
ANT_TARGET=	jar apidocs
PORTDOCS=	*
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ANT_INCLUDE_SHARED_JARS=YES ${ANT} ${ANT_TARGET}

do-install:

	@${ECHO} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${CP} ${WRKSRC}/build/${PORTNAME}.jar ${JAVAJARDIR}/
	@${ECHO} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/build/apidocs/* ${DOCSDIR}
	@${ECHO} " [ DONE ]"
.endif

.include <bsd.port.mk>
