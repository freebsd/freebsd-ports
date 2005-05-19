# New ports collection makefile for:	openldap23-server
# Date created:				02 May 2005
# Whom:					Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=		openldap
DISTVERSION=		2.3.3beta
PORTREVISION=		${OPENLDAP_PORTREVISION}
CATEGORIES=		net databases
MASTER_SITES=		ftp://ftp.OpenLDAP.org/pub/OpenLDAP/%SUBDIR%/ \
			http://public.planetmirror.com/pub/openldap/%SUBDIR%/ \
			ftp://gd.tuwien.ac.at/infosys/network/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.matrix.com.br/pub/openldap/%SUBDIR%/ \
			ftp://ftp.ucr.ac.cr/pub/Unix/openldap/%SUBDIR%/ \
			ftp://ftp.ntua.gr/mirror/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.shellhung.org/pub/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.dti.ad.jp/pub/net/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.u-aizu.ac.jp/pub/net/openldap/%SUBDIR%/ \
			ftp://ftp.holywar.net/pub/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.nl.uu.net/pub/unix/db/openldap/%SUBDIR%/ \
			ftp://ftp.linux.pt/pub/mirrors/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.rediris.es/mirror/OpenLDAP/%SUBDIR%/ \
			ftp://sunsite.cnlab-switch.ch/mirror/OpenLDAP/%SUBDIR%/ \
			http://openldap.cdpa.nsysu.edu.tw/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.plig.org/pub/OpenLDAP/%SUBDIR%/
MASTER_SITE_SUBDIR=	openldap-test
PKGNAMESUFFIX?=		-server
EXTRACT_SUFX=		.tgz

MAINTAINER=		vsevolod@highsecure.ru
COMMENT?=		Open source LDAP server implementation

UNIQUENAME?=		${PKGNAMEPREFIX}openldap23
LATEST_LINK?=		${UNIQUENAME}${PKGNAMESUFFIX}

WANT_OPENLDAP_VER?=	23
.if ${WANT_OPENLDAP_VER} != 23
BROKEN=			"incompatible OpenLDAP version: ${WANT_OPENLDAP_VER}"
.endif

PORTREVISION_CLIENT=	1
PORTREVISION_SERVER=	0

.if defined(CLIENT_ONLY)
OPENLDAP_PORTREVISION=	${PORTREVISION_CLIENT}
OPENLDAP_PKGFILESUFX=	.client

.if ${PKGNAMESUFFIX} == "-sasl-client"
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-client-2.* \
			${PKGNAMEPREFIX}${PORTNAME}-sasl-client-2.[!3].*
.elif ${PKGNAMESUFFIX} == "-client"
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-client-2.[!3].* \
			${PKGNAMEPREFIX}${PORTNAME}-sasl-client-2.*
.else
BROKEN=			"Unknown PKGNAMESUFFIX ${PKGNAMESUFFIX}"
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=		CHANGES drafts rfc
.endif

.if defined(USE_OPENLDAP)
IGNORE=			: You have \`USE_OPENLDAP' defined either in your environment or in make(1) arguments
.endif
.else
OPENLDAP_PORTREVISION=	${PORTREVISION_SERVER}
OPENLDAP_PKGFILESUFX=

.if defined(WITH_SASL)
RUN_DEPENDS=		${LOCALBASE}/lib/libldap-2.3.so.0:${PORTSDIR}/net/openldap23-sasl-client
.else
RUN_DEPENDS=		${LOCALBASE}/lib/libldap-2.3.so.0:${PORTSDIR}/net/openldap23-client
.endif

.if ${PKGNAMESUFFIX} == "-sasl-server"
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-server-2.* \
			${PKGNAMEPREFIX}${PORTNAME}-sasl-server-2.[!3].*
.elif ${PKGNAMESUFFIX} == "-server"
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-server-2.[!3].* \
			${PKGNAMEPREFIX}${PORTNAME}-sasl-server-2.*
.else
BROKEN=			"Unknown PKGNAMESUFFIX ${PKGNAMESUFFIX}"
.endif

.endif

USE_OPENSSL=		yes
USE_REINPLACE=		yes
USE_LIBTOOL_VER=	15

DESCR=			${PKGDIR}/pkg-descr${OPENLDAP_PKGFILESUFX}
PLIST=			${PKGDIR}/pkg-plist${OPENLDAP_PKGFILESUFX}
PKGINSTALL=		${WRKDIR}/pkg-install
PKGMESSAGE=		${WRKDIR}/pkg-message
PKGDEINSTALL=		${WRKDIR}/pkg-deinstall

SCHEMATA=		corba core cosine dyngroup \
			inetorgperson java misc \
			nis openldap ppolicy

LDAP_RUN_DIR?=		/var/run/openldap
LOCALSTATEDIR?=		/var/db
DATABASEDIR?=		${LOCALSTATEDIR}/openldap-data
SLURPDIR?=		${LOCALSTATEDIR}/openldap-slurp

PLIST_SUB+=		LDAP_RUN_DIR=${LDAP_RUN_DIR} \
			DATABASEDIR=${DATABASEDIR} \
			SLURPDIR=${SLURPDIR} \

SED_SCRIPT=		-e 's,%%PKGNAME%%,${PKGNAME},g' \
			-e 's,%%PREFIX%%,${PREFIX},g' \
			-e 's,%%LDAP_RUN_DIR%%,${LDAP_RUN_DIR},g' \
			-e 's,%%DATABASEDIR%%,${DATABASEDIR},g' \
			-e 's,%%SLURPDIR%%,${SLURPDIR},g'

CONFIGURE_ARGS=		--with-threads=posix \
			--with-tls=openssl \
			--enable-dynamic

.if defined(WITH_SASL)
LIB_DEPENDS+=		sasl2.2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--with-cyrus-sasl
.else
CONFIGURE_ARGS+=	--without-cyrus-sasl
.endif

CONFIGURE_SED+=		-e 's,(-lssl) +(-lcrypto),\2 \1,'

.if defined(CLIENT_ONLY)
# client specific configuration

CONFIGURE_ARGS+=	--disable-slapd \
			--disable-monitor \
			--disable-bdb \
			--disable-relay \
			--disable-glue \
			--disable-syncprov

INSTALLS_SHLIB=		yes

.else
# server specific configuration

USE_RC_SUBR=		yes

EXTRA_PATCHES+=		${FILESDIR}/extrapatch-Makefile.in

.if defined(WITH_MODULES) || !defined(WITHOUT_DYNAMIC_BACKENDS) || defined(WITH_SLAPI)
USE_LIBLTDL=		yes
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

CONFIGURE_ARGS+=	--disable-syncprov

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

.if defined(WITH_DYNGROUP)
CONFIGURE_ARGS+=	--enable-dyngroup
.endif

.if defined(WITH_PROXYCACHE)
CONFIGURE_ARGS+=	--enable-proxycache
.endif

.if defined(WITH_ACI)
CONFIGURE_ARGS+=	--enable-aci
.endif

.if defined(WITHOUT_BDB)
CONFIGURE_ARGS+=	--disable-bdb \
			--disable-hdb \
			--with-ldbm-api=bcompat
PLIST_SUB+=		BACK_BDB="@comment " \
			BACK_HDB="@comment "
.else

WITH_BDB_VER?=		43

.if ${WITH_BDB_VER} == 43
CONFIGURE_ARGS+=	--enable-bdb=${BACKEND_ENABLE} \
			--enable-hdb=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_BDB=${BACKEND_PLIST} \
			BACK_HDB=${BACKEND_PLIST}
BDBLIB=			db-4.3.0
.elif ${WITH_BDB_VER} == 42
CONFIGURE_ARGS+=	--enable-bdb=${BACKEND_ENABLE} \
			--enable-hdb=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_BDB=${BACKEND_PLIST} \
			BACK_HDB=${BACKEND_PLIST}
BDBLIB=			db-4.2.2
.elif ${WITH_BDB_VER} == 41
CONFIGURE_ARGS+=	--disable-bdb \
			--enable-hdb=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_BDB="@comment " \
			BACK_HDB=${BACKEND_PLIST}
BDBLIB=			db41.1
.elif ${WITH_BDB_VER} == 4
CONFIGURE_ARGS+=	--disable-bdb \
			--enable-hdb=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_BDB="@comment " \
			BACK_HDB=${BACKEND_PLIST}
BDBLIB=			db4.0
.elif ${WITH_BDB_VER} == 3
CONFIGURE_ARGS+=	--disable-bdb \
			--disable-hdb
PLIST_SUB+=		BACK_BDB="@comment " \
			BACK_HDB="@comment "
BDBLIB=			db3.3
.else
IGNORE=			: WITH_BDB_VER must be 3, 4, 41 or 42
.endif

LIB_DEPENDS+=		${BDBLIB}:${PORTSDIR}/databases/db${WITH_BDB_VER}
CPPFLAGS+=		-I${LOCALBASE}/include/db${WITH_BDB_VER}
CONFIGURE_ARGS+=	--with-ldbm-api=berkeley
CONFIGURE_SED+=		-e 's,ol_DB_LIB=$$,&-l${BDBLIB:R},' \
			-e 's,(ol_cv_lib_db=)yes$$,\1-l${BDBLIB:R},'
.endif

.if defined(WITHOUT_SHELL)
CONFIGURE_ARGS+=	--enable-shell=${BACKEND_ENABLE}
PLIST_SUB+=		BACK_SHELL=${BACKEND_PLIST}
.else
PLIST_SUB+=		BACK_SHELL="@comment "
.endif

.if defined(WITH_PERL)
USE_PERL5=		yes
CONFIGURE_ARGS+=	--enable-perl=${BACKEND_ENABLE}
CONFIGURE_ENV+=		PERLBIN="${PERL}"
PLIST_SUB+=		BACK_PERL=${BACKEND_PLIST}
.else
PLIST_SUB+=		BACK_PERL="@comment "
.endif

.if defined(WITH_SASL)
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
IGNORE=			: WITH_ODBC_TYPE must be iODBC or unixODBC
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

.include <bsd.port.pre.mk>

.if defined(CLIENT_ONLY)
.include "${FILESDIR}/manpages"
.else
.if defined(WITH_RCORDER) && ( defined(DFOSVERSION) || ${OSVERSION} >= 500038 )
RC_DIR=			/
RC_SUFX=
PLIST_SUB+=		RCORDER="" RC_DIR=""
.else
RC_DIR=			${PREFIX}
RC_SUFX=		.sh
PLIST_SUB+=		RCORDER="@comment " RC_DIR="%D"
.endif
SED_SCRIPT+=		-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
			-e 's,%%RC_DIR%%,${RC_DIR:S/\/$//},g' \
			-e 's,%%RC_SUFX%%,${RC_SUFX},g'
PLIST_SUB+=		RC_SUFX=${RC_SUFX}
.endif

pre-everything::
	@${ECHO} "============================================================="
	@${ECHO}
	@${ECHO} "You can build ${PKGNAME} with the following options:"
	@${ECHO}
.if defined(CLIENT_ONLY)
	@${ECHO} "WITH_SASL             with (Cyrus) SASL2 support"
.else
	@${ECHO} "WITH_BDB_VER          select BerkeleyDB version (default 43)"
	@${ECHO} "WITH_SASL             with (Cyrus) SASL2 password verification"
	@${ECHO} "WITH_PERL             with Perl backend"
	@${ECHO} "WITHOUT_SHELL         without Shell backend"
	@${ECHO} "WITH_ODBC             with SQL backend"
	@${ECHO} "WITH_ODBC_TYPE        select ODBC interface (iODBC or unixODBC)"
	@${ECHO} "WITH_SLP              with SLPv2 (RFC 2608) support"
	@${ECHO} "WITH_SLAPI            with Netscape SLAPI plugin API"
	@${ECHO} "WITHOUT_TCP_WRAPPERS  without tcp wrapper support"
	@${ECHO} "WITHOUT_BDB           without BerkeleyDB support"
	@${ECHO} "WITH_DYNGROUP         with Dynamic Group overlay"
	@${ECHO} "WITH_PROXYCACHE       with Proxy Cache overlay"
	@${ECHO} "WITH_ACI              with per-object ACIs (experimental)"
	@${ECHO} "WITHOUT_DYNAMIC_BACKENDS build static backends"
.if defined(DFOSVERSION) || ${OSVERSION} >= 500038
	@${ECHO} "WITH_RCORDER          slapd(1) should start early in the boot process"
.endif
.endif
	@${ECHO}
	@${ECHO} "============================================================="
	@${ECHO}

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

post-build:
.for script in slapd slurpd
	@${SED} ${SED_SCRIPT} ${FILESDIR}/${script}.sh >${WRKDIR}/${script}.sh
.endfor
.for text in pkg-install pkg-message pkg-deinstall
	@if [ -f ${PKGDIR}/${text}${OPENLDAP_PKGFILESUFX} ]; then \
		${SED} ${SED_SCRIPT} ${PKGDIR}/${text}${OPENLDAP_PKGFILESUFX} \
		>${WRKDIR}/${text}; \
	fi
.endfor

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
	@[ "${RC_DIR:S/\/$//}" = "${PREFIX}" ] || ${ECHO_CMD} "@cwd ${RC_DIR}" >>${TMPPLIST}
.for script in slapd slurpd
	@${INSTALL_SCRIPT} ${WRKDIR}/${script}.sh ${DESTDIR}${RC_DIR:S/\/$//}/etc/rc.d/${script}${RC_SUFX}
	@${ECHO_CMD} "etc/rc.d/${script}${RC_SUFX}" >>${TMPPLIST}
.endfor
	@[ "${RC_DIR:S/\/$//}" = "${PREFIX}" ] || ${ECHO_CMD} "@cwd ${PREFIX}" >>${TMPPLIST}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
