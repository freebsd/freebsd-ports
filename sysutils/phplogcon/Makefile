# New ports collection Makefile for: sysutils/phplogcon
# Date created:	        21 December 2008
# Whom:                 Cristiano Rolim Pereira <cristianorolim@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	phplogcon
PORTVERSION=	2.7.2
CATEGORIES=	sysutils www
MASTER_SITES=	http://download.adiscon.com/phplogcon/

MAINTAINER=	cristianorolim@hotmail.com
COMMENT=	Web Based Syslog Review

NO_BUILD=	YES
LOGCONDIR?=	www/phplogcon
PLIST_SUB+=	LOGCONDIR=${LOGCONDIR}

pre-everything::
	@${ECHO_CMD} "# you can customize the installation directory"
	@${ECHO_CMD} "# by setting LOGCON in /etc/make.conf"

OPTIONS=	PHP_MYSQL "MySQL database support (PHP extension)" Off \
		PDO_DBLIB "Microsoft SQL Server and Sybase PDO driver" Off \
		PDO_FIREBIRD "Firebird/Interbase PDO driver" Off \
		PDO_MYSQL "MySQL Server PDO driver" Off \
		PDO_OCI "Oracle PDO driver (i386 onnly)" Off \
		PDO_ODBC "ODBC and DB2 PDO driver" Off \
		PDO_PGSQL "PostgreSQL PDO driver" Off \
		PDO_SQLITE "SQLite PDO driver" Off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	session pdo gd xml
WANT_PHP_WEB=	YES
IGNORE_WITH_PHP=4
DEFAULT_PHP_VER=5

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

.if defined(WITH_PDO_OCI) && ${ARCH} == "i386"
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_oci.so:${PORTSDIR}/databases/php5-pdo_oci
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
	${MKDIR} ${PREFIX}/${LOGCONDIR}
	${CP} -Rp ${WRKSRC}/src/ ${PREFIX}/${LOGCONDIR}/

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
