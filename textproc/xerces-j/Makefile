# New ports collection makefile for:    Xerces
# Date created:		2000/08/12
# Whom:			Marcin Cieslak
#
# $FreeBSD$
#

PORTNAME=	xerces-j
PORTVERSION=	2.6.2
PORTREVISION=	1
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_APACHE_XML}
MASTER_SITE_SUBDIR=	xerces-j/source
DISTFILES=	Xerces-J-src.${PORTVERSION}${EXTRACT_SUFX} Xerces-J-tools.${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	hq@FreeBSD.org
COMMENT=	XML parser for Java

CONFLICTS=	xml4j-4.*

USE_JAVA=	yes
JAVA_VERSION=	1.3+
USE_ANT=	yes

WRKSRC=		${WRKDIR}/xerces-${PORTVERSION:S/./_/g}

OPTIONS=	DEPRECATED_JARS "build/install the deprecated JARs" on \
		SAMPLES "build/install the samples" on

.include <bsd.port.pre.mk>

ALL_TARGET=	jars
.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadocs #docs
PORTDOCS=	api dom3-api other xerces2 xni xs
.endif

JARFILES+=	xercesImpl.jar xml-apis.jar
.if !defined(WITHOUT_DEPRECATED_JARS)
ALL_TARGET+=	deprecatedjars
JARFILES+=	xerces.jar xmlParserAPIs.jar resolver.jar
.endif
.if !defined(WITHOUT_SAMPLES)
JARFILES+=	xercesSamples.jar
.endif

PLIST_FILES+=	${JARFILES:S,^,%%JAVAJARDIR%%/,}

TOOLS_JARFILES=	resolver.jar stylebook-1.0-b2.jar bin/xjavac.jar
CLASSPATH!=	${ECHO_CMD} ${TOOLS_JARFILES:S,^,tools/,} | ${TR} " " ":"
MAKE_ENV=	CLASSPATH=${CLASSPATH}

post-extract:
	@cd ${WRKSRC} && ${MV} ../tools .

do-install:
	@${ECHO_MSG} -n ">> Installing JAR files in ${JAVAJARDIR}..."
	@${MKDIR} ${JAVAJARDIR}
.for JARFILE in ${JARFILES}
	@cd ${WRKSRC}/build && ${INSTALL_DATA} ${JARFILE} ${JAVAJARDIR}/${JARFILE}
	@${ECHO_MSG} -n " ${JARFILE}"
.endfor
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/build/docs/javadocs && \
		${FIND} ${PORTDOCS} -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
		${FIND} ${PORTDOCS} -not -type d -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
	@${ECHO_MSG} " [ DONE ]"
.endif
.if !defined(WITHOUT_SAMPLES)
	@${ECHO_MSG} -n ">> Installing samples in ${EXAMPLESDIR}..."
	@cd ${WRKSRC}/samples && \
		${FIND} . -type d -exec ${MKDIR} "${EXAMPLESDIR}/{}" \; && \
		${FIND} . -not -type d -exec ${INSTALL_DATA} "{}" "${EXAMPLESDIR}/{}" \;
	@${ECHO_MSG} " [ DONE ]"
.endif

.if !defined(WITHOUT_SAMPLES)
post-install:
	@${FIND} -s ${WRKSRC}/samples -not -type d | \
		${SED} -ne 's,^${WRKSRC}/samples,${EXAMPLESDIR:S,${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC}/samples -type d | \
		${SED} -ne 's,^${WRKSRC}/samples,@dirrm ${EXAMPLESDIR:S,${PREFIX}/,,},p' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
