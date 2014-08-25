# Created by: Thomas-Martin Seck <tmseck@FreeBSD.org>
# $FreeBSD$

PORTNAME=	squid
PORTVERSION=	3.3.${SQUID_STABLE_VER}
PORTREVISION=	6
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.squid-cache.org/Versions/v3/${PORTVERSION:R}/ \
		http://www2.us.squid-cache.org/Versions/v3/${PORTVERSION:R}/ \
		http://www1.at.squid-cache.org/Versions/v3/${PORTVERSION:R}/ \
		http://www.eu.squid-cache.org/Versions/v3/${PORTVERSION:R}/ \
		http://www1.jp.squid-cache.org/Versions/v3/${PORTVERSION:R}/
MASTER_SITE_SUBDIR=	squid
PKGNAMESUFFIX=	33
DIST_SUBDIR=	squid3.3

PATCH_SITES=	http://www.squid-cache.org/%SUBDIR%/ \
		http://www2.us.squid-cache.org/%SUBDIR%/ \
		http://www1.at.squid-cache.org/%SUBDIR%/ \
		http://www.eu.squid-cache.org/%SUBDIR%/ \
		http://www1.jp.squid-cache.org/%SUBDIR%/ \
		http://master.squid-cache.org/~amosjeffries/patches/:nosid
PATCH_SITE_SUBDIR=	Versions/v3/${PORTVERSION:R}/changesets
PATCHFILES=	FreeBSD_silence_nosuid_mk1.patch:nosid

MAINTAINER=	ports@FreeBSD.org
COMMENT=	HTTP Caching Proxy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

SQUID_STABLE_VER=	11

CONFLICTS_INSTALL=	squid-2.[0-9].* squid32-* cacheboy-[0-9]* lusca-head-[0-9]*
USES=		perl5 tar:bzip2 shebangfix
SHEBANG_FILES=	scripts/*.pl contrib/*.pl src/*.pl tools/*.pl\
		helpers/external_acl/kerberos_ldap_group/cert_tool
GNU_CONFIGURE=	yes
USE_RC_SUBR=	squid

USERS=		squid
GROUPS=		squid

MYDOCS=		QUICKSTART README RELEASENOTES.html doc/debug-sections.txt
PORTDOCS=	${MYDOCS:T}
PORTEXAMPLES=	*
SUB_FILES+=	pkg-install pkg-message

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	ARP_ACL AUTH_KERB AUTH_LDAP AUTH_NIS AUTH_SASL AUTH_SMB \
		AUTH_SQL \
		CACHE_DIGESTS DEBUG DELAY_POOLS DNS_HELPER ECAP ESI \
		FOLLOW_XFF FS_AUFS FS_COSS HTCP ICAP ICMP IDENT IPV6 KQUEUE \
		LARGEFILE SNMP SSL SSL_CRTD STACKTRACES LAX_HTTP \
		TP_IPF TP_IPFW TP_PF VIA_DB WCCP WCCPV2 DOCS EXAMPLES

OPTIONS_DEFAULT=AUTH_KERB AUTH_NIS FS_AUFS HTCP IDENT KQUEUE SNMP WCCP WCCPV2

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
LAX_HTTP_DESC=	Do not enforce strict HTTP compliance
TP_IPFW_DESC=	Enable transparent proxying with IPFW
TP_IPF_DESC=	Enable transparent proxying with IPFilter
TP_PF_DESC=	Enable transparent proxying with PF
VIA_DB_DESC=	Enable Forward/Via database
WCCPV2_DESC=	Enable Web Cache Coordination Protocol v2
WCCP_DESC=	Enable Web Cache Coordination Protocol

ECAP_USES=		pkgconfig:build

change_files=	ChangeLog\
		contrib/nextstep/makepkg\
		contrib/nextstep/post_install\
		errors/Makefile.am\
		errors/Makefile.in\
		helpers/basic_auth/MSNT/Makefile.am\
		helpers/basic_auth/MSNT/Makefile.in\
		src/Makefile.am\
		src/Makefile.in\
		src/cf_gen.cc\
		src/squid.8.in\
		tools/Makefile.am\
		tools/Makefile.in

.if !defined(SQUID_CONFIGURE_ARGS)\
 || ${SQUID_CONFIGURE_ARGS:M*--disable-unlinkd*} == ""
PLIST_SUB+=	UNLINKD=""
.else
PLIST_SUB+=	UNLINKD="@comment "
.endif

IPV6_CONFIGURE_ENABLE=		ipv6
DELAY_POOLS_CONFIGURE_ENABLE=	delay-pools
SNMP_CONFIGURE_ENABLE=		snmp
SSL_CONFIGURE_ENABLE=		ssl
SSL_CRTD_CONFIGURE_ENABLE=	ssl-crtd
ICMP_CONFIGURE_ENABLE=		icmp
HTCP_CONFIGURE_ENABLE=		htcp
VIA_DB_CONFIGURE_ENABLE=	forw-via-db
CACHE_DIGESTS_CONFIGURE_ENABLE=	cache-digests
WCCP_CONFIGURE_ENABLE=		wccp
WCCPV2_CONFIGURE_ENABLE=	wccpv2
LAX_HTTP_CONFIGURE_ENABLE=	http-violations
IDENT_CONFIGURE_ENABLE=		ident-lookups
ARP_ACL_CONFIGURE_ENABLE=	eui
TP_IPFW_CONFIGURE_ENABLE=	ipfw-transparent
TP_PF_CONFIGURE_ENABLE=		pf-transparent
TP_IPF_CONFIGURE_ENABLE=	ipf-transparent
FOLLOW_XFF_CONFIGURE_ENABLE=	follow-x-forwarded-for
ECAP_CONFIGURE_ENABLE=		ecap
ICAP_CONFIGURE_ENABLE=		icap-client
ESI_CONFIGURE_ENABLE=		esi
KQUEUE_CONFIGURE_ENABLE=	kqueue
LARGEFILE_CONFIGURE_ENABLE=	large-files
STACKTRACES_CONFIGURE_ENABLE=	stacktraces

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

.include <bsd.port.options.mk>

.if ${CC:T:Mclang*} || ${CXX:T:Mclang++*} \
 || ${OPSYS} == FreeBSD && ${OSVERSION} >= 1000024
CXXFLAGS+=	-Wno-unused-private-field
.endif

# Authentication methods and modules:

basic_auth=	DB MSNT MSNT-multi-domain NCSA PAM POP3 RADIUS \
		fake getpwnam
digest_auth=	file
external_acl=	file_userip time_quota unix_group
ntlm_auth=	fake smb_lm
.if ${PORT_OPTIONS:MAUTH_LDAP}
USE_OPENLDAP=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
basic_auth+=	LDAP
external_acl+=	LDAP_group
.endif
.if ${PORT_OPTIONS:MAUTH_SASL}
LIB_DEPENDS+=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
basic_auth+=	SASL
.endif
.if ${PORT_OPTIONS:MAUTH_SMB}
BUILD_DEPENDS+=	smbclient:${PORTSDIR}/net/samba36
RUN_DEPENDS+=	smbclient:${PORTSDIR}/net/samba36
basic_auth+=	SMB
external_acl+=	wbinfo_group
.endif
.if ${PORT_OPTIONS:MAUTH_SQL}
USE_MYSQL=	yes
RUN_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
external_acl+=	SQL_session
.endif
# POLA: allow the old global make.conf(5) (pre src.conf(5)) defines, too:
.if ${PORT_OPTIONS:MAUTH_NIS} && !defined(NO_NIS) && !defined(WITHOUT_NIS)
basic_auth+=	NIS
.endif
# POLA: allow the old global make.conf(5) (pre src.conf(5)) defines, too:
.if ${PORT_OPTIONS:MAUTH_KERB} && !defined(NO_KERBEROS) && !defined(WITHOUT_KERBEROS)
negotiate_auth=	kerberos wrapper
.  if ${OPSYS} == DragonFly
LIB_DEPENDS+=	libkrb5.so:${PORTSDIR}/security/krb5
.  endif
# the kerberos_ldap_group external helper depends on LDAP and SASL:
.if ${PORT_OPTIONS:MAUTH_LDAP} && ${PORT_OPTIONS:MAUTH_SASL}
external_acl+=	kerberos_ldap_group
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
CONFIGURE_ARGS+=	--enable-storeio="${storage_schemes}"\
			--enable-disk-io="${diskio_modules}"

# Log daemon helpers:

logdaemon_helpers=	file
CONFIGURE_ARGS+=	--enable-log-daemon-helpers="${logdaemon_helpers}"

# Rewrite helpers:

rewrite_helpers=	fake
CONFIGURE_ARGS+=	--enable-url-rewrite-helpers="${rewrite_helpers}"

# Other options set via 'make config':

.if ${PORT_OPTIONS:MSSL}
# we need to .include bsd.openssl.mk manually here.because USE_OPENSSL only
# works when it is defined before bsd.port{.pre}.mk is .included.
# This makes it currently impossible to combine this macro with OPTIONS to
# conditionally include OpenSSL support.
# XXX: is this still true with OptionsNG as of 2012-10?
.include "${.CURDIR}/../../Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl="${OPENSSLBASE}"
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
.endif
.if ${PORT_OPTIONS:MDNS_HELPER}
CONFIGURE_ARGS+=	--disable-internal-dns
.endif
.if ${PORT_OPTIONS:MECAP}
LIB_DEPENDS+=	libecap.so:${PORTSDIR}/www/libecap
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif
.if ${PORT_OPTIONS:MESI}
LIB_DEPENDS+=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libxml2.so:${PORTSDIR}/textproc/libxml2
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2
LDFLAGS+=	-L${LOCALBASE}/lib
.endif
.if ${PORT_OPTIONS:MSTACKTRACES}
CFLAGS+=	-g
STRIP=
.endif
.if ${PORT_OPTIONS:MDEBUG} || defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--disable-optimizations --enable-debug-cbdata
WITH_DEBUG?=		yes
.endif

# Finally, add additional user specified configuration options:
CONFIGURE_ARGS+=	${SQUID_CONFIGURE_ARGS}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/src/cf.data.pre
	@cd ${WRKSRC} && ${REINPLACE_CMD}\
		-e 's|\.conf\.default|.conf.sample|'\
		-e 's|)\.default|).sample|'\
		${change_files}
	@cd ${WRKSRC} && ${MV} helpers/basic_auth/MSNT/msntauth.conf.default\
		helpers/basic_auth/MSNT/msntauth.conf.sample
	@cd ${WRKSRC} && ${MV} src/mime.conf.default src/mime.conf.sample
	@${REINPLACE_CMD} -e 's,echo |,echo =head1 |,'\
		${WRKSRC}/helpers/basic_auth/DB/config.test\
		${WRKSRC}/helpers/external_acl/SQL_session/config.test
.if !${PORT_OPTIONS:MIPV6}
	@${REINPLACE_CMD} -e's/ ::1//' -e's/ fc00::\/7//'\
		-e's/ fe80::\/10//' -e's/ 2001:DB8::2//'\
		-e's/ 2001:DB8::a:0\/64//'\
		-e'/tcp_outgoing_address 2001:db8::c001 good_service_net/d'\
		-e'/tcp_outgoing_address 2001:db8::beef normal_service_net/d'\
		-e'/tcp_outgoing_address 2001:db8::1/d'\
		${WRKSRC}/src/cf.data.pre
.endif
#	The kerberos auth helper check is harded for /usr/gssapi/gssapi.h, but
#	kerberos authorization happily uses gssapi located at $LOCALBASE.  Make
#	the config test always pass because it's guaranteed to pass on FreeBSD
#	and DragonFly installs it with the krb5 package.
	@${REINPLACE_CMD} -e 's|exit 1|exit 0|' \
		${WRKSRC}/helpers/negotiate_auth/kerberos/config.test

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/helpers/basic_auth/DB/passwd.sql \
		${STAGEDIR}${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${MYDOCS} ${STAGEDIR}${DOCSDIR}
.endif
	${MKDIR} ${STAGEDIR}/var/squid/logs

.include <bsd.port.mk>
