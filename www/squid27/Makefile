# New ports collection makefile for:	squid24
# Date created:		Tue Mar 27 14:56:08 CEST 2001
# Whom:			Adrian Chadd <adrian@FreeBSD.org>
#
# $FreeBSD$
#
# Tunables:
# WITH_SQUID_PINGER
#   install the external icmp helper program (`pinger') for hierarchy stats and
#   selection
# WITH_SQUID_LDAP_AUTH
#   install external modules for authentication against LDAP servers
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
PORTREVISION=	6
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
		squid-2.5.STABLE4-http_workarounds.patch
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
DOCS=		QUICKSTART README RELEASENOTES.html doc/debug-sections.txt

CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin  --sysconfdir=${PREFIX}/etc/squid \
		--datadir=${PREFIX}/etc/squid \
		--libexecdir=${PREFIX}/libexec/squid \
		--localstatedir=${PREFIX}/squid \
		--enable-storeio="ufs diskd null" \
		--enable-removal-policies="lru heap" \
		--enable-underscores

.if defined(WITH_SQUID_PINGER)
CONFIGURE_ARGS+=	--enable-icmp
.endif

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
			--enable-ntlm-auth-helpers="winbind"

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

# Other configure options you might want to set using SQUID_CONFIGURE_ARGS:
# Please see the configure script in the squid source distribution for a
# complete list.
#
# --enable-dlmalloc
#  Compile and use the malloc package from Doug Lea
# --enable-gnuregex
#  Compile and use the supplied GNUregex routines instead of BSD regex.
# --enable-xmalloc-statistics
#  Show malloc statistics in status page
# --enable-carp
#  Enable CARP support
# --enable-delay-pools
#  Enable delay pools to limit bandwidth usage
# --enable-useragent-log
#  Enable logging of the User-Agent header
# --disable-wccp
#  Disable Web Cache Coordination Protocol
# --enable-snmp
#  Turn on SNMP server support
# --enable-ssl
#  Turn on SSL server support for reverse proxies
# --enable-time-hack
#  Optimize time updates to one per second rather than calling gettimeofday()
# --enable-cachemgr-hostname=some.hostname
#  Set an explicit hostname in cachemgr.cgi
# --enable-arp-acl
#  Enable ACL based on ethernet address (eg: for machines with dynamic DHCP
#  assigned IP addresses)
# --enable-htcp
#  Enable HTCP protocol
# --enable-forw-via-db
#  Enable Forw/Via database
# --enable-cache-digests
#  Use Cache Digests - see http://www.squid-cache.org/Doc/FAQ/FAQ-16.html
# --disable-http-violations
#  Strict HTTP compliance
# --enable-ipf-transparent
#  Enable Transparent Proxy support for IP-Filter systems (incl 3.0)
#  (Note: this is currently broken due to ipf headers not being installed to
#  the base system, see PRs ports/60700 and misc/44148 for details)
#  Note: see http://www.squid-cache.org/Doc/FAQ/FAQ-17.html for information
#  about how to do transparent proxying with ipfw(8).
# --disable-ident-lookups
#  Compile out code that does optional Ident (RFC931) lookups
# --disable-internal-dns
#  Install the old external "dnsserver" binary
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
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.if exists(${PREFIX}/etc/squid/errors/Lithuanian)
# Work around the fact that the errorpages.patch creates files in
# an "Attic" subdir:
	@${FIND} ${WRKSRC}/errors/Lithuanian/Attic -type f \
   	    -exec ${INSTALL_DATA} {} ${PREFIX}/etc/squid/errors/Lithuanian/ \;
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
# Generate parts of pkg-plist on the fly:
	@cd ${PREFIX} && ${FIND} libexec/squid -type f -o -type l \
	    >${WRKDIR}/plist.dynamic
	@${ECHO_CMD} "@dirrm libexec/squid" >>${WRKDIR}/plist.dynamic
# Only register what we should have installed, there may be local additions
# present:
.for d in ${SQUID_LANGUAGES}
	@cd ${PREFIX} && ${FIND} etc/squid/errors/${d} -type f \
	    >>${WRKDIR}/plist.dynamic
	@${ECHO_CMD} "@dirrm etc/squid/errors/${d}" >>${WRKDIR}/plist.dynamic
.endfor
	@${ECHO_CMD} "r ${TMPPLIST}" >${WRKDIR}/ex.script
	@${ECHO_CMD} "/Start of dynamically generated plist" >>${WRKDIR}/ex.script
	@${ECHO_CMD} "r ${WRKDIR}/plist.dynamic" >>${WRKDIR}/ex.script
	@${ECHO_CMD} "x!" >>${WRKDIR}/ex.script
	@${CP} -p ${TMPPLIST} ${TMPPLIST}.orig
	@cd ${WRKDIR} && ex <ex.script >/dev/null

.include <bsd.port.mk>
