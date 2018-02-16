# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch
PORTVERSION=	6.0.1
CATEGORIES=	textproc java devel
MASTER_SITES=	https://artifacts.elastic.co/downloads/${PORTNAME}/ \
		http://mirrors.rit.edu/zi/
PKGNAMESUFFIX=	6

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Full-text search engine for Java

LICENSE=	APACHE20

RUN_DEPENDS=	bash>0:shells/bash

CONFLICTS=	elasticsearch-[0-9]* elasticsearch2-[0-9]* elasticsearch5-[0-9]*

USES=		cpe shebangfix
NO_ARCH=	yes
USE_JAVA=	yes
NO_BUILD=	yes
JAVA_VERSION=	1.8+
USE_RC_SUBR=	${PORTNAME}
SHEBANG_FILES=	bin/elasticsearch-plugin \
		bin/elasticsearch

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

LUCENEVER=	6.4.1
CONFIG_FILES=	elasticsearch.yml log4j2.properties jvm.options
BINS=		elasticsearch \
		elasticsearch-plugin

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
PLIST_SUB+=	SEARCHUSER=${SEARCHUSER} \
		SEARCHGROUP=${SEARCHGROUP} \
		LUCENEVER=${LUCENEVER} \
		PORTVERSION=${PORTVERSION} \
		ELASTIC_DBDIR=${ELASTIC_DBDIR} \
		ELASTIC_LOGDIR=${ELASTIC_LOGDIR}

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/config/elasticsearch.yml
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/bin/elasticsearch

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/elasticsearch
.for f in ${CONFIG_FILES}
	${INSTALL} -m 440 ${WRKSRC}/config/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/bin
.for f in ${BINS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/lib/elasticsearch/bin
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/lib
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/elasticsearch/lib/ "-name *\.jar")

	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/modules
	(cd ${WRKSRC}/modules && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/elasticsearch/modules/)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/elasticsearch
	@${MKDIR} ${STAGEDIR}${ELASTIC_DBDIR} ${STAGEDIR}${ELASTIC_LOGDIR}
	cd ${STAGEDIR}${PREFIX}/bin && ${LN} -s ${PREFIX}/lib/elasticsearch/bin/elasticsearch-plugin elasticsearch-plugin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
