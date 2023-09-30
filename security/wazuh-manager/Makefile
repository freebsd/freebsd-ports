PORTNAME=	wazuh
DISTVERSIONPREFIX=	v
DISTVERSION=	4.7.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://packages.wazuh.com/deps/23/libraries/sources/:wazuh_sources \
		LOCAL/acm/${PORTNAME}/:wazuh_cache
PKGNAMESUFFIX=	-manager
DISTFILES=	${EXTERNAL_DISTFILES} \
		${PORTNAME}-cache-any-${DISTVERSION}${EXTRACT_SUFX}:wazuh_cache
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Security tool to monitor and check logs and intrusions (manager)
WWW=		https://wazuh.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64

BUILD_DEPENDS=	cmake:devel/cmake-core \
		autoconf>=2.71:devel/autoconf
LIB_DEPENDS+=	libgdbm.so:databases/gdbm \
		libnghttp2.so:www/libnghttp2

USES=		cpe gmake perl5 python:3.9 readline shebangfix sqlite:3 uidfix

USE_GITHUB=	yes

USE_RC_SUBR=	${PORTNAME}${PKGNAMESUFFIX}

MAKE_ARGS+=	TARGET=server INSTALLDIR=${WAZUHPREFIX} INSTALL_SHARED="${INSTALL_LIB}" PYTHON_SOURCE=yes OPTIMIZE_CPYTHON=no

WAZUH_CACHEFILE=	${PORTNAME}-cache-any-${DISTVERSION}${EXTRACT_SUFX}
EXTERNAL_DISTFILES=	cJSON.tar.gz:wazuh_sources \
			curl.tar.gz:wazuh_sources \
			jemalloc.tar.gz:wazuh_sources \
			libdb.tar.gz:wazuh_sources \
			libffi.tar.gz:wazuh_sources \
			libyaml.tar.gz:wazuh_sources \
			openssl.tar.gz:wazuh_sources \
			procps.tar.gz:wazuh_sources \
			sqlite.tar.gz:wazuh_sources \
			zlib.tar.gz:wazuh_sources \
			audit-userspace.tar.gz:wazuh_sources \
			msgpack.tar.gz:wazuh_sources \
			bzip2.tar.gz:wazuh_sources \
			nlohmann.tar.gz:wazuh_sources \
			googletest.tar.gz:wazuh_sources \
			libpcre2.tar.gz:wazuh_sources \
			libplist.tar.gz:wazuh_sources	\
			libarchive.tar.gz:wazuh_sources \
			popt.tar.gz:wazuh_sources \
			cpython.tar.gz:wazuh_sources

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

WZBIN_FILES=	wazuh-logcollector wazuh-execd  manage_agents wazuh-modulesd \
		wazuh-agentlessd wazuh-analysisd wazuh-monitord wazuh-reportd wazuh-maild \
		wazuh-logtest-legacy wazuh-csyslogd wazuh-dbd verify-agent-conf clear_stats \
		wazuh-regex agent_control wazuh-integratord wazuh-db wazuh-remoted wazuh-authd

WZARBIN_FILES=	default-firewall-drop pf npf ipfw firewalld-drop disable-account \
		host-deny ip-customblock restart-wazuh route-null kaspersky wazuh-slack

WZSHEBANG_FILES=chardetect connexion cygdb cython cythonize f2py3.9 f2py3 f2py fixup_pubsub_v1_keywords.py \
		flask futurize jp.py jsonschema normalizer openapi-spec-validator pasteurize \
		pyrsa-decrypt pyrsa-encrypt pyrsa-keygen pyrsa-priv2pub pyrsa-sign \
		pyrsa-verify rstpep2html.py rst2s5.py rst2xetex.py rst2man.py rst2odt.py \
		rst2latex.py rst2pseudoxml.py rst2odt_prepstyles.py rst2html.py rst2html5.py \
		rst2html4.py rst2xml.py tabulate wsdump.py

WAZUHMOD750=	/ /logs/wazuh /logs/archives /logs/alerts /logs/firewall \
		/logs/api /logs/cluster /bin /lib /queue /queue/agentless \
		/queue/db /queue/diff /queue/fts /queue/logcollector \
		/queue/syscollector /queue/syscollector/db  /ruleset \
		/ruleset/decoders /ruleset/rules /ruleset/sca /wodles \
		/active-response /active-response/bin /agentless /var /backup \
		/backup/db /backup/agents /backup/groups /backup/shared /queue/rids \
		/wodles/aws /wodles/azure /wodles/docker /wodles/gcloud \
		/wodles/gcloud/buckets /wodles/gcloud/pubsub /wodles/oscap \
		/wodles/oscap/content /stats /integrations

WAZUHMOD770=	/etc/decoders /etc/lists /etc/lists/amazon /etc/rootcheck \
		/etc/rules /etc/shared/default /logs /queue/agent-groups \
		/queue/alerts /queue/cluster /queue/fim /queue/fim/db \
		/queue/rids /queue/sockets /queue/tasks /etc /etc/shared \
		/.ssh /var/db /var/download /var/db/agents /var/run /var/upgrade \
		/var/selinux /var/wodles /var/incoming /var/multigroups  \

WAZUHPREFIX=	/var/ossec

WZPYTHONWHEELS=	aiohttp-3.8.1-cp39-cp39-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		cffi-1.14.4-cp39-cp39-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		cryptography-3.3.2-cp39-cp39-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		frozenlist-1.2.0-cp39-cp39-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		grpcio-1.38.1-cp39-cp39-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		hiredis-1.1.0-cp39-cp39-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		MarkupSafe-2.1.2-cp39-cp39-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		multidict-5.1.0-cp39-cp39-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		numpy-1.21.6-cp39-cp39-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		psutil-5.8.0-cp39-cp39-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		pyarrow-13.0.0-cp39-cp39-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		PyYAML-6.0.1-cp39-cp39-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		SQLAlchemy-1.3.11-cp39-cp39-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		uvloop-0.15.2-cp39-cp39-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl \
		yarl-1.6.3-cp39-cp39-${FBSD_VERSION_BASE}_${ARCH_BASE}.whl

ARCH_BASE=	${ARCH:S/aarch64/arm64/g}
UNAME_r=	${_OSRELEASE:tl}
FBSD_RELEASE=	freebsd_${UNAME_r:S/./_/g:S/-/_/g}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1300139 && ${OSVERSION} < 1400000
FBSD_VERSION_BASE=freebsd_13_2_release_p4
WAZUH_CACHENAME=${PORTNAME}-cache-fbsd13-${ARCH}-${DISTVERSION}
DISTFILES+=	${WAZUH_CACHENAME}${EXTRACT_SUFX}:wazuh_cache
.elif ${OSVERSION} >= 1400000 && ${OSVERSION} < 1500000
FBSD_VERSION_BASE=freebsd_14_0_release_p3
WAZUH_CACHENAME=${PORTNAME}-cache-fbsd14-${ARCH}-${DISTVERSION}
DISTFILES+=	${WAZUH_CACHENAME}${EXTRACT_SUFX}:wazuh_cache
.elif ${OSVERSION} >= 1500000
FBSD_VERSION_BASE=freebsd_15_0_current
WAZUH_CACHENAME=${PORTNAME}-cache-fbsd15-${ARCH}-${DISTVERSION}
DISTFILES+=     ${WAZUH_CACHENAME}${EXTRACT_SUFX}:wazuh_cache
.else
IGNORE=		FreeBSD ${OSVERSION} ${ARCH} is not supported
.endif

post-extract:
.for FILE in ${EXTERNAL_DISTFILES}
	@cd ${WRKSRC}/src/external && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${FILE:S/:wazuh_sources//} ${EXTRACT_AFTER_ARGS}
.endfor
	@cd ${WRKSRC}/src && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${WAZUH_CACHEFILE} ${EXTRACT_AFTER_ARGS}
	@cd ${WRKSRC}/src && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${WAZUH_CACHENAME}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}
.	for FILE in ${WZPYTHONWHEELS}
		@${MV} ${WRKSRC}/src/wazuh-cache/${FILE} ${WRKSRC}/src/wazuh-cache/${FILE:S/${FBSD_VERSION_BASE}/${FBSD_RELEASE}/}
.	endfor
	@${RM} ${WRKSRC}/src/external/cpython/python
	${FIND} ${WRKSRC}/ruleset/sca -type f -name "*.yml" -exec ${MV} "{}" "{}.disabled" \;

post-patch:
	${REINPLACE_CMD} -e 's|HOST_NAME_MAX|_POSIX_HOST_NAME_MAX|g' ${WRKSRC}/src/wazuh_modules/wm_database.c
	${REINPLACE_CMD} -e 's|CC=|CC?=|g' -e 's|AR=|AR?=|g' ${WRKSRC}/src/external/bzip2/Makefile
	${REINPLACE_CMD} -e 's|^\( *MULTIARCH=\).*--print-multiarch.*|\1|' ${WRKSRC}/src/external/cpython/configure

do-build:
	cd ${WRKSRC}/src/ && ${SETENV} ${MAKE_ENV} STAGEDIR=${STAGEDIR} \
		${MAKE_CMD} ${MAKE_ARGS}

do-install:
	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/bin
	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/lib
	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/tmp
	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/.ssh

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

	${INSTALL_DATA} ${WRKSRC}/ruleset/rules/*.xml ${STAGEDIR}${WAZUHPREFIX}/ruleset/rules

	${INSTALL_DATA} ${WRKSRC}/ruleset/decoders/*.xml ${STAGEDIR}${WAZUHPREFIX}/ruleset/decoders
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

	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/queue/vulnerabilities/dictionaries
	${INSTALL_DATA} ${WRKSRC}/src/wazuh_modules/vulnerability_detector/cpe_helper.json ${STAGEDIR}${WAZUHPREFIX}/queue/vulnerabilities/dictionaries

	${INSTALL_DATA} /dev/null ${STAGEDIR}${WAZUHPREFIX}/queue/agents-timestamp
	${INSTALL_DATA} ${WRKSRC}/ruleset/rootcheck/db/*.txt ${STAGEDIR}${WAZUHPREFIX}/etc/shared/default
	${INSTALL_DATA} ${WRKSRC}/etc/agent.conf ${STAGEDIR}${WAZUHPREFIX}/etc/shared/default/agent.conf.sample
	${INSTALL_DATA} ${WRKSRC}/etc/agent.conf ${STAGEDIR}${WAZUHPREFIX}/etc/shared/agent-template.conf

	${INSTALL_SCRIPT} ${WRKSRC}/wodles/__init__.py ${STAGEDIR}${WAZUHPREFIX}/wodles/__init__.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/utils.py ${STAGEDIR}${WAZUHPREFIX}/wodles/utils.py

	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/aws_s3.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/aws-s3.py
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
	${INSTALL_SCRIPT} ${WRKSRC}/framework/wrappers/generic_wrapper.sh ${STAGEDIR}${WAZUHPREFIX}/wodles/azure/azure-logs
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/azure/orm.py ${STAGEDIR}${WAZUHPREFIX}/wodles/azure/orm.py

	${INSTALL_SCRIPT} ${WRKSRC}/framework/wrappers/generic_wrapper.sh ${STAGEDIR}${WAZUHPREFIX}/integrations/maltiverse
	${INSTALL_SCRIPT} ${WRKSRC}/framework/wrappers/generic_wrapper.sh ${STAGEDIR}${WAZUHPREFIX}/integrations/pagerduty
	${INSTALL_SCRIPT} ${WRKSRC}/framework/wrappers/generic_wrapper.sh ${STAGEDIR}${WAZUHPREFIX}/integrations/slack
	${INSTALL_SCRIPT} ${WRKSRC}/framework/wrappers/generic_wrapper.sh ${STAGEDIR}${WAZUHPREFIX}/integrations/virustotal
	${INSTALL_SCRIPT} ${WRKSRC}/framework/wrappers/generic_wrapper.sh ${STAGEDIR}${WAZUHPREFIX}/integrations/shuffle

	${FIND} ${WRKSRC}/ruleset/sca -type f -name "*.yml.disabled" -exec ${INSTALL_DATA} "{}" ${STAGEDIR}${WAZUHPREFIX}/ruleset/sca/ \;

	${INSTALL_LIB} ${WRKSRC}/src/libwazuhext.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/libwazuhshared.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/shared_modules/dbsync/build/lib/libdbsync.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/shared_modules/rsync/build/lib/librsync.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/syscheckd/build/lib/libfimdb.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/wazuh_modules/syscollector/build/lib/libsyscollector.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/data_provider/build/lib/libsysinfo.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/external/jemalloc/lib/libjemalloc.so.2 ${STAGEDIR}${WAZUHPREFIX}/lib

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
		${STAGEDIR}${WAZUHPREFIX}/framework/python/bin/python3 -m compileall -x 'bad_coding|badsyntax|lib2to3/tests/data' -f -p ${WAZUHPREFIX}/framework/python/lib/ "python3.9"
	@cd ${STAGEDIR}${WAZUHPREFIX}/framework/python/lib && \
		${STAGEDIR}${WAZUHPREFIX}/framework/python/bin/python3 -O -m compileall -x 'bad_coding|badsyntax|lib2to3/tests/data' -f -p ${WAZUHPREFIX}/framework/python/lib/ "python3.9"
	@cd ${STAGEDIR}${WAZUHPREFIX}/framework/python/lib && \
		${STAGEDIR}${WAZUHPREFIX}/framework/python/bin/python3 -OO -m compileall -x 'bad_coding|badsyntax|lib2to3/tests/data' -f -p ${WAZUHPREFIX}/framework/python/lib/ "python3.9"

	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/etc/templates
	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/databases
	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/src

	cd ${WRKSRC}/etc/templates && ${COPYTREE_SHARE} config \
		${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/etc/templates/
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} init \
		${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/src/

	${INSTALL_SCRIPT} ${WRKSRC}/gen_ossec.sh ${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/
	${INSTALL_SCRIPT} ${WRKSRC}/add_localfiles.sh ${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/
	${INSTALL_DATA} ${WRKSRC}/src/os_dbd/mysql.schema ${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/databases
	${INSTALL_DATA} ${WRKSRC}/src/os_dbd/postgresql.schema ${STAGEDIR}${WAZUHPREFIX}/packages_files/manager_installation_scripts/databases

post-install:
.for FILE in ${WZSHEBANG_FILES}
	@${REINPLACE_CMD} -i "" -e 's|${STAGEDIR}||g' ${STAGEDIR}${WAZUHPREFIX}/framework/python/bin/${FILE}
.endfor

.include <bsd.port.post.mk>
