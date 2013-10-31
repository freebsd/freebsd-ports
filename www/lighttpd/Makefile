# Created by: k@123.org
# $FreeBSD$

PORTNAME?=	lighttpd
PORTVERSION=	1.4.33
CATEGORIES?=	www
MASTER_SITES?=	http://download.lighttpd.net/lighttpd/releases-1.4.x/

MAINTAINER?=	mm@FreeBSD.org
COMMENT?=	Secure, fast, compliant, and flexible Web Server

.if !defined(_BUILDING_LIGHTTPD_MODULE)
LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING
.endif

LIB_DEPENDS+=	pcre.3:${PORTSDIR}/devel/pcre

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	lthack
USE_GMAKE=	yes
USES=		pkgconfig

#.if !defined(_BUILDING_LIGHTTPD_MODULE)
#USE_AUTOTOOLS=	libtool
#.else
USE_AUTOTOOLS=	autoconf autoheader aclocal automake libtool
ACLOCAL_ARGS=	-I m4
AUTOMAKE_ARGS=	--add-missing
#.endif
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/lighttpd --enable-static

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if !defined(_BUILDING_LIGHTTPD_MODULE)
USE_RC_SUBR=	lighttpd

MAN8=		lighttpd.8

OPTIONS_DEFINE=	BZIP2 FAM GDBM IPV6 LIBEV LUA MEMCACHE MYSQL MYSQLAUTH \
		NODELAY LDAP OPENSSL SPAWNFCGI VALGRIND WEBDAV

OPTIONS_DEFAULT=	IPV6 OPENSSL 

BZIP2_DESC=	bzip2 support (mod_compress)
GDBM_DESC=	gdbm storage (mod_trigger_b4_dl)
LDAP_DESC=	LDAP authentication
LUA_DESC=	lua support (mod_cml, mod_magnet)
MEMCACHE_DESC=	memcached storage (mod_trigger_b4_dl)
MYSQL_DESC=	MySQL support (mod_mysql_vhost)
MYSQLAUTH_DESC=	MySQL authentication (requires WITH_MYSQL)
NODELAY_DESC=	Set TCP_NODELAY on listening sockets
SPAWNFCGI_DESC=	Depend on spawn-fcgi utility
VALGRIND_DESC=	valgrind support
WEBDAV_DESC=	WebDAV support

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

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !defined(_BUILDING_LIGHTTPD_MODULE)
# Default REQUIRE to rc.d script
_REQUIRE=	DAEMON

.if ${PORT_OPTIONS:MDOCS}
DOCS=		AUTHORS COPYING INSTALL NEWS README
PORTDOCS=	${DOCS}
.endif

.if ${PORT_OPTIONS:MOPENSSL}
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-openssl \
			--with-openssl-includes=${OPENSSLINC} \
			--with-openssl-libs=${OPENSSLLIB}
.endif

.if ${PORT_OPTIONS:MBZIP2}
CONFIGURE_ARGS+=	--with-bzip2
.endif

.if ${PORT_OPTIONS:MFAM}
USE_FAM=		yes
CONFIGURE_ARGS+=	--with-fam
CONFIGURE_ENV+=		FAM_CFLAGS="-I${LOCALBASE}/include" FAM_LIBS="-L${LOCALBASE}/lib"
.endif

.if ${PORT_OPTIONS:MGDBM}
LIB_DEPENDS+=		gdbm:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=	--with-gdbm
.endif

.if empty(PORT_OPTIONS:MIPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if ${PORT_OPTIONS:MLIBEV}
CONFIGURE_ARGS+=	--with-libev=${LOCALBASE}
LIB_DEPENDS+=		ev.4:${PORTSDIR}/devel/libev
.endif

.if ${PORT_OPTIONS:MLUA}
USE_LUA=		5.1
CONFIGURE_ARGS+=	--with-lua
CONFIGURE_ENV+=		LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua"
.endif

.if ${PORT_OPTIONS:MMEMCACHE}
LIB_DEPENDS+=		memcache.4:${PORTSDIR}/databases/libmemcache
CONFIGURE_ARGS+=	--with-memcache
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

.if ${PORT_OPTIONS:MSPAWNFCGI}
RUN_DEPENDS+=		spawn-fcgi:${PORTSDIR}/www/spawn-fcgi
.endif

.if ${PORT_OPTIONS:MVALGRIND}
BUILD_DEPENDS+=		valgrind:${PORTSDIR}/devel/valgrind
RUN_DEPENDS+=		valgrind:${PORTSDIR}/devel/valgrind
CONFIGURE_ARGS+=	--with-valgrind
.endif

.if ${PORT_OPTIONS:MWEBDAV}
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
	@${REINPLACE_CMD} -e "s|/usr/bin/python|${LOCALBASE}/bin/python|" \
		${WRKSRC}/doc/config/conf.d/cgi.conf \
		${WRKSRC}/tests/*.conf
	@${ECHO} >> ${WRKSRC}/doc/config/lighttpd.conf
	@${ECHO} "# IPv4 listening socket" >> \
		${WRKSRC}/doc/config/lighttpd.conf
	@${ECHO} "\$$SERVER[\"socket\"] == \"0.0.0.0:80\" { }" >> \
		${WRKSRC}/doc/config/lighttpd.conf

post-install:
	@${MKDIR} ${PREFIX}/etc/lighttpd/conf.d ${PREFIX}/etc/lighttpd/vhosts.d
.for FILE in ${LIGHTTPD_CONF_FILES}
	@${INSTALL_DATA} ${WRKSRC}/doc/config/${FILE} \
		${PREFIX}/etc/lighttpd/${FILE}.sample
.if !exists(${PREFIX}/etc/lighttpd/${FILE})
	@${INSTALL_DATA} ${WRKSRC}/doc/config/${FILE} \
		${PREFIX}/etc/lighttpd/${FILE}
.endif
.endfor
.for FILE in ${LIGHTTPD_CONF_D_FILES}
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

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
. for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/${FILE}
. endfor
.endif
.if ${PORT_OPTIONS:MMYSQLAUTH}
. for FILE in README.mysqlauth mysql_auth.sql
	@${INSTALL_DATA} ${FILESDIR}/${FILE} ${DOCSDIR}/${FILE}
. endfor
.endif

test: build
	@cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} \
		check-TESTS

regression-test: test

.endif # !defined(_BUILDING_LIGHTTPD_MODULE)

.include <bsd.port.post.mk>
