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

USE_PHP=	bcmath ctype gd pcre snmp sockets mbstring session dom xml \
		xmlreader xmlwriter simplexml gettext ldap
WANT_PHP_WEB=	yes

OPTIONS_DEFINE=		MYSQL MYSQLI PGSQL SQLITE ORACLE
OPTIONS_DEFAULT=	MYSQL MYSQLI
MYSQLI_DESC=		MySQLI backend

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
CONFIGURE_ARGS+=        --with-oracle
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/frontends/php && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include "${MASTERDIR}/Makefile"
