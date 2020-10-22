# $FreeBSD$

PORTNAME=	kanboard
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.16
CATEGORIES=	www
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	daniel.tihanyi@tetragir.com
COMMENT=	Simple visual task board software

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:flavors
USE_PHP=	ctype curl dom gd hash filter iconv json mcrypt mbstring \
		openssl pdo session simplexml zlib xml
USE_GITHUB=	yes

NO_BUILD=	yes
NO_ARCH=	yes

KANBOARD_USERNAME?=	www
KANBOARD_GROUPNAME?=	${KANBOARD_USERNAME}

PLIST_SUB=	KANBOARD_USERNAME=${KANBOARD_USERNAME} \
		KANBOARD_GROUPNAME=${KANBOARD_GROUPNAME}

OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	OPCACHE SQLITE
OPTIONS_DEFINE=		OPCACHE
OPCACHE_DESC=	OPcache support (recommended)

MYSQL_USES=	mysql
MYSQL_USE=	PHP=pdo_mysql,mysqli
PGSQL_USES=	pgsql
PGSQL_USE=	PHP=pdo_pgsql,pgsql
SQLITE_USE=	PHP=pdo_sqlite,sqlite3
OPCACHE_USE=	PHP=opcache

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
