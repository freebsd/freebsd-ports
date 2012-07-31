# New ports collection makefile for:	openldap24-server
# Date created:				19 May 2006
# Whom:					Xin LI <delphij@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		openldap
DISTVERSION=		2.4.32
PORTREVISION=		${OPENLDAP_PORTREVISION}
CATEGORIES=		net databases
MASTER_SITES=		ftp://ftp.OpenLDAP.org/pub/OpenLDAP/%SUBDIR%/ \
			ftp://gd.tuwien.ac.at/infosys/network/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.ntua.gr/mirror/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.dti.ad.jp/pub/net/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.u-aizu.ac.jp/pub/net/openldap/%SUBDIR%/ \
			ftp://ftp.nl.uu.net/pub/unix/db/openldap/%SUBDIR%/ \
			ftp://sunsite.cnlab-switch.ch/mirror/OpenLDAP/%SUBDIR%/
MASTER_SITE_SUBDIR=	openldap-release
PKGNAMESUFFIX?=		-server
EXTRACT_SUFX=		.tgz

MAINTAINER=		delphij@FreeBSD.org
COMMENT?=		Open source LDAP server implementation

LICENSE=		OPENLDAP
LICENSE_NAME=		OpenLDAP Public License
LICENSE_FILE=		${WRKSRC}/LICENSE
LICENSE_PERMS=		${_LICENSE_PERMS_DEFAULT}

LATEST_LINK?=		${PKGNAMEPREFIX}openldap24${PKGNAMESUFFIX}
USE_OPENSSL=		yes
MAKE_JOBS_SAFE=		yes
USE_AUTOTOOLS=		libtool
.if !defined(CLIENT_ONLY)
USERS=			ldap
GROUPS=			ldap
.endif

WANT_OPENLDAP_VER?=	24
.if ${WANT_OPENLDAP_VER} != 24
BROKEN=			incompatible OpenLDAP version: ${WANT_OPENLDAP_VER}
.endif

PORTREVISION_CLIENT=	1
PORTREVISION_SERVER=	0
OPENLDAP_SHLIB_MAJOR=	8

OPTIONS_DEFINE=	SASL FETCH

SASL_DESC=	With (Cyrus) SASL2 support
FETCH_DESC=	Enable fetch(3) support

.if !defined(CLIENT_ONLY)
OPTIONS_DEFINE+=	DYNACL ACI BDB DNSSRV MDB PASSWD PERL RELAY SHELL
OPTIONS_DEFINE+=	SOCK ODBC RLOOKUPS SLP SLAPI TCP_WRAPPERS
OPTIONS_DEFINE+=	ACCESSLOG AUDITLOG COLLECT CONSTRAINT DDS
OPTIONS_DEFINE+=	DEREF DYNGROUP DYNLIST MEMBEROF PPOLICY PROXYCACHE
OPTIONS_DEFINE+=	REFINT RETCODE RWM SEQMOD SSSVLV SYNCPROV TRANSLUCENT
OPTIONS_DEFINE+=	UNIQUE VALSORT SMBPWD DYNAMIC_BACKENDS

OPTIONS_DEFAULT=	BDB TCP_WRAPPERS SEQMOD SYNCPROV

DYNACL_DESC=		Run-time loadable ACL (experimental)
ACI_DESC=		Per-object ACI (experimental)
BDB_DESC=		With BerkeleyDB backend
DNSSRV_DESC=		With Dnssrv backend
MDB_DESC=		With Memory-Mapped DB backend
PASSWD_DESC=		With Passwd backend
PERL_DESC=		With Perl backend
RELAY_DESC=		With Relay backend
SHELL_DESC=		With Shell backend (disables threading)
SOCK_DESC=		With Sock backend
ODBC_DESC=		With SQL backend
RLOOKUPS_DESC=		With reverse lookups of client hostnames
SLP_DESC=		With SLPv2 (RFC 2608) support
SLAPI_DESC=		With Netscape SLAPI plugin API
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
SEQMOD_DESC=		With Sequential Modify overlay
SSSVLV_DESC=		With ServerSideSort/VLV overlay
SYNCPROV_DESC=		With Syncrepl Provider overlay
TRANSLUCENT_DESC=	With Translucent Proxy overlay
UNIQUE_DESC=		With attribute Uniqueness overlay
VALSORT_DESC=		With Value Sorting overlay
SMBPWD_DESC=		With Samba Password hashes overlay
DYNAMIC_BACKENDS_DESC=	Build dynamic backends
.endif

.if defined(CLIENT_ONLY)
OPENLDAP_PORTREVISION=	${PORTREVISION_CLIENT}
OPENLDAP_PKGFILESUFX=	.client
.else
OPENLDAP_PORTREVISION=	${PORTREVISION_SERVER}
OPENLDAP_PKGFILESUFX=
.endif

CONFIGURE_SED=		-e 's,-kthread,${PTHREAD_LIBS},g' -e 's,uuid/uuid.h,xxuuid/uuid.h,g'

.include <bsd.port.pre.mk>

.if defined(CLIENT_ONLY)
.if ${PORT_OPTIONS:MSASL}
PKGNAMESUFFIX=		-sasl-client
COMMENT=		Open source LDAP client implementation with SASL2 support
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-client-2.* \
			${PKGNAMEPREFIX}${PORTNAME}-sasl-client-2.[!4].*
.else
PKGNAMESUFFIX=		-client
COMMENT=		Open source LDAP client implementation
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-client-2.[!4].* \
			${PKGNAMEPREFIX}${PORTNAME}-sasl-client-2.*
.endif

PORTDOCS=		CHANGES drafts rfc

.if defined(USE_OPENLDAP)
BROKEN=			You have `USE_OPENLDAP' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif
.else
USE_OPENLDAP=		yes
WANT_OPENLDAP_VER=	24

.if ${PORT_OPTIONS:MSASL}
WANT_OPENLDAP_SASL=	yes
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-client-2.*
PKGNAMESUFFIX=		-sasl-server
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
			DATABASEDIR=${DATABASEDIR} \
			PKGNAME=${PKGNAME}

CONFIGURE_ARGS=		--with-threads=posix \
			--with-tls=openssl \
			--disable-dependency-tracking \
			--enable-dynamic

# XXX FreeBSD does not implement O_DSYNC and fdatasync at this time.
CFLAGS+=		-DMDB_DSYNC=O_SYNC -Dfdatasync=fsync

.if !${PORT_OPTIONS:MFETCH}
CONFIGURE_ARGS+=	--without-fetch
.endif

.if ${PORT_OPTIONS:MSASL}
LIB_DEPENDS+=		sasl2.2:${PORTSDIR}/security/cyrus-sasl2
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
USE_RC_SUBR=		slapd.sh

EXTRA_PATCHES+=		${FILESDIR}/extrapatch-Makefile.in

.if ${PORT_OPTIONS:MMODULES} || ${PORT_OPTIONS:MDYNAMIC_BACKENDS} || ${PORT_OPTIONS:MSLAPI}
USE_AUTOTOOLS+=		libltdl
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
			--enable-lmpasswd \
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

.if ${PORT_OPTIONS:MDEREF}
CONFIGURE_ARGS+=	--enable-deref=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MDYNGROUP}
CONFIGURE_ARGS+=	--enable-dyngroup=${OVERLAY_ENABLE}
.endif

.if ${PORT_OPTIONS:MDYNLIST}
CONFIGURE_ARGS+=	--enable-dynlist=${OVERLAY_ENABLE}
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
CONFIGURE_ARGS+=	--disble-seqmod
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

.if !${PORT_OPTIONS:MBDB}
CONFIGURE_ARGS+=	--disable-bdb \
			--disable-hdb
PLIST_SUB+=		BACK_BDB="@comment " \
			BACK_HDB="@comment "
.else

WITH_BDB_VER?=		46
INVALID_BDB_VER=	42
USE_BDB=		yes

# XXX Can BDB 5.x use XY instead of X as version?
.if ${WITH_BDB_VER} >= 43 || ${WITH_BDB_VER} == 5
CONFIGURE_ARGS+=	--enable-bdb=${BACKEND_ENABLE} \
			--enable-hdb=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_BDB=${BACKEND_PLIST} \
			BACK_HDB=${BACKEND_PLIST}
.elif ${WITH_BDB_VER} >= 4
CONFIGURE_ARGS+=	--disable-bdb \
			--enable-hdb=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_BDB="@comment " \
			BACK_HDB=${BACKEND_PLIST}
.elif ${WITH_BDB_VER} == 3
CONFIGURE_ARGS+=	--disable-bdb \
			--disable-hdb
PLIST_SUB+=		BACK_BDB="@comment " \
			BACK_HDB="@comment "
.endif

CPPFLAGS+=		-I${BDB_INCLUDE_DIR}
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
USE_PERL5=		yes
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
WITH_ODBC_TYPE?=	iODBC
.if ${WITH_ODBC_TYPE:L} == iodbc
LIB_DEPENDS+=		iodbc.3:${PORTSDIR}/databases/libiodbc
.elif ${WITH_ODBC_TYPE:L} == unixodbc
LIB_DEPENDS+=		odbc.2:${PORTSDIR}/databases/unixODBC
.else
BROKEN=			choose either iODBC or unixODBC for WITH_ODBC_TYPE
.endif
.else
PLIST_SUB+=		BACK_SQL="@comment "
.endif

.if ${PORT_OPTIONS:MSMBPWD}
PLIST_SUB+=		SMBPWD=""
.else
PLIST_SUB+=		SMBPWD="@comment "
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
LIB_DEPENDS+=		slp.1:${PORTSDIR}/net/openslp
.endif

# Include tcp-wrapper support
.if !defined(WITHOUT_TCP_WRAPPERS) && exists(/usr/include/tcpd.h)
CONFIGURE_ARGS+=	--enable-wrappers
.endif

# end of client/server specific configuration
.endif

.if defined(WITH_CLDAP)
CPPFLAGS+=		-DLDAP_CONNECTIONLESS
.endif

CPPFLAGS+=		${PTHREAD_CFLAGS} \
			-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
#LIBS+=			${PTHREAD_LIBS}

CONFIGURE_ENV+=		LIBS="${LIBS}"

.if defined(CLIENT_ONLY)
.include "${FILESDIR}/manpages"
.else
SUB_LIST+=		RC_DIR=${PREFIX} \
			LDAP_RUN_DIR=${LDAP_RUN_DIR} \
			DATABASEDIR=${DATABASEDIR}
.endif

PLIST_SUB+=		${SUB_LIST}
PLIST_SUB+=		SHLIB_MAJOR=${OPENLDAP_SHLIB_MAJOR}

post-patch:
	@${REINPLACE_CMD} -e 's,%LOCALSTATEDIR%/run/,${LDAP_RUN_DIR}/,g' \
		${SED_MODULES} ${WRKSRC}/servers/slapd/slapd.conf
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
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

.if ${PORT_OPTIONS:MSMBPWD}
post-build:
	@cd ${BUILD_WRKSRC}/contrib/slapd-modules/smbk5pwd; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} DEFS="-DDO_SAMBA" all
.endif
.endif

pre-su-install:
	@if [ -f ${PKGINSTALL} ]; then \
		${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL; \
	fi
.if ${PORT_OPTIONS:MMODULES} || ${PORT_OPTIONS:MDYNAMIC_BACKENDS} || ${PORT_OPTIONS:MSLAPI}
	@${MKDIR} ${PREFIX}/libexec/openldap
.endif

post-install:
.if defined(CLIENT_ONLY)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}
	@for dir in drafts rfc; do \
		${MKDIR} ${DOCSDIR}/$${dir}; \
		${INSTALL_DATA} ${WRKSRC}/doc/$${dir}/* ${DOCSDIR}/$${dir}; \
	done
.endif
.else
	@${MKDIR} ${LDAP_RUN_DIR}
	@for schema in ${SCHEMATA}; do \
		${ECHO_CMD} "@unexec if cmp -s %D/etc/openldap/schema/$${schema}.schema" \
			"%D/etc/openldap/schema/$${schema}.schema.default; then" \
			"rm -f %D/etc/openldap/schema/$${schema}.schema; fi"; \
		${ECHO_CMD} "etc/openldap/schema/$${schema}.schema.default"; \
		${ECHO_CMD} "@exec [ -f %B/$${schema}.schema ] || ${CP} %B/%f %B/$${schema}.schema"; \
	done >>${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/etc/openldap/schema 2>/dev/null || true" >>${TMPPLIST}
	@${ECHO_CMD} "@unexec ${RMDIR} %D/etc/openldap 2>/dev/null || true" >>${TMPPLIST}
.if ${PORT_OPTIONS:MSMBPWD}
	@${INSTALL_DATA} ${WRKSRC}/contrib/slapd-modules/smbk5pwd/smbk5pwd.la \
		${PREFIX}/libexec/openldap/
	@${INSTALL_PROGRAM} ${WRKSRC}/contrib/slapd-modules/smbk5pwd/.libs/smbk5pwd.so.0 \
		${PREFIX}/libexec/openldap/
	@${LN} -s smbk5pwd.so.0 ${PREFIX}/libexec/openldap/smbk5pwd.so
.endif
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
