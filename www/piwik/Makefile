# New ports collection makefile for:   piwik
# Date created:		31 Dec 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	piwik
PORTVERSION=	0.4.3
CATEGORIES=	www
MASTER_SITES=	http://builds.piwik.org/

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Open Source Web Analytics Software Program

USE_PHP=	mysql gd pdo pdo_mysql zlib
WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>
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
