PORTNAME=	opensips31
DISTVERSION=	3.1.10
CATEGORIES=	net
MASTER_SITES=	https://opensips.org/pub/opensips/${DISTVERSION}/
DISTNAME=	opensips-${DISTVERSION}

MAINTAINER=	bambyster@gmail.com
COMMENT=	Open SIP Server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gm4:devel/m4
LIB_DEPENDS=	libconfuse.so:devel/libconfuse \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libjson-c.so:devel/json-c \
		libjwt.so:www/libjwt \
		libpcre.so:devel/pcre \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		gettext-runtime gmake gnome localbase:ldflags ncurses perl5 \
		pkgconfig shebangfix ssl
USE_GNOME=	libxml2
SHEBANG_GLOB=	*.pl *.sh

USE_RC_SUBR=	${PORTNAME}

USERS=		opensips
GROUPS=		opensips

CFLAGS+=	-pthread
CXXFLAGS+=	-pthread
LDFLAGS+=	-pthread

MAKE_ENV+=	BASEDIR=${STAGEDIR} \
		INSTALL_BIN="${INSTALL_PROGRAM}" \
		INSTALL_CFG="${INSTALL_DATA}" \
		INSTALL_DOC="${INSTALL_DATA}" \
		INSTALL_MODULES="${INSTALL_PROGRAM}" \
		JSON_BUILDER="pkgconf json-c" \
		NICER=0

OPTIONS_DEFINE=		DEBUG DOCS EXAMPLES HTTP LDAP MEMCACHED MYSQL PGSQL \
			PYTHON RABBITMQ RADIUS REDIS SQLITE TESTS TLS UNIXODBC
OPTIONS_DEFAULT=	HTTP LDAP MEMCACHED PGSQL PYTHON RABBITMQ RADIUS REDIS TLS
OPTIONS_SUB=		yes

HTTP_DESC=		Enable HTTP transport via libmicrohttpd
MEMCACHED_DESC=		Build with memcached support
RABBITMQ_DESC=		RabbitMQ/AMQP support
TESTS_DESC=		Install smoke tests

HTTP_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd
HTTP_VARS=		EXTRA_MODULES+=httpd

LDAP_USE=		OPENLDAP=yes
LDAP_VARS=		EXTRA_MODULES+="ldap h350"

MEMCACHED_LIB_DEPENDS=	libmemcached.so:databases/libmemcached
MEMCACHED_VARS=		EXTRA_MODULES+=cachedb_memcached

MYSQL_USES=		mysql:client
MYSQL_VARS=		EXTRA_MODULES+=db_mysql

PGSQL_BUILD_DEPENDS=	p5-DBD-Pg>=3.4:databases/p5-DBD-Pg
PGSQL_USES=		pgsql
WANT_PGSQL=		client
PGSQL_VARS=		EXTRA_MODULES+=db_postgres

PYTHON_USES=		python
PYTHON_MAKE_ENV=	PYTHON=${PYTHON_CMD}
PYTHON_VARS=		EXTRA_MODULES+=python

RABBITMQ_LIB_DEPENDS=	librabbitmq.so:net/rabbitmq-c-devel
RABBITMQ_VARS=		EXTRA_MODULES+="event_rabbitmq rabbitmq rabbitmq_consumer"

RADIUS_LIB_DEPENDS=	libradiusclient-ng.so:net/radiusclient
RADIUS_VARS=		EXTRA_MODULES+=aaa_radius

REDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis
REDIS_VARS=		EXTRA_MODULES+=cachedb_redis

SQLITE_LIB_DEPENDS=	libsqlite3.so:databases/sqlite3
SQLITE_VARS=		EXTRA_MODULES+=db_sqlite

TLS_VARS=		EXTRA_MODULES+="proto_tls proto_wss tls_mgm"

UNIXODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
UNIXODBC_VARS=		EXTRA_MODULES+=db_unixodbc

.include <bsd.port.options.mk>

post-patch:
	@(${CP} files/Makefile.conf ${WRKSRC})
.for i in ${EXTRA_MODULES}
	@${REINPLACE_CMD} -e "s/\(^include_modules=.*\)/\1 ${i}/" ${WRKSRC}/Makefile.conf
.endfor

do-configure-DEBUG-off:
	@${REINPLACE_CMD} -e "s/^#DEFS+= -DNO_DEBUG/DEFS+= -DNO_DEBUG/" ${WRKSRC}/Makefile.conf

do-install-TESTS-on:
	${CP} -r ${WRKSRC}/test ${STAGEDIR}${PREFIX}/tests/${PORTNAME}

do-install-EXAMPLES-on:
	${CP} -r ${WRKSRC}/examples ${STAGEDIR}${PREFIX}/share/examples/${PORTNAME}

post-install-RADIUS-on:
	${MV} ${STAGEDIR}${ETCDIR}/dictionary.opensips ${STAGEDIR}${ETCDIR}/dictionary.opensips.sample

.include <bsd.port.mk>
