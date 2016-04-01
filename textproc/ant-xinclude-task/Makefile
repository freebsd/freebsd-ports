# Created by: Ernst de Haan <znerd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xinclude-task
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	textproc java
MASTER_SITES=	http://people.freebsd.org/~znerd/xinclude-task/
PKGNAMEPREFIX=	ant-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XInclude task for Jakarta Ant

BUILD_DEPENDS=	${JAVAJARDIR}/xincluder.jar:textproc/xincluder

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes

OPTIONS_DEFINE=	DOCS

ALL_TARGET=	jar apidocs
PORTDOCS=	*
MAKE_ENV=	CLASSPATH=${JAVAJARDIR}/xincluder.jar

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/build/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}/
	cd ${WRKSRC}/build/apidocs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
