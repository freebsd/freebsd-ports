# New ports collection makefile for:	opendkim
# Date created:				2009-08-26
# Whom:					Hirohisa Yamaguchi <umq@ueo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	opendkim
PORTVERSION=	2.1.3
CATEGORIES=	mail security
MASTER_SITES=	SF/opendkim

MAINTAINER=	umq@ueo.co.jp
COMMENT=	DKIM library and milter implimentation

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	milter-opendkim
USE_LDCONFIG=	yes

MAN5=		opendkim.conf.5
MAN8=		opendkim-genkey.8 opendkim-genzone.8 \
		opendkim-testadsp.8 opendkim-testkey.8 \
		opendkim.8

SUB_FILES=	pkg-message

OPTIONS= \
	ARLIB		"Asynchronous thread-safe DNS library"	On  \
	LUA		"Describe filter policy with lua"	Off \
	OPENDBX		"Store filter policies via OpenDBX"	Off \
	OPENLDAP	"Store filter policies in LDAP"		Off \
	OPENSSL_PORT	"Use OpenSSL in ports"			Off \
	POPAUTH		"Use POP authentication DB"		Off \
	QUERY_CACHE	"Cache DNS query results locally"	Off \
	UNBOUND		"Use unbound DNS library"		Off

MAKE_ARGS+=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

.include <bsd.port.pre.mk>

WITHOUT_MILTER_CFLAGS=	yes
WITHOUT_MILTER_LDFLAGS=	yes
.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"
CONFIGURE_ARGS+=	--with-milter=${MILTERBASE}

.if ${OSVERSION} < 700000
WITH_OPENSSL_PORT=	yes
.endif
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}

.include "${.CURDIR}/Makefile.features"

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.else
CONFIGURE_ARGS+=--docdir=${WRKDIR}/doc
.endif

.if (defined(WITH_POPAUTH) \
	|| defined(WITH_QUERY_CACHE) \
	|| defined(WITH_BODYLENGTH_DB) \
	|| defined(WITH_LDAP_CACHING) \
	|| defined(WITH_STATS)) \
	&& !defined(WITH_BDB_BASE)
CONFIGURE_ARGS+=	--with-db-incdir=${BDB_INCLUDE_DIR} \
			--with-db-libdir=${BDB_LIB_DIR} \
			--with-db-lib=${BDB_LIB_NAME}
USE_BDB=		41+
.endif
.if defined(WITH_UNBOUND) && !defined(WITHOUT_UNBOUND)
BROKEN=		configure fails since arlib cannot be disabled
.if defined(WITH_ARLIB)
IGNORE=		libar cannot be used simultaneously with libunbound
.endif
CONFIGURE_ARGS+=	--with-unbound \
			--disable-arlib
LIB_DEPENDS+=		unbound:${PORTSDIR}/dns/unbound
PLIST_SUB+=		ARLIB="@comment "
.else
.if defined(WITH_ARLIB)
PLIST_SUB+=		ARLIB=""
CONFIGURE_ARGS+=	--enable-arlib
MAN3=			ar.3
.else
CONFIGURE_ARGS+=	--disable-arlib
PLIST_SUB+=		ARLIB="@comment "
.endif
.endif
.if defined(WITH_POPAUTH) && !defined(WITHOUT_POPAUTH)
CONFIGURE_ARGS+=	--enable-popauth
.endif
.if defined(WITH_QUERY_CACHE) && !defined(WITHOUT_QUERY_CACHE)
CONFIGURE_ARGS+=	--enable-query_cache
.endif
.if defined(WITH_OPENDBX)
CONFIGURE_ARGS+=	--with-odbx
LIB_DEPENDS+=		opendbx:${PORTSDIR}/databases/opendbx
.endif
.if defined(WITH_OPENLDAP)
CONFIGURE_ARGS+=	--with-openldap
USE_OPENLDAP=		yes
.endif
.if defined(WITH_LUA)
CONFIGURE_ARGS+=	--with-lua
MAN3+=			opendkim-lua.3
MAN8+=			miltertest.8
PLIST_SUB+=		LUA=""
USE_LUA=		5.1
.else
PLIST_SUB+=		LUA="@comment "
.endif

post-install:
.if !defined(WITH_DEBUG)
	@${STRIP_CMD} ${PREFIX}/sbin/opendkim
.endif
	@${MKDIR} ${PREFIX}/etc/mail
	${INSTALL_DATA} ${WRKSRC}/opendkim/opendkim.conf.sample ${PREFIX}/etc/mail/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
