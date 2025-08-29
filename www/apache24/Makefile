PORTNAME=	apache24
PORTVERSION=	2.4.65
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	APACHE_HTTPD
DISTNAME=	httpd-${PORTVERSION}
DIST_SUBDIR=	apache24

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Version 2.4.x of Apache web server
WWW=		https://httpd.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libapr-1.so:devel/apr1 \
		libpcre2-8.so:devel/pcre2

USES=		apache:server,2.4 autoreconf compiler:c11 cpe iconv libtool perl5 tar:bzip2
USE_PERL5=	run
USE_RC_SUBR=	apache24 htcacheclean
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CONFLICTS_INSTALL=	py*-circuits # bin/htpasswd

CPE_VENDOR=	apache
CPE_PRODUCT=	http_server

PORTDOCS=	*
SUB_FILES=	pkg-install pkg-deinstall

# Fallback MPM after switching from static to modular MPM
SUB_LIST+=	MPMF="000_mpm_prefork_fallback.conf"

USERS?=		${WWWOWN}
GROUPS?=	${WWWGRP}

.include "${.CURDIR}/Makefile.options"
.include "${.CURDIR}/Makefile.options.desc"
OPTIONS_SUB=	yes

# IMPLIES
AUTHN_DBD_IMPLIES=		DBD
HEARTBEAT_IMPLIES=		WATCHDOG STATUS
HEARTMONITOR_IMPLIES=		WATCHDOG STATUS
LBMETHOD_HEARTBEAT_IMPLIES=	WATCHDOG STATUS HEARTMONITOR
PROXY_HCHECK_IMPLIES=		WATCHDOG
PROXY_HTTP2_IMPLIES=		PROXY_BALANCER
.for module in ${PROXY_ENABLED_MODULES:NPROXY} ${PROXY_DISABLED_MODULES}
${module}_IMPLIES=		PROXY
.endfor
.for module in ${SESSION_ENABLED_MODULES:NSESSION} ${SESSION_DISABLED_MODULES}
${module}_IMPLIES=		SESSION
.endfor

# Multi-Processing Modules options handling
MPM_PREFORK_CONFIGURE_ON=	--with-mpm=prefork
MPM_WORKER_CONFIGURE_ON=	--with-mpm=worker
MPM_EVENT_CONFIGURE_ON=		--with-mpm=event
MPM_SHARED_CONFIGURE_ON=	--enable-mpms-shared=all
MPM_SHARED_SUB_LIST=		MPM_FALLBACK_CHECK=""
MPM_SHARED_SUB_LIST_OFF=	MPM_FALLBACK_CHECK="\#"

AUTHNZ_LDAP_CONFIGURE_ON=	--enable-authnz-ldap
BROTLI_CONFIGURE_WITH=		brotli=${LOCALBASE}
BROTLI_LIB_DEPENDS=		libbrotlicommon.so:archivers/brotli
HTTP2_CONFIGURE_ON=		--with-nghttp2=${LOCALBASE} \
				--with-ssl=${OPENSSLBASE}
HTTP2_LIB_DEPENDS=		libnghttp2.so:www/libnghttp2
HTTP2_USES=			ssl
IPV4_MAPPED_CONFIGURE_ENABLE=	v4-mapped
LDAP_CONFIGURE_ON=		--enable-ldap=shared
LUAJIT_LIB_DEPENDS=		libluajit-5.1.so:lang/luajit
LUA_CONFIGURE_ENV=		LUA_CFLAGS="-I${LUA_INCDIR}" \
				LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}"
LUA_CONFIGURE_WITH=		lua=${LOCALBASE}
LUA_USES=			lua
MD_CONFIGURE_ON=		--with-curl=${LOCALBASE} \
				--with-jansson=${LOCALBASE} \
				--with-ssl=${OPENSSLBASE}
MD_LIB_DEPENDS=			libcurl.so:ftp/curl \
				libjansson.so:devel/jansson
MD_USES=			ssl
PROXY_HTML_USE=			GNOME=libxml2
PROXY_HTML_USES=		gnome
PROXY_HTTP2_CONFIGURE_ON=	--with-nghttp2=${LOCALBASE}
PROXY_HTTP2_LIB_DEPENDS=	libnghttp2.so:www/libnghttp2
SOCACHE_DC_CONFIGURE_ON=	--with-distcache=${LOCALBASE}
SOCACHE_DC_LIB_DEPENDS=		libdistcache.so:security/distcache
# Note: OpenSSL version (base/ports) depends how devel/apr1 was built
#  apu-1-config --(includes|ldflags) and apr_rules.mk
SSL_CONFIGURE_ON=		--with-ssl=${OPENSSLBASE}
SSL_USES=			ssl
TLS_BROKEN=			Module removed upstream, replaced by security/mod_tls
SUEXEC_SYSLOG_CONFIGURE_ON=	--without-suexec-logfile --with-suexec-syslog
XML2ENC_USE=			GNOME=libxml2
XML2ENC_USES=			gnome

ETC_SUBDIRS=		Includes envvars.d extra modules.d

APR_CONFIG?=		${LOCALBASE}/bin/apr-1-config
APU_CONFIG?=		${LOCALBASE}/bin/apu-1-config
APU_LDAP?=		${LOCALBASE}/lib/apr-util-1/apr_ldap.so
APU_CRYPTO_OPENSSL?=	${LOCALBASE}/lib/apr-util-1/apr_crypto_openssl.so
APU_CRYPTO_NSS?=	${LOCALBASE}/lib/apr-util-1/apr_crypto_nss.so

.include <bsd.port.pre.mk>

PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}

CONFIGURE_ARGS+=--prefix=${PREFIX_RELDEST} \
		--enable-layout=FreeBSD \
		--enable-http \
		--with-pcre=${LOCALBASE} \
		--with-apr=${APR_CONFIG} \
		--with-apr-util=${APU_CONFIG}

CONFIGURE_ENV+=	LOCALBASE="${LOCALBASE}" \
		CONFIG_SHELL="${SH}"

MAKE_ENV+=	EXPR_COMPAT=yes \
		INSTALL_MAN="${INSTALL_MAN}" \
		DATADIR=${DATADIR}

.for module in ${ALL_MODULES}
.if ${PORT_OPTIONS:M${module}}
CONFIGURE_ARGS+=	--enable-${module:S/_/-/g:tl}=shared
.else
CONFIGURE_ARGS+=	--disable-${module:S/_/-/g:tl}
.endif
.endfor

#=====================================================
# here we do only OPTIONS fixups

# Check for APR-util module exists
.if exists(${APU_CONFIG})
.  if (${PORT_OPTIONS:MLDAP} || ${PORT_OPTIONS:MAUTHNZ_LDAP}) && !exists(${APU_LDAP})
IGNORE=	LDAP and AUTHNZ_LDAP requires APR-util to have LDAP support built in.\
	Please rebuild APR with LDAP support
.  endif
.  if ${PORT_OPTIONS:MSESSION_CRYPTO} && \
	!(exists(${APU_CRYPTO_OPENSSL}) || exists(${APU_CRYPTO_NSS}))
IGNORE=	SESSION_CRYPTO requires APR-util to have crypto openssl support built in.\
	Please rebuild APR with crypto openssl support
.  endif
.endif	# exists APU_CONFIG

.if ( ${PORT_OPTIONS:MAUTH_BASIC} || ${PORT_OPTIONS:MAUTH_DIGEST} ) && \
	empty(PORT_OPTIONS:MAUTHN*)
IGNORE=	AUTH_BASIC and AUTH_DIGEST need at least one AUTHN provider
.endif

.if ${PORT_OPTIONS:MAUTH_BASIC} && empty(PORT_OPTIONS:MAUTHZ*)
IGNORE=	AUTH_BASIC needs at least one AUTHZ provider
.endif

# Non options-NG option handling
.if ${PORT_OPTIONS:MXML2ENC} || ${PORT_OPTIONS:MPROXY_HTML}
CONFIGURE_ARGS+=	--with-libxml2=${LOCALBASE}/include/libxml2
.else
CONFIGURE_ARGS+=	--without-libxml2
.endif

# WITH_STATIC_SUPPORT, WITH_DEBUG, WITH_EXCEPTION_HOOK
# Only to be used for special builds
.if defined(WITH_STATIC_SUPPORT)
CONFIGURE_ARGS+=	--enable-static-support
.endif
.if defined(WITH_DEBUG)
# debug overrides CFLAGS
DEBUG_FLAGS?=	-O0 -g -ggdb3
CFLAGS=		${DEBUG_FLAGS}
CONFIGURE_ARGS+=	--enable-maintainer-mode
WITH_EXCEPTION_HOOK=	yes
.else
CONFIGURE_ENV+=	INSTALL_PROG_FLAGS="-s"
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-server_buildmark.c
.endif
.if defined(WITH_EXCEPTION_HOOK)
CONFIGURE_ARGS+=	--enable-exception-hook
.endif

pre-extract-SUEXEC-on:
	@${ECHO_CMD} ""
	@${ECHO_CMD} "suexec builds with user '${USERS}' and docroot '${PREFIX}/www' by default,"
	@${ECHO_CMD} "use SUEXEC_DOCROOT and SUEXEC_USERDIR in /etc/make.conf to adjust."
	@${ECHO_CMD} ""

post-extract:
# make sure the configure script contains our patches, preserve the original script for comparsion
	-${MV} -v ${WRKSRC}/configure ${WRKSRC}/configure.upstream

# make stage-qa script happy, it complains on empty dirs even 'PORTDOCS=*' is set
# use RMDIR in case upstream ever place some files into this directories
.for d in xsl/util xsl lang
	-${RMDIR} ${WRKSRC}/docs/manual/style/${d}
.endfor

post-patch:
	${REINPLACE_CMD} -e 's," PLATFORM ",FreeBSD,' ${WRKSRC}/server/core.c
	${REINPLACE_CMD} -e 's|logs/error_log|/var/log/httpd-error.log|' \
		${WRKSRC}/include/httpd.h
	${REINPLACE_CMD} -e 's|perlbin=.*|perlbin=${PERL}|' \
		${WRKSRC}/configure.in
	${RM} ${WRKSRC}/docs/docroot/*.bak
	${INSTALL_DATA} ${WRKSRC}/NOTICE ${WRKSRC}/docs/manual

pre-configure::
# silence autotools
	-@${MV} -v ${WRKSRC}/configure.in ${WRKSRC}/configure.ac 2>/dev/null

post-configure:
	@FTPUSERS=`${EGREP} -v '^#' /etc/ftpusers| ${TR} -s "\n" " "` ;\
		${REINPLACE_CMD} -e "s,%%FTPUSERS%%,$${FTPUSERS}," \
			${WRKSRC}/docs/conf/extra/httpd-userdir.conf
	${REINPLACE_CMD} -e "/EXTRA_LDFLAGS/s|-L/usr/lib||g" ${WRKSRC}/build/config_vars.mk
	${REINPLACE_CMD} -e "s,%%WWWOWN%%,${WWWOWN}," -e "s,%%WWWGRP%%,${WWWGRP}," \
		${WRKSRC}/docs/conf/httpd.conf
	${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/support/envvars-std

post-install:
	@${MKDIR} ${ETC_SUBDIRS:S|^|${STAGEDIR}${ETCDIR}/|}
	${INSTALL_DATA} ${FILESDIR}/no-accf.conf ${STAGEDIR}${ETCDIR}/Includes/
	${INSTALL_DATA} ${FILESDIR}/README_modules.d ${STAGEDIR}${ETCDIR}/modules.d/
	-${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/apache24/mod_*.so
	# Remove files left behind by strip
	${RM} ${STAGEDIR}${DATADIR}/build/ecp.???????? 2>/dev/null

post-install-LOG_FORENSIC-on:
	${INSTALL_SCRIPT} ${WRKSRC}/support/check_forensic ${STAGEDIR}${PREFIX}/sbin

# maintainer only, check for new modules
modlist: extract
	@${AWK} '/: checking whether to enable mod_/ \
		{printf "%%%%%s%%%%libexec/apache24/%s.so\n", \
		toupper($$8), $$8}' ${WRKSRC}/configure.upstream \
		| ${TR} -d '"' \
		| ${SORT} -u \
		| ${GREP} -E -v '^%%MOD_(HTTP|ISAPI|LOG_CONFIG|PRIVILEGES|SO|UNIXD)%%'

.include <bsd.port.post.mk>
