# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unit
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://unit.nginx.org/download/

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Dynamic web application server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES+=		cpe

CPE_VENDOR=	nginx
CPE_PRODUCT=	unit

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=	\
	DEBUG \
	IPV6 \
	UNIXSOCK \
	PHP \
	PYTHON27 \
	PYTHON34 \
	PYTHON35 \
	PYTHON36

OPTIONS_DEFAULT?=IPV6 PYTHON27

DEBUG_DESC=	Enable debug logging
IPV6_DESC=	Enable IPv6
UNIXSOCK_DESC=	Enable unix sockets
GO_DESC=	Enable Go module
PHP_DESC=	Enable PHP module
PYTHON27_DESC=	Enable Python 2.7 module
PYTHON34_DESC=	Enable Python 3.4 module
PYTHON35_DESC=	Enable Python 3.5 module
PYTHON36_DESC=	Enable Python 3.6 module

.include <bsd.port.options.mk>

HAS_CONFIGURE=	yes

UNIT_VARDIR?=	/var
UNIT_RUNDIR?=	${UNIT_VARDIR}/run/unit
UNIT_LOGDIR?=	${UNIT_VARDIR}/log/${PORTNAME}
UNIT_LOGFILE?=	${UNIT_LOGDIR}/${PORTNAME}.log
UNIT_PIDFILE?=	${UNIT_RUNDIR}/${PORTNAME}.pid
UNIT_SOCK?=	${UNIT_RUNDIR}/control.unit.sock

PLIST_FILES+=	etc/rc.d/unitd \
		sbin/unitd

CONFIGURE_ARGS+=--bindir=${PREFIX}/bin \
		--sbindir=${PREFIX}/sbin \
		--modules=${PREFIX}/libexec/${PORTNAME} \
		--log=${UNIT_LOGFILE} \
		--pid=${UNIT_PIDFILE} \
		--ld-opt="-L${LOCALBASE}/lib"

USE_RC_SUBR=	unitd
SUB_LIST+=	UNIT_PIDFILE=${UNIT_PIDFILE} \
		UNIT_SOCK=${UNIT_SOCK} \
		PREFIX=${PREFIX}

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--debug
.endif

.if empty(PORT_OPTIONS:MIPV6)
CONFIGURE_ARGS+=--no-ipv6
.endif

.if empty(PORT_OPTIONS:MUNIXSOCK)
CONFIGURE_ARGS+=--no-unix-sockets
.else
CONFIGURE_ARGS+=--control=unix:${UNIT_SOCK}
.endif

.if ${PORT_OPTIONS:MGO}
BUILD_DEPENDS+=	${LOCALBASE}/bin/go:lang/go
RUN_DEPENDS+=	${LOCALBASE}/bin/go:lang/go
PLIST_FILES+=	go/src/unit/cbytes-1.6.go \
		go/src/unit/cbytes-1.7.go \
		go/src/unit/nxt_go_array.c \
		go/src/unit/nxt_go_array.h \
		go/src/unit/nxt_go_lib.c \
		go/src/unit/nxt_go_lib.h \
		go/src/unit/nxt_go_log.h \
		go/src/unit/nxt_go_mutex.h \
		go/src/unit/nxt_go_port.c \
		go/src/unit/nxt_go_port.h \
		go/src/unit/nxt_go_port_memory.c \
		go/src/unit/nxt_go_port_memory.h \
		go/src/unit/nxt_go_process.c \
		go/src/unit/nxt_go_process.h \
		go/src/unit/nxt_go_run_ctx.c \
		go/src/unit/nxt_go_run_ctx.h \
		go/src/unit/port.go \
		go/src/unit/request.go \
		go/src/unit/response.go \
		go/src/unit/unit.go \
		go/pkg/freebsd_amd64/unit.a
.endif

.if ${PORT_OPTIONS:MPHP}
USES+=	php:embed
PLIST_FILES+=	libexec/unit/php.unit.so
.endif

.if ${PORT_OPTIONS:MPYTHON27}
USES+=	python:2.7
PLIST_FILES+=	libexec/unit/python2.7.unit.so
.endif

.if ${PORT_OPTIONS:MPYTHON34}
USES+=	python:3.4
PLIST_FILES+=	libexec/unit/python3.4.unit.so
.endif

.if ${PORT_OPTIONS:MPYTHON35}
USES+=	python:3.5
PLIST_FILES+=	libexec/unit/python3.5.unit.so
.endif

.if ${PORT_OPTIONS:MPYTHON36}
USES+=	python:3.6
PLIST_FILES+=	libexec/unit/python3.6.unit.so
.endif

post-configure:
.if ${PORT_OPTIONS:MGO}
	@cd ${WRKSRC} && ./configure go --go=${LOCALBASE}/bin/go --go-path=${LOCALBASE}/go
.endif
.if ${PORT_OPTIONS:MPHP}
	@cd ${WRKSRC} && ./configure php --config=${LOCALBASE}/bin/php-config \
		--lib-path="${LOCALBASE}/lib"
.endif
.if ${PORT_OPTIONS:MPYTHON27}
	@cd ${WRKSRC} && ./configure python --config=${LOCALBASE}/bin/python2.7-config
.endif
.if ${PORT_OPTIONS:MPYTHON34}
	@cd ${WRKSRC} && ./configure python --config=${LOCALBASE}/bin/python3.4-config
.endif
.if ${PORT_OPTIONS:MPYTHON35}
	@cd ${WRKSRC} && ./configure python --config=${LOCALBASE}/bin/python3.5-config
.endif
.if ${PORT_OPTIONS:MPYTHON36}
	@cd ${WRKSRC} && ./configure python --config=${LOCALBASE}/bin/python3.6-config
.endif

post-install:
	${MKDIR} ${STAGEDIR}${UNIT_LOGDIR}
	${MKDIR} ${STAGEDIR}${UNIT_RUNDIR}
	${ECHO_CMD} @dir ${UNIT_LOGDIR} >> ${TMPPLIST}
	${ECHO_CMD} @dir ${UNIT_RUNDIR} >> ${TMPPLIST}

.include <bsd.port.mk>
