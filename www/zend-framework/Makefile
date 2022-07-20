PORTNAME=	ZendFramework
PORTVERSION=	2.4.13
PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	https://packages.zendframework.com/releases/${DISTNAME}/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Framework for developing PHP web applications

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gettext php:web,flavors tar:tgz
USE_PHP=	spl

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

PORTDOCS=	CHANGELOG.md CONTRIBUTING.md INSTALL.md README-GIT.md README.md

OPTIONS_DEFINE=		DBLIB DOCS MEMCACHE MYSQL MYSQLI ODBC OPTPHP PGSQL \
			REQPHP SQLITE
OPTIONS_DEFAULT=	REQPHP

DBLIB_DESC=	Enable DBLIB PDO support
MEMCACHE_DESC=	Enable memcache support
MYSQLI_DESC=	Enable MySQLi support
OPTPHP_DESC=	Install optional PHP dependencies
REQPHP_DESC=	Install required PHP dependencies

DBLIB_USE=	PHP=pdo_dblib
MEMCACHE_USE=	PHP=memcache,memcached
MYSQLI_USE=	PHP=mysqli
MYSQL_USE=	PHP=pdo_mysql
ODBC_USE=	PHP=pdo_odbc
OPTPHP_USE=	PHP=bcmath,bitset,json,posix
PGSQL_USE=	PHP=pdo_pgsql
# Add all of the required and/or optional PHP extension dependencies,
# if chosen by the user.
REQPHP_USE=	PHP=ctype,curl,dom,gd,hash,iconv,ldap,mbstring,mcrypt,opcache,pcre,pdo,session,simplexml,soap,sqlite3,xml,zlib
SQLITE_USE=	PHP=pdo_sqlite

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "library bin resources" ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
