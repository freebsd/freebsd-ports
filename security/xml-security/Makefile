PORTNAME=	xml-security
DISTVERSION=	1_5_5
PORTREVISION=	2
CATEGORIES=	security java
MASTER_SITES=	https://archive.apache.org/dist/santuario/java-library/${DISTVERSION}/
DISTNAME=	${PORTNAME}-src-${DISTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java library for XML Signature and Encryption
WWW=		https://santuario.apache.org/javaindex.html

BUILD_DEPENDS=	${JAVALIBDIR}/commons-logging.jar:java/apache-commons-logging \
		${JAVALIBDIR}/xalan.jar:textproc/xalan-j
RUN_DEPENDS=	${JAVALIBDIR}/commons-logging.jar:java/apache-commons-logging

LICENSE=	APACHE20

USES=		cpe java:ant,run zip
CPE_PRODUCT=	xml_security_for_java
CPE_VENDOR=	apache

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
MAKE_ENV=	ANT_INCLUDE_SHARED_JARS=YES
ALL_TARGET=	jar

PORTDOCS=	*
PORTEXAMPLES=	*

PLIST_FILES=	%%JAVAJARDIR%%/xmlsec.jar

OPTIONS_DEFINE=	DOCS EXAMPLES

DOCS_ALL_TARGET=	javadoc

do-install:
	@${ECHO} -n ">> Installing JAR as ${JAVAJARDIR}/xmlsec.jar..."
	@${INSTALL_DATA} ${WRKSRC}/build/xmlsec-${PORTVERSION}.jar \
		${STAGEDIR}/${JAVAJARDIR}/xmlsec.jar
	@${ECHO} " [ DONE ]"

do-install-DOCS-on:
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	@(cd ${WRKSRC}/build/docs/html && ${COPYTREE_SHARE} javadoc \
		${STAGEDIR}/${DOCSDIR})
	@${ECHO} " [ DONE ]"

do-install-EXAMPLES-on:
	@${ECHO} -n ">> Installing examples in ${EXAMPLESDIR}..."
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
	@(cd ${WRKSRC}/samples && ${COPYTREE_SHARE} "javax org" \
		${STAGEDIR}/${EXAMPLESDIR})
	@${ECHO} " [ DONE ]"

.include <bsd.port.mk>
