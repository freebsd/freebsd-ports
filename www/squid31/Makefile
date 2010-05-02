# New ports collection makefile for:	squid24
# Date created:		Tue Mar 27 14:56:08 CEST 2001
# Whom:			Adrian Chadd <adrian@FreeBSD.org>
#
# $FreeBSD$
#
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
# Note:
# Starting with Squid 3.1 SQUID_LANGUAGES and SQUID_DEFAULT_LANG are no longer
# available and will be ignored.
#
# SQUID_CONFIGURE_ARGS
#   Additional configuration options.
#
#   To enable them, use e.g
#   `make SQUID_CONFIGURE_ARGS="--enable-ntml-fail-open" install'
#
#   The list below may be incomplete, please see the configure script
#   in the Squid source distribution for the complete list of additional
#   options.
#   Note that you probably do not need to worry about these options in most
#   cases, they are included in case you want to experiment with them.
#
#    --enable-xmalloc-statistics
#     Show malloc statistics in status page
#    --enable-cachemgr-hostname=some.hostname
#     Make cachemgr.cgi default to this host
#    --disable-unlinkd
#     Do not use "unlinkd"
#    --with-aufs-threads=N_THREADS
#     Tune the number of worker threads for the aufs object
#    --with-filedescriptors=N
#     Force Squid to use N filedescriptors.
#    --enable-ntlm-fail-open
#     Enable NTLM fail open, where a helper that fails one of the
#     Authentication steps can allow Squid to still authenticate the user
#    --enable-x-accelerator-vary
#     Enable support for the X-Accelerator-Vary HTTP header. Can be used
#     to indicate variance within an accelerator setup. Typically used
#     together with other code that adds custom HTTP headers to the
#     requests.
#    --disable-loadable-modules
#     Do not support loadable modules.

PORTNAME=	squid
PORTVERSION=	3.1.${SQUID_STABLE_VER}
CATEGORIES=	www ipv6
MASTER_SITES=	ftp://ftp.squid-cache.org/pub/%SUBDIR%/ \
		http://mirrors.ccs.neu.edu/Squid/ \
		ftp://ftp.fu-berlin.de/unix/www/squid/squid/ \
		ftp://ftp.nl.uu.net/pub/unix/www/squid/ \
		ftp://ftp.solnet.ch/mirror/squid/ \
		ftp://ftp.ntua.gr/pub/www/Squid/squid/ \
		http://mirror.aarnet.edu.au/pub/squid/squid/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/squid,} \
		http://www.squid-cache.org/Versions/v3/3.1/ \
		http://www2.us.squid-cache.org/Versions/v3/3.1/ \
		http://www1.at.squid-cache.org/Versions/v3/3.1/ \
		http://www2.de.squid-cache.org/Versions/v3/3.1/ \
		http://www.eu.squid-cache.org/Versions/v3/3.1/ \
		http://www1.ie.squid-cache.org/Versions/v3/3.1/ \
		http://www1.jp.squid-cache.org/Versions/v3/3.1/ \
		http://www2.tw.squid-cache.org/Versions/v3/3.1/
MASTER_SITE_SUBDIR=	squid
DISTNAME=	squid-3.1.${SQUID_STABLE_VER}
DIST_SUBDIR=	squid3.1

PATCH_SITES=	http://www.squid-cache.org/%SUBDIR%/ \
		http://www2.us.squid-cache.org/%SUBDIR%/ \
		http://www1.at.squid-cache.org/%SUBDIR%/ \
		http://www2.de.squid-cache.org/%SUBDIR%/ \
		http://www.eu.squid-cache.org/%SUBDIR%/ \
		http://www1.ie.squid-cache.org/%SUBDIR%/ \
		http://www1.jp.squid-cache.org/%SUBDIR%/ \
		http://www2.tw.squid-cache.org/%SUBDIR%/
PATCH_SITE_SUBDIR=	Versions/v3/3.1/changesets
PATCHFILES=

MAINTAINER=	tmseck@web.de
COMMENT=	HTTP Caching Proxy

LATEST_LINK=	squid31

SQUID_STABLE_VER=	1

CONFLICTS=	squid-2.[0-9].* squid-3.[^1].* cacheboy-[0-9]* lusca-head-[0-9]*
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_PERL5=	yes
USE_RC_SUBR=	squid

SQUID_UID?=	squid
SQUID_GID?=	squid

MAN1=		squidclient.1
MAN8=		cachemgr.cgi.8 squid.8 squid_radius_auth.8
docs=		QUICKSTART README RELEASENOTES.html doc/debug-sections.txt
PORTDOCS=	${docs:T}
PORTEXAMPLES=	*
SUB_FILES+=	pkg-deinstall pkg-install pkg-message
SUB_LIST+=	SQUID_UID=${SQUID_UID} SQUID_GID=${SQUID_GID}

OPTIONS=	SQUID_KERB_AUTH "Install Kerberos authentication helpers" on \
		SQUID_LDAP_AUTH "Install LDAP authentication helpers" off \
		SQUID_NIS_AUTH "Install NIS/YP authentication helpers" on \
		SQUID_SASL_AUTH "Install SASL authentication helpers" off \
		SQUID_IPV6 "Enable IPv6 support" on \
		SQUID_DELAY_POOLS "Enable delay pools" off \
		SQUID_SNMP "Enable SNMP support" on \
		SQUID_SSL "Enable SSL support for reverse proxies" off \
		SQUID_PINGER "Install the icmp helper" off \
		SQUID_DNS_HELPER "Use the old 'dnsserver' helper" off \
		SQUID_HTCP "Enable HTCP support" on \
		SQUID_VIA_DB "Enable forward/via database" off \
		SQUID_CACHE_DIGESTS "Enable cache digests" off \
		SQUID_WCCP "Enable Web Cache Coordination Prot. v1" on \
		SQUID_WCCPV2 "Enable Web Cache Coordination Prot. v2" off \
		SQUID_STRICT_HTTP "Be strictly HTTP compliant" off \
		SQUID_IDENT "Enable ident (RFC 931) lookups" on \
		SQUID_REFERER_LOG "Enable Referer-header logging" off \
		SQUID_USERAGENT_LOG "Enable User-Agent-header logging" off \
		SQUID_ARP_ACL "Enable ACLs based on ethernet address" off \
		SQUID_IPFW "Enable transparent proxying with IPFW" off \
		SQUID_PF "Enable transparent proxying with PF" off \
		SQUID_IPFILTER "Enable transp. proxying with IPFilter" off \
		SQUID_FOLLOW_XFF "Follow X-Forwarded-For headers" off \
		SQUID_ECAP "En. loadable content adaptation modules" off \
		SQUID_ICAP "Enable ICAP client functionality" off \
		SQUID_ESI "Enable ESI support (experimental)" off \
		SQUID_AUFS "Enable the aufs storage scheme" on \
		SQUID_COSS "Enable COSS (currently not available)" off \
		SQUID_KQUEUE "Use kqueue(2) (experimental)" on \
		SQUID_LARGEFILE "Support log and cache files >2GB" off \
		SQUID_STACKTRACES "Create backtraces on fatal errors" off \
		SQUID_DEBUG "Enable debugging options" off

etc_files=	squid/cachemgr.conf.default \
		squid/errorpage.css.default \
		squid/mib.txt \
		squid/mime.conf.default \
		squid/msntauth.conf.default \
		squid/squid.conf.default \
		squid/squid.conf.documented

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
		ERR_CONNECT_FAIL ERR_DIR_LISTING ERR_DNS_FAIL \
		ERR_ESI ERR_FORWARDING_DENIED \
		ERR_FTP_DISABLED ERR_FTP_FAILURE ERR_FTP_FORBIDDEN \
		ERR_FTP_NOT_FOUND ERR_FTP_PUT_CREATED \
		ERR_FTP_PUT_ERROR ERR_FTP_PUT_MODIFIED ERR_FTP_UNAVAILABLE \
		ERR_ICAP_FAILURE ERR_INVALID_REQ ERR_INVALID_RESP \
		ERR_INVALID_URL ERR_LIFETIME_EXP ERR_NO_RELAY \
		ERR_ONLY_IF_CACHED_MISS ERR_READ_ERROR ERR_READ_TIMEOUT \
		ERR_SECURE_CONNECT_FAIL ERR_SHUTTING_DOWN ERR_SOCKET_FAILURE \
		ERR_TOO_BIG ERR_UNSUP_REQ ERR_UNSUP_HTTPVERSION \
		ERR_URN_RESOLVE ERR_WRITE_ERROR ERR_ZERO_SIZE_OBJECT

error_dirs=	af ar az bg ca cs da de el en es et fa fi fr he hu hy id it \
		ja ko lt lv ms nl pl pt pt-br ro ru sk sv th tr uk uz \
		zh-cn zh-tw \
		templates

error_dir_links=	ar-ae ar-bh ar-dz ar-eg ar-iq ar-jo ar-kw ar-lb \
			ar-ly ar-ma ar-om ar-qa ar-sa ar-sy ar-tn ar-ye \
			az-az bg-bg cs-cz da-dk \
			de-at de-ch de-de de-li de-lu \
			el-gr \
			en-au en-bz en-ca en-gb en-ie en-in en-jm en-nz \
			en-ph en-sg en-tt en-uk en-us en-za en-zw \
			es-ar es-bo es-cl es-co es-cr es-do es-ec es-es \
			es-gt es-hn es-mx es-ni es-pa es-pe es-pr es-py \
			es-sv es-uy es-ve \
			et-ee \
			fa-fa fa-ir fi-fi \
			fr-be fr-ca fr-ch fr-fr fr-lu fr-mc \
			he-il hu-hu hy-am id-id it-ch it-it \
			ja-jp ko-kp ko-kr lt-lt lv-lv ms-my nl-nl \
			pl-pl pt-pt ro-md ro-ro ru-ru sk-sk sv-fi sv-se \
			th-th tr-tr uk-ua zh-hk zh-mo zh-sg

libexec=	cachemgr.cgi digest_pw_auth diskd ip_user_check \
		msnt_auth ncsa_auth ntlm_smb_lm_auth pam_auth smb_auth \
		smb_auth.sh squid_db_auth squid_radius_auth squid_session \
		squid_unix_group wbinfo_group.pl
.if !defined(SQUID_CONFIGURE_ARGS) || ${SQUID_CONFIGURE_ARGS:M*--disable-unlinkd*} == ""
libexec+=	unlinkd
.endif

sbin=		squidclient squid

CONFIGURE_ARGS=	--with-default-user=${SQUID_UID} \
		--bindir=${PREFIX}/sbin  \
		--sbindir=${PREFIX}/sbin  \
		--datadir=${PREFIX}/etc/squid \
		--libexecdir=${PREFIX}/libexec/squid \
		--localstatedir=/var/squid \
		--sysconfdir=${PREFIX}/etc/squid \
		--with-logdir=/var/log/squid \
		--with-pidfile=/var/run/squid/squid.pid \
		--enable-removal-policies="lru heap" \
		--disable-linux-netfilter \
		--disable-linux-tproxy \
		--disable-epoll \
		--disable-translation

.include <bsd.port.pre.mk>

# Authentication methods and modules:

basic_auth=	DB NCSA PAM MSNT SMB squid_radius_auth
digest_auth=	password
external_acl=	ip_user session unix_group wbinfo_group
MAN8+=		ncsa_auth.8 pam_auth.8 squid_db_auth.8 squid_session.8 \
		squid_unix_group.8
.if defined(WITH_SQUID_LDAP_AUTH)
USE_OPENLDAP=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAN8+=		squid_ldap_auth.8 squid_ldap_group.8
basic_auth+=	LDAP
digest_auth+=	ldap
external_acl+=	ldap_group
libexec+=	digest_ldap_auth squid_ldap_auth squid_ldap_group
.endif
.if defined(WITH_SQUID_SASL_AUTH)
LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
basic_auth+=	SASL
libexec+=	sasl_auth
.endif
# POLA: allow the old global make.conf(5) (pre src.conf(5)) defines, too:
.if defined(WITH_SQUID_NIS_AUTH) && !defined(NO_NIS) && !defined(WITHOUT_NIS)
basic_auth+=	YP
libexec+=	yp_auth
.endif
CONFIGURE_ARGS+=	--enable-auth="basic digest negotiate ntlm" \
			--enable-basic-auth-helpers="${basic_auth}" \
			--enable-digest-auth-helpers="${digest_auth}" \
			--enable-external-acl-helpers="${external_acl}" \
			--enable-ntlm-auth-helpers="smb_lm"
# POLA: allow the old global make.conf(5) (pre src.conf(5)) defines, too:
.if defined(WITH_SQUID_KERB_AUTH) && !defined(NO_KERBEROS) && !defined(WITHOUT_KERBEROS)
CONFIGURE_ARGS+=	--enable-negotiate-auth-helpers="squid_kerb_auth"
libexec+=	negotiate_kerb_auth negotiate_kerb_auth_test \
		squid_kerb_auth squid_kerb_auth_test
.endif

# Storage schemes:

storage_schemes=	ufs diskd
# TODO: should AIO be optional as well?
diskio_modules=	AIO Blocking DiskDaemon
.if defined(WITH_SQUID_AUFS)
storage_schemes+=	aufs
diskio_modules+=	DiskThreads
# Only document switching from libpthread to libthr using libmap.conf
# where lipthread is the default threading library:
.if ${OSVERSION} < 700041
EXTRA_PATCHES+=		${PATCHDIR}/extra-patch-src-cf.data.pre.aufs
.endif
# Nil aufs threads is default, set any other value via SQUID_CONFIGURE_ARGS,
# e.g. SQUID_CONFIGURE_ARGS=--with-aufs-threads=N
CFLAGS+=	${PTHREAD_CFLAGS}
.else
CONFIGURE_ARGS+=	--without-pthreads
.endif
.if defined(WITH_SQUID_COSS)
# COSS is currently disabled in Squid-3 until fixes from the 2.x series are
# backported to 3.x.
#storage_schemes+=	coss
.endif
CONFIGURE_ARGS+=	--enable-storeio="${storage_schemes}"
CONFIGURE_ARGS+=	--enable-disk-io="${diskio_modules}"

# Other options set via 'make config':

.if defined(WITHOUT_SQUID_IPV6) || defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif
.if defined(WITH_SQUID_DELAY_POOLS)
CONFIGURE_ARGS+=	--enable-delay-pools
.endif
.if defined(WITHOUT_SQUID_SNMP)
CONFIGURE_ARGS+=	--disable-snmp
.endif
.if defined(WITH_SQUID_SSL)
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
.if defined(WITH_SQUID_PINGER)
CONFIGURE_ARGS+=	--enable-icmp
libexec+=	pinger
.endif
.if defined(WITH_SQUID_DNS_HELPER)
CONFIGURE_ARGS+=	--disable-internal-dns
libexec+=	dnsserver
.endif
.if defined(WITHOUT_SQUID_HTCP)
CONFIGURE_ARGS+=	--disable-htcp
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
.if defined(WITH_SQUID_WCCPV2)
CONFIGURE_ARGS+=	--enable-wccpv2
.endif
.if defined(WITH_SQUID_STRICT_HTTP)
CONFIGURE_ARGS+=	--disable-http-violations
.endif
.if defined(WITHOUT_SQUID_IDENT)
CONFIGURE_ARGS+=	--disable-ident-lookups
.endif
.if defined(WITH_SQUID_REFERER_LOG)
CONFIGURE_ARGS+=	--enable-referer-log
.endif
.if defined(WITH_SQUID_USERAGENT_LOG)
CONFIGURE_ARGS+=	--enable-useragent-log
.endif
.if defined(WITH_SQUID_ARP_ACL)
CONFIGURE_ARGS+=	--enable-arp-acl
.endif
.if defined(WITH_SQUID_IPFW)
CONFIGURE_ARGS+=	--enable-ipfw-transparent
.endif
.if defined(WITH_SQUID_PF)
CONFIGURE_ARGS+=	--enable-pf-transparent
.endif
.if defined(WITH_SQUID_IPFILTER)
CONFIGURE_ARGS+=	--enable-ipf-transparent
.endif
.if defined(WITH_SQUID_FOLLOW_XFF)
CONFIGURE_ARGS+=	--enable-follow-x-forwarded-for
.endif
.if defined(WITH_SQUID_ECAP)
CONFIGURE_ARGS+=	--enable-ecap
LIB_DEPENDS+=	ecap:${PORTSDIR}/www/libecap
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif
.if defined(WITH_SQUID_ICAP)
CONFIGURE_ARGS+=	--enable-icap-client
.endif
.if defined(WITH_SQUID_ESI)
CONFIGURE_ARGS+=	--enable-esi
LIB_DEPENDS+=	expat:${PORTSDIR}/textproc/expat2 \
		xml2:${PORTSDIR}/textproc/libxml2
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2
LDFLAGS+=	-L${LOCALBASE}/lib
.endif
.if defined(WITHOUT_SQUID_KQUEUE)
# Squid-3's kqueue support is still marked as experimental, so it is not yet
# enabled automatically as in Squid-2. We are explicit about disabling it,
# nonetheless:
CONFIGURE_ARGS+=	--disable-kqueue
.else
CONFIGURE_ARGS+=	--enable-kqueue
.endif
.if defined(WITH_SQUID_LARGEFILE)
CONFIGURE_ARGS+=	--with-large-files
.endif
.if defined(WITH_SQUID_STACKTRACES)
CONFIGURE_ARGS+=	--enable-stacktraces
CFLAGS+=		-g
STRIP=
.endif
.if defined(WITH_SQUID_DEBUG) || defined(WITH_DEBUG)
# TODO: are there other useful options that can/should be set to help
#       the developers in debugging failures?
CONFIGURE_ARGS+=	--disable-optimizations
WITH_DEBUG?=		yes
.endif

# Finally, add additional user specified configuration options:
CONFIGURE_ARGS+=	${SQUID_CONFIGURE_ARGS}

CONFIGURE_ENV+=		CFLAGS="${CFLAGS}" \
			CPPFLAGS="${CPPFLAGS}"\
			LDFLAGS="${LDFLAGS}"

PLIST_DIRS=	etc/squid/icons libexec/squid
PLIST_FILES=	${etc_files:S,^,etc/,} ${icon_files:S,^,etc/squid/icons/,} \
		${libexec:S,^,libexec/squid/,} ${sbin:S,^,sbin/,}

PLIST_FILES+=	etc/squid/errors/COPYRIGHT etc/squid/errors/TRANSLATORS
.for d in ${error_dirs}
PLIST_DIRS+=	etc/squid/errors/${d}
PLIST_FILES+=	${error_files:S,^,etc/squid/errors/${d}/,}
.endfor
PLIST_FILES+=	${error_dir_links:S,^,etc/squid/errors/,}
PLIST_DIRS+=	etc/squid/errors etc/squid

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
	    ${WRKSRC}/src/cf.data.pre
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
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/helpers/basic_auth/DB/passwd.sql ${EXAMPLESDIR}
.endif
.if defined(WITH_SQUID_PINGER)
	${CHMOD} 4510 ${PREFIX}/libexec/squid/pinger; \
	${CHGRP} ${SQUID_GID} ${PREFIX}/libexec/squid/pinger
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${docs} ${DOCSDIR}
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} \
	    ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

	@${ECHO_CMD} "===> post-installation information for ${PKGNAME}:"
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} ""
.if defined(WITH_SQUID_COSS)
	@${ECHO_CMD} "Note: COSS support is currently not available in Squid-3."
	@${ECHO_CMD} "Please check your squid.conf and comment out any 'cache_dir coss' definitions."
	@${ECHO_CMD} ""
.endif

.include <bsd.port.post.mk>
