# Created by: Jim Riggs <ports@christianserving.org>
# $FreeBSD$

PORTNAME=	zabbix2
PKGNAMESUFFIX=	-frontend
CATEGORIES=	net-mgmt

MASTERDIR=	${.CURDIR}/../zabbix2-server

NO_BUILD=	yes
PATCHDIR=
PLIST=		${PKGDIR}/pkg-plist.frontend

USE_PHP=	bcmath ctype gd pcre snmp sockets mbstring session dom xml \
		xmlreader xmlwriter simplexml gettext
WANT_PHP_WEB=	yes

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}${PKGNAMESUFFIX}/options
OPTIONS_DEFINE=	MYSQL MYSQLI PGSQL SQLITE
OPTIONS_DEFAULT=	MYSQL MYSQLI
MYSQLI_DESC=	MySQLI backend

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

do-install:
	@${INSTALL} -d ${WWWDIR}
	@cd ${WRKSRC}/frontends/php/ && ${COPYTREE_SHARE} . ${WWWDIR}

.include "${MASTERDIR}/Makefile"
