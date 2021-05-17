PORTNAME=	zabbix54
CATEGORIES=	net-mgmt
PKGNAMESUFFIX=	-frontend

MASTERDIR=	${.CURDIR}/../${PORTNAME}-server

NO_BUILD=	yes
NO_ARCH=	yes
PATCHDIR=
PLIST=		${PKGDIR}/pkg-plist.frontend

USE_PHP=	bcmath ctype dom fileinfo filter gd gettext hash json ldap mbstring \
		openssl pcre session simplexml snmp sockets xml xmlreader xmlwriter
USES+=		php:web

OPTIONS_DEFINE=		MYSQLI PGSQL ORACLE
OPTIONS_DEFAULT=	MYSQLI
MYSQLI_DESC=		MySQLI backend

MYSQLI_USE=	PHP=mysqli

PGSQL_USE=	PHP=pgsql

ORACLE_CONFIGURE_WITH=	oracle

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/ui && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include "${MASTERDIR}/Makefile"
