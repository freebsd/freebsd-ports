# New ports collection makefile for:	zabbix16-frontend
# Date created:		2009-12-10
# Whom:			Jim Riggs <ports@christianserving.org>
#
# $FreeBSD$
#

PORTNAME=	zabbix
PKGNAMESUFFIX=	-frontend

MASTERDIR=	${.CURDIR}/../zabbix16-server

NO_BUILD=	yes
PATCHDIR=
PLIST=		${PKGDIR}/pkg-plist.frontend

USE_PHP=	bcmath gd pcre snmp sockets
WANT_PHP_WEB=	yes

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}${PKGNAMESUFFIX}/options
OPTIONS=	MYSQL "Use MySQL backend" on \
		PGSQL "Use PostgreSQL backend" off \
		SQLITE "Use SQLite backend" off

.include <bsd.port.options.mk>

.ifndef WITHOUT_MYSQL
USE_PHP+=	mysql
.endif

.ifdef WITH_MYSQLI
USE_PHP+=	mysqli
.endif

.ifdef WITH_PGSQL
USE_PHP+=	pgsql
.endif

.ifdef WITH_SQLITE
USE_PHP+=	sqlite
.endif

do-install:
	@${INSTALL} -d ${WWWDIR}
	@cd ${WRKSRC}/frontends/php/ && ${COPYTREE_SHARE} . ${WWWDIR}

.include "${MASTERDIR}/Makefile"
