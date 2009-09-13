# New ports collection makefile for:	dokeos
# Date created:				21 January 2006
# Whom:					Filipe Rocha <filiperocha@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	dokeos
PORTVERSION=	1.8.6
CATEGORIES=	www
MASTER_SITES=	http://www.dokeos.com/download/

MAINTAINER=	filiperocha@gmail.com
COMMENT=	Dokeos is an elearning and course management web application

USE_PHP=	mysql session gd pcre zlib
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
OPTIONS=	LDAP "Use LDAP" off

.if defined(WITH_LDAP)
USE_PHP+=	ldap
.endif

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 755 -R ${WWWDIR}' \
		>> ${TMPPLIST}
	@${CHMOD} 666 ${WWWDIR}/home/*.html
	@${ECHO_CMD} '@exec ${CHMOD} 666 ${WWWDIR}/home/*.html' \
		>> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
