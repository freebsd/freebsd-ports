# Created by: Richard Neese <r.neese@gmail.com>
# $FreeBSD$

PORTNAME=	fusionpbx
DISTVERSION=	3.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.fusionpbx.com/downloads/ \
		${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP5 Graphical User Interface for FreeSwitch

LICENSE=	MPL

LIB_DEPENDS=	libodbc.so:${PORTSDIR}/databases/unixODBC
RUN_DEPENDS+=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_odbc.so:${PORTSDIR}/databases/php${PHP_VER}-pdo_odbc

USE_PHP=	dom filter ftp json pcre pdo pdo_sqlite posix \
		session simplexml xml xmlreader xmlwriter xmlrpc \
		xsl zlib odbc
USE_SQLITE=	yes

DEFAULT_VERSIONS=php=5

VARBASE=	/var

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

OPTIONS_DEFINE=	PDOPGSQL PDOMYSQL

PDOPGSQL_DESC=	Install POSTGRESQL PDO Connector
PDOMYSQL_DESC=	Install MySQL PDO Connector

PDOPGSQL_USES=	pgsql
PDOPGSQL_USE=	PHP=pgsql,pdo_pgsql

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPDOMYSQL}
USE_MYSQL=	client
USE_PHP+=	mysql pdo_mysql
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@${FIND} ${WRKSRC} -name '*.php' -exec ${CHMOD} 644 {} +
	@cd ${WRKSRC}; ${FIND} . \
		| ${CPIO} -pdm -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${WWWDIR}
	@${CHOWN} -R www:www ${STAGEDIR}${WWWDIR}
	@${MKDIR} ${STAGEDIR}${VARBASE}/db/fusionpbx
	@${CHMOD} -R 0744 ${STAGEDIR}${VARBASE}/db/fusionpbx
	@${CHOWN} www:www ${STAGEDIR}${VARBASE}/db/fusionpbx

.include <bsd.port.mk>
