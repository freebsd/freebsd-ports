PORTNAME=	kanboard
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.46
CATEGORIES=	www
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple visual task board software
WWW=		https://kanboard.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}

USES=		cpe php:flavors python
USE_GITHUB=	yes
USE_PHP=	ctype curl dom filter gd iconv mbstring mcrypt \
		pdo session simplexml xml zlib

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_SUB=	KANBOARD_GROUPNAME=${KANBOARD_GROUPNAME} \
		KANBOARD_USERNAME=${KANBOARD_USERNAME}

OPTIONS_DEFINE=		OPCACHE
OPTIONS_DEFAULT=	OPCACHE SQLITE
OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE

OPCACHE_DESC=	OPcache support (recommended)

MYSQL_USES=	mysql
MYSQL_USE=	PHP=mysqli,pdo_mysql
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
