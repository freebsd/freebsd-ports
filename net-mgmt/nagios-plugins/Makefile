# New ports collection makefile for:	nagios-plugins
# Date created:				14 Jul 2002
# Whom:					Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nagios-plugins
PORTVERSION=	1.3.1
PORTREVISION=	6
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	nagiosplug

MAINTAINER=	blaz@si.FreeBSD.org
COMMENT=	Plugins for nagios

OPTIONS=	QSTAT "Game server query support" off \
		FPING "Support for non-flooding fast ping" off \
		NETSNMP "SNMP support" off \
		RADIUS "Radius support" off \
		MYSQL "MySQL support" off \
		PGSQL "PostgreSQL support" off \
		LDAP "OpenLDAP support" off

.include <bsd.port.pre.mk>

USE_SUBMAKE=	yes
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
LIB_DEPENDS+=	radiusclient.0:${PORTSDIR}/net/radiusclient
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
POSTGRESQL_PORT?=databases/postgresql7
LIB_DEPENDS+=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
CONFIGURE_ARGS+=--with-pgsql=${LOCALBASE}
PLIST_SUB+=	SUB_PGSQL=""
.else
PLIST_SUB+=	SUB_PGSQL="@comment "
.endif

.if defined(WITH_LDAP)
USE_OPENLDAP=	YES
CONFIGURE_ARGS+=--enable-ldap
PLIST_SUB+=	SUB_LDAP=""
.else
PLIST_SUB+=	SUB_LDAP="@comment "
.endif

CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
USE_AUTOMAKE_VER=	14
USE_AUTOCONF_VER=	213
USE_GMAKE=	yes
USE_PERL5=	yes

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOMAKE_ENV} ${ACLOCAL} \
		--acdir=${ACLOCAL_DIR})

.include <bsd.port.post.mk>
