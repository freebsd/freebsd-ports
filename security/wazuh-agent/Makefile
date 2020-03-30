# $FreeBSD$

PORTNAME=	wazuh
DISTVERSIONPREFIX=	v
DISTVERSION=	3.12.0
CATEGORIES=	security
MASTER_SITES=	https://packages.wazuh.com/deps/3.12/
PKGNAMESUFFIX=	-agent
DISTFILES=	cJSON.tar.gz src_cpython.tar.gz curl.tar.gz libdb.tar.gz libffi.tar.gz \
		libyaml.tar.gz openssl.tar.gz procps.tar.gz sqlite.tar.gz  zlib.tar.gz \
		audit-userspace.tar.gz msgpack.tar.gz
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	m.muenz@gmail.com
COMMENT=	Security tool to monitor and check logs and intrusions

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	Fails to build external OpenSSL dependency

USES=		gmake perl5 readline shebangfix uidfix

USE_GITHUB=	yes

CONFLICTS_INSTALL=	ossec-*

SHEBANG_FILES=	${WRKSRC}/contrib/util.sh \
		${WRKSRC}/src/external/openssl/Configurations/unix-checker.pm \
		${WRKSRC}/src/init/ossec-client.sh \
		${WRKSRC}/wodles/oscap/oscap.py \
		${WRKSRC}/active-response/*.sh

USERS=		ossec ossecm ossecr
GROUPS=		ossec

OSSEC_GROUP=	ossec
OSSEC_USER=	ossec

WAZUHPREFIX=	/var/ossec

WAZUHMOD750=	/ /logs/ossec /bin /lib /queue /queue/diff /ruleset /ruleset/sca /wodles \
		/active-response /active-response/bin /agentless /var /backup /queue/rids \
		/wodles/oscap /wodles/oscap/content

WAZUHMOD770=	/logs /queue/alerts /queue/ossec /etc /etc/shared /.ssh /var/run /var/upgrade \
		/var/wodles /var/incoming

# extract all extra distfiles in src/external
post-extract:
	@for file in ${DISTFILES}; do \
		if ! (cd ${WRKSRC}/src/external && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$file ${EXTRACT_AFTER_ARGS}); \
		then \
			exit 1; \
		fi; \
	done

do-build:
	@cd ${WRKSRC}/src && ${GMAKE} TARGET=agent

do-install:
	@for mod750 in ${WAZUHMOD750}; do \
		${MKDIR} -m 0750 ${STAGEDIR}${WAZUHPREFIX}$$mod750; \
	done

	@for mod770 in ${WAZUHMOD770}; do \
		${MKDIR} -m 0770 ${STAGEDIR}${WAZUHPREFIX}$$mod770; \
	done

	${MKDIR} -m 1770 ${STAGEDIR}${WAZUHPREFIX}/tmp
	${INSTALL_PROGRAM} ${WRKSRC}/src/ossec-logcollector ${STAGEDIR}${WAZUHPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/ossec-syscheckd ${STAGEDIR}${WAZUHPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/ossec-execd ${STAGEDIR}${WAZUHPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/manage_agents ${STAGEDIR}${WAZUHPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/wazuh-modulesd ${STAGEDIR}${WAZUHPREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/src/ossec-agentd ${STAGEDIR}${WAZUHPREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/libwazuhext.so ${STAGEDIR}${WAZUHPREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/src/agent-auth ${STAGEDIR}${WAZUHPREFIX}/bin
	${CP} ${WRKSRC}/active-response/*.sh ${STAGEDIR}${WAZUHPREFIX}/active-response/bin/
	${CP} ${WRKSRC}/active-response/firewalls/*.sh ${STAGEDIR}${WAZUHPREFIX}/active-response/bin/
	${CP} ${WRKSRC}/etc/internal_options.conf ${STAGEDIR}${WAZUHPREFIX}/etc/
	${CP} ${WRKSRC}/etc/local_internal_options.conf ${STAGEDIR}${WAZUHPREFIX}/etc/local_internal_options.conf
	${CP} ${WRKSRC}/etc/ossec-agent.conf ${STAGEDIR}${WAZUHPREFIX}/etc/ossec.conf
	${CP} ${WRKSRC}/etc/ossec-agent.conf ${STAGEDIR}${WAZUHPREFIX}/etc/ossec.conf.sample
	${CP} /dev/null ${STAGEDIR}${WAZUHPREFIX}/etc/client.keys
	${INSTALL_SCRIPT} /dev/null ${STAGEDIR}${WAZUHPREFIX}/logs/ossec.log
	${INSTALL_SCRIPT} /dev/null ${STAGEDIR}${WAZUHPREFIX}/logs/ossec.json
	${INSTALL_SCRIPT} /dev/null ${STAGEDIR}${WAZUHPREFIX}/logs/active-responses.log
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/util.sh ${STAGEDIR}${WAZUHPREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/src/init/ossec-client.sh ${STAGEDIR}${WAZUHPREFIX}/bin/ossec-control
	${INSTALL_SCRIPT} ${WRKSRC}/src/agentlessd/scripts/* ${STAGEDIR}${WAZUHPREFIX}/agentless/
	${INSTALL_SCRIPT} ${WRKSRC}/src/rootcheck/db/*.txt ${STAGEDIR}${WAZUHPREFIX}/etc/shared/
	${INSTALL_SCRIPT} ${WRKSRC}/etc/wpk_root.pem ${STAGEDIR}${WAZUHPREFIX}/etc/
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/oscap/oscap.py ${STAGEDIR}${WAZUHPREFIX}/wodles/oscap
	${INSTALL_SCRIPT} ${WRKSRC}/wodles/oscap/template_*.xsl ${STAGEDIR}${WAZUHPREFIX}/wodles/oscap

.include <bsd.port.mk>
