# New ports collection makefile for:	ossec-hids-server
# Date created:		23 July 2006
# Whom:			Valerio Daelli <valerio.daelli@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ossec-hids
PORTVERSION=	1.1
PORTREVISION?=	1
CATEGORIES=	security
MASTER_SITES=	http://www.ossec.net/files/
PKGNAMESUFFIX?=	-server

MAINTAINER=	valerio.daelli@gmail.com
COMMENT=	A security tool to monitor and check logs and intrusions

BROKEN=		Unfetchable

USE_RC_SUBR=	ossec-hids

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

do-configure:

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
	@if [ ! -f ${PREFIX}/${PORTNAME}/etc/ossec.conf ]; then \
	${CP} ${PREFIX}/${PORTNAME}/etc/ossec.conf.sample ${PREFIX}/${PORTNAME}/etc/ossec.conf ; \
	fi

.if defined(CLIENT_ONLY)
PLIST=${PKGDIR}/pkg-plist.client
.endif

.include <bsd.port.post.mk>
