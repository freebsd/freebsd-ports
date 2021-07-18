PORTNAME=	kanboard
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.19
CATEGORIES=	www
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	daniel.tihanyi@tetragir.com
COMMENT=	Simple visual task board software

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:flavors
USE_GITHUB=	yes
USE_PHP=	ctype curl dom gd hash filter iconv json mcrypt mbstring \
		openssl pdo session simplexml zlib xml

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_SUB=	KANBOARD_USERNAME=${KANBOARD_USERNAME} \
		KANBOARD_GROUPNAME=${KANBOARD_GROUPNAME}

OPTIONS_DEFINE=		OPCACHE
OPTIONS_DEFAULT=	OPCACHE SQLITE
OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE

OPCACHE_DESC=	OPcache support (recommended)

MYSQL_USES=	mysql
MYSQL_USE=	PHP=pdo_mysql,mysqli
OPCACHE_USE=	PHP=opcache
PGSQL_USES=	pgsql
PGSQL_USE=	PHP=pdo_pgsql,pgsql
SQLITE_USE=	PHP=pdo_sqlite,sqlite3

KANBOARD_GROUPNAME?=	${KANBOARD_USERNAME}
KANBOARD_USERNAME?=	www

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
