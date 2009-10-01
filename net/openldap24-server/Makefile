# New ports collection makefile for:	openldap24-server
# Date created:				19 May 2006
# Whom:					Xin LI <delphij@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		openldap
DISTVERSION=		2.4.18
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
			ftp://ftp.plig.org/pub/OpenLDAP/%SUBDIR%/
MASTER_SITE_SUBDIR=	openldap-release
PKGNAMESUFFIX?=		-server
EXTRACT_SUFX=		.tgz

MAINTAINER=		delphij@FreeBSD.org
COMMENT?=		Open source LDAP server implementation

UNIQUENAME?=		${PKGNAMEPREFIX}openldap24
LATEST_LINK?=		${UNIQUENAME}${PKGNAMESUFFIX}
USE_OPENSSL=		yes
MAKE_JOBS_SAFE=		yes

WANT_OPENLDAP_VER?=	24
.if ${WANT_OPENLDAP_VER} != 24
BROKEN=			incompatible OpenLDAP version: ${WANT_OPENLDAP_VER}
.endif

PORTREVISION_CLIENT=	0
PORTREVISION_SERVER=	1

.if !defined(CLIENT_ONLY)
OPTIONS=	SASL "With (Cyrus) SASL2 support" off \
		DYNACL "Run-time loadable ACL (experimental)" off \
		ACI "Per-object ACI (experimental)" off \
		DNSSRV "With Dnssrv backend" off \
		PASSWD "With Passwd backend" off \
		PERL "With Perl backend" off \
		RELAY "With Relay backend" off \
		SHELL "With Shell backend (disables threading)" off \
		SOCK "With Sock backend" off \
		ODBC "With SQL backend" off \
		RLOOKUPS "With reverse lookups of client hostnames" off \
		SLP "With SLPv2 (RFC 2608) support" off \
		SLAPI "With Netscape SLAPI plugin API" off \
		TCP_WRAPPERS "With tcp wrapper support" on \
		BDB "With BerkeleyDB support" on \
		ACCESSLOG "With In-Directory Access Logging overlay" off \
		AUDITLOG "With Audit Logging overlay" off \
		COLLECT "With Collect overy Services overlay" off \
		CONSTRAINT "With Attribute Constraint overlay" off \
		DDS "With Dynamic Directory Services overlay" off \
		DEREF "With Dereference overlay" off \
		DYNGROUP "With Dynamic Group overlay" off \
		DYNLIST "With Dynamic List overlay" off \
		LASTMOD "With Last Modification overlay" off \
		MEMBEROF "With Reverse Group Membership overlay" off \
		PPOLICY "With Password Policy overlay" off \
		PROXYCACHE "With Proxy Cache overlay" off \
		REFINT "With Referential Integrity overlay" off \
		RETCODE "With Return Code testing overlay" off \
		RWM "With Rewrite/Remap overlay" off \
		SEQMOD "Sequential Modify overlay" on \
		SYNCPROV "With Syncrepl Provider overlay" on \
		TRANSLUCENT "With Translucent Proxy overlay" off \
		UNIQUE "With attribute Uniqueness overlay" off \
		VALSORT "With Value Sorting overlay" off \
		SMBPWD "With Samba Password hashes overlay" off \
		DYNAMIC_BACKENDS "Build dynamic backends" on
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
.if defined(WITH_SASL) && !defined(WITHOUT_SASL)
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

.if defined(WITH_SASL) && !defined(WITHOUT_SASL)
WANT_OPENLDAP_SASL=	yes
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-client-2.*
PKGNAMESUFFIX=		-sasl-server
.else
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-sasl-client-2.*
.endif

.endif

USE_AUTOTOOLS=		libtool:22

DESCR=			${PKGDIR}/pkg-descr${OPENLDAP_PKGFILESUFX}
PLIST=			${PKGDIR}/pkg-plist${OPENLDAP_PKGFILESUFX}

SCHEMATA=		collective corba core cosine duaconf dyngroup \
			inetorgperson java misc nadf \
			nis openldap ppolicy

LDAP_RUN_DIR?=		/var/run/openldap
LOCALSTATEDIR?=		/var/db
DATABASEDIR?=		${LOCALSTATEDIR}/openldap-data

SUB_LIST+=		LDAP_RUN_DIR=${LDAP_RUN_DIR} \
			DATABASEDIR=${DATABASEDIR} \
			PKGNAME=${PKGNAME}

CONFIGURE_ARGS=		--with-threads=posix \
			--with-tls=openssl \
			--enable-dynamic

.if defined(WITH_SASL) && !defined(WITHOUT_SASL)
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
			--disable-glue \
			--disable-syncprov
SUB_FILES+=		pkg-message.client
PKGMESSAGE=		${WRKSRC}/pkg-message.client

USE_LDCONFIG=		yes

.else
# server specific configuration

USE_LDCONFIG=		${PREFIX}/libexec/openldap
SUB_FILES+=		pkg-install pkg-message pkg-deinstall
USE_RC_SUBR=		slapd.sh

EXTRA_PATCHES+=		${FILESDIR}/extrapatch-Makefile.in

.if defined(WITH_MODULES) || !defined(WITHOUT_DYNAMIC_BACKENDS) || defined(WITH_SLAPI)
USE_AUTOTOOLS+=		libltdl:22
CONFIGURE_ARGS+=	--enable-modules
PLIST_SUB+=		MODULES=""
.else
PLIST_SUB+=		MODULES="@comment "
.endif

SED_MODULES=		-e 's/\(moduleload[ 	]*back_[a-z]*\)\.la/\1/'

.if !defined(WITHOUT_DYNAMIC_BACKENDS)
BACKEND_ENABLE=		"mod"
BACKEND_PLIST=		""
SED_MODULES+=		-e 's/\# *\(modulepath\)/\1/' \
			-e 's/\# *\(moduleload[ 	]*back_bdb\)/\1/'
.else
BACKEND_ENABLE=		"yes"
BACKEND_PLIST=		"@comment "
.endif

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--enable-crypt \
			--enable-lmpasswd \
			--enable-ldap=${BACKEND_ENABLE} \
			--enable-meta=${BACKEND_ENABLE} \
			--enable-rewrite \
			--enable-null=${BACKEND_ENABLE} \
			--enable-monitor=${BACKEND_ENABLE}

PLIST_SUB+=		BACKEND=${BACKEND_PLIST}

.if defined(WITH_ACCESSLOG)
CONFIGURE_ARGS+=	--enable-accesslog
.endif

.if defined(WITH_AUDITLOG)
CONFIGURE_ARGS+=	--enable-auditlog
.endif

.if defined(WITH_COLLECT)
CONFIGURE_ARGS+=	--enable-collect
.endif

.if defined(WITH_CONSTRAINT)
CONFIGURE_ARGS+=	--enable-constraint
.endif

.if defined(WITH_DDS)
CONFIGURE_ARGS+=	--enable-dds
.endif

.if defined(WITH_DEREF)
CONFIGURE_ARGS+=	--enable-deref
.endif

.if defined(WITH_DYNGROUP)
CONFIGURE_ARGS+=	--enable-dyngroup
.endif

.if defined(WITH_DYNLIST)
CONFIGURE_ARGS+=	--enable-dynlist
.endif

.if defined(WITH_LASTMOD)
CONFIGURE_ARGS+=	--enable-lastmod
.endif

.if defined(WITH_MEMBEROF)
CONFIGURE_ARGS+=	--enable-memberof
.endif

.if defined(WITH_PPOLICY)
CONFIGURE_ARGS+=	--enable-ppolicy
.endif

.if defined(WITH_PROXYCACHE)
CONFIGURE_ARGS+=	--enable-proxycache
.endif

.if defined(WITH_REFINT)
CONFIGURE_ARGS+=	--enable-refint
.endif

.if defined(WITH_RETCODE)
CONFIGURE_ARGS+=	--enable-retcode
.endif

.if defined(WITH_RWM)
CONFIGURE_ARGS+=	--enable-rwm
.endif

.if defined(WITHOUT_SEQMOD)
CONFIGURE_ARGS+=	--disable-seqmod
.else
CONFIGURE_ARGS+=	--enable-seqmod
.endif

.if defined(WITHOUT_SYNCPROV)
CONFIGURE_ARGS+=	--disable-syncprov
.else
CONFIGURE_ARGS+=	--enable-syncprov
.endif

.if defined(WITH_TRANSLUCENT)
CONFIGURE_ARGS+=	--enable-translucent
.endif

.if defined(WITH_UNIQUE)
CONFIGURE_ARGS+=	--enable-unique
.endif

.if defined(WITH_VALSORT)
CONFIGURE_ARGS+=	--enable-valsort
.endif

.if defined(WITH_ACI)
CONFIGURE_ARGS+=	--enable-aci
.endif

.if defined(WITH_DYNACL)
CONFIGURE_ARGS+=	--enable-dynacl
.endif

.if defined(WITHOUT_BDB)
CONFIGURE_ARGS+=	--disable-bdb \
			--disable-hdb
PLIST_SUB+=		BACK_BDB="@comment " \
			BACK_HDB="@comment "
.else

WITH_BDB_VER?=		46
INVALID_BDB_VER=	42
USE_BDB=		yes

.if ${WITH_BDB_VER} >= 43
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

.if defined(WITH_DNSSRV)
CONFIGURE_ARGS+=	--enable-dnssrv=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_DNSSRV=${BACKEND_PLIST}
.else
PLIST_SUB+=		BACK_DNSSRV="@comment "
.endif

.if defined(WITH_PASSWD)
CONFIGURE_ARGS+=	--enable-passwd=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_PASSWD=${BACKEND_PLIST}
.else
PLIST_SUB+=		BACK_PASSWD="@comment "
.endif

.if defined(WITH_RELAY)
CONFIGURE_ARGS+=	--enable-relay=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_RELAY=${BACKEND_PLIST}
.else
PLIST_SUB+=		BACK_RELAY="@comment "
.endif

.if defined(WITH_SHELL)
CONFIGURE_ARGS+=	--without-threads --enable-shell=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_SHELL=${BACKEND_PLIST}
.else
PLIST_SUB+=		BACK_SHELL="@comment "
WANT_OPENLDAP_THREADS=	yes
.endif

.if defined(WITH_SOCK)
CONFIGURE_ARGS+=	--enable-sock=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_SOCK=${BACKEND_PLIST}
.else
PLIST_SUB+=		BACK_SOCK="@comment "
.endif

.if defined(WITH_PERL)
USE_PERL5=		yes
CONFIGURE_ARGS+=	--enable-perl=${BACKEND_ENABLE}
CONFIGURE_ENV+=		PERLBIN="${PERL}"
PLIST_SUB+=		BACK_PERL=${BACKEND_PLIST}
.else
PLIST_SUB+=		BACK_PERL="@comment "
.endif

.if defined(WITH_SASL) && !defined(WITHOUT_SASL)
CONFIGURE_ARGS+=	--enable-spasswd
.endif

.if defined(WITH_ODBC)
CONFIGURE_ARGS+=	--enable-sql=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_SQL=${BACKEND_PLIST}
WITH_ODBC_TYPE?=	iODBC
.if ${WITH_ODBC_TYPE:L} == iodbc
LIB_DEPENDS+=		iodbc.3:${PORTSDIR}/databases/libiodbc
.elif ${WITH_ODBC_TYPE:L} == unixodbc
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
.else
BROKEN=			choose either iODBC or unixODBC for WITH_ODBC_TYPE
.endif
.else
PLIST_SUB+=		BACK_SQL="@comment "
.endif

.if defined(WITH_SMBPWD)
PLIST_SUB+=		SMBPWD=""
.else
PLIST_SUB+=		SMBPWD="@comment "
.endif

.if defined(WITH_RLOOKUPS)
CONFIGURE_ARGS+=	--enable-rlookups
PLIST_SUB+=		RLOOKUPS=""
.else
PLIST_SUB+=		RLOOKUPS="@comment "
.endif

.if defined(WITH_SLAPI)
CONFIGURE_ARGS+=	--enable-slapi
PLIST_SUB+=		SLAPI=""
USE_LDCONFIG=		yes
.else
PLIST_SUB+=		SLAPI="@comment "
.endif

.if defined(WITH_SLP)
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

CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}" \
			LDFLAGS="${LDFLAGS}" \
			LIBS="${LIBS}"

.if defined(CLIENT_ONLY)
.include "${FILESDIR}/manpages"
.else
SUB_LIST+=		RC_DIR=${PREFIX} \
			RC_SUFX=${RC_SUBR_SUFFIX} \
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

.if defined(WITH_SMBPWD)
post-build:
	@cd ${BUILD_WRKSRC}/contrib/slapd-modules/smbk5pwd; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} DEFS="-DDO_SAMBA" all
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
.if defined(WITH_SMBPWD)
	@${INSTALL_DATA} ${WRKSRC}/contrib/slapd-modules/smbk5pwd/smbk5pwd.la \
		${PREFIX}/libexec/openldap/
	@${INSTALL_PROGRAM} ${WRKSRC}/contrib/slapd-modules/smbk5pwd/.libs/smbk5pwd.so.0 \
		${PREFIX}/libexec/openldap/
	@${LN} -s smbk5pwd.so.0 ${PREFIX}/libexec/openldap/smbk5pwd.so
.endif
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
