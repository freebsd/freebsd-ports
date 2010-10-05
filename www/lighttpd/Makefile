# New ports collection makefile for:		lighttpd
# Date created:					20 May 2004
# Whom:						k@123.org
#
# $FreeBSD$
#

PORTNAME?=	lighttpd
PORTVERSION=	1.4.28
PORTREVISION=	4
CATEGORIES?=	www
MASTER_SITES?=	http://download.lighttpd.net/lighttpd/releases-1.4.x/

MAINTAINER?=	mm@FreeBSD.org
COMMENT?=	A secure, fast, compliant, and very flexible Web Server

BUILD_DEPENDS+=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	lthack
USE_AUTOTOOLS=	autoconf:267 autoheader:267 aclocal:111 automake:111 libtool:22
ACLOCAL_ARGS=	-I m4
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/lighttpd --enable-static

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

.if !defined(_BUILDING_LIGHTTPD_MODULE)
USE_RC_SUBR=	lighttpd.sh

MAN8=		lighttpd.8

OPTIONS=	BZIP2		"Enable Bzip2 support" off \
		CML		"Enable Cache Meta Language support" off \
		FAM		"Enable fam/gamin support" off \
		GDBM		"Enable gdbm storage support" off \
		IPV6		"Enable IPV6 support" on \
		LIBEV		"Enable libev support" off \
		MAGNET		"Enable magnet support" off \
		MEMCACHE	"Enable memory caching support" off \
		MYSQL		"Enable MYSQL support" off \
		MYSQLAUTH	"Enable mysql auth (requires WITH_MYSQL)" off \
		NODELAY		"Set TCP_NODELAY on listening sockets" off \
		OPENLDAP	"Enable LDAP support" off \
		OPENSSL		"Enable SSL support" on \
		SPAWNFCGI	"Depend on spawn-fcgi utility" off \
		VALGRIND	"Enable valgrind support" off \
		WEBDAV		"Enable WebDAV support"	off

.if !defined(NOPORTDOCS)
DOCS=		AUTHORS COPYING INSTALL NEWS README
PORTDOCS=	${DOCS}
.endif

CONF_FILES=	lighttpd.conf modules.conf

CONFD_FILES=	access_log.conf auth.conf cgi.conf cml.conf \
		compress.conf debug.conf dirlisting.conf \
		evhost.conf expire.conf fastcgi.conf \
		magnet.conf mime.conf mysql_vhost.conf proxy.conf \
		rrdtool.conf scgi.conf secdownload.conf \
		simple_vhost.conf ssi.conf status.conf \
		trigger_b4_dl.conf userdir.conf webdav.conf

LIGHTTPD_LOGROOT?=	/var/log/lighttpd
LIGHTTPD_WEBROOT?=	${PREFIX}/www/data
LIGHTTPD_USER?=		www
LIGHTTPD_GROUP?=	www

PLIST_SUB+=		LOGROOT="${LIGHTTPD_LOGROOT}" \
			USER="${LIGHTTPD_USER}" \
			GROUP="${LIGHTTPD_GROUP}" \
			MKDIR="${MKDIR}" \
			CHOWN="${CHOWN}"

.endif # !defined(_BUILDING_LIGHTTPD_MODULE)

.include <bsd.port.pre.mk>

.if !defined(_BUILDING_LIGHTTPD_MODULE)
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

.if defined(WITH_LIBEV)
CONFIGURE_ARGS+=	--with-libev=${LOCALBASE}
LIB_DEPENDS+=		ev.3:${PORTSDIR}/devel/libev
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

.if defined(WITH_MYSQLAUTH) && !defined(WITH_MYSQL)
IGNORE=		WITH_MYSQLAUTH requires WITH_MYSQL
.endif

.if defined(WITH_MYSQLAUTH)
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-mysqlauth
PORTDOCS+=		README.mysqlauth mysql_auth.sql
.endif

.if defined(WITH_NODELAY)
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-nodelay
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
	@${REINPLACE_CMD} -e 's|-std=gnu99||' \
		${WRKSRC}/configure ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -E -e \
		's|^(server.document-root.*=).*|\1 "${PREFIX}/www/data/"|' \
		-e "s|/etc/lighttpd|${PREFIX}/etc/lighttpd|g" \
		-e 's|^(server.event-handler.*=).*|\1 "freebsd-kqueue"|' \
		-e 's|^(server.network-backend.*=).*|\1 "writev"|' \
		-e "s|^(server.username.*=).*|\1 \"${LIGHTTPD_USER}\"|" \
		-e "s|^(server.groupname.*=).*|\1 \"${LIGHTTPD_GROUP}\"|" \
		-e "s|^(var.log_root.*=).*|\1 \"${LIGHTTPD_LOGROOT}\"|" \
		-e "s|^(var.home_dir.*=).*|\1 \"/var/spool/lighttpd\"|" \
		-e "s|^(var.server_root.*=).*|\1 \"${LIGHTTPD_WEBROOT}\"|" \
		${WRKSRC}/doc/config/lighttpd.conf
	@${REINPLACE_CMD} -e "s|/etc/lighttpd|${PREFIX}/etc/lighttpd|g" \
		${WRKSRC}/doc/config/conf.d/auth.conf
	@${ECHO} >> ${WRKSRC}/doc/config/lighttpd.conf
	@${ECHO} "# IPv4 listening socket" >> \
		${WRKSRC}/doc/config/lighttpd.conf
	@${ECHO} "\$$SERVER[\"socket\"] == \"0.0.0.0:80\" { }" >> \
		${WRKSRC}/doc/config/lighttpd.conf

post-install:
	@${MKDIR} ${PREFIX}/etc/lighttpd/conf.d ${PREFIX}/etc/lighttpd/vhosts.d
.for FILE in ${CONF_FILES}
	@${INSTALL_DATA} ${WRKSRC}/doc/config/${FILE} \
		${PREFIX}/etc/lighttpd/${FILE}.sample
.if !exists(${PREFIX}/etc/lighttpd/${FILE})
	@${INSTALL_DATA} ${WRKSRC}/doc/config/${FILE} \
		${PREFIX}/etc/lighttpd/${FILE}
.endif
.endfor
.for FILE in ${CONFD_FILES}
	@${INSTALL_DATA} ${WRKSRC}/doc/config/conf.d/${FILE} \
		${PREFIX}/etc/lighttpd/conf.d/${FILE}.sample
.if !exists(${PREFIX}/etc/lighttpd/conf.d/${FILE})
	@${INSTALL_DATA} ${WRKSRC}/doc/config/conf.d/${FILE} \
		${PREFIX}/etc/lighttpd/conf.d/${FILE}
.endif
.endfor
	@${INSTALL_DATA} ${WRKSRC}/doc/config/vhosts.d/vhosts.template \
		${PREFIX}/etc/lighttpd/vhosts.d/vhosts.template
	@${MKDIR} -m 0700 ${LIGHTTPD_LOGROOT}
	@${CHOWN} ${LIGHTTPD_USER}:${LIGHTTPD_GROUP} ${LIGHTTPD_LOGROOT}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/${FILE}
. endfor
.endif
.if defined(WITH_MYSQLAUTH)
. for FILE in README.mysqlauth mysql_auth.sql
	@${INSTALL_DATA} ${FILESDIR}/${FILE} ${DOCSDIR}/${FILE}
. endfor
.endif
.endif # !defined(_BUILDING_LIGHTTPD_MODULE)

.include <bsd.port.post.mk>
