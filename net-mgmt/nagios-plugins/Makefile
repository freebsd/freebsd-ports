# Created by: Blaz Zupan <blaz@si.FreeBSD.org>
# $FreeBSD$

PORTNAME=	nagios-plugins
PORTVERSION=	2.0
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	https://www.nagios-plugins.org/download/

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Plugins for Nagios

USES=		charsetfix gmake perl5
CHARSETFIX_MAKEFILEIN=Makefile.am
USE_SUBMAKE=	yes
USE_AUTOTOOLS=	libtool aclocal autoconf automake
ACLOCAL_ARGS=	-I m4 -I gl/m4
AUTOMAKE_ARGS=	--add-missing

OPTIONS_DEFINE=	QSTAT FPING NETSNMP RADIUS MYSQL PGSQL LDAP IPV6 JAIL NLS DBI EXTRAOPTS
OPTIONS_DEFAULT=IPV6 EXTRAOPTS
OPTIONS_SUB=	yes

QSTAT_DESC=	Game server query support (check_game)
FPING_DESC=	Support for non-flooding fast ping (check_fping)
NETSNMP_DESC=	SNMP support (check_snmp)
RADIUS_DESC=	Radius support (check_radius)
MYSQL_DESC=	MySQL support (check_mysql)
PGSQL_DESC=	PostgreSQL support (check_pgsql)
LDAP_DESC=	OpenLDAP support (check_ldap)
JAIL_DESC=	Compilation within jail(8) (see help)
DBI_DESC=	Check database using DBI
EXTRAOPTS_DESC=	Parsing of plugins ini config files for extra options

EXTRAOPTS_CONFIGURE_ENABLE=	extra-opts

GNU_CONFIGURE=	yes

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

NAGIOSWWWDIR?=	www/nagios
NAGIOSHTMURL?=	/nagios
NAGIOSCGIURL?=	${NAGIOSHTMURL}/cgi-bin

NAGIOSPOLLIP?=	127.0.0.1
NAGIOSPOLLIP6?=	::1

PLUGINS_DIR=	${PREFIX}/libexec/nagios

CONFIGURE_ARGS+=--with-nagios-user=${NAGIOSUSER} \
		--with-nagios-group=${NAGIOSGROUP} \
		--with-cgiurl=${NAGIOSCGIURL} \
		--sbindir=${PREFIX}/${NAGIOSWWWDIR}/cgi-bin \
		--libexecdir=${PLUGINS_DIR} \
		--datadir=${PREFIX}/share \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=${NAGIOSDIR} \
		--prefix=${PREFIX}

CONFIGURE_ENV=	PERL=${PERL}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

QSTAT_BUILD_DEPENDS=	qstat:${PORTSDIR}/games/qstat
QSTAT_RUN_DEPENDS=	qstat:${PORTSDIR}/games/qstat
QSTAT_CONFIGURE_ENABLE=	qstat

IPV6_CONFIGURE_WITH=	ipv6

FPING_BUILD_DEPENDS=	fping:${PORTSDIR}/net/fping
FPING_RUN_DEPENDS=	fping:${PORTSDIR}/net/fping
FPING_CONFIGURE_ENABLE=	fping

NETSNMP_BUILD_DEPENDS=	snmpcheck:${PORTSDIR}/net-mgmt/net-snmp \
		p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP
NETSNMP_RUN_DEPENDS=	snmpcheck:${PORTSDIR}/net-mgmt/net-snmp \
		p5-Net-SNMP>=0:${PORTSDIR}/net-mgmt/p5-Net-SNMP
NETSNMP_CONFIGURE_ENABLE=	snmp

RADIUS_LIB_DEPENDS=	libradiusclient-ng.so:${PORTSDIR}/net/radiusclient
RADIUS_CONFIGURE_WITH=	radius

MYSQL_USE=	mysql=yes
MYSQL_CONFIGURE_ON=	--with-mysql=${LOCALBASE}
MYSQL_CONFIGURE_OFF=	--without-mysql

PGSQL_USE=	pgsql=yes
PGSQL_CONFIGURE_ON=	--with-pgsql=${LOCALBASE}
PGSQL_CONFIGURE_OFF=	--without-pgsql

LDAP_USE=	openldap=yes
LDAP_CONFIGURE_WITH=	ldap

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

DBI_LIB_DEPENDS=	libdbi.so:${PORTSDIR}/databases/libdbi
DBI_CONFIGURE_WITH=	dbi

.include <bsd.port.options.mk>

.if ${OSVERSION} > 1000055
BUILD_DEPENDS+=		${LOCALBASE}/bin/dig:${PORTSDIR}/dns/bind-tools
CONFIGURE_ARGS+=	--with-dig-command=${PLUGINS_DIR}/nagios-dig \
			--with-nslookup-command=${PLUGINS_DIR}/nagios-nslookup
PLIST_SUB+=	BIND=""
.else
PLIST_SUB+=	BIND="@comment "
.endif

.if !exists(/usr/bin/ssh)
PLIST_SUB+=	SSH="@comment "
.else
PLIST_SUB+=	SSH=""
.endif

post-patch:
.for file in check_by_ssh.c check_disk.c check_http.c check_mrtgtraf.c \
	check_nagios.c check_ntp.c check_ntp_peer.c check_ntp_time.c \
	check_pgsql.c check_snmp.c check_ssh.c check_swap.c check_time.c \
	check_users.c
	@${REINPLACE_CMD} -e 's|setlocale (LC_ALL, "");|setlocale (LC_ALL, ""); setlocale(LC_NUMERIC, "C");|g' ${WRKSRC}/plugins/${file}
.endfor
	@${REINPLACE_CMD} -e 's|chown root|${TRUE}|g' ${WRKSRC}/plugins-root/Makefile.am
.if ${PORT_OPTIONS:MJAIL}
	@${REINPLACE_CMD} -e 's# 127.0.0.1 # ${NAGIOSPOLLIP} #g' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's# ::1 # ${NAGIOSPOLLIP6} #g' ${WRKSRC}/configure.ac
.endif

.if ${OSVERSION} > 1000055
post-install:
.for f in dig nslookup
	${INSTALL_PROGRAM} ${LOCALBASE}/bin/${f} ${STAGEDIR}${PLUGINS_DIR}/nagios-${f}
.endfor
.endif

.include <bsd.port.mk>
