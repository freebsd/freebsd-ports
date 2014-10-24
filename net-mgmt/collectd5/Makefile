# Created by: Matt Peterson <matt@peterson.org>
# $FreeBSD$

PORTNAME=	collectd
PORTVERSION=	5.4.1
PORTREVISION=	12
CATEGORIES=	net-mgmt
MASTER_SITES=	http://collectd.org/files/
PKGNAMESUFFIX=	5

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Systems & network statistics collection daemon

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

# Only autoreconf stage and sigrok plugin need GLIB:
BUILD_DEPENDS=	${LOCALBASE}/share/aclocal/glib-2.0.m4:${PORTSDIR}/devel/glib20
LIB_DEPENDS=	libltdl.so:${PORTSDIR}/devel/libltdl

USES=		autoreconf gmake libtool pkgconfig tar:bzip2
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=		CGI DEBUG GCRYPT VIRT
OPTIONS_GROUP=		INPUT OUTPUT
OPTIONS_GROUP_OUTPUT=	RRDTOOL NOTIFYEMAIL NOTIFYDESKTOP RIEMANN
OPTIONS_GROUP_INPUT=	CURL DBI JSON MEMCACHEC MODBUS MONGODB MYSQL \
			NUTUPS PERL PGSQL PING PYTHON RABBITMQ REDIS \
			ROUTEROS SIGROK SNMP STATGRAB TOKYOTYRANT XML XMMS

CGI_DESC=		Install collection.cgi (requires rrdtool)
CURL_DESC=		Enable curl-based plugins (apache, nginx, etc)
DEBUG_DESC=		Enable debugging
DBI_DESC=		Enable dbi plugin
GCRYPT_DESC=		Build with libgcrypt
JSON_DESC=		Enable JSON plugins
MEMCACHEC_DESC=		Enable memcachec plugin
MODBUS_DESC=		Enable modbus plugin
MONGODB_DESC=		Enable MongoDB-based plugins
MYSQL_DESC=		Enable mysql-based plugins
NOTIFYEMAIL_DESC=	Enable notifications via email
NOTIFYDESKTOP_DESC=	Enable desktop notifications
NUTUPS_DESC=		Enable nut (ups) plugin
PERL_DESC=		Enable libperl plugin and binding
PGSQL_DESC=		Enable postgresql-based plugins
PING_DESC=		Enable ping plugin
PYTHON_DESC=		Enable python-based plugins
RABBITMQ_DESC=		Enable rabbitmq-based plugins
REDIS_DESC=		Enable redis-based plugins
RIEMANN_DESC=		Enable write_riemann plugin (via protobuf-c)
ROUTEROS_DESC=		Enable routeros plugin
RRDTOOL_DESC=		Enable rrdtool plugin (also rrdcached plugin)
SIGROK_DESC=		Enable sigrok plugin
SNMP_DESC=		Enable SNMP plugin
STATGRAB_DESC=		Enable statgrab-based plugins (disk, interface, etc)
TOKYOTYRANT_DESC=	Enable tokyotyrant plugin
VIRT_DESC=		Enable libvirt plugin (requires XML)
XML_DESC=		Enable XML plugins
XMMS_DESC=		Enable xmms plugin

USE_RC_SUBR=	collectd collectdmon

USE_LDCONFIG=	yes

CONFLICTS=	collectd-4.[0-9]*

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

# NOTE: Plugins without dependencies are defined further down.
CONFIGURE_ARGS=	--localstatedir=/var \
		--disable-all-plugins \
		--disable-static \
		--without-amqp \
		--without-java \
		--without-libaquaero5 \
		--without-libganglia \
		--without-libiptc \
		--without-libjvm \
		--without-libkstat \
		--without-libmodbus \
		--without-libnetlink \
		--without-libnetapp \
		--without-libopenipmi \
		--without-libowcapi \
		--without-libperfstat \
		--without-libsensors \
		--without-libvarnish \
		--without-lvm \
		--without-mic \
		--without-oracle

# NOTE: Plugins without external dependencies
CONFIGURE_ARGS+=	\
		--enable-aggregation \
		--enable-apcups \
		--enable-contextswitch \
		--enable-cpu \
		--enable-csv \
		--enable-df \
		--enable-dns \
		--enable-email \
		--enable-exec \
		--enable-filecount \
		--enable-load \
		--enable-logfile \
		--enable-match_empty_counter \
		--enable-match_hashed \
		--enable-match_regex \
		--enable-match_timediff \
		--enable-match_value \
		--enable-mbmon \
		--enable-memcached \
		--enable-memory \
		--enable-network \
		--enable-ntpd \
		--enable-openvpn \
		--enable-powerdns \
		--enable-pf \
		--enable-processes \
		--enable-statsd \
		--enable-swap \
		--enable-syslog \
		--enable-table \
		--enable-tail \
		--enable-target_notification \
		--enable-target_replace \
		--enable-target_scale \
		--enable-target_set \
		--enable-target_v5upgrade \
		--enable-tcpconns \
		--enable-teamspeak2 \
		--enable-ted \
		--enable-threshold \
		--enable-unixsock \
		--enable-uptime \
		--enable-uuid \
		--enable-write_graphite \
		--enable-zfs_arc

.if ${PORT_OPTIONS:MCGI}
RUN_DEPENDS+=	p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-CGI.pm>=0:${PORTSDIR}/www/p5-CGI.pm \
		p5-Data-Dumper>=0:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser
PLIST_SUB+=	CGI=""
.if empty(PORT_OPTIONS:MRRDTOOL)
IGNORE=		CGI requires RRDTOOL. Either select RRDTOOL or deselect CGI
.endif
.else
PLIST_SUB+=	CGI="@comment "
.endif

.if ${PORT_OPTIONS:MCURL}
LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=--with-libcurl=${LOCALBASE} \
		--enable-apache \
		--enable-curl \
		--enable-nginx \
		--enable-write_http
PLIST_SUB+=	CURL=""
.else
CONFIGURE_ARGS+=--without-libcurl \
		--disable-apache \
		--disable-curl \
		--disable-nginx \
		--disable-write_http
PLIST_SUB+=	CURL="@comment "
.endif

.if ${PORT_OPTIONS:MCURL} && ${PORT_OPTIONS:MJSON}
CONFIGURE_ARGS+=--enable-curl_json
PLIST_SUB+=	CURL_JSON=""
.else
CONFIGURE_ARGS+=--disable-curl_json
PLIST_SUB+=	CURL_JSON="@comment "
.endif

.if ${PORT_OPTIONS:MCURL} && ${PORT_OPTIONS:MXML}
CONFIGURE_ARGS+=	\
		--enable-ascent \
		--enable-bind \
		--enable-curl_xml
PLIST_SUB+=	CURL_XML=""
.else
CONFIGURE_ARGS+=	\
		--disable-ascent \
		--disable-bind \
		--disable-curl_xml
PLIST_SUB+=	CURL_XML="@comment "
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.else
CONFIGURE_ARGS+=--disable-debug
.endif

.if ${PORT_OPTIONS:MDBI}
LIB_DEPENDS+=	libdbi.so:${PORTSDIR}/databases/libdbi
CONFIGURE_ARGS+=--with-libdbi=${LOCALBASE} --enable-dbi
PLIST_SUB+=	DBI=""
CFLAGS+=	-Wno-deprecated-declarations
.else
CONFIGURE_ARGS+=--without-libdbi --disable-dbi
PLIST_SUB+=	DBI="@comment "
.endif

.if ${PORT_OPTIONS:MGCRYPT}
LIB_DEPENDS+=	libgcrypt.so:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=--with-libgcrypt=${LOCALBASE}
LIBS+=		-lgcrypt
.else
CONFIGURE_ARGS+=--without-libgcrypt
.endif

.if ${PORT_OPTIONS:MJSON}
LIB_DEPENDS+=	libyajl.so:${PORTSDIR}/devel/yajl
CONFIGURE_ARGS+=--with-libyajl=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-libyajl
.endif

.if ${PORT_OPTIONS:MMEMCACHEC}
LIB_DEPENDS+=	libmemcached.so:${PORTSDIR}/databases/libmemcached
CONFIGURE_ARGS+=--with-libmemcached=${LOCALBASE} --enable-memcachec
PLIST_SUB+=	MEMCACHEC=""
.else
CONFIGURE_ARGS+=--without-libmemcached
PLIST_SUB+=	MEMCACHEC="@comment "
.endif

.if ${PORT_OPTIONS:MMODBUS}
LIB_DEPENDS+=	libmodbus.so:${PORTSDIR}/comms/libmodbus
CONFIGURE_ARGS+=--enable-modbus
PLIST_SUB+=	MODBUS=""
.else
PLIST_SUB+=	MODBUS="@comment "
.endif

.if ${PORT_OPTIONS:MMONGODB}
LIB_DEPENDS+=	libmongoc.so:${PORTSDIR}/devel/mongo-c-driver
CONFIGURE_ARGS+=--with-libmongoc=${LOCALBASE} \
		--enable-write_mongodb
PLIST_SUB+=	MONGODB=""
.else
CONFIGURE_ARGS+=--without-libcmongoc \
		--disable-write_mongodb
PLIST_SUB+=	MONGODB="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-libmysql=${LOCALBASE} --enable-mysql
PLIST_SUB+=	MYSQL=""
.else
CONFIGURE_ARGS+=--without-libmysql --disable-mysql
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MNOTIFYDESKTOP}
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--with-libnotify=${LOCALBASE} \
		--enable-notify_desktop
PLIST_SUB+=	NOTIFYDESKTOP=""
.else
CONFIGURE_ARGS+=--without-libnotify --disable-notify_desktop
PLIST_SUB+=	NOTIFYDESKTOP="@comment "
.endif

.if ${PORT_OPTIONS:MNOTIFYEMAIL}
LIB_DEPENDS+=	libesmtp.so:${PORTSDIR}/mail/libesmtp
CONFIGURE_ARGS+=--with-libesmtp=${LOCALBASE} \
		--enable-notify_email
PLIST_SUB+=	NOTIFYEMAIL=""
.else
CONFIGURE_ARGS+=--without-libesmtp --disable-notify_email
PLIST_SUB+=	NOTIFYEMAIL="@comment "
.endif

.if ${PORT_OPTIONS:MNUTUPS}
LIB_DEPENDS+=	libupsclient.so:${PORTSDIR}/sysutils/nut
CONFIGURE_ARGS+=--with-upsclient=${LOCALBASE} --enable-nut
PLIST_SUB+=	NUTUPS=""
.else
CONFIGURE_ARGS+=--without-libupsclient --disable-nut
PLIST_SUB+=	NUTUPS="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
USES+=		perl5
CONFIGURE_ARGS+=--with-perl=${PERL} --with-perl-bindings --enable-perl
PLIST_SUB+=	PERL=""
.else
CONFIGURE_ARGS+=--without-perl --without-perl-bindings --disable-perl
PLIST_SUB+=	PERL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-postgresql=${LOCALBASE} --enable-postgresql --with-libpq
PLIST_SUB+=	PGSQL=""
.else
CONFIGURE_ARGS+=--without-postgresql --disable-postgresql --without-libpq
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPING}
LIB_DEPENDS+=	liboping.so:${PORTSDIR}/net/liboping
CONFIGURE_ARGS+=--with-liboping=${LOCALBASE} --enable-ping
PLIST_SUB+=	PING=""
.else
CONFIGURE_ARGS+=--without-liboping --disable-ping
PLIST_SUB+=	PING="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python
CONFIGURE_ARGS+=--with-python=${PYTHON_CMD} --enable-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--without-python --disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MRABBITMQ}
LIB_DEPENDS+=	librabbitmq.so:${PORTSDIR}/net/rabbitmq-c
CONFIGURE_ARGS+=--with-librabbitmq=${LOCALBASE} \
		--enable-rabbitmq
PLIST_SUB+=	RABBITMQ=""
.else
CONFIGURE_ARGS+=--without-librabbitmq \
		--disable-rabbitmq
PLIST_SUB+=	RABBITMQ="@comment "
.endif

.if ${PORT_OPTIONS:MREDIS}
LIB_DEPENDS+=	libcredis.so:${PORTSDIR}/databases/credis
CONFIGURE_ARGS+=--with-libcredis=${LOCALBASE} \
		--enable-redis \
		--enable-write_redis
PLIST_SUB+=	REDIS=""
.else
CONFIGURE_ARGS+=--without-libcredis \
		--disable-redis \
		--disable-write_redis
PLIST_SUB+=	REDIS="@comment "
.endif

.if ${PORT_OPTIONS:MRIEMANN}
LIB_DEPENDS+=	libprotobuf-c.so:${PORTSDIR}/devel/protobuf-c
CONFIGURE_ARGS+=--enable-write_riemann
PLIST_SUB+=	RIEMANN=""
.else
CONFIGURE_ARGS+=--disable-write_riemann
PLIST_SUB+=	RIEMANN="@comment "
.endif

.if ${PORT_OPTIONS:MROUTEROS}
LIB_DEPENDS+=	librouteros.so:${PORTSDIR}/net/librouteros
CONFIGURE_ARGS+=--with-librouteros=${LOCALBASE} --enable-routeros
PLIST_SUB+=	ROUTEROS=""
.else
CONFIGURE_ARGS+=--without-librouteros --disable-routeros
PLIST_SUB+=	ROUTEROS="@comment "
.endif

.if ${PORT_OPTIONS:MRRDTOOL}
LIB_DEPENDS+=	librrd.so:${PORTSDIR}/databases/rrdtool
CONFIGURE_ARGS+=--with-librrd=${LOCALBASE} \
		--enable-rrdcached \
		--enable-rrdtool
PLIST_SUB+=	RRDTOOL=""
.else
CONFIGURE_ARGS+=--without-librrd \
		--disable-rrdcached \
		--disable-rrdtool
PLIST_SUB+=	RRDTOOL="@comment "
.endif

.if ${PORT_OPTIONS:MSTATGRAB}
USES+=		pkgconfig
LIB_DEPENDS+=	libstatgrab.so:${PORTSDIR}/devel/libstatgrab
LIBS+=		`pkg-config --libs libstatgrab`
CONFIGURE_ARGS+=--with-libstatgrab=${LOCALBASE} \
		--enable-disk \
		--enable-interface
PLIST_SUB+=	STATGRAB=""
.else
CONFIGURE_ARGS+=--without-libstatgrab
PLIST_SUB+=	STATGRAB="@comment "
.endif

.if ${OSVERSION} >= 900007
CONFIGURE_ARGS+=--enable-users
PLIST_SUB+=	USERS=""
.elif ${PORT_OPTIONS:MSTATGRAB}
CONFIGURE_ARGS+=--enable-users
PLIST_SUB+=	USERS=""
.else
PLIST_SUB+=	USERS="@comment "
.endif

.if ${PORT_OPTIONS:MSIGROK}
USE_GNOME+=	glib20
LIB_DEPENDS+=	libsigrok.so:${PORTSDIR}/devel/libsigrok
CONFIGURE_ARGS+=--with-libsigrok --enable-sigrok
PLIST_SUB+=	SIGROK=""
.else
CONFIGURE_ARGS+=--disable-sigrok
PLIST_SUB+=	SIGROK="@comment "
.endif

.if ${PORT_OPTIONS:MSNMP}
LIB_DEPENDS+=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=--with-libnetsnmp --enable-snmp
PLIST_SUB+=	SNMP=""
.else
CONFIGURE_ARGS+=--without-libnetsnmp
PLIST_SUB+=	SNMP="@comment "
.endif

.if ${PORT_OPTIONS:MTOKYOTYRANT}
LIB_DEPENDS+=	libtokyotyrant.so:${PORTSDIR}/databases/tokyotyrant
CONFIGURE_ARGS+=--with-libtokyotyrant=${LOCALBASE} --enable-tokyotyrant
PLIST_SUB+=	TOKYOTYRANT=""
.else
CONFIGURE_ARGS+=--without-libtokyotyrant --disable-tokyotyrant
PLIST_SUB+=	TOKYOTYRANT="@comment "
.endif

.if ${PORT_OPTIONS:MVIRT}
.if empty(PORT_OPTIONS:MXML)
IGNORE=		VIRT requires XML. Either select XML or deselect VIRT.
.endif
LIB_DEPENDS+=	libvirt.so:${PORTSDIR}/devel/libvirt
CONFIGURE_ARGS+=--enable-libvirt
PLIST_SUB+=	VIRT=""
.else
CONFIGURE_ARGS+=--without-libvirt --disable-libvirt
PLIST_SUB+=	VIRT="@comment "
.endif

.if ${PORT_OPTIONS:MXML}
LIB_DEPENDS+=	libxml2.so:${PORTSDIR}/textproc/libxml2
CONFIGURE_ARGS+=--with-libxml2=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MXMMS}
LIB_DEPENDS+=	libxmms.so:${PORTSDIR}/multimedia/xmms
CONFIGURE_ARGS+=--with-libxmms=${LOCALBASE} --enable-xmms
CFLAGS+=	`xmms-config --cflags`
PLIST_SUB+=	XMMS=""
.else
CONFIGURE_ARGS+=--without-libxmms --disable-xmms
PLIST_SUB+=	XMMS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's/-Werror//' \
		${WRKSRC}/configure.ac ${WRKSRC}/src/Makefile.am \
		${WRKSRC}/src/libcollectdclient/Makefile.am
	@${REINPLACE_CMD} \
		-e 's;@prefix@/var/;/var/;' \
		-e 's;/var/lib/;/var/db/;' \
		-e 's;@localstatedir@/lib/;/var/db/;' \
		${WRKSRC}/src/collectd.conf.in
	@${REINPLACE_CMD} \
		-e 's;/etc/collection\.conf;${WWWDIR}/collection.conf;' \
		${WRKSRC}/contrib/collection.cgi
	@${REINPLACE_CMD} \
		-e 's;/opt/collectd/var/lib;/var/db;' \
		-e 's;/opt/collectd/lib;${PREFIX}/lib;' \
		${WRKSRC}/contrib/collection.conf

post-install:
	@${MKDIR} ${STAGEDIR}/var/db/collectd
.if ${PORT_OPTIONS:MCGI}
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/collection.cgi ${STAGEDIR}${WWWDIR}/
	${INSTALL_DATA} ${WRKSRC}/contrib/collection.conf \
		${STAGEDIR}${WWWDIR}/collection.conf.sample
.endif

post-stage:
.if ${PORT_OPTIONS:MPERL}
	@${SED} -i '' -e 's,${STAGEDIR},,g' ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Collectd/.packlist
.endif

.include <bsd.port.mk>
