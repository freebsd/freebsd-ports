# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	impresscms
PORTVERSION=	1.3.4
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/ImpressCMS%20Official%20Releases/ImpressCMS%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_final

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A Community Developed Content Management System

USES=		zip
USE_PHP=	mysql pcre session iconv xml gd
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} htdocs ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} extras ${STAGEDIR}${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' \
		>> ${TMPPLIST}

.include <bsd.port.mk>
