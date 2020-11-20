# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unit
PORTVERSION=	1.21.0
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES?=	https://unit.nginx.org/download/

MAINTAINER=	osa@FreeBSD.org
COMMENT?=	Dynamic web application server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES+=		compiler:c11 cpe

CPE_VENDOR=	nginx
CPE_PRODUCT=	unit

OPTIONS_DEFINE?=	\
	DEBUG \
	IPV6 \
	PCRE2 \
	SSL \
	UNIXSOCK
OPTIONS_DEFAULT?=	IPV6 PCRE2 SSL UNIXSOCK

DEBUG_DESC=	Enable debug logging
DEVKIT_DESC=	Install headers and library
PCRE2_DESC=	Enable PCRE2 support
SSL_DESC=	Enable SSL/TLS
UNIXSOCK_DESC=	Enable unix sockets

.include <bsd.port.options.mk>

HAS_CONFIGURE=	yes

UNIT_VARDIR?=	/var
UNIT_LOGDIR?=	${UNIT_VARDIR}/log/${PORTNAME}
UNIT_LOGFILE?=	${UNIT_LOGDIR}/${PORTNAME}.log
UNIT_PIDFILE?=	${UNIT_RUNDIR}/${PORTNAME}.pid
UNIT_RUNDIR?=	${UNIT_VARDIR}/run/unit
UNIT_SOCK?=	${UNIT_RUNDIR}/control.unit.sock
UNIT_TMPDIR?=	${UNIT_VARDIR}/tmp/unit

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--ld-opt="-L${LOCALBASE}/lib" \
		--log=${UNIT_LOGFILE} \
		--modules=libexec/unit/modules \
		--pid=${UNIT_PIDFILE} \
		--state=libexec/unit \
		--tmp=${UNIT_TMPDIR} \
		--user=${WWWOWN} --group=${WWWGRP}

USERS?=	${WWWOWN}
GROUPS?=${WWWGRP}

ALL_TARGET=

PLIST_DIRS?=	libexec/unit/modules \
		libexec/unit
PLIST_FILES?=	sbin/unitd

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

.if empty(PORT_OPTIONS:MPCRE2)
CONFIGURE_ARGS+=--no-pcre2
.else
LIB_DEPENDS+=	libpcre2-8.so:devel/pcre2
.endif

.if ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=--openssl
USES+=		ssl
.endif

.if empty(PORT_OPTIONS:MUNIXSOCK)
CONFIGURE_ARGS+=--no-unix-sockets
.else
CONFIGURE_ARGS+=--control=unix:${UNIT_SOCK}
.endif

.if !target(post-install)
post-install:
	${MKDIR} ${STAGEDIR}${UNIT_LOGDIR}
	${MKDIR} ${STAGEDIR}${UNIT_RUNDIR}
	${MKDIR} ${STAGEDIR}${UNIT_TMPDIR}
	${ECHO_CMD} @dir ${UNIT_LOGDIR} >> ${TMPPLIST}
	${ECHO_CMD} @dir ${UNIT_RUNDIR} >> ${TMPPLIST}
	${ECHO_CMD} @dir ${UNIT_TMPDIR} >> ${TMPPLIST}
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unit/modules
.endif

.include <bsd.port.mk>
