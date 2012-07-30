# New ports collection makefile for:    freeradius
# Date created:         May 9 2002
# Whom:                 Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#
# $Id$
#

PORTNAME=	freeradius
DISTVERSION=	2.1.12
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/freeradius/%SUBDIR%/ \
		ftp://ftp.ntua.gr/pub/net/radius/freeradius/%SUBDIR%/ \
		ftp://ftp.uk.freeradius.org/pub/radius/%SUBDIR%/ \
		http://ftp.cc.uoc.gr/mirrors/ftp.freeradius.org/%SUBDIR%/ \
		http://freeradius.portal-to-web.de/%SUBDIR%/ \
		http://mirrors.rit.edu/zi/
MASTER_SITE_SUBDIR=	. old
DISTNAME=	freeradius-server-${DISTVERSION}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	A free RADIUS server implementation

LICENSE=	GPLv2

LIB_DEPENDS=	gdbm:${PORTSDIR}/databases/gdbm

LOGDIR?=	/var/log
KRB5_CONFIG?=	/usr/bin/krb5-config --libs

CONFLICTS=	gnu-radius-[0-9].* openradius-[0-9].* radiusd-cistron-[0-9].* \
		freeradius-mysql-[0-9].* freeradius-[013-9].*

USE_RC_SUBR=	radiusd.sh
USE_AUTOTOOLS=	libltdl libtool autoconf
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_OPENSSL=	yes
MAKE_ARGS+=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	PORTVERSION=${DISTVERSION}

OPTIONS=	USER		"Run as user freeradius, group freeradius" on \
		KERBEROS	"With Kerberos support" off \
		HEIMDAL		"With Heimdal Kerberos support" off \
		HEIMDAL_PORT	"Use Heimdal Kerberos from ports" off \
		HEIMDAL_PATCH	"Enhanced Heimdal support (specify SPN/keytab)" off \
		LDAP		"With LDAP database support" off \
		MYSQL		"With MySQL database support" off \
		PGSQL		"With PostgreSQL database support" off \
		UNIXODBC	"With unixODBC database support" off \
		FIREBIRD	"With Firebird database support (EXPERIMENTAL)" off \
		PERL		"With Perl support" on \
		PYTHON		"With Python support" on \
		OCI8		"With Oracle support (currently experimental)" off \
		RUBY		"With Ruby support (EXPERIMENTAL)" off \
		DHCP		"With DHCP support (EXPERIMENTAL)" off \
		EXPERIMENTAL	"Build experimental modules" off \
		UDPFROMTO	"Compile in UDPFROMTO support" off

.include <bsd.port.options.mk>

# Default requirements for rc script
_REQUIRE=	NETWORKING SERVERS

.ifdef(WITH_USER)
SUB_LIST+=	RUN_AS_USER="yes"
.else
SUB_LIST+=	RUN_AS_USER="no"
.endif

# User and group to use if USER option is chosen
RADIUS_USER=	freeradius
RADIUS_GROUP=	freeradius

USERS=		${RADIUS_USER}
GROUPS=		${RADIUS_GROUP}

CONFIGURE_ARGS+=	--with-system-libtool --with-system-libltdl --disable-ltdl-install

.if defined(WITH_HEIMDAL) && !defined(WITH_KERBEROS)
WITH_KERBEROS=	yes
.endif

.ifdef(WITH_KERBEROS)
.ifdef(WITH_HEIMDAL)
.ifdef(WITH_HEIMDAL_PORT)
LIB_DEPENDS+=	krb5:${PORTSDIR}/security/heimdal
.endif
CONFIGURE_ARGS+=--enable-heimdal-krb5
.else
LIB_DEPENDS+=	krb5:${PORTSDIR}/security/krb5
.endif
CONFIGURE_ARGS+=--with-rlm_krb5
.if defined (WITH_HEIMDAL) && !defined(WITH_HEIMDAL_PORT)
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

# Patch rlm_krb5.c to add Heimdal support for specifying keytab+SPN
.ifdef(WITH_HEIMDAL_PATCH)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src__modules__rlm_krb5__rlm_krb5.c
.endif

.ifdef(WITH_LDAP)
USE_OPENLDAP=	YES
CONFIGURE_ARGS+=--with-rlm_ldap
PLIST_SUB+=	LDAP=""
_REQUIRE+=	slapd
.else
CONFIGURE_ARGS+=--without-rlm_ldap
PLIST_SUB+=	LDAP="@comment "
.endif

.ifdef(WITH_MYSQL)
USE_MYSQL=	YES
CONFIGURE_ARGS+=--with-rlm_sql_mysql
PLIST_SUB+=	MYSQL=""
_REQUIRE+=	mysql
.else
CONFIGURE_ARGS+=--without-rlm_sql_mysql
PLIST_SUB+=	MYSQL="@comment "
.endif

.ifdef(WITH_PGSQL)
USE_PGSQL=	YES
CONFIGURE_ARGS+=--with-rlm_sql_postgresql
PLIST_SUB+=	PGSQL=""
_REQUIRE+=	postgresql
.else
CONFIGURE_ARGS+=--without-rlm_sql_postgresql
PLIST_SUB+=	PGSQL="@comment "
.endif

.ifdef(WITH_UNIXODBC)
CONFIGURE_ARGS+=--with-rlm_sql_unixodbc
PLIST_SUB+=	UNIXODBC=""
LIB_DEPENDS+=	odbc:${PORTSDIR}/databases/unixODBC
.else
CONFIGURE_ARGS+=--without-rlm_sql_unixodbc
PLIST_SUB+=	UNIXODBC="@comment "
.endif

.ifdef(WITH_FIREBIRD)
USE_FIREBIRD=	YES
CONFIGURE_ARGS+=--with-rlm_sql_firebird
PLIST_SUB+=	FIREBIRD=""
.else
CONFIGURE_ARGS+=--without-rlm_sql_firebird
PLIST_SUB+=	FIREBIRD="@comment "
.endif

# Firebird module is still experimental
.if defined(WITH_FIREBIRD) && !defined(WITH_EXPERIMENTAL)
EXPM=		yes
.endif

.ifdef(WITH_PERL)
USE_PERL5=	yes
CONFIGURE_ARGS+=--with-rlm_perl
PLIST_SUB+=	RLMPERL=""
.else
CONFIGURE_ARGS+=--without-perl --without-rlm_perl
PLIST_SUB+=	RLMPERL="@comment "
.endif

.ifdef(WITH_PYTHON)
USE_PYTHON=	yes
CONFIGURE_ARGS+=--with-rlm_python \
		--with-rlm-python-lib-dir=${PYTHON_LIBDIR} \
		--with-rlm-python-include-dir=${PYTHON_INCLUDEDIR}
PLIST_SUB+=	RLMPYTHON=""
.else
CONFIGURE_ARGS+=--without-rlm_python
PLIST_SUB+=	RLMPYTHON="@comment "
.endif

.ifdef(WITH_RUBY)
USE_RUBY=	yes
CONFIGURE_ARGS+=--with-rlm_ruby
PLIST_SUB+=	RLMRUBY=""
.else
CONFIGURE_ARGS+=--without-rlm_ruby
PLIST_SUB+=	RLMRUBY="@comment "
.endif

# rlm_ruby module is still experimental
.if defined(WITH_RUBY) && !defined(WITH_EXPERIMENTAL)
EXPM=		yes
.endif

.ifdef(WITH_DHCP)
CONFIGURE_ARGS+=--with-dhcp
.else
CONFIGURE_ARGS+=--without-dhcp
.endif

# DHCP is still experimental
.if defined(WITH_DHCP) && !defined(WITH_EXPERIMENTAL)
EXPM=		yes
.endif

# No SMB option yet; rlm_smb is still unbuildable
.ifdef(WITH_SMB)
LIB_DEPENDS=	smbclient:${PORTSDIR}/net/samba-libsmbclient
CONFIGURE_ARGS+=--with-rlm_smb
CONFIGURE_ARGS+=--with-rlm-smb-lib-dir=${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-rlm-smb-include-dir=${LOCALBASE}/include
PLIST_SUB+=	SMB=""
.else
CONFIGURE_ARGS+=--without-rlm_smb
PLIST_SUB+=	SMB="@comment "
.endif

# SMB module is still experimental
.if defined(WITH_SMB) && !defined(WITH_EXPERIMENTAL)
EXPM=		yes
.endif

# Oracle support is experimental under FreeBSD
.ifdef(WITH_OCI8)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-exec.c
CONFIGURE_ENV=	ORACLE_HOME="${ORACLE_HOME}"
ORACLE_HOME?=	${LOCALBASE}/oracle8-client
BUILD_DEPENDS+=	${ORACLE_HOME}/lib/libclntst8.a:${PORTSDIR}/databases/oracle8-client
CONFIGURE_ARGS+=--with-oracle-home-dir=${ORACLE_HOME}/rdbms/demo
PLIST_SUB+=	OCI8=""
.else
CONFIGURE_ARGS+=--without-rlm_sql_oracle
PLIST_SUB+=	OCI8="@comment "
.endif

.if defined(EXPM) || defined(WITH_EXPERIMENTAL)
CONFIGURE_ARGS+=--with-experimental-modules
PLIST_SUB+=	EXPM=""
.else
PLIST_SUB+=	EXPM="@comment "
.endif

.ifdef(WITH_DEVELOPER)
CONFIGURE_ARGS+=--enable-developer
# Turn off compiler optimisations
CFLAGS!=	${ECHO} ${CFLAGS} | ${SED} -Ee 's:-O[0-9]?[[:space:]]*::g'
.endif

# Compile in UDPFROMTO support
.ifdef(WITH_UDPFROMTO)
CONFIGURE_ARGS+=--with-udpfromto
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" && ${OSVERSION} < 700000
BROKEN=		Does not build on sparc64-6
.endif

FREERADIUS_LIBDIR=	lib/freeradius-${PORTVERSION}
PLIST_SUB+=	LIBDIR="${FREERADIUS_LIBDIR}"
USE_LDCONFIG=	${PREFIX}/${FREERADIUS_LIBDIR}

CONFIGURE_ARGS+=--quiet \
		--prefix=${PREFIX} \
		--libdir=${PREFIX}/${FREERADIUS_LIBDIR} \
		--localstatedir=/var \
		--with-system-libtool
.ifdef(NOPORTDOCS)
CONFIGURE_ARGS+=--without-docdir
PLIST_SUB+=	PORTDOCS="@comment "
SUB_LIST+=	PORTDOCS="@comment "
.else
CONFIGURE_ARGS+=--with-docdir=${DOCSDIR}
PLIST_SUB+=	PORTDOCS=""
SUB_LIST+=	PORTDOCS=""
.endif
CONFIGURE_ARGS+=--with-logdir=${LOGDIR} \
		--with-openssl-includes=${OPENSSLINC}
# This conditionality avoids -L/usr/lib in the radiusd build step when
# building with base system OpenSSL
.if ${OPENSSLLIB} != "/usr/lib"
CONFIGURE_ARGS+=--with-openssl-libraries=${OPENSSLLIB}
.endif
CONFIGURE_ARGS+=--without-rlm_eap_ikev2 \
		--without-rlm_eap_tnc \
		--without-rlm_eap2 \
		--without-rlm_opendirectory \
		--without-rlm_sql_db2 \
		--without-rlm_sql_iodbc \
		--without-rlm_sql_sqlite \
		--without-rlm_sql_sybase \
		--with-vmps

.if ${ARCH} == amd64
CONFIGURE_ARGS+=	--with-pic
.endif

SUB_LIST+=	RADIUS_USER="${RADIUS_USER}" \
		RADIUS_GROUP="${RADIUS_GROUP}" \
		RADDB_WORK="${WRKSRC}/raddb" \
		RADDB="${PREFIX}/etc/raddb" \
		LOGDIR="${LOGDIR}" \
		LIBDIR="${PREFIX}/${FREERADIUS_LIBDIR}"
SUB_FILES+=	pkg-install pkg-deinstall pkg-message

MAN1=		radclient.1 radeapclient.1 radlast.1 radtest.1 radwho.1 \
		radzap.1 smbencrypt.1
MAN5=		acct_users.5 clients.conf.5 dictionary.5 radiusd.conf.5 \
		radrelay.conf.5 rlm_acct_unique.5 rlm_always.5 \
		rlm_attr_filter.5 rlm_attr_rewrite.5 rlm_chap.5 rlm_counter.5 \
		rlm_detail.5 rlm_digest.5 rlm_expr.5 rlm_files.5 rlm_mschap.5 \
		rlm_pap.5 rlm_passwd.5 rlm_policy.5 rlm_realm.5 rlm_sql.5 \
		rlm_sql_log.5 rlm_unix.5 unlang.5 users.5 checkrad.5
MAN8=		radiusd.8 radmin.8 raddebug.8 radrelay.8 radsqlrelay.8 \
		radwatch.8 rlm_ippool_tool.8 radconf2xml.8 radcrypt.8 \
		radsniff.8 rlm_dbm_cat.8 rlm_dbm_parse.8

SUB_LIST+=	REQUIRE="${_REQUIRE}"

post-patch:
# Patch Makefile / Makefile.in throughout the source tree to install raddb
# contents in ${EXAMPLESDIR}/raddb rather than the raddbdir from configure
	@${FIND} -E ${WRKSRC} -regex '.*/Makefile(\.in)?$$' -exec \
		${REINPLACE_CMD} -e "s:\$$(R)\$$(raddbdir):${EXAMPLESDIR}/raddb:g" {} \;
# Clean up after the last operation (so as not to get unwanted files when installing doc/)
	@${FIND} -E ${WRKSRC} -regex '.*/Makefile(\.in)?\.(orig|bak)$$' -delete
# Patch raddb/certs/bootstrap to use gmake instead of make
	@${REINPLACE_CMD} -Ee "s:^make:${GMAKE}:" \
		${WRKSRC}/raddb/certs/bootstrap
# Patch raddb/certs/Makefile for the full path to the openssl binary (using
# ports OpenSSL if installed)
	@${REINPLACE_CMD} -E \
		-e "s:^([[:space:]])+openssl:\1${OPENSSLBASE}/bin/openssl:g" \
		${WRKSRC}/raddb/certs/Makefile
# Clean up after the last two operations (so as not to get unwanted files in
# raddb)
	@${FIND} -E ${WRKSRC}/raddb/certs \
		-regex '.*/(bootstrap|Makefile)\.(orig|bak)$$' \
		-delete
# If we're using Heimdal from base, alter the LIBS variable
.if defined(WITH_HEIMDAL) && !defined(WITH_HEIMDAL_PORT)
	@${REINPLACE_CMD} -e 's|LIBS|KRB5LIBS|g' ${WRKSRC}/src/modules/rlm_krb5/configure
	@${REINPLACE_CMD} -e 's|-lkrb5|$$(${KRB5_CONFIG})|g' \
		${WRKSRC}/src/modules/rlm_krb5/configure
.endif
# If DHCPis enabled, enable the DHCP dictionary
.ifdef(WITH_DHCP)
	@${REINPLACE_CMD} -Ee 's:^#(.+ dictionary\.dhcp)$$:\1:g' \
		${WRKSRC}/share/dictionary
# Clean up (so as not to get an unwanted file in share)
	@${FIND} -E ${WRKSRC}/share \
		-regex '.*/dictionary\.(orig|bak)$$' \
		-delete
.endif
# Fix PgSQL statement
	@${REINPLACE_CMD} -i '' -e 's|ius.rad||' \
		${WRKSRC}/raddb/sql/postgresql/admin.sql
# Patch scripts/Makefile not to install (unnecessary) rc.radiusd
	@${REINPLACE_CMD} -Ee 's:^(.+rc\.radiusd.+)$$:#\1:g' \
		${WRKSRC}/scripts/Makefile

pre-configure:
# Replace -pthread with ${PTHREAD_LIBS} in configure(.in) files
	@${FIND} -E ${WRKSRC} -regex '.*/configure(\.in)?$$' -exec \
		${REINPLACE_CMD} -e "s:-pthread:${PTHREAD_LIBS}:g" {} \;
# Force the rebuild of some configures from configure.in, as we're patching
# the configure.in
# NOTE: ${WRKSRC}/configure is rebuilt automatically once autoconf is
# added to USE_AUTOTOOLS
	@cd ${WRKSRC}/src/modules/rlm_ldap && ${AUTOCONF} -I ${WRKSRC}
	@cd ${WRKSRC}/src/modules/rlm_sql/drivers/rlm_sql_mysql \
		&& ${AUTOCONF} -I ${WRKSRC}
	@cd ${WRKSRC}/src/modules/rlm_perl && ${AUTOCONF} -I ${WRKSRC}
	@cd ${WRKSRC}/src/modules/rlm_python && ${AUTOCONF} -I ${WRKSRC}

pre-install:
# Run pkg-install PRE-INSTALL
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} \
		PRE-INSTALL

post-install:
# If ${PREFIX}/etc/raddb isn't a directory (or a symlink), make a copy
# of ${EXAMPLESDIR}/raddb as ${PREFIX}/etc/raddb, then bootstrap the
# certificates
	@if ! [ -d ${PREFIX}/etc/raddb -o -L ${PREFIX}/etc/raddb ]; then \
		${CP} -RP ${EXAMPLESDIR}/raddb ${PREFIX}/etc/raddb; \
		${ECHO_MSG} '===> Bootstrapping default certificates, please wait...'; \
		${PREFIX}/etc/raddb/certs/bootstrap >/dev/null 2>&1; \
	fi
# Set ${PREFIX}/etc/raddb and all the files and folders in it to g-w,o-rwx
# (FreeRADIUS will probably complain if this is not done)
	@${CHMOD} -R g-w,o-rwx ${PREFIX}/etc/raddb
# Run pkg-install POST-INSTALL
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} \
		POST-INSTALL
# Display the contents of pkg-message
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
