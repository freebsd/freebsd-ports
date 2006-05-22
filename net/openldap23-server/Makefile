# New ports collection makefile for:	openldap23-server
# Date created:				02 May 2005
# Whom:					Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=		openldap
DISTVERSION=		2.3.23
PORTREVISION=		${OPENLDAP_PORTREVISION}
CATEGORIES=		net databases
MASTER_SITES=		ftp://ftp.OpenLDAP.org/pub/OpenLDAP/%SUBDIR%/ \
			http://public.planetmirror.com/pub/openldap/%SUBDIR%/ \
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

UNIQUENAME?=		${PKGNAMEPREFIX}openldap23
LATEST_LINK?=		${UNIQUENAME}${PKGNAMESUFFIX}
USE_OPENSSL=		yes

WANT_OPENLDAP_VER?=	23
.if ${WANT_OPENLDAP_VER} != 23
BROKEN=			incompatible OpenLDAP version: ${WANT_OPENLDAP_VER}
.endif

PORTREVISION_CLIENT=	1
PORTREVISION_SERVER=	0

.if !defined(CLIENT_ONLY)
OPTIONS=	SASL "With (Cyrus) SASL2 support" on \
		PERL "With Perl backend" off \
		SHELL "With Shell backend (disables threading)" on \
		ODBC "With SQL backend" off \
		SLP "With SLPv2 (RFC 2608) support" off \
		SLAPI "With Netscape SLAPI plugin API" off \
		TCP_WRAPPERS "With tcp wrapper support" on \
		BDB "With BerkeleyDB support" on \
		ACCESSLOG "With In-Directory Access Logging overlay" off \
		AUDITLOG "With Audit Logging overlay" off \
		DENYOP "With Deny Operation overlay" off \
		DYNGROUP "With Dynamic Group overlay" off \
		DYNLIST "With Dynamic List overlay" off \
		LASTMOD "With Last Modification overlay" off \
		PPOLICY "With Password Policy overlay" off \
		PROXYCACHE "With Proxy Cache overlay" off \
		REFINT "With Referential Integrity overlay" off \
		RETCODE "With Return Code testing overlay" off \
		RWM "With Rewrite/Remap overlay" off \
		SYNCPROV "With Syncrepl Provider overlay" off \
		TRANSLUCENT "With Translucent Proxy overlay" off \
		UNIQUE "With attribute Uniqueness overlay" off \
		VALSORT "With Value Sorting overlay" off \
		ACI "With per-object ACIs (experimental)" off \
		DYNAMIC_BACKENDS "Build dynamic backends" on
.endif

.if defined(CLIENT_ONLY)
OPENLDAP_PORTREVISION=	${PORTREVISION_CLIENT}
OPENLDAP_PKGFILESUFX=	.client
.else
OPENLDAP_PORTREVISION=	${PORTREVISION_SERVER}
OPENLDAP_PKGFILESUFX=
.endif

.include <bsd.port.pre.mk>

.if defined(CLIENT_ONLY)
.if defined(WITH_SASL)
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
.else
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-sasl-client-2.*
.endif

.endif

USE_AUTOTOOLS=		libtool:15

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

INSTALLS_SHLIB=		yes
SUB_FILES+=		pkg-message.client
PKGMESSAGE=		${WRKSRC}/pkg-message.client

.else
# server specific configuration

SUB_FILES+=		pkg-deinstall pkg-message pkg-install
USE_RC_SUBR=		slapd.sh slurpd.sh

EXTRA_PATCHES+=		${FILESDIR}/extrapatch-Makefile.in

.if defined(WITH_MODULES) || !defined(WITHOUT_DYNAMIC_BACKENDS) || defined(WITH_SLAPI)
USE_AUTOTOOLS+=		libltdl:15
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
			--enable-ldbm=${BACKEND_ENABLE} \
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

.if defined(WITH_DENYOP)
CONFIGURE_ARGS+=	--enable-denyop
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

.if defined(WITH_SYNCPROV)
CONFIGURE_ARGS+=	--enable-syncprov
.else
CONFIGURE_ARGS+=	--disable-syncprov
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

.if defined(WITHOUT_BDB)
CONFIGURE_ARGS+=	--disable-bdb \
			--disable-hdb \
			--enable-ldbm-api=bcompat
PLIST_SUB+=		BACK_BDB="@comment " \
			BACK_HDB="@comment "
.else

WITH_BDB_VER?=		43
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

.if defined(WITHOUT_SHELL)
PLIST_SUB+=		BACK_SHELL="@comment "
.else
CONFIGURE_ARGS+=	--without-threads --enable-shell=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_SHELL=${BACKEND_PLIST}
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

.if defined(WITH_SLAPI)
CONFIGURE_ARGS+=	--enable-slapi
PLIST_SUB+=		SLAPI=""
INSTALLS_SHLIB=		yes
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

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}" \
			LDFLAGS="${LDFLAGS}" \
			LIBS="${LIBS}"

.if defined(CLIENT_ONLY)
.include "${FILESDIR}/manpages"
.else
.if (${OSVERSION} >= 700007 || (${OSVERSION} < 700000 && ${OSVERSION} >= 600101))
RC_SUFX=
.else
RC_SUFX=		.sh
.endif
SUB_LIST+=		RC_DIR=${PREFIX} \
			RC_SUFX=${RC_SUFX} \
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

pre-install:
	@if [ -f ${PKGINSTALL} ]; then \
		${SETENV} PKG_PREFIX="${PREFIX}" PKG_DESTDIR="${DESTDIR}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL; \
	fi
.if defined(WITH_MODULES) || !defined(WITHOUT_DYNAMIC_BACKENDS) || defined(WITH_SLAPI)
	@${MKDIR} ${DESTDIR}${PREFIX}/libexec/openldap
.endif

post-install:
.if defined(CLIENT_ONLY)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DESTDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${DESTDIR}${DOCSDIR}
	@for dir in drafts rfc; do \
		${MKDIR} ${DESTDIR}${DOCSDIR}/$${dir}; \
		${INSTALL_DATA} ${WRKSRC}/doc/$${dir}/* ${DESTDIR}${DOCSDIR}/$${dir}; \
	done
.endif
.else
	@${MKDIR} ${DESTDIR}${LDAP_RUN_DIR}
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
