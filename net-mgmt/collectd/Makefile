# Created by: Matt Peterson <matt@peterson.org>
# $FreeBSD$

PORTNAME=	collectd
PORTVERSION=	4.10.9
PORTREVISION=	16
CATEGORIES=	net-mgmt
MASTER_SITES=	http://collectd.org/files/

MAINTAINER=	ports@bsdserwis.com
COMMENT=	Systems & network statistics collection daemon

LICENSE=	GPLv2

LIB_DEPENDS=	libltdl.so:${PORTSDIR}/devel/libltdl

GNU_CONFIGURE=	yes
USES=		autoreconf gmake libtool
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=		CGI BIND DEBUG GCRYPT LIBVIRT
OPTIONS_GROUP=		INPUT OUTPUT
OPTIONS_GROUP_OUTPUT=	RRDTOOL RRDCACHED WRITE_HTTP NOTIFYEMAIL NOTIFYDESKTOP
OPTIONS_GROUP_INPUT=	APACHE APCUPS CURL CURL_JSON CURL_XML DBI DISK \
			NUTUPS INTERFACE MBMON MEMCACHED MYSQL NGINX \
			OPENVPN PDNS PGSQL PING PYTHON ROUTEROS SNMP \
			TOKYOTYRANT XMMS
OPTIONS_DEFAULT=	INTERFACE PING SNMP RRDTOOL RRDCACHED

CGI_DESC=		Install collection.cgi (requires RRDTOOL)
BIND_DESC=		Enable BIND 9.5+ statistics
# INPUT
APACHE_DESC=		Apache mod_status (libcurl)
APCUPS_DESC=		APC UPS (apcupsd)
CURL_DESC=		CURL generic web statistics
CURL_JSON_DESC=		CURL JSON generic web statistics
CURL_XML_DESC=		CURL XML generic web statistics
DBI_DESC=		database abstraction library
DISK_DESC=		Disk performance statistics
NUTUPS_DESC=		NUT UPS daemon
INTERFACE_DESC=		Network interfaces (libstatgrab)
MBMON_DESC=		MBMon
MEMCACHED_DESC=		Memcached
NGINX_DESC=		Nginx
NOTIFYEMAIL_DESC=	Email notifications (libesmtp)
NOTIFYDESKTOP_DESC=	Email notifications (libnotify)
OPENVPN_DESC=		OpenVPN statistics
PDNS_DESC=		PowerDNS
PING_DESC=		Network latency (liboping)
ROUTEROS_DESC=		RouterOS plugin
TOKYOTYRANT_DESC=	Tokyotyrant database
XMMS_DESC=		XMMS
# OUTPUT
RRDTOOL_DESC=		RRDTool
RRDCACHED_DESC=		RRDTool Cached (require RRDTOOL)
WRITE_HTTP_DESC=	write_http

USE_RC_SUBR=	collectd collectdmon

USE_LDCONFIG=	yes

CONFLICTS=	collectd-5.[0-9]*

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

# NOTE: Feel free to submit patches adding support for any of these
#       disabled plugins.  If a plugin requires external dependencies,
#       make it optional through OPTIONS defaulting to Off.  Some of
#       these are Linux specific, but others will probably run on
#       FreeBSD as well, given a bit of careful attention.
CONFIGURE_ARGS=	--localstatedir=/var \
		--disable-getifaddrs \
		--disable-apple_sensors \
		--disable-ascent \
		--disable-battery \
		--disable-conntrack \
		--disable-contextswitch \
		--disable-cpufreq \
		--disable-entropy \
		--disable-fscache \
		--disable-gmond \
		--disable-hddtemp \
		--disable-ipmi \
		--disable-iptables \
		--disable-ipvs \
		--disable-irq \
		--disable-java \
		--disable-madwifi \
		--disable-match_empty_counter \
		--disable-match_hashed \
		--disable-match_regex \
		--disable-match_timediff \
		--disable-match_value \
		--disable-memcachec \
		--disable-modbus \
		--disable-multimeter \
		--disable-netapp \
		--disable-netlink \
		--disable-nfs \
		--disable-olsrd \
		--disable-onewire \
		--disable-oracle \
		--disable-perl \
		--disable-pinba \
		--disable-protocols \
		--disable-sensors \
		--disable-serial \
		--disable-table \
		--disable-tape \
		--disable-target_notification \
		--disable-target_replace \
		--disable-target_scale \
		--disable-target_set \
		--disable-teamspeak2 \
		--disable-ted \
		--disable-thermal \
		--disable-users \
		--disable-vmem \
		--disable-vserver \
		--disable-wireless \
		--without-perl-bindings \
		--without-librabbitmq \
		--disable-varnish \
		--without-libvarnish \
		--without-libcredis \
		--without-libganglia \
		--without-libesmtp \
		--disable-static

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.endif

.if ${PORT_OPTIONS:MCGI}
RUN_DEPENDS+=	p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-CGI.pm>=0:${PORTSDIR}/www/p5-CGI.pm \
		p5-Data-Dumper>=0:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser
PLIST_SUB+=	CGI=""
.  if empty(PORT_OPTIONS:MRRDTOOL)
IGNORE=		CGI requires RRDTOOL. Either select RRDTOOL or deselect CGI
.  endif
.else
PLIST_SUB+=	CGI="@comment "
.endif

.if ${PORT_OPTIONS:MBIND}
CONFIGURE_ARGS+=--enable-bind
LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl
LIB_DEPENDS+=	libxml2.so:${PORTSDIR}/textproc/libxml2
PLIST_SUB+=	BIND=""
.  if empty(PORT_OPTIONS:MCURL)
IGNORE=	BIND requires CURL. Either select CURL or deselect BIND
.  endif
.else
CONFIGURE_ARGS+=--disable-bind
PLIST_SUB+=	BIND="@comment "
.endif

.if ${PORT_OPTIONS:MAPACHE}
CONFIGURE_ARGS+=--enable-apache
LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl
PLIST_SUB+=	APACHE=""
.  if empty(PORT_OPTIONS:MCURL)
IGNORE=	APACHE requires CURL. Either select CURL or deselect APACHE
.  endif
.else
CONFIGURE_ARGS+=--disable-apache
PLIST_SUB+=	APACHE="@comment "
.endif

.if ${PORT_OPTIONS:MAPCUPS}
CONFIGURE_ARGS+=--enable-apcups
BUILD_DEPENDS+=	${LOCALBASE}/sbin/apcupsd:${PORTSDIR}/sysutils/apcupsd
PLIST_SUB+=	APCUPS=""
.else
CONFIGURE_ARGS+=--disable-apcups
PLIST_SUB+=	APCUPS="@comment "
.endif

.if ${PORT_OPTIONS:MCURL}
CONFIGURE_ARGS+=--enable-curl --with-libcurl=${LOCALBASE}
LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl
PLIST_SUB+=	CURL=""
.else
CONFIGURE_ARGS+=--disable-curl
PLIST_SUB+=	CURL="@comment "
.endif

.if ${PORT_OPTIONS:MCURL_JSON}
.if empty(PORT_OPTIONS:MCURL)
IGNORE=	using CURL_JSON requires CURL support
.endif
CONFIGURE_ARGS+=--enable-curl_json
LIB_DEPENDS+=	libyajl.so:${PORTSDIR}/devel/yajl
PLIST_SUB+=	CURL_JSON=""
.else
CONFIGURE_ARGS+=--disable-curl_json --without-libyajl
PLIST_SUB+=	CURL_JSON="@comment "
.endif

.if ${PORT_OPTIONS:MCURL_XML}
.if empty(PORT_OPTIONS:MCURL)
IGNORE=	using CURL_XML requires CURL support
.endif
CONFIGURE_ARGS+=--enable-curl_xml
LIB_DEPENDS+=	libxml2.so:${PORTSDIR}/textproc/libxml2
PLIST_SUB+=	CURL_XML=""
.else
CONFIGURE_ARGS+=--disable-curl_xml
PLIST_SUB+=	CURL_XML="@comment "
.endif

.if ${PORT_OPTIONS:MDBI}
CONFIGURE_ARGS+=--enable-dbi --with-libdbi=${LOCALBASE}
LIB_DEPENDS+=	libdbi.so:${PORTSDIR}/databases/libdbi
PLIST_SUB+=	DBI=""
.else
CONFIGURE_ARGS+=--disable-dbi
PLIST_SUB+=	DBI="@comment "
.endif

.if ${PORT_OPTIONS:MDISK}
CONFIGURE_ARGS+=--enable-disk
PLIST_SUB+=	DISK=""
.else
CONFIGURE_ARGS+=--disable-disk
PLIST_SUB+=	DISK="@comment "
.endif

.if ${PORT_OPTIONS:MGCRYPT}
CONFIGURE_ARGS+=--with-libgcrypt-prefix=${LOCALBASE}
LIB_DEPENDS+=	libgcrypt.so:${PORTSDIR}/security/libgcrypt
.endif

.if ${PORT_OPTIONS:MNUTUPS}
CONFIGURE_ARGS+=--enable-nut --with-upsclient
LIB_DEPENDS+=	libupsclient.so:${PORTSDIR}/sysutils/nut
PLIST_SUB+=	NUTUPS=""
.else
CONFIGURE_ARGS+=--disable-nut --without-libupsclient
PLIST_SUB+=	NUTUPS="@comment "
.endif

.if ${PORT_OPTIONS:MINTERFACE}
USES+=		pkgconfig
CONFIGURE_ARGS+=--enable-interface
LIB_DEPENDS+=	libstatgrab.so:${PORTSDIR}/devel/libstatgrab
PLIST_SUB+=	INTERFACE=""
LIBS+=		`pkg-config --libs libstatgrab`
.else
CONFIGURE_ARGS+=--disable-interface
PLIST_SUB+=	INTERFACE="@comment "
.endif

.if ${PORT_OPTIONS:MMBMON}
CONFIGURE_ARGS+=--enable-mbmon
RUN_DEPENDS+=	${LOCALBASE}/bin/mbmon:${PORTSDIR}/sysutils/xmbmon
PLIST_SUB+=	MBMON=""
.else
CONFIGURE_ARGS+=--disable-mbmon
PLIST_SUB+=	MBMON="@comment "
.endif

.if ${PORT_OPTIONS:MMEMCACHED}
LIB_DEPENDS+=	libmemcached.so:${PORTSDIR}/databases/libmemcached
CONFIGURE_ARGS+=--enable-memcached
CONFIGURE_ARGS+=--with-libmemcached=${LOCALBASE}
PLIST_SUB+=	MEMCACHED=""
.else
CONFIGURE_ARGS+=--disable-memcached --without-libmemcached
PLIST_SUB+=	MEMCACHED="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=--enable-mysql
PLIST_SUB+=	MYSQL=""
.else
CONFIGURE_ARGS+=--disable-mysql
PLIST_SUB+=	MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MNGINX}
LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=--enable-nginx
PLIST_SUB+=	NGINX=""
.  if empty(PORT_OPTIONS:MCURL)
IGNORE=	NGINX requires CURL. Either select CURL or deselect NGINX
.  endif
.else
CONFIGURE_ARGS+=--disable-nginx
PLIST_SUB+=	NGINX="@comment "
.endif

.if ${PORT_OPTIONS:MNOTIFYDESKTOP}
LIB_DEPENDS+=	libnotify.so:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--enable-notify_desktop
PLIST_SUB+=	NOTIFYDESKTOP=""
.else
CONFIGURE_ARGS+=--disable-notify_desktop
PLIST_SUB+=	NOTIFYDESKTOP="@comment "
.endif

.if ${PORT_OPTIONS:MNOTIFYEMAIL}
LIB_DEPENDS+=	libesmtp.so:${PORTSDIR}/mail/libesmtp
CONFIGURE_ARGS+=--enable-notify_email
CONFIGURE_ARGS+=--with-libesmtp=${PREFIX}
PLIST_SUB+=	NOTIFYEMAIL=""
.else
CONFIGURE_ARGS+=--disable-notify_email
PLIST_SUB+=	NOTIFYEMAIL="@comment "
.endif

.if ${PORT_OPTIONS:MOPENVPN}
CONFIGURE_ARGS+=--enable-openvpn
RUN_DEPENDS+=	${LOCALBASE}/sbin/openvpn:${PORTSDIR}/security/openvpn
PLIST_SUB+=	OPENVPN=""
.else
CONFIGURE_ARGS+=--disable-openvpn
PLIST_SUB+=	OPENVPN="@comment "
.endif

.if ${PORT_OPTIONS:MPDNS}
USE_PDNS=	yes
CONFIGURE_ARGS+=--enable-powerdns
PLIST_SUB+=	PDNS=""
.else
CONFIGURE_ARGS+=--disable-powerdns
PLIST_SUB+=	PDNS="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--enable-postgresql
PLIST_SUB+=	PGSQL=""
.else
CONFIGURE_ARGS+=--disable-postgresql
PLIST_SUB+=	PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPING}
LIB_DEPENDS+=	liboping.so:${PORTSDIR}/net/liboping
CONFIGURE_ARGS+=--enable-ping
PLIST_SUB+=	PING=""
.else
CONFIGURE_ARGS+=--disable-ping
PLIST_SUB+=	PING="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
USES+=		python
CONFIGURE_ARGS+=--enable-python --with-python=${PYTHON_CMD}
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MROUTEROS}
LIB_DEPENDS+=	librouteros.so:${PORTSDIR}/net/librouteros
CONFIGURE_ARGS+=--enable-routeros --with-librouteros=${LOCALBASE}
PLIST_SUB+=	ROUTEROS=""
.else
CONFIGURE_ARGS+=--disable-routeros --without-librouteros
PLIST_SUB+=	ROUTEROS="@comment "
.endif

.if ${PORT_OPTIONS:MRRDTOOL}
LIB_DEPENDS+=	librrd.so:${PORTSDIR}/databases/rrdtool
CONFIGURE_ARGS+=--enable-rrdtool
PLIST_SUB+=	RRD=""
.else
CONFIGURE_ARGS+=--disable-rrdtool
PLIST_SUB+=	RRD="@comment "
.endif

.if ${PORT_OPTIONS:MRRDCACHED} && ${PORT_OPTIONS:MRRDTOOL}
CONFIGURE_ARGS+=--enable-rrdcached
PLIST_SUB+=	RRDCACHED=""
.else
CONFIGURE_ARGS+=--disable-rrdcached
PLIST_SUB+=	RRDCACHED="@comment "
.endif

.if ${PORT_OPTIONS:MSNMP}
LIB_DEPENDS+=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=--enable-snmp
PLIST_SUB+=	SNMP=""
.else
CONFIGURE_ARGS+=--disable-snmp
PLIST_SUB+=	SNMP="@comment "
.endif

.if ${PORT_OPTIONS:MTOKYOTYRANT}
LIB_DEPENDS+=	libtokyotyrant.so:${PORTSDIR}/databases/tokyotyrant
CONFIGURE_ARGS+=--enable-tokyotyrant
CONFIGURE_ARGS+=--with-libtokyotyrant=${LOCALBASE}
PLIST_SUB+=	TOKYOTYRANT=""
.else
CONFIGURE_ARGS+=--disable-tokyotyrant --without-libtokyotyrant
PLIST_SUB+=	TOKYOTYRANT="@comment "
.endif

.if ${PORT_OPTIONS:MLIBVIRT}
CONFIGURE_ARGS+=--enable-libvirt
LIB_DEPENDS+=	libvirt.so:${PORTSDIR}/devel/libvirt
PLIST_SUB+=	VIRT=""
.else
CONFIGURE_ARGS+=--disable-libvirt
PLIST_SUB+=	VIRT="@comment "
.endif

.if ${PORT_OPTIONS:MWRITE_HTTP}
CONFIGURE_ARGS+=--enable-write_http
PLIST_SUB+=	WRITE_HTTP=""
.else
CONFIGURE_ARGS+=--disable-write_http
PLIST_SUB+=	WRITE_HTTP="@comment "
.endif

.if ${PORT_OPTIONS:MXMMS}
LIB_DEPENDS+=	libxmms.so:${PORTSDIR}/multimedia/xmms
CONFIGURE_ARGS+=--enable-xmms
CFLAGS+=	`xmms-config --cflags`
PLIST_SUB+=	XMMS=""
.else
CONFIGURE_ARGS+=--disable-xmms
PLIST_SUB+=	XMMS="@comment "
.endif

post-patch:
	@${RM} -r ${WRKSRC}/libltdl
	@${REINPLACE_CMD} \
		-e 's;@prefix@/var/;/var/;' \
		-e 's;/var/lib/;/var/db/;' \
		${WRKSRC}/src/collectd.conf.in
	@${REINPLACE_CMD} \
		-e '/^ACLOCAL_AMFLAGS =/s;libltdl/m4;m4;' \
		-e '/\$$[(]mkinstalldirs)/d' \
		${WRKSRC}/Makefile.am
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
.if ${PORT_OPTIONS:MCGI}
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/collection.cgi ${STAGEDIR}${WWWDIR}/
	${INSTALL_DATA} ${WRKSRC}/contrib/collection.conf \
		${STAGEDIR}${WWWDIR}/collection.conf.sample
.endif

.include <bsd.port.mk>
