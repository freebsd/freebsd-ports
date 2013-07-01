# Created by: Adrian Chadd <adrian@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cacheboy
DISTVERSION=	1.5.2
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	CACHEBOY_1.5.2
# EXTRACT_SUFX=	.tar.gz
DIST_SUBDIR=	CACHEBOY_1.5.2

MAINTAINER=	adrian@FreeBSD.org
COMMENT=	HTTP Caching Proxy (Squid Derivative) - Development Release

DEPRECATED=	Broken on FreeBSD 8 and newer
EXPIRATION_DATE=2013-09-01

CONFLICTS=	squid-[0-9]* cacheboy*
LATEST_LINK=	cacheboy15-devel
GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_RC_SUBR=	squid

SQUID_UID?=	squid
SQUID_GID?=	squid

MAN8=		cachemgr.cgi.8 squid.8
docs=		QUICKSTART README.Squid ChangeLog.Cacheboy doc/debug-sections.txt
PORTDOCS=	${docs:T}
PORTEXAMPLES=	passwd.sql
SUB_FILES+=	pkg-deinstall pkg-install pkg-message
SUB_LIST+=	SQUID_UID=${SQUID_UID} SQUID_GID=${SQUID_GID}

OPTIONS_DEFINE=	DOCS NLS SQUID_LDAP_AUTH SQUID_SASL_AUTH SQUID_DELAY_POOLS SQUID_SNMP \
		SQUID_CARP SQUID_SSL SQUID_PINGER SQUID_DNS_HELPER SQUID_HTCP SQUID_VIA_DB \
		SQUID_CACHE_DIGESTS SQUID_WCCP SQUID_WCCPV2 SQUID_STRICT_HTTP SQUID_IDENT \
		SQUID_REFERER_LOG SQUID_USERAGENT_LOG SQUID_ARP_ACL SQUID_PF SQUID_IPFILTER \
		SQUID_FOLLOW_XFF SQUID_AUFS SQUID_COSS SQUID_KQUEUE SQUID_LARGEFILE \
		SQUID_STACKTRACES
OPTIONS_DEFAULT=	SQUID_CARP SQUID_WCCP SQUID_KQUEUE
SQUID_LDAP_AUTH_DESC=		Install LDAP authentication helpers
SQUID_SASL_AUTH_DESC=		Install SASL authentication helpers
SQUID_DELAY_POOLS_DESC=		Enable delay pools
SQUID_SNMP_DESC=		Enable SNMP support
SQUID_CARP_DESC=		Enable CARP support
SQUID_SSL_DESC=			Enable SSL support for reverse proxies
SQUID_PINGER_DESC=		Install the icmp helper
SQUID_DNS_HELPER_DESC=		Use the old 'dnsserver' helper
SQUID_HTCP_DESC=		Enable HTCP support
SQUID_VIA_DB_DESC=		Enable forward/via database
SQUID_CACHE_DIGESTS_DESC=	Enable cache digests
SQUID_WCCP_DESC=		Enable Web Cache Coordination Prot. v1
SQUID_WCCPV2_DESC=		Enable Web Cache Coordination Prot. v2
SQUID_STRICT_HTTP_DESC=		Be strictly HTTP compliant
SQUID_IDENT_DESC=		Enable ident (RFC 931) lookups
SQUID_REFERER_LOG_DESC=		Enable Referer-header logging
SQUID_USERAGENT_LOG_DESC=	Enable User-Agent-header logging
SQUID_ARP_ACL_DESC=		Enable ACLs based on ethernet address
SQUID_PF_DESC=			Enable transparent proxying with PF
SQUID_IPFILTER_DESC=		Enable transp. proxying with IPFilter
SQUID_FOLLOW_XFF_DESC=		Follow X-Forwarded-For headers
SQUID_AUFS_DESC=		Enable the aufs storage scheme
SQUID_COSS_DESC=		Enable the COSS storage scheme
SQUID_KQUEUE_DESC=		Use kqueue(2) instead of poll(2)
SQUID_LARGEFILE_DESC=		Support log and cache files >2GB
SQUID_STACKTRACES_DESC=		Create backtraces on fatal errors

etc_files=	squid/cachemgr.conf.default \
		squid/mib.txt squid/mime.conf.default \
		squid/msntauth.conf.default squid/squid.conf.default

icon_files=	anthony-binhex.gif anthony-bomb.gif anthony-box.gif \
		anthony-box2.gif anthony-c.gif anthony-compressed.gif \
		anthony-dir.gif anthony-dirup.gif anthony-dvi.gif \
		anthony-f.gif anthony-image.gif anthony-image2.gif \
		anthony-layout.gif anthony-link.gif anthony-movie.gif \
		anthony-pdf.gif anthony-portal.gif anthony-ps.gif \
		anthony-quill.gif anthony-script.gif anthony-sound.gif \
		anthony-tar.gif anthony-tex.gif anthony-text.gif \
		anthony-unknown.gif anthony-xbm.gif anthony-xpm.gif

error_files=	ERR_ACCESS_DENIED ERR_CACHE_ACCESS_DENIED \
		ERR_CACHE_MGR_ACCESS_DENIED ERR_CANNOT_FORWARD \
		ERR_CONNECT_FAIL ERR_DNS_FAIL ERR_FORWARDING_DENIED \
		ERR_FTP_DISABLED ERR_FTP_FAILURE ERR_FTP_FORBIDDEN \
		ERR_FTP_NOT_FOUND ERR_FTP_PUT_CREATED \
		ERR_FTP_PUT_ERROR ERR_FTP_PUT_MODIFIED ERR_FTP_UNAVAILABLE \
		ERR_INVALID_REQ ERR_INVALID_RESP ERR_INVALID_URL \
		ERR_LIFETIME_EXP ERR_NO_RELAY ERR_ONLY_IF_CACHED_MISS \
		ERR_READ_ERROR ERR_READ_TIMEOUT ERR_SHUTTING_DOWN \
		ERR_SOCKET_FAILURE ERR_TOO_BIG ERR_UNSUP_REQ \
		ERR_URN_RESOLVE ERR_WRITE_ERROR ERR_ZERO_SIZE_OBJECT

libexec=	cachemgr.cgi digest_pw_auth diskd-daemon logfile-daemon \
		ip_user_check \
		msnt_auth ncsa_auth ntlm_auth \
		pam_auth smb_auth smb_auth.sh squid_db_auth squid_session \
		squid_unix_group wbinfo_group.pl
.if !defined(SQUID_CONFIGURE_ARGS) || ${SQUID_CONFIGURE_ARGS:M*--disable-unlinkd*} == ""
libexec+=	unlinkd
.endif

sbin=		RunCache squidclient squid

CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin  \
		--sbindir=${PREFIX}/sbin  \
		--datadir=${PREFIX}/etc/squid \
		--libexecdir=${PREFIX}/libexec/squid \
		--localstatedir=${PREFIX}/squid \
		--sysconfdir=${PREFIX}/etc/squid \
		--enable-removal-policies="lru heap" \
		--disable-linux-netfilter \
		--disable-linux-tproxy \
		--disable-epoll

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 800037
BROKEN=		does not compile with Heimdal 1.1 in 8.0-CURRENT
.endif

.if ${OSVERSION} < 700000
BROKEN=		does not compile with OpenSSL in 6.x base
.endif

# Authentication methods and modules:

basic_auth=	DB NCSA PAM MSNT SMB
digest_auth=	password
external_acl=	ip_user session unix_group wbinfo_group
MAN8+=		ncsa_auth.8 pam_auth.8 squid_db_auth.8 squid_session.8 \
		squid_unix_group.8
.if ${PORT_OPTIONS:MSQUID_LDAP_AUTH}
USE_OPENLDAP=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAN8+=		squid_ldap_auth.8 squid_ldap_group.8
basic_auth+=	LDAP
digest_auth+=	ldap
external_acl+=	ldap_group
libexec+=	digest_ldap_auth squid_ldap_auth squid_ldap_group
.endif
.if ${PORT_OPTIONS:MSQUID_SASL_AUTH}
LIB_DEPENDS+=	sasl2:${PORTSDIR}/security/cyrus-sasl2
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
basic_auth+=	SASL
libexec+=	sasl_auth
.endif
.if !defined(NO_NIS) && ${PORT_OPTIONS:MNIS}
basic_auth+=	YP
libexec+=	yp_auth
.endif
CONFIGURE_ARGS+=	--enable-auth="basic ntlm digest" \
			--enable-basic-auth-helpers="${basic_auth}" \
			--enable-digest-auth-helpers="${digest_auth}" \
			--enable-external-acl-helpers="${external_acl}" \
			--enable-ntlm-auth-helpers="SMB"
.if !defined(NO_KERBEROS) && ${PORT_OPTIONS:MKERBEROS}
# XXX This currently only works with heimdal from the base system,
#     see files/patch-helpers_negotiate_auth-squid_kerb_auth_*
CONFIGURE_ARGS+=	--enable-negotiate-auth-helpers="squid_kerb_auth"
libexec+=	squid_kerb_auth
.endif

# Storage schemes:

storage_schemes=	ufs diskd null
.if ${PORT_OPTIONS:MSQUID_AUFS}
storage_schemes+=	aufs
EXTRA_PATCHES+=		${PATCHDIR}/extra-patch-src-cf.data.pre.aufs
# Nil aufs threads is default, set any other value via SQUID_CONFIGURE_ARGS
CONFIGURE_ARGS+=	--with-pthreads
.endif
.if ${PORT_OPTIONS:MSQUID_COSS}
storage_schemes+=	coss
.if !  ${PORT_OPTIONS:MSQUID_AUFS}
# use Posix AIO instead of aufs' AIO; note that you then need the kernel to
# supply AIO support, either by loading the aio(4) module (n/a on 4.x) or by
# adding the option VFS_AIO to your kernel configuration if you want to
# actually use COSS storage:
CONFIGURE_ARGS+=	--enable-coss-aio-ops
.endif
sbin+=		cossdump
.endif
CONFIGURE_ARGS+=	--enable-storeio="${storage_schemes}"

# Other options set via 'make config':

.if ${PORT_OPTIONS:MSQUID_DELAY_POOLS}
CONFIGURE_ARGS+=	--enable-delay-pools
.endif
.if ${PORT_OPTIONS:MSQUID_SNMP}
CONFIGURE_ARGS+=	--enable-snmp
.endif
.if ! ${PORT_OPTIONS:MSQUID_CARP}
CONFIGURE_ARGS+=	--disable-carp
.endif
.if ${PORT_OPTIONS:MSQUID_SSL}
# we need to .include bsd.openssl.mk manually here.because USE_OPENSSL only
# works when it is defined before bsd.port{.pre}.mk is .included.
# This makes it currently impossible to combine this macro with OPTIONS to
# conditionally include OpenSSL support.
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--enable-ssl \
			--with-openssl="${OPENSSLBASE}"
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
.endif
.if ${PORT_OPTIONS:MSQUID_PINGER}
CONFIGURE_ARGS+=	--enable-icmp
libexec+=	pinger
.endif
.if ${PORT_OPTIONS:MSQUID_DNS_HELPER}
CONFIGURE_ARGS+=	--disable-internal-dns
libexec+=	dnsserver
.endif
.if ${PORT_OPTIONS:MSQUID_HTCP}
CONFIGURE_ARGS+=	--enable-htcp
.endif
.if ${PORT_OPTIONS:MSQUID_VIA_DB}
CONFIGURE_ARGS+=	--enable-forw-via-db
.endif
.if ${PORT_OPTIONS:MSQUID_CACHE_DIGESTS}
CONFIGURE_ARGS+=	--enable-cache-digests
.endif
.if ! ${PORT_OPTIONS:MSQUID_WCCP}
CONFIGURE_ARGS+=	--disable-wccp
.endif
.if ${PORT_OPTIONS:MSQUID_WCCPV2}
CONFIGURE_ARGS+=	--enable-wccpv2
.endif
.if ${PORT_OPTIONS:MSQUID_STRICT_HTTP}
CONFIGURE_ARGS+=	--disable-http-violations
.endif
.if ! ${PORT_OPTIONS:MSQUID_IDENT}
CONFIGURE_ARGS+=	--disable-ident-lookups
.endif
.if ${PORT_OPTIONS:MSQUID_REFERER_LOG}
CONFIGURE_ARGS+=	--enable-referer-log
.endif
.if ${PORT_OPTIONS:MSQUID_USERAGENT_LOG}
CONFIGURE_ARGS+=	--enable-useragent-log
.endif
.if ${PORT_OPTIONS:MSQUID_ARP_ACL}
CONFIGURE_ARGS+=	--enable-arp-acl
.endif
.if ${PORT_OPTIONS:MSQUID_PF}
CONFIGURE_ARGS+=	--enable-pf-transparent
.endif
.if ${PORT_OPTIONS:MSQUID_IPFILTER}
CONFIGURE_ARGS+=	--enable-ipf-transparent
.endif
.if ${PORT_OPTIONS:MSQUID_FOLLOW_XFF}
CONFIGURE_ARGS+=	--enable-follow-x-forwarded-for
.endif
.if ! ${PORT_OPTIONS:MSQUID_KQUEUE}
CONFIGURE_ARGS+=	--disable-kqueue
.endif
.if ${PORT_OPTIONS:MSQUID_LARGEFILE}
CONFIGURE_ARGS+=	--with-large-files --enable-large-cache-files
.endif
.if ${PORT_OPTIONS:MSQUID_STACKTRACES}
CONFIGURE_ARGS+=	--enable-stacktraces
CFLAGS+=	-g
STRIP=
.endif

# Languages:
#
# If you do not define SQUID_LANGUAGES yourself, all available language files
# will be installed; the default language will be English.

SQUID_LANGUAGES?=	Armenian Azerbaijani Bulgarian Catalan Czech Danish \
			Dutch English Estonian Finnish French German Greek \
			Hebrew Hungarian Italian Japanese Korean Lithuanian \
			Polish Portuguese Romanian Russian-1251 Russian-koi8-r \
			Serbian Simplify_Chinese Slovak Spanish Swedish \
			Traditional_Chinese Turkish NewEnglish
SQUID_DEFAULT_LANG?=	NewEnglish
CONFIGURE_ARGS+=	--enable-err-languages="${SQUID_LANGUAGES}" \
			--enable-default-err-language=${SQUID_DEFAULT_LANG}

# Finally, add additional user specified configuration options:
CONFIGURE_ARGS+=	${SQUID_CONFIGURE_ARGS}

PLIST_DIRS=	etc/squid/icons libexec/squid
PLIST_FILES=	${etc_files:S,^,etc/,} ${icon_files:S,^,etc/squid/icons/,} \
		${libexec:S,^,libexec/squid/,} ${sbin:S,^,sbin/,}

.for d in ${SQUID_LANGUAGES}
PLIST_DIRS+=	etc/squid/errors/${d}
PLIST_FILES+=	${error_files:S,^,etc/squid/errors/${d}/,}
.endfor
PLIST_DIRS+=	etc/squid/errors etc/squid squid/logs squid/cache squid

post-patch:
	@${REINPLACE_CMD} -e 's|%%SQUID_UID%%|${SQUID_UID}|g' \
	    -e 's|%%SQUID_GID%%|${SQUID_GID}|g' \
	    -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/src/cf.data.pre
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	    ${WRKSRC}/helpers/basic_auth/SMB/Makefile.in \
	    ${WRKSRC}/helpers/basic_auth/SMB/smb_auth.sh

pre-install:
# Prevent installation of .orig files by deleting them.
	@${FIND} ${WRKSRC} -name '*.bak' -delete
	@${FIND} ${WRKSRC} -name '*.orig' -delete

pre-su-install:
	@${SETENV} ${SCRIPTS_ENV} PKG_PREFIX=${PREFIX} \
	    ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if ${PORT_OPTIONS:MNLS}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/helpers/basic_auth/DB/passwd.sql ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MSQUID_PINGER}
	${CHMOD} 4510 ${PREFIX}/libexec/squid/pinger; \
	${CHGRP} ${SQUID_GID} ${PREFIX}/libexec/squid/pinger
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${docs} ${DOCSDIR}
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} \
	    ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

	@${ECHO_CMD} "===> post-installation information for ${PKGNAME}:"
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} ""

.include <bsd.port.mk>
