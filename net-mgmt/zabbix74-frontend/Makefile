PORTNAME=	zabbix74
PORTREVISION=	0
CATEGORIES=	net-mgmt
PKGNAMESUFFIX=	-frontend${PHP_PKGNAMESUFFIX}

USES+=		php:web,flavors
USE_PHP=	bcmath ctype filter gd gettext ldap mbstring session \
		simplexml sockets xml xmlreader xmlwriter

MASTERDIR=	${.CURDIR}/../${PORTNAME}-server
PATCHDIR=
NO_ARCH=	yes
NO_BUILD=	yes

PLIST=		${PKGDIR}/pkg-plist.frontend

OPTIONS_DEFINE=		MYSQLI PGSQL
OPTIONS_DEFAULT=	MYSQLI
MYSQLI_DESC=		MySQLI backend

MYSQLI_USE=		PHP=mysqli
PGSQL_USE=		PHP=pgsql

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/ui && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include "${MASTERDIR}/Makefile"
