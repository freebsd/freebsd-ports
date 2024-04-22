PORTNAME=	poi
PORTVERSION=	5.2.5
CATEGORIES=	textproc devel java
MASTER_SITES=	${MAVEN_SITE}/poi/${PORTVERSION}/:poi	\
		${MAVEN_SITE}/poi-examples/${PORTVERSION}/:examples	\
		${MAVEN_SITE}/poi-excelant/${PORTVERSION}/:excelant	\
		${MAVEN_SITE}/poi-ooxml/${PORTVERSION}/:ooxml		\
		${MAVEN_SITE}/poi-ooxml-full/${PORTVERSION}/:ooxmlfull	\
		${MAVEN_SITE}/poi-ooxml-lite/${PORTVERSION}/:ooxmllite	\
		${MAVEN_SITE}/poi-scratchpad/${PORTVERSION}/:scratchpad
PKGNAMEPREFIX=	apache-
DISTFILES=	${PORTNAME}-${PORTVERSION}.jar:poi	\
		${PORTNAME}-examples-${PORTVERSION}.jar:examples	\
		${PORTNAME}-excelant-${PORTVERSION}.jar:excelant	\
		${PORTNAME}-ooxml-${PORTVERSION}.jar:ooxml		\
		${PORTNAME}-ooxml-full-${PORTVERSION}.jar:ooxmlfull	\
		${PORTNAME}-ooxml-lite-${PORTVERSION}.jar:ooxmllite	\
		${PORTNAME}-scratchpad-${PORTVERSION}.jar:scratchpad

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java API To Access Microsoft Format Files
WWW=		https://poi.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKDIR}/META-INF/LICENSE

RUN_DEPENDS=	apache-log4j2>0:devel/apache-log4j2	\
		SparseBitSet>0:devel/sparsebitset	\
		apache-commons-io>0:devel/apache-commons-io	\
		apache-commons-math>0:math/apache-commons-math	\
		apache-commons-codec>0:java/apache-commons-codec	\
		apache-commons-collections4>0:java/apache-commons-collections4

USES=		cpe
CPE_VENDOR=	apache

USE_JAVA=	yes
NO_BUILD=	yes
NO_EXTRACT=	yes
NO_ARCH=	yes
JARNAMES=	examples excelant ooxml ooxml-full ooxml-lite scratchpad

MAVEN_SITE=	https://repo1.maven.org/maven2/org/apache/poi

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar

.for i in ${JARNAMES}
PLIST_FILES+=	${JAVAJARDIR}/${PORTNAME}-${i}.jar
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
.for i in ${JARNAMES}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-${i}-${PORTVERSION}.jar	\
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-${i}.jar
.endfor

.include <bsd.port.mk>
