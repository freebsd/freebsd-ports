PORTNAME=	elasticsearch
DISTVERSIONPREFIX=	v
DISTVERSION=	9.4.9
PORTREVISION=	1
CATEGORIES=	textproc java devel
PKGNAMESUFFIX=	${DISTVERSION:R:S|.||}

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Distributed, RESTful search and analytics engine (${DISTVERSION:R:R} version)
WWW=		https://www.elastic.co/

LICENSE=	APACHE20 AGPLv3 SSPLv1 EL20
LICENSE_COMB=	multi
LICENSE_NAME_EL20=	Elastic License 2.0
LICENSE_NAME_SSPLv1=	Server Side Public License v1
LICENSE_FILE_EL20=	${WRKSRC}/licenses/ELASTIC-LICENSE-2.0.txt
LICENSE_FILE_SSPLv1=	${WRKSRC}/licenses/AGPL-3.0+SSPL-1.0+ELASTIC-LICENSE-2.0.txt
LICENSE_FILE=		${WRKSRC}/LICENSE.txt
LICENSE_PERMS_EL20=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_SSPLv1=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64

BUILD_RUN_DEPENDS=	jna>0:devel/jna
BUILD_DEPENDS=		gradle>=9.7.1:devel/gradle \
			protobuf>=29.6:devel/protobuf \
			${LOCALBASE}/openjdk21/bin/java:java/openjdk21
RUN_DEPENDS=		bash:shells/bash

USES=		cpe java shebangfix
CPE_VENDOR=	elastic
USE_GITHUB=	yes
GH_ACCOUNT=	elastic
JAVA_VERSION=	25
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	distribution/src/bin/elasticsearch \
		distribution/src/bin/elasticsearch-cli \
		distribution/src/bin/elasticsearch-env \
		distribution/src/bin/elasticsearch-env-from-file \
		distribution/src/bin/elasticsearch-geoip \
		distribution/src/bin/elasticsearch-keystore \
		distribution/src/bin/elasticsearch-node \
		distribution/src/bin/elasticsearch-plugin \
		distribution/src/bin/elasticsearch-shard \
		x-pack/plugin/security/src/main/bin/elasticsearch-certgen \
		x-pack/plugin/security/src/main/bin/elasticsearch-certutil \
		x-pack/plugin/security/src/main/bin/elasticsearch-create-enrollment-token \
		x-pack/plugin/security/src/main/bin/elasticsearch-reconfigure-node \
		x-pack/plugin/security/src/main/bin/elasticsearch-reset-password \
		x-pack/plugin/security/src/main/bin/elasticsearch-saml-metadata \
		x-pack/plugin/security/src/main/bin/elasticsearch-service-tokens \
		x-pack/plugin/security/src/main/bin/elasticsearch-setup-passwords \
		x-pack/plugin/security/src/main/bin/elasticsearch-syskeygen \
		x-pack/plugin/security/src/main/bin/elasticsearch-users \
		x-pack/plugin/sql/src/main/bin/elasticsearch-sql-cli \
		x-pack/plugin/watcher/src/main/bin/elasticsearch-croneval

CONFLICTS=	${PORTNAME}*

PORTSCOUT=	limit:^${DISTVERSION:R:S|.|\.|}\.
SUB_FILES=	pkg-message
SUB_LIST=	ETCDIR=${ETCDIR} \
		JAVA_HOME=${JAVA_HOME} \
		BINDIR=${PREFIX}/bin \
		SEARCHUSER=${SEARCHUSER} \
		LOCALBASE=${LOCALBASE}

SEARCHUSER?=	${PORTNAME}
SEARCHGROUP?=	${SEARCHUSER}
.if ${SEARCHUSER} == ${PORTNAME}
USERS=		${SEARCHUSER}
.endif
.if ${SEARCHGROUP} == ${PORTNAME}
GROUPS=		${SEARCHGROUP}
.endif

PORTDOCS=	NOTICE.txt README.asciidoc

OPTIONS_DEFINE=		DOCS LIBVEC
OPTIONS_DEFAULT=	LIBVEC

LIBVEC_DESC=		Build vector library (libvec.so)
LIBVEC_USES=		compiler:c++17-lang gmake
LIBVEC_VARS=		LIBVEC_BOOL=true
LIBVEC_VARS_OFF=	LIBVEC_BOOL=false

# To rebuild the deps archive:
# 1. make makesum build DEV_UPDATE_MODE=yes
# 2. Upload the *-deps archive
# 3. make clean makesum
DEV_UPDATE_MODE?=	no
.if (${DEV_UPDATE_MODE} == "no")
MASTER_SITES+=	LOCAL/vvd/elastic:deps
DISTFILES+=	${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}:deps
GRADLE_ARGS=	--offline
.endif

# Move Gradle's home below ${WRKDIR} instead of using ${HOME}/.gradle
_GRADLE_ENV=	GRADLE_USER_HOME=${WRKDIR}/gradle-${PORTNAME} \
		JAVA_TOOLCHAIN_HOME=${JAVA_HOME} \
		RUNTIME_JAVA_HOME=${JAVA_HOME} \
		LOCAL_VEC_BINARY_OS=true \
		LOCAL_ZSTD_BINARY=true

_GRADLE_RUN=	${SETENV} ${_GRADLE_ENV} gradle --no-daemon \
		--project-cache-dir ${WRKDIR}/gradle-${PORTNAME} \
		--build-cache --no-scan

_LOCALDIST=	${WRKSRC}/build/distribution/local/${PORTNAME}-${DISTVERSION}

CONFIG_FILES=	elasticsearch.yml jvm.options log4j2.properties \
		role_mapping.yml roles.yml
BINS=		elasticsearch elasticsearch-certgen elasticsearch-certutil \
		elasticsearch-cli elasticsearch-create-enrollment-token \
		elasticsearch-croneval elasticsearch-env \
		elasticsearch-env-from-file elasticsearch-geoip \
		elasticsearch-keystore elasticsearch-node elasticsearch-plugin \
		elasticsearch-reconfigure-node elasticsearch-reset-password \
		elasticsearch-saml-metadata elasticsearch-service-tokens \
		elasticsearch-setup-passwords elasticsearch-shard \
		elasticsearch-sql-cli elasticsearch-sql-cli-${DISTVERSION}.jar \
		elasticsearch-syskeygen elasticsearch-users

post-extract:
	${CP} ${PATCHDIR}/public.key ${WRKSRC} ## extracted from: x-pack-core-X.XX.X.jar
	${CP} ${PATCHDIR}/branches.json ${WRKSRC}

post-patch:
	${RM} -r ${WRKSRC}/gradle/gradle-daemon-jvm.properties \
		${WRKSRC}/libs/entitlement/src/main26 \
		${WRKSRC}/libs/entitlement/src/main27 \
		${WRKSRC}/libs/entitlement/qa/entitlement-test-plugin/src/main26 \
		${WRKSRC}/libs/entitlement/qa/entitlement-test-plugin/src/main27
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' \
			 -e 's|%%DOCSDIR%%|${DOCSDIR}|' \
			 -e 's|%%ETCDIR%%|${ETCDIR}|' \
			 -e 's|%%PREFIX%%|${PREFIX}|' \
			 -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/libs/native/libraries/build.gradle \
		${WRKSRC}/x-pack/plugin/otel-data/build.gradle \
		${WRKSRC}/x-pack/plugin/prometheus/build.gradle \
		${WRKSRC}/qa/packaging/src/test/java/org/elasticsearch/packaging/util/Cleanup.java

do-configure:
	@${MKDIR} ${WRKDIR}/gradle-${PORTNAME}
	@${ECHO_CMD} \
		"org.gradle.java.installations.paths=${LOCALBASE}/openjdk21,${LOCALBASE}/openjdk25" \
		> ${WRKDIR}/gradle-${PORTNAME}/gradle.properties
	@${ECHO_CMD} "org.gradle.java.installations.auto-download=false" >> \
		${WRKDIR}/gradle-${PORTNAME}/gradle.properties
	@${ECHO_CMD} "org.gradle.console=plain" >> ${WRKDIR}/gradle-${PORTNAME}/gradle.properties
	@${ECHO_CMD} "org.gradle.caching=true"  >> ${WRKDIR}/gradle-${PORTNAME}/gradle.properties
	@${ECHO_CMD} "org.gradle.daemon=false"  >> ${WRKDIR}/gradle-${PORTNAME}/gradle.properties
	@${ECHO_CMD} "org.gradle.projectcachedir=${WRKDIR}/gradle-${PORTNAME}" >> \
		${WRKDIR}/gradle-${PORTNAME}/gradle.properties

do-build:
	(cd ${WRKSRC} && ${_GRADLE_RUN} ${GRADLE_ARGS} localDistro \
		-Dbuild.snapshot=false -Dlicense.key=public.key \
		-Dfreebsd.build.override-jdk=true -Dfreebsd.build.fromPorts=true \
		-Dfreebsd.build.libvec=${LIBVEC_BOOL})

post-build:
	${RM} ${_LOCALDIST}/modules/repository-azure/jna-5*.jar \
		${_LOCALDIST}/modules/x-pack-inference/jna-5*.jar
	${REINPLACE_CMD} -e 's|hs_err_pid%p.log|$${ES_TMPDIR}/hs_err_pid%p.log|g' \
		-e 's|gc.log|$${ES_TMPDIR}/gc.log|g' \
		${_LOCALDIST}/config/jvm.options
	@${PRINTF} "\n## Path to native libraries\n-Des.nativelibs.path=${LOCALBASE}/lib\n" >> \
		${_LOCALDIST}/config/jvm.options
	${REINPLACE_CMD} -e 's|#path.data: /path/to/data|path.data: /var/db/elasticsearch|g' \
		-e 's|#path.logs: /path/to/logs|path.logs: /var/log/elasticsearch|g' \
		${_LOCALDIST}/config/elasticsearch.yml
	@${PRINTF} "\n# ml is currently not supported on FreeBSD\nxpack.ml.enabled: false\n" >> \
		${_LOCALDIST}/config/elasticsearch.yml
.if (${DEV_UPDATE_MODE} == "yes")
	# https://docs.gradle.org/current/userguide/dependency_caching.html#sec:cache-copy
	@(cd ${WRKDIR} && \
		${TAR} czf ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX} \
			gradle-${PORTNAME}/caches/modules-2/files-2.1 \
			gradle-${PORTNAME}/caches/modules-2/metadata-2.107)
	@${ECHO} "(!!!) Please upload the deps archive: ${DISTDIR}/${PORTNAME}-${DISTVERSION}-deps${EXTRACT_SUFX}"
.endif

post-build-LIBVEC-on:
	@${PRINTF} "\n-Dorg.elasticsearch.nativeaccess.enableVectorLibrary=true\n" \
		>> ${_LOCALDIST}/config/jvm.options

post-build-LIBVEC-off:
	@${PRINTF} "\n-Dorg.elasticsearch.nativeaccess.enableVectorLibrary=false\n" \
		>> ${_LOCALDIST}/config/jvm.options

do-install:
	${INSTALL} -d -m 0750 ${STAGEDIR}${ETCDIR}
.for f in ${CONFIG_FILES}
	${INSTALL} ${_LOCALDIST}/config/${f} ${STAGEDIR}${ETCDIR}/${f}.sample
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/bin
	${INSTALL_SCRIPT} ${BINS:S|^|${_LOCALDIST}/bin/|} ${STAGEDIR}${PREFIX}/lib/elasticsearch/bin
.for f in ${BINS}
	${RLN} ${STAGEDIR}${PREFIX}/lib/elasticsearch/bin/${f} ${STAGEDIR}${PREFIX}/bin/${f}
	${ECHO_CMD} "bin/${f}" >> ${TMPPLIST}
.endfor
	(cd ${_LOCALDIST} && \
		${COPYTREE_SHARE} lib ${STAGEDIR}${PREFIX}/lib/elasticsearch "-name *\.jar" && \
		${COPYTREE_SHARE} modules ${STAGEDIR}${PREFIX}/lib/elasticsearch)
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/plugins \
		 ${STAGEDIR}${PREFIX}/libexec/elasticsearch \
		 ${STAGEDIR}${ETCDIR}/jvm.options.d
	${INSTALL} -lrs ${STAGEDIR}${ETCDIR} ${STAGEDIR}${PREFIX}/lib/elasticsearch/config
	${LN} -s ${JAVASHAREDIR}/classes/jna.jar ${STAGEDIR}${PREFIX}/lib/elasticsearch/lib/jna-0.0.0.jar
	${TOUCH} ${STAGEDIR}${ETCDIR}/users.sample ${STAGEDIR}${ETCDIR}/users_roles.sample

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-install-LIBVEC-on:
	${INSTALL_LIB} ${WRKSRC}/libs/simdvec/native/build/libs/vec/freebsd/amd64/libvec.so \
		${STAGEDIR}${PREFIX}/lib
	${ECHO} "${PREFIX}/lib/libvec.so" >> ${TMPPLIST}

post-install:
	${FIND} -s ${STAGEDIR}${PREFIX}/lib/elasticsearch -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' >> ${TMPPLIST}
	${ECHO} "@dir lib/elasticsearch/modules/x-pack-ml/platform" >> ${TMPPLIST}
	${ECHO} "@dir lib/elasticsearch/plugins" >> ${TMPPLIST}
	${ECHO} "@dir libexec/elasticsearch" >> ${TMPPLIST}
	${ECHO} "@dir(${SEARCHUSER},${SEARCHGROUP},0755) ${ETCDIR}" >> ${TMPPLIST}
	${ECHO} "@owner ${SEARCHUSER}" >> ${TMPPLIST}
	${ECHO} "@group ${SEARCHGROUP}" >> ${TMPPLIST}
	${ECHO} "@mode 0750" >> ${TMPPLIST}
	${ECHO} "@dir ${ETCDIR}/jvm.options.d" >> ${TMPPLIST}
	${ECHO} "@mode 0660" >> ${TMPPLIST}
	${ECHO} "@sample ${ETCDIR}/users.sample" >> ${TMPPLIST}
	${ECHO} "@sample ${ETCDIR}/users_roles.sample" >> ${TMPPLIST}
	${ECHO} "@sample ${ETCDIR}/elasticsearch.yml.sample" >> ${TMPPLIST}
	${ECHO} "@sample ${ETCDIR}/jvm.options.sample" >> ${TMPPLIST}
	${ECHO} "@sample ${ETCDIR}/log4j2.properties.sample" >> ${TMPPLIST}
	${ECHO} "@sample ${ETCDIR}/role_mapping.yml.sample" >> ${TMPPLIST}
	${ECHO} "@sample ${ETCDIR}/roles.yml.sample" >> ${TMPPLIST}
	${ECHO} "@mode" >> ${TMPPLIST}
	${ECHO} "@owner" >> ${TMPPLIST}
	${ECHO} "@group" >> ${TMPPLIST}

.include <bsd.port.mk>
