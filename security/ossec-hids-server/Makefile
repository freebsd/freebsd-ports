# New ports collection makefile for:	ossec-hids-server
# Date created:		23 July 2006
# Whom:			Valerio Daelli <valerio.daelli@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ossec-hids
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.ossec.net/files/ \
		http://www.ossec.net/files/old/
PKGNAMESUFFIX=	-server

MAINTAINER=	glarkin@FreeBSD.org
COMMENT?=	A security tool to monitor and check logs and intrusions

USE_RC_SUBR=	ossec-hids

.if !defined(CLIENT_ONLY)
OPTIONS=	MYSQL "Enable MySQL support" off \
		PGSQL "Enable PostgreSQL support" off
.endif

SUB_LIST=	PORTNAME=${PORTNAME}
SUB_FILES=	pkg-message
PLIST_SUB=	PORTNAME=${PORTNAME}
PORTDOCS=	BUGS CONFIG CONTRIBUTORS INSTALL LICENSE README

.include <bsd.port.pre.mk>

.if !defined(CLIENT_ONLY)
.if defined(WITH_MYSQL)
WITH_DB=	yes
USE_MYSQL=	yes
.endif

.if defined(WITH_PGSQL)
WITH_DB=	yes
USE_PGSQL=	yes
.endif
.endif

.if defined(CLIENT_ONLY)
PKGNAMESUFFIX=	-client
CONFLICTS=	ossec-hids-server-[0-9]* ossec-hids-local-[0-9]*
.elif defined(LOCAL_ONLY)
PKGNAMESUFFIX=	-local
CONFLICTS=	ossec-hids-client-[0-9]* ossec-hids-server-[0-9]*
.else
CONFLICTS=	ossec-hids-client-[0-9]* ossec-hids-local-[0-9]*
.endif

post-patch:
	@${REINPLACE_CMD} 's|PREFIX|${PREFIX}/${PORTNAME}|' ${WRKSRC}/src/LOCATION
	@${REINPLACE_CMD} 's|PREFIX|${PREFIX}/${PORTNAME}|' ${WRKSRC}/src/headers/defs.h

do-build:
.if defined(WITH_DB)
.if defined(CLIENT_ONLY)
	@cd ${WRKSRC}/src;${MAKE} setagent;${MAKE} all;${MAKE} build
.else
	@cd ${WRKSRC}/src;${MAKE} setdb;${MAKE} all;${MAKE} build
.endif
.else
.if defined(CLIENT_ONLY)
	@cd ${WRKSRC}/src;${MAKE} setagent;${MAKE} all;${MAKE} build
.else
	@cd ${WRKSRC}/src;${MAKE} all;${MAKE} build
.endif
.endif

.if defined(CLIENT_ONLY)
do-install:
	@cd ${WRKSRC}/src; ${MAKE} agent
.elif defined(LOCAL_ONLY)
do-install:
	@cd ${WRKSRC}/src; ${MAKE} local
.else
do-install:
	@cd ${WRKSRC}/src; ${MAKE} server
.endif

post-install:
.if defined(CLIENT_ONLY)
	${CP} ${WRKSRC}/etc/ossec-agent.conf ${PREFIX}/${PORTNAME}/etc/ossec.conf.sample
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

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
