# Created by: Valerio Daelli <valerio.daelli@gmail.com>
# $FreeBSD$

PORTNAME=	ossec-hids
PORTVERSION=	2.7
PORTREVISION?=	0
CATEGORIES=	security
MASTER_SITES=	http://www.ossec.net/files/ \
		http://www.ossec.net/files/old/
PKGNAMESUFFIX=	-server

MAINTAINER=	glarkin@FreeBSD.org
COMMENT?=	A security tool to monitor and check logs and intrusions

USE_RC_SUBR=	ossec-hids

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
PORTDOCS=	BUGS CONFIG CONTRIBUTORS INSTALL LICENSE README

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 800067
# Add string function that didn't exist until 8.x
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src__os_csyslogd__csyslogd.c
.endif

.if !defined(CLIENT_ONLY)
.if ${PORT_OPTIONS:MMYSQL}
WITH_DB=	yes
USE_MYSQL=	client
.endif

.if ${PORT_OPTIONS:MPGSQL}
WITH_DB=	yes
USE_PGSQL=	yes
.endif
.endif

.if defined(CLIENT_ONLY)
SUB_LIST+=	PRECMD=:
PKGNAMESUFFIX=	-client
CONFLICTS=	ossec-hids-server-[0-9]* ossec-hids-local-[0-9]*
.elif defined(LOCAL_ONLY)
SUB_LIST+=	PRECMD=ossechids_start_precmd
PKGNAMESUFFIX=	-local
CONFLICTS=	ossec-hids-client-[0-9]* ossec-hids-server-[0-9]*
.else
SUB_LIST+=	PRECMD=ossechids_start_precmd
CONFLICTS=	ossec-hids-client-[0-9]* ossec-hids-local-[0-9]*
.endif

post-patch:
	@${REINPLACE_CMD} 's|PREFIX|${PREFIX}/${PORTNAME}|' ${WRKSRC}/src/LOCATION
	@${REINPLACE_CMD} 's|PREFIX|${PREFIX}/${PORTNAME}|' ${WRKSRC}/src/headers/defs.h

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
	@${MKDIR} ${PREFIX}/${PORTNAME}/etc

.if defined(CLIENT_ONLY)
	@${CP} ${WRKSRC}/etc/ossec-agent.conf ${PREFIX}/${PORTNAME}/etc/ossec.conf.sample
	@if [ ! -f ${PREFIX}/${PORTNAME}/etc/ossec.conf ]; then \
	${CP} ${WRKSRC}/etc/ossec-agent.conf ${PREFIX}/${PORTNAME}/etc/ossec.conf; \
	fi
.elif defined(LOCAL_ONLY)
	${CP} ${WRKSRC}/etc/ossec-local.conf ${PREFIX}/${PORTNAME}/etc/ossec.conf.sample
	@if [ ! -f ${PREFIX}/${PORTNAME}/etc/ossec.conf ]; then \
	${CP} ${WRKSRC}/etc/ossec-local.conf ${PREFIX}/${PORTNAME}/etc/ossec.conf; \
	fi
.else
	@if [ ! -f ${PREFIX}/${PORTNAME}/etc/ossec.conf ]; then \
	${CP} ${WRKSRC}/etc/ossec-server.conf ${PREFIX}/${PORTNAME}/etc/ossec.conf; \
	fi
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
