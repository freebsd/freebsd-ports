# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	impresscms
PORTVERSION=	1.3.7
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/ImpressCMS%20Official%20Releases/ImpressCMS%201.3%20Branch/ImpressCMS%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_final

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Community Developed Content Management System

USES=		zip
USE_PHP=	mysql pcre session iconv xml gd
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} htdocs ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} extras ${STAGEDIR}${WWWDIR}
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
