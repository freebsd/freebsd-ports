PORTNAME=	wazuh
DISTVERSIONPREFIX=	v
DISTVERSION=	4.12.0
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	https://packages.wazuh.com/deps/40/libraries/sources/:wazuh_sources \
		LOCAL/acm/${PORTNAME}/:wazuh_cache
PKGNAMESUFFIX=	-manager
DISTFILES=	${EXTERNAL_DISTFILES} \
		${PORTNAME}-cache-any-${DISTVERSION}${EXTRACT_SUFX}:wazuh_cache \
		${PORTNAME}-python-${DISTVERSION}${EXTRACT_SUFX}:wazuh_cache
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Security tool to monitor and check logs and intrusions (manager)
WWW=		https://wazuh.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

BUILD_DEPENDS=	autoconf>=2.71:devel/autoconf \
		bash>0:shells/bash \
		cmake:devel/cmake-core
LIB_DEPENDS+=	libarrow.so:databases/arrow \
		libcurl.so:ftp/curl \
		libepoll-shim.so:devel/libepoll-shim \
		libffi.so:devel/libffi \
		libgdbm.so:databases/gdbm \
		libnghttp2.so:www/libnghttp2 \
		libopenblas.so:math/openblas
RUN_DEPENDS=	bash>0:shells/bash

USES=		cpe gmake perl5 python:3.11 readline shebangfix sqlite:3 uidfix

USE_GITHUB=	yes
GH_TUPLE=	alonsobsd:wazuh-freebsd:${WAZUH_EXTRAFILE_TAGNAME}:wazuh

USE_RC_SUBR=	${PORTNAME}${PKGNAMESUFFIX}

MAKE_ARGS+=	TARGET=server INSTALLDIR=${WAZUHPREFIX} INSTALL_SHARED="${INSTALL_LIB}" PYTHON_SOURCE=yes OPTIMIZE_CPYTHON=no

WAZUH_CACHEFILE=	${PORTNAME}-cache-any-${DISTVERSION}${EXTRACT_SUFX}
WAZUH_EXTRAFILE=	alonsobsd-${PORTNAME}-freebsd-${WAZUH_EXTRAFILE_TAGNAME}_GH0${EXTRACT_SUFX}
WAZUH_EXTRAFILE_TAGNAME=cd0051b

EXTERNAL_DISTFILES=	audit-userspace.tar.gz:wazuh_sources \
			benchmark.tar.gz:wazuh_sources \
			bzip2.tar.gz:wazuh_sources \
			cJSON.tar.gz:wazuh_sources \
			cpp-httplib.tar.gz:wazuh_sources \
			cpython-3.11.13.tar.gz:wazuh_cache \
			curl.tar.gz:wazuh_sources \
			flatbuffers.tar.gz:wazuh_sources \
			googletest.tar.gz:wazuh_sources \
			http-request.tar.gz:wazuh_cache \
			jemalloc.tar.gz:wazuh_sources \
			libarchive.tar.gz:wazuh_sources \
			libdb.tar.gz:wazuh_sources \
			libffi.tar.gz:wazuh_sources \
			libpcre2.tar.gz:wazuh_sources \
			libplist.tar.gz:wazuh_sources	\
			libyaml.tar.gz:wazuh_sources \
			lua.tar.gz:wazuh_sources \
			lzma.tar.gz:wazuh_sources \
			msgpack.tar.gz:wazuh_sources \
			nlohmann.tar.gz:wazuh_cache \
			openssl.tar.gz:wazuh_sources \
			popt.tar.gz:wazuh_sources \
			procps.tar.gz:wazuh_sources \
			rocksdb.tar.gz:wazuh_sources \
			sqlite.tar.gz:wazuh_sources \
			zlib.tar.gz:wazuh_sources

OPTIONS_DEFINE=	INOTIFY PRELUDE ZEROMQ
OPTIONS_GROUP_DATABASE=	MYSQL PGSQL
OPTIONS_GROUP=		DATABASE

INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
PRELUDE_LIB_DEPENDS=	libprelude.so:security/libprelude
ZEROMQ_LIB_DEPENDS=	libczmq.so:net/czmq

INOTIFY_DESC=	Kevent based real time monitoring
PRELUDE_DESC=	Sensor support from Prelude SIEM
ZEROMQ_DESC=	ZeroMQ support

ZEROMQ_MAKE_ENV=	USE_ZEROMQ=yes
PRELUDE_MAKE_ENV=	USE_PRELUDE=yes
INOTIFY_MAKE_ENV=	USE_INOTIFY=yes
INOTIFY_USES=	pkgconfig
PGSQL_MAKE_ARGS=DATABASE=pgsql
PGSQL_USES=	pgsql
MYSQL_MAKE_ARGS=DATABASE=mysql
MYSQL_USES=	mysql

WAZUH_USER=	wazuh
WAZUH_GROUP=	wazuh
USERS=		${WAZUH_USER}
GROUPS=		${WAZUH_GROUP}

SUB_FILES=	pkg-message
CONFLICTS=	ossec-* wazuh-agent

WZBIN_FILES=	agent_control wazuh-logcollector wazuh-execd  manage_agents wazuh-modulesd \
		wazuh-agentlessd wazuh-analysisd wazuh-monitord wazuh-reportd wazuh-maild \
		wazuh-logtest-legacy wazuh-csyslogd wazuh-dbd verify-agent-conf clear_stats \
		wazuh-regex wazuh-integratord wazuh-db wazuh-remoted wazuh-authd wazuh-keystore

WZARBIN_FILES=	default-firewall-drop pf npf ipfw firewalld-drop disable-account \
		host-deny ip-customblock restart-wazuh route-null kaspersky wazuh-slack

WZSHEBANG_FILES=chardetect connexion cygdb cython cythonize f2py fixup_pubsub_v1_keywords.py \
		futurize httpx jp.py jsonschema normalizer openapi-spec-validator pasteurize \
		pyrsa-decrypt pyrsa-encrypt pyrsa-keygen pyrsa-priv2pub pyrsa-sign \
		pyrsa-verify rstpep2html.py rst2s5.py rst2xetex.py rst2man.py rst2odt.py \
		rst2latex.py rst2pseudoxml.py rst2odt_prepstyles.py rst2html.py rst2html5.py \
		rst2html4.py rst2xml.py tabulate uvicorn wsdump.py

WAZUHMOD660=	/queue/indexer /queue/vd
WAZUHMOD750=	/ /logs/wazuh /logs/archives /logs/alerts /logs/firewall \
		/logs/api /logs/cluster /bin /lib /queue /queue/agentless \
		/queue/db /queue/diff /queue/fts /queue/keystore /queue/logcollector \
		/queue/syscollector /queue/syscollector/db  /ruleset \
		/ruleset/decoders /ruleset/rules /ruleset/sca /wodles \
		/active-response /active-response/bin /agentless /var /backup \
		/backup/db /backup/agents /backup/groups /backup/shared \
		/wodles/aws /wodles/aws/buckets_s3 /wodles/aws/services /wodles/aws/subscribers \
		/wodles/azure /wodles/azure/azure_services /wodles/azure/db \
		/wodles/docker /wodles/gcloud /wodles/gcloud/buckets /wodles/gcloud/pubsub \
		/stats /integrations

WAZUHMOD770=	/etc/decoders /etc/lists /etc/lists/amazon /etc/rootcheck \
		/etc/rules /etc/shared/default /logs /queue/agent-groups \
		/queue/alerts /queue/cluster /queue/fim /queue/fim/db \
		/queue/rids /queue/sockets /queue/tasks /etc /etc/shared \
		/.ssh /var/db /var/download /var/db/agents /var/run /var/upgrade \
		/var/selinux /var/wodles /var/multigroups /queue/rids /queue/router

WAZUHPREFIX=	/var/ossec

WZPYTHONWHEELS=	cffi-1.15.1-cp311-cp311-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		cryptography-44.0.1-cp37-abi3-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		greenlet-2.0.2-cp311-cp311-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		grpcio-1.69.0-cp311-cp311-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		lazy_object_proxy-1.10.0-cp311-cp311-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		MarkupSafe-2.1.2-cp311-cp311-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		multidict-5.2.0-cp311-cp311-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		numpy-1.26.4-cp311-cp311-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		psutil-5.9.0-cp311-cp311-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		pyarrow-20.0.0-cp311-cp311-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		pyyaml-6.0.1-cp311-cp311-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		rpds_py-0.15.2-cp311-cp311-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		uvloop-0.17.0-cp311-cp311-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl

ARCH_BASE=	${ARCH:S/aarch64/arm64/g}
UNAME_r=	${_OSRELEASE:tl}
FBSD_RELEASE=	freebsd_${UNAME_r:S/./_/g:S/-/_/g}

.include <bsd.port.pre.mk>

.if ${ARCH} == "aarch64" && ${OSVERSION} < 1400000
IGNORE=		FreeBSD ${OSVERSION} ${ARCH} is not supported
.endif

.if ${ARCH} == "aarch64"
FBSD14_PATCH_LEVEL=     _p2
.endif

.if ${ARCH} != "aarch64"
FBSD13_PATCH_LEVEL=	#
FBSD14_PATCH_LEVEL=	_p2
.endif

.if ${OSVERSION} >= 1300139 && ${OSVERSION} < 1400000
FBSD_VERSION_BASE=freebsd_13_5_release${FBSD13_PATCH_LEVEL}
FBSD_MAJOR_VERSION=13
WAZUH_CACHENAME=${PORTNAME}-cache-fbsd13-${ARCH}-${DISTVERSION}
DISTFILES+=	${WAZUH_CACHENAME}${EXTRACT_SUFX}:wazuh_cache
.elif ${OSVERSION} >= 1400000 && ${OSVERSION} < 1500000
FBSD_VERSION_BASE=freebsd_14_3_release${FBSD14_PATCH_LEVEL}
FBSD_MAJOR_VERSION=14
WAZUH_CACHENAME=${PORTNAME}-cache-fbsd14-${ARCH}-${DISTVERSION}
DISTFILES+=	${WAZUH_CACHENAME}${EXTRACT_SUFX}:wazuh_cache
.elif ${OSVERSION} >= 1500000
FBSD_VERSION_BASE=freebsd_15_0_current
FBSD_MAJOR_VERSION=15
WAZUH_CACHENAME=${PORTNAME}-cache-fbsd15-${ARCH}-${DISTVERSION}
DISTFILES+=     ${WAZUH_CACHENAME}${EXTRACT_SUFX}:wazuh_cache
.else
IGNORE=		FreeBSD ${OSVERSION} ${ARCH} is not supported
.endif

post-extract:
.for FILE in ${EXTERNAL_DISTFILES}
.if ${FILE} == "http-request.tar.gz:wazuh_cache"
	@cd ${WRKSRC}/src/shared_modules && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${FILE:S/:wazuh_cache//} ${EXTRACT_AFTER_ARGS}
.else
	@cd ${WRKSRC}/src/external && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${FILE:S/:wazuh_sources//:S/:wazuh_cache//} ${EXTRACT_AFTER_ARGS}
.endif
.endfor
	@cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${WAZUH_EXTRAFILE} ${EXTRACT_AFTER_ARGS}
	@${MV} ${WRKDIR}/${PORTNAME}-freebsd-${WAZUH_EXTRAFILE_TAGNAME} ${WRKDIR}/wazuh-freebsd

	@cd ${WRKSRC}/src && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${WAZUH_CACHEFILE} ${EXTRACT_AFTER_ARGS}
	@cd ${WRKSRC}/src && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${WAZUH_CACHENAME}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}
	@cd ${WRKSRC}/src && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${PORTNAME}-python-${DISTVERSION}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}

.	for FILE in ${WZPYTHONWHEELS}
		@${MV} ${WRKSRC}/src/wazuh-cache/${FILE} ${WRKSRC}/src/wazuh-cache/${FILE:S/${FBSD_VERSION_BASE}/${FBSD_RELEASE}/}
.	endfor
	@${RM} ${WRKSRC}/src/external/cpython/python ${WRKSRC}/src/external/cpython/libpython* ${WRKSRC}/src/external/cpython/Modules/*.o

	@${MKDIR} ${WRKSRC}/ruleset/sca/freebsd
	@cd ${WRKDIR}/wazuh-freebsd/var/ossec/ruleset/sca && ${CP} *.yml ${WRKSRC}/ruleset/sca/freebsd/
	${FIND} ${WRKSRC}/ruleset/sca -type f -name "*.yml" -exec ${MV} "{}" "{}.disabled" \;

post-patch:
	${REINPLACE_CMD} -e 's|CC=|CC?=|g' -e 's|AR=|AR?=|g' ${WRKSRC}/src/external/bzip2/Makefile
	${REINPLACE_CMD} -e 's|^\( *MULTIARCH=\).*--print-multiarch.*|\1|' ${WRKSRC}/src/external/cpython/configure
	${REINPLACE_CMD} -e 's|coroutine|coroutines|g' ${WRKSRC}/framework/wazuh/core/cluster/client.py \
		${WRKSRC}/framework/wazuh/rbac/decorators.py

do-build:
	cd ${WRKSRC}/src/ && ${SETENV} ${MAKE_ENV} STAGEDIR=${STAGEDIR} \
		${MAKE_CMD} ${MAKE_ARGS}

do-install:
	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/bin
	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/lib
	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/tmp
	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/templates
	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/.ssh

.for DIRE in ${WAZUHMOD660}
	${MKDIR} -m 0660 ${STAGEDIR}${WAZUHPREFIX}${DIRE}
.endfor

.for DIRE in ${WAZUHMOD750}
	${MKDIR} -m 0750 ${STAGEDIR}${WAZUHPREFIX}${DIRE}
.endfor

.for DIRE in ${WAZUHMOD770}
	${MKDIR} -m 0770 ${STAGEDIR}${WAZUHPREFIX}${DIRE}
.endfor

	${INSTALL_DATA} /dev/null ${STAGEDIR}${WAZUHPREFIX}/logs/ossec.log
	${INSTALL_DATA} /dev/null ${STAGEDIR}${WAZUHPREFIX}/logs/ossec.json
	${INSTALL_DATA} /dev/null ${STAGEDIR}${WAZUHPREFIX}/logs/active-responses.log

.for FILE in ${WZBIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${FILE} ${STAGEDIR}${WAZUHPREFIX}/bin
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/src/syscheckd/build/bin/wazuh-syscheckd ${STAGEDIR}${WAZUHPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/init/wazuh-server.sh ${STAGEDIR}${WAZUHPREFIX}/bin/wazuh-control

	${TOUCH} ${STAGEDIR}${WAZUHPREFIX}/etc/localtime

	${INSTALL_DATA} ${WRKSRC}/etc/internal_options.conf ${STAGEDIR}${WAZUHPREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/src/wazuh_modules/syscollector/norm_config.json ${STAGEDIR}${WAZUHPREFIX}/queue/syscollector
	${INSTALL_DATA} ${WRKSRC}/etc/local_internal_options.conf ${STAGEDIR}${WAZUHPREFIX}/etc/local_internal_options.conf.sample

	${INSTALL_DATA} /dev/null ${STAGEDIR}${WAZUHPREFIX}/etc/client.keys.sample

	${INSTALL_DATA} ${WRKSRC}/etc/ossec-server.conf ${STAGEDIR}${WAZUHPREFIX}/etc/ossec.conf.sample

	${INSTALL_SCRIPT} ${WRKSRC}/src/agentlessd/scripts/* ${STAGEDIR}${WAZUHPREFIX}/agentless/

.for FILE in ${WZARBIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${FILE} ${STAGEDIR}${WAZUHPREFIX}/active-response/bin
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/src/active-response/*.sh ${STAGEDIR}${WAZUHPREFIX}/active-response/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/active-response/*.py ${STAGEDIR}${WAZUHPREFIX}/active-response/bin

	${INSTALL_PROGRAM} ${WRKSRC}/src/default-firewall-drop ${STAGEDIR}${WAZUHPREFIX}/active-response/bin/firewall-drop

# Install rules files
	${INSTALL_DATA} ${WRKSRC}/ruleset/rules/*.xml ${STAGEDIR}${WAZUHPREFIX}/ruleset/rules
	${INSTALL_DATA} ${WRKDIR}/wazuh-freebsd/var/ossec/ruleset/rules/*.xml ${STAGEDIR}${WAZUHPREFIX}/ruleset/rules

# Install decoders files
	${INSTALL_DATA} ${WRKSRC}/ruleset/decoders/*.xml ${STAGEDIR}${WAZUHPREFIX}/ruleset/decoders
	${INSTALL_DATA} ${WRKDIR}/wazuh-freebsd/var/ossec/ruleset/decoders/*.xml ${STAGEDIR}${WAZUHPREFIX}/ruleset/decoders

	${INSTALL_DATA} ${WRKSRC}/ruleset/rootcheck/db/*.txt ${STAGEDIR}${WAZUHPREFIX}/etc/rootcheck

	${INSTALL_DATA} ${WRKSRC}/etc/local_decoder.xml ${STAGEDIR}${WAZUHPREFIX}/etc/decoders/local_decoder.xml.sample
	${INSTALL_DATA} ${WRKSRC}/etc/local_rules.xml ${STAGEDIR}${WAZUHPREFIX}/etc/rules/local_rules.xml.sample

	${INSTALL_DATA} ${WRKSRC}/ruleset/lists/amazon/* ${STAGEDIR}${WAZUHPREFIX}/etc/lists/amazon/
	${INSTALL_DATA} ${WRKSRC}/ruleset/lists/audit-keys ${STAGEDIR}${WAZUHPREFIX}/etc/lists/audit-keys
	${INSTALL_DATA} ${WRKSRC}/ruleset/lists/security-eventchannel ${STAGEDIR}${WAZUHPREFIX}/etc/lists/security-eventchannel

	${INSTALL_SCRIPT} ${WRKSRC}/integrations/maltiverse.py ${STAGEDIR}${WAZUHPREFIX}/integrations/maltiverse.py
	${INSTALL_SCRIPT} ${WRKSRC}/integrations/pagerduty.py ${STAGEDIR}${WAZUHPREFIX}/integrations/pagerduty.py
	${INSTALL_SCRIPT} ${WRKSRC}/integrations/slack.py ${STAGEDIR}${WAZUHPREFIX}/integrations/slack.py
	${INSTALL_SCRIPT} ${WRKSRC}/integrations/shuffle.py ${STAGEDIR}${WAZUHPREFIX}/integrations/shuffle.py
	${INSTALL_SCRIPT} ${WRKSRC}/integrations/virustotal.py ${STAGEDIR}${WAZUHPREFIX}/integrations/virustotal.py

	${INSTALL_DATA} /dev/null ${STAGEDIR}${WAZUHPREFIX}/queue/agents-timestamp
	${INSTALL_DATA} ${WRKSRC}/ruleset/rootcheck/db/*.txt ${STAGEDIR}${WAZUHPREFIX}/etc/shared/default
	${INSTALL_DATA} ${WRKSRC}/etc/agent.conf ${STAGEDIR}${WAZUHPREFIX}/etc/shared/default/agent.conf.sample
	${INSTALL_DATA} ${WRKSRC}/etc/agent.conf ${STAGEDIR}${WAZUHPREFIX}/etc/shared/agent-template.conf

	${INSTALL_SCRIPT} ${WRKSRC}/wodles/__init__.py ${STAGEDIR}${WAZUHPREFIX}/wodles/__init__.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/utils.py ${STAGEDIR}${WAZUHPREFIX}/wodles/utils.py

	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/aws_s3.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/aws-s3.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/__init__.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/__init__.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/aws_tools.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/aws_tools.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/wazuh_integration.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/wazuh_integration.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/buckets_s3/aws_bucket.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/buckets_s3/aws_bucket.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/buckets_s3/cloudtrail.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/buckets_s3/cloudtrail.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/buckets_s3/config.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/buckets_s3/config.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/buckets_s3/guardduty.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/buckets_s3/guardduty.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/buckets_s3/__init__.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/buckets_s3/__init__.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/buckets_s3/load_balancers.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/buckets_s3/load_balancers.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/buckets_s3/server_access.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/buckets_s3/server_access.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/buckets_s3/umbrella.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/buckets_s3/umbrella.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/buckets_s3/vpcflow.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/buckets_s3/vpcflow.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/buckets_s3/waf.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/buckets_s3/waf.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/services/aws_service.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/services/aws_service.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/services/cloudwatchlogs.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/services/cloudwatchlogs.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/services/__init__.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/services/__init__.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/services/inspector.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/services/inspector.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/subscribers/__init__.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/subscribers/__init__.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/subscribers/sqs_queue.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/subscribers/sqs_queue.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/subscribers/s3_log_handler.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/subscribers/s3_log_handler.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/subscribers/sqs_message_processor.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/subscribers/sqs_message_processor.py

	${INSTALL_SCRIPT} ${WRKSRC}/framework/wrappers/generic_wrapper.sh ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/aws-s3

	${INSTALL_SCRIPT} ${WRKSRC}/wodles/gcloud/exceptions.py ${STAGEDIR}${WAZUHPREFIX}/wodles/gcloud/exceptions.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/gcloud/gcloud.py ${STAGEDIR}${WAZUHPREFIX}/wodles/gcloud/gcloud.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/gcloud/integration.py ${STAGEDIR}${WAZUHPREFIX}/wodles/gcloud/integration.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/gcloud/tools.py ${STAGEDIR}${WAZUHPREFIX}/wodles/gcloud/tools.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/gcloud/buckets/bucket.py ${STAGEDIR}${WAZUHPREFIX}/wodles/gcloud/buckets/bucket.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/gcloud/buckets/access_logs.py ${STAGEDIR}${WAZUHPREFIX}/wodles/gcloud/buckets/access_logs.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/gcloud/pubsub/subscriber.py ${STAGEDIR}${WAZUHPREFIX}/wodles/gcloud/pubsub/subscriber.py
	${INSTALL_SCRIPT} ${WRKSRC}/framework/wrappers/generic_wrapper.sh ${STAGEDIR}${WAZUHPREFIX}/wodles/gcloud/gcloud

	${INSTALL_SCRIPT} ${WRKSRC}/wodles/docker-listener/DockerListener.py ${STAGEDIR}${WAZUHPREFIX}/wodles/docker/DockerListener.py
	${INSTALL_SCRIPT} ${WRKSRC}/framework/wrappers/generic_wrapper.sh ${STAGEDIR}${WAZUHPREFIX}/wodles/docker/DockerListener

	${INSTALL_SCRIPT} ${WRKSRC}/wodles/azure/azure-logs.py ${STAGEDIR}${WAZUHPREFIX}/wodles/azure/azure-logs.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/azure/azure_utils.py ${STAGEDIR}${WAZUHPREFIX}/wodles/azure/azure_utils.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/azure/azure_services/__init__.py ${STAGEDIR}${WAZUHPREFIX}/wodles/azure/azure_services/__init__.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/azure/azure_services/analytics.py ${STAGEDIR}${WAZUHPREFIX}/wodles/azure/azure_services/analytics.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/azure/azure_services/graph.py ${STAGEDIR}${WAZUHPREFIX}/wodles/azure/azure_services/graph.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/azure/azure_services/storage.py ${STAGEDIR}${WAZUHPREFIX}/wodles/azure/azure_services/storage.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/azure/db/__init__.py ${STAGEDIR}${WAZUHPREFIX}/wodles/azure/db/__init__.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/azure/db/orm.py ${STAGEDIR}${WAZUHPREFIX}/wodles/azure/db/orm.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/azure/db/utils.py ${STAGEDIR}${WAZUHPREFIX}/wodles/azure/db/utils.py
	${INSTALL_SCRIPT} ${WRKSRC}/framework/wrappers/generic_wrapper.sh ${STAGEDIR}${WAZUHPREFIX}/wodles/azure/azure-logs

	${INSTALL_SCRIPT} ${WRKSRC}/framework/wrappers/generic_wrapper.sh ${STAGEDIR}${WAZUHPREFIX}/integrations/maltiverse
	${INSTALL_SCRIPT} ${WRKSRC}/framework/wrappers/generic_wrapper.sh ${STAGEDIR}${WAZUHPREFIX}/integrations/pagerduty
	${INSTALL_SCRIPT} ${WRKSRC}/framework/wrappers/generic_wrapper.sh ${STAGEDIR}${WAZUHPREFIX}/integrations/slack
	${INSTALL_SCRIPT} ${WRKSRC}/framework/wrappers/generic_wrapper.sh ${STAGEDIR}${WAZUHPREFIX}/integrations/virustotal
	${INSTALL_SCRIPT} ${WRKSRC}/framework/wrappers/generic_wrapper.sh ${STAGEDIR}${WAZUHPREFIX}/integrations/shuffle

# Install SCA files
	${FIND} ${WRKSRC}/ruleset/sca -type f -name "*.yml.disabled" -exec ${INSTALL_DATA} "{}" ${STAGEDIR}${WAZUHPREFIX}/ruleset/sca/ \;

	${INSTALL_LIB} ${WRKSRC}/src/libwazuhext.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/libwazuhshared.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/build/shared_modules/content_manager/libcontent_manager.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/build/shared_modules/indexer_connector/libindexer_connector.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/build/shared_modules/router/librouter.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/build/wazuh_modules/vulnerability_scanner/libvulnerability_scanner.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/data_provider/build/lib/libsysinfo.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/external/jemalloc/lib/libjemalloc.so.2 ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/external/rocksdb/build/librocksdb.so.8.3.2 ${STAGEDIR}${WAZUHPREFIX}/lib/librocksdb.so.8
	${INSTALL_LIB} ${WRKSRC}/src/shared_modules/dbsync/build/lib/libdbsync.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/shared_modules/rsync/build/lib/librsync.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/syscheckd/build/lib/libfimdb.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/wazuh_modules/syscollector/build/lib/libsyscollector.so ${STAGEDIR}${WAZUHPREFIX}/lib

	${INSTALL_DATA} ${WRKSRC}/src/wazuh_modules/vulnerability_scanner/indexer/template/index-template.json ${STAGEDIR}${WAZUHPREFIX}/templates/vd_states_template.json

	${INSTALL_DATA} ${WRKSRC}/VERSION.json ${STAGEDIR}${WAZUHPREFIX}

	cd ${WRKSRC}/src/ && ${SETENV} ${MAKE_ENV} STAGEDIR=${STAGEDIR} \
		${MAKE_CMD} install_python ${MAKE_ARGS}
	cd ${WRKSRC}/src/ && ${SETENV} ${MAKE_ENV} STAGEDIR=${STAGEDIR} \
		${MAKE_CMD} install_dependencies ${MAKE_ARGS}
	cd ${WRKSRC}/src/ && ${SETENV} ${MAKE_ENV} STAGEDIR=${STAGEDIR} \
		${MAKE_CMD} install_framework ${MAKE_ARGS}
	cd ${WRKSRC}/src/ && ${SETENV} ${MAKE_ENV} STAGEDIR=${STAGEDIR} \
		${MAKE_CMD} install_api ${MAKE_ARGS}
	cd ${WRKSRC}/src/ && ${SETENV} ${MAKE_ENV} STAGEDIR=${STAGEDIR} \
		${MAKE_CMD} install_mitre ${MAKE_ARGS}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} --quiet -C framework install INSTALLDIR=${STAGEDIR}${WAZUHPREFIX}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} --quiet -C api install INSTALLDIR=${STAGEDIR}${WAZUHPREFIX}

	@cd ${STAGEDIR}${WAZUHPREFIX}/framework/python/lib && \
		${STAGEDIR}${WAZUHPREFIX}/framework/python/bin/python3 -m compileall -x 'bad_coding|badsyntax|lib2to3/tests/data' -f -p ${WAZUHPREFIX}/framework/python/lib/ "${PYTHON_VERSION}"
	@cd ${STAGEDIR}${WAZUHPREFIX}/framework/python/lib && \
		${STAGEDIR}${WAZUHPREFIX}/framework/python/bin/python3 -O -m compileall -x 'bad_coding|badsyntax|lib2to3/tests/data' -f -p ${WAZUHPREFIX}/framework/python/lib/ "${PYTHON_VERSION}"
	@cd ${STAGEDIR}${WAZUHPREFIX}/framework/python/lib && \
		${STAGEDIR}${WAZUHPREFIX}/framework/python/bin/python3 -OO -m compileall -x 'bad_coding|badsyntax|lib2to3/tests/data' -f -p ${WAZUHPREFIX}/framework/python/lib/ "${PYTHON_VERSION}"

	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/etc/templates
	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/databases
	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/src

	cd ${WRKSRC}/etc/templates && ${COPYTREE_SHARE} config \
		${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/etc/templates/
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} init \
		${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/src/
	cd ${WRKSRC}/ruleset && ${COPYTREE_SHARE} sca \
		${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/

	${INSTALL_SCRIPT} ${WRKSRC}/gen_ossec.sh ${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/
	${INSTALL_SCRIPT} ${WRKSRC}/add_localfiles.sh ${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/
	${INSTALL_DATA} ${WRKSRC}/src/os_dbd/mysql.schema ${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/databases
	${INSTALL_DATA} ${WRKSRC}/src/os_dbd/postgresql.schema ${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/databases

	@${FIND} ${STAGEDIR}${WAZUHPREFIX}/framework/python/lib/${PYTHON_VERSION}/site-packages/numpy/distutils/ -type f -name "*.bak" -delete -o -name "*.orig" -delete
	@${RM} ${STAGEDIR}${WAZUHPREFIX}/framework/python/lib/${PYTHON_VERSION}/site-packages/numpy/f2py/tests/src/temp
	@${RM} ${STAGEDIR}${WAZUHPREFIX}/framework/python/lib/${PYTHON_VERSION}/site-packages/numpy/core/tests/examples/temp

post-install:
	@${STRIP_CMD} ${STAGEDIR}${WAZUHPREFIX}/framework/python/bin/${PYTHON_VERSION}
	@${FIND} ${STAGEDIR}${WAZUHPREFIX}/framework -type f -name "*.so" -exec ${STRIP_CMD} "{}" \;
.for FILE in ${WZSHEBANG_FILES}
	@${REINPLACE_CMD} -i "" -e 's|${STAGEDIR}||g' ${STAGEDIR}${WAZUHPREFIX}/framework/python/bin/${FILE}
.endfor

.include <bsd.port.post.mk>
