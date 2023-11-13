PORTNAME?=		angie
PORTVERSION=		1.3.1
CATEGORIES+=		www
MASTER_SITES+=		https://download.angie.software/files/:angie
DISTNAME=		angie-${DISTVERSIONFULL}
DISTFILES+=		${DISTNAME}${EXTRACT_SUFX}:angie

MAINTAINER?=		oleg@mamontov.net
COMMENT?=		Efficient, powerful and scalable reverse proxy and web server
WWW?=			https://angie.software/en/

LICENSE?=		BSD2CLAUSE
.if ${PORTNAME} == angie
LICENSE_FILE=		${WRKSRC}/LICENSE
.else
LICENSE_FILE?=		${WRKSRC_module}/LICENSE
.endif

.if ${PORTNAME} == angie
LIB_DEPENDS=		libpcre2-8.so:devel/pcre2
.else
BUILD_DEPENDS+=		pcre2>=0:devel/pcre2
RUN_DEPENDS+=		angie==${PKGVERSION}:www/angie
.endif

USES+=			localbase:ldflags ssl
USE_GITHUB=		nodefault

HAS_CONFIGURE?=		yes

.if ${PORTNAME} == angie
ALL_TARGET=		build
SUB_FILES=		angie.conf.sample \
			default.conf.sample \
			example.conf.sample \
			pkg-message
USE_RC_SUBR=		angie
.else
ALL_TARGET?=		modules
CONFIGURE_ADD?=		--add-dynamic-module=${WRKSRC_module}
.endif

# modules always have their own assets
PATCHDIR?=		${.CURDIR}/files
FILESDIR?=		${.CURDIR}/files
SCRIPTDIR?=		${.CURDIR}/scripts
PKGDIR?=		${.CURDIR}

# angie-specific variables
CACHEDIR=		/var/cache/angie
LOGDIR=			/var/log/angie
MODDIR=			${PREFIX}/libexec/angie
RUNDIR=			/var/run
WRKSRC_DEBUG=		${WRKSRC}-debug

PLIST_SUB+=		CACHEDIR=${CACHEDIR} \
			LOGDIR=${LOGDIR} \
			MODDIR=${MODDIR} \
			RUNDIR=${RUNDIR}

SUB_LIST+=		CACHEDIR=${CACHEDIR} \
			LOGDIR=${LOGDIR} \
			MODDIR=${MODDIR} \
			RUNDIR=${RUNDIR} \
			WWWOWN=${WWWOWN}

SUB_FILES?=		pkg-message

OPTIONS_SUB=		yes

CONFIGURE_ARGS=		--prefix=${PREFIX}/etc/angie \
			--conf-path=${PREFIX}/etc/angie/angie.conf \
			--error-log-path=${LOGDIR}/error.log \
			--http-log-path=${LOGDIR}/access.log \
			--lock-path=${RUNDIR}/angie.lock \
			--modules-path=${MODDIR} \
			--pid-path=${RUNDIR}/angie.pid \
			--sbin-path=${PREFIX}/sbin/angie \
			--http-client-body-temp-path=${CACHEDIR}/client_temp \
			--http-fastcgi-temp-path=${CACHEDIR}/fastcgi_temp \
			--http-proxy-temp-path=${CACHEDIR}/proxy_temp \
			--http-scgi-temp-path=${CACHEDIR}/scgi_temp \
			--http-uwsgi-temp-path=${CACHEDIR}/uwsgi_temp \
			--user=${WWWOWN} \
			--group=${WWWGRP} \
			--with-file-aio \
			--with-http_addition_module \
			--with-http_auth_request_module \
			--with-http_dav_module \
			--with-http_flv_module \
			--with-http_gunzip_module \
			--with-http_gzip_static_module \
			--with-http_mp4_module \
			--with-http_random_index_module \
			--with-http_realip_module \
			--with-http_secure_link_module \
			--with-http_slice_module \
			--with-http_ssl_module \
			--with-http_stub_status_module \
			--with-http_sub_module \
			--with-http_v2_module \
			--with-http_v3_module \
			--with-mail \
			--with-mail_ssl_module \
			--with-stream \
			--with-stream_realip_module \
			--with-stream_ssl_module \
			--with-stream_ssl_preread_module \
			--with-threads \
			--with-cc-opt="${CFLAGS}" \
			--with-ld-opt="${LDFLAGS}" \
			${CONFIGURE_ADD}

OPTIONS_DEFINE?=	DEBUG
OPTIONS_DEFAULT?=	DEBUG
DEBUG_DESC?=		Include debug version

.include <bsd.port.options.mk>

post-patch-DEBUG-on:
	@${CP} -Rp ${WRKSRC} ${WRKSRC_DEBUG}

post-configure-DEBUG-on:
	@(cd ${WRKSRC_DEBUG} && \
	    ${SET_LATE_CONFIGURE_ARGS} \
	    if ! ${SETENV} CC="${CC}" CPP="${CPP}" CXX="${CXX}" \
	        CFLAGS="${CFLAGS} -g" CPPFLAGS="${CPPFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	        LDFLAGS="${LDFLAGS}" LIBS="${LIBS}" \
	        INSTALL="/usr/bin/install -c" \
	        INSTALL_DATA="${INSTALL_DATA}" \
	        INSTALL_LIB="${INSTALL_LIB}" \
	        INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	        INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	        ${CONFIGURE_ENV} ${CONFIGURE_CMD} ${CONFIGURE_ARGS} --with-debug; then \
	        ${ECHO_MSG} "===>  Script \"${CONFIGURE_SCRIPT}\" failed unexpectedly."; \
	        (${ECHO_CMD} ${CONFIGURE_FAIL_MESSAGE}) | ${FMT_80} ; \
	        ${FALSE}; \
	    fi \
	)

post-build-DEBUG-on:
	@(cd ${WRKSRC_DEBUG} && ${DO_MAKE_BUILD} ${ALL_TARGET})

.if ${PORTNAME} == angie
do-install:
	${MKDIR} ${STAGEDIR}${CACHEDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${ETCDIR}/http.d
	${MKDIR} ${STAGEDIR}${ETCDIR}/stream.d
	${MKDIR} ${STAGEDIR}${LOGDIR}
	${MKDIR} ${STAGEDIR}${MODDIR}
	${MKDIR} ${STAGEDIR}${WWWDIR}/html

	${RLN} ${STAGEDIR}${MODDIR} ${STAGEDIR}${ETCDIR}/modules

	${INSTALL_PROGRAM} ${WRKSRC}/objs/angie \
	    ${STAGEDIR}${PREFIX}/sbin/angie-nodebug

	${LN} -fs angie-nodebug ${STAGEDIR}${PREFIX}/sbin/angie

	${INSTALL_MAN} ${WRKSRC}/objs/angie.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
.for i in CHANGES CHANGES.ru README.rst
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.for i in fastcgi.conf fastcgi_params mime.types scgi_params uwsgi_params
	${INSTALL_DATA} ${WRKSRC}/conf/${i} ${STAGEDIR}${ETCDIR}/${i}.sample
.endfor
	${INSTALL_DATA} ${WRKSRC}/conf/prometheus_all.conf \
	    ${STAGEDIR}${ETCDIR}/prometheus_all.conf.sample

	${INSTALL_DATA} ${WRKDIR}/angie.conf.sample \
	    ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/default.conf.sample \
	    ${STAGEDIR}${ETCDIR}/http.d
	${INSTALL_DATA} ${WRKDIR}/example.conf.sample \
	    ${STAGEDIR}${ETCDIR}/stream.d
.for i in 50x.html index.html
	${INSTALL_DATA} ${WRKSRC}/html/${i} ${STAGEDIR}${WWWDIR}/html/${i}
.endfor

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${BINMODE} ${WRKSRC_DEBUG}/objs/angie \
	    ${STAGEDIR}${PREFIX}/sbin/angie-debug
.endif

.include <bsd.port.mk>
