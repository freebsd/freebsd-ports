# New ports collection makefile for:	netsaint-plugins
# Date created:				Wed 12 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	netsaint-plugins
PORTVERSION=	1.2.9.2
CATEGORIES=	net
MASTER_SITES=	http://download.sourceforge.net/netsaintplug/
DISTNAME=	${PORTNAME}-1.2.9-2

MAINTAINER=	blaz@amis.net

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sbindir=${PREFIX}/share/netsaint/sbin \
		--libexecdir=${PREFIX}/libexec/netsaint \
		--datadir=${PREFIX}/share/netsaint \
		--sysconfdir=${PREFIX}/etc/netsaint \
		--localstatedir=${PREFIX}/var/netsaint
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
USE_AUTOMAKE=	yes
USE_GMAKE=	yes

# make absolutely sure we have the user/group added!
BUILD_DEPENDS=	netsaint:${PORTSDIR}/net/netsaint
RUN_DEPENDS=	netsaint:${PORTSDIR}/net/netsaint

.if defined(WANT_QSTAT)
BUILD_DEPENDS+=	qstat:${PORTSDIR}/games/qstat
RUN_DEPENDS+=	qstat:${PORTSDIR}/games/qstat
PLIST_SUB+=	WANT_QSTAT=""
.else
PLIST_SUB+=	WANT_QSTAT="@comment "
.endif

.if defined(WANT_FPING)
BUILD_DEPENDS+=	fping:${PORTSDIR}/net/fping
RUN_DEPENDS+=	fping:${PORTSDIR}/net/fping
PLIST_SUB+=	WANT_FPING=""
.else
PLIST_SUB+=	WANT_FPING="@comment "
.endif

.if defined(WANT_SNMP)
BUILD_DEPENDS+=	snmpcheck:${PORTSDIR}/net/net-snmp
RUN_DEPENDS+=	snmpcheck:${PORTSDIR}/net/net-snmp
PLIST_SUB+=	WANT_SNMP=""
CONFIGURE_ARGS+=--enable-snmp
.else
PLIST_SUB+=	WANT_SNMP="@comment "
.endif

.if defined(WANT_RADIUS)
LIB_DEPENDS+=	radiusclient.0:${PORTSDIR}/net/radiusclient
PLIST_SUB+=	WANT_RADIUS=""
CONFIGURE_ARGS+=--enable-radius
.else
PLIST_SUB+=	WANT_RADIUS="@comment "
.endif

.if defined(WANT_MYSQL)
LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
PLIST_SUB+=	WANT_MYSQL=""
CONFIGURE_ARGS+=--with-mysqllibdir=${LOCALBASE}/lib/mysql
.else
PLIST_SUB+=	WANT_MYSQL="@comment "
.endif

.include <bsd.port.mk>
