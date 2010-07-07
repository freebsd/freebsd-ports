# New ports collection makefile for:	nagios-plugins
# Date created:				14 Jul 2002
# Whom:					Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nagios-plugins
PORTVERSION=	1.4.14
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/nagiosplug/nagiosplug/${PORTVERSION}

MAINTAINER=	jarrod@netleader.com.au
COMMENT=	Plugins for Nagios

USE_SUBMAKE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_AUTOTOOLS=	libtool:22 aclocal:19 autoconf:262 automake:19
ACLOCAL_ARGS=	-I m4 -I gl/m4

OPTIONS=	QSTAT "Game server query support (check_game)" OFF \
		FPING "Support for non-flooding fast ping (check_fping)" OFF \
		NETSNMP "SNMP support (check_snmp)" OFF \
		RADIUS "Radius support (check_radius)" OFF \
		MYSQL "MySQL support (check_mysql)" OFF \
		PGSQL "PostgreSQL support (check_pgsql)" OFF \
		LDAP "OpenLDAP support (check_ldap)" OFF \
		IPV6 "IPv6 support" ON \
		JAIL "Compilation within jail(8) (see Makefile)" OFF

GNU_CONFIGURE=	yes

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

NAGIOSWWWDIR?=	www/nagios
NAGIOSHTMURL?=	/nagios
NAGIOSCGIURL?=	${NAGIOSHTMURL}/cgi-bin

NAGIOSPOLLIP?=	127.0.0.1
NAGIOSPOLLIP6?=	::1

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--with-nagios-user=${NAGIOSUSER} \
		--with-nagios-group=${NAGIOSGROUP} \
		--with-cgiurl=${NAGIOSCGIURL} \
		--sbindir=${PREFIX}/${NAGIOSWWWDIR}/cgi-bin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--datadir=${PREFIX}/share \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=${NAGIOSDIR} \
		--prefix=${PREFIX}

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		PERL=${PERL}

.if defined(WITH_QSTAT)
BUILD_DEPENDS+=	qstat:${PORTSDIR}/games/qstat
RUN_DEPENDS+=	qstat:${PORTSDIR}/games/qstat
CONFIGURE_ARGS+=	--enable-qstat
PLIST_SUB+=	SUB_QSTAT=""
.else
PLIST_SUB+=	SUB_QSTAT="@comment "
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--without-ipv6
.endif

.if defined(WITH_FPING)
BUILD_DEPENDS+=	fping:${PORTSDIR}/net/fping
RUN_DEPENDS+=	fping:${PORTSDIR}/net/fping
CONFIGURE_ARGS+=	--enable-fping
PLIST_SUB+=	SUB_FPING=""
.else
PLIST_SUB+=	SUB_FPING="@comment "
.endif

.if defined(WITH_NETSNMP)
BUILD_DEPENDS+=	snmpcheck:${PORTSDIR}/net-mgmt/net-snmp \
		${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}/net-mgmt/p5-Net-SNMP
RUN_DEPENDS+=	snmpcheck:${PORTSDIR}/net-mgmt/net-snmp \
		${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}/net-mgmt/p5-Net-SNMP
CONFIGURE_ARGS+=	--enable-snmp
PLIST_SUB+=	SUB_SNMP=""
.else
PLIST_SUB+=	SUB_SNMP="@comment "
.endif

.if defined(WITH_RADIUS)
LIB_DEPENDS+=	radiusclient-ng.2:${PORTSDIR}/net/radiusclient
CONFIGURE_ARGS+=	--enable-radius
PLIST_SUB+=	SUB_RADIUS=""
.else
PLIST_SUB+=	SUB_RADIUS="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	YES
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE}
PLIST_SUB+=	SUB_MYSQL=""
.else
CONFIGURE_ARGS+=	--without-mysql
PLIST_SUB+=	SUB_MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	YES
CONFIGURE_ARGS+=	--with-pgsql=${LOCALBASE}
PLIST_SUB+=	SUB_PGSQL=""
.else
CONFIGURE_ARGS+=	--with-pgsql=${NONEXISTENT}
PLIST_SUB+=	SUB_PGSQL="@comment "
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	YES
CONFIGURE_ARGS+=	--enable-ldap
PLIST_SUB+=	SUB_LDAP=""
.else
PLIST_SUB+=	SUB_LDAP="@comment "
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

post-patch:
.for file in check_by_ssh.c check_disk.c check_http.c check_mrtgtraf.c \
	check_nagios.c check_pgsql.c check_snmp.c check_ssh.c check_swap.c \
	check_time.c check_users.c utils.c
	@${REINPLACE_CMD} -e 's|setlocale (LC_ALL, "");|setlocale (LC_ALL, ""); setlocale(LC_NUMERIC, "C");|g' ${WRKSRC}/plugins/${file}
.endfor
.if defined(WITH_JAIL)
	@${REINPLACE_CMD} -e 's# 127.0.0.1 # ${NAGIOSPOLLIP} #g' ${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's# ::1 # ${NAGIOSPOLLIP6} #g' ${WRKSRC}/configure.in
.endif

.include <bsd.port.post.mk>
