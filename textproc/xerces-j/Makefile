# New ports collection makefile for:    Xerces
# Date created:		2000/08/12
# Whom:			Marcin Cieslak
#
# $FreeBSD$
#

PORTNAME=	xerces-j
PORTVERSION=	2.6.2
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_APACHE_XML}
MASTER_SITE_SUBDIR=	xerces-j/source
DISTFILES=	Xerces-J-src.${PORTVERSION}${EXTRACT_SUFX} Xerces-J-tools.${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML parser for Java

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant

USE_JAVA=	yes
JAVA_VERSION=	1.3+

WRKSRC=		${WRKDIR}/xerces-${PORTVERSION:S/./_/g}

OPTIONS=	DEPRECATED_JARS "build/install the deprecated JARs" on \
		SAMPLES_JAR "build/install the samples" off

.include <bsd.port.pre.mk>

ANT?=		${LOCALBASE}/bin/ant
ANT_TARGETS=	jars
.if !defined(NOPORTDOCS)
ANT_TARGETS+=	javadocs #docs
PORTDOCS=	api dom3-api other xerces2 xni xs
.endif

JARFILES+=	xercesImpl.jar xml-apis.jar
.if defined(WITH_DEPRECATED_JARS)
ANT_TARGETS+=	deprecatedjars
JARFILES+=	xerces.jar xmlParserAPIs.jar resolver.jar
.endif
.if defined(WITH_SAMPLES_JAR)
JARFILES+=	xercesSamples.jar
.endif

PLIST_FILES+=	${JARFILES:S,^,${JAVAJARDIR:S,${PREFIX},,}/,}

TOOLS_JARFILES=	resolver.jar stylebook-1.0-b2.jar bin/xjavac.jar

post-extract:
	@cd ${WRKSRC} && ${MV} ../tools .

do-build:
	@cd ${WRKSRC} && ${SETENV} CLASSPATH=`echo ${TOOLS_JARFILES:S,^,tools/,} | ${TR} " " ":"` ${ANT} ${ANT_TARGETS}

do-install:
	@${ECHO_CMD} -n ">> Installing JAR files in ${JAVAJARDIR}..."
	@${MKDIR} ${JAVAJARDIR}
.for JARFILE in ${JARFILES}
	@cd ${WRKSRC}/build && ${CP} ${JARFILE} ${JAVAJARDIR}/
	@${ECHO_CMD} -n " ${JARFILE}"
.endfor
	@${ECHO_CMD} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
.for DOCFILE in ${PORTDOCS}
	@cd ${WRKSRC}/build/docs/javadocs && ${CP} -r ${DOCFILE} ${DOCSDIR}/
	@${ECHO_CMD} -n " ${DOCFILE}"
.endfor
	@${ECHO_CMD} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
