# New ports collection makefile for:	xalan-j
# Date created:		21 February 2001
# Whom:			znerd@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xalan-j
PORTVERSION=	2.5.1
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_APACHE_XML}
MASTER_SITE_SUBDIR=	${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}-src

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Apache XSLT processor for transforming XML documents

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant

USE_JAVA=	1.2+

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION:S/./_/g}
ANT?=		${LOCALBASE}/bin/ant
ANT_OPTS=	-Xmx16M
ANT_TARGET=	jar
.if !defined(NOPORTDOCS)
ANT_TARGET+=	javadocs
PORTDOCS=	apidocs
.endif
JARFILE=	xalan.jar
PLIST_FILES=	${JAVAJARDIR:S,^${PREFIX}/,,}/${JARFILE}

# FIXME: the autojavadocs Ant target seems broken with Java 1.4

do-configure:
	${SED} 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/xalan.sh >${WRKDIR}/xalan

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGET}

do-install:
	@${ECHO} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${CP} ${WRKSRC}/build/${JARFILE} ${JAVAJARDIR}/
	@${ECHO} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/build/docs/apidocs ${DOCSDIR}/
	@${ECHO} " [ DONE ]"
.endif

.include <bsd.port.mk>
