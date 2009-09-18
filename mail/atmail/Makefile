# New ports collection makefile for:   atmail
# Date created:		18 June 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	atmail
PORTVERSION=	1.0.3
CATEGORIES=	mail
MASTER_SITES=	http://atmail.org/download/
DISTNAME=	atmailopen
EXTRACT_SUFX=	.tgz

MAINTAINER=	wen@FreeBSD.org
COMMENT=	An Open Source Webmail Client

USE_PHP=	mysql pcre session
WRKSRC=		${WRKDIR}/${DISTNAME}
NO_BUILD=	yes
SUB_FILES=	pkg-message

OPTIONS=	LDAP   "Add support for a LDAP" Off \
		MBSTRING "Add support for UTF8 folder names" Off \
		ICONV "Add support encoding conversion" Off

.include <bsd.port.pre.mk>
.if defined(WITH_LDAP)
USE_PHP+=	ldap
.endif

.if defined(WITH_MBSTRING)
USE_PHP+=	mbstring
.endif

.if defined(WITH_ICONV)
USE_PHP+=	iconv
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' \
		>> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
