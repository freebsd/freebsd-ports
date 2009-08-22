# New ports collection makefile for:	jerichohtml
# Date created:		2008-06-17
# Whom:			Marcin Cieslak <saper@SYSTEM.PL>
#
# $FreeBSD$
#

PORTNAME=	jericho-html
PORTVERSION=	2.6
CATEGORIES=	www java
MASTER_SITES=	SF/jerichohtml/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A java library to analyse and manipulate HTML

USE_ZIP=	yes
USE_JAVA=	1.3+

INTERFACES:=	"compile-time-dependencies/slf4j-api-1.5.2.jar:\
		compile-time-dependencies/commons-logging-api-1.1.1.jar:\
		compile-time-dependencies/log4j-api-1.2.15.jar"

PORTDOCS=	api
PLIST_FILES+=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-build:
	(cd ${WRKSRC} &&  ${RM} -rf classes/* && ${JAVAC}         \
		-classpath ${INTERFACES:S, ,,g}                   \
		-d classes src/java/au/id/jericho/lib/html/*.java \
		src/java/au/id/jericho/lib/html/nodoc/*.java)
	${JAR} -cf ${WRKSRC}/lib/${PORTNAME}.jar                  \
		 -C ${WRKSRC}/classes .
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC} && ${RM} -rf doc/* && ${JAVADOC} -quiet     \
		-windowtitle "Jericho HTML Parser ${PORTVERSION}" \
		-classpath ${INTERFACES:S, ,,g}:src/java:classes  \
		-use -d ${WRKSRC}/doc/api                         \
		-subpackages au.id.jericho.lib.html               \
		-exclude au.id.jericho.lib.html.nodoc             \
		-noqualifier au.id.jericho.lib.html               \
		-group "Core package" au.id.jericho.lib.html)
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/${PORTNAME}.jar ${JAVAJARDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${FIND} api | ${CPIO} -pdmu ${DOCSDIR})
.endif

.include <bsd.port.mk>
