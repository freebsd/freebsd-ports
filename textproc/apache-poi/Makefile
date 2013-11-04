# Created by: Anton Yudin <toha@toha.org.ua>
# $FreeBSD$

PORTNAME=	poi
PORTVERSION=	3.9
CATEGORIES=	textproc devel java
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	${PORTNAME:S,-,/,}/release/src
PKGNAMEPREFIX=	apache-
DISTNAME=	${PORTNAME}-src-${PORTVERSION}-20121203

MAINTAINER=	toha@toha.org.ua
COMMENT=	Java API To Access Microsoft Format Files

BUILD_DEPENDS=	${JAVALIBDIR}/xalan.jar:${PORTSDIR}/textproc/xalan-j

USE_JAVA=	yes
JAVA_VERSION=	1.6+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

DSTAMP=		`date +%Y%m%d`

USE_ANT=	yes
MAKE_ARGS=
MAKE_ENV+=	ANT_INCLUDE_SHARED_JARS=YES
PORTDOCS=	*
ALL_TARGET=	jar
JARFILE=	${PORTNAME}-${PORTVERSION}-${DSTAMP}.jar
DESTJARFILE=	${PORTNAME}.jar
JARNAMES=	examples excelant scratchpad ooxml ooxml-schemas

PLIST_FILES=	%%JAVAJARDIR%%/${DESTJARFILE}

.for i in ${JARNAMES}
PLIST_FILES+=%%JAVAJARDIR%%/${PORTNAME}-${i}.jar
.endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/dist/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}
.for i in ${JARNAMES}
	${INSTALL_DATA} ${WRKSRC}/build/dist/${PORTNAME}-${i}-${PORTVERSION}-${DSTAMP}.jar ${JAVAJARDIR}/${PORTNAME}-${i}.jar
.endfor
	cd ${WRKSRC}/docs/apidocs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

# Workaround stage and ANT bug
do-build:
	@(cd ${BUILD_WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${ANT} ${ALL_TARGET})

.include <bsd.port.mk>
