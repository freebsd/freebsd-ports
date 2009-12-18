# New ports collection makefile for:            lucene
# Date created:         02 Jan 2008
# Whom:         Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$

PORTNAME=	lucene
PORTVERSION=	2.4.1
CATEGORIES=	textproc java devel
MASTER_SITES=	${MASTER_SITE_APACHE:S,%SUBDIR%,lucene/java,}
DISTNAME=	lucene-${PORTVERSION}

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	A full-text search engine for Java

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+

OPTIONS=	DOCS    "Install docs & examples" on \
		CONTRIB "Install contribs" off

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}-core-${PORTVERSION}.jar

CONTRIBS=	analyzers \
		ant \
		benchmark \
		instantiated \
		highlighter \
		lucli \
		memory \
		misc \
		queries \
		regex \
		similarity \
		snowball \
		spellchecker \
		surround \
		swing \
		wikipedia \
		wordnet \
		xml-query-parser

.include <bsd.port.pre.mk>

.if defined(WITH_CONTRIB)
.for f in ${CONTRIBS}
PLIST_FILES+=%%JAVAJARDIR%%/${PORTNAME}-${f}-${PORTVERSION}.jar
.endfor
.endif

.if defined(WITHOUT_DOCS) || !defined(WITH_DOCS)
NOPORTDOCS=	yes
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

DEMODIR=	src/demo/org/apache/lucene/demo

do-install:
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-core-${PORTVERSION}.jar ${JAVAJARDIR}
.if defined(WITH_CONTRIB)
	${INSTALL_DATA} \
	    ${CONTRIBS:C,^(.*)$,${WRKSRC}/contrib/\1/${PORTNAME}-\1-${PORTVERSION}.jar,} \
	    ${JAVAJARDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGES.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/NOTICE.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
	@cd ${WRKSRC}/docs/ \
	    && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	    && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/${DEMODIR} \
	    && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \; \
	    && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${FIND} -s ${WRKSRC}/${DEMODIR} -not -type d \
	    | ${SED} -ne 's,^${WRKSRC}/${DEMODIR},${EXAMPLESDIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC}/${DEMODIR} -type d \
	    | ${SED} -ne 's,^${WRKSRC}/${DEMODIR},@dirrm ${EXAMPLESDIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
