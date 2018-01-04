# Created by: Wen heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	elgg
PORTVERSION=	1.8.0.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://elgg.org/download/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Blogging and social networking platform

LICENSE=	GPLv2

IGNORE_WITH_PHP=	70 71 72

USE_PHP=	mysql gd json soap dom xml
USES=		cpe gettext zip php

NO_BUILD=	yes
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message
ELGGDATADIR=	${WWWDIR}data

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}
	@${INSTALL} -d ${STAGEDIR}${ELGGDATADIR}
	@${CHMOD} 777 ${STAGEDIR}${ELGGDATADIR}

.include <bsd.port.mk>
