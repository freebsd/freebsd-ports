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

MASTERDIR=      ${.CURDIR}/../baculum-common

.include "${MASTERDIR}/Makefile"
