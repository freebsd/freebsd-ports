# Created by: Jim Riggs <ports@christianserving.org>
# $FreeBSD$

PORTNAME=	zabbix2
PKGNAMESUFFIX=	-frontend
CATEGORIES=	net-mgmt

MASTERDIR=	${.CURDIR}/../zabbix2-server

NO_BUILD=	yes
NO_ARCH=	yes
PATCHDIR=
PLIST=		${PKGDIR}/pkg-plist.frontend

USE_PHP=	bcmath ctype gd pcre snmp sockets mbstring session dom xml \
		xmlreader xmlwriter simplexml gettext ldap
USES=		php:web

OPTIONS_DEFINE=	MYSQL MYSQLI PGSQL SQLITE ORACLE
OPTIONS_DEFAULT=	MYSQL MYSQLI
MYSQLI_DESC=	MySQLI backend

MYSQL_VARS=	IGNORE_WITH_PHP+=70

MYSQL_USE=	PHP=mysql
MYSQLI_USE=	PHP=mysqli
PGSQL_USE=	PHP=pgsql
SQLITE_USE=	PHP=sqlite3

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MORACLE}
ZABBIX_REQUIRE=
CONFIGURE_ARGS+=	--with-oracle
.endif

do-install:
	@${INSTALL} -d ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC}/frontends/php/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include "${MASTERDIR}/Makefile"
