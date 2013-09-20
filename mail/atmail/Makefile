# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	atmail
PORTVERSION=	1.0.4
CATEGORIES=	mail
MASTER_SITES=	http://atmail.org/download/
DISTNAME=	atmailopen
EXTRACT_SUFX=	.tgz

MAINTAINER=	chifeng@gmail.com
COMMENT=	An Open Source Webmail Client

USE_PHP=	mysql pcre session
WRKSRC=		${WRKDIR}/${DISTNAME}
NO_BUILD=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	LDAP MBSTRING
MBSTRING_DESC= Support for UTF8 folder names

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLDAP}
USE_PHP+=	ldap
.endif

.if ${PORT_OPTIONS:MMBSTRING}
USE_PHP+=	mbstring
.endif

.if ${PORT_OPTIONS:MICONV}
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

.include <bsd.port.mk>
