# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freeradius
DISTVERSION=	3.0.12
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/freeradius/%SUBDIR%/ \
		ftp://ftp.ntua.gr/pub/net/radius/freeradius/%SUBDIR%/ \
		http://ftp.cc.uoc.gr/mirrors/ftp.freeradius.org/%SUBDIR%/ \
		http://mirrors.rit.edu/zi/
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

USES=		gmake shebangfix ssl tar:bzip2
SHEBANG_FILES=	src/modules/rlm_counter/rad_counter scripts/sql/radsqlrelay
GNU_CONFIGURE=	yes
# Prevent /root/.rnd leftover
MAKE_ARGS+=	HOME=/dev/null
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	${CPPFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	PORTVERSION=${DISTVERSION} LIBVER=0${PORTVERSION:C/\./0/g}

OPTIONS_SUB=	yes
OPTIONS_DEFINE=	USER KERBEROS HEIMDAL HEIMDAL_PORT LDAP MYSQL \
		PGSQL UNIXODBC FIREBIRD REDIS PYTHON RUBY \
		EXPERIMENTAL UDPFROMTO DEVELOPER EDIR PERL REST \
		FREETDS IDN SSL_PORT DOCS SQLITE3
OPTIONS_DEFAULT=USER PERL

USER_DESC=		Run as user freeradius, group freeradius
HEIMDAL_DESC=		With Heimdal Kerberos support
HEIMDAL_PORT_DESC=	With Heimdal Kerberos from ports
UNIXODBC_DESC=		With unixODBC database support
FIREBIRD_DESC=		With Firebird database support (EXPERIMENTAL)
EXPERIMENTAL_DESC=	Build experimental modules
UDPFROMTO_DESC=		Compile in UDPFROMTO support
DEVELOPER_DESC=		Enable developer options
EDIR_DESC=		Enable eDirectory support (implies LDAP)
REST_DESC=		Enable RESTful API support
SSL_PORT_DESC=		Use OpenSSL from the ports collection

SQLITE3_CONFIGURE_WITH=rlm_sql_sqlite
SQLITE3_LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

.include <bsd.port.options.mk>

# Default requirements for rc script
_REQUIRE=	NETWORKING SERVERS

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

.if ${PORT_OPTIONS:MKERBEROS} || ${PORT_OPTIONS:MHEIMDAL}
.if ${PORT_OPTIONS:MHEIMDAL}
.if ${PORT_OPTIONS:MHEIMDAL_PORT}
LIB_DEPENDS+=	libkrb5.so:security/heimdal
.endif
CONFIGURE_ARGS+=--enable-heimdal-krb5 --enable-pthread-support
.else
LIB_DEPENDS+=	libkrb5support.so:security/krb5
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
.else
CONFIGURE_ARGS+=--without-edir
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	YES
LIB_DEPENDS+=	libsasl2.so:security/cyrus-sasl2
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
USES+=		pgsql
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
LIB_DEPENDS+=	libodbc.so:databases/unixODBC
.else
CONFIGURE_ARGS+=--without-rlm_sql_unixodbc
PLIST_SUB+=	UNIXODBC="@comment "
.endif

.if ${PORT_OPTIONS:MFIREBIRD}
USES+=		firebird
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
CONFIGURE_ARGS+=--without-rlm_ruby --with-ruby=no
PLIST_SUB+=	RLMRUBY="@comment "
.endif

# rlm_ruby module is still experimental
.if ${PORT_OPTIONS:MRUBY} && empty(PORT_OPTIONS:MEXPERIMENTAL)
EXPM=		yes
.endif

.if ${PORT_OPTIONS:MREDIS}
LIB_DEPENDS+=	libhiredis.so:databases/hiredis
CONFIGURE_ARGS+=--with-rlm_redis --with-rlm_rediswho
PLIST_SUB+=	RLMREDIS=""
.else
CONFIGURE_ARGS+=--without-rlm_redis --without-rlm_rediswho
PLIST_SUB+=	RLMREDIS="@comment "
.endif

# redis module is still experimental
.if ${PORT_OPTIONS:MREDIS} && empty(PORT_OPTIONS:MEXPERIMENTAL)
EXPM=		yes
.endif

.if ${PORT_OPTIONS:MREST}
LIB_DEPENDS+=	libjson-c.so:devel/json-c \
		libcurl.so:ftp/curl
CONFIGURE_ARGS+=--with-rlm_rest \
		--with-libcurl=${LOCALBASE} \
		--with-jsonc-lib-dir=${LOCALBASE}/lib \
		--with-jsonc-include-dir=${LOCALBASE}/include
PLIST_SUB+=	RLMREST=""
.else
CONFIGURE_ARGS+=--without-rlm_rest
PLIST_SUB+=	RLMREST="@comment "
.endif

# rest module is still experimental
.if ${PORT_OPTIONS:MREST} && empty(PORT_OPTIONS:MEXPERIMENTAL)
EXPM=		yes
.endif

.if ${PORT_OPTIONS:MFREETDS}
LIB_DEPENDS+=	libct.so:databases/freetds
CONFIGURE_ARGS+=--with-rlm_freetds
PLIST_SUB+=	RLMFREETDS=""
.else
CONFIGURE_ARGS+=--without-rlm_freetds
PLIST_SUB+=	RLMFREETDS="@comment "
.endif

# freetds module is still experimental
.if ${PORT_OPTIONS:MFREETDS} && empty(PORT_OPTIONS:MEXPERIMENTAL)
EXPM=		yes
.endif

.if ${PORT_OPTIONS:MIDN}
LIB_DEPENDS+=	libidn.so:dns/libidn
CONFIGURE_ARGS+=--with-rlm_idn
PLIST_SUB+=	RLMIDN=""
.else
CONFIGURE_ARGS+=--without-rlm_idn
PLIST_SUB+=	RLMIDN="@comment "
.endif

# freetds module is still experimental
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

# Compile in UDPFROMTO support
.if ${PORT_OPTIONS:MUDPFROMTO}
CONFIGURE_ARGS+=--with-udpfromto
.endif

.if ${PORT_OPTIONS:MSSL_PORT}
WITH_OPENSSL_PORT=yes
.endif

# rlm_eap_fast is currently broken under 9.x:
# https://github.com/FreeRADIUS/freeradius-server/issues/1803
.if ${OSVERSION} < 1000015
PLIST_SUB+=     EAPFAST="@comment "
.else
PLIST_SUB+=     EAPFAST=""
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
		--with-collectdclient-lib-dir=/dev/null

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
.if ${OSVERSION} < 1000015
	${RM} -r ${WRKSRC}/src/modules/rlm_eap/types/rlm_eap_fast
.endif
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
