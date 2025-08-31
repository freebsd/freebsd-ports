PORTNAME=	unit
PORTVERSION=	${UNIT_VERSION}
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES?=	https://unit.nginx.org/download/
DISTFILES?=	${PORTNAME}-${PORTVERSION}.tar.gz

PATCH_SITES=	https://github.com/nginx/unit/commit/
PATCHFILES=	08e552581d2f56d56ad369a222497138a4e41eff.patch:-p1

MAINTAINER=	osa@FreeBSD.org
COMMENT?=	Dynamic web application server
WWW=		https://unit.nginx.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES+=		compiler:c11 cpe gmake ssl

CPE_VENDOR=	nginx
CPE_PRODUCT=	unit

OPTIONS_DEFINE?=	\
	DEBUG \
	IPV6 \
	NJS \
	OTEL \
	UNIXSOCK
OPTIONS_DEFAULT?=	IPV6 UNIXSOCK

DEBUG_DESC=	Enable debug logging
NJS_DESC=	Enable NGINX JavaScript
OTEL_DESC=	Enable OpenTelemetry
UNIXSOCK_DESC=	Enable unix sockets

.include <bsd.port.options.mk>

HAS_CONFIGURE=	yes

UNIT_VARDIR?=	/var
UNIT_DBDIR?=	${UNIT_VARDIR}/db/${PORTNAME}
UNIT_LOGDIR?=	${UNIT_VARDIR}/log/${PORTNAME}
UNIT_LOGFILE?=	${UNIT_LOGDIR}/${PORTNAME}.log
UNIT_PIDFILE?=	${UNIT_RUNDIR}/${PORTNAME}.pid
UNIT_RUNDIR?=	${UNIT_VARDIR}/run/unit
UNIT_SOCK?=	${UNIT_RUNDIR}/control.unit.sock
UNIT_TMPDIR?=	${UNIT_VARDIR}/tmp/unit

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--ld-opt="-L${LOCALBASE}/lib" \
		--log=${UNIT_LOGFILE} \
		--logdir=${UNIT_LOGDIR} \
		--modulesdir=${PREFIX}/libexec/unit/modules \
		--openssl \
		--pid=${UNIT_PIDFILE} \
		--runstatedir=${UNIT_RUNDIR} \
		--statedir=${UNIT_DBDIR} \
		--tmpdir=${UNIT_TMPDIR} \
		--user=${WWWOWN} --group=${WWWGRP}

USERS?=	${WWWOWN}
GROUPS?=${WWWGRP}

ALL_TARGET=

LIB_DEPENDS+=	libpcre2-8.so:devel/pcre2

PLIST_DIRS?=	libexec/unit/modules \
		libexec/unit
PLIST_FILES?=	sbin/unitd \
		share/man/man8/unitd.8.gz

USE_RC_SUBR?=	unitd
SUB_LIST=	PREFIX=${PREFIX} \
		UNIT_PIDFILE=${UNIT_PIDFILE} \
		UNIT_SOCK=${UNIT_SOCK} \
		UNIT_TMPDIR=${UNIT_TMPDIR} \
		WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP}

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--debug
.endif

.if empty(PORT_OPTIONS:MIPV6)
CONFIGURE_ARGS+=--no-ipv6
.endif

.if ${PORT_OPTIONS:MNJS}
USES+=	pkgconfig
BUILD_DEPENDS+=	${LOCALBASE}/lib/libnjs.a:devel/libnjs
LIB_DEPENDS+=	libquickjs.so:lang/quickjs
CONFIGURE_ARGS+=--njs \
	--cc-opt="-I${LOCALBASE}/include" \
	--ld-opt="-L${LOCALBASE}/lib"
.endif

.if ${PORT_OPTIONS:MOTEL}
BUILD_DEPENDS+=		${LOCALBASE}/lib/libotel.a:devel/unit-otel
CONFIGURE_ARGS+=	--otel
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-auto-make
.endif

.if empty(PORT_OPTIONS:MUNIXSOCK)
CONFIGURE_ARGS+=--no-unix-sockets
.else
CONFIGURE_ARGS+=--control=unix:${UNIT_SOCK}
.endif

.if defined(UNIT_MODNAME) && ${UNIT_MODNAME:Mperl*}
# Fix build failure on clang >= 12
CFLAGS+=	-Wno-compound-token-split-by-macro
.endif

.if !defined(UNIT_MODNAME)
post-patch-OTEL-on:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/auto/make

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE}

post-install:
	${MKDIR} ${STAGEDIR}${UNIT_DBDIR}
	${MKDIR} ${STAGEDIR}${UNIT_LOGDIR}
	${MKDIR} ${STAGEDIR}${UNIT_RUNDIR}
	${MKDIR} ${STAGEDIR}${UNIT_TMPDIR}
	${ECHO_CMD} @dir ${UNIT_DBDIR} >> ${TMPPLIST}
	${ECHO_CMD} @dir ${UNIT_LOGDIR} >> ${TMPPLIST}
	${ECHO_CMD} @dir ${UNIT_RUNDIR} >> ${TMPPLIST}
	${ECHO_CMD} @dir ${UNIT_TMPDIR} >> ${TMPPLIST}
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unit/modules
	${INSTALL_MAN} ${WRKSRC}/build/share/man/man8/unitd.8 \
		${STAGEDIR}${PREFIX}/share/man/man8
.endif

.include "../../www/unit/version.mk"
.include <bsd.port.mk>
