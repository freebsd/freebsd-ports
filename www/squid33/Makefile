# Created by: Thomas-Martin Seck <tmseck@FreeBSD.org>
# $FreeBSD$

PORTNAME=	squid
PORTVERSION=	3.3.${SQUID_STABLE_VER}
CATEGORIES=	www ipv6
MASTER_SITES=	ftp://ftp.squid-cache.org/pub/%SUBDIR%/ \
		http://mirrors.ccs.neu.edu/Squid/ \
		ftp://ftp.fu-berlin.de/unix/www/squid/squid/ \
		ftp://ftp.nl.uu.net/pub/unix/www/squid/ \
		ftp://ftp.solnet.ch/mirror/squid/ \
		ftp://ftp.ntua.gr/pub/www/Squid/squid/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/squid,} \
		http://www.squid-cache.org/Versions/v3/${PORTVERSION:R}/ \
		http://www2.us.squid-cache.org/Versions/v3/${PORTVERSION:R}/ \
		http://www3.us.squid-cache.org/Versions/v3/${PORTVERSION:R}/ \
		http://www1.at.squid-cache.org/Versions/v3/${PORTVERSION:R}/ \
		http://www.eu.squid-cache.org/Versions/v3/${PORTVERSION:R}/ \
		http://www1.ie.squid-cache.org/Versions/v3/${PORTVERSION:R}/ \
		http://www1.jp.squid-cache.org/Versions/v3/${PORTVERSION:R}/ \
		http://www1.za.squid-cache.org/Versions/v3/${PORTVERSION:R}/
MASTER_SITE_SUBDIR=	squid
DIST_SUBDIR=	squid3.3

PATCH_SITES=	http://www.squid-cache.org/%SUBDIR%/ \
		http://www2.us.squid-cache.org/%SUBDIR%/ \
		http://www3.us.squid-cache.org/%SUBDIR%/ \
		http://www1.at.squid-cache.org/%SUBDIR%/ \
		http://www.eu.squid-cache.org/%SUBDIR%/ \
		http://www1.ie.squid-cache.org/%SUBDIR%/ \
		http://www1.jp.squid-cache.org/%SUBDIR%/ \
		http://www2.tw.squid-cache.org/%SUBDIR%/
PATCH_SITE_SUBDIR=	Versions/v3/${PORTVERSION:R}/changesets
PATCHFILES=	#empty

MAINTAINER=	tmseck@FreeBSD.org
COMMENT=	HTTP Caching Proxy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LATEST_LINK=	squid33

SQUID_STABLE_VER=	10

CONFLICTS_INSTALL=	squid-2.[0-9].* squid-3.[!3].* cacheboy-[0-9]* lusca-head-[0-9]*
USES=		perl5
GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_RC_SUBR=	squid

USERS=		squid
GROUPS=		squid

MAN1=		squidclient.1
MAN8=		cachemgr.cgi.8 squid.8
docs=		QUICKSTART README RELEASENOTES.html doc/debug-sections.txt
PORTDOCS=	${docs:T}
PORTEXAMPLES=	*
SUB_FILES+=	pkg-install pkg-message

OPTIONS_DEFINE=	ARP_ACL AUTH_KERB AUTH_LDAP AUTH_NIS AUTH_SASL AUTH_SMB \
		AUTH_SQL \
		CACHE_DIGESTS DEBUG DELAY_POOLS DNS_HELPER ECAP ESI \
		FOLLOW_XFF FS_AUFS FS_COSS HTCP ICAP ICMP IDENT IPV6 KQUEUE \
		LARGEFILE SNMP SSL SSL_CRTD STACKTRACES STRICT_HTTP \
		TP_IPF TP_IPFW TP_PF VIA_DB WCCP WCCPV2 DOCS EXAMPLES

NO_STAGE=	yes
# TODO:
# add an option for external_acl/session (requires some kind of external
# Berkeley DB support, unsure which one)
ARP_ACL_DESC=	Enable ARP/MAC/EUI based authentification
AUTH_KERB_DESC=	Install Kerberos authentication helpers
AUTH_LDAP_DESC=	Install LDAP authentication helpers
AUTH_NIS_DESC=	Install NIS/YP authentication helpers
AUTH_SASL_DESC=	Install SASL authentication helpers
AUTH_SMB_DESC=	Install SMB auth. helpers (req. Samba)
AUTH_SQL_DESC=	Install SQL based auth (uses MySQL)
CACHE_DIGESTS_DESC=	Use cache digests
DEBUG_DESC=	Build with extended debugging support
DELAY_POOLS_DESC=	Enable delay pools (bandwidth limiting)
DNS_HELPER_DESC=	Use external dnsserver processes for DNS
ECAP_DESC=	Enable loadable content adaptation modules
ESI_DESC=	Enable support for ESI
FOLLOW_XFF_DESC=	Enable support for the X-Following-For header
FS_AUFS_DESC=	Enable AUFS (async-io) support
FS_COSS_DESC=	Enable COSS (not stable yet)
HTCP_DESC=	Enable HTCP support
ICAP_DESC=	Enable the ICAP client
ICMP_DESC=	Enable ICMP pinging and network measurement
IDENT_DESC=	Enable Ident lookups (RFC 931)
KQUEUE_DESC=	Enable kqueue(2) support
LARGEFILE_DESC=	Support large (>2GB) cache and log files
SNMP_DESC=	Enable SNMP support
SSL_CRTD_DESC=	Use ssl_crtd to handle SSL cert requests
SSL_DESC=	Enable SSL gatewaying support
STACKTRACES_DESC=	Enable automatic backtraces on fatal errors
STRICT_HTTP_DESC=	Make Squid strictly HTTP compliant
TP_IPFW_DESC=	Enable transparent proxying with IPFW
TP_IPF_DESC=	Enable transparent proxying with IPFilter
TP_PF_DESC=	Enable transparent proxying with PF
VIA_DB_DESC=	Enable Forward/Via database
WCCPV2_DESC=	Enable Web Cache Coordination Protocol v2
WCCP_DESC=	Enable Web Cache Coordination Protocol

OPTIONS_DEFAULT=	AUTH_KERB AUTH_NIS FS_AUFS HTCP IDENT KQUEUE \
			SNMP WCCP WCCPV2

etc_files=	squid/cachemgr.conf.default \
		squid/errorpage.css.default \
		squid/mib.txt \
		squid/mime.conf.default \
		squid/msntauth.conf.default \
		squid/squid.conf.default \
		squid/squid.conf.documented

icon_silk_files=	application.png arrow_up.png bomb.png box.png \
			bricks.png bullet_red.png cd.png chart_line.png \
			compress.png computer_link.png css.png cup.png \
			database.png database_table.png drive_disk.png \
			film.png film_key.png folder.png folder_table.png \
			image.png information.png layers.png layout.png \
			link.png music.png package.png package_go.png \
			page_code.png page_excel.png page_green.png \
			page_white.png page_white_acrobat.png page_white_c.png \
			page_white_cplusplus.png page_white_flash.png \
			page_white_magnify.png page_white_picture.png \
			page_white_powerpoint.png page_white_stack.png \
			page_white_text.png page_world.png \
			page_white_word.png page_white_zip.png photo.png \
			picture.png plugin.png plugin_add.png script.png \
			script_gear.png script_palette.png

error_files=	ERR_ACCESS_DENIED ERR_ACL_TIME_QUOTA_EXCEEDED \
		ERR_AGENT_CONFIGURE ERR_AGENT_WPAD \
		ERR_CACHE_ACCESS_DENIED \
		ERR_CACHE_MGR_ACCESS_DENIED ERR_CONFLICT_HOST \
		ERR_CANNOT_FORWARD ERR_CONNECT_FAIL \
		ERR_DIR_LISTING ERR_DNS_FAIL \
		ERR_ESI ERR_FORWARDING_DENIED \
		ERR_FTP_DISABLED ERR_FTP_FAILURE ERR_FTP_FORBIDDEN \
		ERR_FTP_NOT_FOUND ERR_FTP_PUT_CREATED \
		ERR_FTP_PUT_ERROR ERR_FTP_PUT_MODIFIED ERR_FTP_UNAVAILABLE \
		ERR_GATEWAY_FAILURE \
		ERR_ICAP_FAILURE ERR_INVALID_REQ ERR_INVALID_RESP \
		ERR_INVALID_URL ERR_LIFETIME_EXP ERR_NO_RELAY \
		ERR_ONLY_IF_CACHED_MISS ERR_PRECONDITION_FAILED \
		ERR_READ_ERROR ERR_READ_TIMEOUT \
		ERR_SECURE_CONNECT_FAIL ERR_SHUTTING_DOWN ERR_SOCKET_FAILURE \
		ERR_TOO_BIG ERR_UNSUP_REQ ERR_UNSUP_HTTPVERSION \
		ERR_URN_RESOLVE ERR_WRITE_ERROR ERR_ZERO_SIZE_OBJECT \
		error-details.txt

error_dirs=	af ar az bg ca cs da de el en es et fa fi fr he hu hy id it \
		ja ko lt lv ms nl oc pl pt pt-br ro ru sk sl sr-cyrl sr-latn \
		sv \
		th tr uk uz \
		vi zh-cn zh-tw \
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
			he-il hu-hu hy-am hy-armn id-id it-ch it-it \
			ja-jp ko-kp ko-kr lt-lt lv-lv ms-my nl-nl \
			pl-pl pt-pt ro-md ro-ro ru-ru \
			sk-sk sl-si sr sr-latn-cs sr-sp sv-fi sv-se \
			th-th tr-tr uk-ua vi-vn zh-hk zh-mo zh-sg

libexec=	cachemgr.cgi \
		diskd \
		helper-mux.pl

.if !defined(SQUID_CONFIGURE_ARGS) || ${SQUID_CONFIGURE_ARGS:M*--disable-unlinkd*} == ""
libexec+=	unlinkd
.endif

sbin=		purge squidclient squid

CONFIGURE_ARGS=	--with-default-user=squid \
		--bindir=${PREFIX}/sbin  \
		--sbindir=${PREFIX}/sbin  \
		--datadir=${ETCDIR} \
		--libexecdir=${PREFIX}/libexec/squid \
		--localstatedir=/var \
		--sysconfdir=${ETCDIR} \
		--with-logdir=/var/log/squid \
		--with-pidfile=/var/run/squid/squid.pid \
		--with-swapdir=/var/squid/cache/squid \
		--enable-auth \
		--enable-build-info \
		--enable-loadable-modules \
		--enable-removal-policies="lru heap" \
		--disable-epoll \
		--disable-linux-netfilter \
		--disable-linux-tproxy \
		--disable-translation

.include <bsd.port.pre.mk>

.if ${CC:T:Mclang} == "clang" || ${CXX:T:Mclang++} == "clang++" || ${OSVERSION} >= 1000024
CXXFLAGS+=	-Wno-unused-private-field
.endif

# Authentication methods and modules:

basic_auth=	DB MSNT MSNT-multi-domain NCSA PAM POP3 RADIUS \
		fake getpwnam
digest_auth=	file
external_acl=	file_userip time_quota unix_group
ntlm_auth=	fake smb_lm
libexec+=	basic_db_auth \
		basic_fake_auth \
		basic_getpwnam_auth \
		basic_ncsa_auth \
		basic_msnt_auth \
		basic_msnt_multi_domain_auth \
		basic_pam_auth \
		basic_pop3_auth \
		basic_radius_auth \
		digest_file_auth \
		ext_file_userip_acl \
		ext_time_quota_acl \
		ext_unix_group_acl \
		ntlm_fake_auth \
		ntlm_smb_lm_auth
MAN8+=		basic_getpwnam_auth.8 basic_ncsa_auth.8 basic_pam_auth.8 \
		basic_radius_auth.8 basic_db_auth.8 \
		digest_file_auth.8 \
		ext_file_userip_acl.8 ext_time_quota_acl.8 \
		ext_unix_group_acl.8
.if ${PORT_OPTIONS:MAUTH_LDAP}
USE_OPENLDAP=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAN8+=		basic_ldap_auth.8 ext_ldap_group_acl.8
basic_auth+=	LDAP
external_acl+=	LDAP_group
libexec+=	basic_ldap_auth ext_ldap_group_acl
.endif
.if ${PORT_OPTIONS:MAUTH_SASL}
LIB_DEPENDS+=	sasl2:${PORTSDIR}/security/cyrus-sasl2
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAN8+=		basic_sasl_auth.8
basic_auth+=	SASL
libexec+=	basic_sasl_auth
.endif
.if ${PORT_OPTIONS:MAUTH_SMB}
BUILD_DEPENDS+=	smbclient:${PORTSDIR}/net/samba36
RUN_DEPENDS+=	smbclient:${PORTSDIR}/net/samba36
basic_auth+=	SMB
external_acl+=	wbinfo_group
libexec+=	basic_smb_auth basic_smb_auth.sh \
		ext_wbinfo_group_acl
MAN8+=		ext_wbinfo_group_acl.8
.endif
.if ${PORT_OPTIONS:MAUTH_SQL}
USE_MYSQL=	yes
RUN_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
external_acl+=	SQL_session
libexec+=	ext_sql_session_acl
MAN8+=		ext_sql_session_acl.8
.endif
# POLA: allow the old global make.conf(5) (pre src.conf(5)) defines, too:
.if ${PORT_OPTIONS:MAUTH_NIS} && !defined(NO_NIS) && !defined(WITHOUT_NIS)
basic_auth+=	NIS
libexec+=	basic_nis_auth
.endif
# POLA: allow the old global make.conf(5) (pre src.conf(5)) defines, too:
.if ${PORT_OPTIONS:MAUTH_KERB} && !defined(NO_KERBEROS) && !defined(WITHOUT_KERBEROS)
negotiate_auth=	kerberos wrapper
libexec+=	negotiate_kerberos_auth negotiate_kerberos_auth_test \
		negotiate_wrapper_auth
MAN8+=		negotiate_kerberos_auth.8
# the kerberos_ldap_group external helper depends on LDAP and SASL:
.if ${PORT_OPTIONS:MAUTH_LDAP} && ${PORT_OPTIONS:MAUTH_SASL}
external_acl+=	kerberos_ldap_group
libexec+=	ext_kerberos_ldap_group_acl \
		cert_tool
# TODO
# XXX: this manpage is present in Squid's source but is not being
# built/installed yet (Squid 3.3.3 as at 04/2013).
#MAN8+=		ext_kerberos_ldap_group_acl.8
.endif
.else
negotiate_auth=	none
.endif

CONFIGURE_ARGS+=	--enable-auth-basic="${basic_auth}" \
			--enable-auth-digest="${digest_auth}" \
			--enable-external-acl-helpers="${external_acl}" \
			--enable-auth-negotiate="${negotiate_auth}" \
			--enable-auth-ntlm="${ntlm_auth}"

# Storage schemes:

storage_schemes=	diskd rock ufs
diskio_modules=	AIO Blocking DiskDaemon IpcIo Mmapped
.if ${PORT_OPTIONS:MFS_AUFS}
storage_schemes+=	aufs
diskio_modules+=	DiskThreads
# Nil aufs threads is default, set any other value via SQUID_CONFIGURE_ARGS,
# e.g. SQUID_CONFIGURE_ARGS=--with-aufs-threads=N
LDFLAGS+=	-pthread
.else
CONFIGURE_ARGS+=	--without-pthreads
.endif
.if ${PORT_OPTIONS:MFS_COSS}
storage_schemes+=	coss
.endif
CONFIGURE_ARGS+=	--enable-storeio="${storage_schemes}"
CONFIGURE_ARGS+=	--enable-disk-io="${diskio_modules}"

# Log daemon helpers:

logdaemon_helpers=	file
CONFIGURE_ARGS+=	--enable-log-daemon-helpers="${logdaemon_helpers}"
libexec+=	log_file_daemon

# Rewrite helpers:

rewrite_helpers=	fake
CONFIGURE_ARGS+=	--enable-url-rewrite-helpers="${rewrite_helpers}"
libexec+=	url_fake_rewrite url_fake_rewrite.sh

# Other options set via 'make config':

.if empty(PORT_OPTIONS:MIPV6) || defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-src-cf.data.pre.noipv6
.endif
.if ${PORT_OPTIONS:MDELAY_POOLS}
CONFIGURE_ARGS+=	--enable-delay-pools
.endif
.if empty(PORT_OPTIONS:MSNMP)
CONFIGURE_ARGS+=	--disable-snmp
.endif
.if ${PORT_OPTIONS:MSSL}
# we need to .include bsd.openssl.mk manually here.because USE_OPENSSL only
# works when it is defined before bsd.port{.pre}.mk is .included.
# This makes it currently impossible to combine this macro with OPTIONS to
# conditionally include OpenSSL support.
# XXX: is this still true with OptionsNG as of 2012-10?
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--enable-ssl \
			--with-openssl="${OPENSSLBASE}"
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
.endif
.if ${PORT_OPTIONS:MSSL_CRTD}
CONFIGURE_ARGS+=	--enable-ssl-crtd
libexec+=	ssl_crtd
.endif
.if ${PORT_OPTIONS:MICMP}
CONFIGURE_ARGS+=	--enable-icmp
libexec+=	pinger
.endif
.if ${PORT_OPTIONS:MDNS_HELPER}
CONFIGURE_ARGS+=	--disable-internal-dns
libexec+=	dnsserver
.endif
.if empty(PORT_OPTIONS:MHTCP)
CONFIGURE_ARGS+=	--disable-htcp
.else
CONFIGURE_ARGS+=	--enable-htcp
.endif
.if ${PORT_OPTIONS:MVIA_DB}
CONFIGURE_ARGS+=	--enable-forw-via-db
.else
CONFIGURE_ARGS+=	--disable-forw-via-db
.endif
.if ${PORT_OPTIONS:MCACHE_DIGESTS}
CONFIGURE_ARGS+=	--enable-cache-digests
.else
CONFIGURE_ARGS+=	--disable-cache-digests
.endif
.if ${PORT_OPTIONS:MWCCP}
CONFIGURE_ARGS+=	--enable-wccp
.else
CONFIGURE_ARGS+=	--disable-wccp
.endif
.if ${PORT_OPTIONS:MWCCPV2}
CONFIGURE_ARGS+=	--enable-wccpv2
.else
CONFIGURE_ARGS+=	--disable-wccpv2
.endif
.if ${PORT_OPTIONS:MSTRICT_HTTP}
CONFIGURE_ARGS+=	--disable-http-violations
.endif
.if empty(PORT_OPTIONS:MIDENT)
CONFIGURE_ARGS+=	--disable-ident-lookups
.endif
.if ${PORT_OPTIONS:MARP_ACL}
CONFIGURE_ARGS+=	--enable-eui
.else
CONFIGURE_ARGS+=	--disable-eui
.endif
.if ${PORT_OPTIONS:MTP_IPFW}
CONFIGURE_ARGS+=	--enable-ipfw-transparent
.else
CONFIGURE_ARGS+=	--disable-ipfw-transparent
.endif
.if ${PORT_OPTIONS:MTP_PF}
CONFIGURE_ARGS+=	--enable-pf-transparent
.else
CONFIGURE_ARGS+=	--disable-pf-transparent
.endif
.if ${PORT_OPTIONS:MTP_IPF}
CONFIGURE_ARGS+=	--enable-ipf-transparent
.else
CONFIGURE_ARGS+=	--disable-ipf-transparent
.endif
.if ${PORT_OPTIONS:MFOLLOW_XFF}
CONFIGURE_ARGS+=	--enable-follow-x-forwarded-for
.else
CONFIGURE_ARGS+=	--disable-follow-x-forwarded-for
.endif
.if ${PORT_OPTIONS:MECAP}
CONFIGURE_ARGS+=	--enable-ecap
LIB_DEPENDS+=	ecap:${PORTSDIR}/www/libecap
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USES+=		pkgconfig:build
.else
CONFIGURE_ARGS+=	--disable-ecap
.endif
.if ${PORT_OPTIONS:MICAP}
CONFIGURE_ARGS+=	--enable-icap-client
.else
CONFIGURE_ARGS+=	--disable-icap-client
.endif
.if ${PORT_OPTIONS:MESI}
CONFIGURE_ARGS+=	--enable-esi
LIB_DEPENDS+=	expat:${PORTSDIR}/textproc/expat2 \
		xml2:${PORTSDIR}/textproc/libxml2
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--disable-esi
.endif
.if ${PORT_OPTIONS:MKQUEUE}
CONFIGURE_ARGS+=	--enable-kqueue
.else
CONFIGURE_ARGS+=	--disable-kqueue
.endif
.if ${PORT_OPTIONS:MLARGEFILE}
CONFIGURE_ARGS+=	--with-large-files
.endif
.if ${PORT_OPTIONS:MSTACKTRACES}
CONFIGURE_ARGS+=	--enable-stacktraces
CFLAGS+=		-g
STRIP=
.endif
.if ${PORT_OPTIONS:MDEBUG} || defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--disable-optimizations --enable-debug-cbdata
WITH_DEBUG?=		yes
.endif

# Finally, add additional user specified configuration options:
CONFIGURE_ARGS+=	${SQUID_CONFIGURE_ARGS}

PLIST_DIRS=	%%ETCDIR%%/icons/silk %%ETCDIR%%/icons libexec/squid
PLIST_FILES=	${etc_files:S,^,etc/,} \
		%%ETCDIR%%/icons/SN.png \
		${icon_silk_files:S,^,%%ETCDIR%%/icons/silk/,} \
		${libexec:S,^,libexec/squid/,} ${sbin:S,^,sbin/,}

PLIST_FILES+=	%%ETCDIR%%/errors/COPYRIGHT %%ETCDIR%%/errors/TRANSLATORS
.for d in ${error_dirs}
PLIST_DIRS+=	%%ETCDIR%%/errors/${d}
PLIST_FILES+=	${error_files:S,^,%%ETCDIR%%/errors/${d}/,}
.endfor
PLIST_FILES+=	${error_dir_links:S,^,%%ETCDIR%%/errors/,}
PLIST_DIRS+=	%%ETCDIR%%/errors
PLIST_DIRSTRY+=	%%ETCDIR%%

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
	    ${WRKSRC}/src/cf.data.pre

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
.if ${PORT_OPTIONS:MICMP}
	${CHMOD} 4510 ${PREFIX}/libexec/squid/pinger; \
	${CHGRP} squid ${PREFIX}/libexec/squid/pinger
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
