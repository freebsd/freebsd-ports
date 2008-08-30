# New ports collection makefile for:   impresscms
# Date created:		25 August 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	impresscms
PORTVERSION=	1.0.2
CATEGORIES=	www
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}_final

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Community Developed Content Management System

USE_PHP=	mysql pcre session iconv xml
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>
do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} htdocs ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} upgrade ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} extras ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 755 -R ${WWWDIR}' \
		>> ${TMPPLIST}

post-install:
	@${CHMOD} -R 777 ${WWWDIR}/htdocs/cache
	@${CHMOD} -R 777 ${WWWDIR}/htdocs/uploads
	@${CHMOD} -R 777 ${WWWDIR}/htdocs/templates_c
	@${CHMOD} -R 666 ${WWWDIR}/htdocs/mainfile.php

	@${ECHO_CMD} '@exec ${CHMOD} 777 -R ${WWWDIR}/htdocs/cache' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 777 -R ${WWWDIR}/htdocs/uploads' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 777 -R ${WWWDIR}/htdocs/templates_c' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 666 -R ${WWWDIR}/htdocs/mainfile.php' \
		>> ${TMPPLIST}

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
