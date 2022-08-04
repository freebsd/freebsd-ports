PORTNAME=	wazuh
DISTVERSION=	4.3.6
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	security
MASTER_SITES=	https://packages.wazuh.com/deps/16/libraries/sources/:wazuh_sources \
		LOCAL/acm/${PORTNAME}/:wazuh_cache
PKGNAMESUFFIX=	-manager
DISTFILES=	${EXTERNAL_DISTFILES} \
		${PORTNAME}-cache-any${EXTRACT_SUFX}:wazuh_cache
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Security tool to monitor and check logs and intrusions (manager)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake
LIB_DEPENDS+=	libgdbm.so:databases/gdbm \
		libnghttp2.so:www/libnghttp2

USES=		cpe gmake perl5 python:3.9 readline shebangfix sqlite:3 uidfix

USE_GITHUB=	yes
USE_RC_SUBR=	${PORTNAME}${PKGNAMESUFFIX}

MAKE_ARGS+=	TARGET=server INSTALLDIR=${WAZUHPREFIX} INSTALL_SHARED="${INSTALL_LIB}" PYTHON_SOURCE=yes

WAZUH_CACHEFILE=	${PORTNAME}-cache-any${EXTRACT_SUFX}
EXTERNAL_DISTFILES=	cJSON.tar.gz:wazuh_sources \
			curl.tar.gz:wazuh_sources \
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

WZBIN_FILES=	wazuh-logcollector wazuh-syscheckd wazuh-execd  manage_agents wazuh-modulesd \
		wazuh-agentlessd wazuh-analysisd wazuh-monitord wazuh-reportd wazuh-maild \
		wazuh-logtest-legacy wazuh-csyslogd wazuh-dbd verify-agent-conf clear_stats \
		wazuh-regex agent_control wazuh-integratord wazuh-db wazuh-remoted wazuh-authd

WZARBIN_FILES=	default-firewall-drop pf npf ipfw firewalld-drop disable-account \
		host-deny ip-customblock restart-wazuh route-null kaspersky wazuh-slack

WZSHEBANG_FILES=fixup_pubsub_v1_keywords.py pasteurize rst2xetex.py connexion rst2man.py rst2odt.py \
		pyrsa-priv2pub pyrsa-encrypt cygdb pyrsa-sign rstpep2html.py rst2s5.py rst2latex.py \
		chardetect futurize cython rst2pseudoxml.py pyrsa-keygen wsdump.py rst2odt_prepstyles.py \
		jp.py cythonize pyrsa-verify normalizer rst2html.py rst2html5.py openapi-spec-validator \
		rst2html4.py jsonschema rst2xml.py tabulate flask pyrsa-decrypt

WAZUHMOD750=	/ /logs/wazuh /logs/archives /logs/alerts /logs/firewall \
		/logs/api /logs/cluster /bin /lib /queue /queue/agentless \
		/queue/db /queue/diff /queue/fts /queue/logcollector \
		/queue/syscollector /queue/syscollector/db  /ruleset \
		/ruleset/decoders /ruleset/rules /ruleset/sca /wodles \
		/active-response /active-response/bin /agentless /var /backup \
		/backup/agents /backup/groups /backup/shared /queue/rids \
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

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1200500 && ${OSVERSION} < 1300000
WAZUH_CACHENAME=${PORTNAME}-cache-fbsd12-${ARCH}
DISTFILES+=	${WAZUH_CACHENAME}${EXTRACT_SUFX}:wazuh_cache
.elif ${OSVERSION} >= 1300139 && ${OSVERSION} < 1400000
WAZUH_CACHENAME=${PORTNAME}-cache-fbsd13-${ARCH}
DISTFILES+=	${WAZUH_CACHENAME}${EXTRACT_SUFX}:wazuh_cache
.endif

post-extract:
.for FILE in ${EXTERNAL_DISTFILES}
	@cd ${WRKSRC}/src/external && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${FILE:S/:wazuh_sources//} ${EXTRACT_AFTER_ARGS}
.endfor
	@cd ${WRKSRC}/src && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${WAZUH_CACHEFILE} ${EXTRACT_AFTER_ARGS}
	@cd ${WRKSRC}/src && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${WAZUH_CACHENAME}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS}
	@${RM} ${WRKSRC}/src/external/cpython/python

post-patch:
	${REINPLACE_CMD} -e 's|HOST_NAME_MAX|_POSIX_HOST_NAME_MAX|g' ${WRKSRC}/src/wazuh_modules/wm_database.c
	${REINPLACE_CMD} -e 's|CC=|CC?=|g' -e 's|AR=|AR?=|g' ${WRKSRC}/src/external/bzip2/Makefile
	${REINPLACE_CMD} '115d' ${WRKSRC}/src/wazuh_modules/syscollector/CMakeLists.txt
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
	${INSTALL_SCRIPT} ${WRKSRC}/src/init/wazuh-server.sh ${STAGEDIR}${WAZUHPREFIX}/bin/wazuh-control

	${TOUCH} ${STAGEDIR}${WAZUHPREFIX}/etc/localtime

	${INSTALL_DATA} ${WRKSRC}/etc/internal_options.conf ${STAGEDIR}${WAZUHPREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/src/wazuh_modules/syscollector/norm_config.json ${STAGEDIR}${WAZUHPREFIX}/queue/syscollector
	${INSTALL_DATA} ${WRKSRC}/etc/local_internal_options.conf ${STAGEDIR}${WAZUHPREFIX}/etc/local_internal_options.conf

	${INSTALL_DATA} /dev/null ${STAGEDIR}${WAZUHPREFIX}/etc/client.keys

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

	${INSTALL_DATA} ${WRKSRC}/etc/local_decoder.xml ${STAGEDIR}${WAZUHPREFIX}/etc/decoders/local_decoder.xml
	${INSTALL_DATA} ${WRKSRC}/etc/local_rules.xml ${STAGEDIR}${WAZUHPREFIX}/etc/rules/local_rules.xml

	${INSTALL_DATA} ${WRKSRC}/ruleset/lists/amazon/* ${STAGEDIR}${WAZUHPREFIX}/etc/lists/amazon/
	${INSTALL_DATA} ${WRKSRC}/ruleset/lists/audit-keys ${STAGEDIR}${WAZUHPREFIX}/etc/lists/audit-keys
	${INSTALL_DATA} ${WRKSRC}/ruleset/lists/security-eventchannel ${STAGEDIR}${WAZUHPREFIX}/etc/lists/security-eventchannel

	${INSTALL_SCRIPT} ${WRKSRC}/integrations/pagerduty ${STAGEDIR}${WAZUHPREFIX}/integrations/pagerduty
	${INSTALL_SCRIPT} ${WRKSRC}/integrations/slack ${STAGEDIR}${WAZUHPREFIX}/integrations/slack.py
	${INSTALL_SCRIPT} ${WRKSRC}/integrations/virustotal ${STAGEDIR}${WAZUHPREFIX}/integrations/virustotal.py

	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/queue/vulnerabilities/dictionaries
	${INSTALL_DATA} ${WRKSRC}/src/wazuh_modules/vulnerability_detector/cpe_helper.json ${STAGEDIR}${WAZUHPREFIX}/queue/vulnerabilities/dictionaries

	${INSTALL_DATA} /dev/null ${STAGEDIR}${WAZUHPREFIX}/queue/agents-timestamp
	${INSTALL_DATA} ${WRKSRC}/ruleset/rootcheck/db/*.txt ${STAGEDIR}${WAZUHPREFIX}/etc/shared/default
	${INSTALL_DATA} ${WRKSRC}/etc/agent.conf ${STAGEDIR}${WAZUHPREFIX}/etc/shared/default
	${INSTALL_DATA} ${WRKSRC}/etc/agent.conf ${STAGEDIR}${WAZUHPREFIX}/etc/shared/agent-template.conf

	${INSTALL_SCRIPT} ${WRKSRC}/wodles/__init__.py ${STAGEDIR}${WAZUHPREFIX}/wodles/__init__.py
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/utils.py ${STAGEDIR}${WAZUHPREFIX}/wodles/utils.py

	${INSTALL_SCRIPT} ${WRKSRC}/wodles/aws/aws_s3.py ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/aws-s3.py
	${INSTALL_SCRIPT} ${WRKSRC}/framework/wrappers/generic_wrapper.sh ${STAGEDIR}${WAZUHPREFIX}/wodles/aws/aws-s3

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

	${INSTALL_SCRIPT} ${WRKSRC}/framework/wrappers/generic_wrapper.sh ${STAGEDIR}${WAZUHPREFIX}/integrations/slack
	${INSTALL_SCRIPT} ${WRKSRC}/framework/wrappers/generic_wrapper.sh ${STAGEDIR}${WAZUHPREFIX}/integrations/virustotal

	${FIND} ${WRKSRC}/ruleset/sca -type f -name "*.yml" -exec ${INSTALL_DATA} "{}" ${STAGEDIR}${WAZUHPREFIX}/ruleset/sca \;

	${INSTALL_LIB} ${WRKSRC}/src/libwazuhext.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/libwazuhshared.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/shared_modules/dbsync/build/lib/libdbsync.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/shared_modules/rsync/build/lib/librsync.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/wazuh_modules/syscollector/build/lib/libsyscollector.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/data_provider/build/lib/libsysinfo.so ${STAGEDIR}${WAZUHPREFIX}/lib

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
