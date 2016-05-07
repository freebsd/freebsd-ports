# Created by: Ryan Steinmetz
# $FreeBSD$

PORTNAME=	SNMP4Nagios
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Vendor specific SNMP plugins for Nagios

BUILD_DEPENDS=	snmpcheck:net-mgmt/net-snmp
RUN_DEPENDS=	snmpcheck:net-mgmt/net-snmp

GNU_CONFIGURE=	yes

NAGIOSWWWDIR?=	www/nagios
NAGIOSDIR?=	/var/spool/nagios

OPTIONS_DEFINE=	RRDTOOL
RRDTOOL_DESC=	Build with rrdtool support

.include <bsd.port.options.mk>

CONFIGURE_ARGS=	--sbindir=${PREFIX}/${NAGIOSWWWDIR}/cgi-bin \
		--bindir=${PREFIX}/libexec/nagios \
		--libexecdir=${PREFIX}/libexec/nagios \
		--datadir=${PREFIX}/share \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=${NAGIOSDIR} \
		--with-rrddir=${NAGIOSDIR}/snmp4nagios/rrd \
		--with-pngdir=${NAGIOSDIR}/snmp4nagios/png \
		--prefix=${PREFIX}

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MRRDTOOL}
LIB_DEPENDS+=	librrd.so:databases/rrdtool
CONFIGURE_ARGS+=--with-rrd
PLIST_SUB+=	RRD=""
.else
CONFIGURE_ARGS+=--with-rrd=no
PLIST_SUB+=	RRD="@comment "
.endif

.include <bsd.port.post.mk>
