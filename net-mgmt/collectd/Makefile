# New ports collection makefile for:	collectd
# Date created:				Sat Sep 29 05:19:31 PDT 2007
# Whom:					Matt Peterson <matt@peterson.org>
#
# $FreeBSD$
#

PORTNAME=	collectd
PORTVERSION=	4.1.2
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://collectd.org/files/ \
		http://matt.peterson.org/FreeBSD/ports/

MAINTAINER=	matt@peterson.org
COMMENT=	Systems & network statistics collection daemon

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

OPTIONS=	APACHE "Apache mod_status statistics (libcurl)" Off \
		APCUPS "APC UPS support" Off \
		DEBUG "enable debugging" Off \
		INTERFACE "Network interface statistics (libstatgrab)" On \
		MBMON "Query mbmond" Off \
		MYSQL "MySQL statistics" Off \
		PING "Network latency statistics (liboping)" On \
		RRDTOOL "RRDTool output plugin" On \
		SNMP "SNMP support" On \
		XMMS "XMMS statistics" Off

MAN1=		collectd.1 collectd-nagios.1
MAN5=		collectd.conf.5 collectd-email.5 collectd-exec.5 \
		collectd-snmp.5 collectd-unixsock.5 collectd-perl.5

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITH_XMMS) || defined(WITH_INTERFACE)
USE_GNOME=	pkgconfig
. if defined(WITH_XMMS)
USE_GNOME+=	glib
. endif
.endif

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 601103 )
BROKEN=	Need bind9 import post 6.1
.endif

CONFIGURE_ARGS=	--disable-apple_sensors \
		--disable-battery \
		--disable-hddtemp \
		--disable-multimeter \
		--disable-iptables \
		--disable-perl \
		--disable-sensors \
		--disable-serial \
		--disable-vserver \
		--disable-wireless

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.else
PLIST_SUB+=		APACHE="@comment "
.endif

.if defined(WITH_APACHE)
CONFIGURE_ARGS+=	--enable-apache
BUILD_DEPENDS+=		curl.4:${PORTSDIR}/ftp/curl
PLIST_SUB+=		APACHE=""
.else
CONFIGURE_ARGS+=	--disable-apache
PLIST_SUB+=		APACHE="@comment "
.endif

.if defined(WITH_APCUPS)
CONFIGURE_ARGS+=	--enable-apcups
BUILD_DEPENDS+=		${LOCALBASE}/sbin/apcupsd:${PORTSDIR}/sysutils/apcupsd
PLIST_SUB+=		APCUPS=""
.else
CONFIGURE_ARGS+=	--disable-apcups
PLIST_SUB+=		APCUPS="@comment "
.endif

.if defined(WITH_INTERFACE)
CONFIGURE_ARGS+=	--enable-interface
LIB_DEPENDS+=		statgrab.8:${PORTSDIR}/devel/libstatgrab
PLIST_SUB+=		INTERFACE=""
CONFIGURE_ENV+=	LIBS="`pkg-config --libs libstatgrab`"
.else
CONFIGURE_ARGS+=	--disable-interface
PLIST_SUB+=		INTERFACE="@comment "
.endif

.if defined(WITH_MBMON)
CONFIGURE_ARGS+=	--enable-mbmon
RUN_DEPENDS+=		${LOCALBASE}/sbin/mbmond:${PORTSDIR}/sysutils/mbmon
PLIST_SUB+=		MBMON=""
.else
CONFIGURE_ARGS+=	--disable-mbmon
PLIST_SUB+=		MBMON="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=		yes
CONFIGURE_ARGS+=	--enable-mysql
PLIST_SUB+=		MYSQL=""
.else
CONFIGURE_ARGS+=	--disable-mysql
PLIST_SUB+=		MYSQL="@comment "
.endif

.if defined(WITH_PING)
LIB_DEPENDS+=		oping:${PORTSDIR}/net/liboping
CONFIGURE_ARGS+=	--enable-ping
PLIST_SUB+=		PING=""
.else
CONFIGURE_ARGS+=	--disable-ping
PLIST_SUB+=		PING="@comment "
.endif

.if defined(WITH_RRDTOOL)
LIB_DEPENDS+=		rrd:${PORTSDIR}/databases/rrdtool
CONFIGURE_ARGS+=	--enable-rrdtool
PLIST_SUB+=		RRD=""
.else
CONFIGURE_ARGS+=	--disable-rrdtool
PLIST_SUB+=		RRD="@comment "
.endif

.if defined(WITH_SNMP)
LIB_DEPENDS+=		netsnmp.16:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=	--enable-snmp
PLIST_SUB+=		SNMP=""
.else
CONFIGURE_ARGS+=	--disable-snmp
PLIST_SUB+=		SNMP="@comment "
.endif

.if defined(WITH_XMMS)
LIB_DEPENDS+=		xmms.4:${PORTSDIR}/multimedia/xmms
CONFIGURE_ARGS+=	--enable-xmms
CFLAGS=			`pkg-config glib --cflags`
PLIST_SUB+=		XMMS=""
.else
CONFIGURE_ARGS+=	--disable-xmms
PLIST_SUB+=		XMMS="@comment "
.endif

.include <bsd.port.post.mk>
