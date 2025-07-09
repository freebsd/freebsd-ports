PORTNAME=	kamailio
DISTVERSION=	6.0.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.kamailio.org/pub/kamailio/${PORTVERSION}/src/
DISTNAME=	${PORTNAME}-${DISTVERSION}_src

MAINTAINER=	drtr0jan@yandex.ru
COMMENT=	Very fast and configurable open source SIP proxy
WWW=		https://www.kamailio.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xsltproc:textproc/libxslt

USES=		bison cmake compiler:c11 cpe pkgconfig python:build readline \
		shebangfix

USE_LDCONFIG=	yes
USE_RC_SUBR=	kamailio

SHEBANG_FILES=	utils/kamctl/dbtextdb/dbtextdb.py utils/kamctl/kamctl \
		utils/kamctl/kamdbctl

ALL_TARGET=	all dbschema man

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
				KAFKA LOST LWSC MICROHTTPD MQTT NGHTTP2 \
				OUTBOUND PERL PHONENUM PRESENCE RADIUS SCTP \
				SIPREPO SLACK TLS WEBSOCKET
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
NGHTTP2_DESC=		HTTP2 server module implementation
OUTBOUND_DESC=		SIP Outbound support
PHONENUM_DESC=		Phone number lookup and normalization using libphonenumber
PRESENCE_DESC=		Presence support
PYTHON3_DESC=		Execute embedded Python3 scripts
SCTP_DESC=		SCTP support
SIPREPO_DESC=		In-memory SIP message storage
SLACK_DESC=		Connector to Slack channels

DIALPLAN_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2
DIALPLAN_VARS=		EXTRA_MODULES+=dialplan

DOCS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-cmake_modules-docs.cmake \
			${PATCHDIR}/extra-patch-src_CMakeLists.txt

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
LUAJIT_CMAKE_BOOL=	LUAJIT
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

NGHTTP2_LIB_DEPENDS=	libevent.so:devel/libevent \
			libnghttp2.so:www/libnghttp2
NGHTTP2_VARS=		EXTRA_MODULES+=nghttp2

OUTBOUND_USES=	ssl
OUTBOUND_VARS=	EXTRA_MODULES+=outbound

PERL_USES=	perl5
PERL_CMAKE_ON=	-DPERLCCOPTS="`perl -MExtUtils::Embed -e ccopts`" \
		-DPERLLDOPTS="`perl -MExtUtils::Embed -e ldopts`" \
		-DTYPEMAP="`perl -MConfig -e 'print $$Config{privlib}'`/ExtUtils/typemap"
PERL_VARS=	EXTRA_MODULES+="app_perl db_perlvdb"

PGSQL_USES=	pgsql
PGSQL_VARS=	EXTRA_MODULES+=db_postgres

PHONENUM_LIB_DEPENDS=	libphonenumber.so:devel/libphonenumber
PHONENUM_VARS=		EXTRA_MODULES+=phonenum

PRESENCE_LIB_DEPENDS=	libcurl.so:ftp/curl \
			libicuuc.so:devel/icu \
			libxml2.so:textproc/libxml2
PRESENCE_VARS=		EXTRA_MODULES+="presence presence_conference presence_dfks presence_dialoginfo presence_mwi presence_profile presence_reginfo presence_xml pua pua_bla pua_dialoginfo pua_reginfo pua_rpc pua_usrloc pua_xmpp rls xcap_client xcap_server"

PYTHON3_USES=	gettext-runtime python
PYTHON3_VARS=	EXTRA_MODULES+=app_python3

RADIUS_LIB_DEPENDS=	libradcli.so:net/radcli
RADIUS_VARS=		EXTRA_MODULES+="acc_radius auth_radius misc_radius peering"

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

.if !empty (EXTRA_MODULES)
CMAKE_ARGS+=	-DINCLUDE_MODULES="${EXTRA_MODULES}"
.endif

post-install:
	@(cd ${STAGEDIR}${ETCDIR}; for i in `${FIND} . -type f`; do ${MV} $$i $$i.sample; done)

.include <bsd.port.post.mk>
