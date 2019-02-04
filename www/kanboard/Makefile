# $FreeBSD$

PORTNAME=	kanboard
PORTVERSION=	1.2.7
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	bsd@if0.eu
COMMENT=	Simple visual task board software

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php

NO_BUILD=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
USE_PHP=	ctype curl dom gd hash filter iconv json mcrypt mbstring \
		openssl pdo session simplexml \
		zlib xml

KANBOARD_USERNAME?=	www
KANBOARD_GROUPNAME?=	${KANBOARD_USERNAME}

PLIST_SUB=	KANBOARD_USERNAME=${KANBOARD_USERNAME} \
		KANBOARD_GROUPNAME=${KANBOARD_GROUPNAME}

OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	SQLITE
OPTIONS_DEFINE=		OPCACHE
OPCACHE_DESC=	OPcache support (recommended)

MYSQL_USE=	MYSQL=client PHP=mysql,pdo_mysql
PGSQL_USES=	pgsql
PGSQL_USE=	PHP=pdo_pgsql,pgsql
SQLITE_USE=	PHP=pdo_sqlite,sqlite3
OPCACHE_USE=	PHP=opcache

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
