# New ports collection makefile for:	XML for Java
# Date created:		21 Feb 2000
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xml4j
PORTVERSION=	4.3.0
CATEGORIES=	textproc
MASTER_SITES=	http://dl.alphaworks.ibm.com/technologies/xml4j/
DISTNAME=	XML4J-bin.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML for Java parser

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/./_/g}
USE_JAVA=	yes
JAVA_VERSION=	1.2+
NO_BUILD=	YES
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

CONFLICTS=	xerces-j-2.*

SAMPLES=	dom sax simpletype socket ui xni xs
PORTDOCS=	*.html graphics images javadocs resources
JARFILES=	resolver.jar xercesImpl.jar xercesSamples.jar xml-apis.jar xmlParserAPIs.jar
DATAFILES=	personal-schema.xml personal.dtd personal.xml personal.xsd

PLIST_FILES=	${JARFILES:S,^,%%JAVAJARDIR%%/,} \
		${DATAFILES:S,^,%%DATADIR%%/,}
PLIST_DIRS=	%%DATADIR%%

do-install:
	@${MKDIR} ${JAVAJARDIR}
	@${ECHO_MSG} -n ">> Installing JAR in ${JAVAJARDIR}..."
	@cd ${WRKSRC} && \
		${INSTALL_DATA} ${JARFILES} ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing data in ${DATADIR}..."
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/data && \
		${INSTALL_DATA} ${DATAFILES} ${DATADIR}/
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && \
		${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	@cd ${WRKSRC}/docs && \
		${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing samples in ${EXAMPLESDIR}..."
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/samples && \
		${FIND} ${SAMPLES} -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \;
	@cd ${WRKSRC}/samples && \
		${FIND} ${SAMPLES} -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${FIND} -s ${WRKSRC}/samples -not -type d | \
		${SED} -ne 's,^${WRKSRC}/samples,${EXAMPLESDIR:S,${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC}/samples -type d | \
		${SED} -ne 's,^${WRKSRC}/samples,@dirrm ${EXAMPLESDIR:S,${PREFIX}/,,},p' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
