# Ports collection makefile for: fusionpbx
# Date created: Jan 12, 2011
# Whom: Richard Neese <r.neese@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fusionpbx
DISTVERSION=	3.0.4
CATEGORIES=	www
MASTER_SITES=	http://www.fusionpbx.com/downloads/ \
		${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	r.neese@gmail.com
COMMENT=	Fusionpbx PHP5 Graphical User Interface for FreeSwitch

LIB_DEPENDS=	odbc:${PORTSDIR}/databases/unixODBC
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_odbc.so:${PORTSDIR}/databases/php5-pdo_odbc

USE_SQLITE=	yes

USE_PHP=	dom filter ftp json pcre pdo pdo_sqlite posix \
		session simplexml xml xmlreader xmlwriter xmlrpc \
		xsl zlib odbc

DEFAULT_PHP_VER=	5
IGNORE_WITH_PHP=	4

VARBASE=	/var

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

#config options
OPTIONS=	PDOPGSQL	"Install POSTGRESQL PDO Connecor" off \
		PDOMYSQL	"Install MySQL PDO Connector " off

.include <bsd.port.options.mk>

.if !defined(WITH_PDOPGSQL)
PLIST_SUB+=	WITH_PDOPGSQL="@comment "
.else
USE_PGSQL=	yes
USE_PHP+=	pgsql pdo_pgsql
PLIST_SUB+=	WITH_PDOPGSQL=""
.endif

.if !defined(WITH_PDOMYSQL)
PLIST_SUB+=	WITHPDO-MYSQL="@comment "
.else
USE_MYSQL=	client
USE_PHP+=	mysql pdo_mysql
PLIST_SUB+=	WITH_PDOMYSQL=""
.endif

do-install:
	@${MKDIR} ${WWWDIR}
	@${FIND} ${WRKSRC} -name '*.php' -exec ${CHMOD} 644 {} +
	@cd ${WRKSRC}; ${FIND} . \
		| ${CPIO} -pdm -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHOWN} -R www:www ${WWWDIR}
	@${MKDIR} ${VARBASE}/db/fusionpbx
	@${CHMOD} -R 0744 ${VARBASE}/db/fusionpbx
	@${CHOWN} www:www ${VARBASE}/db/fusionpbx

.include <bsd.port.mk>
