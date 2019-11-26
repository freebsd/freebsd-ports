# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xml-security
DISTVERSION=	1_5_5
PORTREVISION=	1
CATEGORIES=	security java
MASTER_SITES=	APACHE/santuario/java-library/${DISTVERSION}
DISTNAME=	${PORTNAME}-src-${DISTVERSION}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java library for XML Signature and Encryption

BUILD_DEPENDS=	${JAVALIBDIR}/commons-logging.jar:java/apache-commons-logging \
		${JAVALIBDIR}/xalan.jar:textproc/xalan-j
RUN_DEPENDS=	${JAVALIBDIR}/commons-logging.jar:java/apache-commons-logging

LICENSE=	APACHE20

OPTIONS_DEFINE=	DOCS EXAMPLES
USES=		cpe zip
CPE_PRODUCT=	xml_security_for_java
CPE_VENDOR=	apache
USE_JAVA=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
USE_ANT=	yes
MAKE_ENV=	ANT_INCLUDE_SHARED_JARS=YES
ALL_TARGET=	jar

PORTDOCS=	*
PORTEXAMPLES=	*

PLIST_FILES=	%%JAVAJARDIR%%/xmlsec.jar

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadoc
.endif

do-install:
	@${ECHO} -n ">> Installing JAR as ${JAVAJARDIR}/xmlsec.jar..."
	@${INSTALL_DATA} ${WRKSRC}/build/xmlsec-${PORTVERSION}.jar \
		${STAGEDIR}/${JAVAJARDIR}/xmlsec.jar
	@${ECHO} " [ DONE ]"
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
	@(cd ${WRKSRC}/build/docs/html && ${COPYTREE_SHARE} javadoc \
		${STAGEDIR}/${DOCSDIR})
	@${ECHO} " [ DONE ]"
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO} -n ">> Installing examples in ${EXAMPLESDIR}..."
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
	@(cd ${WRKSRC}/samples && ${COPYTREE_SHARE} "javax org" \
		${STAGEDIR}/${EXAMPLESDIR})
	@${ECHO} " [ DONE ]"
.endif

.include <bsd.port.mk>
