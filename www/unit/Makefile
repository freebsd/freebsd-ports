PORTNAME=	unit
PORTVERSION=	${UNIT_VERSION}
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
	SSL \
	UNIXSOCK
OPTIONS_DEFAULT?=	IPV6 PCRE2 SSL UNIXSOCK

OPTIONS_RADIO+=		REGEX
OPTIONS_RADIO_REGEX=	NOPCRE PCRE PCRE2

DEBUG_DESC=	Enable debug logging
REGEX_DESC=	Support regular expressions
NOPCRE_DESC=	No support for Regular Expressions
PCRE_DESC=	Regular Expressions via devel/pcre
PCRE2_DESC=	Regular Expressions via devel/pcre2
SSL_DESC=	Enable SSL/TLS
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
		--modules=libexec/unit/modules \
		--pid=${UNIT_PIDFILE} \
		--state=${UNIT_DBDIR} \
		--tmp=${UNIT_TMPDIR} \
		--user=${WWWOWN} --group=${WWWGRP}

USERS?=	${WWWOWN}
GROUPS?=${WWWGRP}

ALL_TARGET=

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

.if ${PORT_OPTIONS:MNOPCRE}
CONFIGURE_ARGS+=--no-regex
.endif

.if ${PORT_OPTIONS:MPCRE}
CONFIGURE_ARGS+=--no-pcre2
LIB_DEPENDS+=	libpcre.so:devel/pcre
.endif

.if ${PORT_OPTIONS:MPCRE2}
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

.if defined(UNIT_MODNAME) && ${UNIT_MODNAME:Mperl*}
# Fix build failure on clang >= 12
.if ${OSVERSION} >= 1301000
CFLAGS+=	-Wno-compound-token-split-by-macro
.endif
.endif

.if !target(post-install)
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
	${INSTALL_MAN} ${WRKSRC}/build/unitd.8 ${STAGEDIR}${MAN8PREFIX}/share/man/man8
.endif

.include "../../www/unit/version.mk"
.include <bsd.port.mk>
