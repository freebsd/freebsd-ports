# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freeradius
DISTVERSION=	3.0.15
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/freeradius/%SUBDIR%/ \
		ftp://ftp.ntua.gr/pub/net/radius/freeradius/%SUBDIR%/ \
		http://ftp.cc.uoc.gr/mirrors/ftp.freeradius.org/%SUBDIR%/ \
		ZI
MASTER_SITE_SUBDIR=	. old
PKGNAMESUFFIX=	3
DISTNAME=	freeradius-server-${DISTVERSION}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Free RADIUS server implementation

LICENSE=	GPLv2

LIB_DEPENDS=	libgdbm.so:databases/gdbm \
		libtalloc.so:devel/talloc

LOGDIR?=	/var/log
KRB5_CONFIG?=	/usr/bin/krb5-config --libs

CONFLICTS_INSTALL=	gnu-radius-[0-9].* openradius-[0-9].* radiusd-cistron-[0-9].* \
		freeradius-mysql-[0-9].* freeradius-[^3].*

USE_RC_SUBR=	radiusd

USES=		gmake readline shebangfix ssl tar:bzip2
SHEBANG_FILES=	src/modules/rlm_counter/rad_counter scripts/sql/radsqlrelay
GNU_CONFIGURE=	yes
# Prevent /root/.rnd leftover
MAKE_ARGS+=	HOME=/dev/null
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	${CPPFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	PORTVERSION=${DISTVERSION} LIBVER=0${PORTVERSION:C/\./0/g}

# Default requirements for rc script
_REQUIRE=	NETWORKING SERVERS

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	USER LDAP MYSQL PGSQL UNIXODBC FIREBIRD REDIS \
		EXPERIMENTAL UDPFROMTO DEVELOPER EDIR PERL REST \
		FREETDS IDN DOCS SQLITE3 PYTHON RUBY UNBOUND
OPTIONS_DEFAULT=USER PERL HEIMDAL UDPFROMTO
OPTIONS_SINGLE=	KRB
OPTIONS_SINGLE_KRB=	NOKRB HEIMDAL HEIMDAL_PORT MITKRB_PORT

USER_DESC=		Run as user freeradius, group freeradius
KRB_DESC=		${KERBEROS_DESC}
NOKRB_DESC=		Without Kerberos support
HEIMDAL_DESC=		With Heimdal Kerberos support
HEIMDAL_PORT_DESC=	With Heimdal Kerberos from ports
MITKRB_PORT_DESC=	With MIT Kerberos from ports
UNIXODBC_DESC=		With unixODBC database support
UNBOUND_DESC=		With unbound DNS support
FIREBIRD_DESC=		With Firebird database support (EXPERIMENTAL)
EXPERIMENTAL_DESC=	Build experimental modules
UDPFROMTO_DESC=		Compile in UDPFROMTO support
DEVELOPER_DESC=		Enable developer options
EDIR_DESC=		Enable eDirectory support (implies LDAP)
REST_DESC=		Enable RESTful API support

EDIR_CONFIGURE_WITH=		edir
EDIR_IMPLIES=			LDAP
FREETDS_CONFIGURE_WITH=		rlm_freetds
FREETDS_CONFIGURE_OFF=		--without-freetds
FREETDS_LIB_DEPENDS=		libct.so:databases/freetds
HEIMDAL_CONFIGURE_ON=		--with-rlm-krb5-dir=/
HEIMDAL_PORT_LIB_DEPENDS=	libkrb5.so:security/heimdal
HEIMDAL_PORT_CONFIGURE_ON=	--with-rlm-krb5-dir=${LOCALBASE}
HEIMDAL_CONFLICTS_BUILD=	krb5-[0-9].*
IDN_CONFIGURE_WITH=		rlm_idn
IDN_LIB_DEPENDS=		libidn.so:dns/libidn
FIREBIRD_CONFIGURE_WITH=	rlm_sql_firebird
FIREBIRD_USES=			firebird
LDAP_CONFIGURE_WITH=		rlm_ldap
LDAP_LIB_DEPENDS=		libsasl2.so:security/cyrus-sasl2
LDAP_USE=			OPENLDAP
LDAP_VARS=			_REQUIRE+=slapd
MITKRB_PORT_CONFIGURE_ON=	--with-rlm-krb5-dir=${LOCALBASE}
MITKRB_PORT_LIB_DEPENDS=	libkrb5support.so:security/krb5
MITKRB_CONFLICTS_BUILD=		heimdal-[0-9].*
MYSQL_CONFIGURE_WITH=		rlm_sql_mysql
MYSQL_USE=			MYSQL
MYSQL_VARS=			_REQUIRE+=mysql
NOKRB_CONFIGURE_ON=		--without-rlm_krb5
NOKRB_PLIST_SUB=		RLMKRB5="@comment "
NOKRB_PLIST_SUB_OFF=		RLMKRB5=""
PERL_CONFIGURE_WITH=		rlm_perl
PERL_CONFIGURE_OFF=		--without-perl
PERL_USES=			perl5
PGSQL_USES=			pgsql
PGSQL_VARS=			_REQUIRE+=postgresql
PGSQL_CONFIGURE_WITH=		rlm_sql_postgresql
PYTHON_CONFIGURE_WITH=		rlm_python
PYTHON_CONFIGURE_ON=		--with-rlm-python-lib-dir=${PYTHON_LIBDIR} \
				--with-rlm-python-include-dir=${PYTHON_INCLUDEDIR}
PYTHON_USES=			python:2.7 gettext-runtime
PYTHON_VARS=			SHEBANG_FILES+=src/modules/rlm_python/*.py
REDIS_CONFIGURE_WITH=		rlm_redis rlm_rediswho
REDIS_LIB_DEPENDS=		libhiredis.so:databases/hiredis
REST_CONFIGURE_WITH=		rlm_rest
REST_CONFIGURE_ON=		--with-libcurl=${LOCALBASE} \
				--with-jsonc-lib-dir=${LOCALBASE}/lib \
				--with-jsonc-include-dir=${LOCALBASE}/include
REST_LIB_DEPENDS=		libcurl.so:ftp/curl \
				libjson-c.so:devel/json-c
RUBY_CONFIGURE_WITH=		rlm_ruby
RUBY_USE=			RUBY
RUBY_IGNORE=			with ruby support leaks memory, breaks signal handling.  Please disable RUBY support
SQLITE3_CONFIGURE_WITH=		rlm_sql_sqlite
SQLITE3_LIB_DEPENDS=		libsqlite3.so:databases/sqlite3
UDPFROMTO_CONFIGURE_OFF=	--without-udpfromto
UNBOUND_CONFIGURE_WITH=		rlm_unbound
UNBOUND_LIB_DEPENDS=		libunbound.so:dns/unbound
UNIXODBC_CONFIGURE_WITH=	rlm_sql_unixodbc
UNIXODBC_LIB_DEPENDS=		libodbc.so:databases/unixODBC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MUSER}
SUB_LIST+=	RUN_AS_USER="yes"
.else
SUB_LIST+=	RUN_AS_USER="no"
.endif

# User and group to use if USER option is chosen
RADIUS_USER=	freeradius
RADIUS_GROUP=	freeradius

USERS=		${RADIUS_USER}
GROUPS=		${RADIUS_GROUP}

# Firebird module is still experimental
.if ${PORT_OPTIONS:MFIREBIRD} && empty(PORT_OPTIONS:MEXPERIMENTAL)
EXPM=		yes
.endif

# rlm_ruby module is still experimental
.if ${PORT_OPTIONS:MRUBY} && empty(PORT_OPTIONS:MEXPERIMENTAL)
EXPM=		yes
.endif

# redis module is still experimental
.if ${PORT_OPTIONS:MREDIS} && empty(PORT_OPTIONS:MEXPERIMENTAL)
EXPM=		yes
.endif

# rest module is still experimental
.if ${PORT_OPTIONS:MREST} && empty(PORT_OPTIONS:MEXPERIMENTAL)
EXPM=		yes
.endif

# freetds module is still experimental
.if ${PORT_OPTIONS:MFREETDS} && empty(PORT_OPTIONS:MEXPERIMENTAL)
EXPM=		yes
.endif

# idn module is still experimental
.if ${PORT_OPTIONS:MIDN} && empty(PORT_OPTIONS:MEXPERIMENTAL)
EXPM=		yes
.endif

.if ${PORT_OPTIONS:MEXPERIMENTAL} || defined(EXPM)
CONFIGURE_ARGS+=--with-experimental-modules
PLIST_SUB+=	EXPM=""
.else
CONFIGURE_ARGS+=--without-experimental-modules
PLIST_SUB+=	EXPM="@comment "
.endif

.if ${PORT_OPTIONS:MDEVELOPER}
CONFIGURE_ARGS+=--enable-developer
# Turn off compiler optimisations
CFLAGS!=	${ECHO} ${CFLAGS} | ${SED} -Ee 's:-O[0-9]?[[:space:]]*::g'
.else
CONFIGURE_ARGS+=--quiet
.endif

.include <bsd.port.pre.mk>

# if we're installing, place sample configs into ${EXAMPLESDIR}
MAKE_ARGS+=	raddbdir="${EXAMPLESDIR}/raddb" R=${STAGEDIR}

FREERADIUS_LIBDIR=	lib/freeradius-${PORTVERSION}
PLIST_SUB+=	LIBDIR="${FREERADIUS_LIBDIR}"
USE_LDCONFIG=	${PREFIX}/${FREERADIUS_LIBDIR}

.if empty(PORT_OPTIONS:MDOCS)
CONFIGURE_ARGS+=--without-docdir
PLIST_SUB+=	PORTDOCS="@comment "
SUB_LIST+=	PORTDOCS="@comment "
.else
CONFIGURE_ARGS+=--with-docdir=${DOCSDIR}
PLIST_SUB+=	PORTDOCS=""
SUB_LIST+=	PORTDOCS=""
.endif

# This conditionality avoids -L/usr/lib in the radiusd build step when
# building with base system OpenSSL
.if ${OPENSSLLIB} != "/usr/lib"
CONFIGURE_ARGS+=--with-openssl-libraries=${OPENSSLLIB}
.endif
CONFIGURE_ARGS+=--with-logdir=${LOGDIR} \
		--with-openssl-includes=${OPENSSLINC} \
		--prefix=${PREFIX} --libdir=${PREFIX}/${FREERADIUS_LIBDIR} \
		--localstatedir=/var \
		--without-rlm_eap_ikev2 \
		--without-rlm_eap_tnc \
		--without-rlm_eap2 \
		--without-rlm_opendirectory \
		--without-rlm_sql_db2 \
		--without-rlm_sql_iodbc \
		--without-rlm_sql_sybase \
		--without-rlm_yubikey \
		--without-rlm_sql_oracle \
		--without-rlm_securid \
		--without-rlm_cache_memcached \
		--with-vmps \
		--with-collectdclient-lib-dir=/dev/null \
		--disable-openssl-version-check

.if ${ARCH} == amd64
CONFIGURE_ARGS+=--with-pic
.endif

SUB_FILES+=	pkg-install pkg-message
SUB_LIST+=	RADIUS_USER="${RADIUS_USER}" \
		RADIUS_GROUP="${RADIUS_GROUP}" \
		RADDB_WORK="${WRKSRC}/raddb" \
		RADDB="${PREFIX}/etc/raddb" \
		LOGDIR="${LOGDIR}" \
		LIBDIR="${PREFIX}/${FREERADIUS_LIBDIR}"
SUB_LIST+=	REQUIRE="${_REQUIRE}"

post-patch:
# never try to find execinfo.h (needed until we can enable/disable backtrace
	@${REINPLACE_CMD} -e '/#include <execinfo.h>/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -Ee "s:tests/all.mk ::" ${WRKSRC}/src/all.mk
	@${CP} ${WRKSRC}/m4/ax_with_prog.m4 ${WRKSRC}
# Patch raddb/certs/Makefile for the full path to the openssl binary (using
# ports OpenSSL if installed)
	@${REINPLACE_CMD} -E \
		-e "s:^([[:space:]])+openssl:\1${OPENSSLBASE}/bin/openssl:g" \
		${WRKSRC}/raddb/certs/Makefile
	@${REINPLACE_CMD} -Ee 's: ..R...sbindir./rc.radiusd : :' \
		${WRKSRC}/scripts/all.mk

# If we're using Heimdal from base, alter the LIBS variable
.if ${PORT_OPTIONS:MHEIMDAL} && empty(PORT_OPTIONS:MHEIMDAL_PORT)
	@${REINPLACE_CMD} -e 's|LIBS|KRB5LIBS|g' ${WRKSRC}/src/modules/rlm_krb5/configure
	@${REINPLACE_CMD} -e 's|-lkrb5|$$(${KRB5_CONFIG})|g' \
		${WRKSRC}/src/modules/rlm_krb5/configure
.endif
.if empty(PORT_OPTIONS:MRUBY)
	@${RM} -r ${WRKSRC}/src/modules/rlm_ruby/
.endif

post-build:
	@${FIND} ${WRKSRC}/build/lib -type f -name '*.so' -exec ${STRIP_CMD} {} \;
	@${FIND} ${WRKSRC}/build/bin -type f -exec ${STRIP_CMD} {} \;

post-install:
	${MKDIR} ${STAGEDIR}/var/run/radiusd

.include <bsd.port.post.mk>
