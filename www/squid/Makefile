PORTNAME=	squid
DISTVERSION=	6.14
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://github.com/${PORTNAME}-cache/${PORTNAME}/releases/download/${PORTNAME:tu}_${DISTVERSION:S|.|_|g}/

PATCH_SITES=	http://www2.pl.squid-cache.org/%SUBDIR%/ \
		http://www1.il.squid-cache.org/%SUBDIR%/ \
		http://www2.gr.squid-cache.org/%SUBDIR%/ \
		http://ca2.squid-cache.org/%SUBDIR%/ \
		https://www.squid-cache.org/%SUBDIR%/
PATCH_SITE_SUBDIR=	Versions/v6/changesets

MAINTAINER=	timp87@gmail.com
COMMENT=	HTTP Caching Proxy
WWW=		https://www.squid-cache.org/ \
		https://github.com/squid-cache/squid/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib cpe gmake localbase:ldflags perl5 \
		shebangfix tar:xz
CPE_VENDOR=	squid-cache
USE_RC_SUBR=	squid

SHEBANG_FILES=	contrib/*.pl scripts/*.pl tools/*.pl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--bindir=${PREFIX}/sbin \
		--datadir=${ETCDIR} \
		--disable-arch-native \
		--disable-epoll \
		--disable-strict-error-checking \
		--enable-build-info \
		--enable-removal-policies="lru heap" \
		--libexecdir=${PREFIX}/libexec/squid \
		--localstatedir=/var \
		--sbindir=${PREFIX}/sbin \
		--sysconfdir=${ETCDIR} \
		--with-default-user=squid \
		--with-included-ltdl \
		--with-logdir=/var/log/squid \
		--with-pidfile=/var/run/squid/squid.pid \
		--with-swapdir=/var/squid/cache \
		--without-cap \
		--without-gnutls \
		--without-netfilter-conntrack \
		--without-systemd

CONFLICTS=	squid-devel

SUB_FILES+=	pkg-install pkg-message

USERS=		squid
GROUPS=		squid

.if !defined(SQUID_CONFIGURE_ARGS) || \
	${SQUID_CONFIGURE_ARGS:M*--disable-unlinkd*} == ""
PLIST_SUB+=	UNLINKD=""
.else
PLIST_SUB+=	UNLINKD="@comment "
.endif
PORTDOCS=	${MYDOCS:T}
PORTEXAMPLES=	*

OPTIONS_DEFINE=		ARP_ACL CACHE_DIGESTS DEBUG DELAY_POOLS DOCS ECAP ESI \
			EXAMPLES FOLLOW_XFF FS_AUFS FS_DISKD FS_ROCK HTCP ICAP \
			ICMP IDENT IPV6 KQUEUE LARGEFILE LAX_HTTP NETTLE SNMP \
			SSL SSL_CRTD STACKTRACES TDB VIA_DB WCCP WCCPV2
OPTIONS_DEFAULT=	ARP_ACL AUTH_NIS CACHE_DIGESTS DELAY_POOLS FOLLOW_XFF \
			FS_AUFS FS_DISKD FS_ROCK GSSAPI_BASE HTCP ICAP ICMP \
			IDENT KQUEUE LARGEFILE LAX_HTTP SNMP SSL SSL_CRTD \
			TP_IPFW VIA_DB WCCP WCCPV2
OPTIONS_GROUP=		AUTH
OPTIONS_GROUP_AUTH=	AUTH_LDAP AUTH_NIS AUTH_SASL AUTH_SMB AUTH_SQL
OPTIONS_RADIO=		FW
OPTIONS_RADIO_FW=	TP_IPF TP_IPFW TP_PF
OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_SUB=		yes

ARP_ACL_DESC=		ARP/MAC/EUI based authentification
AUTH_DESC=		Authentication helpers
AUTH_LDAP_DESC=		Install LDAP authentication helpers
AUTH_NIS_DESC=		Install NIS/YP authentication helpers
AUTH_SASL_DESC=		Install SASL authentication helpers
AUTH_SMB_DESC=		Install SMB auth. helpers (req. Samba)
AUTH_SQL_DESC=		Install SQL based auth
CACHE_DIGESTS_DESC=	Use cache digests
DEBUG_DESC=		Build with extended debugging support
DELAY_POOLS_DESC=	Delay pools (bandwidth limiting)
ECAP_DESC=		Loadable content adaptation modules
ESI_DESC=		ESI support
FOLLOW_XFF_DESC=	Support for the X-Following-For header
FS_AUFS_DESC=		AUFS (threaded-io) support
FS_DISKD_DESC=		DISKD storage engine controlled by separate service
FS_ROCK_DESC=		ROCK storage engine
HTCP_DESC=		HTCP support
ICAP_DESC=		the ICAP client
ICMP_DESC=		ICMP pinging and network measurement
IDENT_DESC=		Ident lookups (RFC 931)
KQUEUE_DESC=		Kqueue(2) support
LARGEFILE_DESC=		Support large (>2GB) cache and log files
LAX_HTTP_DESC=		Do not enforce strict HTTP compliance
NETTLE_DESC=		Nettle MD5 algorithm support
SNMP_DESC=		SNMP support
SSL_CRTD_DESC=		Use ssl_crtd to handle SSL cert requests
SSL_DESC=		SSL gatewaying support
STACKTRACES_DESC=	Enable automatic backtraces on fatal errors
TDB_DESC=		TrivialDB support required for session and time quota external helpers
TP_IPFW_DESC=		Transparent proxying with IPFW
TP_IPF_DESC=		Transparent proxying with IPFilter
TP_PF_DESC=		Transparent proxying with PF
VIA_DB_DESC=		Forward/Via database
WCCPV2_DESC=		Web Cache Coordination Protocol v2
WCCP_DESC=		Web Cache Coordination Protocol

ARP_ACL_CONFIGURE_ENABLE=	eui
AUTH_LDAP_USES=			ldap
AUTH_LDAP_CONFIGURE_WITH=	ldap
AUTH_LDAP_VARS=			BASIC_AUTH+=LDAP \
				DIGEST_AUTH+="eDirectory LDAP" \
				EXTERNAL_ACL+="LDAP_group eDirectory_userip"
AUTH_SASL_LIB_DEPENDS=		libsasl2.so:security/cyrus-sasl2
AUTH_SASL_VARS=			BASIC_AUTH+=SASL
AUTH_SMB_USES=			samba:run
AUTH_SMB_VARS=			BASIC_AUTH+=SMB \
				EXTERNAL_ACL+=wbinfo_group
AUTH_SQL_RUN_DEPENDS=		p5-DBI>=1.08:databases/p5-DBI
AUTH_SQL_VARS=			EXTERNAL_ACL+=SQL_session
CACHE_DIGESTS_CONFIGURE_ENABLE=	cache-digests
DELAY_POOLS_CONFIGURE_ENABLE=	delay-pools
ECAP_LIB_DEPENDS=		libecap.so:www/libecap
ECAP_USES=			pkgconfig:build
ECAP_CONFIGURE_ENABLE=		ecap
ESI_LIB_DEPENDS=		libexpat.so:textproc/expat2 \
				libxml2.so:textproc/libxml2
ESI_CONFIGURE_ENABLE=		esi
ESI_CONFIGURE_WITH=		expat xml2
FOLLOW_XFF_CONFIGURE_ENABLE=	follow-x-forwarded-for
FS_AUFS_CONFIGURE_WITH=		pthreads
# Nil aufs threads is default, set any other value via SQUID_CONFIGURE_ARGS,
# e.g. SQUID_CONFIGURE_ARGS=--with-aufs-threads=N
FS_AUFS_LDFLAGS=		-pthread
FS_AUFS_VARS=			DISKIO_MODULES+=DiskThreads \
				STORAGE_SCHEMES+=aufs
FS_DISKD_VARS=			DISKIO_MODULES+=DiskDaemon \
				STORAGE_SCHEMES+=diskd
FS_ROCK_VARS=			STORAGE_SCHEMES+=rock
GSSAPI_BASE_USES=		gssapi
GSSAPI_BASE_CONFIGURE_ON=	${GSSAPI_CONFIGURE_ARGS} \
				krb5_config=${GSSAPIBASEDIR}/bin/krb5-config
.if exists(/usr/libdata/pkgconfig/mit-krb5.pc)
GSSAPI_BASE_CONFIGURE_ON+=	--with-mit-krb5=${GSSAPIBASEDIR}
.else
GSSAPI_BASE_CONFIGURE_ON+=	--with-heimdal-krb5=${GSSAPIBASEDIR}
.endif
GSSAPI_BASE_PLIST_SUB=		AUTH_KERB=""
GSSAPI_HEIMDAL_USES=		gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON=	${GSSAPI_CONFIGURE_ARGS} \
				--with-heimdal-krb5=${GSSAPIBASEDIR} \
				krb5_config=${GSSAPIBASEDIR}/bin/krb5-config
GSSAPI_HEIMDAL_PLIST_SUB=	AUTH_KERB=""
GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	${GSSAPI_CONFIGURE_ARGS} \
				--with-mit-krb5=${GSSAPIBASEDIR} \
				krb5_config=${GSSAPIBASEDIR}/bin/krb5-config
GSSAPI_MIT_PLIST_SUB=		AUTH_KERB=""
GSSAPI_NONE_CONFIGURE_ON=	--without-gnugss \
				--without-heimdal-krb5 \
				--without-mit-krb5
HTCP_CONFIGURE_ENABLE=		htcp
ICAP_CONFIGURE_ENABLE=		icap-client
ICMP_CONFIGURE_ENABLE=		icmp
IDENT_CONFIGURE_ENABLE=		ident-lookups
IPV6_CONFIGURE_ENABLE=		ipv6
KQUEUE_CONFIGURE_ENABLE=	kqueue
LARGEFILE_CONFIGURE_WITH=	large-files
LAX_HTTP_CONFIGURE_ENABLE=	http-violations
NETTLE_LIB_DEPENDS=		libnettle.so:security/nettle
NETTLE_CONFIGURE_WITH=		nettle
SNMP_CONFIGURE_ENABLE=		snmp
SSL_USES=			ssl
SSL_CONFIGURE_ON=		--enable-security-cert-generators="file" \
				--with-openssl \
				LIBOPENSSL_CFLAGS=-I${OPENSSLINC} \
				LIBOPENSSL_LIBS="-lcrypto -lssl"
SSL_CONFIGURE_ENABLE=		ssl
SSL_CRTD_IMPLIES=		SSL
SSL_CRTD_CONFIGURE_ENABLE=	ssl-crtd
STACKTRACES_LIB_DEPENDS=	libunwind.so:devel/libunwind
STACKTRACES_CONFIGURE_ENABLE=	stacktraces
STACKTRACES_CFLAGS=		-g
STACKTRACES_LDFLAGS=		-lunwind
STACKTRACES_EXTRA_PATCHES=	${FILESDIR}/extra-patch-gen-stacktrace
STACKTRACES_VARS=		STRIP=""
TDB_LIB_DEPENDS=		libtdb.so:${SAMBA_TDB_PORT}
TDB_USES=			pkgconfig:build samba:env
TDB_CONFIGURE_WITH=		tdb
TDB_VARS=			EXTERNAL_ACL+="time_quota session"
TP_IPFW_CONFIGURE_ENABLE=	ipfw-transparent
TP_IPF_CONFIGURE_ENABLE=	ipf-transparent
TP_PF_CONFIGURE_ENABLE=		pf-transparent
TP_PF_CONFIGURE_WITH=		nat-devpf
VIA_DB_CONFIGURE_ENABLE=	forw-via-db
WCCPV2_CONFIGURE_ENABLE=	wccpv2
WCCP_CONFIGURE_ENABLE=		wccp

MYDOCS=		QUICKSTART README RELEASENOTES.html doc/debug-sections.txt

change_files=	ChangeLog errors/Makefile.am errors/Makefile.in \
		src/auth/basic/SMB_LM/README.html \
		src/Makefile.am src/Makefile.in \
		src/cf_gen.cc src/squid.8.in \
		test-suite/Makefile.in test-suite/Makefile.am \
		tools/Makefile.am tools/Makefile.in

.include <bsd.port.options.mk>

# Authentication methods and modules:
BASIC_AUTH+=	DB NCSA PAM POP3 RADIUS SMB_LM fake getpwnam
DIGEST_AUTH+=	file
EXTERNAL_ACL+=	file_userip unix_group delayer

# POLA: allow the old global make.conf(5) (pre src.conf(5)) defines, too:
.if ${PORT_OPTIONS:MAUTH_NIS} && !defined(NO_NIS) && !defined(WITHOUT_NIS)
BASIC_AUTH+=	NIS
CPPFLAGS+=	-DBOOL_DEFINED
.endif

# POLA: allow the old global make.conf(5) (pre src.conf(5)) defines, too:
.if ${PORT_OPTIONS:MGSSAPI_NONE} || defined(NO_KERBEROS) || \
	defined(WITHOUT_KERBEROS)
NEGOTIATE_AUTH=	none
PLIST_SUB+=	AUTH_KERB="@comment "
.else
# The kerberos_ldap_group external helper also depends on LDAP and SASL:
# The kerberos_sid_group external helper depends on kerberos_ldap_group meanwhile
. if ${PORT_OPTIONS:MAUTH_LDAP} && ${PORT_OPTIONS:MAUTH_SASL}
EXTERNAL_ACL+=	kerberos_ldap_group kerberos_sid_group
. endif
NEGOTIATE_AUTH=	kerberos wrapper
.endif

# Storage schemes:
STORAGE_SCHEMES+=	ufs
DISKIO_MODULES+=	AIO Blocking IpcIo Mmapped

CONFIGURE_ARGS+=	--enable-auth-basic="${BASIC_AUTH}" \
			--enable-auth-digest="${DIGEST_AUTH}" \
			--enable-auth-negotiate="${NEGOTIATE_AUTH}" \
			--enable-auth-ntlm="fake SMB_LM" \
			--enable-disk-io="${DISKIO_MODULES}" \
			--enable-external-acl-helpers="${EXTERNAL_ACL}" \
			--enable-log-daemon-helpers="file DB" \
			--enable-security-cert-validators="fake" \
			--enable-storeid-rewrite-helpers="file" \
			--enable-storeio="${STORAGE_SCHEMES}" \
			--enable-url-rewrite-helpers="fake LFS"
# Other options set via 'make config':

.if ${PORT_OPTIONS:MDEBUG} || defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--disable-optimizations
WITH_DEBUG?=		yes
.endif

# Finally, add additional user specified configuration options:
CONFIGURE_ARGS+=	${SQUID_CONFIGURE_ARGS}

post-patch:
	@(cd ${WRKSRC} && ${REINPLACE_CMD} \
		-e 's|\.conf\.default|.conf.sample|' \
		-e 's|)\.default|).sample|' \
		${change_files})
	@(cd ${WRKSRC} && ${MV} src/mime.conf.default src/mime.conf.sample)

post-patch-IPV6-off:
	@${REINPLACE_CMD} -E -e's| ::1$$||' -e's| ::1?/128||g' \
		-e'/acl localnet src f[ce][08]0::/d' \
		-e's| 2001:DB8::[^[:space:]]+$$||' \
		-e'/tcp_outgoing_address 2001:db8::/d' \
		${WRKSRC}/src/cf.data.pre

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/auth/basic/DB/passwd.sql \
		${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${MYDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
