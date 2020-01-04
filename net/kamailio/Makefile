# Created by: Oliver Mahmoudi <olivermahmoudi@gmail.com>
# $FreeBSD$

PORTNAME=	kamailio
PORTVERSION=	5.3.1
CATEGORIES=	net
MASTER_SITES=	http://www.kamailio.org/pub/kamailio/${PORTVERSION}/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Very fast and configurable open source SIP proxy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libxml2.so:textproc/libxml2 \
		libcurl.so:ftp/curl
RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

USES=		compiler:c11 gmake ncurses pkgconfig python:3.5+ readline \
		shebangfix

USE_LDCONFIG=	yes
SHEBANG_FILES=	utils/kamctl/dbtextdb/dbtextdb.py \
		utils/kamctl/kamctl utils/kamctl/kamdbctl

CFLAGS+=	-Wall

KAMAILIO_USER?=		kamailio
KAMAILIO_GROUP?=	kamailio

USERS=		${KAMAILIO_USER}
GROUPS=		${KAMAILIO_GROUP}

KAMAILIO_RUNDIR?=	/var/run/${PORTNAME}

USE_RC_SUBR=	kamailio

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

SUB_LIST=	KAMAILIO_USER=${KAMAILIO_USER} \
		KAMAILIO_GROUP=${KAMAILIO_GROUP} \
		KAMAILIO_RUNDIR=${KAMAILIO_RUNDIR}

OPTIONS_GROUP=		DATABASE_DRIVERS KEMI_LANGS
OPTIONS_GROUP_DATABASE_DRIVERS=	MYSQL PGSQL UNIXODBC
OPTIONS_GROUP_KEMI_LANGS=	LUAJIT PYTHON3
OPTIONS_DEFINE=		DATABASE DIALPLAN DOCS KEMIX PERL PRESENCE RADIUS \
			SCTP TLS WEBSOCKET
OPTIONS_DEFAULT=	MYSQL PRESENCE RADIUS TLS
OPTIONS_SUB=		YES

DATABASE_DRIVERS_DESC=	Database drivers

DATABASE_DESC=	Database support
DATABASE_VARS=	EXTRA_GROUPS+=db

MYSQL_IMPLIES=	DATABASE
MYSQL_USES=	mysql
MYSQL_VARS=	EXTRA_GROUPS+=mysql

PGSQL_IMPLIES=	DATABASE
PGSQL_USES=	pgsql
PGSQL_VARS=	EXTRA_GROUPS+=postgres

UNIXODBC_IMPLIES=	DATABASE
UNIXODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
UNIXODBC_VARS=		EXTRA_MODULES+=db_unixodbc

KEMIX_DESC=		Core KEMI Functions
KEMIX_VARS=		EXTRA_MODULES+=kemix

KEMI_LANGS_DESC=	Kamailio Embedded Interface Interpreters

LUAJIT_DESC=		Execute embedded Lua scripts
LUAJIT_IMPLIES=		KEMIX
LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:lang/luajit
LUAJIT_MAKE_ARGS=	LUAJIT=yes
LUAJIT_VARS=		EXTRA_MODULES+=app_lua

PYTHON3_DESC=		Execute embedded Python3 scripts
PYTHON3_IMPLIES=	KEMIX
PYTHON3_MAKE_ARGS=	PYTHON3=${PYTHON_CMD}
PYTHON3_VARS=		EXTRA_MODULES+=app_python3

DIALPLAN_DESC=		String translations based on rules
DIALPLAN_LIB_DEPENDS=	libpcre.so:devel/pcre
DIALPLAN_VARS=		EXTRA_MODULES+=dialplan

PERL_USES=	perl5
PERL_VARS=	EXTRA_MODULES+=app_perl
PERL_MAKE_ENV=	PERLLDOPTS="`perl -MExtUtils::Embed -e ldopts`" \
		PERLCCOPTS="`perl -MExtUtils::Embed -e ccopts`" \
		TYPEMAP="`perl -MConfig -e 'print $$Config{privlib}'`/ExtUtils/typemap"

PRESENCE_DESC=	Presence support
PRESENCE_VARS=	EXTRA_GROUPS+=presence

RADIUS_LIB_DEPENDS=	libradiusclient-ng.so:net/radiusclient
RADIUS_VARS=		EXTRA_GROUPS+=radius

SCTP_DESC=	SCTP support
SCTP_VARS=	EXTRA_MODULES+=sctp

TLS_USES=	ssl
TLS_VARS=	EXTRA_MODULES+=tls

WEBSOCKET_DESC=		Websocket support
WEBSOCKET_LIB_DEPENDS=	libunistring.so:devel/libunistring
WEBSOCKET_VARS=		EXTRA_MODULES+=websocket

.include <bsd.port.pre.mk>

DEFAULT_GROUPS=	standard

.if !empty (EXTRA_GROUPS)
CFG_ARGS+=	group_include="${DEFAULT_GROUPS} ${EXTRA_GROUPS}"
.else
CFG_ARGS+=	group_include="${DEFAULT_GROUPS}"
.endif

.if !empty (EXTRA_MODULES)
CFG_ARGS+=	include_modules="${EXTRA_MODULES}"
.endif

post-patch:
	${REINPLACE_CMD} '551s|$$(run_prefix)/$$(run_dir)|${KAMAILIO_RUNDIR}|' \
		${WRKSRC}/src/Makefile.defs

post-patch-DOCS-off:
	@${REINPLACE_CMD} 's|install-doc install-man|install-man|' \
		${WRKSRC}/src/Makefile

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${CFG_ARGS} cfg

do-install:
	@${MKDIR} ${STAGEDIR}${KAMAILIO_RUNDIR}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} install
	@(cd ${STAGEDIR}${ETCDIR}; for i in `${FIND} . -type f`; do ${MV} $$i $$i.sample; done)

post-install:
	@${RMDIR} ${STAGEDIR}${DATADIR} || true
	@${FIND} ${STAGEDIR}${PREFIX} -type f -name '*.so' -exec ${STRIP_CMD} {} +
	@${FIND} ${STAGEDIR}${PREFIX} -type f -name '*.so.1' -exec ${STRIP_CMD} {} +
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/kamailio
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/kamcmd
	@${ECHO_CMD} "@dir(${KAMAILIO_USER},${KAMAILIO_GROUP},750) ${KAMAILIO_RUNDIR}" >> ${TMPPLIST}

.include <bsd.port.post.mk>
