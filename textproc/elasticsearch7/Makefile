# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch
PORTVERSION=	7.6.1
CATEGORIES=	textproc java devel
MASTER_SITES=	https://artifacts.elastic.co/downloads/${PORTNAME}/
PKGNAMESUFFIX=	7
DISTNAME=	${PORTNAME}-${PORTVERSION}-no-jdk-linux-x86_64

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Full-text search engine for Java

LICENSE=	APACHE20

BUILD_DEPENDS=	jna>0:devel/jna
RUN_DEPENDS=	bash>0:shells/bash \
		jna>0:devel/jna

USES=		cpe shebangfix

CONFLICTS=	elasticsearch[56]-[0-9]*

NO_ARCH=	yes
USE_JAVA=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
JAVA_VERSION=	8+
USE_RC_SUBR=	${PORTNAME}
SHEBANG_FILES=	bin/elasticsearch \
		bin/elasticsearch-certgen \
		bin/elasticsearch-certutil \
		bin/elasticsearch-cli \
		bin/elasticsearch-croneval \
		bin/elasticsearch-env \
		bin/elasticsearch-env-from-file \
		bin/elasticsearch-keystore \
		bin/elasticsearch-migrate \
		bin/elasticsearch-node \
		bin/elasticsearch-plugin \
		bin/elasticsearch-saml-metadata \
		bin/elasticsearch-setup-passwords \
		bin/elasticsearch-shard \
		bin/elasticsearch-sql-cli \
		bin/elasticsearch-syskeygen \
		bin/elasticsearch-users \
		bin/x-pack-env \
		bin/x-pack-security-env \
		bin/x-pack-watcher-env

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

CONFIG_FILES=	elasticsearch.yml \
		jvm.options \
		log4j2.properties \
		role_mapping.yml \
		roles.yml
BINS=		elasticsearch \
		elasticsearch-certgen \
		elasticsearch-certutil \
		elasticsearch-cli \
		elasticsearch-croneval \
		elasticsearch-env \
		elasticsearch-env-from-file \
		elasticsearch-keystore \
		elasticsearch-migrate \
		elasticsearch-node \
		elasticsearch-plugin \
		elasticsearch-saml-metadata \
		elasticsearch-setup-passwords \
		elasticsearch-shard \
		elasticsearch-sql-cli \
		elasticsearch-sql-cli-${PORTVERSION}.jar \
		elasticsearch-syskeygen \
		elasticsearch-users \
		x-pack-env \
		x-pack-security-env \
		x-pack-watcher-env

PORTDOCS=	LICENSE.txt \
		NOTICE.txt \
		README.asciidoc

SIGAR_ARCH=	${ARCH:S|i386|x86|}
SEARCHUSER?=	elasticsearch
SEARCHGROUP?=	${SEARCHUSER}
USERS=		${SEARCHUSER}
GROUPS=		${SEARCHGROUP}

SUB_LIST=	ETCDIR=${ETCDIR} JAVA_HOME=${JAVA_HOME}
SUB_FILES=	pkg-message

post-patch:
	${RM} ${WRKSRC}/lib/jna-*.jar
	# ML plugin not supported on FreeBSD
	${RM} -rf ${WRKSRC}/modules/x-pack/x-pack-ml

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/elasticsearch
.for f in ${CONFIG_FILES}
	${INSTALL} ${WRKSRC}/config/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/bin
.for f in ${BINS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/lib/elasticsearch/bin
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/lib
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/elasticsearch/lib/ "-name *\.jar")

	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/modules
	(cd ${WRKSRC}/modules && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/elasticsearch/modules/)
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/elasticsearch
	${INSTALL} -lrs ${STAGEDIR}${ETCDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/config
	${LN} -s ${JAVASHAREDIR}/classes/jna.jar ${STAGEDIR}${PREFIX}/lib/elasticsearch/lib/jna.jar

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

post-install:
	${ECHO} "@sample ${ETCDIR}/elasticsearch.yml.sample" >> ${TMPPLIST}
	${ECHO} "@sample ${ETCDIR}/jvm.options.sample" >> ${TMPPLIST}
	${ECHO} "@sample ${ETCDIR}/log4j2.properties.sample" >> ${TMPPLIST}
	${ECHO} "@sample ${ETCDIR}/role_mapping.yml.sample" >> ${TMPPLIST}
	${ECHO} "@sample ${ETCDIR}/roles.yml.sample" >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/lib/elasticsearch -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${ECHO} "@dir lib/elasticsearch/plugins" >> ${TMPPLIST}
	${ECHO} "@dir libexec/elasticsearch" >> ${TMPPLIST}
	${ECHO} "@dir(elasticsearch,elasticsearch,0755) ${ETCDIR}" >> ${TMPPLIST}

.include <bsd.port.mk>
