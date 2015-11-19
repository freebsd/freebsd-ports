# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch
PORTVERSION=	2.0.0
CATEGORIES=	textproc java devel
MASTER_SITES=	http://download.elasticsearch.org/${PORTNAME}/${PORTNAME}/ \
		http://mirrors.rit.edu/zi/
PKGNAMESUFFIX=	2

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Full-text search engine for Java

LICENSE=	APACHE20

CONFLICTS=	elasticsearch-[0-9]*

USES=		cpe
NO_ARCH=	yes
USE_JAVA=	yes
NO_BUILD=	yes
JAVA_VERSION=	1.7+
USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

LUCENEVER=	5.2.1
CONFIG_FILES=	elasticsearch.yml logging.yml
JARS=		elasticsearch-${PORTVERSION}.jar \
		HdrHistogram-2.1.6.jar \
		antlr-runtime-3.5.jar \
		apache-log4j-extras-1.2.17.jar \
		asm-4.1.jar \
		asm-commons-4.1.jar \
		commons-cli-1.3.1.jar \
		compiler-0.8.13.jar \
		compress-lzf-1.0.2.jar \
		groovy-all-2.4.4-indy.jar \
		guava-18.0.jar \
		hppc-0.7.1.jar \
		jackson-core-2.5.3.jar \
		jackson-dataformat-cbor-2.5.3.jar \
		jackson-dataformat-smile-2.5.3.jar \
		jackson-dataformat-yaml-2.5.3.jar \
		jna-4.1.0.jar \
		joda-convert-1.2.jar \
		joda-time-2.8.2.jar \
		jsr166e-1.1.0.jar \
		jts-1.13.jar \
		log4j-1.2.17.jar \
		lucene-analyzers-common-${LUCENEVER}.jar \
		lucene-backward-codecs-${LUCENEVER}.jar \
		lucene-core-${LUCENEVER}.jar \
		lucene-expressions-${LUCENEVER}.jar \
		lucene-grouping-${LUCENEVER}.jar \
		lucene-highlighter-${LUCENEVER}.jar \
		lucene-join-${LUCENEVER}.jar \
		lucene-memory-${LUCENEVER}.jar \
		lucene-misc-${LUCENEVER}.jar \
		lucene-queries-${LUCENEVER}.jar \
		lucene-queryparser-${LUCENEVER}.jar \
		lucene-sandbox-${LUCENEVER}.jar \
		lucene-spatial-${LUCENEVER}.jar \
		lucene-suggest-${LUCENEVER}.jar \
		netty-3.10.5.Final.jar \
		snakeyaml-1.12.jar \
		spatial4j-0.4.1.jar \
		t-digest-3.0.jar
BINS=		elasticsearch.in.sh \
		elasticsearch \
		plugin

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

SUB_LIST=	SEARCHUSER=${SEARCHUSER} \
		SEARCHGROUP=${SEARCHGROUP} \
		PORTVERSION=${PORTVERSION}
SUB_FILES=	pkg-message
PLIST_SUB=	SEARCHUSER=${SEARCHUSER} \
		SEARCHGROUP=${SEARCHGROUP} \
		LUCENEVER=${LUCENEVER} \
		PORTVERSION=${PORTVERSION} \
		ELASTIC_DBDIR=${ELASTIC_DBDIR} \
		ELASTIC_LOGDIR=${ELASTIC_LOGDIR}

post-patch:
	${SED} -i .bak -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/config/elasticsearch.yml
	${SED} -i .bak -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/bin/elasticsearch.in.sh

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/elasticsearch
.for f in ${CONFIG_FILES}
	${INSTALL} -m 440 ${WRKSRC}/config/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/bin
.for f in ${BINS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/lib/elasticsearch/bin
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/lib
.for f in ${JARS}
	${INSTALL_DATA} ${WRKSRC}/lib/${f} ${STAGEDIR}${PREFIX}/lib/elasticsearch/lib
.endfor

	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/elasticsearch

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s ${PREFIX}/lib/elasticsearch/bin/plugin elasticsearch-plugin

.include <bsd.port.mk>
