# New ports collection makefile for:   xoops
# Date created:		02/08/2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xoops
PORTVERSION=	2.0.18.1
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Dynamic Web CMS

USE_PHP=	mysql

NO_BUILD=	yes
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 755 -R ${WWWDIR}' \
		>> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
