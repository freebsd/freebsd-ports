# New ports collection makefile for:	nagios-plugins
# Date created:				14 Jul 2002
# Whom:					Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nagios-plugins
PORTVERSION=	1.4.2
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	nagiosplug

MAINTAINER=	jarrod@netleader.com.au
COMMENT=	Plugins for nagios

OPTIONS=	QSTAT "Game server query support" off \
		FPING "Support for non-flooding fast ping" off \
		NETSNMP "SNMP support" off \
		RADIUS "Radius support" off \
		MYSQL "MySQL support" off \
		PGSQL "PostgreSQL support" off \
 		LDAP "OpenLDAP support" off \
 		IPV6 "IPV6 support" on

.include <bsd.port.pre.mk>

USE_SUBMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sbindir=${PREFIX}/share/nagios/cgi-bin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--datadir=${PREFIX}/share/nagios \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=/var/spool/nagios \
		--with-df-command="/bin/df -Pkt noprocfs"

.if defined(WITH_QSTAT)
BUILD_DEPENDS+=	qstat:${PORTSDIR}/games/qstat
RUN_DEPENDS+=	qstat:${PORTSDIR}/games/qstat
CONFIGURE_ARGS+=--enable-qstat
PLIST_SUB+=	SUB_QSTAT=""
.else
PLIST_SUB+=	SUB_QSTAT="@comment "
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=--with-ipv6
.else
CONFIGURE_ARGS+=--without-ipv6
.endif

.if defined(WITH_FPING)
BUILD_DEPENDS+=	fping:${PORTSDIR}/net/fping
RUN_DEPENDS+=	fping:${PORTSDIR}/net/fping
CONFIGURE_ARGS+=--enable-fping
PLIST_SUB+=	SUB_FPING=""
.else
PLIST_SUB+=	SUB_FPING="@comment "
.endif

.if defined(WITH_NETSNMP)
BUILD_DEPENDS+=	snmpcheck:${PORTSDIR}/net-mgmt/net-snmp \
		${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}/net-mgmt/p5-Net-SNMP
RUN_DEPENDS+=	snmpcheck:${PORTSDIR}/net-mgmt/net-snmp \
		${SITE_PERL}/Net/SNMP.pm:${PORTSDIR}/net-mgmt/p5-Net-SNMP
CONFIGURE_ARGS+=--enable-snmp
PLIST_SUB+=	SUB_SNMP=""
.else
PLIST_SUB+=	SUB_SNMP="@comment "
.endif

.if defined(WITH_RADIUS)
LIB_DEPENDS+=	radiusclient-ng.2:${PORTSDIR}/net/radiusclient
CONFIGURE_ARGS+=--enable-radius
PLIST_SUB+=	SUB_RADIUS=""
.else
PLIST_SUB+=	SUB_RADIUS="@comment "
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	YES
CONFIGURE_ARGS+=--with-mysql=${LOCALBASE}
PLIST_SUB+=	SUB_MYSQL=""
.else
PLIST_SUB+=	SUB_MYSQL="@comment "
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	YES
CONFIGURE_ARGS+=--with-pgsql=${LOCALBASE}
PLIST_SUB+=	SUB_PGSQL=""
.else
CONFIGURE_ARGS+=--with-pgsql=${NONEXISTENT}
PLIST_SUB+=	SUB_PGSQL="@comment "
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	YES
CONFIGURE_ARGS+=--enable-ldap
PLIST_SUB+=	SUB_LDAP=""
.else
PLIST_SUB+=	SUB_LDAP="@comment "
.endif

CONFIGURE_ENV=	LOCALBASE=${LOCALBASE} LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"
USE_AUTOTOOLS=	automake:19 autoconf:259
USE_GMAKE=	yes
USE_PERL5=	yes

post-patch:
.for file in check_by_ssh.c check_disk.c check_http.c check_load.c \
	check_mrtgtraf.c check_nagios.c check_pgsql.c check_ping.c \
	check_procs.c check_snmp.c check_ssh.c check_swap.c check_time.c \
	check_users.c utils.c
	@${REINPLACE_CMD} -e 's|setlocale (LC_ALL, "");|setlocale (LC_ALL, ""); setlocale(LC_NUMERIC, "C");|g' ${WRKSRC}/plugins/${file}
.endfor

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOMAKE_ENV} ${ACLOCAL} \
		--acdir=${ACLOCAL_DIR} -I m4)

.include <bsd.port.post.mk>
