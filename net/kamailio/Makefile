# Created by: Oliver Mahmoudi <olivermahmoudi@gmail.com>
# $FreeBSD$

PORTNAME=	kamailio
PORTVERSION=	5.2.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.kamailio.org/pub/kamailio/${PORTVERSION}/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Very fast and configurable open source SIP proxy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=Does not build: /bin/sh: clang: not found

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libxml2.so:textproc/libxml2 \
		libcurl.so:ftp/curl
RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

USES=		gmake ncurses pkgconfig python readline shebangfix

USE_LDCONFIG=	yes
SHEBANG_FILES=	utils/kamctl/dbtextdb/dbtextdb.py \
		utils/kamctl/kamctl utils/kamctl/kamdbctl

CFLAGS+=	-Wall

USERS=		kamailio
GROUPS=		kamailio

USE_RC_SUBR=	kamailio

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

RUNDIR?=	/var/run/${PORTNAME}

SUB_LIST=	RUNDIR=${RUNDIR} \
		USERS=${USERS} \
		GROUPS=${GROUPS}

OPTIONS_MULTI=	DATABASE
OPTIONS_MULTI_DATABASE=MYSQL PGSQL
OPTIONS_DEFINE=	DATABASE DIALPLAN DOCS JITSI PERL PRESENCE RADIUS \
		SCTP TLS UNIXODBC WEBSOCKET
OPTIONS_DEFAULT=MYSQL PRESENCE RADIUS TLS
OPTIONS_SUB=	YES

DATABASE_DESC=	Database support (select one or more)

DIALPLAN_DESC=	Dialplan support
DIALPLAN_LIB_DEPENDS=libpcre.so:devel/pcre
DIALPLAN_VARS=	EXTRA_MODULES+=dialplan

JITSI_DESC=	VoIP Frontend GUI via Jitsi
JITSI_RUN_DEPENDS=jitsi:net-im/jitsi

MYSQL_IMPLIES=	DATABASE
MYSQL_USES=	mysql
MYSQL_VARS=	EXTRA_GROUPS+=mysql

PERL_USES=	perl5
PERL_VARS=	EXTRA_MODULES+=app_perl
PERL_MAKE_ENV=	PERLLDOPTS="`perl -MExtUtils::Embed -e ldopts`" \
		PERLCCOPTS="`perl -MExtUtils::Embed -e ccopts`" \
		TYPEMAP="`perl -MConfig -e 'print $$Config{privlib}'`/ExtUtils/typemap"

PGSQL_IMPLIES=	DATABASE
PGSQL_USES=	pgsql
PGSQL_VARS=	EXTRA_GROUPS+=postgres

PRESENCE_DESC=	Presence support
PRESENCE_VARS=	EXTRA_GROUPS+=presence

RADIUS_LIB_DEPENDS=libradiusclient-ng.so:net/radiusclient
RADIUS_VARS=	EXTRA_GROUPS+=radius

SCTP_DESC=	SCTP support
SCTP_VARS=	EXTRA_MODULES+=sctp

TLS_USES=	ssl
TLS_VARS=	EXTRA_MODULES+=tls

UNIXODBC_LIB_DEPENDS=libodbc.so:databases/unixODBC
UNIXODBC_VARS=	EXTRA_MODULES+=db_unixodbc

WEBSOCKET_DESC=	Websocket support
WEBSOCKET_LIB_DEPENDS=libunistring.so:devel/libunistring
WEBSOCKET_VARS=	EXTRA_MODULES+=websocket

.include <bsd.port.pre.mk>

DEFAULT_GROUP_INCLUDE=standard standard-dep

.if !empty (EXTRA_GROUPS)
MAKE_ARGS+=	group_include="${DEFAULT_GROUP_INCLUDE} ${EXTRA_GROUPS}"
.else
MAKE_ARGS+=	group_include="${DEFAULT_GROUP_INCLUDE}"
.endif

.if !empty (EXTRA_MODULES)
MAKE_ARGS+=	include_modules="${EXTRA_MODULES}"
.endif

post-patch:
	${REINPLACE_CMD} '499s|$$(run_prefix)/$$(run_dir)|${RUNDIR}|' \
		${WRKSRC}/src/Makefile.defs
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} 's|install-doc install-man|install-man|' \
		${WRKSRC}/src/Makefile
.endif

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} cfg

do-build:
	@cd ${WRKSRC} && ${DO_MAKE_BUILD} ${ALL_TARGET}

do-install:
	@${MKDIR} ${STAGEDIR}${RUNDIR}
	@cd ${WRKSRC} && ${MAKE_CMD} ${INSTALL_TARGET}
	@(cd ${STAGEDIR}${ETCDIR}; for i in `${FIND} . -type f`; do ${MV} $$i $$i.sample; done)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/kamailio/*.so.1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/kamailio/modules/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/kamailio
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/kamcmd
	@${ECHO_CMD} "@dir(${USERS},${GROUPS},750) ${RUNDIR}" >> ${TMPPLIST}

.include <bsd.port.post.mk>
