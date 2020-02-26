# Created by: Anton Yudin <toha@toha.org.ua>
# $FreeBSD$

PORTNAME=	poi
PORTVERSION=	4.1.2
CATEGORIES=	textproc devel java
MASTER_SITES=	APACHE/${PORTNAME}/release/bin
PKGNAMEPREFIX=	apache-
DISTNAME=	${PORTNAME}-bin-${PORTVERSION}-${RELEASE_DATE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java API To Access Microsoft Format Files

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe
CPE_VENDOR=	apache

USE_JAVA=	yes
NO_BUILD=	yes
NO_ARCH=	yes
RELEASE_DATE=	20200217
JARNAMES=	examples excelant scratchpad ooxml ooxml-schemas
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar
PORTDOCS=	*

.for i in ${JARNAMES}
PLIST_FILES+=	${JAVAJARDIR}/${PORTNAME}-${i}.jar
.endfor

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
.for i in ${JARNAMES}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${i}-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}-${i}.jar
.endfor

do-install-DOCS-on:
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
