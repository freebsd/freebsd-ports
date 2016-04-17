# Created by: Anton Yudin <toha@toha.org.ua>
# $FreeBSD$

PORTNAME=	poi
PORTVERSION=	3.14
CATEGORIES=	textproc devel java
MASTER_SITES=	APACHE/${PORTNAME}/release/bin
PKGNAMEPREFIX=	apache-
DISTNAME=	${PORTNAME}-bin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java API To Access Microsoft Format Files

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTDOCS=	*
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
RELEASE_DATE=	20160307
JARNAMES=	examples excelant scratchpad ooxml ooxml-schemas
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar
OPTIONS_DEFINE=	DOCS

USES=		cpe
CPE_VENDOR=	apache

.for i in ${JARNAMES}
PLIST_FILES+=	%%JAVAJARDIR%%/${PORTNAME}-${i}.jar
.endfor

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-${RELEASE_DATE}.jar..."
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}-${RELEASE_DATE}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
.for i in ${JARNAMES}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${i}-${PORTVERSION}-${RELEASE_DATE}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-${i}.jar
.endfor
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing documentation in ${STAGEDIR}${DOCSDIR}/..."
	@cd ${WRKSRC}/docs \
	  && ${FIND} . -type d -not -empty -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
