# New ports collection makefile for:	claroline
# Date created:		29 Feb 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	claroline
PORTVERSION=	1.9.0
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Claroline/Claroline%20${PORTVERSION}
DISTNAME=	claroline190

MAINTAINER=	wenheping@gmail.com
COMMENT=	Open Source eLearning and eWorking platform

USE_ZIP=	yes
NO_BUILD=	yes
USE_PHP=	mysql
WRKSRC=		${WRKDIR}/${DISTNAME}
SUB_FILES=	pkg-message

OPTIONS=	LDAP    "Add LDAP authentication functionality" Off \
		GD      "Add GD functionality" On \
		OPENSSL "Add OpenSSL functionality" Off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GD)
USE_PHP+=	gd
.endif

.if defined(WITH_OPENSSL)
USE_PHP+=	openssl
.endif

.if defined(WITH_LDAP)
USE_PHP+=	ldap
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' >>${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
