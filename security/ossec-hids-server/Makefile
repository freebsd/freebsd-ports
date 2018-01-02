# Created by: Valerio Daelli <valerio.daelli@gmail.com>
# $FreeBSD$

PORTNAME=	ossec-hids
PORTVERSION=	2.8.3
DISTVERSIONPREFIX=	v
PORTREVISION?=	3
CATEGORIES=	security
PKGNAMESUFFIX=	-server

MAINTAINER=	dominik.lisiak@bemsoft.pl
COMMENT?=	Security tool to monitor and check logs and intrusions

USE_GITHUB=	yes
GH_ACCOUNT=	ossec
USE_RC_SUBR=	ossec-hids

CFLAGS+=	-ferror-limit=0

USES=		readline ssl

.if defined(MAINTAINER_MODE)
UID_FILES+=	../../UIDs
GID_FILES+=	../../GIDs
.endif
USERS=		ossec ossecm ossecr
GROUPS=		ossec

.if !defined(CLIENT_ONLY)
OPTIONS_DEFINE=	MYSQL PGSQL

MYSQL_VARS=	WITH_DB=yes
MYSQL_USE=	MYSQL=client
MYSQL_PORTDOCS=	mysql.schema

PGSQL_VARS=	WITH_DB=yes
PGSQL_USES=	pgsql
PGSQL_PORTDOCS=	postgresql.schema

RUN_DEPENDS=	expect:lang/expect

USES+=		shebangfix
SHEBANG_LANG=	expect
expect_OLD_CMD=	"/usr/bin/env expect"
expect_CMD=	${LOCALBASE}/bin/expect
SHEBANG_FILES=	src/agentlessd/scripts/main.exp \
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
OPTIONS_DEFINE+=	DOCS

SUB_LIST=	PORTNAME=${PORTNAME}
SUB_FILES=	pkg-message
PLIST_SUB=	PORTNAME=${PORTNAME}
DOCSFILES=	BUGS CONFIG CONTRIBUTORS INSTALL LICENSE
PORTDOCS=	${DOCSFILES}

BROKEN_aarch64=		Fails to compile: error: use of undeclared identifier __LDPGSZ

.include <bsd.port.pre.mk>

STRIP_FILES=	ossec-luac agent_control ossec-lua ossec-dbd ossec-regex ossec-monitord ossec-makelists verify-agent-conf ossec-analysisd ossec-agentlessd syscheck_control ossec-execd manage_agents ossec-csyslogd ossec-syscheckd ossec-logtest ossec-authd ossec-logcollector list_agents ossec-maild clear_stats ossec-remoted ossec-reportd rootcheck_control syscheck_update
.if defined(CLIENT_ONLY)
SUB_LIST+=	PRECMD=:
PKGNAMESUFFIX=	-client
CONFLICTS_INSTALL=	ossec-hids-server-[0-9]* ossec-hids-local-[0-9]*
STRIP_FILES=	agent-auth manage_agents ossec-agentd ossec-execd ossec-logcollector ossec-lua ossec-luac ossec-syscheckd
.elif defined(LOCAL_ONLY)
SUB_LIST+=	PRECMD=ossechids_start_precmd
PKGNAMESUFFIX=	-local
CONFLICTS_INSTALL=	ossec-hids-client-[0-9]* ossec-hids-server-[0-9]*
.else
SUB_LIST+=	PRECMD=ossechids_start_precmd
CONFLICTS_INSTALL=	ossec-hids-client-[0-9]* ossec-hids-local-[0-9]*
.endif

post-patch:
	@${REINPLACE_CMD} 's|PREFIX|${PREFIX}/${PORTNAME}|' ${WRKSRC}/src/headers/defs.h
	@${ECHO} "DIR=\"${STAGEDIR}${PREFIX}/${PORTNAME}\"" > ${WRKSRC}/src/LOCATION
	@${REINPLACE_CMD} -e 's|-DLUA_USE_LINUX|& ${CPPFLAGS}|' \
		-e 's|-lreadline|& ${LDFLAGS}|' \
		${WRKSRC}/src/external/lua-5.2.3/src/Makefile
	@${REINPLACE_CMD} -e 's|OPENSSLCMD=|OPENSSLCMD=-L${OPENSSLLIB} |' \
		${WRKSRC}/src/Makeall

do-build:
.if defined(WITH_DB)
.if defined(CLIENT_ONLY)
	@cd ${WRKSRC}/src;${MAKE} setagent;${MAKE} all;${MAKE} build
.elif defined(LOCAL_ONLY)
	@cd ${WRKSRC}/src;${MAKE} setlocal;${MAKE} setdb;${MAKE} all;${MAKE} build
.else
	@cd ${WRKSRC}/src;${MAKE} setdb;${MAKE} all;${MAKE} build
.endif
.else
.if defined(CLIENT_ONLY)
	@cd ${WRKSRC}/src;${MAKE} setagent;${MAKE} all;${MAKE} build; \
		${MAKE} unsetdb
.elif defined(LOCAL_ONLY)
	@cd ${WRKSRC}/src;${MAKE} setlocal;${MAKE} all;${MAKE} build; \
		${MAKE} unsetdb
.else
	@cd ${WRKSRC}/src;${MAKE} all;${MAKE} build;${MAKE} unsetdb
.endif
.endif

do-install:
.if defined(CLIENT_ONLY)
	@cd ${WRKSRC}/src; ${MAKE} agent
.elif defined(LOCAL_ONLY)
	@cd ${WRKSRC}/src; ${MAKE} local
.else
	@cd ${WRKSRC}/src; ${MAKE} server
.endif
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}/etc
.for file in ${STRIP_FILES}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/ossec-hids/bin/${file}
.endfor

.if defined(CLIENT_ONLY)
	@${CP} ${WRKSRC}/etc/ossec-agent.conf ${STAGEDIR}${PREFIX}/${PORTNAME}/etc/ossec.conf.sample
.elif defined(LOCAL_ONLY)
	${CP} ${WRKSRC}/etc/ossec-local.conf ${STAGEDIR}${PREFIX}/${PORTNAME}/etc/ossec.conf.sample
.else
	${CP} ${WRKSRC}/etc/ossec-server.conf ${STAGEDIR}${PREFIX}/${PORTNAME}/etc/ossec.conf.sample
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCSFILES} ${STAGEDIR}${DOCSDIR}

post-install-MYSQL-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} src/os_dbd/mysql.schema ${STAGEDIR}${DOCSDIR}

post-install-PGSQL-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} src/os_dbd/postgresql.schema ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
