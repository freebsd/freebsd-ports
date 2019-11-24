# $FreeBSD$

PKGNAMESUFFIX?=	-${OSSEC_TYPE}
COMMENT?=	Security tool to monitor and check logs and intrusions - local (standalone) installation
OSSEC_TYPE?=	local

.include "${.CURDIR}/../ossec-hids/version.mk"

LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler gmake ssl

.if ${OSSEC_TYPE} == local
CONFLICTS_INSTALL=	ossec-hids-client-* \
			ossec-hids-agent-* \
			ossec-hids-server-*
.elif ${OSSEC_TYPE} == agent
CONFLICTS_INSTALL=	ossec-hids-client-* \
			ossec-hids-local-* \
			ossec-hids-server-*
.elif ${OSSEC_TYPE} == server
CONFLICTS_INSTALL=	ossec-hids-client-* \
			ossec-hids-agent-* \
			ossec-hids-local-*
.endif

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 libevent.so:devel/libevent
.if ${OSSEC_TYPE} != agent
RUN_DEPENDS=	expect:lang/expect
.endif

INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
PRELUDE_LIB_DEPENDS=	libprelude.so:security/libprelude
ZEROMQ_LIB_DEPENDS=	libczmq.so:net/czmq

INOTIFY_USES=	pkgconfig
LUA_USES=	readline
MYSQL_USE=	mysql
PGSQL_USES=	pgsql

USE_GITHUB=	yes
GH_ACCOUNT=	ossec

USE_RC_SUBR=	ossec-hids

USES+=		shebangfix
SHEBANG_FILES=	active-response/ossec-pagerduty.sh

.if ${OSSEC_TYPE} != agent
SHEBANG_LANG=	expect
expect_OLD_CMD=	"/usr/bin/env expect"
expect_CMD=	${LOCALBASE}/bin/expect
SHEBANG_FILES+=	src/agentlessd/scripts/main.exp \
		src/agentlessd/scripts/ssh.exp \
		src/agentlessd/scripts/ssh_asa-fwsmconfig_diff \
		src/agentlessd/scripts/ssh_foundry_diff \
		src/agentlessd/scripts/ssh_generic_diff \
		src/agentlessd/scripts/ssh_integrity_check_bsd \
		src/agentlessd/scripts/ssh_integrity_check_linux \
		src/agentlessd/scripts/ssh_nopass.exp \
		src/agentlessd/scripts/ssh_pixconfig_diff \
		src/agentlessd/scripts/sshlogin.exp \
		src/agentlessd/scripts/su.exp
.endif

OPTIONS_SUB=			yes
OPTIONS_DEFINE=			DOCS INOTIFY LUA

.if ${OSSEC_TYPE} != agent
OPTIONS_DEFINE+=		PRELUDE ZEROMQ

OPTIONS_RADIO=			DATABASE
OPTIONS_RADIO_DATABASE=		MYSQL PGSQL
.endif

OPTIONS_DEFAULT=		INOTIFY

INOTIFY_DESC=		Kevent based real time monitoring
PRELUDE_DESC=		Sensor support from Prelude SIEM
ZEROMQ_DESC=		ZeroMQ support (experimental)
DATABASE_DESC=		Database output

INOTIFY_VARS=	OSSEC_ARGS+=USE_INOTIFY=yes
LUA_VARS=	OSSEC_ARGS+=LUA_ENABLE=yes STRIP_FILES+=ossec-lua STRIP_FILES+=ossec-luac
PRELUDE_VARS=	OSSEC_ARGS+=USE_PRELUDE=yes
ZEROMQ_VARS=	OSSEC_ARGS+=USE_ZEROMQ=yes
MYSQL_VARS=	OSSEC_ARGS+=DATABASE=mysql PKGMSG_FILES+=message-database DB_TYPE=mysql DB_SCHEMA=mysql.schema
PGSQL_VARS=	OSSEC_ARGS+=DATABASE=pgsql PKGMSG_FILES+=message-database DB_TYPE=postgresql DB_SCHEMA=postgresql.schema

.if ${OSSEC_TYPE} == agent
STRIP_FILES=	agent-auth \
		manage_agents \
		ossec-agentd \
		ossec-execd \
		ossec-logcollector \
		ossec-syscheckd
.else
STRIP_FILES=	agent_control \
		clear_stats \
		list_agents \
		manage_agents \
		ossec-agentlessd \
		ossec-analysisd \
		ossec-authd \
		ossec-csyslogd \
		ossec-dbd \
		ossec-execd \
		ossec-logcollector \
		ossec-logtest \
		ossec-maild \
		ossec-makelists \
		ossec-monitord \
		ossec-regex \
		ossec-remoted \
		ossec-reportd \
		ossec-syscheckd \
		rootcheck_control \
		syscheck_control \
		syscheck_update \
		verify-agent-conf
.endif
.if defined(MAINTAINER_MODE)
OSSEC_HOME=		${PREFIX}/${PORTNAME}
.else
OSSEC_HOME?=		${PREFIX}/${PORTNAME}
.endif
OSSEC_RC=		${PREFIX}/etc/rc.d/ossec-hids
FIREWALL_DROP_BIN=	${OSSEC_HOME}/active-response/bin/firewall-drop.sh
IPFILTER_BIN=		${OSSEC_HOME}/active-response/bin/ipfilter.sh
RESTART_OSSEC_BIN=	${OSSEC_HOME}/active-response/bin/restart-ossec.sh
SHARED_DIR=		${OSSEC_HOME}/etc/shared

SAMPLE_FILES=		${OSSEC_HOME}/etc/local_internal_options.conf \
			${OSSEC_HOME}/active-response/bin/cloudflare-ban.sh \
			${OSSEC_HOME}/active-response/bin/ossec-pagerduty.sh \
			${OSSEC_HOME}/active-response/bin/ossec-slack.sh \
			${OSSEC_HOME}/active-response/bin/ossec-tweeter.sh

.if empty(USER)
USER=$$(${ID} -un)
.endif
.if empty(GROUP)
GROUP=$$(${ID} -gn)
.endif

.if !defined(MAINTAINER_MODE)
USER_ARGS+=	OSSEC_GROUP=${GROUP} \
		OSSEC_USER=${USER} \
		OSSEC_USER_MAIL=${USER} \
		OSSEC_USER_REM=${USER}
.endif
OSSEC_USER=	ossec
OSSEC_GROUP=	ossec
USERS=		${OSSEC_USER} ossecm ossecr
GROUPS=		${OSSEC_GROUP}

SUB_LIST+=	PORTNAME=${PORTNAME} \
		CATEGORY=${CATEGORIES:[1]} \
		OSSEC_TYPE=${OSSEC_TYPE} \
		OSSEC_HOME=${OSSEC_HOME} \
		VERSION=${PORTVERSION} \
		DB_TYPE=${DB_TYPE} \
		DB_SCHEMA=${DOCSDIR}/${DB_SCHEMA} \
		OSSEC_USER=${OSSEC_USER} \
		OSSEC_GROUP=${OSSEC_GROUP} \
		OSSEC_RC=${OSSEC_RC}
SUB_FILES=	pkg-install \
		pkg-deinstall \
		${PKGMSG_FILES} \
		restart-ossec.sh

.if defined(MAINTAINER_MODE)
PLIST_SUB=	OSSEC_HOME=${PORTNAME}
.else
PLIST_SUB=	OSSEC_HOME=${OSSEC_HOME}
.endif
PLIST=		${PKGDIR}/pkg-plist-${OSSEC_TYPE}
DOCSFILES=	BUGS CHANGELOG CONTRIBUTORS LICENSE README.md SUPPORT.md
PKGHELP=	${PKGDIR}/pkg-help-${OSSEC_TYPE}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGMSG_FILES=	message-header

PKG_CONFIG=	${CONFIGURE_ENV:MPKG_CONFIG=*:S/PKG_CONFIG=//}
CFLAGS+=	-I${LOCALBASE}/include
INOTIFY_CFLAGS=	$$(${PKG_CONFIG} --cflags libinotify)
INOTIFY_LDFLAGS=$$(${PKG_CONFIG} --libs libinotify)

OSSEC_ARGS+=	TARGET=${OSSEC_TYPE} PCRE2_SYSTEM=yes INSTALL_LOCALTIME=no INSTALL_RESOLVCONF=no
.if defined(OSSEC_MAX_AGENTS)
OSSEC_ARGS+=	MAXAGENTS=${OSSEC_MAX_AGENTS}
.endif
.if !defined(MAINTAINER_MODE)
OSSEC_ARGS+=	INSTALL_CMD=install
.endif
BUILD_ARGS+=	${MAKE_ARGS} ${OSSEC_ARGS} PREFIX=${OSSEC_HOME}
INSTALL_ARGS+=	${USER_ARGS} ${OSSEC_ARGS} PREFIX=${STAGEDIR}${OSSEC_HOME}

.include <bsd.port.pre.mk>

PKGMSG_FILES+=	message-firewall message-config

post-patch:
	@${REINPLACE_CMD} -e 's|-DLUA_USE_LINUX|& ${CPPFLAGS}|' \
		-e 's|-lreadline|& ${LDFLAGS}|' \
		${WRKSRC}/src/external/lua/src/Makefile
.if ${CHOSEN_COMPILER_TYPE} == gcc
	@${REINPLACE_CMD} -e 's|-Wno-implicit-fallthrough||g' ${WRKSRC}/src/Makefile
.endif

do-build:
	@cd ${WRKSRC}/src; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${BUILD_ARGS} build

do-install:
	@cd ${WRKSRC}/src; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${INSTALL_ARGS} install

post-install:
.for file_path in ${SAMPLE_FILES}
	@${MV} -f ${STAGEDIR}${file_path} ${STAGEDIR}${file_path}.sample
.endfor
	@${MV} -f ${STAGEDIR}${FIREWALL_DROP_BIN} ${STAGEDIR}${IPFILTER_BIN}
	@${CP} ${WRKDIR}/restart-ossec.sh ${STAGEDIR}${RESTART_OSSEC_BIN}
	@${CHMOD} 550 ${STAGEDIR}${RESTART_OSSEC_BIN}
.if defined(MAINTAINER_MODE)
	@${CHOWN} ${USER}:${OSSEC_GROUP} ${STAGEDIR}${RESTART_OSSEC_BIN}
.else
	@${SH} ${SCRIPTDIR}/sanitize-stage.sh ${OSSEC_TYPE} ${OSSEC_HOME} ${STAGEDIR}
.endif

.if ${OSSEC_TYPE} == agent
. if defined(MAINTAINER_MODE)
	@for file_name in $$(find "${STAGEDIR}${SHARED_DIR}" -type f); do ${CHMOD} 0644 $${file_name}; ${CHOWN} ${OSSEC_USER}:${OSSEC_GROUP} $${file_name}; done
. else
	@for file_name in $$(find "${STAGEDIR}${SHARED_DIR}" -type f); do ${CHMOD} 0644 $${file_name}; done
. endif
.endif
	@${ECHO_CMD} -n > ${PKGMESSAGE}
.for file_name in ${PKGMSG_FILES}
	@${CAT} ${WRKDIR}/${file_name} >> ${PKGMESSAGE}
	@${ECHO_CMD} >> ${PKGMESSAGE}
.endfor
.for file_name in ${STRIP_FILES}
	@${STRIP_CMD} ${STAGEDIR}${OSSEC_HOME}/bin/${file_name}
.endfor

.if defined(MAINTAINER_MODE)
plist: makeplist
	@${SH} ${SCRIPTDIR}/plist.sh ${OSSEC_TYPE} ${OSSEC_HOME} ${PLIST} ${WRKDIR} ${STAGEDIR}
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCSFILES} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} etc/ossec-${OSSEC_TYPE}.conf ${STAGEDIR}${DOCSDIR}/ossec.conf.sample

post-install-MYSQL-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} src/os_dbd/${DB_SCHEMA} ${STAGEDIR}${DOCSDIR}

post-install-PGSQL-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} src/os_dbd/${DB_SCHEMA} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
