# New ports collection makefile for:    Xerces
# Date created:		2000/08/12
# Whom:			Marcin Cieslak
#
# $FreeBSD$
#

PORTNAME=	xerces-j
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	textproc java
MASTER_SITES=	http://xml.apache.org/dist/xerces-j/old_xerces2/
DISTNAME=	Xerces-J-src.${PORTVERSION}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	XML parser for Java

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant

USE_JAVA=	1.3+

WRKSRC=		${WRKDIR}/xerces-${PORTVERSION:S/./_/g}
ANT?=		${LOCALBASE}/bin/ant
.if defined(NOPORTDOCS)
ANT_TARGETS=	jar apijar
.else
ANT_TARGETS=	jar apijar javadocs
# We should install other documentation too, but
# we have no stylebook port yet
#
# ANT_TARGETS=	jar apijar docs javadocs
.endif
JAVASHAREDIR=	${PREFIX}/share/java
JARDIR=		${JAVASHAREDIR}/classes
JARFILES=	xercesImpl.jar xmlParserAPIs.jar

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGETS}

do-install:
	@${ECHO} -n ">> Installing JAR files in ${JARDIR}..."
	@cd ${WRKSRC}/build && ${CP} ${JARFILES} ${JARDIR}/
	@${ECHO} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/build/docs/javadocs/* ${DOCSDIR}
	@${ECHO} " [ DONE ]"
.endif

.include <bsd.port.mk>
