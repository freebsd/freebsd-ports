# New ports collection makefile for:	squid24
# Date created:		Tue Mar 27 14:56:08 CEST 2001
# Whom:			Adrian Chadd <adrian@FreeBSD.org>
#
# $FreeBSD$
#
# Tunables not (yet) configurable via 'make config':
# SQUID_{U,G}ID
#   Which user/group squid should run as (default: squid/squid).
#   The user and group will be created if they do not already exist.
#   NOTE: before version 2.5.4_6, these settings defaulted to
#   nobody/nogroup.
#   If you wish to keep these settings, please define SQUID_UID=nobody and
#   SQUID_GID=nogroup in your make environment before you start the update.
# SQUID_LANGUAGES
#   A list of languages for which error page files should be installed
#   (default: all)
# SQUID_DEFAULT_LANG
#   If you define SQUID_LANGUAGES, select which language should be the default
#   (default: English)
# SQUID_CONFIGURE_ARGS
#   Additional configuration options, see below for a list

PORTNAME=	squid
PORTVERSION=	2.5.4
PORTREVISION=	8
CATEGORIES=	www
MASTER_SITES=	\
		ftp://ftp.squid-cache.org/pub/%SUBDIR%/ \
		ftp://ftp.unimelb.edu.au/pub/cwis/servers/unix/squid/%SUBDIR%/ \
		ftp://sunsite.auc.dk/pub/infosystems/squid/%SUBDIR%/ \
		ftp://ftp.leo.org/pub/comp/general/infosys/www/servers/squid/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/squid/&,}
MASTER_SITE_SUBDIR=	squid-2/STABLE
DISTNAME=	squid-2.5.STABLE4
DIST_SUBDIR=	squid2.5

PATCH_SITES=	http://www.squid-cache.org/Versions/v2/2.5/bugs/
PATCHFILES=	squid-2.5.STABLE4-reconfigure_message.patch \
		squid-2.5.STABLE4-digest_auth_pwchange.patch \
		squid-2.5.STABLE4-redirect_login_space.patch \
		squid-2.5.STABLE4-fqdnnegcache.patch \
		pam_auth-2.2.patch \
		squid-2.5.STABLE4_auth_param_doc.patch \
		squid-2.5.STABLE4-errorpages.patch \
		squid-2.5.STABLE4-error_load_text.patch \
		squid-2.5.STABLE4-xpi_mime.patch \
		squid-2.5.STABLE4-size_overflow.patch \
		squid-2.5.STABLE4-extacl_auth_loop.patch \
		squid-2.5.STABLE4-squid_ldap_group.patch \
		squid-2.5.STABLE4-positive_dns_ttl.patch \
		squid-2.5.STABLE4-gopherhtml.patch \
		squid-2.5.STABLE4-netroute.patch \
		squid-2.5.STABLE4-synflood.patch \
		squid-2.5.STABLE4-fqdn.patch \
		squid-2.5.STABLE4-connect_cleanup.patch \
		squid-2.5.STABLE4-pconn_post.patch \
		squid-2.5.STABLE4-ftp_put.patch \
		squid-2.5.STABLE4-pconn-load.patch \
		squid-2.5.STABLE4-icon_urls.patch \
		squid-2.5.STABLE4-redirector_access.patch \
		squid-2.5.STABLE4-pconn-lifo.patch \
		squid-2.5.STABLE4-cache_peer_maxconn.patch \
		squid-2.5.STABLE4-pid_filename_none.patch \
		squid-2.5.STABLE4-dns_namelength.patch \
		squid-2.5.STABLE4-urllogin_acl.patch \
		squid-2.5.STABLE4-russian.patch \
		squid-2.5.STABLE4-redirlog.patch \
		squid-2.5.STABLE4-pinger.patch \
		squid-2.5.STABLE4-partial_reload.patch \
		squid-2.5.STABLE4-ldap_tls.patch \
		squid-2.5.STABLE4-ldap_group_bufsize.patch \
		squid-2.5.STABLE4-http_workarounds.patch \
		squid-2.5.STABLE4-empty_proxy_auth.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	tmseck@netcologne.de
COMMENT=	The successful WWW proxy cache and accelerator

CONFLICTS=	squid-*
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes

SQUID_UID?=	squid
SQUID_GID?=	squid

MAN8=		squid.8
docs=		QUICKSTART README RELEASENOTES.html doc/debug-sections.txt
.if !defined(NOPORTDOCS)
PORTDOCS=	${docs:T}
.endif

OPTIONS=	SQUID_LDAP_AUTH "Install LDAP authentication helpers" off \
		SQUID_DELAY_POOLS "Enable delay pools" off \
		SQUID_SNMP "Enable SNMP support" off \
		SQUID_CARP "Enable CARP support" off \
		SQUID_SSL "Enable SSL support for reverse proxies" off \
		SQUID_PINGER "Install the icmp helper" off \
		SQUID_DNS_HELPER "Use the old 'dnsserver' helper" off \
		SQUID_HTCP "Enable HTCP support" off \
		SQUID_VIA_DB "Enable forward/via database" off \
		SQUID_CACHE_DIGESTS "Enable cache digests" off \
		SQUID_WCCP "Enable Web Cache Coordination Protocol" on \
		SQUID_STRICT_HTTP "Be strictly HTTP compliant" off \
		SQUID_IDENT "Enable ident (RFC 931) lookups" on \
		SQUID_USERAGENT_LOG "Enable User-Agent-header logging" off

PLIST_FILES=	etc/rc.d/squid.sh etc/squid/mib.txt etc/squid/mime.conf.default \
		etc/squid/msntauth.conf.default etc/squid/squid.conf.default \
		sbin/RunAccel sbin/RunCache sbin/squidclient sbin/squid

CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin  --sysconfdir=${PREFIX}/etc/squid \
		--datadir=${PREFIX}/etc/squid \
		--libexecdir=${PREFIX}/libexec/squid \
		--localstatedir=${PREFIX}/squid \
		--enable-storeio="ufs diskd null" \
		--enable-removal-policies="lru heap" \
		--enable-underscores

.include <bsd.port.pre.mk>

# Authentication methods and modules:

basic_auth=	NCSA PAM YP MSNT winbind
external_acl=	ip_user unix_group wbinfo_group winbind_group
MAN8+=		pam_auth.8 squid_unix_group.8
.if defined(WITH_SQUID_LDAP_AUTH)
USE_OPENLDAP=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAN8+=		squid_ldap_auth.8 squid_ldap_group.8
basic_auth+=	LDAP
external_acl+=	ldap_group
.endif
CONFIGURE_ARGS+=	--enable-auth="basic ntlm digest" \
			--enable-basic-auth-helpers="${basic_auth}" \
			--enable-digest-auth-helpers="password" \
			--enable-external-acl-helpers="${external_acl}" \
			--enable-ntlm-auth-helpers="SMB winbind"

# Options set via 'make config':

.if defined(WITH_SQUID_DELAY_POOLS)
CONFIGURE_ARGS+=	--enable-delay-pools
.endif
.if defined(WITH_SQUID_SNMP)
CONFIGURE_ARGS+=	--enable-snmp
.endif
.if defined(WITH_SQUID_CARP)
CONFIGURE_ARGS+=	--enable-carp
.endif
.if defined(WITH_SQUID_SSL)
CONFIGURE_ARGS+=	--enable-ssl
.endif
.if defined(WITH_SQUID_PINGER)
CONFIGURE_ARGS+=	--enable-icmp
.endif
.if defined(WITH_SQUID_DNS_HELPER)
CONFIGURE_ARGS+=	--disable-internal-dns
.endif
.if defined(WITH_SQUID_HTCP)
CONFIGURE_ARGS+=	--enable-htcp
.endif
.if defined(WITH_SQUID_VIA_DB)
CONFIGURE_ARGS+=	--enable-forw-via-db
.endif
.if defined(WITH_SQUID_CACHE_DIGESTS)
CONFIGURE_ARGS+=	--enable-cache-digests
.endif
.if defined(WITHOUT_SQUID_WCCP)
CONFIGURE_ARGS+=	--disable-wccp
.endif
.if defined(WITH_SQUID_STRICT_HTTP)
CONFIGURE_ARGS+=	--disable-http-violations
.endif
.if defined(WITHOUT_SQUID_IDENT)
CONFIGURE_ARGS+=	--disable-ident-lookups
.endif
.if defined(WITH_SQUID_USERAGENT_LOG)
CONFIGURE_ARGS+=	--enable-useragent-log
.endif

# Languages:
#
# If you do not define SQUID_LANGUAGES yourself, all available language files
# will be installed; the default language will be english.

SQUID_LANGUAGES?=	\
	Bulgarian Catalan Czech Danish Dutch English Estonian Finnish      \
	French German Hebrew Hungarian Italian Japanese Korean Lithuanian  \
	Polish Portuguese Romanian Russian-1251 Russian-koi8-r Serbian     \
	Simplify_Chinese Slovak Spanish Swedish Traditional_Chinese Turkish
SQUID_DEFAULT_LANG?=	English
CONFIGURE_ARGS+=	--enable-err-languages="${SQUID_LANGUAGES}" \
			--enable-default-err-language=${SQUID_DEFAULT_LANG}

# Other not so common configure options you can set via SQUID_CONFIGURE_ARGS:
# Please see the configure script in the squid source distribution for a
# complete list.
#
# --enable-dlmalloc
#  Compile and use the malloc package from Doug Lea
# --enable-gnuregex
#  Compile and use the supplied GNUregex routines instead of BSD regex.
# --enable-xmalloc-statistics
#  Show malloc statistics in status page
# --enable-time-hack
#  Optimize time updates to one per second rather than calling gettimeofday()
# --enable-cachemgr-hostname=some.hostname
#  Set an explicit hostname in cachemgr.cgi
# --enable-truncate
#  Use truncate() rather than unlink()
# --disable-hostname-checks
#  Squid by default rejects any host names with odd characters in their name
#  to conform with internet standards. If you disagree with this you may use
#  this switch to turn off any such checks, provided that the resolver used by
#  Squid does not reject such host names. This may be required to participate
#  in testbeds for international domain names.
# --disable-unlinkd
#  Do not use "unlinkd"
# --enable-stacktraces
#  Enable automatic call backtrace on fatal errors
#
# These options do not yet work on FreeBSD:
#
# --enable-arp-acl
#  Enable ACL based on ethernet address (eg: for machines with dynamic DHCP
#  assigned IP addresses)
# --enable-ipf-transparent
#  Enable Transparent Proxy support for IP-Filter systems (incl 3.0)
#  (IPFilter headers are not currently installed to the base system,
#  PRs ports/60700 and misc/44148 describe the problem; see
#  http://www.squid-cache.org/Doc/FAQ/FAQ-17.html for information
#  about how to do transparent proxying with ipfw)

CONFIGURE_ARGS+=	${SQUID_CONFIGURE_ARGS}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/doc/squid.8
# Prevent installation of .orig files by deleting them.
	@${FIND} ${WRKSRC} -name '*.bak' -delete
	@${FIND} ${WRKSRC} -name '*.orig' -delete

pre-configure:
	@${REINPLACE_CMD} -e 's|%%SQUID_UID%%|${SQUID_UID}|g' \
	    -e 's|%%SQUID_GID%%|${SQUID_GID}|g' ${WRKSRC}/src/cf.data.pre

pre-install:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
	    -e 's|%%SQUID_UID%%|${SQUID_UID}|g' ${FILESDIR}/squid.sh \
	    >${WRKDIR}/squid.sh

pre-su-install:
	@${SETENV} SQUID_UID=${SQUID_UID} SQUID_GID=${SQUID_GID} \
	    PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if defined(WITH_SQUID_PINGER)
	${CHMOD} 4710 ${PREFIX}/libexec/squid/pinger; \
	${CHGRP} ${SQUID_GID} ${PREFIX}/libexec/squid/pinger
.endif
	${INSTALL_SCRIPT} ${WRKDIR}/squid.sh ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${docs} ${DOCSDIR}
.endif

# Work around the fact that the errorpages.patch creates files in
# an "Attic" subdir:
.if exists(${PREFIX}/etc/squid/errors/Lithuanian)
	@${FIND} ${WRKSRC}/errors/Lithuanian/Attic -type f \
   	    -exec ${INSTALL_DATA} {} ${PREFIX}/etc/squid/errors/Lithuanian/ \;
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
# Create package list:
	@cd ${PREFIX} && ${FIND} libexec/squid -type f -o -type l | ${SORT} \
	    >>${TMPPLIST}
	@${ECHO_CMD} "@dirrm libexec/squid" >>${TMPPLIST}
	@cd ${PREFIX} && ${FIND} etc/squid/icons -type f -o -type l | ${SORT} \
	    >>${TMPPLIST}
	@${ECHO_CMD} "@dirrm etc/squid/icons" >>${TMPPLIST}
.for d in ${SQUID_LANGUAGES}
	@cd ${PREFIX} && ${FIND} etc/squid/errors/${d} -type f | ${SORT} \
	    >>${TMPPLIST}
	@${ECHO_CMD} "@dirrm etc/squid/errors/${d}" >>${TMPPLIST}
.endfor
	@${ECHO_CMD} "@dirrm etc/squid/errors" >>${TMPPLIST}

.include <bsd.port.post.mk>
