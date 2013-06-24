# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=		openldap
DISTVERSION=		2.3.43
PORTREVISION=		2
PORTREVISION=		${OPENLDAP_PORTREVISION}
CATEGORIES=		net databases
MASTER_SITES=		ftp://ftp.OpenLDAP.org/pub/OpenLDAP/%SUBDIR%/ \
			ftp://gd.tuwien.ac.at/infosys/network/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.matrix.com.br/pub/openldap/%SUBDIR%/ \
			ftp://ftp.ucr.ac.cr/pub/Unix/openldap/%SUBDIR%/ \
			ftp://ftp.ntua.gr/mirror/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.dti.ad.jp/pub/net/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.u-aizu.ac.jp/pub/net/openldap/%SUBDIR%/ \
			ftp://ftp.holywar.net/pub/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.nl.uu.net/pub/unix/db/openldap/%SUBDIR%/ \
			ftp://ftp.linux.pt/pub/mirrors/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.rediris.es/mirror/OpenLDAP/%SUBDIR%/ \
			ftp://sunsite.cnlab-switch.ch/mirror/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.plig.org/pub/OpenLDAP/%SUBDIR%/ \
			http://www.openldap.org/software/download/OpenLDAP/%SUBDIR%/
MASTER_SITE_SUBDIR=	openldap-release
PKGNAMESUFFIX?=		-server
EXTRACT_SUFX=		.tgz

MAINTAINER=		delphij@FreeBSD.org
COMMENT?=		Open source LDAP server implementation

UNIQUENAME?=		${PKGNAMEPREFIX}openldap23
LATEST_LINK?=		${UNIQUENAME}${PKGNAMESUFFIX}
USE_OPENSSL=		yes

DEPRECATED=		Unmaintained by upstream
EXPIRATION_DATE=	2013-07-01

WANT_OPENLDAP_VER?=	23
.if ${WANT_OPENLDAP_VER} != 23
BROKEN=			incompatible OpenLDAP version: ${WANT_OPENLDAP_VER}
.endif

PORTREVISION_CLIENT=	1
PORTREVISION_SERVER=	0

.if !defined(CLIENT_ONLY)
OPTIONS_DEFINE=	SASL PERL SHELL ODBC SLP SLAPI TCP_WRAPPERS BDB ACCESSLOG DENYOP \
		DYNGROUP DYNLIST LASTMOD PPOLICY PROXYCACHE REFINT RETCODE RWM \
		SYNCPROV TRANSLUCENT UNIQUE VALSORT ACI DYNAMIC_BACKENDS SLURPD
OPTIONS_DEFAULT=	TCP_WRAPPERS BDB DYNAMIC_BACKENDS SLURPD
SASL_DESC=		With (Cyrus) SASL2 support
PERL_DESC=		With Perl backend
SHELL_DESC=		With Shell backend (disables threading)
ODBC_DESC=		With SQL backend
SLP_DESC=		With SLPv2 (RFC 2608) support
SLAPI_DESC=		With Netscape SLAPI plugin API
TCP_WRAPPERS_DESC=	With tcp wrapper support
BDB_DESC=		With BerkeleyDB support
ACCESSLOG_DESC=		With In-Directory Access Logging overlay
AUDITLOG_DESC=		With Audit Logging overlay
DENYOP_DESC=		With Deny Operation overlay
DYNGROUP_DESC=		With Dynamic Group overlay
DYNLIST_DESC=		With Dynamic List overlay
LASTMOD_DESC=		With Last Modification overlay
PPOLICY_DESC=		With Password Policy overlay
PROXYCACHE_DESC=	With Proxy Cache overlay
REFINT_DESC=		With Referential Integrity overlay
RETCODE_DESC=		With Return Code testing overlay
RWM_DESC=		With Rewrite/Remap overlay
SYNCPROV_DESC=		With Syncrepl Provider overlay
TRANSLUCENT_DESC=	With Translucent Proxy overlay
UNIQUE_DESC=		With attribute Uniqueness overlay
VALSORT_DESC=		With Value Sorting overlay
ACI_DESC=		With per-object ACIs (experimental)
DYNAMIC_BACKENDS_DESC=	Build dynamic backends
SLURPD_DESC=		Build slurpd replication daemon
.endif

.if defined(CLIENT_ONLY)
OPENLDAP_PORTREVISION=	${PORTREVISION_CLIENT}
OPENLDAP_PKGFILESUFX=	.client
.else
OPENLDAP_PORTREVISION=	${PORTREVISION_SERVER}
OPENLDAP_PKGFILESUFX=
.endif

CONFIGURE_SED=		-e 's,-kthread,${PTHREAD_LIBS},g'

.include <bsd.port.pre.mk>

.if defined(CLIENT_ONLY)
.if ${PORT_OPTIONS:MSASL}
PKGNAMESUFFIX=		-sasl-client
COMMENT=		Open source LDAP client implementation with SASL2 support
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-client-2.* \
			${PKGNAMEPREFIX}${PORTNAME}-sasl-client-2.[!3].*
.else
PKGNAMESUFFIX=		-client
COMMENT=		Open source LDAP client implementation
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-client-2.[!3].* \
			${PKGNAMEPREFIX}${PORTNAME}-sasl-client-2.*
.endif

PORTDOCS=		CHANGES drafts rfc

.if defined(USE_OPENLDAP)
BROKEN=			You have `USE_OPENLDAP' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif
.else
USE_OPENLDAP=		yes
WANT_OPENLDAP_VER=	23

.if defined(WITH_SASL) && !defined(WITHOUT_SASL)
WANT_OPENLDAP_SASL=	yes
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-client-2.*
PKGNAMESUFFIX=		-sasl-server
.else
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-sasl-client-2.*
.endif

.endif

USE_AUTOTOOLS=		libtool

DESCR=			${PKGDIR}/pkg-descr${OPENLDAP_PKGFILESUFX}
PLIST=			${PKGDIR}/pkg-plist${OPENLDAP_PKGFILESUFX}

SCHEMATA=		corba core cosine dyngroup \
			inetorgperson java misc \
			nis openldap ppolicy

LDAP_RUN_DIR?=		/var/run/openldap
LOCALSTATEDIR?=		/var/db
DATABASEDIR?=		${LOCALSTATEDIR}/openldap-data
SLURPDIR?=		${LOCALSTATEDIR}/openldap-slurp

SUB_LIST+=		LDAP_RUN_DIR=${LDAP_RUN_DIR} \
			DATABASEDIR=${DATABASEDIR} \
			SLURPDIR=${SLURPDIR} \
			PKGNAME=${PKGNAME}

CONFIGURE_ARGS=		--with-threads=posix \
			--with-tls=openssl \
			--enable-dynamic

.if ${PORT_OPTIONS:MSASL}
LIB_DEPENDS+=		sasl2:${PORTSDIR}/security/cyrus-sasl2
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
			--disable-glue \
			--disable-syncprov

USE_LDCONFIG=		yes
SUB_FILES+=		pkg-message.client
PKGMESSAGE=		${WRKSRC}/pkg-message.client

.else
# server specific configuration

USE_LDCONFIG=		${PREFIX}/libexec/openldap
SUB_FILES+=		pkg-deinstall pkg-message pkg-install
USE_RC_SUBR=		slapd ${SLURPDSH}

EXTRA_PATCHES+=		${FILESDIR}/extrapatch-Makefile.in

.if defined(WITH_MODULES) || ${PORT_OPTIONS:MDYNAMIC_BACKENDS} || ${PORT_OPTIONS:MSLAPI}
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

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--enable-ldbm=${BACKEND_ENABLE} \
			--enable-crypt \
			--enable-lmpasswd \
			--enable-ldap=${BACKEND_ENABLE} \
			--enable-meta=${BACKEND_ENABLE} \
			--enable-rewrite \
			--enable-null=${BACKEND_ENABLE} \
			--enable-monitor=${BACKEND_ENABLE}

PLIST_SUB+=		BACKEND=${BACKEND_PLIST}

.if ${PORT_OPTIONS:MACCESSLOG}
CONFIGURE_ARGS+=	--enable-accesslog
.endif

.if ${PORT_OPTIONS:MAUDITLOG}
CONFIGURE_ARGS+=	--enable-auditlog
.endif

.if ${PORT_OPTIONS:MDENYOP}
CONFIGURE_ARGS+=	--enable-denyop
.endif

.if ${PORT_OPTIONS:MDYNGROUP}
CONFIGURE_ARGS+=	--enable-dyngroup
.endif

.if ${PORT_OPTIONS:MDYNLIST}
CONFIGURE_ARGS+=	--enable-dynlist
.endif

.if ${PORT_OPTIONS:MLASTMOD}
CONFIGURE_ARGS+=	--enable-lastmod
.endif

.if ${PORT_OPTIONS:MPPOLICY}
CONFIGURE_ARGS+=	--enable-ppolicy
.endif

.if ${PORT_OPTIONS:MPROXYCACHE}
CONFIGURE_ARGS+=	--enable-proxycache
.endif

.if ${PORT_OPTIONS:MREFINT}
CONFIGURE_ARGS+=	--enable-refint
.endif

.if ${PORT_OPTIONS:MRETCODE}
CONFIGURE_ARGS+=	--enable-retcode
.endif

.if ${PORT_OPTIONS:MRWM}
CONFIGURE_ARGS+=	--enable-rwm
.endif

.if ${PORT_OPTIONS:MSYNCPROV}
CONFIGURE_ARGS+=	--enable-syncprov
.else
CONFIGURE_ARGS+=	--disable-syncprov
.endif

.if ${PORT_OPTIONS:MTRANSLUCENT}
CONFIGURE_ARGS+=	--enable-translucent
.endif

.if ${PORT_OPTIONS:MUNIQUE}
CONFIGURE_ARGS+=	--enable-unique
.endif

.if ${PORT_OPTIONS:MVALSORT}
CONFIGURE_ARGS+=	--enable-valsort
.endif

.if ${PORT_OPTIONS:MACI}
CONFIGURE_ARGS+=	--enable-aci
.endif

.if ! ${PORT_OPTIONS:MBDB}
CONFIGURE_ARGS+=	--disable-bdb \
			--disable-hdb \
			--enable-ldbm-api=bcompat
PLIST_SUB+=		BACK_BDB="@comment " \
			BACK_HDB="@comment "
.else

WITH_BDB_VER?=		44
INVALID_BDB_VER=	46
USE_BDB=		yes

.if ${WITH_BDB_VER} >= 42
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
CONFIGURE_ARGS+=	--enable-ldbm-api=berkeley
CONFIGURE_SED+=		-e 's,ol_DB_LIB=$$,&-l${BDB_LIB_NAME:R},' \
			-e 's,(ol_cv_lib_db=)yes$$,\1-l${BDB_LIB_NAME:R},'
.endif

.if ${PORT_OPTIONS:MSHELL}
CONFIGURE_ARGS+=	--without-threads --enable-shell=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_SHELL=${BACKEND_PLIST}
.else
PLIST_SUB+=		BACK_SHELL="@comment "
WANT_OPENLDAP_THREADS=	yes
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

.if defined(WITH_IODBC) && defined(WITH_UNIXODBC)
IGNORE=		selected mutually exclusive options: WITH_IODBC and WITH_UNIXODBC
.endif

.if !defined(WITH_IODBC) && !defined(WITH_UNIXODBC)
WITH_IODBC?=	yes
.endif

.if ${PORT_OPTIONS:MODBC}
CONFIGURE_ARGS+=	--enable-sql=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_SQL=${BACKEND_PLIST}
.if defined(WITH_IODBC)
LIB_DEPENDS+=		iodbc.3:${PORTSDIR}/databases/libiodbc
.elif defined(WITH_UNIXODBC)
LIB_DEPENDS+=		odbc.2:${PORTSDIR}/databases/unixODBC
.endif
.else
PLIST_SUB+=		BACK_SQL="@comment "
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

.if defined(WANT_OPENLDAP_THREADS) && !defined(WITHOUT_SLURPD)
SLURPDSH=		slurpd
PLIST_SUB+=		SLURPD=""
.else
PLIST_SUB+=		SLURPD="@comment "
CONFIGURE_ARGS+=	--disable-slurpd
.endif

# Include tcp-wrapper support
.if ${PORT_OPTIONS:MTCP_WRAPPERS} && exists(/usr/include/tcpd.h)
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
.endif

pre-su-install:
	@if [ -f ${PKGINSTALL} ]; then \
		${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL; \
	fi
.if defined(WITH_MODULES) || !defined(WITHOUT_DYNAMIC_BACKENDS) || defined(WITH_SLAPI)
	@${MKDIR} ${PREFIX}/libexec/openldap
.endif

post-install:
.if defined(CLIENT_ONLY)
.if ${PORT_OPTIONS:MDOCS}
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
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
