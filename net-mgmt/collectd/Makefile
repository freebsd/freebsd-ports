# New ports collection makefile for:	collectd
# Date created:				Sat Sep 29 05:19:31 PDT 2007
# Whom:					Matt Peterson <matt@peterson.org>
#
# $FreeBSD$
#

PORTNAME=	collectd
PORTVERSION=	4.1.2
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://collectd.org/files/ \
		http://mirror.roe.ch/dist/${PORTNAME}/

MAINTAINER=	daniel@roe.ch
COMMENT=	Systems & network statistics collection daemon

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes

OPTIONS=	CGI	"Install collection.cgi (requires RRDTOOL)" Off \
		DEBUG	"Enable debugging" Off \
		APACHE	"Input: Apache mod_status (libcurl)" Off \
		APCUPS	"Input: APC UPS (apcupsd)" Off \
		INTERFACE "Input: Network interfaces (libstatgrab)" On \
		MBMON	"Input: MBMon" Off \
		MYSQL	"Input: MySQL" Off \
		PING	"Input: Network latency (liboping)" On \
		SNMP	"Input: SNMP" On \
		XMMS	"Input: XMMS" Off \
		RRDTOOL	"Output: RRDTool" On

MAN1=		collectd.1 collectd-nagios.1
MAN5=		collectd.conf.5 collectd-email.5 collectd-exec.5 \
		collectd-snmp.5 collectd-unixsock.5 collectd-perl.5
USE_RC_SUBR=	collectd

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 601103 )
BROKEN=		Need bind9 import post 6.1
.endif

CONFIGURE_ARGS=	--localstatedir=/var \
		--disable-apple_sensors \
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
CONFIGURE_ARGS+=--enable-debug
.endif

.if defined(WITH_CGI)
RUN_DEPENDS+=	${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm \
		${SITE_PERL}/${PERL_ARCH}/Data/Dumper.pm:${PORTSDIR}/devel/p5-Data-Dumper
PLIST_SUB+=	CGI=""
.else
PLIST_SUB+=	CGI="@comment "
.endif

.if defined(WITH_APACHE)
CONFIGURE_ARGS+=--enable-apache
LIB_DEPENDS+=	curl.4:${PORTSDIR}/ftp/curl
PLIST_SUB+=	APACHE=""
.else
CONFIGURE_ARGS+=--disable-apache
PLIST_SUB+=	APACHE="@comment "
.endif

.if defined(WITH_APCUPS)
CONFIGURE_ARGS+=--enable-apcups
BUILD_DEPENDS+=	${LOCALBASE}/sbin/apcupsd:${PORTSDIR}/sysutils/apcupsd
PLIST_SUB+=	APCUPS=""
.else
CONFIGURE_ARGS+=--disable-apcups
PLIST_SUB+=	APCUPS="@comment "
.endif

.if defined(WITH_INTERFACE)
BUILD_DEPENDS+=	pkg-config:${PORTSDIR}/devel/pkg-config
CONFIGURE_ARGS+=--enable-interface
LIB_DEPENDS+=	statgrab.8:${PORTSDIR}/devel/libstatgrab
PLIST_SUB+=	INTERFACE=""
CONFIGURE_ENV+=	LIBS="`pkg-config --libs libstatgrab`"
.else
CONFIGURE_ARGS+=--disable-interface
PLIST_SUB+=	INTERFACE="@comment "
.endif

.if defined(WITH_MBMON)
CONFIGURE_ARGS+=--enable-mbmon
RUN_DEPENDS+=	${LOCALBASE}/sbin/mbmond:${PORTSDIR}/sysutils/mbmon
PLIST_SUB+=	MBMON=""
.else
CONFIGURE_ARGS+=--disable-mbmon
PLIST_SUB+=	MBMON="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--enable-mysql
PLIST_SUB+=	MYSQL=""
.else
CONFIGURE_ARGS+=--disable-mysql
PLIST_SUB+=	MYSQL="@comment "
.endif

.if defined(WITH_PING)
LIB_DEPENDS+=	oping:${PORTSDIR}/net/liboping
CONFIGURE_ARGS+=--enable-ping
PLIST_SUB+=	PING=""
.else
CONFIGURE_ARGS+=--disable-ping
PLIST_SUB+=	PING="@comment "
.endif

.if defined(WITH_RRDTOOL)
LIB_DEPENDS+=	rrd:${PORTSDIR}/databases/rrdtool
CONFIGURE_ARGS+=--enable-rrdtool
PLIST_SUB+=	RRD=""
.else
CONFIGURE_ARGS+=--disable-rrdtool
PLIST_SUB+=	RRD="@comment "
.endif

.if defined(WITH_SNMP)
LIB_DEPENDS+=	netsnmp.16:${PORTSDIR}/net-mgmt/net-snmp
CONFIGURE_ARGS+=--enable-snmp
PLIST_SUB+=	SNMP=""
.else
CONFIGURE_ARGS+=--disable-snmp
PLIST_SUB+=	SNMP="@comment "
.endif

.if defined(WITH_XMMS)
USE_GNOME+=	_glib20
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
CONFIGURE_ARGS+=--enable-xmms
CFLAGS+=	`pkg-config glib --cflags`
PLIST_SUB+=	XMMS=""
.else
CONFIGURE_ARGS+=--disable-xmms
PLIST_SUB+=	XMMS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's;@prefix@/var/;/var/;' \
		-e 's;/var/lib/;/var/db/;' \
		${WRKSRC}/src/collectd.conf.in
	@${REINPLACE_CMD} \
		-e 's;$$[(]DESTDIR)$$[(]sysconfdir)/collectd\.conf;&.sample;' \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/$$[(]mkinstalldirs)/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} \
		-e 's;/etc/collection\.conf;${WWWDIR}/collection.conf;' \
		${WRKSRC}/contrib/collection.cgi
	@${REINPLACE_CMD} \
		-e 's;/opt/collectd/var/lib;/var/db;' \
		-e 's;/opt/collectd/lib;${PREFIX}/lib;' \
		${WRKSRC}/contrib/collection.conf

post-install:
	${MKDIR} /var/db/collectd
	if [ ! -f ${PREFIX}/etc/collectd.conf ]; then \
		${CP} -p ${PREFIX}/etc/collectd.conf.sample \
			${PREFIX}/etc/collectd.conf ; \
	fi
.if defined(WITH_CGI)
	${MKDIR} ${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/collection.cgi ${WWWDIR}/
	${INSTALL_DATA} ${WRKSRC}/contrib/collection.conf \
		${WWWDIR}/collection.conf.sample
	if [ ! -f ${WWWDIR}/collection.conf ]; then \
		${CP} -p ${WWWDIR}/collection.conf.sample \
			${WWWDIR}/collection.conf ; \
	fi
.endif

.include <bsd.port.post.mk>
