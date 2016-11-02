# Created by: Bo-Yi Wu <appleboy.tw@gmail.com>
# $FreeBSD$

PORTNAME=	php-plurk-api
PORTVERSION=	1.6.4
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	appleboy.tw@gmail.com
COMMENT=	Plurk API Implementation with PHP

LICENSE=	BSD3CLAUSE

BROKEN=		Unfetchable (google code has gone away)

NO_BUILD=	yes
NO_ARCH=	yes
USE_PHP=	json curl
USES=		shebangfix zip
php_OLD_CMD=	/usr/bin/php5
SHEBANG_FILES=	example.php
WRKSRC=		${WRKDIR}/${PORTVERSION}

PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_LIST=	PKGNAME=${PKGNAME}
SUB_FILES=	pkg-message

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${CHMOD} 755 ${STAGEDIR}${WWWDIR}/example.php

.include <bsd.port.mk>
