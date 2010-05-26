# New ports collection makefile for:   impresscms
# Date created:		25 August 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	impresscms
PORTVERSION=	1.2.1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/ImpressCMS%20Official%20Releases/ImpressCMS%20${PORTVERSION}%20Final
DISTNAME=	${PORTNAME}_${PORTVERSION}_final

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A Community Developed Content Management System

USE_PHP=	mysql pcre session iconv xml gd
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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
