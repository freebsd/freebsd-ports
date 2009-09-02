# New ports collection makefile for:   snmp4nagios
# Date created:        22 June 2008
# Whom:                Ryan Steinmetz
#
# $FreeBSD$
#

PORTNAME=	SNMP4Nagios
PORTVERSION=	0.4
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	rpsfa@rit.edu
COMMENT=	Vendor specific SNMP plugins for Nagios

BUILD_DEPENDS=	snmpcheck:${PORTSDIR}/net-mgmt/net-snmp
RUN_DEPENDS=	snmpcheck:${PORTSDIR}/net-mgmt/net-snmp

GNU_CONFIGURE=	yes

NAGIOSWWWDIR?=	www/nagios
NAGIOSDIR?=	/var/spool/nagios

OPTIONS=	RRDTOOL "Build with rrdtool support" OFF

CONFIGURE_ARGS=	--sbindir=${PREFIX}/${NAGIOSWWWDIR}/cgi-bin \
		--bindir=${PREFIX}/libexec/nagios \
		--libexecdir=${PREFIX}/libexec/nagios \
		--datadir=${PREFIX}/share \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=${NAGIOSDIR} \
		--with-rrddir=${NAGIOSDIR}/snmp4nagios/rrd \
		--with-pngdir=${NAGIOSDIR}/snmp4nagios/png \
		--prefix=${PREFIX}

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(WITH_RRDTOOL)
LIB_DEPENDS+=	rrd:${PORTSDIR}/databases/rrdtool
CONFIGURE_ARGS+=--with-rrd
PLIST_SUB+=	RRD=""
.else
CONFIGURE_ARGS+=--with-rrd=no
PLIST_SUB+=	RRD="@comment "
.endif

.include <bsd.port.post.mk>
