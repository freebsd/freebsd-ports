# Created by: Hirohisa Yamaguchi <umq@ueo.co.jp>
# $FreeBSD$

PORTNAME=		opendkim
PORTVERSION=		2.8.3
PORTREVISION=		1
CATEGORIES=		mail security
MASTER_SITES=		SF
MASTER_SITE_SUBDIR=	${PORTNAME} \
			${PORTNAME}/Previous%20Releases

MAINTAINER=		umq@ueo.co.jp
COMMENT=		DKIM library and milter implementation

LICENSE=		BSD3CLAUSE SENDMAIL
LICENSE_COMB=		multi

LICENSE_FILE_SENDMAIL=	${WRKSRC}/LICENSE.Sendmail
LICENSE_GROUPS_SENDMAIL=	FSF OSI
LICENSE_NAME_SENDMAIL=	Sendmail Open Source License
LICENSE_PERMS_SENDMAIL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GNU_CONFIGURE=	yes
NO_OPTIONS_SORT=yes
USES=		pkgconfig perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	opendkim/opendkim-genkey.in
SHEBANG_FILES=	opendkim/opendkim-genkey* reputation/opendkim-* stats/opendkim-*
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_SINGLE=		RESOLV
OPTIONS_SINGLE_RESOLV=	STOCK_RESOLVER UNBOUND
OPTIONS_DEFINE=		FILTER GNUTLS LUA MEMCACHED BDB_BASE OPENDBX OPENLDAP \
			POPAUTH QUERY_CACHE STATS DEBUG
OPTIONS_DEFAULT=	FILTER LUA UNBOUND

STOCK_RESOLVER_DESC=	Use the stock resolver library
UNBOUND_DESC=		Use unbound DNS library
FILTER_DESC=		OpenDKIM filter, requires libmilter/Sendmail
GNUTLS_DESC=		Use GnuTLS instead of OpenSSL
LUA_DESC=		Describe filter policy with lua
MEMCACHED_DESC=		Use memcached as a data set
BDB_BASE_DESC=		Use Berkeley DB from base
OPENDBX_DESC=		Store filter policies via OpenDBX
OPENLDAP_DESC=		Store filter policies in LDAP
POPAUTH_DESC=		Use POP authentication DB
QUERY_CACHE_DESC=	Cache DNS query results locally
STATS_DESC=		Setup statistics tools
DEBUG_DESC=		Build with debug symbols

MAKE_ARGS+=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

.include "${.CURDIR}/Makefile.options"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFILTER}
USE_RC_SUBR=		milter-opendkim
PLIST_SUB+=		FILTER=""
SUB_FILES=		pkg-message
WITHOUT_MILTER_CFLAGS=	yes
WITHOUT_MILTER_LDFLAGS=	yes
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"
CONFIGURE_ARGS+=	--with-milter=${MILTERBASE}
.else
CONFIGURE_ARGS+=	--disable-filter
PLIST_SUB+=		FILTER="@comment "
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=		libgnutls.so:${PORTSDIR}/security/gnutls
CONFIGURE_ARGS+=	--with-gnutls=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.endif

.include "${.CURDIR}/Makefile.features"

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ! ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--docdir=${WRKDIR}/doc
.endif

.if ${PORT_OPTIONS:MSTATS}
CONFIGURE_ARGS+=	--enable-stats
PLIST_SUB+=		STATS=""
.else
PLIST_SUB+=		STATS="@comment "
.endif
.if ${PORT_OPTIONS:MPOPAUTH} \
	|| ${PORT_OPTIONS:MQUERY_CACHE} \
	|| (${PORT_OPTIONS:MFFR} && ${PORT_OPTIONS:MLDAP_CACHING} ) \
	|| (${PORT_OPTIONS:MFFR} && ${PORT_OPTIONS:MREPUTATION} ) \
	|| ${PORT_OPTIONS:MSTATS}
. if ${PORT_OPTIONS:MBDB_BASE}
CONFIGURE_ARGS+=	--with-db-lib=c
. else
CONFIGURE_ARGS+=	--with-db-incdir=${BDB_INCLUDE_DIR} \
			--with-db-libdir=${BDB_LIB_DIR} \
			--with-db-lib=${BDB_LIB_NAME}
USE_BDB=		40+
. endif
.endif
.if ${PORT_OPTIONS:MUNBOUND}
CONFIGURE_ARGS+=	--with-unbound
LIB_DEPENDS+=		libunbound.so:${PORTSDIR}/dns/unbound
.endif
.if ${PORT_OPTIONS:MPOPAUTH}
CONFIGURE_ARGS+=	--enable-popauth
.endif
.if ${PORT_OPTIONS:MQUERY_CACHE}
CONFIGURE_ARGS+=	--enable-query_cache
.endif
.if ${PORT_OPTIONS:MMEMCACHED}
CONFIGURE_ARGS+=	--with-libmemcached
LIB_DEPENDS+=		libmemcached.so:${PORTSDIR}/databases/libmemcached
.else
CONFIGURE_ARGS+=	--without-libmemcached
.endif
.if ${PORT_OPTIONS:MOPENDBX}
CONFIGURE_ARGS+=	--with-odbx
LIB_DEPENDS+=		libopendbx.so:${PORTSDIR}/databases/opendbx
PLIST_SUB+=		ODBX=""
.else
CONFIGURE_ARGS+=	--without-odbx
PLIST_SUB+=		ODBX="@comment "
.endif
.if ${PORT_OPTIONS:MOPENLDAP}
CONFIGURE_ARGS+=	--with-openldap
LIB_DEPENDS+=		libldap.so:${PORTSDIR}/net/openldap24-sasl-client
USE_OPENLDAP=		yes
.else
CONFIGURE_ARGS+=	--without-openldap
.endif
.if ${PORT_OPTIONS:MLUA}
CONFIGURE_ARGS+=	--with-lua
PLIST_SUB+=		LUA=""
USES+=			lua
.else
PLIST_SUB+=		LUA="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e '/PKG_CONFIG/s/lua5\.2/lua-${LUA_VER}/' \
	-e '/PKG_CONFIG/s/cyrussasl/libsasl2/' \
	${WRKSRC}/configure

post-patch:
.if ${PORT_OPTIONS:MLCOV}
	${CP} ${FILESDIR}/lcov-helper.sh ${WRKSRC}/libopendkim/tests/
	${CP} ${FILESDIR}/lcov-helper.sh ${WRKSRC}/opendkim/tests/
	${FIND} ${WRKSRC} -type f -name \*-helper.sh -exec ${CHMOD} 755 {} +
.endif

post-install:
.if ! ${PORT_OPTIONS:MDEBUG} && ${PORT_OPTIONS:MFILTER}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/opendkim
.endif
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopendkim.so.9
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/mail
	${INSTALL_DATA} ${WRKSRC}/opendkim/opendkim.conf.sample ${STAGEDIR}${PREFIX}/etc/mail/

regression-test: build
	cd ${WRKSRC} ; ${MAKE} check

.include <bsd.port.mk>
