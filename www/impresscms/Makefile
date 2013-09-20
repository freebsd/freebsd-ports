# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	impresscms
PORTVERSION=	1.3.4
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/ImpressCMS%20Official%20Releases/ImpressCMS%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_final

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A Community Developed Content Management System

USE_PHP=	mysql pcre session iconv xml gd
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.pre.mk>
do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} htdocs ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} extras ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' \
		>> ${TMPPLIST}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
