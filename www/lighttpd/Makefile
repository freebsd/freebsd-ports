# Created by: k@123.org
# $FreeBSD$

PORTNAME?=	lighttpd
PORTVERSION=	1.4.44
CATEGORIES?=	www
MASTER_SITES?=	http://download.lighttpd.net/lighttpd/releases-1.4.x/

MAINTAINER=	pkubaj@anongoth.pl
COMMENT?=	Secure, fast, compliant, and flexible Web Server

.if !defined(_BUILDING_LIGHTTPD_MODULE)
LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING
.endif

LIB_DEPENDS+=	libpcre.so:devel/pcre

GNU_CONFIGURE=	yes
USES=		autoreconf gmake libtool localbase pkgconfig tar:xz
USE_CSTD=	gnu99

.if !defined(_BUILDING_LIGHTTPD_MODULE)
USES+=	cpe
.endif

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/lighttpd
INSTALL_TARGET=	install-strip

.if !defined(_BUILDING_LIGHTTPD_MODULE)
PORTDOCS=	AUTHORS COPYING INSTALL NEWS README

USE_RC_SUBR=	lighttpd
REQUIRE=	DAEMON

OPTIONS_DEFINE=	ATTR BZIP2 DOCS FAM GDBM GEOIP IPV6 KRB5 LIBEV LUA MEMCACHED \
		MYSQL LDAP OPENSSL SPAWNFCGI VALGRIND WEBDAV

OPTIONS_DEFAULT=	OPENSSL
OPTIONS_SUB=	yes

ATTR_DESC=	extended attributes support
BZIP2_DESC=	bzip2 support (mod_compress)
GDBM_DESC=	gdbm storage (mod_trigger_b4_dl)
KRB5_DESC=	Kerberos authentication (mod_authn_gssapi)
LDAP_DESC=	LDAP authentication (mod_authn_ldap)
LIBEV_DESC=	Fast events support via libev (disables kqueue)
LUA_DESC=	lua support (mod_cml, mod_magnet)
MEMCACHED_DESC=	memcached storage (mod_trigger_b4_dl)
MYSQL_DESC=	MySQL support (mod_authn_mysql, mod_mysql_vhost)
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
GEOIP_LIB_DEPENDS=	libGeoIP.so:net/GeoIP
GEOIP_CONFIGURE_WITH=	geoip
IPV6_CONFIGURE_OFF=	--disable-ipv6
KRB5_CONFIGURE_WITH=	krb5
KRB5_CPPFLAGS=		${GSSAPICPPFLAGS}
KRB5_LDFLAGS=		${GSSAPILDFLAGS}
KRB5_LIBS=		${GSSAPILIBS}
KRB5_USES=		gssapi:mit
LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		openldap=yes
LDAP_VARS=		REQUIRE+=slapd
LIBEV_CONFIGURE_WITH=	libev=${LOCALBASE}
LIBEV_LIB_DEPENDS=	libev.so:devel/libev
LUA_USES=		lua
LUA_CONFIGURE_WITH=	lua
LUA_CONFIGURE_ENV=	LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}"
MEMCACHED_LIB_DEPENDS=	libmemcached.so:databases/libmemcached
MEMCACHED_CONFIGURE_WITH=memcached
MYSQL_CONFIGURE_WITH=	mysql
MYSQL_USES=		mysql
MYSQL_VARS=		REQUIRE+=mysql
OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_WITH=	openssl
OPENSSL_CONFIGURE_ON=	--with-openssl-includes=${OPENSSLINC} --with-openssl-libs=${OPENSSLLIB}
SPAWNFCGI_RUN_DEPENDS=	spawn-fcgi:www/spawn-fcgi
VALGRIND_BUILD_DEPENDS=	valgrind:devel/valgrind
VALGRIND_RUN_DEPENDS=	valgrind:devel/valgrind
VALGRIND_CONFIGURE_WITH=valgrind
WEBDAV_USE=		GNOME=libxml2
WEBDAV_LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid \
			libsqlite3.so:databases/sqlite3
WEBDAV_CONFIGURE_WITH=	webdav-props webdav-locks

LIGHTTPD_CONF_FILES=	lighttpd.conf modules.conf

LIGHTTPD_CONF_D_FILES=	access_log.conf \
	auth.conf cgi.conf cml.conf \
	compress.conf debug.conf dirlisting.conf \
	evhost.conf expire.conf fastcgi.conf \
	magnet.conf mime.conf mysql_vhost.conf proxy.conf \
	rrdtool.conf scgi.conf secdownload.conf \
	simple_vhost.conf ssi.conf status.conf \
	trigger_b4_dl.conf userdir.conf webdav.conf

LOGROOT=	/var/log/lighttpd
PLIST_SUB=	LOGROOT="${LOGROOT}"

.endif # !defined(_BUILDING_LIGHTTPD_MODULE)

.include <bsd.port.options.mk>

.if !defined(_BUILDING_LIGHTTPD_MODULE)

SUB_LIST=	REQUIRE="${REQUIRE}"

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
	@${MKDIR} -m 0700 ${STAGEDIR}${LOGROOT}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

test: build
	@cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} \
		check-TESTS

regression-test: test

.endif # !defined(_BUILDING_LIGHTTPD_MODULE)

.include <bsd.port.mk>
