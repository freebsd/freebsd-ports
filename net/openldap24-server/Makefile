PORTNAME=		openldap
DISTVERSION=		2.4.59
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
PKGNAMESUFFIX=		24-client
.else
PKGNAMESUFFIX=		24-server
.endif

MAINTAINER=		delphij@FreeBSD.org
.if defined(CLIENT_ONLY)
COMMENT=		Open source LDAP client implementation
.else
COMMENT=		Open source LDAP server implementation
.endif

LICENSE=		OPENLDAP
LICENSE_NAME=		OpenLDAP Public License
LICENSE_FILE=		${WRKSRC}/LICENSE
LICENSE_PERMS=		dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

.if defined(CLIENT_ONLY)
CONFLICTS_INSTALL=	${PORTNAME}2[0-3][5-9]-client ${PORTNAME}2[0-35-9]-client ${PORTNAME}-client
.else
CONFLICTS_INSTALL=	${PORTNAME}2[0-3][5-9]-server ${PORTNAME}2[0-35-9]-server ${PORTNAME}-server
.endif

GNU_CONFIGURE=		yes
# :keepla because port uses lt_dlopen
USES=			cpe libtool:keepla ssl tar:tgz

WANT_OPENLDAP_VER?=	24
.if ${WANT_OPENLDAP_VER} != 24
BROKEN=			incompatible OpenLDAP version: ${WANT_OPENLDAP_VER}
.endif

PORTREVISION_CLIENT=	4
PORTREVISION_SERVER=	9
OPENLDAP_SHLIB_MAJOR=	2
OPENLDAP_SHLIB_MINOR=	11.7
OPENLDAP_MAJOR=		${DISTVERSION:R}

OPTIONS_DEFINE=		DEBUG FETCH GSSAPI
OPTIONS_DEFAULT=	DEBUG

FETCH_DESC=		Enable fetch(3) support
FETCH_BUILD_DEPENDS=	autoconf>0:devel/autoconf
GSSAPI_DESC=		With GSSAPI support

FETCH_CONFIGURE_WITH=	fetch
GSSAPI_RUN_DEPENDS=	cyrus-sasl-gssapi>0:security/cyrus-sasl2-gssapi

.if defined(CLIENT_ONLY)
OPTIONS_DEFINE+=	DOCS
.else
OPTIONS_GROUP=		BKNDS OVLYS
BKNDS_DESC=		OpenLDAP backends
BKNDS_DEFAULTS=		DNSSRV MDB PASSWD RELAY ODBC SOCK
OPTIONS_GROUP_BKNDS+=	${BKNDS_DEFAULTS}
OPTIONS_GROUP_BKNDS+=	BDB PERL SHELL

OVLYS_DESC=		OpenLDAP overlays
OPTIONS_GROUP_OVLYS+=	ACCESSLOG
OPTIONS_GROUP_OVLYS+=	ADDPARTIAL
OPTIONS_GROUP_OVLYS+=	ALLOP
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
OPTIONS_GROUP_OVLYS+=	LASTBIND
OPTIONS_GROUP_OVLYS+=	LASTMOD
OPTIONS_GROUP_OVLYS+=	MEMBEROF
OPTIONS_GROUP_OVLYS+=	NOPS
OPTIONS_GROUP_OVLYS+=	PCACHE
OPTIONS_GROUP_OVLYS+=	PPOLICY
OPTIONS_GROUP_OVLYS+=	REFINT
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
OPTIONS_DEFINE+=	RLOOKUPS SLP SLAPI TCP_WRAPPERS
OPTIONS_DEFINE+=	DYNAMIC_BACKENDS
OPTIONS_DEFINE+=	LMPASSWD
OPTIONS_DEFINE+=	PBKDF2
OPTIONS_DEFINE+=	OUTLOOK
OPTIONS_DEFINE+=	KQUEUE
OPTIONS_DEFINE+=	DYNAMIC_MODULES

OPTIONS_DEFAULT+=	DYNAMIC_MODULES
OPTIONS_DEFAULT+=	${BKNDS_DEFAULTS}
OPTIONS_DEFAULT+=	${OPTIONS_GROUP_OVLYS}

DYNACL_DESC=		Run-time loadable ACL (experimental)
ACI_DESC=		Per-object ACI (experimental)
BDB_DESC=		With BerkeleyDB backend (DEPRECATED)
MDB_DESC=		With Memory-Mapped DB backend
DNSSRV_DESC=		With Dnssrv backend
PASSWD_DESC=		With Passwd backend
PERL_DESC=		With Perl backend
RELAY_DESC=		With Relay backend
SHELL_DESC=		With Shell backend (disables threading)
SOCK_DESC=		With Sock backend
ODBC_DESC=		With SQL backend
RLOOKUPS_DESC=		With reverse lookups of client hostnames
SLP_DESC=		With SLPv2 (RFC 2608) support
SLAPI_DESC=		With Netscape SLAPI plugin API (experimental)
TCP_WRAPPERS_DESC=	With tcp wrapper support
ACCESSLOG_DESC=		With In-Directory Access Logging overlay
ADDPARTIAL_DESC=	With addpartial overlay (experimental)
ALLOP_DESC=		With allop overlay (experimental)
AUDITLOG_DESC=		With Audit Logging overlay
AUTOGROUP_DESC=		With autogroup overlay (experimental)
CLOAK_DESC=		With cloak overlay (experimental)
COLLECT_DESC=		With Collect overy Services overlay
CONSTRAINT_DESC=	With Attribute Constraint overlay
DDS_DESC=		With Dynamic Directory Services overlay
DEREF_DESC=		With Dereference overlay
DENYOP_DESC=		With denyop overlay (experimental)
DYNGROUP_DESC=		With Dynamic Group overlay
DYNLIST_DESC=		With Dynamic List overlay
MEMBEROF_DESC=		With Reverse Group Membership overlay
NOPS_DESC=		With nops overlay
PPOLICY_DESC=		With Password Policy overlay
PCACHE_DESC=		With Proxy Cache overlay
REFINT_DESC=		With Referential Integrity overlay
RETCODE_DESC=		With Return Code testing overlay
RWM_DESC=		With Rewrite/Remap overlay
SEQMOD_DESC=		With Sequential Modify overlay
SSSVLV_DESC=		With ServerSideSort/VLV overlay
SYNCPROV_DESC=		With Syncrepl Provider overlay
TRACE_DESC=		With Trace overlay
TRANSLUCENT_DESC=	With Translucent Proxy overlay
UNIQUE_DESC=		With attribute Uniqueness overlay
VALSORT_DESC=		With Value Sorting overlay
SMBPWD_DESC=		With Samba Password hashes overlay
SHA2_DESC=		With SHA2 Password hashes overlay
LMPASSWD_DESC=		With LM hash password support (DEPRECATED)
PBKDF2_DESC=		With PBKDF2 hash password support
DYNAMIC_BACKENDS_DESC=	Build dynamic backends (DEPRECATED)
DYNAMIC_MODULES_DESC=	Build dynamic backend and overlay modules
OUTLOOK_DESC=		Force caseIgnoreOrderingMatch on name attribute (experimental)
LASTBIND_DESC=		With lastbind overlay
LASTMOD_DESC=		With lastmod overlay (experimental)
KQUEUE_DESC=		With kqueue support (experimental)

ACCESSLOG_CONFIGURE_ENABLE=	accesslog=${OVERLAY_ENABLE}
ACCESSLOG_PLIST_SUB=		OVERLAY_ACCESSLOG=${OVERLAY_PLIST}
ACCESSLOG_PLIST_SUB_OFF=	OVERLAY_ACCESSLOG="@comment "

AUDITLOG_CONFIGURE_ENABLE=	auditlog=${OVERLAY_ENABLE}
AUDITLOG_PLIST_SUB=		OVERLAY_AUDITLOG=${OVERLAY_PLIST}
AUDITLOG_PLIST_SUB_OFF=		OVERLAY_AUDITLOG="@comment "

ADDPARTIAL_PLIST_SUB=		OVERLAY_ADDPARTIAL=${OVERLAY_PLIST}
ADDPARTIAL_PLIST_SUB_OFF=	OVERLAY_ADDPARTIAL="@comment "

ALLOP_PLIST_SUB=		OVERLAY_ALLOP=${OVERLAY_PLIST}
ALLOP_PLIST_SUB_OFF=		OVERLAY_ALLOP="@comment "

AUTOGROUP_PLIST_SUB=		OVERLAY_AUTOGROUP=${OVERLAY_PLIST}
AUTOGROUP_PLIST_SUB_OFF=	OVERLAY_AUTOGROUP="@comment "

CLOAK_PLIST_SUB=		OVERLAY_CLOAK=${OVERLAY_PLIST}
CLOAK_PLIST_SUB_OFF=		OVERLAY_CLOAK="@comment "

COLLECT_CONFIGURE_ENABLE=	collect=${OVERLAY_ENABLE}
COLLECT_PLIST_SUB=		OVERLAY_COLLECT=${OVERLAY_PLIST}
COLLECT_PLIST_SUB_OFF=		OVERLAY_COLLECT="@comment "

CONSTRAINT_CONFIGURE_ENABLE=	constraint=${OVERLAY_ENABLE}
CONSTRAINT_PLIST_SUB=		OVERLAY_CONSTRAINT=${OVERLAY_PLIST}
CONSTRAINT_PLIST_SUB_OFF=	OVERLAY_CONSTRAINT="@comment "

DDS_CONFIGURE_ENABLE=		dds=${OVERLAY_ENABLE}
DDS_PLIST_SUB=			OVERLAY_DDS=${OVERLAY_PLIST}
DDS_PLIST_SUB_OFF=		OVERLAY_DDS="@comment "

DENYOP_PLIST_SUB=		OVERLAY_DENYOP=${OVERLAY_PLIST}
DENYOP_PLIST_SUB_OFF=		OVERLAY_DENYOP="@comment "

DEBUG_CONFIGURE_ENABLE=		debug
MAKE_ENV+=			STRIP=${STRIP}

KQUEUE_BUILD_DEPENDS=		autoconf>0:devel/autoconf
KQUEUE_EXTRA_PATCHES+=		${FILESDIR}/extrapatch-ITS6300

LMPASSWD_CONFIGURE_ENABLE=	lmpasswd

DEREF_CONFIGURE_ENABLE=		deref=${OVERLAY_ENABLE}
DEREF_PLIST_SUB=		OVERLAY_DEREF=${OVERLAY_PLIST}
DEREF_PLIST_SUB_OFF=		OVERLAY_DEREF="@comment "

DYNGROUP_CONFIGURE_ENABLE=	dyngroup=${OVERLAY_ENABLE}
DYNGROUP_PLIST_SUB=		OVERLAY_DYNGROUP=${OVERLAY_PLIST}
DYNGROUP_PLIST_SUB_OFF=		OVERLAY_DYNGROUP="@comment "

DYNLIST_CONFIGURE_ENABLE=	dynlist=${OVERLAY_ENABLE}
DYNLIST_PLIST_SUB=		OVERLAY_DYNLIST=${OVERLAY_PLIST}
DYNLIST_PLIST_SUB_OFF=		OVERLAY_DYNLIST="@comment "

MEMBEROF_CONFIGURE_ENABLE=	memberof=${OVERLAY_ENABLE}
MEMBEROF_PLIST_SUB=		OVERLAY_MEMBEROF=${OVERLAY_PLIST}
MEMBEROF_PLIST_SUB_OFF=		OVERLAY_MEMBEROF="@comment "

PPOLICY_CONFIGURE_ENABLE=	ppolicy=${OVERLAY_ENABLE}
PPOLICY_PLIST_SUB=		OVERLAY_PPOLICY=${OVERLAY_PLIST}
PPOLICY_PLIST_SUB_OFF=		OVERLAY_PPOLICY="@comment "

PCACHE_CONFIGURE_ENABLE=	proxycache=${OVERLAY_ENABLE}
PCACHE_PLIST_SUB=		OVERLAY_PCACHE=${OVERLAY_PLIST}
PCACHE_PLIST_SUB_OFF=		OVERLAY_PCACHE="@comment "

REFINT_CONFIGURE_ENABLE=	refint=${OVERLAY_ENABLE}
REFINT_PLIST_SUB=		OVERLAY_REFINT=${OVERLAY_PLIST}
REFINT_PLIST_SUB_OFF=		OVERLAY_REFINT="@comment "

RETCODE_CONFIGURE_ENABLE=	retcode=${OVERLAY_ENABLE}
RETCODE_PLIST_SUB=		OVERLAY_RETCODE=${OVERLAY_PLIST}
RETCODE_PLIST_SUB_OFF=		OVERLAY_RETCODE="@comment "

RWM_CONFIGURE_ENABLE+=		rwm=${OVERLAY_ENABLE}
RWM_PLIST_SUB=			OVERLAY_RWM=${OVERLAY_PLIST}
RWM_PLIST_SUB_OFF=		OVERLAY_RWM="@comment "

SEQMOD_CONFIGURE_ENABLE=	seqmod=${OVERLAY_ENABLE}
SEQMOD_PLIST_SUB=		OVERLAY_SEQMOD=${OVERLAY_PLIST}
SEQMOD_PLIST_SUB_OFF=		OVERLAY_SEQMOD="@comment "

SSSVLV_CONFIGURE_ENABLE=	sssvlv=${OVERLAY_ENABLE}
SSSVLV_PLIST_SUB=		OVERLAY_SSSVLV=${OVERLAY_PLIST}
SSSVLV_PLIST_SUB_OFF=		OVERLAY_SSSVLV="@comment "

SYNCPROV_CONFIGURE_ENABLE=	syncprov=${OVERLAY_ENABLE}
SYNCPROV_PLIST_SUB=		OVERLAY_SYNCPROV=${OVERLAY_PLIST}
SYNCPROV_PLIST_SUB_OFF=		OVERLAY_SYNCPROV="@comment "

TRANSLUCENT_CONFIGURE_ENABLE=	translucent=${OVERLAY_ENABLE}
TRANSLUCENT_PLIST_SUB=		OVERLAY_TRANSLUCENT=${OVERLAY_PLIST}
TRANSLUCENT_PLIST_SUB_OFF=	OVERLAY_TRANSLUCENT="@comment "

UNIQUE_CONFIGURE_ENABLE=	unique=${OVERLAY_ENABLE}
UNIQUE_PLIST_SUB=		OVERLAY_UNIQUE=${OVERLAY_PLIST}
UNIQUE_PLIST_SUB_OFF=		OVERLAY_UNIQUE="@comment "

VALSORT_CONFIGURE_ENABLE=	valsort=${OVERLAY_ENABLE}
VALSORT_PLIST_SUB=		OVERLAY_VALSORT=${OVERLAY_PLIST}
VALSORT_PLIST_SUB_OFF=		OVERLAY_VALSORT="@comment "

ACI_CONFIGURE_ENABLE=		aci
DYNACL_CONFIGURE_ENABLE=	dynacl

DNSSRV_CONFIGURE_ENABLE=	dnssrv=${BACKEND_ENABLE}
DNSSRV_PLIST_SUB=		BACK_DNSSRV=${BACKEND_PLIST}
DNSSRV_PLIST_SUB_OFF=		BACK_DNSSRV="@comment "

MDB_CONFIGURE_ENABLE=		mdb=${BACKEND_ENABLE}
MDB_PLIST_SUB=			BACK_MDB=${BACKEND_PLIST}
MDB_PLIST_SUB_OFF=		BACK_MDB="@comment "

PASSWD_CONFIGURE_ENABLE=	passwd=${BACKEND_ENABLE}
PASSWD_PLIST_SUB=		BACK_PASSWD=${BACKEND_PLIST}
PASSWD_PLIST_SUB_OFF=		BACK_PASSWD="@comment "

RELAY_CONFIGURE_ENABLE=		relay=${BACKEND_ENABLE}
RELAY_PLIST_SUB=		BACK_RELAY=${BACKEND_PLIST}
RELAY_PLIST_SUB_OFF=		BACK_RELAY="@comment "

SHELL_CONFIGURE_ARGS=		--without-threads
SHELL_CONFIGURE_ENABLE=		shell=${BACKEND_ENABLE}
SHELL_PLIST_SUB=		BACK_SHELL=${BACKEND_PLIST}
SHELL_PLIST_SUB_OFF=		BACK_SHELL="@comment "

SOCK_CONFIGURE_ENABLE=		sock=${BACKEND_ENABLE}
SOCK_PLIST_SUB=			BACK_SOCK=${BACKEND_PLIST}
SOCK_PLIST_SUB_OFF=		BACK_SOCK="@comment "

PERL_USES=			perl5
PERL_CONFIGURE_ENABLE=		perl=${BACKEND_ENABLE}
PERL_CONFIGURE_ENV=		PERLBIN="${PERL}"
PERL_PLIST_SUB=			BACK_PERL=${BACKEND_PLIST}
PERL_PLIST_SUB_OFF=		BACK_PERL="@comment "

CONFIGURE_ARGS+=		--enable-spasswd

ODBC_CONFIGURE_ENABLE=		sql=${BACKEND_ENABLE}
ODBC_LIB_DEPENDS=		libodbc.so:databases/unixODBC
ODBC_LDFLAGS=			-L${LOCALBASE}/lib
ODBC_PLIST_SUB=			BACK_SQL=${BACKEND_PLIST}
ODBC_PLIST_SUB_OFF=		BACK_SQL="@comment "

SMBPWD_PLIST_SUB=		SMBPWD=""
SMBPWD_PLIST_SUB_OFF=		SMBPWD="@comment "

SHA2_PLIST_SUB=			SHA2=""
SHA2_PLIST_SUB_OFF=		SHA2="@comment "

PBKDF2_PLIST_SUB=		PBKDF2=""
PBKDF2_PLIST_SUB_OFF=		PBKDF2="@comment "

LASTBIND_PLIST_SUB=		OVERLAY_LASTBIND=""
LASTBIND_PLIST_SUB_OFF=		OVERLAY_LASTBIND="@comment "

LASTMOD_PLIST_SUB=		OVERLAY_LASTMOD=""
LASTMOD_PLIST_SUB_OFF=		OVERLAY_LASTMOD="@comment "

NOPS_PLIST_SUB=			OVERLAY_NOPS=""
NOPS_PLIST_SUB_OFF=		OVERLAY_NOPS="@comment "

RLOOKUPS_CONFIGURE_ENABLE=	rlookups
RLOOKUPS_SUB=			RLOOKUPS=""
RLOOKUPS_PLIST_SUB_OFF=		RLOOKUPS="@comment "

SLAPI_CONFIGURE_ENABLE=		slapi
SLAPI_PLIST_SUB=		SLAPI=""
SLAPI_PLIST_SUB_OFF=		SLAPI="@comment "

SLP_CONFIGURE_ENABLE=		slp
SLP_LIB_DEPENDS=		libslp.so:net/openslp

TRACE_PLIST_SUB=		OVERLAY_TRACE=""
TRACE_PLIST_SUB_OFF=		OVERLAY_TRACE="@comment "

TCP_WRAPPERS_CONFIGURE_ENABLE=	wrappers

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

.if defined(USE_OPENLDAP)
BROKEN=			you have USE_OPENLDAP variable defined either in environment or in make(1) arguments; please undefine and try again
.endif
.else
OPENLDAP_PORTREVISION=	${PORTREVISION_SERVER}
OPENLDAP_PKGFILESUFX=

USE_OPENLDAP=		yes
WANT_OPENLDAP_VER=	24

LIB_DEPENDS+=		libicudata.so:devel/icu

SUB_LIST+=		RC_DIR=${PREFIX} \
			LDAP_RUN_DIR=${LDAP_RUN_DIR} \
			DATABASEDIR=${DATABASEDIR}

USERS=			ldap
GROUPS=			ldap
LDAP_USER?=		ldap
LDAP_GROUP?=		ldap
.endif

DESCR=			${PKGDIR}/pkg-descr${OPENLDAP_PKGFILESUFX}
PLIST=			${PKGDIR}/pkg-plist${OPENLDAP_PKGFILESUFX}

SCHEMATA=		collective corba core cosine duaconf dyngroup \
			inetorgperson java misc \
			nis openldap pmi ppolicy

LDAP_RUN_DIR?=		/var/run/openldap
LOCALSTATEDIR?=		/var/db
DATABASEDIR?=		${LOCALSTATEDIR}/openldap-data
BACKUPDIR?=		/var/backups/openldap

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
			--disable-dependency-tracking \
			--enable-dynamic

LIB_DEPENDS+=		libsasl2.so:security/cyrus-sasl2
CONFIGURE_ARGS+=	--with-cyrus-sasl

.if defined(CLIENT_ONLY)
# client specific configuration

CONFIGURE_ARGS+=	--disable-slapd \
			--disable-monitor \
			--disable-bdb \
			--disable-relay \
			--disable-syncprov
SUB_FILES+=		pkg-message.client
PKGMESSAGE=		${WRKSRC}/pkg-message.client

USE_LDCONFIG=		yes

.else
# server specific configuration

USE_LDCONFIG=		${PREFIX}/libexec/openldap
SUB_FILES+=		pkg-message pkg-deinstall
USE_RC_SUBR=		slapd

EXTRA_PATCHES+=		${FILESDIR}/extrapatch-Makefile.in

.if ${PORT_OPTIONS:MDYNAMIC_MODULES} || ${PORT_OPTIONS:MDYNAMIC_BACKENDS} || ${PORT_OPTIONS:MSLAPI}
LIB_DEPENDS+=		libltdl.so:devel/libltdl
LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--enable-modules
PLIST_SUB+=		MODULES=""
.else
PLIST_SUB+=		MODULES="@comment "
.endif

SED_MODULES=		-e 's/\(moduleload[ 	]*back_[a-z]*\)\.la/\1/'

.if ${PORT_OPTIONS:MDYNAMIC_MODULES} || ${PORT_OPTIONS:MDYNAMIC_BACKENDS}
BACKEND_ENABLE=		"mod"
BACKEND_PLIST=		""
SED_MODULES+=		-e 's/\# *\(modulepath\)/\1/' \
			-e 's/\# *\(moduleload[ 	]*back_bdb\)/\1/'
.else
BACKEND_ENABLE=		"yes"
BACKEND_PLIST=		"@comment "
.endif

.if ${PORT_OPTIONS:MDYNAMIC_MODULES}
OVERLAY_ENABLE=		mod
OVERLAY_PLIST=		""
.else
OVERLAY_ENABLE=		yes
OVERLAY_PLIST=		"@comment "
.endif

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--enable-crypt \
			--enable-ldap=${BACKEND_ENABLE} \
			--enable-meta=${BACKEND_ENABLE} \
			--enable-rewrite \
			--enable-null=${BACKEND_ENABLE} \
			--enable-monitor=${BACKEND_ENABLE}

PLIST_SUB+=		BACKEND=${BACKEND_PLIST}

.if ${PORT_OPTIONS:MBDB}
USES+=			bdb:5

CONFIGURE_ARGS+=	--enable-bdb=${BACKEND_ENABLE} \
			--enable-hdb=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_BDB=${BACKEND_PLIST} \
			BACK_HDB=${BACKEND_PLIST}

CPPFLAGS+=		-I${BDB_INCLUDE_DIR}
LDFLAGS+=		-L${BDB_LIB_DIR}
CONFIGURE_SED+=		-e 's,ol_DB_LIB=$$,&-l${BDB_LIB_NAME:R},' \
			-e 's,(ol_cv_lib_db=)yes$$,\1-l${BDB_LIB_NAME:R},'
.else
CONFIGURE_ARGS+=	--disable-bdb \
			--disable-hdb
PLIST_SUB+=		BACK_BDB="@comment " \
			BACK_HDB="@comment "
.endif

# end of client/server specific configuration
.endif

.if defined(WITH_CLDAP)
CPPFLAGS+=		-DLDAP_CONNECTIONLESS
.endif

CPPFLAGS+=		-I${LOCALBASE}/include
LIBS+=			-L${LOCALBASE}/lib

PLIST_SUB+=		${SUB_LIST}
PLIST_SUB+=		SHLIB_MAJOR=${OPENLDAP_SHLIB_MAJOR}
PLIST_SUB+=		SHLIB_MINOR=${OPENLDAP_SHLIB_MINOR}
PLIST_SUB+=		OPENLDAP_MAJOR=${OPENLDAP_MAJOR}

.include <bsd.port.pre.mk>

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

pre-configure:
	@if [ -n "`${PKG_INFO} -xI '^bind\(84\)\{0,1\}-base-8\.' 2>/dev/null`" ]; then \
		${ECHO_CMD} "${PKGNAME}: bind installed with PORT_REPLACES_BASE_BIND causes build problems."; \
		${FALSE}; \
	fi
.if ${PORT_OPTIONS:MKQUEUE} || ${PORT_OPTIONS:MFETCH}
	@(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf)
.endif

.if !defined(CLIENT_ONLY)
test: build
	@(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)

post-build:
	@${DO_NADA}
.for module in ${CONTRIB_MODULES}
	@(cd ${BUILD_WRKSRC}/contrib/${module} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
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
	for prog in ldapcompare ldapdelete ldapexop ldapmodify ldapmodrdn ldappasswd ldapsearch ldapurl ldapwhoami; do\
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/$${prog}; \
	done

	for library in lber ldap_r; do \
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib$${library}-${OPENLDAP_MAJOR}.so.${OPENLDAP_SHLIB_MAJOR}; \
	done
	for suffix in -${OPENLDAP_MAJOR}.so.2 -${OPENLDAP_MAJOR}.so.${OPENLDAP_SHLIB_MAJOR}.${OPENLDAP_SHLIB_MINOR} .a .la .so; do \
		${LN} -sf libldap_r$${suffix} ${STAGEDIR}${PREFIX}/lib/libldap$${suffix}; \
	done
.else
	${MKDIR} ${STAGEDIR}${LDAP_RUN_DIR}
.for module in ${CONTRIB_MODULES}
	(cd ${WRKSRC}/contrib/${module} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} prefix="${PREFIX}" install)
.endfor
.for cleanfile in ${CONTRIB_CLEANFILES}
	${RM} ${STAGEDIR}${PREFIX}/libexec/openldap/${cleanfile}
.endfor
.if ${PORT_OPTIONS:MDYNAMIC_MODULES} || ${PORT_OPTIONS:MDYNAMIC_BACKENDS} || ${PORT_OPTIONS:MSMBPWD} || ${PORT_OPTIONS:MSHA2} || ${PORT_OPTIONS:MPBKDF2}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/openldap/*.so
.endif
.if ${PORT_OPTIONS:MDYNAMIC_MODULES} || ${PORT_OPTIONS:MDYNAMIC_BACKENDS} || ${PORT_OPTIONS:MSLAPI}
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/openldap
.endif
.endif # defined(CLIENT_ONLY)

.include <bsd.port.post.mk>
