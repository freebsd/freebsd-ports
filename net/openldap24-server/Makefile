# New ports collection makefile for:    OpenLDAP 2.2
# Date created:		20 Sep 1998
# Whom:			Lachlan O'Dea
#
# $FreeBSD$
#

PORTNAME=	openldap
PORTVERSION=	${OPENLDAP_VERSION}.a
PORTREVISION=	1
CATEGORIES=	net databases
MASTER_SITES=	ftp://ftp.OpenLDAP.org/pub/OpenLDAP/%SUBDIR%/		\
		http://public.planetmirror.com/pub/openldap/%SUBDIR%/	\
		ftp://gd.tuwien.ac.at/infosys/network/OpenLDAP/%SUBDIR%/\
		ftp://ftp.matrix.com.br/pub/openldap/%SUBDIR%/		\
		ftp://ftp.ucr.ac.cr/pub/Unix/openldap/%SUBDIR%/		\
		ftp://ftp.ntua.gr/mirror/OpenLDAP/%SUBDIR%/		\
		ftp://ftp.dti.ad.jp/pub/net/OpenLDAP/%SUBDIR%/		\
		ftp://ftp.holywar.net/pub/OpenLDAP/%SUBDIR%/		\
		ftp://ftp.nl.uu.net/pub/unix/db/openldap/%SUBDIR%/	\
		ftp://ftp.linux.pt/pub/mirrors/OpenLDAP/%SUBDIR%/	\
		ftp://ftp.rediris.es/mirror/OpenLDAP/%SUBDIR%/	\
		ftp://sunsite.cnlab-switch.ch/mirror/OpenLDAP/%SUBDIR%/	\
		http://openldap.cdpa.nsysu.edu.tw/OpenLDAP/%SUBDIR%/	\
		ftp://ftp.u-aizu.ac.jp/pub/net/openldap/%SUBDIR%/	\
		ftp://ftp.plig.org/pub/OpenLDAP/%SUBDIR%/
MASTER_SITE_SUBDIR=	openldap-test
DISTNAME=	openldap-${OPENLDAP_VERSION}alpha
EXTRACT_SUFX=	.tgz

MAINTAINER=	eikemeier@fillmore-labs.com
COMMENT=	Open source LDAP client and server implementation

OPENLDAP_VERSION=	2.2.0

CONFLICTS=		openldap*

LATEST_LINK=		openldap2

USE_OPENSSL=		yes
USE_REINPLACE=		yes
USE_LIBTOOL_VER=	14

PKGINSTALL=		${WRKDIR}/pkg-install
PKGMESSAGE=		${WRKDIR}/pkg-message

LOCALSTATEDIR?=		/var/db
LDAP_RUN_DIR?=		/var/run/openldap

WITH_BDB_VER?=		41

CONFIGURE_ARGS=		--with-threads \
			--with-tls=openssl

SED_SCRIPT=		-e 's,%%PREFIX%%,${PREFIX},g' \
			-e 's,%%LDAP_RUN_DIR%%,${LDAP_RUN_DIR},g' \
			-e 's,%%LOCALSTATEDIR%%,${LOCALSTATEDIR},g'

.if defined(CLIENT_ONLY)
PKGNAMESUFFIX=		-client
CONFIGURE_ARGS+=	--disable-slapd
PLIST_SUB+=		SERVER="@comment " \
			SLAPI="@comment "
SED_SCRIPT+=            -e '/^%%SERVER%%/d'
.else
CONFIGURE_ARGS+=	--localstatedir=${LOCALSTATEDIR} \
			--enable-lmpasswd \
			--enable-ldbm \
			--with-ldbm-api=berkeley \
			--enable-ldap \
			--enable-meta \
			--enable-rewrite \
			--enable-null \
			--enable-monitor

.if ${WITH_BDB_VER} == 41
LIB_DEPENDS=		db41.1:${PORTSDIR}/databases/db41
CONFIGURE_ARGS+=	--enable-bdb
.elif ${WITH_BDB_VER} == 4
LIB_DEPENDS=		db4.0:${PORTSDIR}/databases/db4
CONFIGURE_ARGS+=	--disable-bdb
.elif ${WITH_BDB_VER} == 3
LIB_DEPENDS=		db3.3:${PORTSDIR}/databases/db3
CONFIGURE_ARGS+=	--disable-bdb
.else
.error WITH_BDB_VER must be 3, 4 or 41
.endif
LIBS+=			-ldb${WITH_BDB_VER}
CPPFLAGS+=		-I${LOCALBASE}/include/db${WITH_BDB_VER}

.if defined(WITH_SHELL)
CONFIGURE_ARGS+=	--enable-shell
.endif

.if defined(WITH_PERL)
.error build with Perl backend broken: <http://www.openldap.org/its/index.cgi/Development?id=2513>
USE_PERL5=	yes
CONFIGURE_ARGS+=	--enable-perl
.endif

.if defined(WITH_SASL)
LIB_DEPENDS+=		sasl2.2:${PORTSDIR}/security/cyrus-sasl2
CONFIGURE_ARGS+=	--with-cyrus-sasl \
			--enable-spasswd
.else
CONFIGURE_ARGS+=	--without-cyrus-sasl
.endif

.if defined(WITH_ODBC)
LIB_DEPENDS+=		iodbc.3:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--enable-sql
.endif

.if defined(WITH_SLAPI)
LIB_DEPENDS+=		ltdl.4:${PORTSDIR}/devel/libltdl
CONFIGURE_ARGS+=	--enable-slapi
LIBS+=			-lltdl
PLIST_SUB+=		SLAPI=""
.else
PLIST_SUB+=		SLAPI="@comment "
.endif

# Include tcp-wrapper support
.if !defined(WITHOUT_TCP_WRAPPERS) && exists(/usr/include/tcpd.h)
CONFIGURE_ARGS+=	--enable-wrappers
.endif

PLIST_SUB+=		SERVER=""
SED_SCRIPT+=		-e '/^%%SERVER%%/s,,,'
.endif

PLIST_SUB+=		LOCALSTATEDIR=${LOCALSTATEDIR} \
			LDAP_RUN_DIR=${LDAP_RUN_DIR}

# math.h uses _REENTRANT and stdio.h uses _THREAD_SAFE, so define both.
CPPFLAGS+=		-D_REENTRANT ${PTHREAD_CFLAGS} \
			-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib

CONFIGURE_TARGET=	--host=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" \
			LDFLAGS="${LDFLAGS}" \
			LIBS="${LIBS}"

INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>
.include "${FILESDIR}/manpages"

pre-everything::
	@${ECHO} "============================================================="
	@${ECHO}
	@${ECHO} "You can build ${PKGNAME} with the following options:"
	@${ECHO}
	@${ECHO} "WITH_BDB_VER          select BerkeleyDB version (default 4.1)"
	@${ECHO} "WITH_SASL             with SASL2 authorization"
	@${ECHO} "WITH_PERL             with Perl backend"
	@${ECHO} "WITH_SHELL            with Shell backend"
	@${ECHO} "WITH_ODBC             with SQL backend"
	@${ECHO} "WITH_SLAPI            with Netscape SLAPI plugin API
	@${ECHO} "WITHOUT_TCP_WRAPPERS  without tcp wrapper support"
	@${ECHO}
	@${ECHO} "============================================================="
	@${ECHO}

post-patch:
	@${REINPLACE_CMD} -e 's,%LOCALSTATEDIR%/slapd\.,${LDAP_RUN_DIR}/slapd.,g' \
		${WRKSRC}/servers/slapd/slapd.conf

post-build:
.for script in slapd.sh slurpd.sh
	@${SED} ${SED_SCRIPT} ${FILESDIR}/${script} >${WRKDIR}/${script}
.endfor
.for text in pkg-install pkg-message
	@${SED} ${SED_SCRIPT} ${.CURDIR}/${text} >${WRKDIR}/${text}
.endfor

post-install:
.if !defined(CLIENT_ONLY)
	@${INSTALL_SCRIPT} ${WRKDIR}/slapd.sh ${WRKDIR}/slurpd.sh ${PREFIX}/etc/rc.d
	@${MKDIR} ${LDAP_RUN_DIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for dir in rfc drafts; do \
		${MKDIR} ${DOCSDIR}/$${dir}; \
		${FIND} ${WRKSRC}/doc/$${dir} -maxdepth 1 -type f \
			-exec ${INSTALL_DATA} {} ${DOCSDIR}/$${dir} \; -print \
			| ${SED} -e "s,^${WRKSRC}/doc/,${DOCSDIR:S,^${PREFIX}/,,}/," \
			>>${TMPPLIST}; \
		${ECHO_CMD} "@dirrm ${DOCSDIR:S,^${PREFIX}/,,}/$${dir}" >>${TMPPLIST}; \
	done
	@${ECHO_CMD} "@dirrm ${DOCSDIR:S,^${PREFIX}/,,}" >>${TMPPLIST}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
