# New ports collection makefile for:            lucene
# Date created:         02 Jan 2008
# Whom:         Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#
# Please don't forget to bump the version in py-lucene if this changes!

PORTNAME=	lucene
PORTVERSION=	3.5.0
CATEGORIES=	textproc java devel
MASTER_SITES=	APACHE
MASTER_SITE_SUBDIR=	${PORTNAME}/java/${PORTVERSION}/
DISTNAME=	lucene-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	A full-text search engine for Java

LICENSE=	AL2

USE_JAVA=	yes
USE_ANT=	yes
JAVA_VERSION=	1.5+
WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS=	DOCS    "Install docs & examples" on \
		CONTRIB "Install contribs" off

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}-core-${PORTVERSION}.jar

.include <bsd.port.options.mk>

CONTRIBS=	benchmark \
		demo \
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
		spatial \
		spellchecker \
		xml-query-parser

EXTRA_CONTRIBS_BUILD=	analyzers

EXTRA_CONTRIBS_DIRS=	smartcn \
		stempel

.if defined(WITH_CONTRIB)
.for f in ${EXTRA_CONTRIBS_BUILD} ${CONTRIBS} ${EXTRA_CONTRIBS_DIRS}
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
post-build:
.for i in ${EXTRA_CONTRIBS_BUILD} ${CONTRIBS}
	cd ${WRKSRC}/contrib/${i} && ${ANT}
.endfor
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/${PORTNAME}-core-${PORTVERSION:R}-SNAPSHOT.jar \
		${JAVAJARDIR}/${PORTNAME}-core-${PORTVERSION}.jar
.if defined(WITH_CONTRIB)
. for f in ${CONTRIBS}
	@${INSTALL_DATA} \
	    ${WRKSRC}/build/contrib/${f}/${PORTNAME}-${f}-${PORTVERSION:R}-SNAPSHOT.jar \
	    ${JAVAJARDIR}/${PORTNAME}-${f}-${PORTVERSION}.jar
. endfor
. for d in ${EXTRA_CONTRIBS_DIRS}
	@${INSTALL_DATA} \
	    ${WRKSRC}/build/contrib/${EXTRA_CONTRIBS_BUILD}/${d}/${PORTNAME}-${d}-${PORTVERSION:R}-SNAPSHOT.jar \
	    ${JAVAJARDIR}/${PORTNAME}-${d}-${PORTVERSION}.jar
. endfor
	@${INSTALL_DATA} \
	    ${WRKSRC}/build/contrib/${EXTRA_CONTRIBS_BUILD}/common/${PORTNAME}-${EXTRA_CONTRIBS_BUILD}-${PORTVERSION:R}-SNAPSHOT.jar \
	    ${JAVAJARDIR}/${PORTNAME}-${EXTRA_CONTRIBS_BUILD}-${PORTVERSION}.jar
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in CHANGES.txt LICENSE.txt NOTICE.txt README.txt
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/${DEMODIR} && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
