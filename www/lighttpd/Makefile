# Created by: k@123.org
# $FreeBSD$

PORTNAME?=	lighttpd
PORTVERSION=	1.4.39
PORTREVISION=	1
CATEGORIES?=	www
MASTER_SITES?=	http://download.lighttpd.net/lighttpd/releases-1.4.x/

MAINTAINER=	pkubaj@riseup.net
COMMENT?=	Secure, fast, compliant, and flexible Web Server

.if !defined(_BUILDING_LIGHTTPD_MODULE)
LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING
.endif

LIB_DEPENDS+=	libpcre.so:devel/pcre

GNU_CONFIGURE=	yes
USES=		autoreconf gmake libtool pkgconfig tar:xz

.if !defined(_BUILDING_LIGHTTPD_MODULE)
USES+=	cpe
.endif

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/lighttpd
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if !defined(_BUILDING_LIGHTTPD_MODULE)
USE_RC_SUBR=	lighttpd

OPTIONS_DEFINE=	ATTR BZIP2 DOCS FAM GDBM IPV6 LIBEV LUA MEMCACHE MYSQL MYSQLAUTH \
		NODELAY LDAP OPENSSL SPAWNFCGI VALGRIND WEBDAV

OPTIONS_DEFAULT=	OPENSSL

ATTR_DESC=	extended attributes support
BZIP2_DESC=	bzip2 support (mod_compress)
GDBM_DESC=	gdbm storage (mod_trigger_b4_dl)
LDAP_DESC=	LDAP authentication
LIBEV_DESC=	Fast events support via libev (disables kqueue)
LUA_DESC=	lua support (mod_cml, mod_magnet)
MEMCACHE_DESC=	memcached storage (mod_trigger_b4_dl)
MYSQL_DESC=	MySQL support (mod_mysql_vhost)
MYSQLAUTH_DESC=	MySQL authentication (requires WITH_MYSQL)
NODELAY_DESC=	Set TCP_NODELAY on listening sockets
SPAWNFCGI_DESC=	Depend on spawn-fcgi utility
VALGRIND_DESC=	valgrind support
WEBDAV_DESC=	WebDAV support

ATTR_CONFIGURE_WITH=	attr
BZIP2_CONFIGURE_WITH=	bzip2
FAM_USES=		fam
FAM_CONFIGURE_ON=	--with-fam
FAM_CONFIGURE_ENV=	FAM_CFLAGS="-I${LOCALBASE}/include" FAM_LIBS="-L${LOCALBASE}/lib"
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_WITH=	gdbm
IPV6_CONFIGURE_OFF=	--disable-ipv6
LIBEV_CONFIGURE_WITH=	libev=${LOCALBASE}
LIBEV_LIB_DEPENDS=	libev.so:devel/libev
LUA_USES=		lua:51+
LUA_CONFIGURE_WITH=	lua
LUA_CONFIGURE_ENV=	LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}"
MEMCACHE_LIB_DEPENDS=	libmemcache.so:databases/libmemcache
MEMCACHE_CONFIGURE_WITH=memcache
MYSQLAUTH_IMPLIES=	MYSQL
SPAWNFCGI_RUN_DEPENDS=	spawn-fcgi:www/spawn-fcgi
VALGRIND_BUILD_DEPENDS=	valgrind:devel/valgrind
VALGRIND_RUN_DEPENDS=	valgrind:devel/valgrind
VALGRIND_CONFIGURE_WITH=valgrind

LIGHTTPD_CONF_FILES=	lighttpd.conf modules.conf

LIGHTTPD_CONF_D_FILES=	access_log.conf \
	auth.conf cgi.conf cml.conf \
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

.include <bsd.port.options.mk>

.if !defined(_BUILDING_LIGHTTPD_MODULE)
# Default REQUIRE to rc.d script
_REQUIRE=	DAEMON

.if ${PORT_OPTIONS:MDOCS}
DOCS=		AUTHORS COPYING INSTALL NEWS README
PORTDOCS=	${DOCS}
.endif

.if ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--with-openssl \
			--with-openssl-includes=${OPENSSLINC} \
			--with-openssl-libs=${OPENSSLLIB}
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--with-mysql
_REQUIRE+=		mysql
.endif

.if ${PORT_OPTIONS:MMYSQLAUTH} && empty(PORT_OPTIONS:MMYSQL)
IGNORE=		option WITH_MYSQLAUTH requires WITH_MYSQL
.endif

.if ${PORT_OPTIONS:MMYSQLAUTH}
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-mysqlauth
PORTDOCS+=		README.mysqlauth mysql_auth.sql
.endif

.if ${PORT_OPTIONS:MNODELAY}
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-nodelay
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap
_REQUIRE+=		slapd
.endif

.if ${PORT_OPTIONS:MWEBDAV}
USE_GNOME+=		libxml2
LIB_DEPENDS+=		libuuid.so:misc/e2fsprogs-libuuid \
			libsqlite3.so:databases/sqlite3
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
	@${REINPLACE_CMD} -e "s|/usr/bin/python|${LOCALBASE}/bin/python|" \
		${WRKSRC}/doc/config/conf.d/cgi.conf \
		${WRKSRC}/tests/*.conf
	@${ECHO} >> ${WRKSRC}/doc/config/lighttpd.conf
	@${ECHO} "# IPv4 listening socket" >> \
		${WRKSRC}/doc/config/lighttpd.conf
	@${ECHO} "\$$SERVER[\"socket\"] == \"0.0.0.0:80\" { }" >> \
		${WRKSRC}/doc/config/lighttpd.conf

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/lighttpd/conf.d ${STAGEDIR}${PREFIX}/etc/lighttpd/vhosts.d
.for FILE in ${LIGHTTPD_CONF_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/config/${FILE} \
		${STAGEDIR}${PREFIX}/etc/lighttpd/${FILE}.sample
.endfor
.for FILE in ${LIGHTTPD_CONF_D_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/config/conf.d/${FILE} \
		${STAGEDIR}${PREFIX}/etc/lighttpd/conf.d/${FILE}.sample
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/config/vhosts.d/vhosts.template \
		${STAGEDIR}${PREFIX}/etc/lighttpd/vhosts.d/vhosts.template

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
. for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}/${FILE}
. endfor
.endif
.if ${PORT_OPTIONS:MMYSQLAUTH}
. for FILE in README.mysqlauth mysql_auth.sql
	${INSTALL_DATA} ${FILESDIR}/${FILE} ${STAGEDIR}${DOCSDIR}/${FILE}
. endfor
.endif
	@${MKDIR} -m 0700 ${STAGEDIR}${LIGHTTPD_LOGROOT}

test: build
	@cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} \
		check-TESTS

regression-test: test

.endif # !defined(_BUILDING_LIGHTTPD_MODULE)

.include <bsd.port.mk>
