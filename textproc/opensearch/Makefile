PORTNAME=	opensearch
DISTVERSION?=	3.1.0
DISTVERSIONSUFFIX=	-linux-x64
PORTREVISION?=	0
CATEGORIES=	textproc java devel
MASTER_SITES=	https://artifacts.opensearch.org/releases/bundle/${PORTNAME}/${DISTVERSION}/
PKGNAMESUFFIX?=	#

MAINTAINER=	opensearch@FreeBSD.org
COMMENT?=	Full-text search engine for Java
WWW=		https://opensearch.org

LICENSE=	APACHE20

BUILD_DEPENDS=	jna>0:devel/jna
RUN_DEPENDS=	bash>0:shells/bash \
		jna>0:devel/jna

USES=		cpe java shebangfix
JAVA_VERSION=	21+
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	bin/opensearch bin/opensearch-cli \
		bin/opensearch-env bin/opensearch-env-from-file \
		bin/opensearch-keystore bin/opensearch-node \
		bin/opensearch-plugin bin/opensearch-shard \
		plugins/opensearch-security/tools/audit_config_migrater.sh \
		plugins/opensearch-security/tools/hash.sh \
		plugins/opensearch-security/tools/install_demo_configuration.sh \
		plugins/opensearch-security/tools/securityadmin.sh

CONFLICTS?=	opensearch13 opensearch210 opensearch213 opensearch216

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

OPTIONS_DEFINE=	PLUGINS
OPTIONS_DEFAULT=PLUGINS

.include <bsd.port.options.mk>

CONFIG_FILES=	opensearch.yml jvm.options log4j2.properties

PLUGINS_CONFIG_FILES?=	\
		opensearch-notifications-core/notifications-core.yml \
		opensearch-notifications/notifications.yml \
		opensearch-observability/observability.yml
.if ${PKGNAMESUFFIX} == "210" || ${PKGNAMESUFFIX} == "213" || ${PKGNAMESUFFIX} == "216"
PLUGINS_CONFIG_FILES+=	\
		opensearch-performance-analyzer/agent-stats-metadata \
		opensearch-performance-analyzer/log4j2.xml \
		opensearch-performance-analyzer/opensearch_security.policy \
		opensearch-performance-analyzer/performance-analyzer.properties \
		opensearch-performance-analyzer/plugin-stats-metadata \
		opensearch-performance-analyzer/rca.conf \
		opensearch-performance-analyzer/rca_idle_cluster_manager.conf \
		opensearch-performance-analyzer/rca_cluster_manager.conf \
		opensearch-performance-analyzer/supervisord.conf \
		opensearch-security/whitelist.yml
.endif
PLUGINS_CONFIG_FILES+=	\
		opensearch-reports-scheduler/reports-scheduler.yml \
		opensearch-security/action_groups.yml \
		opensearch-security/allowlist.yml \
		opensearch-security/audit.yml \
		opensearch-security/config.yml \
		opensearch-security/internal_users.yml \
		opensearch-security/nodes_dn.yml \
		opensearch-security/roles.yml \
		opensearch-security/roles_mapping.yml \
		opensearch-security/tenants.yml

# Upstream provide some *.example files.  These are also copied as sample filse
# but we do not register them as @sample to avoid installing filse that needs
# to be tuned a site specific way.
PLUGINS_SAMPLE_CONFIG_FILES=	\
		opensearch-security/opensearch.yml

BINS=		opensearch opensearch-cli opensearch-env \
		opensearch-env-from-file opensearch-keystore \
		opensearch-node opensearch-plugin \
		opensearch-shard

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
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/opensearch/extensions
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/opensearch/lib
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "agent lib modules" ${STAGEDIR}${PREFIX}/lib/opensearch/)
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/opensearch
	${INSTALL} -lrs ${STAGEDIR}${ETCDIR} ${STAGEDIR}${PREFIX}/lib/opensearch/config
	${LN} -s ${JAVASHAREDIR}/classes/jna.jar ${STAGEDIR}${PREFIX}/lib/opensearch/lib/jna.jar

do-install-PLUGINS-on:
	${MKDIR} ${STAGEDIR}${ETCDIR}/opensearch-notifications-core \
		 ${STAGEDIR}${ETCDIR}/opensearch-notifications \
		 ${STAGEDIR}${ETCDIR}/opensearch-observability \
		 ${STAGEDIR}${ETCDIR}/opensearch-reports-scheduler \
		 ${STAGEDIR}${ETCDIR}/opensearch-security
.if ${PKGNAMESUFFIX} == "210" || ${PKGNAMESUFFIX} == "213" || ${PKGNAMESUFFIX} == "216"
	${MKDIR} ${STAGEDIR}${ETCDIR}/opensearch-performance-analyzer
.endif

.for f in ${PLUGINS_CONFIG_FILES}
	${INSTALL} ${WRKSRC}/config/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
	${ECHO} "@sample(opensearch,opensearch,640) ${ETCDIR}/${f}.sample" >> ${TMPPLIST}
.endfor
.for f in ${PLUGINS_SAMPLE_CONFIG_FILES}
	${INSTALL} ${WRKSRC}/config/${f}.example ${STAGEDIR}${ETCDIR}/${f}.sample
	${ECHO} "@(opensearch,opensearch,640) ${ETCDIR}/${f}.sample" >> ${TMPPLIST}
.endfor
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "plugins" ${STAGEDIR}${PREFIX}/lib/opensearch/)
	(cd ${WRKSRC}/plugins/opensearch-security/tools && ${COPYTREE_BIN} "*.sh" ${STAGEDIR}${PREFIX}/lib/opensearch/plugins/opensearch-security/tools)

post-install:
.for f in ${CONFIG_FILES}
	${ECHO} "@sample(opensearch,opensearch,640) ${ETCDIR}/${f}.sample" >> ${TMPPLIST}
.endfor
	${FIND} -s ${STAGEDIR}${PREFIX}/lib/opensearch -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${ECHO} "@dir lib/opensearch/extensions" >> ${TMPPLIST}
	${ECHO} "@dir libexec/opensearch" >> ${TMPPLIST}
.if ${PORT_OPTIONS:MPLUGINS}
	${ECHO} "@dir lib/opensearch/plugins" >> ${TMPPLIST}
	${ECHO} "@dir(opensearch,opensearch,0750) ${ETCDIR}/opensearch-notifications-core" >> ${TMPPLIST}
	${ECHO} "@dir(opensearch,opensearch,0750) ${ETCDIR}/opensearch-notifications" >> ${TMPPLIST}
	${ECHO} "@dir(opensearch,opensearch,0750) ${ETCDIR}/opensearch-observability" >> ${TMPPLIST}
.if ${PKGNAMESUFFIX} == "210" || ${PKGNAMESUFFIX} == "213" || ${PKGNAMESUFFIX} == "216"
	${ECHO} "@dir(opensearch,opensearch,0750) ${ETCDIR}/opensearch-performance-analyzer" >> ${TMPPLIST}
.endif
	${ECHO} "@dir(opensearch,opensearch,0750) ${ETCDIR}/opensearch-reports-scheduler" >> ${TMPPLIST}
	${ECHO} "@dir(opensearch,opensearch,0750) ${ETCDIR}/opensearch-security" >> ${TMPPLIST}
.endif
	${ECHO} "@dir(opensearch,opensearch,0750) ${ETCDIR}/" >> ${TMPPLIST}

.include <bsd.port.mk>
