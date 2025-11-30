PORTNAME=	opendkim
DISTVERSIONPREFIX=	rel-opendkim-
DISTVERSION=	2.11.0-Beta2-48
DISTVERSIONSUFFIX=	-g551ab382
PORTREVISION=	2
CATEGORIES=	mail security
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DKIM library and milter implementation
WWW=		http://opendkim.org/

LICENSE=	BSD3CLAUSE SENDMAIL
LICENSE_COMB=	multi
LICENSE_GROUPS_SENDMAIL=	FSF OSI
LICENSE_NAME_SENDMAIL=	Sendmail Open Source License
LICENSE_FILE_SENDMAIL=	${WRKSRC}/LICENSE.Sendmail
LICENSE_PERMS_SENDMAIL=		dist-mirror dist-sell pkg-mirror pkg-sell \
				auto-accept

USES=		autoreconf cpe libtool perl5 pkgconfig shebangfix ssl
USE_GITHUB=	yes
GH_ACCOUNT=	trusteddomainproject
GH_PROJECT=	OpenDKIM
USE_LDCONFIG=	yes
USE_PERL5=	run

SHEBANG_FILES=	opendkim/opendkim-genkey* reprrd/opendkim-reprrdimport* \
		reputation/opendkim-* stats/opendkim-*

GNU_CONFIGURE=	yes

MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}
TEST_TARGET=	check

CONFLICTS_INSTALL=	opendkim

PORTDOCS=	*

OPTIONS_DEFINE=			BDB_BASE CURL DOCS FILTER GNUTLS JANSSON LDNS \
				LMDB LUA MEMCACHED OPENDBX OPENLDAP POPAUTH \
				QUERY_CACHE SASL
OPTIONS_DEFAULT=		FILTER LUA UNBOUND
OPTIONS_GROUP=			DEVELOPER FFR
OPTIONS_GROUP_DEVELOPER=	ALLSYMBOLS CODECOVERAGE DEBUG
OPTIONS_GROUP_FFR=		ADSP_LISTS ATPS DB_HANDLE_POOLS DEFAULT_SENDER \
				DIFFHEADERS IDENTITY_HEADER LDAP_CACHING \
				LUA_ONLY_SIGNING POSTGRES_RECONNECT_HACK \
				RATE_LIMIT RBL REPLACE_RULES REPRRD REPUTATION \
				RESIGN SENDER_MACRO SOCKETDB STATS STATSEXT VBR
OPTIONS_SINGLE=			RESOLV
OPTIONS_SINGLE_RESOLV=		STOCK_RESOLVER UNBOUND
NO_OPTIONS_SORT=	yes
OPTIONS_SUB=			yes

ADSP_LISTS_DESC=		ADSP filtering for lists (experimental)
ALLSYMBOLS_DESC=		Export all internal symbols for better test coverage
ATPS_DESC=			Authorized Third Party Sign check
BDB_BASE_DESC=			Use Berkeley DB from base
CODECOVERAGE_DESC=		Enable internal code-coverage/profiling
CURL_DESC=			Use cURL for web queries
DB_HANDLE_POOLS_DESC=		Database handle pools (experimental)
DEBUG_DESC=			Build with debug symbols
DEFAULT_SENDER_DESC=		Default sender address
DEVELOPER_DESC=			Options useful for OpenDKIM development
DIFFHEADERS_DESC=		Compare signed and verified headers (experimental)
FFR_DESC=			Use features marked as For-Future-Releases
FILTER_DESC=			OpenDKIM filter, requires libmilter/Sendmail
GNUTLS_DESC=			Use GnuTLS instead of OpenSSL
IDENTITY_HEADER_DESC=		Special header to set identity
JANSSON_DESC=			Statistics and other output as JSON data
LDAP_CACHING_DESC=		LDAP query piggybacking and caching
LDNS_DESC=			Use LDNS library for DNS queries
LMDB_DESC=			Use Lightning Memory-Mapped DB key-value store
LUA_DESC=			Describe filter policy with lua
LUA_ONLY_SIGNING_DESC=		Message signing by Lua only
MEMCACHED_DESC=			Use memcached as a data set
OPENDBX_DESC=			Store filter policies via OpenDBX
OPENLDAP_DESC=			Store filter policies in LDAP
POPAUTH_DESC=			Use POP authentication DB
POSTGRES_RECONNECT_HACK_DESC=	PostgreSQL connection error detection bug hack
QUERY_CACHE_DESC=		Cache DNS query results locally
RATE_LIMIT_DESC=		DKIM based rate limiting support
RBL_DESC=			Realtime Blacklist query support
REPLACE_RULES_DESC=		String substition when signing
REPRRD_DESC=			Support for collaborative reputation that uses rrdtool (experimental)
REPUTATION_DESC=		Reputation check (experimental)
RESIGN_DESC=			One-step resigning
SASL_DESC=			Enable SASL authentication with LDAP
SENDER_MACRO_DESC=		Macro to determine sender
SOCKETDB_DESC=			Arbitrary socket data sets
STATSEXT_DESC=			Localized stats extensions
STATS_DESC=			Per-message and per-signature statistics
STOCK_RESOLVER_DESC=		Use the stock resolver library
UNBOUND_DESC=			Use unbound DNS library
VBR_DESC=			Vouch-By-Reference support

ADSP_LISTS_CONFIGURE_ENABLE=	adsp_lists

ALLSYMBOLS_CONFIGURE_ENABLE=	allsymbols

ATPS_CONFIGURE_ENABLE=	atps

CODECOVERAGE_CONFIGURE_ENABLE=	codecoverage

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_WITH=	libcurl

DB_HANDLE_POOLS_CONFIGURE_ENABLE=	db_handle_pools

DEBUG_CONFIGURE_ENABLE=	debug

DEFAULT_SENDER_CONFIGURE_ENABLE=	default_sender

DIFFHEADERS_LIB_DEPENDS=	libtre.so:textproc/libtre
DIFFHEADERS_CONFIGURE_ENABLE=	diffheaders
DIFFHEADERS_CONFIGURE_WITH=	tre=${LOCALBASE}

FILTER_USE=	RC_SUBR=milter-opendkim

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_OFF=	--with-openssl=${OPENSSLBASE}
GNUTLS_CONFIGURE_WITH=	gnutls

IDENTITY_HEADER_CONFIGURE_ENABLE=	identity_header

JANSSON_LIB_DEPENDS=	libjansson.so:devel/jansson
JANSSON_CONFIGURE_WITH=	libjansson

LDAP_CACHING_USES=		ldap
LDAP_CACHING_CONFIGURE_ENABLE=	ldap_caching

LDNS_LIB_DEPENDS=	libldns.so:dns/ldns
LDNS_CONFIGURE_WITH=	ldns

LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb
LMDB_CONFIGURE_WITH=	lmdb

LUA_USES=		lua
LUA_CONFIGURE_WITH=	lua

LUA_ONLY_SIGNING_IMPLIES=		LUA
LUA_ONLY_SIGNING_CONFIGURE_ENABLE=	lua_only_signing

MEMCACHED_LIB_DEPENDS=		libmemcached.so:databases/libmemcached
MEMCACHED_CONFIGURE_WITH=	libmemcached

OPENDBX_LIB_DEPENDS=	libopendbx.so:databases/opendbx
OPENDBX_CONFIGURE_WITH=	odbx

OPENLDAP_USES=			ldap
OPENLDAP_CONFIGURE_WITH=	openldap

POPAUTH_CONFIGURE_ENABLE=	popauth

POSTGRES_RECONNECT_HACK_CONFIGURE_ENABLE=	postgresql_reconnect_hack

QUERY_CACHE_CONFIGURE_ENABLE=	query_cache

RATE_LIMIT_CONFIGURE_ENABLE=	rate_limit

RBL_IMPLIES=		LUA
RBL_CONFIGURE_ENABLE=	rbl

REPLACE_RULES_CONFIGURE_ENABLE=	replace_rules

REPRRD_LIB_DEPENDS=		librrd.so:databases/rrdtool
REPRRD_CONFIGURE_ENABLE=	reprrd

REPUTATION_IMPLIES=		CURL JANSSON
REPUTATION_CONFIGURE_ENABLE=	reputation

RESIGN_CONFIGURE_ENABLE=	resign

SASL_IMPLIES=		OPENLDAP
SASL_CONFIGURE_WITH=	sasl

SENDER_MACRO_CONFIGURE_ENABLE=	sender_macro

SOCKETDB_CONFIGURE_ENABLE=	socketdb

STATSEXT_IMPLIES=		LUA STATS
STATSEXT_CONFIGURE_ENABLE=	statsext

STATS_CONFIGURE_ENABLE=	stats

UNBOUND_LIB_DEPENDS=	libunbound.so:dns/unbound
UNBOUND_CONFIGURE_WITH=	unbound

VBR_CONFIGURE_ENABLE=	vbr

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFILTER}
SUB_FILES=		pkg-message
WITHOUT_MILTER_CFLAGS=	yes
WITHOUT_MILTER_LDFLAGS=	yes
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"
CONFIGURE_ARGS+=	--with-milter=${MILTERBASE}
.endif

.if ${PORT_OPTIONS:MPOPAUTH} || ${PORT_OPTIONS:MQUERY_CACHE} || \
	${PORT_OPTIONS:MLDAP_CACHING} || ${PORT_OPTIONS:MREPUTATION} || \
	${PORT_OPTIONS:MSTATS}
. if ${PORT_OPTIONS:MBDB_BASE}
CONFIGURE_ARGS+=	--with-db-lib=c
. else
CONFIGURE_ARGS+=	--with-db-incdir=${BDB_INCLUDE_DIR} \
			--with-db-lib=${BDB_LIB_NAME} \
			--with-db-libdir=${BDB_LIB_DIR}
USES+=			bdb
. endif
.endif

.if ${PORT_OPTIONS:MCODECOVERAGE}
LDFLAGS+=	-lpthread
.endif

pre-configure:
	${REINPLACE_CMD} -e '/PKG_CHECK_MODULES/s/lua5\.[0-9]/lua-${LUA_VER}/' \
	    -e '/PKG_CHECK_MODULES/s/cyrussasl/libsasl2/'			 \
	    ${WRKSRC}/configure.ac

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/mail
	${INSTALL_DATA} ${WRKSRC}/opendkim/opendkim.conf.sample \
	    ${STAGEDIR}${PREFIX}/etc/mail/

.include <bsd.port.mk>
