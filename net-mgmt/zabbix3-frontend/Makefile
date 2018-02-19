# Created by: Pakhom Golynga <pg@pakhom.spb.ru>
# $FreeBSD$

PORTNAME=	zabbix3
CATEGORIES=	net-mgmt
PKGNAMESUFFIX=	-frontend

MASTERDIR=	${.CURDIR}/../zabbix3-server

NO_BUILD=	yes
NO_ARCH=	yes
PATCHDIR=
PLIST=		${PKGDIR}/pkg-plist.frontend

USE_PHP=	bcmath ctype dom gd gettext json ldap mbstring pcre \
		session simplexml snmp sockets xml xmlreader xmlwriter

USES=	php:web gettext

OPTIONS_DEFINE=		MYSQL MYSQLI PGSQL SQLITE ORACLE
OPTIONS_DEFAULT=	MYSQLI
MYSQLI_DESC=		MySQLI backend

MYSQL_VARS=	IGNORE_WITH_PHP+="70 71"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MMYSQLI}
USE_PHP+=	mysqli
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_PHP+=	sqlite3
.endif

.if ${PORT_OPTIONS:MORACLE}
ZABBIX_REQUIRE=
CONFIGURE_ARGS+=	--with-oracle
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/frontends/php && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include "${MASTERDIR}/Makefile"
