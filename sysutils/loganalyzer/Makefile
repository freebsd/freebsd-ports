# Created by: Cristiano Rolim Pereira <cristianorolim@outlook.com>
# $FreeBSD$

PORTNAME=	loganalyzer
PORTVERSION=	3.6.3
CATEGORIES=	sysutils www
MASTER_SITES=	http://download.adiscon.com/loganalyzer/

MAINTAINER=	cristianorolim@outlook.com
COMMENT=	Web based Syslog browsing and analysis

NO_BUILD=	YES
ANALYZERDIR?=	www/loganalyzer
PLIST_SUB+=	ANALYZERDIR=${ANALYZERDIR}

OPTIONS_DEFINE=	PHP_MYSQL PDO_DBLIB PDO_FIREBIRD PDO_MYSQL PDO_ODBC PDO_PGSQL \
	PDO_SQLITE
PHP_MYSQL_DESC=		MySQL database support (PHP extension)
PDO_DBLIB_DESC=		Microsoft SQL Server and Sybase PDO driver
PDO_FIREBIRD_DESC=	Firebird/Interbase PDO driver
PDO_MYSQL_DESC=		MySQL Server PDO driver
PDO_ODBC_DESC=		ODBC and DB2 PDO driver
PDO_PGSQL_DESC=		PostgreSQL PDO driver
PDO_SQLITE_DESC=	SQLite PDO driver

USE_PHP=	session pdo gd xml zlib
WANT_PHP_WEB=	YES
DEFAULT_PHP_VER=5

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPHP_MYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MPDO_DBLIB}
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_dblib.so:${PORTSDIR}/databases/php5-pdo_dblib
.endif

.if ${PORT_OPTIONS:MPDO_FIREBIRD}
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_firebird.so:${PORTSDIR}/databases/php5-pdo_firebird
.endif

.if ${PORT_OPTIONS:MPDO_MYSQL}
USE_PHP+=	pdo_mysql
.endif

.if ${PORT_OPTIONS:MPDO_ODBC}
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_odbc.so:${PORTSDIR}/databases/php5-pdo_odbc
.endif

.if ${PORT_OPTIONS:MPDO_PGSQL}
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
.endif

.if ${PORT_OPTIONS:MPDO_SQLITE}
USE_PHP+=	pdo_sqlite
.endif

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_CMD} "# you can customize the installation directory"
	@${ECHO_CMD} "# by setting ANALYZERDIR in /etc/make.conf"

do-install:
	${MKDIR} ${PREFIX}/${ANALYZERDIR}
	cd ${WRKSRC}/src/ && ${COPYTREE_SHARE} \* ${PREFIX}/${ANALYZERDIR}/
	${INSTALL_DATA} ${WRKSRC}/src/.htaccess ${PREFIX}/${ANALYZERDIR}/

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/* ${DATADIR}
.endif

.include <bsd.port.post.mk>
