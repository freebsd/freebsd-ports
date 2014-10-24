# Created by: Brian Somers <brian@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freeradius
DISTVERSION=	2.2.5
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/freeradius/%SUBDIR%/ \
		ftp://ftp.ntua.gr/pub/net/radius/freeradius/%SUBDIR%/ \
		http://ftp.cc.uoc.gr/mirrors/ftp.freeradius.org/%SUBDIR%/ \
		http://mirrors.rit.edu/zi/
MASTER_SITE_SUBDIR=	. old
DISTNAME=	freeradius-server-${DISTVERSION}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Free RADIUS server implementation

LICENSE=	GPLv2

LIB_DEPENDS=	libgdbm.so:${PORTSDIR}/databases/gdbm \
		libltdl.so:${PORTSDIR}/devel/libltdl

LOGDIR?=	/var/log
KRB5_CONFIG?=	/usr/bin/krb5-config --libs

CONFLICTS_INSTALL=	gnu-radius-[0-9].* openradius-[0-9].* radiusd-cistron-[0-9].* \
		freeradius-mysql-[0-9].* freeradius-[^2].* freeradius3-3.*

USE_RC_SUBR=	radiusd

USES=		gmake libtool shebangfix tar:bzip2
SHEBANG_FILES=	scripts/radsqlrelay src/modules/rlm_counter/rad_counter
USE_AUTOTOOLS=	libtoolize aclocal autoconf autoheader
USE_OPENSSL=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	${CPPFLAGS}
LIBS+=		-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--libdir=${PREFIX}/${FREERADIUS_LIBDIR} \
		--localstatedir=/var \
		--disable-ltdl-install \
		--with-system-libltdl \
		--with-logdir=${LOGDIR} \
		--with-openssl-includes=${OPENSSLINC} \
		--without-rlm_eap_ikev2 \
		--without-rlm_eap_tnc \
		--without-rlm_eap2 \
		--without-rlm_opendirectory \
		--without-rlm_sql_db2 \
		--without-rlm_sql_iodbc \
		--without-rlm_sql_sqlite \
		--without-rlm_sql_sybase \
		--with-vmps

# if we're installing, place sample configs into ${EXAMPLESDIR}
MAKE_ARGS=	raddbdir="${EXAMPLESDIR}/raddb" R=${STAGEDIR}

SUB_FILES=	pkg-install pkg-message
SUB_LIST=	RADIUS_USER="${RADIUS_USER}" \
		RADIUS_GROUP="${RADIUS_GROUP}" \
		RADDB_WORK="${WRKSRC}/raddb" \
		RADDB="${PREFIX}/etc/raddb" \
		LOGDIR="${LOGDIR}" \
		LIBDIR="${PREFIX}/${FREERADIUS_LIBDIR}" \
		REQUIRE="${_REQUIRE}"

PLIST_SUB=	PORTVERSION=${DISTVERSION} LIBVER=0${PORTVERSION:C/\./0/g}
FREERADIUS_LIBDIR=	lib/freeradius-${PORTVERSION}
PLIST_SUB+=	LIBDIR="${FREERADIUS_LIBDIR}"
USE_LDCONFIG=	${PREFIX}/${FREERADIUS_LIBDIR}

# User and group to use if USER option is chosen
RADIUS_USER=	freeradius
RADIUS_GROUP=	freeradius

USERS=		${RADIUS_USER}
GROUPS=		${RADIUS_GROUP}

# Default requirements for rc script
_REQUIRE=	NETWORKING SERVERS

OPTIONS_DEFINE=	USER KERBEROS HEIMDAL HEIMDAL_PORT LDAP MYSQL \
		PGSQL UNIXODBC FIREBIRD PERL PYTHON OCI8 RUBY DHCP \
		EXPERIMENTAL UDPFROMTO DEVELOPER EDIR SSL_PORT DOCS
OPTIONS_DEFAULT=USER PERL PYTHON

DHCP_DESC=		With DHCP support (EXPERIMENTAL)
USER_DESC=		Run as user freeradius, group freeradius
HEIMDAL_DESC=		With Heimdal Kerberos support
HEIMDAL_PORT_DESC=	With Heimdal Kerberos from ports
UNIXODBC_DESC=		With unixODBC database support
FIREBIRD_DESC=		With Firebird database support (EXPERIMENTAL)
OCI8_DESC=		With Oracle support (currently experimental)
EXPERIMENTAL_DESC=	Build experimental modules
UDPFROMTO_DESC=		Compile in UDPFROMTO support
DEVELOPER_DESC=		Enable developer options
EDIR_DESC=		Enable eDirectory support (implies LDAP)
SSL_PORT_DESC=		Use OpenSSL from the ports collection

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUSER}
SUB_LIST+=	RUN_AS_USER="yes"
.else
SUB_LIST+=	RUN_AS_USER="no"
.endif

.if ${PORT_OPTIONS:MKERBEROS} || ${PORT_OPTIONS:MHEIMDAL}
.if ${PORT_OPTIONS:MHEIMDAL}
.if ${PORT_OPTIONS:MHEIMDAL_PORT}
LIB_DEPENDS+=	libkrb5.so:${PORTSDIR}/security/heimdal
.endif
CONFIGURE_ARGS+=--enable-heimdal-krb5
.else
LIB_DEPENDS+=	libkrb5.so:${PORTSDIR}/security/krb5
.endif
CONFIGURE_ARGS+=--with-rlm_krb5
.if ${PORT_OPTIONS:MHEIMDAL} && empty(PORT_OPTIONS:MHEIMDAL_PORT)
CONFIGURE_ARGS+=--with-rlm-krb5-lib-dir=/usr/lib
CONFIGURE_ARGS+=--with-rlm-krb5-include-dir=/usr/include
CONFIGURE_ENV+=	KRB5LIBS="$$(${KRB5_CONFIG})"
.else
CONFIGURE_ARGS+=--with-rlm-krb5-lib-dir=${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-rlm-krb5-include-dir=${LOCALBASE}/include
.endif
PLIST_SUB+=	KRB5=""
.else
CONFIGURE_ARGS+=--without-rlm_krb5
PLIST_SUB+=	KRB5="@comment "
.endif

.if ${PORT_OPTIONS:MEDIR}
CONFIGURE_ARGS+=--with-edir
.if empty(PORT_OPTIONS:MLDAP)
PORT_OPTIONS+=	LDAP
.endif
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	YES
CONFIGURE_ARGS+=--with-rlm_ldap
PLIST_SUB+=	LDAP=""
_REQUIRE+=	slapd
.else
CONFIGURE_ARGS+=--without-rlm_ldap
PLIST_SUB+=	LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	YES
CONFIGURE_ARGS+=--with-rlm_sql_mysql
PLIST_SUB+=	MYSQL=""
_REQUIRE+=	mysql
.else
CONFIGURE_ARGS+=--without-rlm_sql_mysql
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	YES
CONFIGURE_ARGS+=--with-rlm_sql_postgresql
PLIST_SUB+=	PGSQL=""
_REQUIRE+=	postgresql
.else
CONFIGURE_ARGS+=--without-rlm_sql_postgresql
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MUNIXODBC}
CONFIGURE_ARGS+=--with-rlm_sql_unixodbc
PLIST_SUB+=	UNIXODBC=""
LIB_DEPENDS+=	libodbc.so:${PORTSDIR}/databases/unixODBC
.else
CONFIGURE_ARGS+=--without-rlm_sql_unixodbc
PLIST_SUB+=	UNIXODBC="@comment "
.endif

.if ${PORT_OPTIONS:MFIREBIRD}
USE_FIREBIRD=	YES
CONFIGURE_ARGS+=--with-rlm_sql_firebird
PLIST_SUB+=	FIREBIRD=""
.else
CONFIGURE_ARGS+=--without-rlm_sql_firebird
PLIST_SUB+=	FIREBIRD="@comment "
.endif

# Firebird module is still experimental
.if ${PORT_OPTIONS:MFIREBIRD} && empty(PORT_OPTIONS:MEXPERIMENTAL)
EXPM=		yes
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
CONFIGURE_ARGS+=--with-rlm_perl
PLIST_SUB+=	RLMPERL=""
.else
CONFIGURE_ARGS+=--without-perl --without-rlm_perl
PLIST_SUB+=	RLMPERL="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python
CONFIGURE_ARGS+=--with-rlm_python \
		--with-rlm-python-lib-dir=${PYTHON_LIBDIR} \
		--with-rlm-python-include-dir=${PYTHON_INCLUDEDIR}
CONFIGURE_ENV+=	PYTHONBIN=${PYTHON_CMD}
PLIST_SUB+=	RLMPYTHON=""
.else
CONFIGURE_ARGS+=--without-rlm_python
PLIST_SUB+=	RLMPYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MRUBY}
IGNORE=		with ruby support leaks memory, breaks signal handling.  Please disable RUBY support
USE_RUBY=	yes
CONFIGURE_ARGS+=--with-rlm_ruby
PLIST_SUB+=	RLMRUBY=""
.else
CONFIGURE_ARGS+=--without-rlm_ruby
PLIST_SUB+=	RLMRUBY="@comment "
.endif

# rlm_ruby module is still experimental
.if ${PORT_OPTIONS:MRUBY} && empty(PORT_OPTIONS:MEXPERIMENTAL)
EXPM=		yes
.endif

.if ${PORT_OPTIONS:MDHCP}
CONFIGURE_ARGS+=--with-dhcp
.else
CONFIGURE_ARGS+=--without-dhcp
.endif

# DHCP is still experimental
.if ${PORT_OPTIONS:MDHCP} && empty(PORT_OPTIONS:MEXPERIMENTAL)
EXPM=		yes
.endif

# No SMB option yet; rlm_smb is still unbuildable
.if ${PORT_OPTIONS:MSMB}
LIB_DEPENDS=	libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient
CONFIGURE_ARGS+=--with-rlm_smb
CONFIGURE_ARGS+=--with-rlm-smb-lib-dir=${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-rlm-smb-include-dir=${LOCALBASE}/include
PLIST_SUB+=	SMB=""
.else
CONFIGURE_ARGS+=--without-rlm_smb
PLIST_SUB+=	SMB="@comment "
.endif

# SMB module is still experimental
.if ${PORT_OPTIONS:MSMB} && empty(PORT_OPTIONS:MSMB)
EXPM=		yes
.endif

# Oracle support is experimental under FreeBSD
.if ${PORT_OPTIONS:MOCI8}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-exec.c
CONFIGURE_ENV+=	ORACLE_HOME="${ORACLE_HOME}"
ORACLE_HOME?=	${LOCALBASE}/oracle8-client
BUILD_DEPENDS+=	${ORACLE_HOME}/lib/libclntst8.a:${PORTSDIR}/databases/oracle8-client
CONFIGURE_ARGS+=--with-oracle-home-dir=${ORACLE_HOME}/rdbms/demo
PLIST_SUB+=	OCI8=""
.else
CONFIGURE_ARGS+=--without-rlm_sql_oracle
PLIST_SUB+=	OCI8="@comment "
.endif

.if ${PORT_OPTIONS:MEXPERIMENTAL} || defined(EXPM)
CONFIGURE_ARGS+=--with-experimental-modules
PLIST_SUB+=	EXPM=""
.else
PLIST_SUB+=	EXPM="@comment "
.endif

.if ${PORT_OPTIONS:MDEVELOPER}
CONFIGURE_ARGS+=--enable-developer
# Turn off compiler optimisations
CFLAGS!=	${ECHO} ${CFLAGS} | ${SED} -Ee 's:-O[0-9]?[[:space:]]*::g'
.endif

# Compile in UDPFROMTO support
.if ${PORT_OPTIONS:MUDPFROMTO}
CONFIGURE_ARGS+=--with-udpfromto
.endif

.if ${PORT_OPTIONS:MSSL_PORT}
WITH_OPENSSL_PORT=yes
.endif

.if empty(PORT_OPTIONS:MDOCS)
CONFIGURE_ARGS+=--without-docdir
PLIST_SUB+=	PORTDOCS="@comment "
SUB_LIST+=	PORTDOCS="@comment "
.else
CONFIGURE_ARGS+=--with-docdir=${DOCSDIR}
PLIST_SUB+=	PORTDOCS=""
SUB_LIST+=	PORTDOCS=""
.endif

.include <bsd.port.pre.mk>

# This conditionality avoids -L/usr/lib in the radiusd build step when
# building with base system OpenSSL
.if ${OPENSSLLIB} != "/usr/lib"
CONFIGURE_ARGS+=--with-openssl-libraries=${OPENSSLLIB}
.endif

post-patch:
# never try to find execinfo.h (needed until we can enable/disable backtrace
	@${REINPLACE_CMD} -e '/execinfo.h/d' ${WRKSRC}/configure \
		${WRKSRC}/configure.in
# Patch raddb/certs/Makefile for the full path to the openssl binary (using
# ports OpenSSL if installed)
	@${REINPLACE_CMD} -E \
		-e "s:^([[:space:]])+openssl:\1${OPENSSLBASE}/bin/openssl:g" \
		${WRKSRC}/raddb/certs/Makefile
# If we're using Heimdal from base, alter the LIBS variable
.if ${PORT_OPTIONS:MHEIMDAL} && empty(PORT_OPTIONS:MHEIMDAL_PORT)
	@${REINPLACE_CMD} -e 's|LIBS|KRB5LIBS|g' ${WRKSRC}/src/modules/rlm_krb5/configure
	@${REINPLACE_CMD} -e 's|-lkrb5|$$(${KRB5_CONFIG})|g' \
		${WRKSRC}/src/modules/rlm_krb5/configure
.endif
# If DHCP is enabled, enable the DHCP dictionary
.if ${PORT_OPTIONS:MDHCP}
	@${REINPLACE_CMD} -Ee 's:^#(.+ dictionary\.dhcp)$$:\1:g' \
		${WRKSRC}/share/dictionary
.endif
# Patch scripts/Makefile not to install (unnecessary) rc.radiusd
	@${REINPLACE_CMD} -Ee 's:^(.+rc\.radiusd.+)$$:#\1:g' \
		${WRKSRC}/scripts/Makefile

pre-configure:
# Force the rebuild of some configures from configure.in, as we're patching
# the configure.in
# NOTE: ${WRKSRC}/configure is rebuilt automatically once autoconf is
# added to USE_AUTOTOOLS
	@cd ${WRKSRC}/src/modules/rlm_ldap && ${AUTOCONF} -I ${WRKSRC}
	@cd ${WRKSRC}/src/modules/rlm_sql/drivers/rlm_sql_mysql \
		&& ${AUTOCONF} -I ${WRKSRC}
	@cd ${WRKSRC}/src/modules/rlm_perl && ${AUTOCONF} -I ${WRKSRC}
	@cd ${WRKSRC}/src/modules/rlm_python && ${AUTOCONF} -I ${WRKSRC}

.include <bsd.port.post.mk>
