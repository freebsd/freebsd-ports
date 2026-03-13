PORTNAME=	elasticsearch
DISTVERSION=	7.17.29
CATEGORIES=	textproc java devel
MASTER_SITES=	https://artifacts.elastic.co/downloads/${PORTNAME}/ \
		LOCAL/vvd/elastic
PKGNAMESUFFIX=	7
DISTNAME=	${PORTNAME}-${DISTVERSION}-darwin-x86_64

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Full-text search engine for Java
WWW=		https://www.elastic.co/

LICENSE=	APACHE20

DEPRECATED=	7.x reached EoL on 15 Jan 2026 - use textproc/elasticsearch8 or textproc/elasticsearch9*
EXPIRATION_DATE=	2026-06-30

BUILD_DEPENDS=	jna>0:devel/jna
RUN_DEPENDS=	bash>0:shells/bash \
		jna>0:devel/jna

USES=		cpe java shebangfix
JAVA_VERSION=	21 17 11 8
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	bin/elasticsearch bin/elasticsearch-certgen \
		bin/elasticsearch-certutil bin/elasticsearch-cli \
		bin/elasticsearch-croneval bin/elasticsearch-env \
		bin/elasticsearch-env-from-file bin/elasticsearch-keystore \
		bin/elasticsearch-migrate bin/elasticsearch-node \
		bin/elasticsearch-plugin bin/elasticsearch-saml-metadata \
		bin/elasticsearch-setup-passwords bin/elasticsearch-shard \
		bin/elasticsearch-sql-cli bin/elasticsearch-syskeygen \
		bin/elasticsearch-users bin/x-pack-env bin/x-pack-security-env \
		bin/x-pack-watcher-env

CONFLICTS=	${PORTNAME}8 ${PORTNAME}9*

NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	limit:^7
SUB_FILES=	pkg-message
SUB_LIST=	ETCDIR=${ETCDIR} \
		JAVA_HOME=${JAVA_HOME}

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

SEARCHUSER?=	${PORTNAME}
SEARCHGROUP?=	${SEARCHUSER}
.if ${SEARCHUSER} == ${PORTNAME}
USERS=		${SEARCHUSER}
.endif
.if ${SEARCHGROUP} == ${PORTNAME}
GROUPS=		${SEARCHGROUP}
.endif

PORTDOCS=	LICENSE.txt NOTICE.txt README.asciidoc

OPTIONS_DEFINE=	DOCS

CONFIG_FILES=	elasticsearch.yml jvm.options log4j2.properties \
		role_mapping.yml roles.yml
BINS=		elasticsearch elasticsearch-certgen elasticsearch-certutil \
		elasticsearch-cli elasticsearch-croneval elasticsearch-env \
		elasticsearch-env-from-file elasticsearch-keystore \
		elasticsearch-migrate elasticsearch-node elasticsearch-plugin \
		elasticsearch-saml-metadata elasticsearch-setup-passwords \
		elasticsearch-shard elasticsearch-sql-cli \
		elasticsearch-sql-cli-${DISTVERSION}.jar \
		elasticsearch-syskeygen elasticsearch-users x-pack-env \
		x-pack-security-env x-pack-watcher-env

post-patch:
	${RM} ${WRKSRC}/lib/jna-*.jar
# ML plugin not supported on FreeBSD
	${RM} -rf ${WRKSRC}/modules/x-pack/x-pack-ml
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/bin/elasticsearch-env

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} \
		 ${STAGEDIR}${PREFIX}/lib/elasticsearch/bin \
		 ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins \
		 ${STAGEDIR}${PREFIX}/libexec/elasticsearch
.for f in ${CONFIG_FILES}
	${INSTALL} ${WRKSRC}/config/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor
	${INSTALL_SCRIPT} ${BINS:S|^|${WRKSRC}/bin/|} ${STAGEDIR}${PREFIX}/lib/elasticsearch/bin
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/elasticsearch/lib/ "-name *\.jar")
	(cd ${WRKSRC}/modules && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/elasticsearch/modules/)
	${INSTALL} -lrs ${STAGEDIR}${ETCDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/config
	${LN} -s ${JAVASHAREDIR}/classes/jna.jar ${STAGEDIR}${PREFIX}/lib/elasticsearch/lib/jna-0.0.0.jar

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

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
	${ECHO} "@dir(${SEARCHUSER},${SEARCHGROUP},0755) ${ETCDIR}" >> ${TMPPLIST}

.include <bsd.port.mk>
