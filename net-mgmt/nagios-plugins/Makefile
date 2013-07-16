# Created by: Blaz Zupan <blaz@si.FreeBSD.org>
# $FreeBSD$

PORTNAME=	nagios-plugins
PORTVERSION=	1.4.16
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/nagiosplug/nagiosplug/${PORTVERSION}

MAINTAINER=	jarrod@downtools.com.au
COMMENT=	Plugins for Nagios

USES=		charsetfix
CHARSETFIX_MAKEFILEIN=Makefile.am
USE_SUBMAKE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_AUTOTOOLS=	libtool aclocal autoconf automake
ACLOCAL_ARGS=	-I m4 -I gl/m4
AUTOMAKE_ARGS=	--add-missing

OPTIONS_DEFINE=	QSTAT FPING NETSNMP RADIUS MYSQL PGSQL LDAP IPV6 JAIL NLS
OPTIONS_DEFAULT=IPV6

QSTAT_DESC=	Game server query support (check_game)
FPING_DESC=	Support for non-flooding fast ping (check_fping)
NETSNMP_DESC=	SNMP support (check_snmp)
RADIUS_DESC=	Radius support (check_radius)
MYSQL_DESC=	MySQL support (check_mysql)
PGSQL_DESC=	PostgreSQL support (check_pgsql)
LDAP_DESC=	OpenLDAP support (check_ldap)
JAIL_DESC=	Compilation within jail(8) (see Makefile)

GNU_CONFIGURE=	yes

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

NAGIOSWWWDIR?=	www/nagios
NAGIOSHTMURL?=	/nagios
NAGIOSCGIURL?=	${NAGIOSHTMURL}/cgi-bin

NAGIOSPOLLIP?=	127.0.0.1
NAGIOSPOLLIP6?=	::1

.include <bsd.port.options.mk>

CONFIGURE_ARGS=	--with-nagios-user=${NAGIOSUSER} \
		--with-nagios-group=${NAGIOSGROUP} \
		--with-cgiurl=${NAGIOSCGIURL} \
		--sbindir=${PREFIX}/${NAGIOSWWWDIR}/cgi-bin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--datadir=${PREFIX}/share \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=${NAGIOSDIR} \
		--prefix=${PREFIX}

CONFIGURE_ENV=	PERL=${PERL}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

.if ${PORT_OPTIONS:MQSTAT}
BUILD_DEPENDS+=	qstat:${PORTSDIR}/games/qstat
RUN_DEPENDS+=	qstat:${PORTSDIR}/games/qstat
CONFIGURE_ARGS+=	--enable-qstat
PLIST_SUB+=	SUB_QSTAT=""
.else
PLIST_SUB+=	SUB_QSTAT="@comment "
.endif

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif

.if ${PORT_OPTIONS:MFPING}
BUILD_DEPENDS+=	fping:${PORTSDIR}/net/fping
RUN_DEPENDS+=	fping:${PORTSDIR}/net/fping
CONFIGURE_ARGS+=	--enable-fping
PLIST_SUB+=	SUB_FPING=""
.else
PLIST_SUB+=	SUB_FPING="@comment "
.endif

.if ${PORT_OPTIONS:MNETSNMP}
BUILD_DEPENDS+=	snmpcheck:${PORTSDIR}/net-mgmt/net-snmp \
		p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP
RUN_DEPENDS+=	snmpcheck:${PORTSDIR}/net-mgmt/net-snmp \
		p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP
CONFIGURE_ARGS+=	--enable-snmp
PLIST_SUB+=	SUB_SNMP=""
.else
PLIST_SUB+=	SUB_SNMP="@comment "
.endif

.if ${PORT_OPTIONS:MRADIUS}
LIB_DEPENDS+=	radiusclient-ng:${PORTSDIR}/net/radiusclient
CONFIGURE_ARGS+=	--enable-radius
PLIST_SUB+=	SUB_RADIUS=""
.else
PLIST_SUB+=	SUB_RADIUS="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	YES
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
PLIST_SUB+=	SUB_MYSQL=""
.else
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB+=	SUB_MYSQL="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	YES
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}
PLIST_SUB+=	SUB_PGSQL=""
.else
CONFIGURE_ARGS+=	--with-pgsql=${NONEXISTENT}
PLIST_SUB+=	SUB_PGSQL="@comment "
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=	YES
CONFIGURE_ARGS+=	--enable-ldap
PLIST_SUB+=	SUB_LDAP=""
.else
PLIST_SUB+=	SUB_LDAP="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

# Restore check_users from 1.4.15 for hosts without getutxent(3)
.if ${OSVERSION} < 900007
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-plugins__check_users.c
.endif

post-patch:
.for file in check_by_ssh.c check_disk.c check_http.c check_mrtgtraf.c \
	check_nagios.c check_ntp.c check_ntp_peer.c check_ntp_time.c \
	check_pgsql.c check_snmp.c check_ssh.c check_swap.c check_time.c \
	check_users.c
	@${REINPLACE_CMD} -e 's|setlocale (LC_ALL, "");|setlocale (LC_ALL, ""); setlocale(LC_NUMERIC, "C");|g' ${WRKSRC}/plugins/${file}
.endfor
.if ${PORT_OPTIONS:MJAIL}
	@${REINPLACE_CMD} -e 's# 127.0.0.1 # ${NAGIOSPOLLIP} #g' ${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's# ::1 # ${NAGIOSPOLLIP6} #g' ${WRKSRC}/configure.in
.endif

.include <bsd.port.mk>
