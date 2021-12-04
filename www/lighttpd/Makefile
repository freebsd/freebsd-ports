# Created by: k@123.org

PORTNAME?=	lighttpd
PORTVERSION=	1.4.63
CATEGORIES?=	www
MASTER_SITES?=	https://download.lighttpd.net/lighttpd/releases-1.4.x/

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT?=	Secure, fast, compliant, and flexible Web Server

.if !defined(_BUILDING_LIGHTTPD_MODULE)
LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING
.endif

LIB_DEPENDS+=	libpcre2-8.so:devel/pcre2

USES=		autoreconf compiler:c11 gmake libtool localbase pkgconfig tar:xz
USE_CSTD=	gnu99

.if !defined(_BUILDING_LIGHTTPD_MODULE)
USES+=	cpe
.endif

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/lighttpd \
		--with-pcre2
INSTALL_TARGET=	install-strip

.if !defined(_BUILDING_LIGHTTPD_MODULE)
TEST_TARGET=	check

PORTDOCS=	AUTHORS COPYING INSTALL NEWS README

USE_RC_SUBR=	lighttpd
REQUIRE=	LOGIN

OPTIONS_DEFINE=	ATTR DBI DOCS GDBM IPV6 KRB5 LUA MAXMINDDB MEMCACHED NETTLE \
		LDAP SPAWNFCGI VALGRIND WEBDAV ZSTD
OPTIONS_GROUP=	SSL
OPTIONS_GROUP_SSL=	OPENSSL GNUTLS MBEDTLS NSS WOLFSSL

OPTIONS_DEFAULT=	NETTLE LUA OPENSSL
OPTIONS_SUB=	yes

ATTR_DESC=	extended attributes support
DBI_DESC=	DBI authentication (mod_authn_dbi)
GDBM_DESC=	gdbm storage (mod_trigger_b4_dl)
KRB5_DESC=	Kerberos authentication (mod_authn_gssapi)
LDAP_DESC=	LDAP authentication (mod_authn_ldap)
LUA_DESC=	lua support (mod_magnet)
MAXMINDDB_DESC=	IP-based geolocation lookup (mod_maxminddb)
MEMCACHED_DESC=	memcached storage (mod_trigger_b4_dl)
NETTLE_DESC=	Crypto support from Nettle
SPAWNFCGI_DESC=	Depend on spawn-fcgi utility
VALGRIND_DESC=	valgrind support
WEBDAV_DESC=	WebDAV support
ZSTD_DESC=	mod_deflate support for zstd (Zstandard)

ATTR_CONFIGURE_WITH=	attr
DBI_CONFIGURE_WITH=	dbi=${LOCALBASE}
DBI_LIB_DEPENDS=	libdbi.so:databases/libdbi
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
GDBM_CONFIGURE_WITH=	gdbm
GNUTLS_CONFIGURE_WITH=	gnutls=${LOCALBASE}
GNUTLS_LIBS=		-lgnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
IPV6_CONFIGURE_OFF=	--disable-ipv6
KRB5_CONFIGURE_WITH=	krb5
KRB5_CPPFLAGS=		${GSSAPICPPFLAGS}
KRB5_LDFLAGS=		${GSSAPILDFLAGS}
KRB5_LIBS=		${GSSAPILIBS}
KRB5_USES=		gssapi:mit
LDAP_CONFIGURE_WITH=	ldap
LDAP_USE=		openldap=yes
LDAP_VARS=		REQUIRE+=slapd
LUA_USES=		lua
LUA_CONFIGURE_WITH=	lua
LUA_CONFIGURE_ENV=	LUA_CFLAGS="-I${LUA_INCDIR}" LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}"
MAXMINDDB_CONFIGURE_WITH=	maxminddb=${LOCALBASE}
MAXMINDDB_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
MBEDTLS_CONFIGURE_WITH=	mbedtls=${LOCALBASE}
MBEDTLS_LIB_DEPENDS=	libmbedtls.so:security/mbedtls
MEMCACHED_LIB_DEPENDS=	libmemcached.so:databases/libmemcached
MEMCACHED_CONFIGURE_WITH=memcached
NETTLE_CONFIGURE_WITH=	nettle=${LOCALBASE}
NETTLE_LIB_DEPENDS=	libnettle.so:security/nettle
NSS_CONFIGURE_WITH=	nss=${LOCALBASE}
NSS_CPPFLAGS=		-I${LOCALBASE}/include/nspr
NSS_LIB_DEPENDS=	libnss3.so:security/nss
OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_WITH=	openssl
OPENSSL_CONFIGURE_ON=	--with-openssl-includes=${OPENSSLINC} --with-openssl-libs=${OPENSSLLIB}
SPAWNFCGI_RUN_DEPENDS=	spawn-fcgi:www/spawn-fcgi
VALGRIND_BUILD_DEPENDS=	valgrind:devel/valgrind
VALGRIND_RUN_DEPENDS=	valgrind:devel/valgrind
VALGRIND_CONFIGURE_WITH=valgrind
WEBDAV_USES=		gnome
WEBDAV_USE=		GNOME=libxml2
WEBDAV_LIB_DEPENDS=	libuuid.so:misc/e2fsprogs-libuuid \
			libsqlite3.so:databases/sqlite3
WEBDAV_CONFIGURE_WITH=	webdav-props webdav-locks
WOLFSSL_CONFIGURE_WITH=	wolfssl=${LOCALBASE}
WOLFSSL_LIB_DEPENDS=	libwolfssl.so:security/wolfssl
ZSTD_CONFIGURE_WITH=	zstd
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd

LIGHTTPD_CONF_FILES=	lighttpd.conf modules.conf

LIGHTTPD_CONF_D_FILES=	access_log.conf \
	auth.conf cgi.conf \
	debug.conf dirlisting.conf \
	evhost.conf expire.conf fastcgi.conf \
	magnet.conf mime.conf mysql_vhost.conf proxy.conf \
	rrdtool.conf scgi.conf secdownload.conf \
	simple_vhost.conf ssi.conf status.conf \
	trigger_b4_dl.conf userdir.conf webdav.conf

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
CACHEDIR=	/var/cache/${PORTNAME}
LOGDIR=		/var/log/${PORTNAME}
HOMEDIR=	/var/run/${PORTNAME}
RUNDIR=		/var/run
PLIST_SUB+=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
PLIST_SUB+=	CACHEDIR="${CACHEDIR}" HOMEDIR="${HOMEDIR}" LOGDIR="${LOGDIR}"

.endif # !defined(_BUILDING_LIGHTTPD_MODULE)

.include <bsd.port.options.mk>

.if !defined(_BUILDING_LIGHTTPD_MODULE)

SUB_LIST=	REQUIRE="${REQUIRE}"

post-patch:
	@${REINPLACE_CMD} -E -e \
		's|^(server.document-root.*=).*|\1 "${PREFIX}/www" + "/data"|' \
		-e "s|/etc/lighttpd|${ETCDIR}|g" \
		-e 's|^(server.event-handler.*=).*|\1 "freebsd-kqueue"|' \
		-e 's|^(server.network-backend.*=).*|\1 "writev"|' \
		-e "s|^(server.username.*=).*|\1 \"${WWWOWN}\"|" \
		-e "s|^(server.groupname.*=).*|\1 \"${WWWGRP}\"|" \
		-e "s|^(var.log_root.*=).*|\1 \"${LOGDIR}\"|" \
		-e "s|^(var.server_root.*=).*|\1 \"${WWWDIR}\"|" \
		-e "s|^(var.home_dir.*=).*|\1 \"${HOMEDIR}\"|" \
		-e "s|^(var.state_dir.*=).*|\1 \"${RUNDIR}\"|" \
		-e "s|^(var.cache_dir.*=).*|\1 \"${CACHEDIR}\"|" \
		${WRKSRC}/doc/config/lighttpd.conf
	@${REINPLACE_CMD} -e "s|/etc/lighttpd|${ETCDIR}|g" \
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
	@${MKDIR} ${STAGEDIR}${ETCDIR}/conf.d ${STAGEDIR}${ETCDIR}/vhosts.d
.for FILE in ${LIGHTTPD_CONF_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/config/${FILE} \
		${STAGEDIR}${ETCDIR}/${FILE}.sample
.endfor
.for FILE in ${LIGHTTPD_CONF_D_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/config/conf.d/${FILE} \
		${STAGEDIR}${ETCDIR}/conf.d/${FILE}.sample
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/config/vhosts.d/vhosts.template \
		${STAGEDIR}${ETCDIR}/vhosts.d/vhosts.template
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@${MKDIR} -m 0700 ${STAGEDIR}${CACHEDIR}
	@${MKDIR} -m 0700 ${STAGEDIR}${HOMEDIR}/sockets
	@${MKDIR} -m 0700 ${STAGEDIR}${LOGDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.endif # !defined(_BUILDING_LIGHTTPD_MODULE)

.include <bsd.port.mk>
