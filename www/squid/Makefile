# Created by: Adrian Chadd <adrian@FreeBSD.org>
# $FreeBSD$

NO_STAGE=	yes
# Tunables not (yet) configurable via 'make config':
# SQUID_{U,G}ID
#   Which user/group Squid should run as (default: squid/squid).
#   The user and group will be created if they do not already exist using
#   a uid:gid of 100:100.
#   NOTE: older versions of Squid defaulted to nobody/nogroup.
#   If you wish to run Squid as "nobody" (which is not recommended), please
#   define SQUID_UID=nobody and SQUID_GID=nogroup in your make environment
#   before you start the update or installation of this port.
#
# SQUID_LANGUAGES
#   A list of languages for which error page files should be installed
#   (default: all)
#
#   E.g. use `make SQUID_LANGUAGES="English French"' if you want to
#   install the files for these languages only.
#   Use `make -VSQUID_LANGUAGES' or scroll down to this variable's
#   definition to see which values are valid.
#
# SQUID_DEFAULT_LANG
#   If you define SQUID_LANGUAGES, select which language should be the default
#   one (this variable defaults to English). This setting can be overwritten
#   with squid.conf's error_directory directive.
#
# SQUID_CONFIGURE_ARGS
#   Additional configuration options.
#
#   To enable them, use e.g
#   `make SQUID_CONFIGURE_ARGS="--enable-dlmalloc --enable-truncate" install'
#
#   The list below may be incomplete, please see the configure script
#   in the Squid source distribution for the complete list of additional
#   options.
#   Note that you probably do not need to worry about these options in most
#   cases, they are included in case you want to experiment with them.
#
#    --enable-dlmalloc
#     Compile and use the malloc package from Doug Lea
#    --enable-gnuregex
#     Compile and use the supplied GNUregex routines instead of BSD regex
#     (not recommended).
#    --enable-xmalloc-statistics
#     Show malloc statistics in status page
#    --enable-cachemgr-hostname=some.hostname
#     Set an explicit hostname in cachemgr.cgi
#    --enable-truncate
#     Use truncate() rather than unlink()
#    --disable-unlinkd
#     Do not use "unlinkd"
#    --with-aufs-threads=N_THREADS
#     Tune the number of worker threads for the aufs object
#    --with-coss-membuf-size
#     COSS membuf size (default: 1048576 bytes)
#    --with-maxfd=N
#     Override the maximum number of filedescriptors. Useful if you
#     build as another user who is not privileged to use the amount
#     of filedescriptors the resulting binary is expected to support.
#    --enable-ntlm-fail-open
#     Enable NTLM fail open, where a helper that fails one of the
#     Authentication steps can allow Squid to still authenticate the user
#    --enable-x-accelerator-vary
#     Enable support for the X-Accelerator-Vary HTTP header. Can be used
#     to indicate variance within an accelerator setup. Typically used
#     together with other code that adds custom HTTP headers to the
#     requests.
#    --enable-forward-log
#     Enable experimental forward_log directive.
#    --enable-multicast-miss
#     Enable experimental multicast notification of cachemisses.
#

PORTNAME=	squid
PORTVERSION=	2.7.${SQUID_STABLE_VER}
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.squid-cache.org/pub/%SUBDIR%/ \
		http://mirrors.ccs.neu.edu/Squid/ \
		ftp://ftp.fu-berlin.de/unix/www/squid/squid/ \
		ftp://ftp.nl.uu.net/pub/unix/www/squid/ \
		ftp://ftp.solnet.ch/mirror/squid/ \
		ftp://ftp.ntua.gr/pub/www/Squid/squid/ \
		http://mirror.aarnet.edu.au/pub/squid/squid/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/squid,} \
		http://www.squid-cache.org/Versions/v2/2.7/ \
		http://www2.us.squid-cache.org/Versions/v2/2.7/ \
		http://www1.at.squid-cache.org/Versions/v2/2.7/ \
		http://www2.de.squid-cache.org/Versions/v2/2.7/ \
		http://www.eu.squid-cache.org/Versions/v2/2.7/ \
		http://www1.ie.squid-cache.org/Versions/v2/2.7/ \
		http://www1.jp.squid-cache.org/Versions/v2/2.7/ \
		http://www2.tw.squid-cache.org/Versions/v2/2.7/
MASTER_SITE_SUBDIR=	squid
DISTNAME=	squid-2.7.STABLE${SQUID_STABLE_VER}
DIST_SUBDIR=	squid2.7

PATCH_SITES=	http://www.squid-cache.org/%SUBDIR%/ \
		http://www2.us.squid-cache.org/%SUBDIR%/ \
		http://www1.at.squid-cache.org/%SUBDIR%/ \
		http://www2.de.squid-cache.org/%SUBDIR%/ \
		http://www.eu.squid-cache.org/%SUBDIR%/ \
		http://www1.ie.squid-cache.org/%SUBDIR%/ \
		http://www1.jp.squid-cache.org/%SUBDIR%/ \
		http://www2.tw.squid-cache.org/%SUBDIR%/
PATCH_SITE_SUBDIR=	Versions/v2/2.7/changesets
#PATCH_DIST_STRIP=	-p1
PATCHFILES=	SQUID-2012_1.patch

MAINTAINER=	tmseck@FreeBSD.org
COMMENT=	HTTP Caching Proxy

SQUID_STABLE_VER=	9

CONFLICTS_INSTALL=	squid-2.[^7]* squid3?-* cacheboy-[0-9]* lusca-head-[0-9]*
USES=		perl5
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_RC_SUBR=	squid

SQUID_UID?=	squid
SQUID_GID?=	squid

MAN8=		cachemgr.cgi.8 squid.8
docs=		QUICKSTART README RELEASENOTES.html doc/debug-sections.txt
PORTDOCS=	${docs:T}
PORTEXAMPLES=	passwd.sql
SUB_FILES+=	pkg-deinstall pkg-install pkg-message
SUB_LIST+=	SQUID_UID=${SQUID_UID} SQUID_GID=${SQUID_GID}

OPTIONS_DEFINE=	KERB_AUTH LDAP_AUTH NIS_AUTH SASL_AUTH DELAY_POOLS SNMP CARP \
		SSL PINGER DNS_HELPER HTCP VIA_DB CACHE_DIGESTS WCCP WCCPV2 \
		STRICT_HTTP IDENT REFERER_LOG USERAGENT_LOG ARP_ACL PF IPFILTER \
		FOLLOW_XFF AUFS COSS KQUEUE LARGEFILE STACKTRACES
OPTIONS_DEFAULT=	KERB_AUTH NIS_AUTH CARP WCCP IDENT KQUEUE
KERB_AUTH_DESC=		Install Kerberos authentication helpers
LDAP_AUTH_DESC=		Install LDAP authentication helpers
NIS_AUTH_DESC=		Install NIS/YP authentication helpers
SASL_AUTH_DESC=		Install SASL authentication helpers
DELAY_POOLS_DESC=	Enable delay pools
SNMP_DESC=		Enable SNMP support
CARP_DESC=		Enable CARP support
SSL_DESC=		Enable SSL support for reverse proxies
PINGER_DESC=		Install the icmp helper
DNS_HELPER_DESC=	Use the old 'dnsserver' helper
HTCP_DESC=		Enable HTCP support
VIA_DB_DESC=		Enable forward/via database
CACHE_DIGESTS_DESC=	Enable cache digests
WCCP_DESC=		Enable Web Cache Coordination Prot. v1
WCCPV2_DESC=		Enable Web Cache Coordination Prot. v2
STRICT_HTTP_DESC=	Be strictly HTTP compliant
IDENT_DESC=		Enable ident (RFC 931) lookups
REFERER_LOG_DESC=	Enable Referer-header logging
USERAGENT_LOG_DESC=	Enable User-Agent-header logging
ARP_ACL_DESC=		Enable ACLs based on ethernet address
PF_DESC=		Enable transparent proxying with PF
IPFILTER_DESC=		Enable transp. proxying with IPFilter
FOLLOW_XFF_DESC=	Follow X-Forwarded-For headers
AUFS_DESC=		Enable the aufs storage scheme
COSS_DESC=		Enable the COSS storage scheme
KQUEUE_DESC=		Use kqueue(2) instead of poll(2)
LARGEFILE_DESC=		Support log and cache files >2GB
STACKTRACES_DESC=	Create backtraces on fatal errors

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

libexec=	cachemgr.cgi digest_pw_auth diskd-daemon \
		ip_user_check logfile-daemon \
		msnt_auth ncsa_auth ntlm_auth \
		pam_auth smb_auth smb_auth.sh squid_db_auth squid_session \
		squid_unix_group wbinfo_group.pl
.if !defined(SQUID_CONFIGURE_ARGS) || ${SQUID_CONFIGURE_ARGS:M*--disable-unlinkd*} == ""
libexec+=	unlinkd
.endif

sbin=		RunCache squidclient squid

CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin  \
		--sbindir=${PREFIX}/sbin  \
		--datadir=${ETCDIR} \
		--libexecdir=${PREFIX}/libexec/squid \
		--localstatedir=/var/squid \
		--sysconfdir=${ETCDIR} \
		--enable-removal-policies="lru heap" \
		--disable-linux-netfilter \
		--disable-linux-tproxy \
		--disable-epoll

.include <bsd.port.pre.mk>

# Authentication methods and modules:

basic_auth=	DB NCSA PAM MSNT SMB
digest_auth=	password
external_acl=	ip_user session unix_group wbinfo_group
MAN8+=		ncsa_auth.8 pam_auth.8 squid_db_auth.8 squid_session.8 \
		squid_unix_group.8
.if ${PORT_OPTIONS:MLDAP_AUTH}
USE_OPENLDAP=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAN8+=		squid_ldap_auth.8 squid_ldap_group.8
basic_auth+=	LDAP
digest_auth+=	ldap
external_acl+=	ldap_group
libexec+=	digest_ldap_auth squid_ldap_auth squid_ldap_group
.endif
.if ${PORT_OPTIONS:MSASL_AUTH}
LIB_DEPENDS+=	sasl2:${PORTSDIR}/security/cyrus-sasl2
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
basic_auth+=	SASL
libexec+=	sasl_auth
.endif
# POLA: allow the old global make.conf(5) (pre src.conf(5)) defines, too:
.if ${PORT_OPTIONS:MNIS_AUTH} && !defined(NO_NIS) && !defined(WITHOUT_NIS)
basic_auth+=	YP
libexec+=	yp_auth
.endif
CONFIGURE_ARGS+=	--enable-auth="basic digest negotiate ntlm" \
			--enable-basic-auth-helpers="${basic_auth}" \
			--enable-digest-auth-helpers="${digest_auth}" \
			--enable-external-acl-helpers="${external_acl}" \
			--enable-ntlm-auth-helpers="SMB"
# POLA: allow the old global make.conf(5) (pre src.conf(5)) defines, too:
.if ${PORT_OPTIONS:MKERB_AUTH} && !defined(NO_KERBEROS) && !defined(WITHOUT_KERBEROS)
# XXX This currently only works with heimdal from the base system,
#     see files/patch-squid_kerb_auth:
CONFIGURE_ARGS+=	--enable-negotiate-auth-helpers="squid_kerb_auth"
libexec+=	squid_kerb_auth
.endif

# Storage schemes:

storage_schemes=	ufs diskd null
.if ${PORT_OPTIONS:MAUFS}
storage_schemes+=	aufs
.if ${OSVERSION}<700055
# Only document libmap.conf for releases where it may be needed to
# switch from libpthread (aka libkse) to libthr:
EXTRA_PATCHES+=		${PATCHDIR}/extra-patch-src-cf.data.pre.aufs
.endif
# Nil aufs threads is default, set any other value via SQUID_CONFIGURE_ARGS
CONFIGURE_ARGS+=	--with-pthreads
.endif
.if ${PORT_OPTIONS:MCOSS}
storage_schemes+=	coss
.if ! ${PORT_OPTIONS:MAUFS}
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

.if ${PORT_OPTIONS:MDELAY_POOLS}
CONFIGURE_ARGS+=	--enable-delay-pools
.endif
.if ${PORT_OPTIONS:MSNMP}
CONFIGURE_ARGS+=	--enable-snmp
.endif
.if ! ${PORT_OPTIONS:MCARP}
CONFIGURE_ARGS+=	--disable-carp
.endif
.if ${PORT_OPTIONS:MSSL}
# we need to .include bsd.openssl.mk manually here.because USE_OPENSSL only
# works when it is defined before bsd.port{.pre}.mk is .included.
# This makes it currently impossible to combine this macro with OPTIONS to
# conditionally include OpenSSL support.
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--enable-ssl \
			--with-openssl="${OPENSSLBASE}"
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
.endif
.if ${PORT_OPTIONS:MPINGER}
CONFIGURE_ARGS+=	--enable-icmp
libexec+=	pinger
.endif
.if ${PORT_OPTIONS:MDNS_HELPER}
CONFIGURE_ARGS+=	--disable-internal-dns
libexec+=	dnsserver
.endif
.if ${PORT_OPTIONS:MHTCP}
CONFIGURE_ARGS+=	--enable-htcp
.endif
.if ${PORT_OPTIONS:MVIA_DB}
CONFIGURE_ARGS+=	--enable-forw-via-db
.endif
.if ${PORT_OPTIONS:MCACHE_DIGESTS}
CONFIGURE_ARGS+=	--enable-cache-digests
.endif
.if ! ${PORT_OPTIONS:MWCCP}
CONFIGURE_ARGS+=	--disable-wccp
.endif
.if ${PORT_OPTIONS:MWCCPV2}
CONFIGURE_ARGS+=	--enable-wccpv2
.endif
.if ${PORT_OPTIONS:MSTRICT_HTTP}
CONFIGURE_ARGS+=	--disable-http-violations
.endif
.if ! ${PORT_OPTIONS:MIDENT}
CONFIGURE_ARGS+=	--disable-ident-lookups
.endif
.if ${PORT_OPTIONS:MREFERER_LOG}
CONFIGURE_ARGS+=	--enable-referer-log
.endif
.if ${PORT_OPTIONS:MUSERAGENT_LOG}
CONFIGURE_ARGS+=	--enable-useragent-log
.endif
.if ${PORT_OPTIONS:MARP_ACL}
CONFIGURE_ARGS+=	--enable-arp-acl
.endif
.if ${PORT_OPTIONS:MPF}
CONFIGURE_ARGS+=	--enable-pf-transparent
.endif
.if ${PORT_OPTIONS:MIPFILTER}
CONFIGURE_ARGS+=	--enable-ipf-transparent
.endif
.if ${PORT_OPTIONS:MFOLLOW_XFF}
CONFIGURE_ARGS+=	--enable-follow-x-forwarded-for
.endif
.if ${PORT_OPTIONS:MICAP}
IGNORE=		does not have working ICAP support anymore -- please use Squid 3.x if you need ICAP. Please remove WITH_SQUID_ICAP from your make environment
.endif
.if ! ${PORT_OPTIONS:MKQUEUE}
CONFIGURE_ARGS+=	--disable-kqueue
.endif
.if ${PORT_OPTIONS:MLARGEFILE}
CONFIGURE_ARGS+=	--with-large-files --enable-large-cache-files
.endif
.if ${PORT_OPTIONS:MSTACKTRACES}
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
			Traditional_Chinese Turkish Ukrainian-1251 \
			Ukrainian-koi8-u Ukrainian-utf8
SQUID_DEFAULT_LANG?=	English
CONFIGURE_ARGS+=	--enable-err-languages="${SQUID_LANGUAGES}" \
			--enable-default-err-language=${SQUID_DEFAULT_LANG}

# Finally, add additional user specified configuration options:
CONFIGURE_ARGS+=	${SQUID_CONFIGURE_ARGS}

CONFIGURE_ENV+=		GREP="${GREP}"

PLIST_DIRS=	%%ETCDIR%%/icons libexec/squid
PLIST_FILES=	${etc_files:S,^,etc/,} ${icon_files:S,^,%%ETCDIR%%/icons/,} \
		${libexec:S,^,libexec/squid/,} ${sbin:S,^,sbin/,}

.for d in ${SQUID_LANGUAGES}
PLIST_DIRS+=	%%ETCDIR%%/errors/${d}
PLIST_FILES+=	${error_files:S,^,%%ETCDIR%%/errors/${d}/,}
.endfor
PLIST_DIRS+=	%%ETCDIR%%/errors
PLIST_DIRSTRY+=	%%ETCDIR%%

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
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/helpers/basic_auth/DB/passwd.sql ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MPINGER}
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

.include <bsd.port.post.mk>
