# New ports collection makefile for:	openldap22-server
# Date created:				10 Jul 2003
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=		openldap
PORTVERSION=		2.2.5
PORTREVISION=		${OPENLDAP_PORTVERSION}
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
			http://openldap.cdpa.nsysu.edu.tw/OpenLDAP/%SUBDIR%/ \
			ftp://ftp.plig.org/pub/OpenLDAP/%SUBDIR%/
MASTER_SITE_SUBDIR=	openldap-release
PKGNAMESUFFIX=		${OPENLDAP_PKGNAMESUFFIX}
EXTRACT_SUFX=		.tgz

MAINTAINER=		eik@FreeBSD.org
COMMENT?=		Open source LDAP server implementation

LATEST_LINK=		${PKGNAMEPREFIX}openldap22${PKGNAMESUFFIX}
CONFLICTS=		${PKGNAMEPREFIX}${PORTNAME}-client-2.[013-9].*

WANT_OPENLDAP_VER?=	22
.if ${WANT_OPENLDAP_VER} != 22
BROKEN=			"incompatible OpenLDAP version: ${WANT_OPENLDAP_VER}"
.endif

.if defined(CLIENT_ONLY)
OPENLDAP_PORTVERSION=	0
OPENLDAP_PKGNAMESUFFIX?=-client
OPENLDAP_PKGFILESUFX?=	.client

.if !defined(NOPORTDOCS)
PORTDOCS=		drafts rfc
.endif

.if defined(USE_OPENLDAP)
.error You have `USE_OPENLDAP' defined either in your environment or in make(1) arguments.
.endif
.else
OPENLDAP_PORTVERSION=	1
OPENLDAP_PKGNAMESUFFIX?=-server
OPENLDAP_PKGFILESUFX?=

RUN_DEPENDS=		${LOCALBASE}/lib/libldap.so.202:${PORTSDIR}/net/openldap22-client
CONFLICTS+=		${PKGNAMEPREFIX}${PORTNAME}-server-2.[013-9].*
.endif

USE_OPENSSL=		yes
USE_REINPLACE=		yes
USE_LIBTOOL_VER=	14

DESCR=			${PKGDIR}/pkg-descr${OPENLDAP_PKGFILESUFX}
PLIST=			${PKGDIR}/pkg-plist${OPENLDAP_PKGFILESUFX}
PKGINSTALL=		${WRKDIR}/pkg-install
PKGMESSAGE=		${WRKDIR}/pkg-message
PKGDEINSTALL=		${WRKDIR}/pkg-deinstall

SCHEMATA=		corba core cosine \
			dyngroup inetorgperson java \
			misc nis openldap

LDAP_RUN_DIR?=		${DESTDIR}/var/run/openldap
LOCALSTATEDIR?=		${DESTDIR}/var/db
DATABASEDIR?=		${LOCALSTATEDIR}/openldap-data
SLURPDIR?=		${LOCALSTATEDIR}/openldap-slurp

PLIST_SUB+=		LDAP_RUN_DIR=${LDAP_RUN_DIR} \
			DATABASEDIR=${DATABASEDIR} \
			SLURPDIR=${SLURPDIR} \

SED_SCRIPT=		-e 's,%%PREFIX%%,${PREFIX},g' \
			-e 's,%%LDAP_RUN_DIR%%,${LDAP_RUN_DIR},g' \
			-e 's,%%DATABASEDIR%%,${DATABASEDIR},g' \
			-e 's,%%SLURPDIR%%,${SLURPDIR},g'

CONFIGURE_ARGS=		--with-threads \
			--with-tls=openssl \
			--enable-dynamic

.if defined(WITH_SASL)
LIB_DEPENDS+=		sasl2.2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--with-cyrus-sasl
.else
CONFIGURE_ARGS+=	--without-cyrus-sasl
.endif

.if defined(CLIENT_ONLY)
# client specific configuration

CONFIGURE_ARGS+=	--disable-slapd

INSTALLS_SHLIB=		yes

.else
# server specific configuration

EXTRA_PATCHES+=		${FILESDIR}/extrapatch-Makefile.in

CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--enable-ldbm \
			--with-ldbm-api=berkeley \
			--enable-crypt \
			--enable-lmpasswd \
			--enable-ldap \
			--enable-meta \
			--enable-rewrite \
			--enable-null \
			--enable-monitor

WITH_BDB_VER?=		42

.if ${WITH_BDB_VER} == 42
LIB_DEPENDS+=		db-4.2.2:${PORTSDIR}/databases/db42
CONFIGURE_ARGS+=	--enable-bdb
.elif ${WITH_BDB_VER} == 41
LIB_DEPENDS+=		db41.1:${PORTSDIR}/databases/db41
CONFIGURE_ARGS+=	--enable-bdb
.elif ${WITH_BDB_VER} == 4
LIB_DEPENDS+=		db4.0:${PORTSDIR}/databases/db4
CONFIGURE_ARGS+=	--disable-bdb
.elif ${WITH_BDB_VER} == 3
LIB_DEPENDS+=		db3.3:${PORTSDIR}/databases/db3
CONFIGURE_ARGS+=	--disable-bdb
.else
.error WITH_BDB_VER must be 3, 4, 41 or 42
.endif
.if ${WITH_BDB_VER} == 42
LIBS+=			-ldb-4.2
.else
LIBS+=			-ldb${WITH_BDB_VER}
.endif
CPPFLAGS+=		-I${LOCALBASE}/include/db${WITH_BDB_VER}

.if defined(WITH_SHELL)
CONFIGURE_ARGS+=	--enable-shell
.endif

.if defined(WITH_PERL)
USE_PERL5=	yes
CONFIGURE_ARGS+=	--enable-perl
.endif

.if defined(WITH_SASL)
CONFIGURE_ARGS+=	--enable-spasswd
.endif

.if defined(WITH_ODBC)
WITH_ODBC_TYPE?=	iODBC
.endif
.if defined(WITH_ODBC_TYPE)
.if ${WITH_ODBC_TYPE:L} == iodbc
LIB_DEPENDS+=		iodbc.3:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--enable-sql
.elif ${WITH_ODBC_TYPE:L} == unixodbc
LIB_DEPENDS+=		odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--enable-sql
.else
.error WITH_ODBC_TYPE must be iODBC or unixODBC
.endif
.endif

.if defined(WITH_SLAPI)
LIB_DEPENDS+=		ltdl.4:${PORTSDIR}/devel/libltdl
CONFIGURE_ARGS+=	--enable-slapi
PLIST_SUB+=		SLAPI=""
INSTALLS_SHLIB=		yes
.else
PLIST_SUB+=		SLAPI="@comment "
.endif

# Include tcp-wrapper support
.if !defined(WITHOUT_TCP_WRAPPERS) && exists(/usr/include/tcpd.h)
CONFIGURE_ARGS+=	--enable-wrappers
.endif

# end of client/server specific configuration
.endif

CPPFLAGS+=		${PTHREAD_CFLAGS} \
			-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" \
			LDFLAGS="${LDFLAGS}" \
			LIBS="${LIBS}"

.include <bsd.port.pre.mk>

.if defined(CLIENT_ONLY)
.include "${FILESDIR}/manpages"
.else
.if ${OSVERSION} >= 500038
RC_SUBR?=	${DESTDIR}/etc/rc.subr
RC_DIR=		${DESTDIR}/etc/rc.d
RC_SUFX=
.else
USE_RC_SUBR=	yes
RC_DIR=		${PREFIX}/etc/rc.d
RC_SUFX=	.sh
.endif

SED_SCRIPT+=	-e 's,%%RC_SUBR%%,${RC_SUBR},g' \
		-e 's,%%RC_DIR%%,${RC_DIR},g' \
		-e 's,%%RC_SUFX%%,${RC_SUFX},g'
PLIST_SUB+=	RC_DIR=${RC_DIR} \
		RC_SUFX=${RC_SUFX}
.endif

pre-everything::
	@${ECHO} "============================================================="
	@${ECHO}
	@${ECHO} "You can build ${PKGNAME} with the following options:"
	@${ECHO}
.if defined(CLIENT_ONLY)
	@${ECHO} "WITH_SASL             with (Cyrus) SASL2 support"
.else
	@${ECHO} "WITH_BDB_VER          select BerkeleyDB version (default 42)"
	@${ECHO} "WITH_SASL             with (Cyrus) SASL2 password verification"
	@${ECHO} "WITH_PERL             with Perl backend"
	@${ECHO} "WITH_SHELL            with Shell backend"
	@${ECHO} "WITH_ODBC             with SQL backend"
	@${ECHO} "WITH_ODBC_TYPE        select ODBC interface (iODBC or unixODBC)"
	@${ECHO} "WITH_SLAPI            with Netscape SLAPI plugin API
	@${ECHO} "WITHOUT_TCP_WRAPPERS  without tcp wrapper support"
.endif
	@${ECHO}
	@${ECHO} "============================================================="
	@${ECHO}

post-patch:
	@${REINPLACE_CMD} -e 's,%LOCALSTATEDIR%/run/,${LDAP_RUN_DIR}/,g' \
		${WRKSRC}/servers/slapd/slapd.conf

pre-configure:
	@${REINPLACE_CMD} -e '/^LIBTOOL=/s,\$$(top_builddir)/libtool,${LIBTOOL},g' \
		${WRKSRC}/configure

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
		${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL; \
	fi

post-install:
.if defined(CLIENT_ONLY)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for dir in drafts rfc; do \
		${MKDIR} ${DOCSDIR}/$${dir}; \
		${INSTALL_DATA} ${WRKSRC}/doc/$${dir}/* ${DOCSDIR}/$${dir}; \
	done
.endif
.else
	@for schema in ${SCHEMATA}; do \
		${ECHO_CMD} "@unexec if cmp -s %D/etc/openldap/schema/$${schema}.schema" \
			"%D/etc/openldap/schema/$${schema}.schema.default; then" \
			"rm -f %D/etc/openldap/schema/$${schema}.schema; fi" >>${TMPPLIST}; \
		${ECHO_CMD} "etc/openldap/schema/$${schema}.schema.default" >>${TMPPLIST}; \
		${ECHO_CMD} "@exec [ -f %B/$${schema}.schema ] || cp %B/%f %B/$${schema}.schema" >>${TMPPLIST}; \
	done
	@${ECHO_CMD} "@unexec rmdir %D/etc/openldap/schema 2>/dev/null || true" >>${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir %D/etc/openldap 2>/dev/null || true" >>${TMPPLIST}
#	currently the only way to participate in rcorder(8)
	@if [ "${RC_DIR}" != "${PREFIX}" ]; then \
		${ECHO_CMD} "@cwd ${RC_DIR}" >>${TMPPLIST}; \
	fi
.for script in slapd slurpd
	@${INSTALL_SCRIPT} ${WRKDIR}/${script}.sh ${RC_DIR}/${script}${RC_SUFX}
	@${ECHO_CMD} "${script}${RC_SUFX}" >>${TMPPLIST}
.endfor
	@${MKDIR} ${LDAP_RUN_DIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
