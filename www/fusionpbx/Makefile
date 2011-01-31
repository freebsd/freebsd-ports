# Ports collection makefile for: fusionpbx
# Date created: Jan 12, 2011
# Whom: Richard Neese <r.neese@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fusionpbx
PORTVERSION=	1.2.0
CATEGORIES=	www
MASTER_SITES=	http://www.fusionpbx.com/downloads/ \
		${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	r.neese@gmail.com
COMMENT=	Fusionpbx PHP5 Graphical User Interface for FreeSwitch

RUN_DEPENDS=    ${LOCALBASE}/bin/freeswitch:${PORTSDIR}/net/freeswitch

USE_SQLITE=	yes

USE_PHP=	dom filter ftp json pcre pdo pdo_sqlite posix \
		session simplexml xml xmlreader xmlwriter xmlrpc \
		xsl zlib

DEFAULT_PHP_VER=	5
IGNORE_WITH_PHP=	4

.if defined(WITH_APACHE22)
WANT_PHP_WEB=	yes
.else
WANT_PHP_CLI=   yes
.endif

VARBASE?=	/var

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

SUB_FILES=	pkg-message

#config options
OPTIONS=	PGSQLCLIENT	"Install and use POSTGRESQL Connector Client" off \
		MYSQLCLIENT	"Install and use MySQL Connector Client" off \
		APACHE22	"Install APACHE 2.2 Web Server" off \
		NGINX		"Install Nginx Web Server (Default)" on \
		PHP5ODBC	"Install PHP5 ODBC Connctors" off

.include <bsd.port.options.mk>

.if !defined(WITH_PGSQLCLIENT)
PLIST_SUB+=	WITH_PGSQLCLIENT="@comment "
.else
USE_PGSQL=	yes
USE_PHP+=	pgsql pdo_pgsql
PLIST_SUB+=	WITH_PGSQLCLIENT=""
.endif

.if !defined(WITH_MYSQLCLIENT)
PLIST_SUB+=	WITH_MYSQLCLIENT="@comment "
.else
USE_MYSQL=	client
USE_PHP+=       mysql pdo_mysql
PLIST_SUB+=	WITH_MYSQLCLIENT=""
.endif

.if !defined(WITH_NGINX)
PLIST_SUB+=	WITH_NGINX="@comment "
.else
PLIST_SUB+=	WITH_NGINX=""
RUN_DEPENDS+=	nginx:${PORTSDIR}/www/nginx-devel
.endif

.if !defined(WITH_APACHE22)
PLIST_SUB+=	WITH_APACHE22="@comment "
.else
PLIST_SUB+=	WITH_APACHE22=""
USE_APACHE=	22+
.endif

.if !defined(WITH_PHP5ODBC)
PLIST_SUB+=	WITH_PHP5ODBC="@comment "
.else
USE_PHP+=	odbc pdo_odbc
PLIST_SUB+=	WITH_PHP5ODBC=""
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

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
