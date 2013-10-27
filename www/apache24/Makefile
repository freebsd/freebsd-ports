# $FreeBSD$

PORTNAME=	apache24
PORTVERSION=	2.4.6
CATEGORIES=	www ipv6
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
DISTNAME=	httpd-${PORTVERSION}
DIST_SUBDIR=	apache24

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Version 2.4.x of Apache web server

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libapr-1.so:${PORTSDIR}/devel/apr1 \
		libpcre.so:${PORTSDIR}/devel/pcre

CONFLICTS_INSTALL=	caudium14-1.* \
		apache-*-2.2.* apache22-*

USE_APACHE=	common24
USES=		iconv perl5
USE_PERL5=	run
USE_AUTOTOOLS=	autoconf libtool
USE_RC_SUBR=	apache24 htcacheclean
LIBTOOLFILES=	configure.in

PORTDOCS=	*

USERS=		www
GROUPS=		www

# for slave ports
.if !defined(MASTERDIR)
APACHEDIR=	${.CURDIR}
.else
APACHEDIR=	${MASTERDIR}
.endif

WITH_HTTP_PORT?=	80
WITH_SSL_PORT?=		443

.include "${APACHEDIR}/Makefile.options"
.include "${APACHEDIR}/Makefile.options.desc"

AUTHNZ_LDAP_CONFIGURE_ON=	--enable-authnz-ldap

# http://httpd.apache.org/docs/2.4/bind.html
IPV4_MAPPED_CONFIGURE_OFF=	--disable-v4-mapped
IPV4_MAPPED_CONFIGURE_ON=	--enable-v4-mapped

LDAP_CONFIGURE_ON=		--enable-ldap=shared

LUAJIT_LIB_DEPENDS=		luajit:${PORTSDIR}/lang/luajit
LUA_CONFIGURE_OFF=		--without-lua
LUA_CONFIGURE_ON=		--with-lua=${LOCALBASE}

SOCACHE_DC_CONFIGURE_ON=	--with-distcache=${LOCALBASE}
SOCACHE_DC_LIB_DEPENDS=		distcache:${PORTSDIR}/security/distcache

SSL_CFLAGS=			-I${OPENSSLINC}
SSL_CONFIGURE_ON=		--with-ssl=${OPENSSLBASE}
SSL_LDFLAGS=			-L${OPENSSLLIB}
SSL_USE=			OPENSSL=yes

.include <bsd.port.options.mk>

ETC_SUBDIRS=		Includes envvars.d extra

.if ! ${PORT_OPTIONS:MDOCS}
MAKE_ENV+=	NOPORTDOCS=yes
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

PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}

CONFIGURE_ARGS+=--prefix=${PREFIX_RELDEST} \
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

.if ${PORT_OPTIONS:MLUA}
USE_LUA=	5.1+
LUA_COMPS=	lua
.endif

.if ${PORT_OPTIONS:MPROXY_HTML} || ${PORT_OPTIONS:MXML2ENC}
USE_GNOME=	libxml2
.endif

.include <bsd.port.pre.mk>
.include "${APACHEDIR}/Makefile.modules"

pre-configure::
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"  You can check your modules configuration by using make show-modules"
	@${ECHO_MSG}	""

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

post-configure:
	@FTPUSERS=`${EGREP} -v '^#' /etc/ftpusers| ${TR} -s "\n" " "` ;\
	${REINPLACE_CMD} -e "s,%%FTPUSERS%%,$${FTPUSERS}," ${WRKSRC}/docs/conf/extra/httpd-userdir.conf
	@${REINPLACE_CMD} -e "s,%%WWWOWN%%,${WWWOWN}," -e "s,%%WWWGRP%%,${WWWGRP}," ${WRKSRC}/docs/conf/httpd.conf
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/support/envvars-std

post-install:
	@${MKDIR} ${ETC_SUBDIRS:S|^|${STAGEDIR}${ETCDIR}/|}
	@${INSTALL_DATA} ${FILESDIR}/no-accf.conf ${STAGEDIR}${ETCDIR}/Includes/

.if ${PORT_OPTIONS:MLOG_FORENSIC}
	@${INSTALL_SCRIPT} ${WRKSRC}/support/check_forensic ${STAGEDIR}${PREFIX}/sbin
.endif

# maintainer only, check for new modules
modlist: extract
	@${AWK} '/: checking whether to enable mod_/ \
		{printf "%%%%%s%%%%libexec/apache24/%s.so\n", \
		toupper($$8), $$8}' ${WRKSRC}/configure \
		| ${TR} -d '"' \
		| ${SORT} -u \
		| ${GREP} -E -v '^%%MOD_(HTTP|ISAPI|LOG_CONFIG|PRIVILEGES|SO|UNIXD)%%'

.include <bsd.port.post.mk>
