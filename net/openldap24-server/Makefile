# Created by: Xin LI <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=		openldap
DISTVERSION=		2.4.45
PORTREVISION=		${OPENLDAP_PORTREVISION}
CATEGORIES=		net databases
MASTER_SITES=		ftp://ftp.OpenLDAP.org/pub/OpenLDAP/%SUBDIR%/ \
			ftp://gd.tuwien.ac.at/infosys/network/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.ntua.gr/mirror/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.u-aizu.ac.jp/pub/net/openldap/%SUBDIR%/ \
			ftp://ftp.nl.uu.net/pub/unix/db/openldap/%SUBDIR%/ \
			ftp://sunsite.cnlab-switch.ch/mirror/OpenLDAP/%SUBDIR%/ \
			http://www.openldap.org/software/download/OpenLDAP/%SUBDIR%/
MASTER_SITE_SUBDIR=	openldap-release
.if defined(CLIENT_ONLY)
.if ${CLIENT_ONLY} == sasl
PKGNAMESUFFIX=		-sasl-client
.else
PKGNAMESUFFIX=		-client
.endif
.else
PKGNAMESUFFIX?=		-server
.endif

MAINTAINER=		delphij@FreeBSD.org
.if defined(CLIENT_ONLY)
.if ${CLIENT_ONLY} == sasl
COMMENT=		Open source LDAP client implementation with SASL2 support
.else
COMMENT=		Open source LDAP client implementation
.endif
.else
COMMENT=		Open source LDAP server implementation
.endif

LICENSE=		OPENLDAP
LICENSE_NAME=		OpenLDAP Public License
LICENSE_FILE=		${WRKSRC}/LICENSE
LICENSE_PERMS=		dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

.if defined(CLIENT_ONLY)
.if ${CLIENT_ONLY} == sasl
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-client-2.* \
			${PKGNAMEPREFIX}${PORTNAME}-sasl-client-2.[0-3].*
.else
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-client-2.[0-3].* \
			${PKGNAMEPREFIX}${PORTNAME}-sasl-client-2.*
.endif
.endif

GNU_CONFIGURE=		yes
# :keepla because port uses lt_dlopen
USES=			cpe libtool:keepla ssl tar:tgz
.if !defined(CLIENT_ONLY)
USERS=			ldap
GROUPS=			ldap
LDAP_USER?=		ldap
LDAP_GROUP?=		ldap
.endif

WANT_OPENLDAP_VER?=	24
.if ${WANT_OPENLDAP_VER} != 24
BROKEN=			incompatible OpenLDAP version: ${WANT_OPENLDAP_VER}
.endif

PORTREVISION_CLIENT=	0
PORTREVISION_SERVER=	1
OPENLDAP_SHLIB_MAJOR=	2
OPENLDAP_SHLIB_MINOR=	10.8
OPENLDAP_MAJOR=		${DISTVERSION:R}

OPTIONS_DEFINE=		DEBUG FETCH GSSAPI

FETCH_DESC=		Enable fetch(3) support
GSSAPI_DESC=		With GSSAPI support (implies SASL support)

.if !defined(CLIENT_ONLY)
OPTIONS_DEFINE+=	DYNACL ACI BDB MDB DNSSRV PASSWD PERL RELAY SHELL
OPTIONS_DEFINE+=	SOCK ODBC RLOOKUPS SLP SLAPI TCP_WRAPPERS
OPTIONS_DEFINE+=	ACCESSLOG AUDITLOG COLLECT CONSTRAINT DDS
OPTIONS_DEFINE+=	DEREF DYNGROUP DYNLIST MEMBEROF PPOLICY PROXYCACHE
OPTIONS_DEFINE+=	REFINT RETCODE RWM SEQMOD SSSVLV SYNCPROV TRANSLUCENT
OPTIONS_DEFINE+=	UNIQUE VALSORT SMBPWD SHA2 DYNAMIC_BACKENDS SASL
OPTIONS_DEFINE+=	LMPASSWD
OPTIONS_DEFINE+=	OUTLOOK
OPTIONS_DEFINE+=	LASTBIND

OPTIONS_DEFAULT=	MDB SYNCPROV DYNAMIC_BACKENDS

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
AUDITLOG_DESC=		With Audit Logging overlay
COLLECT_DESC=		With Collect overy Services overlay
CONSTRAINT_DESC=	With Attribute Constraint overlay
DDS_DESC=		With Dynamic Directory Services overlay
DEREF_DESC=		With Dereference overlay
DYNGROUP_DESC=		With Dynamic Group overlay
DYNLIST_DESC=		With Dynamic List overlay
MEMBEROF_DESC=		With Reverse Group Membership overlay
PPOLICY_DESC=		With Password Policy overlay
PROXYCACHE_DESC=	With Proxy Cache overlay
REFINT_DESC=		With Referential Integrity overlay
RETCODE_DESC=		With Return Code testing overlay
RWM_DESC=		With Rewrite/Remap overlay
SASL_DESC=		With (Cyrus) SASL2 support
SEQMOD_DESC=		With Sequential Modify overlay
SSSVLV_DESC=		With ServerSideSort/VLV overlay
SYNCPROV_DESC=		With Syncrepl Provider overlay
TRANSLUCENT_DESC=	With Translucent Proxy overlay
UNIQUE_DESC=		With attribute Uniqueness overlay
VALSORT_DESC=		With Value Sorting overlay
SMBPWD_DESC=		With Samba Password hashes overlay
SHA2_DESC=		With SHA2 Password hashes overlay
LMPASSWD_DESC=		With LM hash password support (DEPRECATED)
DYNAMIC_BACKENDS_DESC=	Build dynamic backends
OUTLOOK_DESC=		Force caseIgnoreOrderingMatch on name attribute (experimental)
LASTBIND_DESC=		With lastbind overlay
.endif

.if defined(CLIENT_ONLY)
OPENLDAP_PORTREVISION=	${PORTREVISION_CLIENT}
OPENLDAP_PKGFILESUFX=	.client
.else
OPENLDAP_PORTREVISION=	${PORTREVISION_SERVER}
OPENLDAP_PKGFILESUFX=
.endif

CONFIGURE_SED=		-e 's,uuid/uuid.h,xxuuid/uuid.h,g'

.include <bsd.port.options.mk>

.if defined(CLIENT_ONLY)
PORTDOCS=		CHANGES drafts rfc

.if ${CLIENT_ONLY} == sasl
PORT_OPTIONS+=	SASL
.endif
.if defined(USE_OPENLDAP)
BROKEN=			you have USE_OPENLDAP variable defined either in environment or in make(1) arguments; please undefine and try again
.endif
.else
USE_OPENLDAP=		yes
WANT_OPENLDAP_VER=	24

.if ${PORT_OPTIONS:MGSSAPI} && empty(PORT_OPTIONS:MSASL)
PORT_OPTIONS+=	SASL
.endif

.if ${PORT_OPTIONS:MSASL}
WANT_OPENLDAP_SASL=	yes
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-client-2.*
PKGNAMESUFFIX=		-sasl-server
.if ${PORT_OPTIONS:MGSSAPI}
RUN_DEPENDS+=		cyrus-sasl-gssapi>0:security/cyrus-sasl2-gssapi
.endif
.else
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-sasl-client-2.*
.endif

.endif

DESCR=			${PKGDIR}/pkg-descr${OPENLDAP_PKGFILESUFX}
PLIST=			${PKGDIR}/pkg-plist${OPENLDAP_PKGFILESUFX}

SCHEMATA=		collective corba core cosine duaconf dyngroup \
			inetorgperson java misc \
			nis openldap pmi ppolicy

LDAP_RUN_DIR?=		/var/run/openldap
LOCALSTATEDIR?=		/var/db
DATABASEDIR?=		${LOCALSTATEDIR}/openldap-data

SUB_LIST+=		LDAP_RUN_DIR=${LDAP_RUN_DIR} \
			LDAP_USER=${LDAP_USER} \
			LDAP_GROUP=${LDAP_GROUP} \
			DATABASEDIR=${DATABASEDIR} \
			PKGNAME=${PKGNAME}

CONFIGURE_ARGS=		--with-threads=posix \
			--with-tls=openssl \
			--disable-dependency-tracking \
			--enable-dynamic

# XXX FreeBSD does not implement O_DSYNC and fdatasync at this time.
CFLAGS+=		-DMDB_DSYNC=O_SYNC -Dfdatasync=fsync

.if ${PORT_OPTIONS:MSASL}
LIB_DEPENDS+=		libsasl2.so:security/cyrus-sasl2
CONFIGURE_ARGS+=	--with-cyrus-sasl
.else
CONFIGURE_ARGS+=	--without-cyrus-sasl
.endif

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

.if ${PORT_OPTIONS:MDYNAMIC_BACKENDS} || ${PORT_OPTIONS:MSLAPI}
LIB_DEPENDS+=		libltdl.so:devel/libltdl
CONFIGURE_ARGS+=	--enable-modules
PLIST_SUB+=		MODULES=""
.else
PLIST_SUB+=		MODULES="@comment "
.endif

SED_MODULES=		-e 's/\(moduleload[ 	]*back_[a-z]*\)\.la/\1/'

.if ${PORT_OPTIONS:MDYNAMIC_BACKENDS}
BACKEND_ENABLE=		"mod"
BACKEND_PLIST=		""
SED_MODULES+=		-e 's/\# *\(modulepath\)/\1/' \
			-e 's/\# *\(moduleload[ 	]*back_bdb\)/\1/'
.else
BACKEND_ENABLE=		"yes"
BACKEND_PLIST=		"@comment "
.endif

OVERLAY_ENABLE=		yes

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--enable-crypt \
			--enable-ldap=${BACKEND_ENABLE} \
			--enable-meta=${BACKEND_ENABLE} \
			--enable-rewrite \
			--enable-null=${BACKEND_ENABLE} \
			--enable-monitor=${BACKEND_ENABLE}

PLIST_SUB+=		BACKEND=${BACKEND_PLIST}

.if ${PORT_OPTIONS:MACCESSLOG}
CONFIGURE_ARGS+=	--enable-accesslog=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MAUDITLOG}
CONFIGURE_ARGS+=	--enable-auditlog=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MCOLLECT}
CONFIGURE_ARGS+=	--enable-collect=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MCONSTRAINT}
CONFIGURE_ARGS+=	--enable-constraint=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MDDS}
CONFIGURE_ARGS+=	--enable-dds=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug=yes
.endif

MAKE_ENV+=		STRIP=${STRIP}

.if ${PORT_OPTIONS:MDEREF}
CONFIGURE_ARGS+=	--enable-deref=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MDYNGROUP}
CONFIGURE_ARGS+=	--enable-dyngroup=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MDYNLIST}
CONFIGURE_ARGS+=	--enable-dynlist=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MLMPASSWD}
CONFIGURE_ARGS+=	--enable-lmpasswd
.endif

.if ${PORT_OPTIONS:MMEMBEROF}
CONFIGURE_ARGS+=	--enable-memberof=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MPPOLICY}
CONFIGURE_ARGS+=	--enable-ppolicy=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MPROXYCACHE}
CONFIGURE_ARGS+=	--enable-proxycache=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MREFINT}
CONFIGURE_ARGS+=	--enable-refint=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MRETCODE}
CONFIGURE_ARGS+=	--enable-retcode=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MRWM}
CONFIGURE_ARGS+=	--enable-rwm=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MSEQMOD}
CONFIGURE_ARGS+=	--enable-seqmod=${OVERLAY_ENABLE}
.else
CONFIGURE_ARGS+=	--disable-seqmod
.endif

.if ${PORT_OPTIONS:MSSSVLV}
CONFIGURE_ARGS+=	--enable-sssvlv=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MSYNCPROV}
CONFIGURE_ARGS+=	--enable-syncprov=${OVERLAY_ENABLE}
.else
CONFIGURE_ARGS+=	--disable-syncprov
.endif

.if ${PORT_OPTIONS:MTRANSLUCENT}
CONFIGURE_ARGS+=	--enable-translucent=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MUNIQUE}
CONFIGURE_ARGS+=	--enable-unique=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MVALSORT}
CONFIGURE_ARGS+=	--enable-valsort=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MACI}
CONFIGURE_ARGS+=	--enable-aci
.endif

.if ${PORT_OPTIONS:MDYNACL}
CONFIGURE_ARGS+=	--enable-dynacl
.endif

.if ${PORT_OPTIONS:MLASTBIND}
CONFIGURE_ARGS+=	--enable-lastbind
.endif

.if !${PORT_OPTIONS:MBDB}
CONFIGURE_ARGS+=	--disable-bdb \
			--disable-hdb
PLIST_SUB+=		BACK_BDB="@comment " \
			BACK_HDB="@comment "
.else

USES+=			bdb
INVALID_BDB_VER=	6

CONFIGURE_ARGS+=	--enable-bdb=${BACKEND_ENABLE} \
			--enable-hdb=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_BDB=${BACKEND_PLIST} \
			BACK_HDB=${BACKEND_PLIST}

CPPFLAGS+=		-I${BDB_INCLUDE_DIR}
LDFLAGS+=		-L${BDB_LIB_DIR}
CONFIGURE_SED+=		-e 's,ol_DB_LIB=$$,&-l${BDB_LIB_NAME:R},' \
			-e 's,(ol_cv_lib_db=)yes$$,\1-l${BDB_LIB_NAME:R},'
.endif

.if ${PORT_OPTIONS:MDNSSRV}
CONFIGURE_ARGS+=	--enable-dnssrv=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_DNSSRV=${BACKEND_PLIST}
.else
PLIST_SUB+=		BACK_DNSSRV="@comment "
.endif

.if ${PORT_OPTIONS:MMDB}
CONFIGURE_ARGS+=	--enable-mdb=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_MDB=${BACKEND_PLIST}
.else
PLIST_SUB+=		BACK_MDB="@comment "
.endif

.if ${PORT_OPTIONS:MPASSWD}
CONFIGURE_ARGS+=	--enable-passwd=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_PASSWD=${BACKEND_PLIST}
.else
PLIST_SUB+=		BACK_PASSWD="@comment "
.endif

.if ${PORT_OPTIONS:MRELAY}
CONFIGURE_ARGS+=	--enable-relay=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_RELAY=${BACKEND_PLIST}
.else
PLIST_SUB+=		BACK_RELAY="@comment "
.endif

.if ${PORT_OPTIONS:MSHELL}
CONFIGURE_ARGS+=	--without-threads --enable-shell=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_SHELL=${BACKEND_PLIST}
.else
PLIST_SUB+=		BACK_SHELL="@comment "
WANT_OPENLDAP_THREADS=	yes
.endif

.if ${PORT_OPTIONS:MSOCK}
CONFIGURE_ARGS+=	--enable-sock=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_SOCK=${BACKEND_PLIST}
.else
PLIST_SUB+=		BACK_SOCK="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=			perl5
CONFIGURE_ARGS+=	--enable-perl=${BACKEND_ENABLE}
CONFIGURE_ENV+=		PERLBIN="${PERL}"
PLIST_SUB+=		BACK_PERL=${BACKEND_PLIST}
.else
PLIST_SUB+=		BACK_PERL="@comment "
.endif

.if ${PORT_OPTIONS:MSASL}
CONFIGURE_ARGS+=	--enable-spasswd
.endif

.if ${PORT_OPTIONS:MODBC}
CONFIGURE_ARGS+=	--enable-sql=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_SQL=${BACKEND_PLIST}
LIB_DEPENDS+=		libodbc.so:databases/unixODBC
LDFLAGS+=		-L${LOCALBASE}/lib
.else
PLIST_SUB+=		BACK_SQL="@comment "
.endif

.if ${PORT_OPTIONS:MSMBPWD}
PLIST_SUB+=		SMBPWD=""
.else
PLIST_SUB+=		SMBPWD="@comment "
.endif

.if ${PORT_OPTIONS:MSHA2}
PLIST_SUB+=		SHA2=""
.else
PLIST_SUB+=		SHA2="@comment "
.endif

.if ${PORT_OPTIONS:MLASTBIND}
PLIST_SUB+=		LASTBIND=""
.else
PLIST_SUB+=		LASTBIND="@comment "
.endif

.if ${PORT_OPTIONS:MRLOOKUPS}
CONFIGURE_ARGS+=	--enable-rlookups
PLIST_SUB+=		RLOOKUPS=""
.else
PLIST_SUB+=		RLOOKUPS="@comment "
.endif

.if ${PORT_OPTIONS:MSLAPI}
CONFIGURE_ARGS+=	--enable-slapi
PLIST_SUB+=		SLAPI=""
USE_LDCONFIG=		yes
.else
PLIST_SUB+=		SLAPI="@comment "
.endif

.if ${PORT_OPTIONS:MSLP}
CONFIGURE_ARGS+=	--enable-slp
LIB_DEPENDS+=		libslp.so:net/openslp
.endif

# Include tcp-wrapper support
.if ${PORT_OPTIONS:MTCP_WRAPPERS}
CONFIGURE_ARGS+=	--enable-wrappers
.endif

# Force using caseIgnoreOrderingMatch on 'name' attribute.
# This may be a violation of RFC 4519 2.18 definition.
# See http://www.openldap.org/lists/openldap-technical/201211/msg00175.html
.if ${PORT_OPTIONS:MOUTLOOK}
EXTRA_PATCHES+=		${FILESDIR}/extrapatch-outlook-servers__slapd__schema_prep.c
.endif

# end of client/server specific configuration
.endif

.if defined(WITH_CLDAP)
CPPFLAGS+=		-DLDAP_CONNECTIONLESS
.endif

CPPFLAGS+=		-I${LOCALBASE}/include
LIBS+=			-L${LOCALBASE}/lib

.if defined(CLIENT_ONLY)
.else
SUB_LIST+=		RC_DIR=${PREFIX} \
			LDAP_RUN_DIR=${LDAP_RUN_DIR} \
			DATABASEDIR=${DATABASEDIR}
.endif

PLIST_SUB+=		${SUB_LIST}
PLIST_SUB+=		SHLIB_MAJOR=${OPENLDAP_SHLIB_MAJOR}
PLIST_SUB+=		SHLIB_MINOR=${OPENLDAP_SHLIB_MINOR}
PLIST_SUB+=		OPENLDAP_MAJOR=${OPENLDAP_MAJOR}

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mopenssl-devel}
BROKEN=		Does not build with openssl-devel
.endif

.if !${PORT_OPTIONS:MFETCH}
CONFIGURE_ARGS+=	--without-fetch
.else
. if defined(OPENSSL_INSTALLED) && ${OPENSSL_INSTALLED} != "" || ${SSL_DEFAULT} != base
BROKEN=	using OpenSSL from ports and OPTION FETCH together is not supported
. endif
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%LOCALSTATEDIR%/run/|${LDAP_RUN_DIR}/|g' \
		${SED_MODULES} ${WRKSRC}/servers/slapd/slapd.conf
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

.if !defined(CLIENT_ONLY)
test: build
	@(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)

post-build:
	@${DO_NADA}
.if ${PORT_OPTIONS:MSMBPWD}
	@(cd ${BUILD_WRKSRC}/contrib/slapd-modules/smbk5pwd && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} DEFS="-DDO_SAMBA" prefix="${PREFIX}" all)
.endif
.if ${PORT_OPTIONS:MSHA2}
	@(cd ${BUILD_WRKSRC}/contrib/slapd-modules/passwd/sha2 && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} prefix="${PREFIX}" all)
.endif
.if ${PORT_OPTIONS:MLASTBIND}
	@(cd ${BUILD_WRKSRC}/contrib/slapd-modules/lastbind && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} prefix="${PREFIX}" all)
.endif
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

	for library in lber ldap ldap_r; do \
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib$${library}-${OPENLDAP_MAJOR}.so.${OPENLDAP_SHLIB_MAJOR}; \
	done
.else
	${MKDIR} ${STAGEDIR}${LDAP_RUN_DIR}
.if ${PORT_OPTIONS:MSMBPWD}
	(cd ${WRKSRC}/contrib/slapd-modules/smbk5pwd && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} prefix="${PREFIX}" install)
	${RM} ${STAGEDIR}${PREFIX}/libexec/openldap/smbk5pwd.a
.endif
.if ${PORT_OPTIONS:MSHA2}
	(cd ${WRKSRC}/contrib/slapd-modules/passwd/sha2 && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} prefix="${PREFIX}" install)
	${RM} ${STAGEDIR}${PREFIX}/libexec/openldap/pw-sha2.a
.endif
.if ${PORT_OPTIONS:MLASTBIND}
	(cd ${WRKSRC}/contrib/slapd-modules/lastbind && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} prefix="${PREFIX}" install)
	${RM} ${STAGEDIR}${PREFIX}/libexec/openldap/lastbind.a
.endif
.if ${PORT_OPTIONS:MDYNAMIC_BACKENDS} || ${PORT_OPTIONS:MSMBPWD} || ${PORT_OPTIONS:MSHA2}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/openldap/*.so
.endif
.if ${PORT_OPTIONS:MDYNAMIC_BACKENDS} || ${PORT_OPTIONS:MSLAPI}
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/openldap
.endif
.endif # defined(CLIENT_ONLY)

.include <bsd.port.post.mk>
