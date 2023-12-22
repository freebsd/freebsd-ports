PORTNAME=	wazuh
DISTVERSION=	4.7.1
DISTVERSIONPREFIX=	v
CATEGORIES=	security
MASTER_SITES=	https://packages.wazuh.com/deps/23/libraries/sources/:wazuh_sources
PKGNAMESUFFIX=	-agent
DISTFILES=	${EXTERNAL_DISTFILES}
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Security tool to monitor and check logs and intrusions (agent)
WWW=		https://github.com/wazuh/wazuh

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core
LIB_DEPENDS=	libnghttp2.so:www/libnghttp2

USES=		cpe gmake perl5 readline shebangfix sqlite:3 uidfix

USE_GITHUB=	yes
USE_RC_SUBR=	${PORTNAME}${PKGNAMESUFFIX}

MAKE_ARGS+=	TARGET=agent

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
			popt.tar.gz:wazuh_sources

OPTIONS_DEFAULT=	INOTIFY
OPTIONS_DEFINE=		INOTIFY PRELUDE ZEROMQ

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

WAZUH_USER=	wazuh
WAZUH_GROUP=	wazuh
USERS=		${WAZUH_USER}
GROUPS=		${WAZUH_GROUP}

CONFLICTS=	ossec-* wazuh-manager
SUB_FILES=	pkg-message

WZBIN_FILES=	agent-auth manage_agents wazuh-agentd wazuh-execd wazuh-logcollector \
		wazuh-modulesd

WZARBIN_FILES=	default-firewall-drop pf npf ipfw firewalld-drop disable-account \
		host-deny ip-customblock restart-wazuh route-null kaspersky wazuh-slack

WAZUHMOD750=	/ /logs/wazuh /bin /lib /queue /queue/diff /queue/logcollector \
		/queue/syscollector /queue/syscollector/db  /ruleset /ruleset/sca /wodles \
		/active-response /active-response/bin /agentless /var /backup \
		/wodles/aws /wodles/azure /wodles/docker /wodles/gcloud \
		/wodles/gcloud/buckets /wodles/gcloud/pubsub

WAZUHMOD770=	/etc/shared/default /logs /queue/alerts /queue/fim \
		/queue/fim/db /queue/rids /queue/sockets /etc /etc/shared \
		/var/run /var/upgrade /var/selinux /var/wodles /var/incoming

WAZUHPREFIX=	/var/ossec

.include <bsd.port.pre.mk>

post-extract:
.for FILE in ${EXTERNAL_DISTFILES}
	@cd ${WRKSRC}/src/external && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${FILE:S/:wazuh_sources//} ${EXTRACT_AFTER_ARGS}
.endfor

post-patch:
	${REINPLACE_CMD} -e 's|HOST_NAME_MAX|_POSIX_HOST_NAME_MAX|g' ${WRKSRC}/src/wazuh_modules/wm_database.c
	${REINPLACE_CMD} -e 's|CC=|CC?=|g' -e 's|AR=|AR?=|g' ${WRKSRC}/src/external/bzip2/Makefile

do-build:
	cd ${WRKSRC}/src/ && ${SETENV} ${MAKE_ENV} STAGEDIR=${STAGEDIR} \
		${MAKE_CMD} ${MAKE_ARGS}

do-install:
	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/bin
	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/lib
	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/tmp

.for DIRE in ${WAZUHMOD750}
	${MKDIR} -m 0750 ${STAGEDIR}${WAZUHPREFIX}${DIRE}
.endfor

.for DIRE in ${WAZUHMOD770}
	${MKDIR} -m 0770 ${STAGEDIR}${WAZUHPREFIX}${DIRE}
.endfor

.for FILE in ${WZBIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${FILE} ${STAGEDIR}${WAZUHPREFIX}/bin
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/src/syscheckd/build/bin/wazuh-syscheckd ${STAGEDIR}${WAZUHPREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/init/wazuh-client.sh ${STAGEDIR}${WAZUHPREFIX}/bin/wazuh-control

	${TOUCH} ${STAGEDIR}${WAZUHPREFIX}/etc/localtime

	${INSTALL_DATA} ${WRKSRC}/etc/internal_options.conf ${STAGEDIR}${WAZUHPREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/src/wazuh_modules/syscollector/norm_config.json ${STAGEDIR}${WAZUHPREFIX}/queue/syscollector
	${INSTALL_DATA} ${WRKSRC}/etc/local_internal_options.conf ${STAGEDIR}${WAZUHPREFIX}/etc/local_internal_options.conf.sample

	${INSTALL_DATA} /dev/null ${STAGEDIR}${WAZUHPREFIX}/etc/client.keys.sample
	${INSTALL_DATA} ${WRKSRC}/etc/wpk_root.pem ${STAGEDIR}${WAZUHPREFIX}/etc/

	${INSTALL_DATA} ${WRKSRC}/etc/ossec-agent.conf ${STAGEDIR}${WAZUHPREFIX}/etc/ossec.conf.sample

	${INSTALL_SCRIPT} ${WRKSRC}/src/agentlessd/scripts/* ${STAGEDIR}${WAZUHPREFIX}/agentless/

.for FILE in ${WZARBIN_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${FILE} ${STAGEDIR}${WAZUHPREFIX}/active-response/bin
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/src/wazuh-slack ${STAGEDIR}${WAZUHPREFIX}/active-response/bin

	${INSTALL_SCRIPT} ${WRKSRC}/src/active-response/*.sh ${STAGEDIR}${WAZUHPREFIX}/active-response/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/active-response/*.py ${STAGEDIR}${WAZUHPREFIX}/active-response/bin

	${INSTALL_PROGRAM} ${WRKSRC}/src/default-firewall-drop ${STAGEDIR}${WAZUHPREFIX}/active-response/bin/firewall-drop

	${INSTALL_DATA} ${WRKSRC}/ruleset/rootcheck/db/*.txt ${STAGEDIR}${WAZUHPREFIX}/etc/shared

	${INSTALL_DATA} ${WRKSRC}/ruleset/rootcheck/db/*.txt ${STAGEDIR}${WAZUHPREFIX}/etc/shared/default

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

	${INSTALL_DATA} ${WRKSRC}/ruleset/sca/generic/sca_unix_audit.yml ${STAGEDIR}${WAZUHPREFIX}/ruleset/sca/

	${INSTALL_LIB} ${WRKSRC}/src/libwazuhext.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/libwazuhshared.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/shared_modules/dbsync/build/lib/libdbsync.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/shared_modules/rsync/build/lib/librsync.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/syscheckd/build/lib/libfimdb.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/wazuh_modules/syscollector/build/lib/libsyscollector.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/src/data_provider/build/lib/libsysinfo.so ${STAGEDIR}${WAZUHPREFIX}/lib

	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/packages_files/agent_installation_scripts/etc/templates
	${MKDIR} ${STAGEDIR}${WAZUHPREFIX}/packages_files/agent_installation_scripts/src

	cd ${WRKSRC}/etc/templates && ${COPYTREE_SHARE} config \
		${STAGEDIR}${WAZUHPREFIX}/packages_files/agent_installation_scripts/etc/templates/
	cd ${WRKSRC}/ruleset && ${COPYTREE_SHARE} sca \
		${STAGEDIR}${WAZUHPREFIX}/packages_files/agent_installation_scripts/
	cd ${WRKSRC}/src && ${COPYTREE_SHARE} init \
		${STAGEDIR}${WAZUHPREFIX}/packages_files/agent_installation_scripts/src/

	${INSTALL_SCRIPT} ${WRKSRC}/gen_ossec.sh ${STAGEDIR}${WAZUHPREFIX}/packages_files/agent_installation_scripts/
	${INSTALL_SCRIPT} ${WRKSRC}/add_localfiles.sh ${STAGEDIR}${WAZUHPREFIX}/packages_files/agent_installation_scripts/

.include <bsd.port.post.mk>
