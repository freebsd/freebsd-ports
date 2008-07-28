# New ports collection makefile for:    freeradius
# Date created:         May 9 2002
# Whom:                 Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freeradius
DISTVERSION=	2.0.5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/freeradius/%SUBDIR%/ \
		ftp://ftp.ntua.gr/pub/net/radius/freeradius/%SUBDIR%/ \
		ftp://ftp.uk.freeradius.org/pub/radius/%SUBDIR%/ \
		http://ftp.cc.uoc.gr/mirrors/ftp.freeradius.org/%SUBDIR%/ \
		http://freeradius.portal-to-web.de/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
DISTNAME=	freeradius-server-${DISTVERSION}

MAINTAINER=	david@wood2.org.uk
COMMENT=	A free RADIUS server implementation

RUN_DEPENDS=	gmake:${PORTSDIR}/devel/gmake
LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

USE_BZIP2=	yes
WANT_PERL=	yes

LOGDIR?=	/var/log

CONFLICTS=	gnu-radius-[0-9].* openradius-[0-9].* radiusd-cistron-[0-9].* \
		freeradius-mysql-[0-9].* freeradius-[013-9].*

USE_RC_SUBR=	radiusd.sh
USE_AUTOTOOLS=	libltdl:15 libtool:15 autoconf:261
USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_PYTHON=	yes
MAKE_ARGS+=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

PLIST_SUB=	PORTVERSION=${DISTVERSION}

OPTIONS=	USER		"Run as user freeradius, group freeradius" on \
		KERBEROS	"With Kerberos support" off \
		HEIMDAL		"With Heimdal Kerberos support" off \
		LDAP		"With LDAP database support" off \
		MYSQL		"With MySQL database support" off \
		PGSQL		"With PostgreSQL database support" off \
		FIREBIRD	"With Firebird database support (EXPERIMENTAL)" off \
		SNMP		"With SNMP support" off \
		EXPERIMENTAL	"Build experimental modules (including DHCP)" off

.include <bsd.port.pre.mk>

# Default requirements for rc script
_REQUIRE=	NETWORKING SERVERS

# User and group to use if USER is set
USER=	freeradius
GROUP=	freeradius

FREERADIUS_LIBDIR=	lib/freeradius-${PORTVERSION}
PLIST_SUB+=	LIBDIR="${FREERADIUS_LIBDIR}"
USE_LDCONFIG=	${PREFIX}/${FREERADIUS_LIBDIR}

CONFIGURE_ARGS=	--quiet \
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
CONFIGURE_ARGS+=--with-rlm-python-lib-dir=${PYTHON_LIBDIR} \
		--with-rlm-python-include-dir=${PYTHON_INCLUDEDIR} \
		--without-rlm_eap_ikev2 \
		--without-rlm_eap_tnc \
		--without-rlm_eap2 \
		--without-rlm_opendirectory \
		--without-rlm_sql_db2 \
		--without-rlm_sql_iodbc \
		--without-rlm_sql_oracle \
		--without-rlm_sql_sqlite \
		--without-rlm_sql_sybase \
		--without-rlm_sql_unixodbc \
		--with-vmps

.if ${ARCH} == amd64
CONFIGURE_ARGS+=	--with-pic
.endif

# Credentials for WITH_USER are RADIUS_USER, RADIUS_UID, RADIUS_GECOS,
# RADIUS_HOME, RADIUS_SHELL, RADIUS_GROUP and RADIUS_GID.

# Parse ${PORTSDIR}/UIDs and GIDs for the defaults
USER!=	${GREP} -E '^${USER}:' ${PORTSDIR}/UIDs | \
		${SED} -Ee 's/^([^:]*):([^:]*):([^:]*):([^:]*)::0:0:([^:]*):([^:]*):([^:]*)$$/USER="\1" UID="\3" GECOS="\5" HOME="\6" SHELL="\7"/'
GROUP!=	${GREP} -E '^${GROUP}:' ${PORTSDIR}/GIDs | \
		${SED} -Ee 's/^([^:]*):([^:]*):([^:]*):$$/GROUP="\1" GID="\3"/'

# Apply the defaults where necessary
RADIUS_USER?=	${USER:MUSER*:C/^[^=]*=\"([^\"]*)\"$/\1/}
RADIUS_UID?=	${USER:MUID*:C/^[^=]*=\"([^\"]*)\"$/\1/}
RADIUS_GECOS?=	${USER:MGECOS*:C/^[^=]*=\"([^\"]*)\"$/\1/}
RADIUS_HOME?=	${USER:MHOME*:C/^[^=]*=\"([^\"]*)\"$/\1/}
RADIUS_SHELL?=	${USER:MSHELL*:C/^[^=]*=\"([^\"]*)\"$/\1/}
RADIUS_GROUP?=	${GROUP:MGROUP*:C/^[^=]*=\"([^\"]*)\"$/\1/}
RADIUS_GID?=	${GROUP:MGID*:C/^[^=]*=\"([^\"]*)\"$/\1/}

SUB_LIST+=	USER="${RADIUS_USER}" \
		UID="${RADIUS_UID}" \
		GECOS="${RADIUS_GECOS}" \
		HOME="${RADIUS_HOME}" \
		SHELL="${RADIUS_SHELL}" \
		GROUP="${RADIUS_GROUP}" \
		GID="${RADIUS_GID}" \
		RADDB_WORK="${WRKSRC}/raddb" \
		RADDB="${PREFIX}/etc/raddb" \
		LOGDIR="${LOGDIR}" \
		RC_SUBR_SUFFIX="${RC_SUBR_SUFFIX}"
SUB_FILES+=	pkg-install pkg-deinstall pkg-message
.ifdef(WITH_USER)
SUB_LIST+=	RUN_AS_USER="yes"
.else
SUB_LIST+=	RUN_AS_USER="no"
.endif

.if defined(WITH_HEIMDAL) && !defined(WITH_KERBEROS)
WITH_KERBEROS=	yes
.endif

.ifdef(WITH_KERBEROS)
.ifdef(WITH_HEIMDAL)
LIB_DEPENDS+=	krb5.23:${PORTSDIR}/security/heimdal
CONFIGURE_ARGS+=--enable-heimdal-krb5
.else
LIB_DEPENDS+=	krb5.3:${PORTSDIR}/security/krb5
.endif
CONFIGURE_ARGS+=--with-rlm-krb5-lib-dir=${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-rlm-krb5-include-dir=${LOCALBASE}/include
PLIST_SUB+=	KRB5=""
.else
CONFIGURE_ARGS+=--without-rlm_krb5
PLIST_SUB+=	KRB5="@comment "
.endif

.ifdef(WITH_LDAP)
USE_OPENLDAP=	YES
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
WITH_EXPERIMENTAL=	yes
.endif

.ifdef(WITH_SNMP)
LIB_DEPENDS+=	snmp.4:${PORTSDIR}/net-mgmt/net-snmp4
.else
CONFIGURE_ARGS+=--without-snmp
.endif

.ifdef(WITH_EXPERIMENTAL)
CONFIGURE_ARGS+=--with-experimental-modules --with-dhcp
PLIST_SUB+=	EXPM=""
.else
PLIST_SUB+=	EXPM="@comment "
.endif

.ifdef(WITH_DEVELOPER)
CONFIGURE_ARGS+=--enable-developer
# Turn off compiler optimisations
CFLAGS!=	${ECHO} ${CFLAGS} | ${SED} -Ee 's:-O[0-9]?[[:space:]]*::g'
.endif

# NOPERL has been removed from OPTIONS. It is a nasty hack as it doesn't
# properly remove the dependency on perl. The main configure.in should be
# patched so that the perl detection test fails to make this work properly,
# though that configure run (at least in 2.0.0) only looks for perl to issue
# a warning about Simultaneous-Use and checkrad.pl maybe not working without
# perl.
# Leave WITH_NOPERL as a knob for anyone that really wants it - or for
# a proper fix in the future.
.ifdef(WITH_NOPERL)
CONFIGURE_ARGS+=--without-rlm_perl
PLIST_SUB+=	RLMPERL="@comment "
.else
USE_PERL5=	yes
CONFIGURE_ARGS+=--with-rlm_perl
PLIST_SUB+=	RLMPERL=""
.endif

MAN1=		radclient.1 radeapclient.1 radlast.1 radtest.1 radwho.1 \
		radzap.1
MAN5=		acct_users.5 clients.conf.5 dictionary.5 radiusd.conf.5 \
		radrelay.conf.5 rlm_acct_unique.5 rlm_always.5 \
		rlm_attr_filter.5 rlm_attr_rewrite.5 rlm_chap.5 rlm_counter.5 \
		rlm_detail.5 rlm_digest.5 rlm_expr.5 rlm_files.5 rlm_mschap.5 \
		rlm_pap.5 rlm_passwd.5 rlm_policy.5 rlm_realm.5 rlm_sql.5 \
		rlm_sql_log.5 rlm_unix.5 unlang.5 users.5
MAN8=		radiusd.8 radrelay.8 radsqlrelay.8 radwatch.8 \
		rlm_ippool_tool.8

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
# Clean up after the last operation (so as not to get unwanted files in raddb)
	@${FIND} -E ${WRKSRC}/raddb/certs -regex '.*/bootstrap\.(orig|bak)$$' \
		-delete

pre-configure:
# Replace -pthread with ${PTHREAD_LIBS} in configure(.in) files
	@${FIND} -E ${WRKSRC} -regex '.*/configure(\.in)?$$' -exec \
		${REINPLACE_CMD} -e "s:-pthread:${PTHREAD_LIBS}:g" {} \;
# Force the rebuild of some configures from configure.in, as we're patching
# the configure.in
# NOTE: ${WRKSRC}/configure is rebuilt automatically once autoconf:261 is
# added to USE_AUTOTOOLS
	@cd ${WRKSRC}/src/modules/rlm_ldap && ${AUTOCONF} -I ${WRKSRC}
	@cd ${WRKSRC}/src/modules/rlm_sql/drivers/rlm_sql_mysql \
		&& ${AUTOCONF} -I ${WRKSRC}
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
