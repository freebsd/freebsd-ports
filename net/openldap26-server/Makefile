PORTNAME=		openldap
DISTVERSION=		2.6.10
PORTREVISION=		${OPENLDAP_PORTREVISION}
CATEGORIES=		net databases
MASTER_SITES=		https://www.openldap.org/software/download/OpenLDAP/%SUBDIR%/ \
			http://gpl.savoirfairelinux.net/pub/mirrors/openldap/%SUBDIR%/ \
			http://repository.linagora.org/OpenLDAP/%SUBDIR%/ \
			http://mirror.eu.oneandone.net/software/openldap/%SUBDIR%/ \
			ftp://ftp.ntua.gr/mirror/OpenLDAP/%SUBDIR%/ \
			https://mirror-hk.koddos.net/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.dti.ad.jp/pub/net/OpenLDAP/%SUBDIR%/ \
			https://mirror.koddos.net/OpenLDAP/%SUBDIR%/ \
			https://mirror.lyrahosting.com/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.OpenLDAP.org/pub/OpenLDAP/%SUBDIR%/ \
			http://www.openldap.org/software/download/OpenLDAP/%SUBDIR%/
MASTER_SITE_SUBDIR=	openldap-release
.if defined(CLIENT_ONLY)
PKGNAMESUFFIX=		26-client
.else
PKGNAMESUFFIX=		26-server
.endif

MAINTAINER=		delphij@FreeBSD.org
WWW=		https://www.OpenLDAP.org/
.if defined(CLIENT_ONLY)
COMMENT=		Open source LDAP client implementation
.else
COMMENT=		Open source LDAP server implementation
.endif

LICENSE=		OPENLDAP
LICENSE_NAME=		OpenLDAP Public License
LICENSE_FILE=		${WRKSRC}/LICENSE
LICENSE_PERMS=		dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

# :keepla because port uses lt_dlopen
USES=			cpe gmake libtool:keepla localbase ssl tar:tgz
BUILD_DEPENDS+=		autoconf>0:devel/autoconf

.if defined(CLIENT_ONLY)
CONFLICTS_INSTALL=	${PORTNAME}2[0-57-9]-client ${PORTNAME}-client
.else
CONFLICTS_INSTALL=	${PORTNAME}2[0-57-9]-server ${PORTNAME}-server
.endif

GNU_CONFIGURE=		yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PORTREVISION_CLIENT=	0
PORTREVISION_SERVER=	0
OPENLDAP_SHLIB_MAJOR=	2
OPENLDAP_SHLIB_MINOR=	0.200

OPTIONS_DEFINE=		DEBUG FETCH GSSAPI
OPTIONS_DEFAULT+=	DEBUG

FETCH_DESC=		Enable fetch(3) support
GSSAPI_DESC=		With GSSAPI support

FETCH_CONFIGURE_WITH=	fetch

GSSAPI_RUN_DEPENDS=		cyrus-sasl-gssapi>0:security/cyrus-sasl2-gssapi

.if defined(CLIENT_ONLY)
OPTIONS_DEFINE+=	DOCS
.else
OPTIONS_GROUP=		BKNDS OVLYS
BKNDS_DESC=		OpenLDAP backends
BKNDS_DEFAULTS=		ASYNCMETA DNSSRV MDB PASSWD RELAY SOCK
OPTIONS_GROUP_BKNDS+=	${BKNDS_DEFAULTS}
OPTIONS_GROUP_BKNDS+=	PERL SQL

OVLYS_DESC=		OpenLDAP overlays
OPTIONS_GROUP_OVLYS+=	ACCESSLOG
OPTIONS_GROUP_OVLYS+=	ADDPARTIAL
OPTIONS_GROUP_OVLYS+=	ALLOP
OPTIONS_GROUP_OVLYS+=	AUTOCA
OPTIONS_GROUP_OVLYS+=	AUDITLOG
OPTIONS_GROUP_OVLYS+=	AUTOGROUP
OPTIONS_GROUP_OVLYS+=	CLOAK
OPTIONS_GROUP_OVLYS+=	COLLECT
OPTIONS_GROUP_OVLYS+=	CONSTRAINT
OPTIONS_GROUP_OVLYS+=	DDS
OPTIONS_GROUP_OVLYS+=	DENYOP
OPTIONS_GROUP_OVLYS+=	DEREF
OPTIONS_GROUP_OVLYS+=	DYNGROUP
OPTIONS_GROUP_OVLYS+=	DYNLIST
OPTIONS_GROUP_OVLYS+=	EMPTYDS
OPTIONS_GROUP_OVLYS+=	HOMEDIR
OPTIONS_GROUP_OVLYS+=	LASTBIND
OPTIONS_GROUP_OVLYS+=	LASTMOD
OPTIONS_GROUP_OVLYS+=	MEMBEROF
OPTIONS_GROUP_OVLYS+=	NOPS
OPTIONS_GROUP_OVLYS+=	NESTGROUP
OPTIONS_GROUP_OVLYS+=	OTP
OPTIONS_GROUP_OVLYS+=	PROXYCACHE
OPTIONS_GROUP_OVLYS+=	PPOLICY
OPTIONS_GROUP_OVLYS+=	REFINT
OPTIONS_GROUP_OVLYS+=	REMOTEAUTH
OPTIONS_GROUP_OVLYS+=	RETCODE
OPTIONS_GROUP_OVLYS+=	RWM
OPTIONS_GROUP_OVLYS+=	SEQMOD
OPTIONS_GROUP_OVLYS+=	SHA2
OPTIONS_GROUP_OVLYS+=	SMBPWD
OPTIONS_GROUP_OVLYS+=	SSSVLV
OPTIONS_GROUP_OVLYS+=	SYNCPROV
OPTIONS_GROUP_OVLYS+=	TRACE
OPTIONS_GROUP_OVLYS+=	TRANSLUCENT
OPTIONS_GROUP_OVLYS+=	UNIQUE
OPTIONS_GROUP_OVLYS+=	VALSORT

OPTIONS_DEFINE+=	DYNACL ACI
OPTIONS_DEFINE+=	RLOOKUPS SLP SLAPI
OPTIONS_DEFINE+=	PBKDF2
OPTIONS_DEFINE+=	OUTLOOK
OPTIONS_DEFINE+=	ARGON2
OPTIONS_DEFINE+=	LLOADD

OPTIONS_EXCLUDE_FreeBSD_15=	SMBPWD	# Only works with Heimdal

OPTIONS_DEFAULT+=	${BKNDS_DEFAULTS}
OPTIONS_DEFAULT+=	${OPTIONS_GROUP_OVLYS}
OPTIONS_DEFAULT+=	ARGON2 LLOADD

OPTIONS_SUB=		yes

ACI_DESC=		Per-object ACI (experimental)
ARGON2_DESC=		Argon2 password hashing module
DYNACL_DESC=		Run-time loadable ACL (experimental)
LLOADD_DESC=		Enable load balancer
OUTLOOK_DESC=		Force caseIgnoreOrderingMatch on name attribute (experimental)
RLOOKUPS_DESC=		With reverse lookups of client hostnames
SLAPI_DESC=		With Netscape SLAPI plugin API (experimental)
SLP_DESC=		With SLPv2 (RFC 2608) support

ASYNCMETA_DESC=		With asynchronous metadirectory backend
DNSSRV_DESC=		With Dnssrv backend
MDB_DESC=		With Memory-Mapped DB backend
SQL_DESC=		With SQL backend
PASSWD_DESC=		With Passwd backend
PERL_DESC=		With Perl backend
RELAY_DESC=		With Relay backend
SOCK_DESC=		With Sock backend

ACCESSLOG_DESC=		With In-Directory Access Logging overlay
AUDITLOG_DESC=		With Audit Logging overlay
AUTOCA_DESC=		With Automatic Certificate Authority overlay
COLLECT_DESC=		With Collect overy Services overlay
CONSTRAINT_DESC=	With Attribute Constraint overlay
DDS_DESC=		With Dynamic Directory Services overlay
DEREF_DESC=		With Dereference overlay
DYNGROUP_DESC=		With Dynamic Group overlay
DYNLIST_DESC=		With Dynamic List overlay
HOMEDIR_DESC=		With Home Directory Management overlay
MEMBEROF_DESC=		With Reverse Group Membership overlay
NESTGROUP_DESC=		With nestgroup overlay
NOPS_DESC=		With nops overlay
OTP_DESC=		With OTP 2-factor authentication overlay
PPOLICY_DESC=		With Password Policy overlay
PROXYCACHE_DESC=	With Proxy Cache overlay
REFINT_DESC=		With Referential Integrity overlay
REMOTEAUTH_DESC=	With Deferred Authentication overlay
RETCODE_DESC=		With Return Code testing overlay
RWM_DESC=		With Rewrite/Remap overlay
SEQMOD_DESC=		With Sequential Modify overlay
SSSVLV_DESC=		With ServerSideSort/VLV overlay
SYNCPROV_DESC=		With Syncrepl Provider overlay
TRANSLUCENT_DESC=	With Translucent Proxy overlay
UNIQUE_DESC=		With attribute Uniqueness overlay
VALSORT_DESC=		With Value Sorting overlay

ADDPARTIAL_DESC=	With addpartial overlay (experimental)
ALLOP_DESC=		With allop overlay (experimental)
AUTOGROUP_DESC=		With autogroup overlay (experimental)
CLOAK_DESC=		With cloak overlay (experimental)
DENYOP_DESC=		With denyop overlay (experimental)
EMPTYDS_DESC=		With emptyds overlay (experimental)
LASTBIND_DESC=		With lastbind overlay
LASTMOD_DESC=		With lastmod overlay (experimental)
TRACE_DESC=		With Trace overlay

PBKDF2_DESC=		With PBKDF2 hash password support
SHA2_DESC=		With SHA2 Password hashes overlay
SMBPWD_DESC=		With Samba Password hashes overlay

ACCESSLOG_CONFIGURE_ENABLE=	accesslog=mod
ACI_CONFIGURE_ENABLE=		aci
ARGON2_CONFIGURE_ENABLE=	argon2
ARGON2_CONFIGURE_WITH=		argon2=libsodium
ARGON2_LIB_DEPENDS=		libsodium.so:security/libsodium
ASYNCMETA_CONFIGURE_ENABLE=	asyncmeta=mod
AUDITLOG_CONFIGURE_ENABLE=	auditlog=mod
AUTOCA_CONFIGURE_ENABLE=	autoca=mod
COLLECT_CONFIGURE_ENABLE=	collect=mod
CONSTRAINT_CONFIGURE_ENABLE=	constraint=mod
DDS_CONFIGURE_ENABLE=		dds=mod
DEBUG_CONFIGURE_ENABLE=		debug
DEREF_CONFIGURE_ENABLE=		deref=mod
DNSSRV_CONFIGURE_ENABLE=	dnssrv=mod
DYNACL_CONFIGURE_ENABLE=	dynacl
DYNGROUP_CONFIGURE_ENABLE=	dyngroup=mod
DYNLIST_CONFIGURE_ENABLE=	dynlist=mod
HOMEDIR_CONFIGURE_ENABLE=	homedir=mod
LLOADD_CONFIGURE_ENABLE=	balancer=mod
LLOADD_LIB_DEPENDS=		libevent.so:devel/libevent
MDB_CONFIGURE_ENABLE=		mdb=yes
MEMBEROF_CONFIGURE_ENABLE=	memberof=mod
NESTGROUP_CONFIGURE_ENABLE=	nestgroup=mod
OTP_CONFIGURE_ENABLE=		otp=mod
PASSWD_CONFIGURE_ENABLE=	passwd=mod
PERL_CONFIGURE_ENABLE=		perl=mod
PERL_CONFIGURE_ENV=		PERLBIN="${PERL}"
PERL_USES=			perl5
PPOLICY_CONFIGURE_ENABLE=	ppolicy=mod
PROXYCACHE_CONFIGURE_ENABLE=	proxycache=mod
REFINT_CONFIGURE_ENABLE=	refint=mod
RELAY_CONFIGURE_ENABLE=		relay=yes
REMOTEAUTH_CONFIGURE_ENABLE=	remoteauth=mod
RETCODE_CONFIGURE_ENABLE=	retcode=mod
RLOOKUPS_CONFIGURE_ENABLE=	rlookups
RWM_CONFIGURE_ENABLE=		rwm=mod
SEQMOD_CONFIGURE_ENABLE=	seqmod=mod
SLAPI_CONFIGURE_ENABLE=		slapi
SLAPI_USE=			LDCONFIG
SLP_CONFIGURE_ENABLE=		slp
SLP_LIB_DEPENDS=		libslp.so:net/openslp
SOCK_CONFIGURE_ENABLE=		sock=mod
SQL_CONFIGURE_ENABLE=		sql=mod
SQL_LDFLAGS=			-L${LOCALBASE}/lib
SQL_LIB_DEPENDS=		libodbc.so:databases/unixODBC
SSSVLV_CONFIGURE_ENABLE=	sssvlv=mod
SYNCPROV_CONFIGURE_ENABLE=	syncprov=yes
TRANSLUCENT_CONFIGURE_ENABLE=	translucent=mod
UNIQUE_CONFIGURE_ENABLE=	unique=mod
VALSORT_CONFIGURE_ENABLE=	valsort=mod

# Force using caseIgnoreOrderingMatch on 'name' attribute.
# This may be a violation of RFC 4519 2.18 definition.
# See http://www.openldap.org/lists/openldap-technical/201211/msg00175.html
OUTLOOK_EXTRA_PATCHES=		${FILESDIR}/extrapatch-outlook-servers__slapd__schema_prep.c
.endif

CONFIGURE_SED=		-e 's,uuid/uuid.h,xxuuid/uuid.h,g'

.include <bsd.port.options.mk>

.if defined(CLIENT_ONLY)
OPENLDAP_PORTREVISION=	${PORTREVISION_CLIENT}
OPENLDAP_PKGFILESUFX=	.client

PORTDOCS=		CHANGES drafts rfc

CONFIGURE_ARGS+=	--disable-slapd \
			--disable-monitor \
			--disable-relay \
			--disable-syncprov
USE_LDCONFIG=		yes
.else
OPENLDAP_PORTREVISION=	${PORTREVISION_SERVER}
OPENLDAP_PKGFILESUFX=

LIB_DEPENDS+=		libicudata.so:devel/icu \
			libldap.so:net/openldap26-client \
			libltdl.so:devel/libltdl

SUB_LIST+=		RC_DIR=${PREFIX} \
			LDAP_RUN_DIR=${LDAP_RUN_DIR} \
			DATABASEDIR=${DATABASEDIR}

USERS=			ldap
GROUPS=			ldap
LDAP_USER?=		ldap
LDAP_GROUP?=		ldap
USE_LDCONFIG=		${PREFIX}/libexec/openldap
SUB_FILES+=		pkg-deinstall
USE_RC_SUBR=		slapd

EXTRA_PATCHES+=		${FILESDIR}/extrapatch-Makefile.in

LDFLAGS+=		-L${LOCALBASE}/lib

SED_MODULES=		-e 's/\(moduleload[ 	]*back_[a-z]*\)\.la/\1/' \
			-e 's/\# *\(modulepath\)/\1/'

CONFIGURE_ARGS+=	--enable-modules \
			--localstatedir=${LOCALSTATEDIR} \
			--enable-crypt \
			--enable-ldap=mod \
			--enable-meta=mod \
			--enable-null=mod
.endif

LDAP_RUN_DIR?=		/var/run/openldap
LOCALSTATEDIR?=		/var/db
DATABASEDIR?=		${LOCALSTATEDIR}/openldap-data
BACKUPDIR?=		/var/backups/openldap

DESCR=			${PKGDIR}/pkg-descr${OPENLDAP_PKGFILESUFX}
PLIST=			${PKGDIR}/pkg-plist${OPENLDAP_PKGFILESUFX}

SUB_FILES+=		pkg-message${OPENLDAP_PKGFILESUFX}
PKGMESSAGE=		${WRKSRC}/pkg-message${OPENLDAP_PKGFILESUFX}

SUB_LIST+=		LDAP_RUN_DIR=${LDAP_RUN_DIR} \
			LDAP_USER=${LDAP_USER} \
			LDAP_GROUP=${LDAP_GROUP} \
			BACKUPDIR=${BACKUPDIR} \
			DATABASEDIR=${DATABASEDIR} \
			PORTNAME=${PORTNAME} \
			PKGNAME=${PKGNAME} \
			PKGNAMESUFFIX=${PKGNAMESUFFIX}

CONFIGURE_ARGS+=	--with-threads=posix \
			--with-tls=openssl \
			--enable-dynamic

LIB_DEPENDS+=		libsasl2.so:security/cyrus-sasl2
CONFIGURE_ARGS+=	--with-cyrus-sasl --enable-spasswd
MAKE_ENV+=		STRIP=${STRIP}

CPPFLAGS+=		-I${LOCALBASE}/include
LIBS+=			-L${LOCALBASE}/lib

PLIST_SUB+=		${SUB_LIST}
PLIST_SUB+=		SHLIB_MAJOR=${OPENLDAP_SHLIB_MAJOR}
PLIST_SUB+=		SHLIB_MINOR=${OPENLDAP_SHLIB_MINOR}

.if ${PORT_OPTIONS:MFETCH} && (defined(OPENSSL_INSTALLED) && ${OPENSSL_INSTALLED} != "" || ${SSL_DEFAULT} != base)
BROKEN=	using OpenSSL from ports and OPTION FETCH together is not supported
. endif

.if ${PORT_OPTIONS:MADDPARTIAL}
CONTRIB_MODULES+=	slapd-modules/addpartial
CONTRIB_CLEANFILES+=	addpartial.a
.endif
.if ${PORT_OPTIONS:MALLOP}
CONTRIB_MODULES+=	slapd-modules/allop
CONTRIB_CLEANFILES+=	allop.a
.endif
.if ${PORT_OPTIONS:MAUTOGROUP}
CONTRIB_MODULES+=	slapd-modules/autogroup
CONTRIB_CLEANFILES+=	autogroup.a
.endif
.if ${PORT_OPTIONS:MCLOAK}
CONTRIB_MODULES+=	slapd-modules/cloak
CONTRIB_CLEANFILES+=	cloak.a
.endif
.if ${PORT_OPTIONS:MDENYOP}
CONTRIB_MODULES+=	slapd-modules/denyop
CONTRIB_CLEANFILES+=	denyop.a
.endif
.if ${PORT_OPTIONS:MEMPTYDS}
CONTRIB_MODULES+=	slapd-modules/emptyds
CONTRIB_CLEANFILES+=	emptyds.a
.endif
.if ${PORT_OPTIONS:MLASTBIND}
CONTRIB_MODULES+=	slapd-modules/lastbind
CONTRIB_CLEANFILES+=	lastbind.a
.endif
.if ${PORT_OPTIONS:MLASTMOD}
CONTRIB_MODULES+=	slapd-modules/lastmod
CONTRIB_CLEANFILES+=	lastmod.a
.endif
.if ${PORT_OPTIONS:MNOPS}
CONTRIB_MODULES+=	slapd-modules/nops
CONTRIB_CLEANFILES+=	nops.a
.endif
.if ${PORT_OPTIONS:MTRACE}
CONTRIB_MODULES+=	slapd-modules/trace
CONTRIB_CLEANFILES+=	trace.a
.endif
.if ${PORT_OPTIONS:MSHA2}
CONTRIB_MODULES+=	slapd-modules/passwd/sha2
CONTRIB_CLEANFILES+=	pw-sha2.a
.endif
.if ${PORT_OPTIONS:MPBKDF2}
CONTRIB_MODULES+=	slapd-modules/passwd/pbkdf2
CONTRIB_CLEANFILES+=	pw-pbkdf2.a
.endif
.if ${PORT_OPTIONS:MSMBPWD}
CONTRIB_MODULES+=	slapd-modules/smbk5pwd
CONTRIB_CLEANFILES+=	smbk5pwd.a
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%LOCALSTATEDIR%/run/|${LDAP_RUN_DIR}/|g' \
		${SED_MODULES} ${WRKSRC}/servers/slapd/slapd.conf
	@${REINPLACE_CMD} -e 's|%LOCALSTATEDIR%/run/|${LDAP_RUN_DIR}/|g' \
		${SED_MODULES} ${WRKSRC}/servers/slapd/slapd.ldif
	@${REINPLACE_CMD} -e 's|^OPT =.*|OPT = ${CFLAGS}|g' \
		-e 's|^CC =.*|CC = ${CC}|g' \
		${SED_MODULES} ${WRKSRC}/contrib/slapd-modules/*/Makefile \
		${WRKSRC}/contrib/slapd-modules/*/*/Makefile
.if defined(CONFIGURE_SED)
	@${REINPLACE_CMD} -E ${CONFIGURE_SED} \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
.endif
.if !${PORT_OPTIONS:MDEBUG}
	@${REINPLACE_CMD} -E \
		-e '/ldap_dump_(connection|requests_and_responses);/d' \
		${WRKSRC}/libraries/libldap/ldap.map
.endif

pre-configure:
	@(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf)

.if !defined(CLIENT_ONLY)
test: build
	@(cd ${BUILD_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)

post-build:
.for module in ${CONTRIB_MODULES}
	@(cd ${BUILD_WRKSRC}/contrib/${module} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} prefix="${PREFIX}" all)
.endfor
.endif

pre-install:
.if !defined(CLIENT_ONLY)
	${MKDIR} ${STAGEDIR}${DATABASEDIR}
.endif

post-install:
.if defined(CLIENT_ONLY)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}
	for dir in drafts rfc; do \
		${MKDIR} ${STAGEDIR}${DOCSDIR}/$${dir}; \
		${INSTALL_DATA} ${WRKSRC}/doc/$${dir}/* ${STAGEDIR}${DOCSDIR}/$${dir}; \
	done
	for prog in ldapcompare ldapdelete ldapexop ldapmodify ldapmodrdn ldappasswd ldapsearch ldapurl ldapvc ldapwhoami; do\
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/$${prog}; \
	done
	for library in lber ldap; do \
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib$${library}.so.${OPENLDAP_SHLIB_MAJOR}; \
	done
.else
	${MKDIR} ${STAGEDIR}${LDAP_RUN_DIR}
.for module in ${CONTRIB_MODULES}
	(cd ${WRKSRC}/contrib/${module} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} prefix="${PREFIX}" install)
.endfor
.for cleanfile in ${CONTRIB_CLEANFILES}
	${RM} ${STAGEDIR}${PREFIX}/libexec/openldap/${cleanfile}
.endfor
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/openldap/*.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/slapd
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/openldap
.endif # defined(CLIENT_ONLY)

post-install-SLAPI-on:
	for library in slapi; do \
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib$${library}.so.${OPENLDAP_SHLIB_MAJOR}; \
	done

.include <bsd.port.mk>
