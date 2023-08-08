PORTNAME=	fusionpbx
PORTVERSION=	4.4.1
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	richard2891@gmail.com
COMMENT=	Web/PHP Interface for FreeSwitch
WWW=		https://www.fusionpbx.com

LICENSE=	MPL11

LIB_DEPENDS=	libodbc.so:databases/unixODBC
RUN_DEPENDS=	${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_odbc.so:databases/php${PHP_VER}-pdo_odbc \
		${LOCALBASE}/bin/freeswitch:net/freeswitch \
		${LOCALBASE}/bin/memcached:databases/memcached

USES=		cpe sqlite php fakeroot
USE_PHP=	phar pdo pdo_odbc pdo_sqlite gd imap \
		ldap sockets simplexml xml session odbc

USE_GITHUB=	yes

VARBASE=	var

NO_BUILD=	yes

OPTIONS_DEFINE=	PDOPGSQL

OPTIONS_DEFAULT=	PDOPGSQL

PDOPGSQL_DESC=	Install POSTGRESQL PDO Connector

PDOPGSQL_USES=	pgsql
PDOPGSQL_USE=	PHP=pgsql,pdo_pgsql

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	@${MKDIR} ${STAGEDIR}/${VARBASE}/db/fusionpbx

	@${MKDIR} ${STAGEDIR}/${VARBASE}/cache/fusionpbx
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}/secure

.include <bsd.port.mk>
