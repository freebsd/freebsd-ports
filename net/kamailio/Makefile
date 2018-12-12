# Created by: Oliver Mahmoudi <olivermahmoudi@gmail.com>
# $FreeBSD$

PORTNAME=	kamailio
PORTVERSION=	5.2.0

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

BROKEN_powerpc64=	Does not build: /bin/sh: clang: not found

USES=		gmake ncurses pkgconfig python readline shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	utils/kamctl/dbtextdb/dbtextdb.py \
		utils/kamctl/kamctl utils/kamctl/kamdbctl
CFLAGS+=	-Wall

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_RC_SUBR=	kamailio

USERS=		kamailio
GROUPS=		kamailio

OPTIONS_DEFINE=	DOCS MYSQL PGSQL PERL RADIUS JITSI SCTP TLS \
		UNIXODBC PRESENCE WEBSOCKET DIALPLAN
OPTIONS_DEFAULT=MYSQL RADIUS TLS PRESENCE
OPTIONS_SUB=	YES

DIALPLAN_DESC=	Dialplan support
JITSI_DESC=	VoIP Frontend GUI via Jitsi
SCTP_DESC=	SCTP support
PRESENCE_DESC=	Presence support
WEBSOCKET_DESC=	Websocket support

MYSQL_USES=	mysql
PGSQL_USES=	pgsql
JITSI_RUN_DEPENDS=	jitsi:net-im/jitsi
UNIXODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
RADIUS_LIB_DEPENDS=	libradiusclient-ng.so:net/radiusclient
TLS_USES=	ssl

.include <bsd.port.options.mk>

DEFAULT_GROUP_INCLUDE=	standard standard-dep

.if ${PORT_OPTIONS:MMYSQL}
EXTRA_GROUPS+=	mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
EXTRA_GROUPS+=	postgres
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
EXTRA_MODULES+=	app_perl
MAKE_ENV+=	PERLLDOPTS=`perl -MExtUtils::Embed -e ldopts` \
		PERLCCOPTS=`perl -MExtUtils::Embed -e ccopts` \
		TYPEMAP=`perl -MConfig -e 'print $Config{installprivlib}'`/ExtUtils/typemap
.endif

.if ${PORT_OPTIONS:MUNIXODBC}
EXTRA_MODULES+=	db_unixodbc
.endif

.if ${PORT_OPTIONS:MDIALPLAN}
LIB_DEPENDS+=	libpcre.so:devel/pcre
EXTRA_MODULES+=	dialplan
.endif

.if ${PORT_OPTIONS:MRADIUS}
EXTRA_GROUPS+=	radius
.endif

.if ${PORT_OPTIONS:MSCTP}
EXTRA_MODULES+=	sctp
.endif

.if ${PORT_OPTIONS:MTLS}
EXTRA_MODULES+=	tls
.endif

.if ${PORT_OPTIONS:MPRESENCE}
EXTRA_GROUPS+=	presence
.endif

.if ${PORT_OPTIONS:MWEBSOCKET}
EXTRA_MODULES+=	websocket
LIB_DEPENDS+=	libunistring.so:devel/libunistring
.endif

.if !empty (EXTRA_GROUPS)
MAKE_ARGS+=	group_include="${DEFAULT_GROUP_INCLUDE} ${EXTRA_GROUPS}"
.else
MAKE_ARGS+=	group_include="${DEFAULT_GROUP_INCLUDE}"
.endif

.if !empty (EXTRA_MODULES)
MAKE_ARGS+=	include_modules="${EXTRA_MODULES}"
.endif

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's#install-doc install-man#install-man#'	\
		${WRKSRC}/Makefile
.endif

pre-build:
	cd ${WRKSRC} && ${GMAKE} ${MAKE_ARGS} cfg

do-build:
	cd ${WRKSRC} && ${GMAKE} ${ALL_TARGET}

do-install:
	cd ${WRKSRC} && ${GMAKE} ${INSTALL_TARGET}
.if ! ${PORT_OPTIONS:MMYSQL} && ! ${PORT_OPTIONS:MPGSQL}
	${RMDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}
.endif

post-install:
	(cd ${STAGEDIR}${PREFIX}/lib/kamailio/modules ; ${STRIP_CMD} *.so)
	(cd ${STAGEDIR}${PREFIX}/lib/kamailio ; ${STRIP_CMD} *.so.1)
	(cd ${STAGEDIR}${PREFIX}/sbin ; ${STRIP_CMD} kamailio kamcmd)

.include <bsd.port.mk>
