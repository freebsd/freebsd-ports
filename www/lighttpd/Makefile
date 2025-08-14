PORTNAME=	lighttpd
PORTVERSION=	1.4.80
CATEGORIES=	www
MASTER_SITES=	https://download.lighttpd.net/lighttpd/releases-1.4.x/

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Secure, fast, compliant, and flexible Web Server
WWW=		https://www.lighttpd.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		compiler:c11 cmake cpe localbase:ldflags pkgconfig tar:xz

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--libdir=${PREFIX}/lib/lighttpd

TEST_TARGET=	check

PORTDOCS=	AUTHORS COPYING INSTALL NEWS README

USE_RC_SUBR=	lighttpd
REQUIRE=	LOGIN

OPTIONS_DEFINE=	ATTR DBI DOCS KRB5 LUA MAXMINDDB NETTLE LDAP SPAWNFCGI \
		WEBDAV ZSTD
OPTIONS_GROUP=	SSL
OPTIONS_GROUP_SSL=	OPENSSL GNUTLS MBEDTLS NSS WOLFSSL

OPTIONS_DEFAULT=	NETTLE LUA OPENSSL
OPTIONS_SUB=	yes

ATTR_DESC=	extended attributes support
DBI_DESC=	DBI authentication (mod_authn_dbi)
KRB5_DESC=	Kerberos authentication (mod_authn_gssapi)
LDAP_DESC=	LDAP authentication (mod_authn_ldap)
LUA_DESC=	lua support (mod_magnet)
MAXMINDDB_DESC=	IP-based geolocation lookup (mod_maxminddb)
NETTLE_DESC=	Crypto support from Nettle
SPAWNFCGI_DESC=	Depend on spawn-fcgi utility
WEBDAV_DESC=	WebDAV support
ZSTD_DESC=	mod_deflate support for zstd (Zstandard)

ATTR_CMAKE_BOOL=	WITH_XATTR
DBI_CMAKE_BOOL=		WITH_DBI
DBI_LIB_DEPENDS=	libdbi.so:databases/libdbi
GNUTLS_CMAKE_BOOL=	WITH_GNUTLS
GNUTLS_LIBS=		-lgnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
KRB5_CMAKE_BOOL=	WITH_KRB5
KRB5_CPPFLAGS=		${GSSAPICPPFLAGS}
KRB5_LDFLAGS=		${GSSAPILDFLAGS}
KRB5_LIBS=		${GSSAPILIBS}
KRB5_USES=		gssapi:mit
LDAP_CMAKE_BOOL=	WITH_LDAP
LDAP_USES=		ldap
LDAP_VARS=		REQUIRE+=slapd
LUA_USES=		lua
LUA_CMAKE_BOOL=		WITH_LUA
LUA_CMAKE_ON=		-DWITH_LUA_VERSION:STRING="lua-${LUA_VER}"
MAXMINDDB_CMAKE_BOOL=	WITH_MAXMINDDB
MAXMINDDB_LIB_DEPENDS=	libmaxminddb.so:net/libmaxminddb
MBEDTLS_CMAKE_BOOL=	WITH_MBEDTLS
MBEDTLS_LIB_DEPENDS=	libmbedtls.so:security/mbedtls2
NETTLE_CMAKE_BOOL=	WITH_NETTLE
NETTLE_LIB_DEPENDS=	libnettle.so:security/nettle
NSS_CMAKE_BOOL=		WITH_NSS
NSS_CPPFLAGS=		-I${LOCALBASE}/include/nspr
NSS_LIB_DEPENDS=	libnss3.so:security/nss
OPENSSL_USES=		ssl
OPENSSL_CMAKE_BOOL=	WITH_OPENSSL
SPAWNFCGI_RUN_DEPENDS=	spawn-fcgi:www/spawn-fcgi
WEBDAV_CMAKE_BOOL=	WITH_WEBDAV_LOCKS \
			WITH_WEBDAV_PROPS
WEBDAV_LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
			libsqlite3.so:databases/sqlite3
WOLFSSL_CMAKE_BOOL=	WITH_WOLFSSL
WOLFSSL_LIB_DEPENDS=	libwolfssl.so:security/wolfssl
ZSTD_CMAKE_BOOL=	WITH_ZSTD
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd

LIGHTTPD_CONF_FILES=	lighttpd.conf modules.conf lighttpd.annotated.conf

LIGHTTPD_CONF_D_FILES=	access_log.conf \
			auth.conf \
			cgi.conf \
			debug.conf \
			dirlisting.conf \
			evhost.conf \
			expire.conf \
			fastcgi.conf \
			magnet.conf \
			mime.conf \
			proxy.conf \
			rrdtool.conf \
			scgi.conf \
			simple_vhost.conf \
			ssi.conf \
			status.conf \
			userdir.conf \
			webdav.conf

USERS=		${WWWOWN}
GROUPS=		${WWWGRP}
CACHEDIR=	/var/cache/${PORTNAME}
LOGDIR=		/var/log/${PORTNAME}
HOMEDIR=	/var/run/${PORTNAME}
RUNDIR=		/var/run
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}" CACHEDIR="${CACHEDIR}" \
		HOMEDIR="${HOMEDIR}" LOGDIR="${LOGDIR}"
SUB_LIST=	REQUIRE="${REQUIRE}"

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s|/etc/lighttpd|${ETCDIR}|g" \
		${WRKSRC}/doc/config/lighttpd.conf
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
		${WRKSRC}/doc/config/lighttpd.annotated.conf
	@${REINPLACE_CMD} -e "s|/usr/bin/python|${LOCALBASE}/bin/python|" \
		${WRKSRC}/doc/config/conf.d/cgi.conf

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

.include <bsd.port.mk>
