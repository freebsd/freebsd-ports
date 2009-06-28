# New ports collection makefile for:		lighttpd
# Date created:					20 May 2004
# Whom:						k@123.org
#
# $FreeBSD$
#

PORTNAME=	lighttpd
PORTVERSION=	1.4.23
CATEGORIES=	www
MASTER_SITES=	http://www.lighttpd.net/download/ \
		http://mirrors.cat.pdx.edu/lighttpd/

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	A secure, fast, compliant, and very flexible Web Server

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_GNOME=	lthack
USE_RC_SUBR=	lighttpd.sh
CONFIGURE_ARGS=	--libdir=${PREFIX}/lib/lighttpd

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN8=		lighttpd.8

OPTIONS=	BZIP2		"Enable Bzip2 support" off \
		CML		"Enable Cache Meta Language support" off \
		FAM		"Enable fam/gamin support" off \
		GDBM		"Enable gdbm storage support" off \
		IPV6		"Enable IPV6 support" on \
		MAGNET		"Enable magnet support" off \
		MEMCACHE	"Enable memory caching support" off \
		MYSQL		"Enable MYSQL support" off \
		OPENLDAP	"Enable LDAP support" off \
		OPENSSL		"Enable SSL support" on \
		SPAWNFCGI	"Enable spawn-fcgi utility" on \
		VALGRIND	"Enable valgrind support" off \
		WEBDAV		"Enable WebDAV support"	off

.include <bsd.port.pre.mk>

# Default REQUIRE to rc.d script
_REQUIRE=	DAEMON

.if !defined(WITHOUT_OPENSSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl \
			--with-openssl-includes=${OPENSSLINC} \
			--with-openssl-libs=${OPENSSLLIB}
.endif

.if defined(WITH_BZIP2)
CONFIGURE_ARGS+=	--with-bzip2
.endif

.if defined(WITH_CML)
USE_LUA=		yes
CONFIGURE_ARGS+=	--with-lua
CONFIGURE_ENV+=		LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua"
.endif

.if defined(WITH_FAM)
USE_FAM=		yes
CONFIGURE_ARGS+=	--with-fam
CONFIGURE_ENV+=		FAM_CFLAGS="-I${LOCALBASE}/include" FAM_LIBS="-L${LOCALBASE}/lib"
.endif

.if defined(WITH_GDBM)
LIB_DEPENDS+=		gdbm:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=	--with-gdbm
.endif

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITH_MAGNET)
USE_LUA=		5.1+
CONFIGURE_ARGS+=	--with-lua
CONFIGURE_ENV+=		LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua"
.endif

.if defined(WITH_MEMCACHE)
LIB_DEPENDS+=		memcache.4:${PORTSDIR}/databases/libmemcache
CONFIGURE_ARGS+=	--with-memcache
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql
_REQUIRE+=		mysql
.endif

.if defined(WITH_OPENLDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap
_REQUIRE+=		slapd
.endif

.if defined(WITH_SPAWNFCGI)
RUN_DEPENDS+=		spawn-fcgi:${PORTSDIR}/www/spawn-fcgi
.endif

.if defined(WITH_VALGRIND)
BUILD_DEPENDS+=		valgrind:${PORTSDIR}/devel/valgrind
RUN_DEPENDS+=		valgrind:${PORTSDIR}/devel/valgrind
CONFIGURE_ARGS+=	--with-valgrind
.endif

.if defined(WITH_WEBDAV)
USE_GNOME+=		libxml2
LIB_DEPENDS+=		uuid.1:${PORTSDIR}/misc/e2fsprogs-libuuid \
			sqlite3.8:${PORTSDIR}/databases/sqlite3
CONFIGURE_ARGS+=	--with-webdav-props --with-webdav-locks
.endif

SUB_LIST+=		REQUIRE="${_REQUIRE}"

post-patch:
	@${REINPLACE_CMD} -e 's|-std=gnu99||' ${WRKSRC}/configure ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -E -e 's|(server.document-root.*=).*|\1 "${PREFIX}/www/data/"|' \
		-e 's|(server.errorlog.*=).*|\1 "/var/log/lighttpd.error.log"|' \
		-e 's|# server.event-handler|server.event-handler|' \
		-e 's|(accesslog.filename.*=).*|\1 "/var/log/lighttpd.access.log"|' \
		-e 's|#server.pid-file|server.pid-file|' \
		-e 's|#server.username.*|server.username            = "www"|' \
		-e 's|#server.groupname.*|server.groupname           = "www"|' \
		-e 's|/usr/local/bin/php|${PREFIX}/bin/php-cgi|' \
			${WRKSRC}/doc/lighttpd.conf
.if !defined(WITHOUT_IPV6)
	@${ECHO} "" >> ${WRKSRC}/doc/lighttpd.conf
	@${ECHO} "# Enable IPV6 and IPV4 together" >> ${WRKSRC}/doc/lighttpd.conf
	@${ECHO} "server.use-ipv6 = \"enable\"" >> ${WRKSRC}/doc/lighttpd.conf
	@${ECHO} "\$$SERVER[\"socket\"] == \"0.0.0.0:80\" { }" >> ${WRKSRC}/doc/lighttpd.conf
.endif

post-install:
	@${INSTALL_DATA} ${WRKSRC}/doc/lighttpd.conf ${PREFIX}/etc/lighttpd.conf.sample
.if !exists(${PREFIX}/etc/lighttpd.conf)
	@${INSTALL_DATA} ${WRKSRC}/doc/lighttpd.conf ${PREFIX}/etc/lighttpd.conf
.endif
	@${LIBTOOL} --finish ${PREFIX}/lib

.include <bsd.port.post.mk>
