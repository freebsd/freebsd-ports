# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xml-security
PORTVERSION=	1.5.5
CATEGORIES=	security java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	santuario/java-library/${PORTVERSION:S/./_/g}
DISTNAME=	${PORTNAME}-src-${PORTVERSION:S/./_/g}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A Java library for XML Signature and Encryption

BUILD_DEPENDS=	${JAVALIBDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging \
		${JAVALIBDIR}/xalan.jar:${PORTSDIR}/textproc/xalan-j
RUN_DEPENDS=	${JAVALIBDIR}/commons-logging.jar:${PORTSDIR}/java/jakarta-commons-logging

LICENSE=	APACHE20

OPTIONS_DEFINE=	DOCS EXAMPLES
USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/./_/g}
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
