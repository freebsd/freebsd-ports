# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch
PORTVERSION=	1.7.5
CATEGORIES=	textproc java devel
MASTER_SITES=	http://download.elasticsearch.org/${PORTNAME}/${PORTNAME}/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Full-text search engine for Java

LICENSE=	APACHE20

RUN_DEPENDS=	java-sigar>=0:java/sigar

CONFLICTS=	elasticsearch[0-9]-[0-9]*

USES=		cpe
NO_ARCH=	yes
USE_JAVA=	yes
NO_BUILD=	yes
JAVA_VERSION=	1.7+
ONLY_FOR_ARCHS=	i386 amd64
USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

LUCENEVER=	4.10.4
CONFIG_FILES=	elasticsearch.yml logging.yml
JARS=		elasticsearch-${PORTVERSION}.jar \
		asm-4.1.jar \
		asm-commons-4.1.jar \
		apache-log4j-extras-1.2.17.jar \
		antlr-runtime-3.5.jar \
		groovy-all-2.4.4.jar \
		jna-4.1.0.jar \
		jts-1.13.jar \
		log4j-1.2.17.jar \
		lucene-analyzers-common-${LUCENEVER}.jar \
		lucene-core-${LUCENEVER}.jar \
		lucene-expressions-${LUCENEVER}.jar \
		lucene-grouping-${LUCENEVER}.jar \
		lucene-highlighter-${LUCENEVER}.jar \
		lucene-join-${LUCENEVER}.jar \
		lucene-memory-${LUCENEVER}.jar \
		lucene-queries-${LUCENEVER}.jar \
		lucene-misc-${LUCENEVER}.jar \
		lucene-queries-${LUCENEVER}.jar \
		lucene-queryparser-${LUCENEVER}.jar \
		lucene-sandbox-${LUCENEVER}.jar \
		lucene-spatial-${LUCENEVER}.jar \
		lucene-suggest-${LUCENEVER}.jar \
		spatial4j-0.4.1.jar

DOCS=		LICENSE.txt \
		NOTICE.txt \
		README.textile

SIGAR_ARCH=	${ARCH:S|i386|x86|}
SEARCHUSER?=	elasticsearch
SEARCHGROUP?=	${SEARCHUSER}
USERS=		${SEARCHUSER}
GROUPS=		${SEARCHGROUP}
ELASTIC_DBDIR=	/var/db/elasticsearch
ELASTIC_LOGDIR=	/var/log/elasticsearch

.if ${OPSYS} == FreeBSD
.  if ${OSVERSION} >= 1000000
PLATFORM_VER=	1
.  else
PLATFORM_VER=	9
.  endif
.else
BROKEN=		${OPSYS} platform is not supported
.endif

SIGAR_LIBNAME=	libsigar-${ARCH:S,i386,x86,}-freebsd-${PLATFORM_VER}.so

SUB_LIST=	SEARCHUSER=${SEARCHUSER} \
		SEARCHGROUP=${SEARCHGROUP} \
		PORTVERSION=${PORTVERSION}
SUB_FILES=	elasticsearch-plugin pkg-message
PLIST_SUB=	SIGAR_ARCH=${SIGAR_ARCH} \
		SEARCHUSER=${SEARCHUSER} \
		SEARCHGROUP=${SEARCHGROUP} \
		LUCENEVER=${LUCENEVER} \
		PORTVERSION=${PORTVERSION} \
		ELASTIC_DBDIR=${ELASTIC_DBDIR} \
		ELASTIC_LOGDIR=${ELASTIC_LOGDIR} \
		SIGAR_LIBNAME=${SIGAR_LIBNAME}

post-patch:
	${SED} -i .bak -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/config/elasticsearch.yml

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/elasticsearch
.for f in ${CONFIG_FILES}
	${INSTALL} -m 440 ${WRKSRC}/config/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/elasticsearch-plugin ${STAGEDIR}${PREFIX}/bin/elasticsearch-plugin
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch
.for f in ${JARS}
	${INSTALL_DATA} ${WRKSRC}/lib/${f} ${STAGEDIR}${PREFIX}/lib/elasticsearch/
.endfor

	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/sigar
#	${INSTALL_DATA} ${WRKSRC}/lib/sigar/sigar-1.6.4.jar ${STAGEDIR}${PREFIX}/lib/elasticsearch/sigar/
	cd ${STAGEDIR}${PREFIX}/lib/elasticsearch/sigar && ${LN} -s ${JAVAJARDIR}/sigar.jar
	cd ${STAGEDIR}${PREFIX}/lib/elasticsearch/sigar && ${LN} -s ${JAVAJARDIR}/${SIGAR_LIBNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
