# New ports collection makefile for:	openldap20-server
# Date created:				10 Jul 2003
# Whom:					Oliver Eikemeier
#
# $FreeBSD$
#

PORTNAME=		openldap
PORTVERSION=		${OPENLDAP_VERSION}
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

OPENLDAP_VERSION=	2.0.27

LATEST_LINK=		${PKGNAMEPREFIX}openldap20${PKGNAMESUFFIX}
CONFLICTS=		openldap12-* \
			${PKGNAMEPREFIX}${PORTNAME}-client-2.[1-9].*

WANT_OPENLDAP_VER?=	20
.if ${WANT_OPENLDAP_VER} != 20
BROKEN=			"incompatible OpenLDAP version: ${WANT_OPENLDAP_VER}"
.endif

.if defined(CLIENT_ONLY)
OPENLDAP_PORTVERSION=	0
OPENLDAP_PKGNAMESUFFIX?=-client
OPENLDAP_PKGFILESUFX?=	.client

.if defined(USE_OPENLDAP)
.error You have `USE_OPENLDAP' defined either in your environment or in make(1) arguments.
.endif
.else
OPENLDAP_PORTVERSION=	2
OPENLDAP_PKGNAMESUFFIX?=-server
OPENLDAP_PKGFILESUFX?=

USE_OPENLDAP=		yes
CONFLICTS+=		${PKGNAMEPREFIX}${PORTNAME}-server-2.[1-9].*
.endif

#USE_OPENSSL=		yes
USE_REINPLACE=		yes
USE_LIBTOOL_VER=	13

DESCR=			${PKGDIR}/pkg-descr${OPENLDAP_PKGFILESUFX}
PLIST=			${WRKDIR}/pkg-plist
PKGINSTALL=		${WRKDIR}/pkg-install
PKGMESSAGE=		${WRKDIR}/pkg-message

LDAP_RUN_DIR?=		${DESTDIR}/var/run/openldap
LOCALSTATEDIR?=		${DESTDIR}/var/db
DATABASEDIR?=		${LOCALSTATEDIR}/openldap-ldbm
SLURPDIR?=		${LOCALSTATEDIR}/openldap-slurp

PLIST_SUB+=		LDAP_RUN_DIR=${LDAP_RUN_DIR} \
			DATABASEDIR=${DATABASEDIR} \
			SLURPDIR=${SLURPDIR} \

SED_SCRIPT=		-e 's,%%PREFIX%%,${PREFIX},g' \
			-e 's,%%LDAP_RUN_DIR%%,${LDAP_RUN_DIR},g' \
			-e 's,%%DATABASEDIR%%,${DATABASEDIR},g'

CONFIGURE_ARGS=		--with-threads \
			--with-tls=openssl \
			--enable-dynamic

.if defined(WITH_SASL)
LIB_DEPENDS+=		sasl.8:${PORTSDIR}/security/cyrus-sasl
CPPFLAGS+=		-I${LOCALBASE}/include/sasl1
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
			--enable-ldap

WITH_BDB_VER?=		3

.if ${WITH_BDB_VER} == 41
BROKEN=			"OpenLDAP 2.0 doesn't support Berkeley DB 4.1"
.elif ${WITH_BDB_VER} == 4
LIB_DEPENDS+=		db4.0:${PORTSDIR}/databases/db4
.elif ${WITH_BDB_VER} == 3
LIB_DEPENDS+=		db3.3:${PORTSDIR}/databases/db3
.else
.error WITH_BDB_VER must be 3 or 4
.endif
LIBS+=			-ldb${WITH_BDB_VER}
CPPFLAGS+=		-I${LOCALBASE}/include/db${WITH_BDB_VER}

.if defined(WITH_SHELL)
CONFIGURE_ARGS+=	--enable-shell
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

# Include tcp-wrapper support
.if !defined(WITHOUT_TCP_WRAPPERS) && exists(/usr/include/tcpd.h)
CONFIGURE_ARGS+=	--enable-wrappers
.endif

# end of client/server specific configuration
.endif

# math.h uses _REENTRANT and stdio.h uses _THREAD_SAFE, so define both.
CPPFLAGS+=		-D_REENTRANT ${PTHREAD_CFLAGS} \
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
	@${ECHO} "WITH_SASL             with (Cyrus) SASL1 support"
.else
	@${ECHO} "WITH_BDB_VER          select BerkeleyDB version (default 3)"
	@${ECHO} "WITH_SASL             with (Cyrus) SASL1 password verification"
	@${ECHO} "WITH_SHELL            with Shell backend"
	@${ECHO} "WITH_ODBC             with SQL backend"
	@${ECHO} "WITH_ODBC_TYPE        select ODBC interface (iODBC or unixODBC)"
	@${ECHO} "WITHOUT_TCP_WRAPPERS  without tcp wrapper support"
.endif
	@${ECHO}
	@${ECHO} "============================================================="
	@${ECHO}

post-patch:
	@${REINPLACE_CMD} -e 's,%LOCALSTATEDIR%/slapd\.,${LDAP_RUN_DIR}/slapd.,g' \
		${WRKSRC}/servers/slapd/slapd.conf

pre-configure:
	@${REINPLACE_CMD} -e '/^LIBTOOL=/s,\$$(top_builddir)/libtool,${LIBTOOL},g' \
		${WRKSRC}/configure

post-build:
.for script in slapd slurpd
	@${SED} ${SED_SCRIPT} ${FILESDIR}/${script}.sh >${WRKDIR}/${script}.sh
.endfor
.for text in pkg-install pkg-message
	@if [ -f ${MASTERDIR}/${text}${OPENLDAP_PKGFILESUFX} ]; then \
		${SED} ${SED_SCRIPT} ${MASTERDIR}/${text}${OPENLDAP_PKGFILESUFX} \
		>${WRKDIR}/${text}; \
	fi
.endfor

.if !defined(CLIENT_ONLY)
test: build
	@cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test
.endif

pre-install:
	@${CP} ${MASTERDIR}/pkg-plist${OPENLDAP_PKGFILESUFX} ${PLIST}
.if defined(CLIENT_ONLY)
.if !defined(NOPORTDOCS)
	@for dir in rfc drafts; do \
		${FIND} ${WRKSRC}/doc/$${dir} -maxdepth 1 -type f \
			| ${SED} -e "s,^${WRKSRC}/doc/,%%DOCSDIR%%/," \
			>>${PLIST}; \
		${ECHO_CMD} "@dirrm %%DOCSDIR%%/$${dir}" >>${PLIST}; \
	done
	@${ECHO_CMD} "@dirrm %%DOCSDIR%%" >>${PLIST}
.endif
.endif
	@if [ -f ${PKGINSTALL} ]; then \
		${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL; \
	fi

post-install:
.if defined(CLIENT_ONLY)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for dir in rfc drafts; do \
		${MKDIR} ${DOCSDIR}/$${dir}; \
		${FIND} ${WRKSRC}/doc/$${dir} -maxdepth 1 -type f \
			-exec ${INSTALL_DATA} {} ${DOCSDIR}/$${dir} \; ; \
	done
.endif
.else
.for script in slapd slurpd
	@${INSTALL_SCRIPT} ${WRKDIR}/${script}.sh ${RC_DIR}/${script}${RC_SUFX}
.endfor
	@${MKDIR} ${LDAP_RUN_DIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
