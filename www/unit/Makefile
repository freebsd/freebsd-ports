# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unit
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://unit.nginx.org/download/

MAINTAINER=	osa@FreeBSD.org
COMMENT?=	Dynamic web application server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES+=		cpe

CPE_VENDOR=	nginx
CPE_PRODUCT=	unit

OPTIONS_DEFINE?=	\
	DEBUG \
	IPV6 \
	UNIXSOCK
OPTIONS_DEFAULT?=IPV6 UNIXSOCK

DEBUG_DESC=	Enable debug logging
IPV6_DESC=	Enable IPv6
UNIXSOCK_DESC=	Enable unix sockets

.include <bsd.port.options.mk>

HAS_CONFIGURE=	yes

UNIT_VARDIR?=	/var
UNIT_RUNDIR?=	${UNIT_VARDIR}/run/unit
UNIT_LOGDIR?=	${UNIT_VARDIR}/log/${PORTNAME}
UNIT_LOGFILE?=	${UNIT_LOGDIR}/${PORTNAME}.log
UNIT_PIDFILE?=	${UNIT_RUNDIR}/${PORTNAME}.pid
UNIT_SOCK?=	${UNIT_RUNDIR}/control.unit.sock

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--modules=libexec/unit/modules \
		--state=libexec/unit \
		--log=${UNIT_LOGFILE} \
		--pid=${UNIT_PIDFILE} \
		--ld-opt="-L${LOCALBASE}/lib"

PLIST_FILES?=	sbin/unitd
PLIST_DIRS?=	libexec/unit/modules \
		libexec/unit

USE_RC_SUBR?=	unitd
SUB_LIST=	UNIT_PIDFILE=${UNIT_PIDFILE} \
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

.if !target(post-install)
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unit/modules
.endif

.include <bsd.port.mk>
