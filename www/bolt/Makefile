# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bolt
PORTVERSION=	2.2.10
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://bolt.cm/distribution/

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Sophisticated, lightweight & simple CMS

LICENSE=	MIT

NO_ARCH=	yes
NO_BUILD=	yes
USE_PHP=	curl gd openssl simplexml
WANT_PHP_WEB=	yes

PLIST_SUB+=	WWWGRP=${WWWGRP}

WRKSRC=	${WRKDIR}/bolt-git-2015-09-01-ca8eace

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	SQLITE

MYSQL_USE=	PHP=pdo_mysql
PGSQL_USE=	PHP=pdo_pgsql
SQLITE_USE=	PHP=pdo_sqlite

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}${WWWDIR}/
	${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
