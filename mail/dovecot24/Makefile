PORTNAME=	dovecot
DISTVERSION=	2.4.4
CATEGORIES=	mail
MASTER_SITES=	https://dovecot.org/releases/2.4/
PKGNAMESUFFIX=	24${DOVE_SUFFIX}

MAINTAINER=	jordan@ostreff.info
COMMENT=	Secure, fast and powerful IMAP and POP3 server
WWW=		https://www.dovecot.org/

LICENSE=	LGPL21 MIT
LICENSE_COMB=	dual

LIB_DEPENDS=	libpcre2-32.so:devel/pcre2 \
		libstemmer.so:textproc/snowballstemmer \
		libxapian.so:databases/xapian-core \
		libzstd.so:archivers/zstd

FLAVORS=	default mysql pgsql sqlite3 ldap cdb
FLAVOR?=	default

USES=		cpe gmake iconv libtool perl5 pkgconfig python shebangfix ssl
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
USE_RC_SUBR=	${PORTNAME}

.if ${FLAVOR} == mysql
DOVE_SUFFIX=	-mysql
.elif ${FLAVOR} == pgsql
DOVE_SUFFIX=	-pgsql
.elif ${FLAVOR} == sqlite3
DOVE_SUFFIX=	-sqlite3
.elif ${FLAVOR} == ldap
DOVE_SUFFIX=	-ldap
.elif ${FLAVOR} == cdb
DOVE_SUFFIX=	-cdb
.else
DOVE_SUFFIX=
.endif

SHEBANG_FILES=	src/lib-settings/settings-history.py

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var \
		--sysconfdir=${PREFIX}/etc \
		--with-ssldir=${PREFIX}/etc/ssl \
		--with-statedir=/var/db/${PORTNAME} \
		--without-systemd

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include -I${OPENSSLINC} -D_GNU_SOURCE
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}

CONFLICTS_INSTALL=	dovecot dovecot-cdb dovecot-ldap dovecot-mysql \
			dovecot-pgsql dovecot-sqlite3

.if ${FLAVOR} == default
CONFLICTS_INSTALL+=	dovecot24-cdb dovecot24-ldap dovecot24-mysql \
			dovecot24-pgsql dovecot24-sqlite3
.elif ${FLAVOR} == mysql
CONFLICTS_INSTALL+=	dovecot24 dovecot24-cdb dovecot24-ldap dovecot24-pgsql \
			dovecot24-sqlite3
.elif ${FLAVOR} == pgsql
CONFLICTS_INSTALL+=	dovecot24 dovecot24-cdb dovecot24-ldap dovecot24-mysql \
			dovecot24-sqlite3
.elif ${FLAVOR} == sqlite3
CONFLICTS_INSTALL+=	dovecot24 dovecot24-cdb dovecot24-ldap dovecot24-mysql \
			dovecot24-pgsql
.elif ${FLAVOR} == ldap
CONFLICTS_INSTALL+=	dovecot24 dovecot24-cdb dovecot24-mysql dovecot24-pgsql \
			dovecot24-sqlite3
.elif ${FLAVOR} == cdb
CONFLICTS_INSTALL+=	dovecot24 dovecot24-ldap dovecot24-mysql \
			dovecot24-pgsql dovecot24-sqlite3
.endif

DOCSDIR=	${PREFIX}/share/doc/dovecot
EXAMPLESDIR=	${PREFIX}/share/examples/dovecot
DOCS=		AUTHORS COPYING NEWS TODO
SUB_FILES=	dovecot pkg-message
SUB_LIST+=	DISTVERSION=${DISTVERSION} \
		RC_SUBR=/etc/rc.subr \
		REQUIRE="${_REQUIRE}"

USERS=		${PORTNAME} dovenull
GROUPS=		${USERS}

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES IMAP4REV2 LIBSODIUM LIBUNWIND LUA LZ4 \
			UTF8
OPTIONS_DEFAULT=	DOCS EXAMPLES GSSAPI_NONE LUA UTF8

# The DB group (CDB/LDAP/MYSQL/PGSQL/SQLITE) is only a real, toggleable
# OPTIONS group for the default flavor. For the mysql/pgsql/sqlite3/ldap/
# cdb flavors the backend is fixed by the flavor itself and injected
# further below via plain USES/CONFIGURE_ARGS/LIB_DEPENDS - NOT via
# PORT_OPTIONS+= after the fact, since that does not reliably re-run the
# option's _USES/_CONFIGURE_WITH/_LIB_DEPENDS machinery.
.if ${FLAVOR} == default
OPTIONS_GROUP=		DB FTS
OPTIONS_GROUP_DB=	CDB LDAP MYSQL PGSQL SQLITE
.else
OPTIONS_GROUP=		FTS
.endif
OPTIONS_GROUP_FTS=	ICU SOLR TEXTCAT

OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE

OPTIONS_FILE=	${PORT_DBDIR}/mail_dovecot24${DOVE_SUFFIX}/options
OPTIONS_SUB=	yes

CDB_DESC=		CDB database support
DB_DESC=		Database support
FTS_DESC=		Full text search plugins
GSSAPI_BASE_DESC=	Use GSSAPI from base
GSSAPI_HEIMDAL_DESC=	Use Heimdal GSSAPI from security/heimdal
GSSAPI_MIT_DESC=	Use MIT GSSAPI from security/krb5
GSSAPI_NONE_DESC=	Build without GSSAPI support
ICU_DESC=		Use libicu for FTS unicode normalization
IMAP4REV2_DESC=		Enable experimental IMAP4REV2 support
LIBSODIUM_DESC=		Support libsodium based crypts (ARGON2I/ARGON2ID)
LIBUNWIND_DESC=		Get backtraces using libunwind
SOLR_DESC=		Solr FTS support (untested and NOT recommended)
TEXTCAT_DESC=		Libexttextcat FTS support
UTF8_DESC=		Enable experimental SMTPUTF8 support

CDB_LIB_DEPENDS=	libcdb.so:databases/tinycdb
CDB_CONFIGURE_WITH=	cdb

GSSAPI_BASE_USES=		gssapi
GSSAPI_HEIMDAL_USES=		gssapi:heimdal
GSSAPI_MIT_USES=		gssapi:mit
GSSAPI_NONE_CONFIGURE_ON=	--without-gssapi
GSSAPI_NONE_CONFIGURE_OFF=	--with-gssapi

ICU_LIB_DEPENDS=	libicui18n.so:devel/icu \
			libicuuc.so:devel/icu
ICU_CONFIGURE_WITH=	icu
ICU_LDFLAGS=		-licuuc

IMAP4REV2_CONFIGURE_ON=		--enable-experimental-imap4rev2
IMAP4REV2_CONFIGURE_OFF=	--disable-experimental-imap4rev2

LDAP_USES=		ldap
LDAP_CONFIGURE_ON=	--with-ldap=yes
LDAP_CONFIGURE_OFF=	--with-ldap=no
LDAP_VARS=		_REQUIRE+=slapd

LIBSODIUM_LIB_DEPENDS=		libsodium.so:security/libsodium
LIBSODIUM_CONFIGURE_WITH=	sodium

LIBUNWIND_LIB_DEPENDS=		libunwind.so:devel/libunwind
LIBUNWIND_CONFIGURE_ON=		--with-libunwind=yes
LIBUNWIND_CONFIGURE_OFF=	--with-libunwind=no

LUA_USES=		lua:53,54
LUA_CONFIGURE_ON=	--with-lua=yes
LUA_CONFIGURE_OFF=	--with-lua=no

LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZ4_CONFIGURE_WITH=	lz4

MYSQL_USES=		mysql
MYSQL_CONFIGURE_WITH=	mysql
MYSQL_VARS=		_REQUIRE+=mysql

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_WITH=	pgsql
PGSQL_VARS=		_REQUIRE+=postgresql

SOLR_LIB_DEPENDS=	libcurl.so:ftp/curl \
			libexpat.so:textproc/expat2
SOLR_CONFIGURE_WITH=	solr

SQLITE_USES=		sqlite
SQLITE_CONFIGURE_WITH=	sqlite

TEXTCAT_LIB_DEPENDS=	libexttextcat-2.0.so:textproc/libexttextcat
TEXTCAT_CONFIGURE_WITH=	textcat

UTF8_CONFIGURE_ON=	--enable-experimental-mail-utf8
UTF8_CONFIGURE_OFF=	--disable-experimental-mail-utf8

_REQUIRE=	LOGIN

.include <bsd.port.options.mk>

# The mysql/pgsql/sqlite3/ldap/cdb flavors bypass the OPTIONS framework
# entirely for their DB backend: USES/CONFIGURE_ARGS/LIB_DEPENDS are set
# directly here so they always take effect, regardless of OPTIONS
# processing order. LDAP in particular requires an explicit
# --with-ldap=yes or src/lib-ldap is never built at all (unlike the SQL
# drivers, which dovecot auto-detects and builds regardless of any
# --with-X flag).
.if ${FLAVOR} == mysql
USES+=			mysql
CONFIGURE_ARGS+=	--with-mysql=yes
_REQUIRE+=		mysql
.elif ${FLAVOR} == pgsql
USES+=			pgsql
CONFIGURE_ARGS+=	--with-pgsql=yes
_REQUIRE+=		postgresql
.elif ${FLAVOR} == sqlite3
USES+=			sqlite
CONFIGURE_ARGS+=	--with-sqlite=yes
.elif ${FLAVOR} == ldap
USES+=			ldap
CONFIGURE_ARGS+=	--with-ldap=yes
_REQUIRE+=		slapd
.elif ${FLAVOR} == cdb
LIB_DEPENDS+=		libcdb.so:databases/tinycdb
CONFIGURE_ARGS+=	--with-cdb=yes
.endif

# Because LDAP is no longer part of the OPTIONS framework for non-default
# flavors, OPTIONS_SUB=yes can no longer auto-generate the %%LDAP%% plist
# substitution for them - set it explicitly so pkg-plist stays correct
# for every flavor.
.if ${FLAVOR} == ldap
PLIST_SUB+=	LDAP=""
.elif ${FLAVOR} != default
PLIST_SUB+=	LDAP="@comment "
.endif

# imap-hibernate does not build on FreeBSD < 15.0 due to kqueue being used for notifications
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1500000
PLIST_SUB+=	IMAP_HIBERNATE="@comment "
.else
PLIST_SUB+=	IMAP_HIBERNATE=""
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^LIBS =/s/$$/ @LTLIBICONV@/' \
		${WRKSRC}/src/lib-mail/Makefile.in

post-configure:
	@${REINPLACE_CMD} -e 's/^auth_DEPENDENCIES =.*/auth_DEPENDENCIES =/' \
		${WRKSRC}/src/auth/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@if [ -f ${STAGEDIR}${ETCDIR}/dovecot.conf ]; then \
		${MV} ${STAGEDIR}${ETCDIR}/dovecot.conf ${STAGEDIR}${ETCDIR}/dovecot.conf.sample; \
	fi
	@if [ -f ${STAGEDIR}${DOCSDIR}/dovecot-openssl.cnf ]; then \
		${INSTALL_DATA} ${STAGEDIR}${DOCSDIR}/dovecot-openssl.cnf ${STAGEDIR}${EXAMPLESDIR}; \
	fi
	@if [ -f ${STAGEDIR}${DOCSDIR}/mkcert.sh ]; then \
		${INSTALL_SCRIPT} ${STAGEDIR}${DOCSDIR}/mkcert.sh ${STAGEDIR}${EXAMPLESDIR}; \
	fi

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@if [ -d ${WRKSRC} ]; then \
		(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}); \
	fi

.include <bsd.port.mk>
