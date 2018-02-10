# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phpmp
PORTVERSION=	0.12.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web interface for music player daemon

EXPIRATION_DATE=	2018-03-07
DEPRECATED=	Unmaintained, all www files wrongly belongs to www user.

LICENSE=	GPLv2

NO_BUILD=	yes
USES=		php
USE_PHP=	pcre sockets

PHPMP?=		${WWWDIR_REL}
PLIST_SUB=	PHPMP="${PHPMP}" WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PHPMP}
	@${CP} -R ${WRKSRC}/ ${STAGEDIR}${PREFIX}/${PHPMP}
	@${CHMOD} -R 755 ${STAGEDIR}${PREFIX}/${PHPMP}

.include <bsd.port.mk>
