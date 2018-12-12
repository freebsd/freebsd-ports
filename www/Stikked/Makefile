# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Stikked
DISTVERSION=	0.13.0
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	PHP-based Pastebin, with a simple and easy to use user interface

USES=		php:web

USE_GITHUB=	yes
GH_ACCOUNT=	claudehohl

USE_PHP=	ctype filter gd pgsql session

NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message

OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=	PGSQL

MYSQL_DESC=	Include the PHP shared extension for MySQL
PGSQL_DESC=	Include the PHP shared extension for PostgreSQL
SQLITE_DESC=	Include the PHP shared extension for SQLite3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	sqlite3
.endif

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/htdocs && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	${INSTALL_DATA} ${STAGEDIR}${WWWDIR}/application/config/stikked.php.dist ${STAGEDIR}${ETCDIR}/stikked.php.sample
	${LN} -sf ${ETCDIR}/stikked.php ${STAGEDIR}${WWWDIR}/application/config/

.include <bsd.port.mk>
