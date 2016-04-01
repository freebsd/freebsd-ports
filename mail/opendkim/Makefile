# Created by: Hirohisa Yamaguchi <umq@ueo.co.jp>
# $FreeBSD$

PORTNAME=		opendkim
PORTVERSION=		2.10.3
PORTREVISION=		5
CATEGORIES=		mail security
MASTER_SITES=		SF/${PORTNAME} \
			SF/${PORTNAME}/Previous%20Releases \
			ftp://ftpmirror.uk/freebsd-ports/${PORTNAME}/

MAINTAINER=		freebsd-ports@dan.me.uk
COMMENT=		DKIM library and milter implementation

LICENSE=		BSD3CLAUSE SENDMAIL
LICENSE_COMB=		multi

LICENSE_FILE_SENDMAIL=	${WRKSRC}/LICENSE.Sendmail
LICENSE_GROUPS_SENDMAIL=	FSF OSI
LICENSE_NAME_SENDMAIL=	Sendmail Open Source License
LICENSE_PERMS_SENDMAIL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GNU_CONFIGURE=	yes
NO_OPTIONS_SORT=yes
USES=		libtool perl5 pkgconfig shebangfix
USE_PERL5=	run
SHEBANG_FILES=	opendkim/opendkim-genkey* reputation/opendkim-* stats/opendkim-* \
		reprrd/opendkim-reprrdimport*
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

PORTDOCS=	*

CONFIGURE_ARGS+=	--without-tre

OPTIONS_SUB=		yes
OPTIONS_SINGLE=		RESOLV
OPTIONS_SINGLE_RESOLV=	STOCK_RESOLVER UNBOUND
OPTIONS_DEFINE=		FILTER CURL GNUTLS JANSSON LDNS LMDB LUA MEMCACHED \
			BDB_BASE OPENDBX OPENLDAP POPAUTH QUERY_CACHE SASL
OPTIONS_DEFAULT=	FILTER LUA UNBOUND

STOCK_RESOLVER_DESC=	Use the stock resolver library

UNBOUND_DESC=		Use unbound DNS library
UNBOUND_CONFIGURE_WITH=	unbound
UNBOUND_LIB_DEPENDS=	libunbound.so:dns/unbound

FILTER_DESC=		OpenDKIM filter, requires libmilter/Sendmail
FILTER_USE=		RC_SUBR=milter-opendkim

CURL_DESC=		Use cURL for web queries
CURL_CONFIGURE_WITH=	libcurl
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

GNUTLS_DESC=		Use GnuTLS instead of OpenSSL
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_WITH=	gnutls
GNUTLS_CONFIGURE_OFF=	--with-openssl=${OPENSSLBASE}

JANSSON_DESC=		Statistics and other output as JSON data
JANSSON_CONFIGURE_WITH=	libjansson
JANSSON_LIB_DEPENDS=	libjansson.so:devel/jansson

LDNS_DESC=		Use LDNS library for DNS queries
LDNS_CONFIGURE_WITH=	ldns
LDNS_LIB_DEPENDS=	libldns.so:dns/ldns

LMDB_DESC=		Use Lightning Memory-Mapped DB key-value store
LMDB_CONFIGURE_WITH=	lmdb
LMDB_LIB_DEPENDS=	liblmdb.so:databases/lmdb

LUA_DESC=		Describe filter policy with lua
LUA_CONFIGURE_WITH=	lua
LUA_USES=		lua

MEMCACHED_DESC=		Use memcached as a data set
MEMCACHED_CONFIGURE_WITH=	libmemcached
MEMCACHED_LIB_DEPENDS=	libmemcached.so:databases/libmemcached

BDB_BASE_DESC=		Use Berkeley DB from base

OPENDBX_DESC=		Store filter policies via OpenDBX
OPENDBX_CONFIGURE_WITH=	odbx
OPENDBX_LIB_DEPENDS=	libopendbx.so:databases/opendbx

OPENLDAP_DESC=		Store filter policies in LDAP
OPENLDAP_CONFIGURE_WITH=openldap
OPENLDAP_USE=		OPENLDAP=yes

POPAUTH_DESC=		Use POP authentication DB
POPAUTH_CONFIGURE_ENABLE=	popauth

QUERY_CACHE_DESC=	Cache DNS query results locally
QUERY_CACHE_CONFIGURE_ENABLE=	query_cache

SASL_DESC=		Enable SASL authentication with LDAP
SASL_CONFIGURE_WITH=	sasl

DOCS_CONFIGURE_ON=	--docdir=${WRKDIR}/doc

MAKE_ARGS+=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"
MAKE_ENV=	INSTALL_STRIP_FLAG=${STRIP}

.include "${.CURDIR}/Makefile.options"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSASL} && ${PORT_OPTIONS:MOPENLDAP}
WANT_OPENLDAP_SASL=	yes
.endif

.if ${PORT_OPTIONS:MFILTER}
SUB_FILES=		pkg-message
WITHOUT_MILTER_CFLAGS=	yes
WITHOUT_MILTER_LDFLAGS=	yes
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"
CONFIGURE_ARGS+=	--with-milter=${MILTERBASE}
.endif

.if ${PORT_OPTIONS:MLUA_ONLY_SIGNING} || \
    ${PORT_OPTIONS:MRBL}
.if !${PORT_OPTIONS:MLUA}
IGNORE= options LUA_ONLY_SIGNING and RBL require LUA as well
.endif
.endif

.if ${PORT_OPTIONS:MREPUTATION}
.if !${PORT_OPTIONS:MCURL} || !${PORT_OPTIONS:MJANSSON}
IGNORE= option REPUTATION requires CURL and JANSSON as well
.endif
.endif

.if ${PORT_OPTIONS:MSTATSEXT}
.if !${PORT_OPTIONS:MSTATS} || !${PORT_OPTIONS:MLUA}
IGNORE= option STATSEXT requires STATS and LUA as well
.endif
.endif

.if ${PORT_OPTIONS:MPOPAUTH}             \
	|| ${PORT_OPTIONS:MQUERY_CACHE}  \
	|| ${PORT_OPTIONS:MLDAP_CACHING} \
	|| ${PORT_OPTIONS:MREPUTATION}   \
	|| ${PORT_OPTIONS:MSTATS}
. if ${PORT_OPTIONS:MBDB_BASE}
CONFIGURE_ARGS+=	--with-db-lib=c
. else
CONFIGURE_ARGS+=	--with-db-incdir=${BDB_INCLUDE_DIR} \
			--with-db-libdir=${BDB_LIB_DIR}     \
			--with-db-lib=${BDB_LIB_NAME}
USE_BDB=		40+
. endif
.endif

.if ${PORT_OPTIONS:MCODECOVERAGE}
LDFLAGS+=		-lpthread
.endif

pre-configure:
	${REINPLACE_CMD} -e '/LIBLUA_LIBS/s/lua5\.[0-9]/lua-${LUA_VER}/' \
	    -e '/PKG_CONFIG/s/lua5\.[0-9]/lua-${LUA_VER}/'		 \
	    -e '/PKG_CONFIG/s/cyrussasl/libsasl2/'			 \
	    ${WRKSRC}/configure

post-patch:
.if ${PORT_OPTIONS:MLCOV}
	${CP} ${FILESDIR}/lcov-helper.sh ${WRKSRC}/libopendkim/tests/
	${CP} ${FILESDIR}/lcov-helper.sh ${WRKSRC}/opendkim/tests/
	${FIND} ${WRKSRC} -type f -name \*-helper.sh -exec ${CHMOD} 755 {} +
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/mail
	${INSTALL_DATA} ${WRKSRC}/opendkim/opendkim.conf.sample \
	    ${STAGEDIR}${PREFIX}/etc/mail/

regression-test: build
	cd ${WRKSRC} ; ${MAKE} check

.include <bsd.port.mk>
