# Created by: Sergey Osipov <sipopo@yandex.ru>

PKGNAMESUFFIX=	-api

COMMENT=	Baculum API

LICENSE=	AGPLv3

RUN_DEPENDS=	baculum-common>0:www/baculum-common

PLIST=		${.CURDIR}/pkg-plist

OPTIONS_DEFINE=	MYSQL PGSQL
OPTIONS_DEFAULT=PGSQL

MYSQL_DESC=	Enable MySQL PDO support
PGSQL_DESC=	Enable PostgreSQL PDO support

USE_PHP=	bcmath pdo

.if !empty(PORT_OPTIONS:MMYSQL)
USE_PHP+=	pdo_mysql
.endif

.if !empty(PORT_OPTIONS:MPGSQL)
USE_PHP+=	pdo_pgsql
.endif

MASTERDIR=	${.CURDIR}/../baculum-common

.include "${MASTERDIR}/Makefile"
