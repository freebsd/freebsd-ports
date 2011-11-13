# New ports collection makefile for:            lucene
# Date created:         02 Jan 2008
# Whom:         Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#
# Please don't forget to bump the version in py-lucene if this changes!

PORTNAME=	lucene
PORTVERSION=	3.4.0
CATEGORIES=	textproc java devel
MASTER_SITES=	${MASTER_SITE_APACHE:S,%SUBDIR%,lucene/java/$(PORTVERSION),}
DISTNAME=	lucene-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	A full-text search engine for Java

LICENSE=	ASL

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+

OPTIONS=	DOCS    "Install docs & examples" on \
		CONTRIB "Install contribs" off

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}-core-${PORTVERSION}.jar

.include <bsd.port.options.mk>

CONTRIBS=	analyzers \
		benchmark \
		facet	\
		grouping \
		highlighter \
		icu \
		instantiated \
		join	\
		memory \
		misc \
		queries \
		queryparser	\
		remote	\
		smartcn \
		spatial \
		spellchecker \
		stempel \
		xml-query-parser

.if defined(WITH_CONTRIB)
.for f in ${CONTRIBS}
PLIST_FILES+=%%JAVAJARDIR%%/${PORTNAME}-${f}-${PORTVERSION}.jar
.endfor
.endif

.if defined(WITHOUT_DOCS) || !defined(WITH_DOCS)
NOPORTDOCS=	yes
NOPORTEXAMPLES=	yes
.endif

PORTDOCS=	*
PORTEXAMPLES=	*

DEMODIR=	contrib/demo

.if defined(WITH_CONTRIB)
post-extract:
	${MV} ${WRKSRC}/contrib/analyzers/common/* ${WRKSRC}/contrib/analyzers/
	${RMDIR} ${WRKSRC}/contrib/analyzers/common
	${MV} ${WRKSRC}/contrib/analyzers/smartcn/ ${WRKSRC}/contrib/
	${MV} ${WRKSRC}/contrib/analyzers/stempel/ ${WRKSRC}/contrib/
.endif

do-install:
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-core-${PORTVERSION}.jar \
		${JAVAJARDIR}
.if defined(WITH_CONTRIB)
. for f in ${CONTRIBS}
	@${INSTALL_DATA} \
	    ${WRKSRC}/contrib/${f}/${PORTNAME}-${f}-${PORTVERSION}.jar \
	    ${JAVAJARDIR}
. endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGES.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/NOTICE.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/${DEMODIR} && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
