PORTNAME=	freeunit
DISTVERSION=	1.36.0
CATEGORIES=	www

MAINTAINER=	pkaipila@gmail.com
COMMENT?=	Dynamic web application server, successor of NGINX Unit
WWW=		https://freeunit.org \
		https://github.com/freeunitorg/freeunit

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS+=	libpcre2-8.so:devel/pcre2

USES+=		compiler:c11 gmake pkgconfig ssl

USE_GITHUB=	yes
GH_ACCOUNT=	freeunitorg

USE_RC_SUBR?=	unitd

UNIT_VARDIR?=	/var
UNIT_DBDIR?=	${UNIT_VARDIR}/db/${PORTNAME}
UNIT_LOGDIR?=	${UNIT_VARDIR}/log/${PORTNAME}
UNIT_LOGFILE?=	${UNIT_LOGDIR}/${PORTNAME}.log
UNIT_PIDFILE?=	${UNIT_RUNDIR}/${PORTNAME}.pid
UNIT_RUNDIR?=	${UNIT_VARDIR}/run/unit
UNIT_SOCK?=	${UNIT_RUNDIR}/control.unit.sock
UNIT_TMPDIR?=	${UNIT_VARDIR}/tmp/unit

OPTIONS_DEFINE?=	DEBUG
OPTIONS_DEFAULT?=

DEBUG_DESC=	Enable debug logging

.include <bsd.port.options.mk>

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=	--control=unix:${UNIT_SOCK} \
		--group=${WWWGRP} \
		--ld-opt="-L${LOCALBASE}/lib" \
		--log=${UNIT_LOGFILE} \
		--logdir=${UNIT_LOGDIR} \
		--modulesdir=${PREFIX}/libexec/unit/modules \
		--openssl \
		--pid=${UNIT_PIDFILE} \
		--prefix=${PREFIX} \
		--runstatedir=${UNIT_RUNDIR} \
		--statedir=${UNIT_DBDIR} \
		--tmpdir=${UNIT_TMPDIR} \
		--user=${WWWOWN}

SUB_LIST=	PREFIX=${PREFIX} \
		UNIT_PIDFILE=${UNIT_PIDFILE} \
		UNIT_SOCK=${UNIT_SOCK} \
		UNIT_TMPDIR=${UNIT_TMPDIR} \
		WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--debug
.endif

USERS?=		${WWWOWN}
GROUPS?=	${WWWGRP}

.if !defined(FREEUNIT_MODNAME)

LIB_DEPENDS+=	libbrotlienc.so:archivers/brotli \
				libzstd.so:archivers/zstd

CONFIGURE_ARGS+=	--zlib --zstd --brotli

PLIST_DIRS=	libexec/unit \
		libexec/unit/modules
PLIST_FILES=	sbin/unitd \
		share/man/man8/unitd.8.gz

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

.else

PLIST_FILES+=	libexec/unit/modules/${FREEUNIT_MODNAME}.unit.so

.endif

.include <bsd.port.mk>
