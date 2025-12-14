PORTNAME=	jericho-html
PORTVERSION=	3.4
CATEGORIES=	www java
MASTER_SITES=	SF/jerichohtml/${PORTNAME}/${PORTVERSION}

MAINTAINER=	saper@saper.info
COMMENT=	Java library to analyse and manipulate HTML
WWW=		https://sourceforge.net/projects/jerichohtml/

LICENSE=		APACHE20 EPL LGPL21+
LICENSE_COMB=	dual

USES=		java zip

INTERFACES:=	"compile-time-dependencies/slf4j-api-1.7.12.jar:\
		compile-time-dependencies/commons-logging-api-1.1.1.jar:\
		compile-time-dependencies/log4j-api-2.4.1.jar"

PORTDOCS=	*
PLIST_FILES+=	${JAVAJARDIR}/${PORTNAME}.jar

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${WRKSRC} && ${RM} -r classes/* && ${SETENV}         \
		LANG=en_US.ISO8859-1 LC_ALL=en_US.ISO8859-1 ${JAVAC} \
		-classpath ${INTERFACES:S, ,,g}                   \
		-encoding Windows-1252 \
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
