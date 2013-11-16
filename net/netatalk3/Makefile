# Created by: stb
# $FreeBSD$

PORTNAME=	netatalk
PORTVERSION=	3.1.0
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=${PORTNAME}/${PORTNAME}/3.1
PKGNAMESUFFIX=	3

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	File server for Mac OS X

LICENSE=	GPLv2

LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt \
    		event-2:${PORTSDIR}/devel/libevent2

USE_AUTOTOOLS=	libtool
USE_BDB=	46+
USE_BZIP2=	yes
USES=		iconv gmake pkgconfig perl5
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_RC_SUBR=	netatalk

CONFIGURE_ARGS+=	--enable-tcp-wrappers \
			--with-pkgconfdir=${PREFIX}/etc \
			--with-libgcrypt-dir=${LOCALBASE} \
			--with-uams-path=${PREFIX}/libexec/netatalk-uams \
			--with-bdb=${LOCALBASE} \
			${ICONV_CONFIGURE_BASE} \
			--localstatedir=/var \
			--disable-bundled-libevent \
			--with-libevent-header=${LOCALBASE}/include \
			--with-libevent-lib=${LOCALBASE}/lib/event2

OPTIONS_DEFINE=PAM KRB5 LDAP SENDFILE KERBEROS DTRACE DBUS MYSQL
OPTIONS_DEFAULT=KERBEROS DBUS
OPTIONS_RADIO=ZEROCONF
OPTIONS_RADIO_ZEROCONF=AVAHI MDNSRESPONDER
OPTIONS_DEFAULT+=AVAHI

NOZEROCONF_DESC=Disable Zeroconf(Bonjour) support
KRB5_DESC=	Enable Kerberos V UAM
DTRACE_DESC=	Enable DTrace support
SENDFILE_DESC=	Enable Sendfile support
MYSQL_DESC=	Enable MySQL CNID backend support

.include <bsd.port.options.mk>

CONFLICTS=	bigloo-2.* cap-6.0.* tct-1.* netatalk-[12]* yudit-[0-9]*

.if ${PORT_OPTIONS:MKRB5}
CONFIGURE_ARGS+=	--enable-krbV-uam
PLIST_SUB+=		NETATALKKRB5=""
.else
PLIST_SUB+=		NETATALKKRB5="@comment "
.endif

.if ${PORT_OPTIONS:MDTRACE}
CONFIGURE_ARGS+=	--with-dtrace
.else
CONFIGURE_ARGS+=	--without-dtrace
.endif

.if ${PORT_OPTIONS:MKERBEROS}
CONFIGURE_ARGS+=	--with-kerberos
.else
CONFIGURE_ARGS+=	--without-kerberos
.endif

.if ${PORT_OPTIONS:MPAM}
CONFIGURE_ARGS+=	--with-pam
PLIST_SUB+=		NETATALKPAM=""
.else
CONFIGURE_ARGS+=	--without-pam
PLIST_SUB+=		NETATALKPAM="@comment "
.endif

.if ${PORT_OPTIONS:MNOZEROCONF}
CONFIGURE_ARGS+=	--disable-zeroconf
SUB_LIST+=		ZEROCONF=""
.endif

.if ${PORT_OPTIONS:MAVAHI}
CONFIGURE_ARGS+=	--enable-zeroconf=${LOCALBASE}
CFLAGS+=		-I${LOCALBASE}/include -L${LOCALBASE}/lib
LIB_DEPENDS+=		avahi-client:${PORTSDIR}/net/avahi-app
SUB_LIST+=		ZEROCONF="avahi_daemon"
.endif

.if ${PORT_OPTIONS:MMDNSRESPONDER}
CONFIGURE_ARGS+=	--enable-zeroconf=${LOCALBASE}
CFLAGS+=		-I${LOCALBASE}/include -L${LOCALBASE}/lib
LIB_DEPENDS+=		dns_sd:${PORTSDIR}/net/mDNSResponder
SUB_LIST+=		ZEROCONF="mdnsd"
.endif

.if ${PORT_OPTIONS:MLDAP}
CONFIGURE_ARGS+=	--with-ldap=${LOCALBASE}
CFLAGS+=		-I${LOCALBASE}/include -L${LOCALBASE}/lib
USE_OPENLDAP=		yes
.else
CONFIGURE_ARGS+=	--without-ldap
.endif

.if ${PORT_OPTIONS:MSENDFILE}
CONFIGURE_ARGS+=	--enable-sendfile
.else
CONFIGURE_ARGS+=	--disable-sendfile
.endif

.if ${PORT_OPTIONS:MDBUS} || exists(${LOCALBASE}/libdata/pkgconfig/dbus-glib-1.pc)
LIB_DEPENDS+=		dbus-glib-1:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS+=		${LOCALBASE}/libdata/pkgconfig/dbus-python.pc:${PORTSDIR}/devel/py-dbus
PLIST_SUB+=		DBUS=""
.else
PLIST_SUB+=		DBUS="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
.else
CONFIGURE_ARGS+=--with-mysql-config=/nonexistent
.endif

.if ${OSVERSION} < 800031
PLIST_SUB+=	ATFUNCS="@comment "
.else
PLIST_SUB+=	ATFUNCS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%DB_NAME%%|${BDB_INCLUDE_DIR:T}| ; \
	    	s|%%DB_LIB%%|-l${BDB_LIB_NAME}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/configure

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/macusers/macusers \
		${STAGEDIR}${PREFIX}/bin/macusers
	[ -f ${STAGEDIR}${PREFIX}/etc/afp.conf ] || \
		${INSTALL_DATA} -c ${STAGEDIR}${PREFIX}/etc/afp.conf.dist ${STAGEDIR}${PREFIX}/etc/afp.conf
	[ -f ${STAGEDIR}${PREFIX}/etc/extmap.conf ] || \
		${INSTALL_DATA} -c ${STAGEDIR}${PREFIX}/etc/extmap.conf.dist ${STAGEDIR}${PREFIX}/etc/extmap.conf
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
