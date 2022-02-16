PORTNAME=	zabbix6
CATEGORIES=	net-mgmt
PKGNAMESUFFIX=	-frontend${PHP_PKGNAMESUFFIX}

USES+=		php:web,flavors
USE_PHP=	bcmath ctype dom fileinfo filter gd gettext hash json ldap \
		mbstring openssl pcre session simplexml snmp sockets xml \
		xmlreader xmlwriter

MASTERDIR=	${.CURDIR}/../${PORTNAME}-server
PATCHDIR=
NO_ARCH=	yes
NO_BUILD=	yes

PLIST=		${PKGDIR}/pkg-plist.frontend

OPTIONS_DEFINE=		MYSQLI ORACLE PGSQL
OPTIONS_DEFAULT=	MYSQLI
MYSQLI_DESC=		MySQLI backend

MYSQLI_USE=		PHP=mysqli
ORACLE_CONFIGURE_WITH=	oracle
PGSQL_USE=		PHP=pgsql

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/ui && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include "${MASTERDIR}/Makefile"
