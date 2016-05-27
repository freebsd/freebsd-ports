# $FreeBSD$

PORTNAME=	kanboard
PORTVERSION=	1.0.28
CATEGORIES=	www
MASTER_SITES=	http://kanboard.net/ \
		https://bitbucket.org/if0/kanboard-archives/downloads/ \
		https://github.com/freebsd-kanboard/archives/blob/master/

MAINTAINER=	bsd@if0.eu
COMMENT=	Simple visual task board software

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
USES=		zip
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
	@${MKDIR} -m 0755 ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
