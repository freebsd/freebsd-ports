# Created by: Matt Peterson <matt@peterson.org>
# $FreeBSD$

PORTNAME=	collectd
PORTVERSION=	5.3.0
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	http://collectd.org/files/

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Systems & network statistics collection daemon

USES=		gmake
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf autoheader automake libltdl

LATEST_LINK=	collectd5

OPTIONS_DEFINE=		CGI CURL DEBUG DBI GCRYPT JSON MEMCACHEC MODBUS MYSQL NUTUPS PGSQL PING PYTHON REDIS ROUTEROS RRDTOOL SNMP STATGRAB TOKYOTYRANT VIRT XML XMMS

CGI_DESC=		Install collection.cgi (requires rrdtool)
CURL_DESC=		Enable curl-based plugins (apache, nginx, etc)
DEBUG_DESC=		Enable debugging
DBI_DESC=		Enable dbi plugin
GCRYPT_DESC=		Build with libgcrypt
JSON_DESC=		Enable JSON plugins
MEMCACHEC_DESC=		Enable memcachec plugin
MODBUS_DESC=		Enable modbus plugin
MYSQL_DESC=		Enable mysql-based plugins
NUTUPS_DESC=		Enable nut (ups) plugin
PGSQL_DESC=		Enable postgresql-based plugins
PING_DESC=		Enable ping plugin
PYTHON_DESC=		Enable python-based plugins
REDIS_DESC=		Enable redis-based plugins
ROUTEROS_DESC=		Enable routeros plugin
RRDTOOL_DESC=		Enable rrdtool plugin (also rrdcached plugin)
SNMP_DESC=		Enable SNMP plugin
STATGRAB_DESC=		Enable statgrab-based plugins (disk, interface, etc)
TOKYOTYRANT_DESC=	Enable tokyotyrant plugin
VIRT_DESC=		Enable libvirt plugin (requires XML)
XML_DESC=		Enable XML plugins
XMMS_DESC=		Enable xmms plugin

MAN1=		collectd.1 collectd-nagios.1 collectd-tg.1 collectdmon.1 collectdctl.1
MAN5=		collectd.conf.5 collectd-email.5 collectd-exec.5 \
		collectd-snmp.5 collectd-unixsock.5 collectd-perl.5 \
		collectd-java.5 collectd-python.5 types.db.5 collectd-threshold.5
USE_RC_SUBR=	collectd collectdmon

USE_LDCONFIG=	yes

CONFLICTS=	collectd-4.[0-9]*

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

# NOTE: Plugins without dependencies are defined further down.
CONFIGURE_ARGS=	--localstatedir=/var \
		--disable-all-plugins \
		--disable-getifaddrs \
		--disable-static \
		--without-java \
		--without-libcredis \
		--without-libcurl \
		--without-libdbi \
		--without-libesmtp \
		--without-libganglia \
		--without-libgcrypt \
		--without-libiptc \
		--without-libjvm \
		--without-libkstat \
		--without-libmemcached \
		--without-libmodbus \
		--without-libmongoc \
		--without-libmysql \
		--without-libnetlink \
		--without-libnetapp \
		--without-libnetsnmp \
		--without-libnotify \
		--without-libopenipmi \
		--without-liboping \
		--without-libowcapi \
		--without-libperfstat \
		--without-libperl \
		--without-libpq \
		--without-librabbitmq \
		--without-librouteros \
		--without-librrd \
		--without-libsensors \
		--without-libstatgrab \
		--without-libtokyotyrant \
		--without-libupsclient \
		--without-libvarnish \
		--without-libvirt \
		--without-libxmms \
		--without-libyajl \
		--without-oracle \
		--without-perl-bindings \
		--without-python

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
		--enable-users \
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
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=--with-libcurl=${LOCALBASE} \
		--enable-apache \
		--enable-curl \
		--enable-nginx \
		--enable-write_http
PLIST_SUB+=	CURL=""
.else
PLIST_SUB+=	CURL="@comment "
.endif

.if ${PORT_OPTIONS:MCURL} && ${PORT_OPTIONS:MJSON}
CONFIGURE_ARGS+=--enable-curl_json
PLIST_SUB+=	CURL_JSON=""
.else
PLIST_SUB+=	CURL_JSON="@comment "
.endif

.if ${PORT_OPTIONS:MCURL} && ${PORT_OPTIONS:MXML}
CONFIGURE_ARGS+=	\
		--enable-ascent \
		--enable-bind \
		--enable-curl_xml
PLIST_SUB+=	CURL_XML=""
.else
PLIST_SUB+=	CURL_XML="@comment "
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.endif

.if ${PORT_OPTIONS:MDBI}
LIB_DEPENDS+=	dbi:${PORTSDIR}/databases/libdbi
CONFIGURE_ARGS+=--with-libdbi=${LOCALBASE} --enable-dbi
PLIST_SUB+=	DBI=""
.else
PLIST_SUB+=	DBI="@comment "
.endif

.if ${PORT_OPTIONS:MGCRYPT}
LIB_DEPENDS+=	gcrypt:${PORTSDIR}/security/libgcrypt
CONFIGURE_ARGS+=--with-libgcrypt=${LOCALBASE}
LDFLAGS+=	-lgcrypt
.endif

.if ${PORT_OPTIONS:MJSON}
LIB_DEPENDS+=	yajl:${PORTSDIR}/devel/yajl
CONFIGURE_ARGS+=--with-libyajl=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MMEMCACHEC}
LIB_DEPENDS+=	memcached:${PORTSDIR}/databases/libmemcached
CONFIGURE_ARGS+=--with-libmemcached=${LOCALBASE} --enable-memcachec
PLIST_SUB+=	MEMCACHEC=""
.else
PLIST_SUB+=	MEMCACHEC="@comment "
.endif

.if ${PORT_OPTIONS:MMODBUS}
LIB_DEPENDS+=	modbus:${PORTSDIR}/comms/libmodbus
CONFIGURE_ARGS+=--enable-modbus
PLIST_SUB+=	MODBUS=""
.else
PLIST_SUB+=	MODBUS="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-libmysql=${LOCALBASE} --enable-mysql
PLIST_SUB+=	MYSQL=""
.else
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MNOTIFYEMAIL}
LIB_DEPENDS+=	esmtp:${PORTSDIR}/mail/libesmtp
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--with-libesmtp=${LOCALBASE} \
		--with-libnotify=${LOCALBASE} \
		--enable-notify_email
PLIST_SUB+=	NOTIFYEMAIL=""
.else
PLIST_SUB+=	NOTIFYEMAIL="@comment "
.endif

.if ${PORT_OPTIONS:MNUTUPS}
LIB_DEPENDS+=	upsclient:${PORTSDIR}/sysutils/nut
CONFIGURE_ARGS+=--with-upsclient=${LOCALBASE} --enable-nut
PLIST_SUB+=	NUTUPS=""
.else
PLIST_SUB+=	NUTUPS="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--with-postgresql=${LOCALBASE} --enable-postgresql --with-libpq
PLIST_SUB+=	PGSQL=""
.else
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPING}
LIB_DEPENDS+=	oping:${PORTSDIR}/net/liboping
CONFIGURE_ARGS+=--with-liboping=${LOCALBASE} --enable-ping
PLIST_SUB+=	PING=""
.else
PLIST_SUB+=	PING="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USE_PYTHON=	yes
CONFIGURE_ARGS+=--with-python=${LOCALBASE} --enable-python
PLIST_SUB+=	PYTHON=""
.else
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MREDIS}
LIB_DEPENDS+=	credis:${PORTSDIR}/databases/credis
CONFIGURE_ARGS+=--with-libcredis=${LOCALBASE} \
		--enable-redis \
		--enable-write_redis
PLIST_SUB+=	REDIS=""
.else
PLIST_SUB+=	REDIS="@comment "
.endif

.if ${PORT_OPTIONS:MROUTEROS}
LIB_DEPENDS+=	routeros:${PORTSDIR}/net/librouteros
CONFIGURE_ARGS+=--with-librouteros=${LOCALBASE} --enable-routeros
PLIST_SUB+=	ROUTEROS=""
.else
PLIST_SUB+=	ROUTEROS="@comment "
.endif

.if ${PORT_OPTIONS:MRRDTOOL}
LIB_DEPENDS+=	rrd:${PORTSDIR}/databases/rrdtool
CONFIGURE_ARGS+=--with-librrd=${LOCALBASE} \
		--enable-rrdcached \
		--enable-rrdtool
PLIST_SUB+=	RRDTOOL=""
.else
PLIST_SUB+=	RRDTOOL="@comment "
.endif

.if ${PORT_OPTIONS:MSTATGRAB}
USES+=		pkgconfig
LIB_DEPENDS+=	statgrab:${PORTSDIR}/devel/libstatgrab
CONFIGURE_ENV+= LIBS="`pkg-config --libs libstatgrab`"
CONFIGURE_ARGS+=--with-libstatgrab=${LOCALBASE} \
		--enable-disk \
		--enable-interface
PLIST_SUB+=	STATGRAB=""
.else
PLIST_SUB+=	STATGRAB="@comment "
.endif

.if ${PORT_OPTIONS:MSNMP}
LIB_DEPENDS+=	netsnmp:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=--with-libnetsnmp --enable-snmp
PLIST_SUB+=	SNMP=""
.else
PLIST_SUB+=	SNMP="@comment "
.endif

.if ${PORT_OPTIONS:MTOKYOTYRANT}
LIB_DEPENDS+=	tokyotyrant:${PORTSDIR}/databases/tokyotyrant
CONFIGURE_ARGS+=--with-libtokyotyrant=${LOCALBASE} --enable-tokyotyrant
PLIST_SUB+=	TOKYOTYRANT=""
.else
PLIST_SUB+=	TOKYOTYRANT="@comment "
.endif

.if ${PORT_OPTIONS:MVIRT}
LIB_DEPENDS+=	virt.1001:${PORTSDIR}/devel/libvirt
CONFIGURE_ARGS+=--enable-libvirt
.if empty(PORT_OPTIONS:MXML)
IGNORE=		VIRT requires XML. Either select XML or deselect VIRT.
.endif
PLIST_SUB+=	VIRT=""
.else
PLIST_SUB+=	VIRT="@comment "
.endif

.if ${PORT_OPTIONS:MXML}
LIB_DEPENDS+=	xml2:${PORTSDIR}/textproc/libxml2
CONFIGURE_ARGS+=--with-libxml2=${LOCALBASE}
.endif

.if ${PORT_OPTIONS:MXMMS}
LIB_DEPENDS+=	xmms:${PORTSDIR}/multimedia/xmms
CONFIGURE_ARGS+=--with-libxmms=${LOCALBASE} --enable-xmms
CFLAGS+=	`xmms-config --cflags`
PLIST_SUB+=	XMMS=""
.else
PLIST_SUB+=	XMMS="@comment "
.endif

AUTOTOOLSFILES=	aclocal.m4

post-patch:
	@${REINPLACE_CMD} -e 's|1.11.1|%%AUTOMAKE_APIVER%%|g' \
			  -e 's|2.67|%%AUTOCONF_VERSION%%|g' \
			  ${WRKSRC}/aclocal.m4
	@${REINPLACE_CMD} \
		-e 's;@prefix@/var/;/var/;' \
		-e 's;/var/lib/;/var/db/;' \
		-e 's;@localstatedir@/lib/;/var/db/;' \
		${WRKSRC}/src/collectd.conf.in
	@${REINPLACE_CMD} -e '/$$[(]mkinstalldirs)/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} \
		-e 's;/etc/collection\.conf;${WWWDIR}/collection.conf;' \
		${WRKSRC}/contrib/collection.cgi
	@${REINPLACE_CMD} \
		-e 's;/opt/collectd/var/lib;/var/db;' \
		-e 's;/opt/collectd/lib;${PREFIX}/lib;' \
		${WRKSRC}/contrib/collection.conf
	@${REINPLACE_CMD} \
		-e 's;{libdir}/pkgconfig;{prefix}/libdata/pkgconfig;' \
		${WRKSRC}/configure.in

post-install:
	${MKDIR} /var/db/collectd
	if [ ! -f ${PREFIX}/etc/collectd.conf ]; then \
		${CP} -p ${PREFIX}/etc/collectd.conf.sample \
			${PREFIX}/etc/collectd.conf ; \
	fi
.if ${PORT_OPTIONS:MCGI}
	${MKDIR} ${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/collection.cgi ${WWWDIR}/
	${INSTALL_DATA} ${WRKSRC}/contrib/collection.conf \
		${WWWDIR}/collection.conf.sample
	if [ ! -f ${WWWDIR}/collection.conf ]; then \
		${CP} -p ${WWWDIR}/collection.conf.sample \
			${WWWDIR}/collection.conf ; \
	fi
.endif

.include <bsd.port.mk>
