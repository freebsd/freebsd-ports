# New ports collection Makefile for: sysutils/phplogcon
# Date created:	        21 December 2008
# Whom:                 Cristiano Rolim Pereira <cristianorolim@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	loganalyzer
PORTVERSION=	3.4.5
CATEGORIES=	sysutils www
MASTER_SITES=	http://download.adiscon.com/loganalyzer/

MAINTAINER=	cristianorolim@outlook.com
COMMENT=	Web based Syslog browsing and analysis

NO_BUILD=	YES
ANALYZERDIR?=	www/loganalyzer
PLIST_SUB+=	ANALYZERDIR=${ANALYZERDIR}

pre-everything::
	@${ECHO_CMD} "# you can customize the installation directory"
	@${ECHO_CMD} "# by setting ANALYZER in /etc/make.conf"

OPTIONS=	PHP_MYSQL "MySQL database support (PHP extension)" Off \
		PDO_DBLIB "Microsoft SQL Server and Sybase PDO driver" Off \
		PDO_FIREBIRD "Firebird/Interbase PDO driver" Off \
		PDO_MYSQL "MySQL Server PDO driver" Off \
		PDO_ODBC "ODBC and DB2 PDO driver" Off \
		PDO_PGSQL "PostgreSQL PDO driver" Off \
		PDO_SQLITE "SQLite PDO driver" Off

.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	session pdo gd xml
WANT_PHP_WEB=	YES
IGNORE_WITH_PHP=4
DEFAULT_PHP_VER=5
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PHP_DEPENDS)
.if defined(WITH_PHP_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_PDO_DBLIB)
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_dblib.so:${PORTSDIR}/databases/php5-pdo_dblib
.endif

.if defined(WITH_PDO_FIREBIRD)
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_firebird.so:${PORTSDIR}/databases/php5-pdo_firebird
.endif

.if defined(WITH_PDO_MYSQL)
USE_PHP+=	pdo_mysql
.endif

.if defined(WITH_PDO_ODBC)
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_odbc.so:${PORTSDIR}/databases/php5-pdo_odbc
.endif

.if defined(WITH_PDO_PGSQL)
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
.endif

.if defined(WITH_PDO_SQLITE)
USE_PHP+=	pdo_sqlite
.endif
.endif

do-install:
	${MKDIR} ${PREFIX}/${ANALYZERDIR}
	${CP} -Rp ${WRKSRC}/src/ ${PREFIX}/${ANALYZERDIR}/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/* ${DOCSDIR}
.endif
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/* ${DATADIR}
.endif

.include <bsd.port.post.mk>
