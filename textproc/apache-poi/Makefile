PORTNAME=	poi
PORTVERSION=	5.2.3
CATEGORIES=	textproc devel java
MASTER_SITES=	https://archive.apache.org/dist/${PORTNAME}/release/bin/
PKGNAMEPREFIX=	apache-
DISTNAME=	${PORTNAME}-bin-${PORTVERSION}-${RELEASE_DATE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java API To Access Microsoft Format Files
WWW=		https://poi.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	log4j>0:devel/log4j	\
		SparseBitSet>0:devel/sparsebitset	\
		apache-commons-io>0:devel/apache-commons-io	\
		apache-commons-math>0:math/apache-commons-math	\
		apache-commons-codec>0:java/apache-commons-codec	\
		apache-commons-collections4>0:java/apache-commons-collections4

USES=		cpe tar:tgz
CPE_VENDOR=	apache

USE_JAVA=	yes
NO_BUILD=	yes
NO_ARCH=	yes
RELEASE_DATE=	20220909
JARNAMES=	examples excelant javadoc ooxml ooxml-full ooxml-lite scratchpad
WRKSRC=		${WRKDIR}/${PORTNAME}-bin-${PORTVERSION}

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar

.for i in ${JARNAMES}
PLIST_FILES+=	${JAVAJARDIR}/${PORTNAME}-${i}.jar
.endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
.for i in ${JARNAMES}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${i}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-${i}.jar
.endfor

.include <bsd.port.mk>
