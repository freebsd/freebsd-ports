# Created by: Hirohisa Yamaguchi <umq@ueo.co.jp>
# $FreeBSD$

PORTNAME=		opendkim
PORTVERSION=		2.7.4
CATEGORIES=		mail security
MASTER_SITES=		SF
MASTER_SITE_SUBDIR=	${PORTNAME} \
			${PORTNAME}/Previous%20Releases

MAINTAINER=		umq@ueo.co.jp
COMMENT=		DKIM library and milter implementation

LICENSE=		BSD SENDMAIL
LICENSE_COMB=		multi

LICENSE_FILE_SENDMAIL=	${WRKSRC}/LICENSE.Sendmail
LICENSE_GROUPS_SENDMAIL=	FSF OSI
LICENSE_NAME_SENDMAIL=	Sendmail Open Source License
LICENSE_PERMS_SENDMAIL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
NO_OPTIONS_SORT=yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

MAN8=		opendkim-genkey.8 opendkim-genzone.8 opendkim-testadsp.8 \
		opendkim-testkey.8 opendkim-testmsg.8
PORTDOCS=	*

OPTIONS_SINGLE=		RESOLV
OPTIONS_SINGLE_RESOLV=	STOCK_RESOLVER UNBOUND
OPTIONS_DEFINE=		FILTER GNUTLS LUA MEMCACHED BDB_BASE OPENDBX OPENLDAP \
			POPAUTH QUERY_CACHE STATS
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

MAKE_ARGS+=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

.include "${.CURDIR}/Makefile.options"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFILTER}
USE_RC_SUBR=		milter-opendkim
MAN5+=			opendkim.conf.5
MAN8+=			opendkim.8
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
LIB_DEPENDS+=		gnutls:${PORTSDIR}/security/gnutls
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
MAN8+=			opendkim-expire.8 opendkim-gengraphs.8 \
			opendkim-genstats.8 opendkim-stats.8
. if ${PORT_OPTIONS:MOPENDBX}
MAN1+=			opendkim-spam.1
MAN8+=			opendkim-importstats.8
. endif
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
USE_BDB=		41+
. endif
.endif
.if ${PORT_OPTIONS:MUNBOUND}
CONFIGURE_ARGS+=	--with-unbound
LIB_DEPENDS+=		unbound:${PORTSDIR}/dns/unbound
.endif
.if ${PORT_OPTIONS:MPOPAUTH}
CONFIGURE_ARGS+=	--enable-popauth
.endif
.if ${PORT_OPTIONS:MQUERY_CACHE}
CONFIGURE_ARGS+=	--enable-query_cache
.endif
.if ${PORT_OPTIONS:MMEMCACHED}
CONFIGURE_ARGS+=	--with-libmemcached
LIB_DEPENDS+=		memcached:${PORTSDIR}/databases/libmemcached
.else
CONFIGURE_ARGS+=	--without-libmemcached
.endif
.if ${PORT_OPTIONS:MOPENDBX}
CONFIGURE_ARGS+=	--with-odbx
LIB_DEPENDS+=		opendbx:${PORTSDIR}/databases/opendbx
PLIST_SUB+=		ODBX=""
.else
CONFIGURE_ARGS+=	--without-odbx
PLIST_SUB+=		ODBX="@comment "
.endif
.if ${PORT_OPTIONS:MOPENLDAP}
CONFIGURE_ARGS+=	--with-openldap
LIB_DEPENDS+=		ldap:${PORTSDIR}/net/openldap24-sasl-client
USE_OPENLDAP=		yes
.else
CONFIGURE_ARGS+=	--without-openldap
.endif
.if ${PORT_OPTIONS:MLUA}
CONFIGURE_ARGS+=	--with-lua
. if ${PORT_OPTIONS:MFILTER}
MAN3+=			opendkim-lua.3
. endif
MAN8+=			miltertest.8
PLIST_SUB+=		LUA=""
USE_LUA=		5.1
.else
PLIST_SUB+=		LUA="@comment "
.endif

post-install:
.if ! ${PORT_OPTIONS:MDEBUG} && ${PORT_OPTIONS:MFILTER}
	@${STRIP_CMD} ${PREFIX}/sbin/opendkim
.endif
	@${MKDIR} ${PREFIX}/etc/mail
	${INSTALL_DATA} ${WRKSRC}/opendkim/opendkim.conf.sample ${PREFIX}/etc/mail/
.if ${PORT_OPTIONS:MFILTER}
	@${CAT} ${PKGMESSAGE}
.endif

regression-test: build
	cd ${WRKSRC} ; ${MAKE} check

.include <bsd.port.mk>
