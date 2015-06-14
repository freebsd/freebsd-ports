# Created by: Valerio Daelli <valerio.daelli@gmail.com>
# $FreeBSD$

PORTNAME=	ossec-hids
PORTVERSION=	2.8.2
PORTREVISION?=	0
CATEGORIES=	security
USE_GITHUB=	yes
GH_ACCOUNT=	ossec
PKGNAMESUFFIX=	-server

MAINTAINER=	brd@FreeBSD.org
COMMENT?=	Security tool to monitor and check logs and intrusions

USE_RC_SUBR=	ossec-hids

CFLAGS+=	-ferror-limit=0

USES=		readline
USE_OPENSSL=	yes

.if defined(MAINTAINER_MODE)
UID_FILES+=	../../UIDs
GID_FILES+=	../../GIDs
.endif
USERS=		ossec ossecm ossecr
GROUPS=		ossec

.if !defined(CLIENT_ONLY)
OPTIONS_DEFINE=	MYSQL PGSQL
.endif
OPTIONS_DEFINE+=	DOCS

SUB_LIST=	PORTNAME=${PORTNAME}
SUB_FILES=	pkg-message
PLIST_SUB=	PORTNAME=${PORTNAME}
PORTDOCS=	BUGS CONFIG CONTRIBUTORS INSTALL LICENSE

.include <bsd.port.pre.mk>

.if !defined(CLIENT_ONLY)
.if ${PORT_OPTIONS:MMYSQL}
WITH_DB=	yes
USE_MYSQL=	client
.endif

.if ${PORT_OPTIONS:MPGSQL}
WITH_DB=	yes
USES+=		pgsql
.endif
.endif

STRIP_FILES=	ossec-luac agent_control ossec-lua ossec-dbd ossec-regex ossec-monitord ossec-makelists verify-agent-conf ossec-analysisd ossec-agentlessd syscheck_control ossec-execd manage_agents ossec-csyslogd ossec-syscheckd ossec-logtest ossec-authd ossec-logcollector list_agents ossec-maild clear_stats ossec-remoted ossec-reportd rootcheck_control syscheck_update
.if defined(CLIENT_ONLY)
SUB_LIST+=	PRECMD=:
PKGNAMESUFFIX=	-client
CONFLICTS=	ossec-hids-server-[0-9]* ossec-hids-local-[0-9]*
STRIP_FILES=	agent-auth manage_agents ossec-agentd ossec-execd ossec-logcollector ossec-lua ossec-luac ossec-syscheckd
.elif defined(LOCAL_ONLY)
SUB_LIST+=	PRECMD=ossechids_start_precmd
PKGNAMESUFFIX=	-local
CONFLICTS=	ossec-hids-client-[0-9]* ossec-hids-server-[0-9]*
.else
SUB_LIST+=	PRECMD=ossechids_start_precmd
CONFLICTS=	ossec-hids-client-[0-9]* ossec-hids-local-[0-9]*
.endif

post-patch:
	@${REINPLACE_CMD} 's|PREFIX|${PREFIX}/${PORTNAME}|' ${WRKSRC}/src/headers/defs.h
	@${ECHO} "DIR=\"${STAGEDIR}${PREFIX}/${PORTNAME}\"" > ${WRKSRC}/src/LOCATION
	@${REINPLACE_CMD} -e 's|-DLUA_USE_LINUX|& ${CPPFLAGS}|' \
		-e 's|-lreadline|& ${LDFLAGS}|' \
		${WRKSRC}/src/external/lua-5.2.3/src/Makefile

do-build:
.if defined(WITH_DB)
.if defined(CLIENT_ONLY)
	@cd ${WRKSRC}/src;${MAKE} setagent;${MAKE} all;${MAKE} build
.elif defined(LOCAL_ONLY)
	@cd ${WRKSRC}/src;${MAKE} setlocal;${MAKE} all;${MAKE} build
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

post-install:
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

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
