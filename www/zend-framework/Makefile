# New ports collection makefile for:	zend-framework
# Date created:        31 October 2006
# Whom:                Greg Larkin <glarkin@sourcehosting.net>
#
# $FreeBSD$
#

PORTNAME=	ZendFramework
PORTVERSION=	1.0.0rc3
CATEGORIES=	www
MASTER_SITES=	http://framework.zend.com/releases/${DISTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/rc3/-RC3/}

MAINTAINER=	glarkin@sourcehosting.net
COMMENT=	A framework for developing PHP web applications

NO_BUILD=	yes
USE_PHP=	pcre
WANT_PHP_WEB=	yes
IGNORE_WITH_PHP=4

USE_GETTEXT=	yes

SUB_FILES=	pkg-message
SUB_LIST=	DATADIR=${DATADIR} LOCALBASE=${LOCALBASE}

WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS=	MYSQL "Install MySQL PDO support" Off \
		DBLIB "Install DBLIB PDO support" Off \
		PGSQL "Install PostgreSQL PDO support" Off \
		OCI "Install Oracle OCI 8 PDO support" Off \
		ODBC "Install ODBC PDO support" Off \
		SQLITE "Install SQLite v3 PDO support" Off

.include <bsd.port.pre.mk>

DB_DEFINED=	no

.if defined(WITH_MYSQL)
DB_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_mysql.so:${PORTSDIR}/databases/php5-pdo_mysql
DB_DEFINED=	yes
.endif

.if defined(WITH_DBLIB)
DB_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_dblib.so:${PORTSDIR}/databases/php5-pdo_dblib
DB_DEFINED=	yes
.endif

.if defined(WITH_PGSQL)
DB_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql
DB_DEFINED=	yes
.endif

.if defined(WITH_OCI)
DB_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_oci.so:${PORTSDIR}/databases/php5-pdo_oci
DB_DEFINED=	yes
.endif

.if defined(WITH_ODBC)
DB_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_odbc.so:${PORTSDIR}/databases/php5-pdo_odbc
DB_DEFINED=	yes
.endif

.if defined(WITH_SQLITE)
DB_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_sqlite.so:${PORTSDIR}/databases/php5-pdo_sqlite
DB_DEFINED=	yes
.endif

.if ${DB_DEFINED} == "yes"
USE_PHP+=	pdo
RUN_DEPENDS+=	${DB_DEPENDS}
.endif

# Fix USE_PHP after bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.php.mk"

do-install:
	@${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/* ${DATADIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DATADIR}
	${FIND} ${DATADIR} -type f -print | ${XARGS} -n1 ${CHMOD} 644
	${FIND} ${DATADIR} -type d -print | ${XARGS} -n1 ${CHMOD} 755

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
