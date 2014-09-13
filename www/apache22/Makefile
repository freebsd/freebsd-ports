# $FreeBSD$

PORTNAME=	apache22
PORTVERSION=	2.2.29
PORTREVISION?=	0
CATEGORIES=	www ipv6
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
DISTNAME=	httpd-${PORTVERSION}
DIST_SUBDIR=	apache22

MAINTAINER?=	apache@FreeBSD.org
COMMENT?=	Version 2.2.x of Apache web server with ${WITH_MPM} MPM.

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libapr-1.so:${PORTSDIR}/devel/apr1 \
		libpcre.so:${PORTSDIR}/devel/pcre

CONFLICTS_INSTALL=	caudium14-1.* \
		apache-*-2.2.* apache22-*-2.2.* \
		apache-*-2.4.* apache24-*-2.4.*

USE_APACHE=	common22
USES=		tar:bzip2 iconv perl5 libtool cpe
USE_PERL5=	run
USE_AUTOTOOLS=	autoconf
USE_RC_SUBR=	apache22 htcacheclean

CPE_VENDOR=	apache
CPE_PRODUCT=	http_server

PORTDOCS=	*

USERS=		www
GROUPS=		www

# for slave ports
.if !defined(MASTERDIR)
APACHEDIR=	${.CURDIR}
.else
APACHEDIR=	${MASTERDIR}
.endif

WITH_MPM?=		prefork # or worker, event, itk, peruser
WITH_HTTP_PORT?=	80
WITH_SSL_PORT?=		443

.include "${APACHEDIR}/Makefile.options"

AUTHNZ_LDAP_CONFIGURE_ON=	--enable-authnz-ldap

# http://httpd.apache.org/docs/2.2/bind.html
IPV4_MAPPED_CONFIGURE_ENABLE=	v4-mapped

LDAP_CONFIGURE_ON=		--enable-ldap=shared
SSL_CFLAGS=			-I${OPENSSLINC}
SSL_CONFIGURE_ON=		--with-ssl=${OPENSSLBASE}
SSL_LDFLAGS=			-L${OPENSSLLIB}
SSL_USE=			OPENSSL=yes

SUEXEC_RSRCLIMIT_EXTRA_PATCHES=	${FILESDIR}/extra-patch-suexec_rsrclimit
SUEXEC_USERDIR_EXTRA_PATCHES=	${FILESDIR}/extra-patch-suexec_userdir

.include <bsd.port.options.mk>

ETC_SUBDIRS=		Includes envvars.d extra modules.d

# PR: 182947
.if ${WITH_MPM} != "peruser"
SUB_LIST+=	RELOAD_CMD=graceful
.else
SUB_LIST+=	RELOAD_CMD=hrestart
.endif

APR_CONFIG?=		${LOCALBASE}/bin/apr-1-config
APU_CONFIG?=		${LOCALBASE}/bin/apu-1-config

# APU modules used by AUTHN_DBD DBD
APU_DBD_MYSQL?=		${LOCALBASE}/lib/apr-util-1/apr_dbd_mysql.so
APU_DBD_PGSQL?=		${LOCALBASE}/lib/apr-util-1/apr_dbd_pgsql.so
APU_DBD_SQLITE3?=	${LOCALBASE}/lib/apr-util-1/apr_dbd_sqlite3.so
# APU module used by AUTHNZ_LDAP LDAP
APU_LDAP?=		${LOCALBASE}/lib/apr-util-1/apr_ldap.so
# APU module used by SESSION_CRYPTO
APU_CRYPTO_OPENSSL?=	${LOCALBASE}/lib/apr-util-1/apr_crypto_openssl.so
APU_CRYPTO_NSS?=	${LOCALBASE}/lib/apr-util-1/apr_crypto_nss.so

CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--enable-layout=FreeBSD \
		--with-port=${WITH_HTTP_PORT} \
		--with-sslport=${WITH_SSL_PORT} \
		--with-expat=${LOCALBASE} \
		--with-iconv=${ICONV_PREFIX} \
		--enable-http \
		--with-pcre=${LOCALBASE} \
		--with-apr=${APR_CONFIG} \
		--with-apr-util=${APU_CONFIG}

CONFIGURE_ENV=	\
		CONFIG_SHELL="${SH}" \
		LOCALBASE="${LOCALBASE}"

MAKE_ENV+=	EXPR_COMPAT=yes \
		INSTALL_MAN="${INSTALL_MAN}" \
		EXAMPLESDIR=${EXAMPLESDIR}

#=====================================================
# CONFIGURE_ARGS will be handled in Makefile.modules,
# here we do only OPTIONS fixups

.if ${PORT_OPTIONS:MSUEXEC_RSRCLIMIT} && !${PORT_OPTIONS:MSUEXEC}
IGNORE=		suEXEC resource limit patch requires mod_suexec.\
		Please (re)run 'make config' and choose SUEXEC option also
.endif

.if ${PORT_OPTIONS:MSUEXEC_USERDIR} && !${PORT_OPTIONS:MSUEXEC}
IGNORE=		suEXEC UserDir patch requires mod_suexec.\
		Please (re)run 'make config' and choose SUEXEC option also
.endif

.include <bsd.port.pre.mk>
.include "${APACHEDIR}/Makefile.modules"

show-options:
	@${SED} -ne 's/^##//p' ${APACHEDIR}/Makefile.doc

pre-everything::
	@${CAT}	${FILESDIR}/HEADS_UP
.if !defined(BATCH) || !defined(PORT_BUILDING)
	@/bin/sleep 5
.endif

post-extract:
# remove possible leftover .svn directories in the sources
	@${FIND} ${WRKSRC} -type d -name .svn -print | ${XARGS} ${RM} -rf
# limit grep results ...
	@${FIND} ${WRKSRC} -type f \( -name 'NWGNU*' -o -name '*.ds?' -o -name '*.dep' -o -name '*.mak' -o -name '*.win' \) -delete

post-patch:
	@${REINPLACE_CMD} -e 's," PLATFORM ",FreeBSD,' ${WRKSRC}/server/core.c
# IPv4_mapping fix: https://issues.apache.org/bugzilla/show_bug.cgi?id=53824
	@${REINPLACE_CMD} -e 's|freebsd5|freebsd|' \
		-e 's|^perlbin=.*|perlbin=${PERL}|' \
		${WRKSRC}/configure.in ${WRKSRC}/configure
	@${RM} -f ${WRKSRC}/docs/docroot/*.bak
	@${INSTALL_DATA} ${WRKSRC}/NOTICE ${WRKSRC}/docs/manual
# we use devel/apr and devel/pcre
	@${RM} -rf ${WRKSRC}/srclib
	@${REINPLACE_CMD} -e 's/srclib//' ${WRKSRC}/Makefile.in

pre-configure::
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"  You can check your modules configuration by using make show-modules"
	@${ECHO_MSG}	""

# Fix build with OpenSSL from ports
.if ${PORT_OPTIONS:MSSL}
. if ${OPSYS} == FreeBSD
.  if defined(OPENSSL_INSTALLED) && ${OPENSSL_INSTALLED} != ""
	@${ECHO_MSG}	"===>  apply fix for FreeBSD-${OSREL} (${OSVERSION}) for usage with ${OPENSSL_INSTALLED}"
	@${ECHO_MSG}	""
	${REINPLACE_CMD} -e "s|(ALL_CFLAGS)|(ALL_CFLAGS) -L${OPENSSLLIB}|" ${WRKSRC}/build/rules.mk.in
.  endif
. endif
.endif

post-configure:
	@FTPUSERS=`${EGREP} -v '^#' /etc/ftpusers| ${TR} -s "\n" " "` ;\
	${REINPLACE_CMD} -e "s,%%FTPUSERS%%,$${FTPUSERS}," ${WRKSRC}/docs/conf/extra/httpd-userdir.conf
	@${REINPLACE_CMD} -e "s,%%WWWOWN%%,${WWWOWN}," -e "s,%%WWWGRP%%,${WWWGRP}," ${WRKSRC}/docs/conf/httpd.conf
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/support/envvars-std

post-install:
	@${MKDIR} ${ETC_SUBDIRS:S|^|${STAGEDIR}${ETCDIR}/|}
	${INSTALL_DATA} ${FILESDIR}/no-accf.conf ${STAGEDIR}${ETCDIR}/Includes/
	${INSTALL_DATA} ${FILESDIR}/README_modules.d ${STAGEDIR}${ETCDIR}/modules.d/
# place for module configuration samples
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}/modules.d
	${INSTALL_DATA} ${FILESDIR}/README_modules.d ${STAGEDIR}${EXAMPLESDIR}/modules.d

# suppress warning for non binary files
	-@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/* \
		${STAGEDIR}${PREFIX}/libexec/apache22/*.so 2>/dev/null
.if ${PORT_OPTIONS:MLOG_FORENSIC}
	@${INSTALL_SCRIPT} ${WRKSRC}/support/check_forensic ${STAGEDIR}${PREFIX}/sbin
.endif

# maintainer only, check for new modules
modlist: extract
	@${AWK} '/: checking whether to enable mod_/ \
		{printf "%%%%%s%%%%libexec/apache22/%s.so\n", \
		toupper($$8), $$8}' ${WRKSRC}/configure \
		| ${TR} -d '"' \
		| ${SORT} -u \
		| ${GREP} -E -v '^%%MOD_(ECHO|EXAMPLE|HTTP|IDENT|ISAPI|SO)%%'

.include <bsd.port.post.mk>
