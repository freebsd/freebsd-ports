# Created by: Marcin Cieslak <saper@SYSTEM.PL>
# $FreeBSD$

PORTNAME=	jericho-html
PORTVERSION=	3.2
CATEGORIES=	www java
MASTER_SITES=	SF/jerichohtml/${PORTNAME}/${PORTVERSION}

MAINTAINER=	saper@saper.info
COMMENT=	Java library to analyse and manipulate HTML

USES=		zip
USE_JAVA=	1.5+

INTERFACES:=	"compile-time-dependencies/slf4j-api-1.6.1.jar:\
		compile-time-dependencies/commons-logging-api-1.1.1.jar:\
		compile-time-dependencies/log4j-1.2.16.jar"

PORTDOCS=	*
PLIST_FILES+=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-build:
	(cd ${WRKSRC} &&  ${RM} -rf classes/* && ${JAVAC}         \
		-classpath ${INTERFACES:S, ,,g}                   \
		-d classes src/java/net/htmlparser/jericho/*.java \
		src/java/net/htmlparser/jericho/nodoc/*.java)
	${MKDIR} ${WRKSRC}/lib
	${JAR} -cf ${WRKSRC}/lib/${PORTNAME}.jar                  \
		 -C ${WRKSRC}/classes .

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}.jar ${STAGEDIR}${JAVAJARDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
