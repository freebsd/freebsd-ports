# Created by: Sven R <freebsd@hackacad.net>

PORTNAME=	opensearch
DISTVERSION=	1.2.4
DISTVERSIONSUFFIX=	-linux-x64
CATEGORIES=	textproc java devel
MASTER_SITES=	https://artifacts.opensearch.org/releases/bundle/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	opensearch@FreeBSD.org
COMMENT=	Full-text search engine for Java

LICENSE=	APACHE20

BUILD_DEPENDS=	jna>0:devel/jna
RUN_DEPENDS=	bash>0:shells/bash \
		jna>0:devel/jna

USES=		cpe shebangfix
USE_JAVA=	yes
JAVA_VERSION=	11+
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	bin/opensearch bin/opensearch-cli \
		bin/opensearch-env bin/opensearch-env-from-file \
		bin/opensearch-keystore bin/opensearch-node \
		bin/opensearch-plugin bin/opensearch-shard \
		bin/performance-analyzer-agent-cli \
		plugins/opensearch-security/tools/audit_config_migrater.sh \
		plugins/opensearch-security/tools/hash.sh \
		plugins/opensearch-security/tools/install_demo_configuration.sh \
		plugins/opensearch-security/tools/securityadmin.sh

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	PLUGINS
OPTIONS_DEFAULT=PLUGINS

.include <bsd.port.options.mk>

CONFIG_FILES=	opensearch.yml jvm.options log4j2.properties

BINS=		opensearch opensearch-cli opensearch-env \
		opensearch-env-from-file opensearch-keystore \
		opensearch-node opensearch-plugin \
		opensearch-shard performance-analyzer-agent-cli

SEARCHUSER?=	opensearch
SEARCHGROUP?=	${SEARCHUSER}
USERS=		${SEARCHUSER}
GROUPS=		${SEARCHGROUP}

SUB_FILES=	pkg-message
SUB_LIST=	ETCDIR=${ETCDIR} \
		JAVA_HOME=${JAVA_HOME}

post-patch:
	${RM} ${WRKSRC}/lib/jna-*.jar

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/opensearch
.for f in ${CONFIG_FILES}
	${INSTALL} ${WRKSRC}/config/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/opensearch/bin
.for f in ${BINS}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/lib/opensearch/bin
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/opensearch/lib
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "lib modules" ${STAGEDIR}${PREFIX}/lib/opensearch/)
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/opensearch
	${INSTALL} -lrs ${STAGEDIR}${ETCDIR} ${STAGEDIR}${PREFIX}/lib/opensearch/config
	${LN} -s ${JAVASHAREDIR}/classes/jna.jar ${STAGEDIR}${PREFIX}/lib/opensearch/lib/jna.jar

do-install-PLUGINS-on:
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "plugins" ${STAGEDIR}${PREFIX}/lib/opensearch/)
	(cd ${WRKSRC}/plugins/opensearch-security/tools && ${COPYTREE_BIN} "*.sh" ${STAGEDIR}${PREFIX}/lib/opensearch/plugins/opensearch-security/tools)

post-install:
.for f in ${CONFIG_FILES}
	${ECHO} "@sample ${ETCDIR}/${f}.sample" >> ${TMPPLIST}
.endfor
	${FIND} -s ${STAGEDIR}${PREFIX}/lib/opensearch -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${ECHO} "@dir lib/opensearch/plugins" >> ${TMPPLIST}
	${ECHO} "@dir libexec/opensearch" >> ${TMPPLIST}
	${ECHO} "@dir(opensearch,opensearch,0755) ${ETCDIR}" >> ${TMPPLIST}

.include <bsd.port.mk>
