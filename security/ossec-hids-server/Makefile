# New ports collection makefile for:	ossec-hids-server
# Date created:		23 July 2006
# Whom:			Valerio Daelli <valerio.daelli@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ossec-hids
PORTVERSION=	1.3
PORTREVISION?=	0
CATEGORIES=	security
MASTER_SITES=	http://www.ossec.net/files/ \
		http://www.ossec.net/files/old/
PKGNAMESUFFIX?=	-server

MAINTAINER=	valerio.daelli@gmail.com
COMMENT=	A security tool to monitor and check logs and intrusions

USE_RC_SUBR=	ossec-hids

SUB_LIST=	PORTNAME=${PORTNAME}
SUB_FILES=	pkg-message
PLIST_SUB=	PORTNAME=${PORTNAME}
PORTDOCS=	BUGS CONFIG CONTRIB INSTALL LICENSE README

.include <bsd.port.pre.mk>

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
	@cd ${WRKSRC}/src;${MAKE} all;${MAKE} build

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
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
