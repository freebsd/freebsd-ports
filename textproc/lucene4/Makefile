# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lucene
PORTVERSION=	4.4.0
CATEGORIES=	textproc java devel
MASTER_SITES=	APACHE
MASTER_SITE_SUBDIR=	${PORTNAME}/java/${PORTVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Full-text search engine for Java, 4.x branch

LICENSE=	AL2

CONFLICTS=	lucene-[0-9].*

USE_JAVA=	yes
NO_BUILD=	yes
JAVA_VERSION=	1.6+

OPTIONS_DEFINE=	CONTRIB DOCS EXAMPLES
CONTRIB_DESC=	Install contributed jars
OPTIONS_DEFAULT=	CONTRIB

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}-core-${PORTVERSION}.jar
PKGNAMESUFFIX:=	4
LASTEST_LINK=	${PORTNAME}4

.include <bsd.port.options.mk>

CONTRIBS=	benchmark \
		classification \
		codecs \
		demo \
		facet	\
		grouping \
		highlighter \
		join \
		memory \
		misc \
		queries \
		queryparser \
		replicator \
		sandbox \
		spatial \
		suggest

EXTRA_CONTRIBS_DIRS=	common \
		icu \
		kuromoji \
		morfologik \
		phonetic \
		smartcn \
		stempel \
		uima

.if ${PORT_OPTIONS:MCONTRIB}
.for f in ${CONTRIBS}
PLIST_FILES+=%%JAVAJARDIR%%/${PORTNAME}-${f}-${PORTVERSION}.jar
.endfor
.for g in ${EXTRA_CONTRIBS_DIRS}
PLIST_FILES+=%%JAVAJARDIR%%/${PORTNAME}-analyzers-${g}-${PORTVERSION}.jar
.endfor
.endif

PORTDOCS=	*
PORTEXAMPLES=	*

do-install:
	${INSTALL_DATA} ${WRKSRC}/core/${PORTNAME}-core-${PORTVERSION}.jar ${JAVAJARDIR}
.if ${PORT_OPTIONS:MCONTRIB}
. for f in ${CONTRIBS}
	${INSTALL_DATA} ${WRKSRC}/${f}/${PORTNAME}-${f}-${PORTVERSION}.jar ${JAVAJARDIR}
. endfor
. for d in ${EXTRA_CONTRIBS_DIRS}
	${INSTALL_DATA} ${WRKSRC}/analysis/${d}/${PORTNAME}-analyzers-${d}-${PORTVERSION}.jar ${JAVAJARDIR}
. endfor
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in CHANGES.txt NOTICE.txt README.txt
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/demo/${PORTNAME}-demo-${PORTVERSION}.jar ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
