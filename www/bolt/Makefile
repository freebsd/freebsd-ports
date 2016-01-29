# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bolt
PORTVERSION=	2.2.17
PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	https://bolt.cm/distribution/

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Sophisticated, lightweight & simple CMS

LICENSE=	MIT

NO_ARCH=	yes
NO_BUILD=	yes
USE_PHP=	ctype curl dom gd json mbstring openssl simplexml tokenizer
WANT_PHP_WEB=	yes

PLIST_SUB+=	WWWGRP=${WWWGRP}

OPTIONS_DEFINE=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	SQLITE

MYSQL_USE=	PHP=pdo_mysql
PGSQL_USE=	PHP=pdo_pgsql
SQLITE_USE=	PHP=pdo_sqlite

do-install:
	${INSTALL} -d -m 755 ${STAGEDIR}${WWWDIR}/
	${CP} -R ${WRKSRC}/ ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
