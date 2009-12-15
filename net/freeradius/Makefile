# New ports collection makefile for:    freeradius
# Date created:         May 9 2002
# Whom:                 Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freeradius
PORTVERSION?=	1.1.8
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/freeradius/%SUBDIR%/ \
		ftp://ftp.ntua.gr/pub/net/radius/freeradius/%SUBDIR%/ \
		ftp://ftp.uk.freeradius.org/pub/radius/%SUBDIR%/ \
		http://ftp.cc.uoc.gr/mirrors/ftp.freeradius.org/%SUBDIR%/ \
		http://freeradius.portal-to-web.de/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old

MAINTAINER?=	david@wood2.org.uk
COMMENT?=	A free RADIUS server implementation

USE_BZIP2=	yes
WANT_PERL=	yes

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

LOGDIR?=	/var/log

# If FREERADIUS_SLAVE_MYSQL is defined, we want to build the
# freeradius-mysql slave port

CONFLICTS=	gnu-radius-[0-9].* openradius-[0-9].* radiusd-cistron-[0-9].*
.ifdef(FREERADIUS_SLAVE_MYSQL)
CONFLICTS+=	freeradius-[0-9].* freeradius-mysql-[02-9].*
PKGNAMESUFFIX=	-mysql
.else
CONFLICTS+=	freeradius-mysql-[0-9].* freeradius-[02-9].*
.endif
NO_LATEST_LINK=	yes

USE_RC_SUBR=	radiusd.sh
USE_AUTOTOOLS=	libltdl:22 libtool:22 autoconf:262
USE_GMAKE=	yes
USE_OPENSSL=	yes
MAKE_ARGS+=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS=	KERBEROS	"With Kerberos support" off \
		HEIMDAL		"With Heimdal Kerberos support" off \
		LDAP		"With LDAP database support" off
.ifndef(FREERADIUS_SLAVE_MYSQL)
OPTIONS+=	MYSQL		"With MySQL database support" off
.endif
OPTIONS+=	PGSQL		"With PostgreSQL database support" off \
		UNIXODBC	"With unixODBC database support" off \
		FIREBIRD	"With Firebird database support (EXPERIMENTAL)" off \
		SNMP		"With SNMP support" off \
		EDIR		"With Novell eDirectory support" off \
		NOPERL		"Do not require perl (use only if necessary)" off \
		EXPERIMENTAL	"Build experimental modules" off

.include <bsd.port.pre.mk>

# Default requirements for rc script
_REQUIRE=	NETWORKING SERVERS

.ifdef(FREERADIUS_SLAVE_MYSQL)
WITH_MYSQL=	yes
.endif

CONFIGURE_ARGS=	--quiet \
		--prefix=${PREFIX} \
		--localstatedir=/var \
		--with-system-libtool
.ifdef(NOPORTDOCS)
CONFIGURE_ARGS+=--without-docdir
PLIST_SUB+=	PORTDOCS="@comment "
.else
CONFIGURE_ARGS+=--with-docdir=${DOCSDIR}
PLIST_SUB+=	PORTDOCS=""
.endif
CONFIGURE_ARGS+=--with-logdir=${LOGDIR} \
		--with-large-files \
		--with-openssl-includes=${OPENSSLINC}
# This conditionality avoids -L/usr/lib in the radiusd build step when
# building with base system OpenSSL
.if ${OPENSSLLIB} != "/usr/lib"
CONFIGURE_ARGS+=--with-openssl-libraries=${OPENSSLLIB}
.endif
CONFIGURE_ARGS+=--without-rlm_sql_db2 \
		--without-rlm_sql_freetds \
		--without-rlm_sql_iodbc \
		--without-rlm_sql_oracle \
		--without-rlm_sql_sybase

.if ${ARCH} == amd64
CONFIGURE_ARGS+=	--with-pic
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

.if defined(WITH_EDIR) && !defined(WITH_LDAP)
WITH_LDAP=	yes
.endif

.ifdef(WITH_LDAP)
USE_OPENLDAP=	YES
PLIST_SUB+=	LDAP=""
_REQUIRE+=	slapd
.else
CONFIGURE_ARGS+=--without-rlm_ldap
PLIST_SUB+=	LDAP="@comment "
.endif

.ifdef(WITH_EDIR)
CONFIGURE_ARGS+=--with-edir
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
LIB_DEPENDS+=	odbc.1:${PORTSDIR}/databases/unixODBC
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
WITH_EXPERIMENTAL=	yes
.endif

.ifdef(WITH_SNMP)
LIB_DEPENDS+=	snmp.4:${PORTSDIR}/net-mgmt/net-snmp4
.else
CONFIGURE_ARGS+=--without-snmp
.endif

.ifdef(WITH_EXPERIMENTAL)
USE_PYTHON=	yes
# hack to get the dependency
.include "${PORTSDIR}/Mk/bsd.python.mk"
CONFIGURE_ARGS+=--with-experimental-modules
PLIST_SUB+=	EXPM=""
.else
PLIST_SUB+=	EXPM="@comment "
.endif

.ifdef(WITH_DEVELOPER)
CONFIGURE_ARGS+=--enable-developer
.endif

.ifdef(WITH_NOPERL)
CONFIGURE_ARGS+=--without-rlm_perl
PLIST_SUB+=	RLMPERL="@comment "
.else
USE_PERL5=	yes
CONFIGURE_ARGS+=--with-rlm_perl
PLIST_SUB+=	RLMPERL=""
.endif

USE_LDCONFIG=	yes

MAN1=		radclient.1 radeapclient.1 radlast.1 radtest.1 radwho.1 \
		radzap.1
MAN5=		acct_users.5 clients.5 clients.conf.5 dictionary.5 naslist.5 \
		radiusd.conf.5 rlm_acct_unique.5 rlm_always.5 \
		rlm_attr_filter.5 rlm_attr_rewrite.5 rlm_chap.5 rlm_counter.5 \
		rlm_detail.5 rlm_expr.5 rlm_files.5 rlm_mschap.5 rlm_pap.5 \
		rlm_passwd.5 rlm_realm.5 rlm_sql.5 rlm_sql_log.5 rlm_unix.5 \
		users.5
MAN8=		radiusd.8 radrelay.8 radsqlrelay.8 radwatch.8 rlm_ippool_tool.8

SUB_LIST+=	REQUIRE="${_REQUIRE}"

post-patch:
# Patch Makefile / Makefile.in throughout the source tree to install raddb
# contents in ${EXAMPLESDIR}/raddb rather than the raddbdir from configure
	@${FIND} -E ${WRKSRC} -regex '.*/Makefile(\.in)?$$' -exec \
		${REINPLACE_CMD} -e "s:\$$(R)\$$(raddbdir):${EXAMPLESDIR}/raddb:g" {} \;
# Clean up after the last operation (so as not to get unwanted files when installing doc/)
	@${FIND} -E ${WRKSRC} -regex '.*/Makefile(\.in)?\.(orig|bak)$$' -delete

pre-configure:
# Replace -pthread with ${PTHREAD_LIBS} in configure(.in) files
	@${FIND} -E ${WRKSRC} -regex '.*/configure(\.in)?$$' -exec \
		${REINPLACE_CMD} -e "s:-pthread:${PTHREAD_LIBS}:g" {} \;
# Force the rebuild of some configures from configure.in, as we're patching
# the configure.in
# NOTE: ${WRKSRC}/configure is rebuilt automatically once autoconf:262 is
# added to USE_AUTOTOOLS
	@cd ${WRKSRC}/src/modules/rlm_ldap && ${AUTOCONF} -I ${WRKSRC}
	@cd ${WRKSRC}/src/modules/rlm_sql/drivers/rlm_sql_mysql \
		&& ${AUTOCONF} -I ${WRKSRC}
	@cd ${WRKSRC}/src/modules/rlm_python && ${AUTOCONF} -I ${WRKSRC}

post-install:
# Create (if necessary) ${PREFIX}/etc/raddb and subdirectories using
# ${EXAMPLESDIR}/raddb as the model layout
	@for i in `${FIND} ${EXAMPLESDIR}/raddb/ -type d -print \
	| ${SED} -e 's:^${EXAMPLESDIR}/raddb::g'`; do \
		if [ ! -d ${PREFIX}/etc/raddb$${i} ]; then \
			${MKDIR} ${PREFIX}/etc/raddb$${i}; \
		fi; \
	done
# Copy all files from ${EXAMPLESDIR}/raddb to ${PREFIX}/etc/raddb if they
# don't already exist in the destination location
	@for i in `${FIND} ${EXAMPLESDIR}/raddb/ -type f -print \
	| ${SED} -e 's:^${EXAMPLESDIR}/raddb/::g'`; do \
		if [ ! -f ${PREFIX}/etc/raddb/$${i} ]; then \
			${CP} ${EXAMPLESDIR}/raddb/$${i} ${PREFIX}/etc/raddb/$${i}; \
		fi; \
	done
# Set ${PREFIX}/etc/raddb and all the files and folders in it to g-w,o-rwx
# (FreeRADIUS will probably complain if this is not done)
	@${CHMOD} -R g-w,o-rwx ${PREFIX}/etc/raddb

.include <bsd.port.post.mk>
