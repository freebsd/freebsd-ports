PORTNAME=	kamailio
PORTVERSION=	5.5.4
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.kamailio.org/pub/kamailio/${PORTVERSION}/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	Very fast and configurable open source SIP proxy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

USES=		compiler:c11 cpe gmake ncurses pkgconfig python:3.5+ readline \
		shebangfix

USE_LDCONFIG=	yes
USE_RC_SUBR=	kamailio

SHEBANG_FILES=	utils/kamctl/dbtextdb/dbtextdb.py utils/kamctl/kamctl \
		utils/kamctl/kamdbctl

MAKE_ARGS+=	LIBSSL_SET_MUTEX_SHARED=1
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

OPTIONS_DEFINE=			DATABASE DIALPLAN DOCS EVAPI JWT KAFKA LWSC \
				MQTT OUTBOUND PERL PHONENUM PRESENCE RADIUS \
				SCTP SECSIPID TLS WEBSOCKET
OPTIONS_DEFAULT=		MYSQL PRESENCE RADIUS SQLITE TLS
OPTIONS_GROUP=			DATABASE_DRIVERS KEMI_LANGS
OPTIONS_GROUP_DATABASE_DRIVERS=	MYSQL PGSQL SQLITE UNIXODBC
OPTIONS_GROUP_KEMI_LANGS=	LUAJIT PYTHON3
OPTIONS_SUB=			YES

DATABASE_DESC=		Database support
DATABASE_DRIVERS_DESC=	Database drivers
DIALPLAN_DESC=		String translations based on rules
EVAPI_DESC=		Network event broadcast API
JWT_DESC=		JSON Web Token generation and validation
KAFKA_DESC=		Produces and sends messages to a Kafka server
KEMI_LANGS_DESC=	Kamailio Embedded Interface Interpreters
LUAJIT_DESC=		Execute embedded Lua scripts
LWSC_DESC=		Websocket client connector using libwebsockets
MQTT_DESC=		MQTT connector for bi-directional publish-subscribe communication
OUTBOUND_DESC=		SIP Outbound support
PHONENUM_DESC=		Phone number lookup and normalization using libphonenumber
PRESENCE_DESC=		Presence support
PYTHON3_DESC=		Execute embedded Python3 scripts
SCTP_DESC=		SCTP support
SECSIPID_DESC=		Secure SIP/Telephony Identity (STIR/SHAKEN) extensions
WEBSOCKET_DESC=		WebSocket transport layer

DATABASE_VARS=	EXTRA_GROUPS+=db

DIALPLAN_LIB_DEPENDS=	libpcre.so:devel/pcre
DIALPLAN_VARS=		EXTRA_MODULES+=dialplan

EVAPI_LIB_DEPENDS=	libev.so:devel/libev
EVAPI_VARS=		EXTRA_MODULES+=evapi

JWT_LIB_DEPENDS=	libjwt.so:www/libjwt
JWT_VARS=		EXTRA_MODULES+=jwt

KAFKA_LIB_DEPENDS=	librdkafka.so:net/librdkafka
KAFKA_VARS=		EXTRA_MODULES+=kafka

LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
LUAJIT_MAKE_ARGS=	LUAJIT=yes
LUAJIT_VARS=		EXTRA_MODULES+=app_lua

LWSC_LIB_DEPENDS=	libwebsockets.so:net/libwebsockets
LWSC_VARS=		EXTRA_MODULES+=lwsc

MQTT_LIB_DEPENDS=	libev.so:devel/libev \
			libmosquitto.so:net/mosquitto
MQTT_VARS=		EXTRA_MODULES+=mqtt

MYSQL_IMPLIES=	DATABASE
MYSQL_USES=	mysql
MYSQL_VARS=	EXTRA_GROUPS+=mysql

OUTBOUND_VARS=	EXTRA_MODULES+=outbound

PERL_USES=	perl5
PERL_MAKE_ENV=	PERLCCOPTS="`perl -MExtUtils::Embed -e ccopts`" \
		PERLLDOPTS="`perl -MExtUtils::Embed -e ldopts`" \
		TYPEMAP="`perl -MConfig -e 'print $$Config{privlib}'`/ExtUtils/typemap"
PERL_VARS=	EXTRA_MODULES+=app_perl

PGSQL_IMPLIES=	DATABASE
PGSQL_USES=	pgsql
PGSQL_VARS=	EXTRA_GROUPS+=postgres

PHONENUM_LIB_DEPENDS=	libphonenumber.so:devel/libphonenumber
PHONENUM_VARS=		EXTRA_MODULES+=phonenum

PRESENCE_LIB_DEPENDS=	libcurl.so:ftp/curl \
			libxml2.so:textproc/libxml2
PRESENCE_VARS=		EXTRA_GROUPS+=presence

PYTHON3_USES=		gettext-runtime
PYTHON3_MAKE_ARGS=	PYTHON3=${PYTHON_CMD}
PYTHON3_VARS=		EXTRA_MODULES+=app_python3

RADIUS_LIB_DEPENDS=	libradiusclient-ng.so:net/radiusclient
RADIUS_VARS=		EXTRA_GROUPS+=radius

SCTP_VARS=	EXTRA_MODULES+=sctp

SECSIPID_VARS=	EXTRA_MODULES+=secsipid

SQLITE_IMPLIES=	DATABASE
SQLITE_USES=	sqlite
SQLITE_VARS=	EXTRA_MODULES+=db_sqlite

TLS_USES=	ssl
TLS_VARS=	EXTRA_MODULES+=tls

UNIXODBC_IMPLIES=	DATABASE
UNIXODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
UNIXODBC_VARS=		EXTRA_MODULES+=db_unixodbc

WEBSOCKET_LIB_DEPENDS=	libunistring.so:devel/libunistring
WEBSOCKET_VARS=		EXTRA_MODULES+=websocket

.include <bsd.port.pre.mk>

DEFAULT_GROUPS=	standard

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
