PORTNAME=	loganalyzer
PORTVERSION=	4.1.12
CATEGORIES=	sysutils www
MASTER_SITES=	http://download.adiscon.com/loganalyzer/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Web Syslog and IT Event Viewer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe php:web,flavors
CPE_VENDOR=	adiscon
NO_ARCH=	yes
NO_BUILD=	yes
ANALYZERDIR?=	www/loganalyzer
PLIST_SUB+=	ANALYZERDIR=${ANALYZERDIR}

OPTIONS_DEFINE=	PHP_MYSQL PDO_DBLIB PDO_FIREBIRD PDO_MYSQL PDO_ODBC PDO_PGSQL \
		PDO_SQLITE DOCS
PHP_MYSQL_DESC=		MySQL database support (PHP extension)
PDO_DBLIB_DESC=		Microsoft SQL Server and Sybase PDO driver
PDO_FIREBIRD_DESC=	Firebird/Interbase PDO driver
PDO_MYSQL_DESC=		MySQL Server PDO driver
PDO_ODBC_DESC=		ODBC and DB2 PDO driver
PDO_PGSQL_DESC=		PostgreSQL PDO driver
PDO_SQLITE_DESC=	SQLite PDO driver

.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	session pdo gd xml zlib
.endif

PHP_MYSQL_USE=	php=mysqli
PDO_DBLIB_RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_dblib.so:${PORTSDIR}/databases/php5-pdo_dblib
PDO_FIREBIRD_RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_firebird.so:${PORTSDIR}/databases/php5-pdo_firebird
PDO_MYSQL_USE=	php=pdo_mysql
PDO_ODBC_RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_odbc.so:${PORTSDIR}/databases/php5-pdo_odbc
PDO_PGSQL_RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
PDO_SQLITE_USE=	php=pdo_sqlite

pre-everything::
	@${ECHO_CMD} "# you can customize the installation directory"
	@${ECHO_CMD} "# by setting ANALYZERDIR in /etc/make.conf"

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${ANALYZERDIR}
	cd ${WRKSRC}/src/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/${ANALYZERDIR}/
	${INSTALL_DATA} ${WRKSRC}/src/.htaccess ${STAGEDIR}${PREFIX}/${ANALYZERDIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}/
	${TOUCH} ${STAGEDIR}${PREFIX}/${ANALYZERDIR}/config.php.sample

.include <bsd.port.mk>
