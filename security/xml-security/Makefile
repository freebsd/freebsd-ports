PORTNAME=	xmlsec
DISTVERSION=	3.0.5
CATEGORIES=	security java
MASTER_SITES=	https://repo1.maven.org/maven2/org/apache/santuario/xmlsec/${DISTVERSION}/
DISTFILES=	${PORTNAME}-${PORTVERSION}.jar

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java library for XML Signature and Encryption
WWW=		https://santuario.apache.org/javaindex.html

LICENSE=	APACHE20

RUN_DEPENDS=	${JAVALIBDIR}/commons-logging.jar:java/apache-commons-logging

USES=		cpe java:run
CPE_PRODUCT=	xml_security_for_java
CPE_VENDOR=	apache

NO_BUILD=	yes
NO_ARCH=	yes
EXTRACT_ONLY=

PORTDOCS=	*

PLIST_FILES=	%%JAVAJARDIR%%/xmlsec.jar

OPTIONS_DEFINE=	DOCS
DOCS_DISTFILES=	${PORTNAME}-${PORTVERSION}-javadoc.jar

do-install:
	@${ECHO} -n ">> Installing JAR as ${JAVAJARDIR}/xmlsec.jar..."
	${INSTALL_DATA} ${DISTDIR}/xmlsec-${PORTVERSION}.jar \
		${STAGEDIR}/${JAVAJARDIR}/xmlsec.jar
	@${ECHO} " [ DONE ]"

do-install-DOCS-on:
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/xmlsec-${PORTVERSION}-javadoc.jar \
		${STAGEDIR}/${DOCSDIR}/xmlsec-javadoc.jar
	@${ECHO} " [ DONE ]"

.include <bsd.port.mk>
