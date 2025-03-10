PORTNAME=	fusionpbx
PORTVERSION=	5.3.0
CATEGORIES=	www

MAINTAINER=	richard2891@gmail.com
COMMENT=	Web/PHP Interface for FreeSwitch
WWW=		https://www.fusionpbx.com

LICENSE=	MPL11

LIB_DEPENDS=	libodbc.so:databases/unixODBC
RUN_DEPENDS=	${LOCALBASE}/bin/freeswitch:net/freeswitch \
		${LOCALBASE}/bin/memcached:databases/memcached \
		${PHPBASE}/lib/php/${PHP_EXT_DIR}/pdo_odbc.so:databases/php${PHP_VER}-pdo_odbc

USES=		cpe fakeroot php sqlite
USE_GITHUB=	yes
USE_PHP=	gd imap ldap odbc pdo pdo_odbc pdo_sqlite phar session \
		simplexml sockets xml

VARBASE=	var

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	PDOPGSQL

OPTIONS_DEFAULT=	PDOPGSQL

PDOPGSQL_DESC=	Install POSTGRESQL PDO Connector

PDOPGSQL_USES=	pgsql
PDOPGSQL_USE=	PHP=pdo_pgsql,pgsql

.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	@${MKDIR} ${STAGEDIR}/${VARBASE}/db/fusionpbx

	@${MKDIR} ${STAGEDIR}/${VARBASE}/cache/fusionpbx
	@${CHMOD} -R 755 ${STAGEDIR}${WWWDIR}/secure

.include <bsd.port.mk>
