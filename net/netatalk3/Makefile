PORTNAME=	netatalk
PORTVERSION=	3.2.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/netatalk-${PORTVERSION:S/./-/g}/
PKGNAMESUFFIX=	3

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	File server for Mac OS X
WWW=		http://netatalk.sourceforge.net/

LICENSE=	GPLv2

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libevent.so:devel/libevent

USES=		bdb:18 cpe gettext iconv meson perl5 pkgconfig shebangfix ssl tar:xz
USE_LDCONFIG=	yes
USE_RC_SUBR=	netatalk
#INSTALL_TARGET=install-strip
CPE_VENDOR=	netatalk_project

MESON_ARGS=		-Dwith-libgcrypt-dir=${LOCALBASE} \
			-Dwith-bdb=${LOCALBASE} \
			-Dwith-libiconv=${LOCALBASE} \
			-Dwith-ssl-dir=${OPENSSLBASE} \
			-Dwith-dtrace=false \
			-Ddisable-init-hooks=true \
			-Dpkg_config_path=${LOCALBASE}/libdata/pkgconfig \
			-Dwith-shadow=disabled \
			-Denable-pgp-uam=disabled \
			--localstatedir=/var \
			--infodir=${PREFIX}/share/info

OPTIONS_DEFINE=PAM KERBEROS5 LDAP SENDFILE KERBEROS DBUS MYSQL ACL LIBWRAP SPOTLIGHT
OPTIONS_DEFAULT=AVAHI DBUS KERBEROS LIBWRAP SENDFILE
OPTIONS_RADIO=ZEROCONF
OPTIONS_RADIO_ZEROCONF=AVAHI MDNSRESPONDER
ZEROCONF_DESC=	Zeroconf(Bonjour) support
MYSQL_DESC=	Enable MySQL CNID backend support
SENDFILE_DESC=	Enable Sendfile support
ACL_DESC=	Enable ACL support
SPOTLIGHT_DESC=	Enable Spotlight search support
OPTIONS_SUB=	yes
KERBEROS5_MESON_ON=	-Denable-krbV-uam=enabled \
			-Dwith-kerberos=enabled
KERBEROS5_MESON_OFF=	-Denable-krbV-uam=disabled \
			-Dwith-kerberos=disabled
KERBEROS_LIB_DEPENDS=libgpg-error.so:security/libgpg-error
PAM_MESON_ON=		-Dwith-pam=${LOCALBASE}
PAM_MESON_OFF=		-Dwithout-pam=true
AVAHI_CFLAGS=		-I${LOCALBASE}/include -L${LOCALBASE}/lib
AVAHI_LIB_DEPENDS=		libavahi-client.so:net/avahi-app
AVAHI_SUB_LIST=		ZEROCONF="avahi_daemon"
MDNSRESPONDER_CFLAGS=		-I${LOCALBASE}/include -L${LOCALBASE}/lib
MDNSRESPONDER_LIB_DEPENDS=		libdns_sd.so:net/mDNSResponder
MDNSRESPONDER_SUB_LIST=	ZEROCONF="mdnsd"
LDAP_MESON_ON=	-Dwith-ldap=${LOCALBASE}
LDAP_CFLAGS=		-I${LOCALBASE}/include -L${LOCALBASE}/lib
LDAP_USES=	ldap
SENDFILE_MESON_OFF=-Ddisable-sendfile=true
DBUS_USES=	gnome python
DBUS_USE=	GNOME=glib20
DBUS_LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
			libdbus-1.so:devel/dbus
DBUS_RUN_DEPENDS=	${PYTHON_SITELIBDIR}/dbus/_dbus.py:devel/py-dbus@${PY_FLAVOR}
DBUS_MESON_ON=		-Dwith-dbus-daemon=${LOCALBASE}/bin/dbus-daemon \
			-Dwith-dbus-sysconf-dir=${LOCALBASE}/etc/dbus-1/system.d
DBUS_MESON_OFF=		-Dwith-afpstats=disabled
MYSQL_USES=	mysql
MYSQL_MESON_OFF=-Dwith-mysql-config=/nonexistent
ACL_LIB_DEPENDS=	libsunacl.so:sysutils/libsunacl
ACL_MESON_ENABLED=with-acls
LIBWRAP_MESON_OFF=-Ddisable-tcp-wrappers=true
SPOTLIGHT_LIB_DEPENDS=	libtracker-sparql-3.0.so:sysutils/tracker3
SPOTLIGHT_MESON_OFF=	-Dwith-spotlight=disabled

SHEBANG_GLOB=	afpstats

CONFLICTS=	jday yudit # bin/dbd man/man1/uniconv.1.gz

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MAVAHI}=="" && ${PORT_OPTIONS:MMDNSRESPONDER}==""
SUB_LIST+=	ZEROCONF=""
MESON_ARGS+=-Denable-zeroconf=disabled
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DB_NAME%%|${BDB_INCLUDE_DIR:T}|' \
		${WRKSRC}/meson.build
#	@${REINPLACE_CMD} -e 's|\.dist|\.sample|g' \
#		${WRKSRC}/config/Makefile.in
#	@${REINPLACE_CMD} -e 's|%%PYTHONCMD%%|${PYTHONCMD}|' \
#		${WRKSRC}/contrib/shell_utils/afpstats

post-install:
	${INSTALL_SCRIPT} ${BUILD_WRKSRC}/contrib/macusers/macusers \
		${STAGEDIR}${PREFIX}/bin/macusers

.if ${PORT_OPTIONS:MPAM}
	${INSTALL_DATA} ${FILESDIR}/pam.conf ${STAGEDIR}${PREFIX}/etc/pam.d/netatalk.sample
.endif

.include <bsd.port.post.mk>
