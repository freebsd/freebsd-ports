PORTNAME=	kamailio
DISTVERSION=	5.8.5
CATEGORIES=	net
MASTER_SITES=	http://www.kamailio.org/pub/kamailio/${PORTVERSION}/src/
DISTNAME=	${PORTNAME}-${DISTVERSION}_src

MAINTAINER=	drtr0jan@yandex.ru
COMMENT=	Very fast and configurable open source SIP proxy
WWW=		https://www.kamailio.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

USES=		compiler:c11 cpe gmake ncurses pkgconfig python readline \
		shebangfix

USE_LDCONFIG=	yes
USE_RC_SUBR=	kamailio

SHEBANG_FILES=	utils/kamctl/dbtextdb/dbtextdb.py utils/kamctl/kamctl \
		utils/kamctl/kamdbctl

CFLAGS+=	-Wall

KAMAILIO_USER?=		kamailio
KAMAILIO_GROUP?=	kamailio
KAMAILIO_RUNDIR?=	/var/run/${PORTNAME}

SUB_LIST=	KAMAILIO_GROUP=${KAMAILIO_GROUP} \
		KAMAILIO_RUNDIR=${KAMAILIO_RUNDIR} \
		KAMAILIO_USER=${KAMAILIO_USER}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USERS=		${KAMAILIO_USER}
GROUPS=		${KAMAILIO_GROUP}

OPTIONS_DEFINE=			DIALPLAN DOCS EVAPI GCRYPT HTTP_CLIENT JWT \
				KAFKA LOST LWSC MICROHTTPD MQTT OUTBOUND PERL \
				PHONENUM PRESENCE RADIUS SCTP SIPREPO SLACK TLS \
				WEBSOCKET
OPTIONS_DEFAULT=		MYSQL PRESENCE RADIUS SQLITE TLS
OPTIONS_GROUP=			DATABASE_DRIVERS KEMI_LANGS
OPTIONS_GROUP_DATABASE_DRIVERS=	MYSQL PGSQL SQLITE UNIXODBC
OPTIONS_GROUP_KEMI_LANGS=	LUAJIT PYTHON3
OPTIONS_SUB=			YES

DATABASE_DRIVERS_DESC=	Database drivers
DIALPLAN_DESC=		String translations based on rules
EVAPI_DESC=		Network event broadcast API
GCRYPT_DESC=		Cryptography functions
HTTP_CLIENT_DESC=	HTTP-client module
JWT_DESC=		JSON Web Token generation and validation
KAFKA_DESC=		Produces and sends messages to a Kafka server
KEMI_LANGS_DESC=	Kamailio Embedded Interface Interpreters
LOST_DESC=		HELD (RFC6155) and LOST (RFC5222) location-based routing
LUAJIT_DESC=		Execute embedded Lua scripts
LWSC_DESC=		Websocket client connector using libwebsockets
MICROHTTPD_DESC=	Simple HTTP server implementation
MQTT_DESC=		MQTT connector for bi-directional publish-subscribe communication
OUTBOUND_DESC=		SIP Outbound support
PHONENUM_DESC=		Phone number lookup and normalization using libphonenumber
PRESENCE_DESC=		Presence support
PYTHON3_DESC=		Execute embedded Python3 scripts
SCTP_DESC=		SCTP support
SIPREPO_DESC=		In-memory SIP message storage
SLACK_DESC=		Connector to Slack channels
WEBSOCKET_DESC=		WebSocket transport layer

DIALPLAN_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
DIALPLAN_VARS=		EXTRA_MODULES+=dialplan

EVAPI_LIB_DEPENDS=	libev.so:devel/libev
EVAPI_VARS=		EXTRA_MODULES+=evapi

GCRYPT_LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
GCRYPT_VARS=		EXTRA_MODULES+=gcrypt

HTTP_CLIENT_LIB_DEPENDS=	libcurl.so:ftp/curl
HTTP_CLIENT_VARS=		EXTRA_MODULES+=http_client

JWT_LIB_DEPENDS=	libjwt.so:www/libjwt
JWT_VARS=		EXTRA_MODULES+=jwt

KAFKA_LIB_DEPENDS=	librdkafka.so:net/librdkafka
KAFKA_VARS=		EXTRA_MODULES+=kafka

LOST_LIB_DEPENDS=	libcurl.so:ftp/curl \
			libxml2.so:textproc/libxml2
LOST_VARS=		EXTRA_MODULES+=lost

LUAJIT_USES=		luajit
LUAJIT_MAKE_ARGS=	LUAJIT=yes
LUAJIT_VARS=		EXTRA_MODULES+=app_lua

LWSC_LIB_DEPENDS=	libwebsockets.so:net/libwebsockets
LWSC_VARS=		EXTRA_MODULES+=lwsc

MICROHTTPD_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd
MICROHTTPD_VARS=	EXTRA_MODULES+=microhttpd

MQTT_LIB_DEPENDS=	libev.so:devel/libev \
			libmosquitto.so:net/mosquitto
MQTT_VARS=		EXTRA_MODULES+=mqtt

MYSQL_LIB_DEPENDS=	libunwind.so:devel/libunwind
MYSQL_USES=		mysql
MYSQL_VARS=		EXTRA_MODULES+=db_mysql

OUTBOUND_USES=	ssl
OUTBOUND_VARS=	EXTRA_MODULES+=outbound

PERL_USES=	perl5
PERL_MAKE_ENV=	PERLCCOPTS="`perl -MExtUtils::Embed -e ccopts`" \
		PERLLDOPTS="`perl -MExtUtils::Embed -e ldopts`" \
		TYPEMAP="`perl -MConfig -e 'print $$Config{privlib}'`/ExtUtils/typemap"
PERL_VARS=	EXTRA_MODULES+="app_perl db_perlvdb"

PGSQL_USES=	pgsql
PGSQL_VARS=	EXTRA_MODULES+=db_postgres

PHONENUM_LIB_DEPENDS=	libphonenumber.so:devel/libphonenumber
PHONENUM_VARS=		EXTRA_MODULES+=phonenum

PRESENCE_LIB_DEPENDS=	libcurl.so:ftp/curl \
			libxml2.so:textproc/libxml2
PRESENCE_VARS=		EXTRA_GROUPS+=kpresence

PYTHON3_USES=		gettext-runtime
PYTHON3_MAKE_ARGS=	PYTHON3=${PYTHON_CMD}
PYTHON3_VARS=		EXTRA_MODULES+=app_python3

RADIUS_LIB_DEPENDS=	libradiusclient-ng.so:net/radiusclient
RADIUS_VARS=		EXTRA_GROUPS+=kradius

SCTP_VARS=	EXTRA_MODULES+=sctp

SIPREPO_VARS=	EXTRA_MODULES+=siprepo

SLACK_LIB_DEPENDS=	libcurl.so:ftp/curl
SLACK_VARS=		EXTRA_MODULES+=slack

SQLITE_USES=	sqlite
SQLITE_VARS=	EXTRA_MODULES+=db_sqlite

TLS_USES=	ssl
TLS_VARS=	EXTRA_MODULES+=tls

UNIXODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
UNIXODBC_VARS=		EXTRA_MODULES+=db_unixodbc

WEBSOCKET_LIB_DEPENDS=	libunistring.so:devel/libunistring
WEBSOCKET_USES=		ssl
WEBSOCKET_VARS=		EXTRA_MODULES+=websocket

.include <bsd.port.pre.mk>

DEFAULT_GROUPS=	default

CFG_ARGS+=	LIBDIR="lib" \
		run_target="${KAMAILIO_RUNDIR}"

.if !empty (EXTRA_GROUPS)
CFG_ARGS+=	group_include="${DEFAULT_GROUPS} ${EXTRA_GROUPS}"
.else
CFG_ARGS+=	group_include="${DEFAULT_GROUPS}"
.endif

.if !empty (EXTRA_MODULES)
CFG_ARGS+=	include_modules="${EXTRA_MODULES}"
.endif

post-patch-DOCS-off:
	@${REINPLACE_CMD} 's|install-doc install-man|install-man|' \
		${WRKSRC}/src/Makefile

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${CFG_ARGS} cfg

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install
	@(cd ${STAGEDIR}${ETCDIR}; for i in `${FIND} . -type f`; do ${MV} $$i $$i.sample; done)

post-install:
	@${RMDIR} ${STAGEDIR}${DATADIR} || true
	@${FIND} ${STAGEDIR}${PREFIX} -type f -name '*.so' -exec ${STRIP_CMD} {} +
	@${FIND} ${STAGEDIR}${PREFIX} -type f -name '*.so.1' -exec ${STRIP_CMD} {} +
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/kamailio
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/kamcmd

.include <bsd.port.post.mk>
