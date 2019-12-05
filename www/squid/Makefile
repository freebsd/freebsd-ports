# $FreeBSD$

PORTNAME=	squid
PORTVERSION=	4.9
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v4/ \
		http://www2.us.squid-cache.org/Versions/v4/ \
		http://www1.at.squid-cache.org/Versions/v4/ \
		http://www.eu.squid-cache.org/Versions/v4/ \
		http://www1.jp.squid-cache.org/Versions/v4/
DIST_SUBDIR=	squid${PORTVERSION:R}

PATCH_SITES=	http://www.squid-cache.org/%SUBDIR%/ \
		http://www2.us.squid-cache.org/%SUBDIR%/ \
		http://www1.at.squid-cache.org/%SUBDIR%/ \
		http://www.eu.squid-cache.org/%SUBDIR%/ \
		http://www1.jp.squid-cache.org/%SUBDIR%/ \
		http://master.squid-cache.org/~amosjeffries/patches/:nosid
PATCH_SITE_SUBDIR=	Versions/v4/changesets

MAINTAINER=	timp87@gmail.com
COMMENT=	HTTP Caching Proxy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lib cpe perl5 shebangfix tar:xz

CONFLICTS=	squid*-3.*
CPE_VENDOR=	squid-cache
SHEBANG_FILES=	scripts/*.pl contrib/*.pl tools/*.pl
GNU_CONFIGURE=	yes
USE_RC_SUBR=	squid

USERS=		squid
GROUPS=		squid

MYDOCS=		QUICKSTART README RELEASENOTES.html doc/debug-sections.txt
PORTDOCS=	${MYDOCS:T}
PORTEXAMPLES=	*
SUB_FILES+=	pkg-install pkg-message

OPTIONS_SUB=	yes
OPTIONS_GROUP=	AUTH
OPTIONS_RADIO=	FW
OPTIONS_GROUP_AUTH=AUTH_LDAP AUTH_NIS AUTH_SASL AUTH_SMB AUTH_SQL
OPTIONS_RADIO_FW=TP_IPF TP_IPFW TP_PF
OPTIONS_DEFINE=	ARP_ACL BDB CACHE_DIGESTS DEBUG DELAY_POOLS DOCS ECAP ESI EXAMPLES \
		FOLLOW_XFF FS_AUFS FS_DISKD FS_ROCK HTCP ICAP ICMP IDENT IPV6 \
		KQUEUE LARGEFILE LAX_HTTP NETTLE PCRE SNMP SSL SSL_CRTD \
		STACKTRACES VIA_DB WCCP WCCPV2

OPTIONS_SINGLE=	GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_NONE GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT

OPTIONS_DEFAULT=ARP_ACL AUTH_NIS CACHE_DIGESTS DELAY_POOLS FOLLOW_XFF FS_AUFS \
		FS_DISKD FS_ROCK GSSAPI_BASE HTCP ICAP ICMP IDENT KQUEUE \
		LARGEFILE LAX_HTTP PCRE SNMP SSL SSL_CRTD TP_IPFW VIA_DB WCCP \
		WCCPV2

ARP_ACL_CONFIGURE_ENABLE=	eui
AUTH_LDAP_CFLAGS=		-I${LOCALBASE}/include
AUTH_LDAP_LDFLAGS=		-L${LOCALBASE}/lib
AUTH_LDAP_USE=			OPENLDAP=yes
AUTH_LDAP_VARS=			BASIC_AUTH+=LDAP EXTERNAL_ACL+=LDAP_group
AUTH_SASL_CFLAGS=		-I${LOCALBASE}/include
AUTH_SASL_CPPFLAGS=		-I${LOCALBASE}/include
AUTH_SASL_LDFLAGS=		-L${LOCALBASE}/lib
AUTH_SASL_LIB_DEPENDS=		libsasl2.so:security/cyrus-sasl2
AUTH_SASL_VARS=			BASIC_AUTH+=SASL
AUTH_SMB_USES=			samba:run
AUTH_SMB_VARS=			BASIC_AUTH+=SMB EXTERNAL_ACL+=wbinfo_group
AUTH_SQL_RUN_DEPENDS=		p5-DBI>=1.08:databases/p5-DBI
AUTH_SQL_VARS=			EXTERNAL_ACL+=SQL_session
BDB_USES=			bdb
CACHE_DIGESTS_CONFIGURE_ENABLE=	cache-digests
DELAY_POOLS_CONFIGURE_ENABLE=	delay-pools
ECAP_CFLAGS=			-I${LOCALBASE}/include
ECAP_CONFIGURE_ENABLE=		ecap
ECAP_LDFLAGS=			-L${LOCALBASE}/lib
ECAP_LIB_DEPENDS=		libecap.so:www/libecap
ECAP_USES=			pkgconfig:build
ESI_CFLAGS=			-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2
ESI_CONFIGURE_ENABLE=		esi
ESI_LDFLAGS=			-L${LOCALBASE}/lib
ESI_LIB_DEPENDS=		libexpat.so:textproc/expat2 \
				libxml2.so:textproc/libxml2
FOLLOW_XFF_CONFIGURE_ENABLE=	follow-x-forwarded-for
HTCP_CONFIGURE_ENABLE=		htcp
ICAP_CONFIGURE_ENABLE=		icap-client
ICMP_CONFIGURE_ENABLE=		icmp
IDENT_CONFIGURE_ENABLE=		ident-lookups
IPV6_CONFIGURE_ENABLE=		ipv6
KQUEUE_CONFIGURE_ENABLE=	kqueue
LARGEFILE_CONFIGURE_WITH=	large-files
LAX_HTTP_CONFIGURE_ENABLE=	http-violations
FS_AUFS_VARS=			STORAGE_SCHEMES+=aufs DISKIO_MODULES+=DiskThreads
# Nil aufs threads is default, set any other value via SQUID_CONFIGURE_ARGS,
# e.g. SQUID_CONFIGURE_ARGS=--with-aufs-threads=N
FS_AUFS_LDFLAGS=		-pthread
FS_AUFS_CONFIGURE_OFF=		--without-pthreads
FS_DISKD_VARS=			STORAGE_SCHEMES+=diskd DISKIO_MODULES+=DiskDaemon
FS_ROCK_VARS=			STORAGE_SCHEMES+=rock
NETTLE_LIB_DEPENDS=		libnettle.so:security/nettle
NETTLE_CONFIGURE_OFF=		--without-nettle
PCRE_LIB_DEPENDS=		libpcre.so:devel/pcre
PCRE_CPPFLAGS=			-I${LOCALBASE}/include
PCRE_LDFLAGS=			-L${LOCALBASE}/lib -lpcreposix -lpcre
SNMP_CONFIGURE_ENABLE=		snmp
SSL_CONFIGURE_ENABLE=		ssl
SSL_CONFIGURE_ON=		--with-openssl=${OPENSSLBASE} \
				--enable-security-cert-generators="file" \
				LIBOPENSSL_CFLAGS=-I${OPENSSLINC} \
				LIBOPENSSL_LIBS="-lcrypto -lssl"
SSL_USES=			ssl
SSL_CRTD_CONFIGURE_ENABLE=	ssl-crtd
SSL_CRTD_IMPLIES=		SSL
STACKTRACES_CONFIGURE_ENABLE=	stacktraces
STACKTRACES_EXTRA_PATCHES=	${FILESDIR}/extra-patch-gen-stacktrace
STACKTRACES_LIB_DEPENDS=	libunwind.so:devel/libunwind
STACKTRACES_CFLAGS=		-g
STACKTRACES_LDFLAGS=		-lunwind -L${LOCALBASE}/lib
STACKTRACES_VARS=		STRIP=""
TP_IPFW_CONFIGURE_ENABLE=	ipfw-transparent
TP_IPF_CONFIGURE_ENABLE=	ipf-transparent
TP_PF_CONFIGURE_ENABLE=		pf-transparent
TP_PF_CONFIGURE_WITH=		nat-devpf
VIA_DB_CONFIGURE_ENABLE=	forw-via-db
WCCPV2_CONFIGURE_ENABLE=	wccpv2
WCCP_CONFIGURE_ENABLE=		wccp

GSSAPI_NONE_CONFIGURE_ON=	--without-heimdal-krb5 \
				--without-mit-krb5 \
				--without-gss

GSSAPI_BASE_USES=		gssapi
GSSAPI_BASE_CONFIGURE_ON=	--with-heimdal-krb5=${GSSAPIBASEDIR} \
				${GSSAPI_CONFIGURE_ARGS} \
				krb5_config=${GSSAPIBASEDIR}/bin/krb5-config
GSSAPI_BASE_PLIST_SUB=		AUTH_KERB=""

GSSAPI_HEIMDAL_USES=		gssapi:heimdal
GSSAPI_HEIMDAL_CONFIGURE_ON=	--with-heimdal-krb5=${GSSAPIBASEDIR} \
				${GSSAPI_CONFIGURE_ARGS} \
				krb5_config=${GSSAPIBASEDIR}/bin/krb5-config
GSSAPI_HEIMDAL_PLIST_SUB=	AUTH_KERB=""

GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_MIT_CONFIGURE_ON=	--with-mit-krb5=${GSSAPIBASEDIR} \
				${GSSAPI_CONFIGURE_ARGS} \
				krb5_config=${GSSAPIBASEDIR}/bin/krb5-config
GSSAPI_MIT_PLIST_SUB=		AUTH_KERB=""

ARP_ACL_DESC=		ARP/MAC/EUI based authentification
AUTH_DESC=		Authentication helpers
AUTH_LDAP_DESC=		Install LDAP authentication helpers
AUTH_NIS_DESC=		Install NIS/YP authentication helpers
AUTH_SASL_DESC=		Install SASL authentication helpers
AUTH_SMB_DESC=		Install SMB auth. helpers (req. Samba)
AUTH_SQL_DESC=		Install SQL based auth
BDB_DESC=		Berkeley DB support required for session and time quota external helpers
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
NETTLE_DESC=		Nettle MD5 algorithm support
SNMP_DESC=		SNMP support
SSL_CRTD_DESC=		Use ssl_crtd to handle SSL cert requests
SSL_DESC=		SSL gatewaying support
STACKTRACES_DESC=	Enable automatic backtraces on fatal errors
LAX_HTTP_DESC=		Do not enforce strict HTTP compliance
TP_IPFW_DESC=		Transparent proxying with IPFW
TP_IPF_DESC=		Transparent proxying with IPFilter
TP_PF_DESC=		Transparent proxying with PF
VIA_DB_DESC=		Forward/Via database
WCCPV2_DESC=		Web Cache Coordination Protocol v2
WCCP_DESC=		Web Cache Coordination Protocol

change_files=	ChangeLog \
		contrib/nextstep/makepkg \
		contrib/nextstep/post_install \
		errors/Makefile.am \
		errors/Makefile.in \
		src/auth/basic/SMB_LM/README.html \
		src/Makefile.am \
		src/Makefile.in \
		src/cf_gen.cc \
		src/squid.8.in \
		test-suite/Makefile.in \
		tools/Makefile.am \
		tools/Makefile.in

.if !defined(SQUID_CONFIGURE_ARGS) \
	|| ${SQUID_CONFIGURE_ARGS:M*--disable-unlinkd*} == ""
PLIST_SUB+=	UNLINKD=""
.else
PLIST_SUB+=	UNLINKD="@comment "
.endif

CONFIGURE_ARGS=	--with-default-user=squid \
		--bindir=${PREFIX}/sbin \
		--sbindir=${PREFIX}/sbin \
		--datadir=${ETCDIR} \
		--libexecdir=${PREFIX}/libexec/squid \
		--localstatedir=/var \
		--sysconfdir=${ETCDIR} \
		--with-logdir=/var/log/squid \
		--with-pidfile=/var/run/squid/squid.pid \
		--with-swapdir=/var/squid/cache \
		--without-gnutls \
		--with-included-ltdl \
		--enable-auth \
		--enable-zph-qos \
		--enable-build-info \
		--enable-loadable-modules \
		--enable-removal-policies="lru heap" \
		--disable-epoll \
		--disable-linux-netfilter \
		--disable-linux-tproxy \
		--disable-translation \
		--disable-arch-native \
		--disable-strict-error-checking

.include <bsd.port.options.mk>

# Authentication methods and modules:

BASIC_AUTH+=	DB SMB_LM NCSA PAM POP3 RADIUS fake getpwnam
EXTERNAL_ACL+=	file_userip unix_group

# POLA: allow the old global make.conf(5) (pre src.conf(5)) defines, too:
.if ${PORT_OPTIONS:MAUTH_NIS} && !defined(NO_NIS) && !defined(WITHOUT_NIS)
BASIC_AUTH+=	NIS
.endif

# POLA: allow the old global make.conf(5) (pre src.conf(5)) defines, too:
.if ${PORT_OPTIONS:MGSSAPI_NONE} || defined(NO_KERBEROS) || defined(WITHOUT_KERBEROS)
NEGOTIATE_AUTH=	none
PLIST_SUB+=	AUTH_KERB="@comment "
.else
# The kerberos_ldap_group external helper also depends on LDAP and SASL:
. if ${PORT_OPTIONS:MAUTH_LDAP} && ${PORT_OPTIONS:MAUTH_SASL}
EXTERNAL_ACL+=	kerberos_ldap_group
. endif
NEGOTIATE_AUTH=	kerberos wrapper
.endif

# The session and time_quota external helpers require Berkeley DB support:
.if ${PORT_OPTIONS:MBDB}
CPPFLAGS+=	-I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${BDB_LIB_DIR}
EXTERNAL_ACL+=	time_quota session
.endif

# Storage schemes:
STORAGE_SCHEMES+=	ufs
DISKIO_MODULES+=	AIO Blocking IpcIo Mmapped

CONFIGURE_ARGS+=	--enable-auth-basic="${BASIC_AUTH}" \
			--enable-auth-digest="file" \
			--enable-external-acl-helpers="${EXTERNAL_ACL}" \
			--enable-auth-negotiate="${NEGOTIATE_AUTH}" \
			--enable-auth-ntlm="fake SMB_LM" \
			--enable-storeio="${STORAGE_SCHEMES}" \
			--enable-disk-io="${DISKIO_MODULES}" \
			--enable-log-daemon-helpers="file" \
			--enable-url-rewrite-helpers="fake" \
			--enable-storeid-rewrite-helpers="file" \
			--enable-security-cert-validators="fake"

# Other options set via 'make config':

.if ${PORT_OPTIONS:MDEBUG} || defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--disable-optimizations --enable-debug-cbdata
WITH_DEBUG?=		yes
.endif

# Finally, add additional user specified configuration options:
CONFIGURE_ARGS+=	${SQUID_CONFIGURE_ARGS}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/cf.data.pre
	@(cd ${WRKSRC} && ${REINPLACE_CMD} \
		-e 's|\.conf\.default|.conf.sample|' \
		-e 's|)\.default|).sample|' \
		${change_files})
	@(cd ${WRKSRC} && ${MV} src/mime.conf.default src/mime.conf.sample)

post-patch-IPV6-off:
	@${REINPLACE_CMD} -e's| ::1||' -e's|^.*fc00::\/7.*||' \
		-e's|^.*fe80::\/10.*||' -e's| 2001:DB8::2||' \
		-e's| 2001:DB8::a:0\/64||' \
		-e's|tcp_outgoing_address 2001:db8::c001 good_service_net||' \
		-e's|tcp_outgoing_address 2001:db8::beef normal_service_net||' \
		-e's|tcp_outgoing_address 2001:db8::1||' \
		${WRKSRC}/src/cf.data.pre

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/auth/basic/DB/passwd.sql \
		${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${MYDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
