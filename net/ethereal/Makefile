# New ports collection makefile for:   ethereal
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	ethereal
PORTVERSION=	0.10.0a
PORTREVISION=	2
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.ethereal.com/pub/ethereal/%SUBDIR%/ \
		ftp://gd.tuwien.ac.at/infosys/security/ethereal/%SUBDIR%/ \
		ftp://ftp.sunet.se/pub/network/monitoring/ethereal/%SUBDIR%/ \
		ftp://ftp.mirrors.wiretapped.net/pub/security/packet-capture/ethereal/%SUBDIR%/ \
		http://www.mirrors.wiretapped.net/pub/security/packet-capture/ethereal/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old-versions

MAINTAINER=	billf@FreeBSD.org
COMMENT=	An X11/GTK network analyzer/capture tool

.if !defined(WITHOUT_SNMP)
LIB_DEPENDS=	netsnmp.6:${PORTSDIR}/net/net-snmp
.endif

USE_BZIP2=	yes
CONFIGURE_ARGS=	--program-transform-name=""
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
.if !defined(WITHOUT_X11)
USE_X_PREFIX=	yes
.if defined(WITH_GTK2)
LIB_DEPENDS+=	gtk-x11-2.0:${PORTSDIR}/x11-toolkits/gtk20
CONFIGURE_ARGS+=	--enable-gtk2=yes
.else
USE_GNOME=	gtk12
.endif
MAN1+=		ethereal.1
PLIST_SUB+=	ETHEREAL=bin/ethereal
.else
PLIST_SUB+=	ETHEREAL="@comment ethereal not built"
USE_GNOME=	glib12
CONFIGURE_ARGS+=	--enable-ethereal=no \
			--disable-gtktest
.endif

USE_LIBTOOL=	yes
LIBTOOLFILES=	configure epan/configure wiretap/configure
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.if !defined(WITHOUT_SNMP)
CONFIGURE_ARGS+=	--enable-snmp=yes \
			--with-net-snmp=${LOCALBASE}/lib \
			--without-ucdsnmp
.if exists(/usr/include/openssl/crypto.h)
CONFIGURE_ARGS+=	--with-ssl=/usr
.endif
.else
CONFIGURE_ARGS+=	--enable-snmp=no --without-ucdsnmp --without-net-snmp
.endif

.if defined(WITH_ADNS) || (!defined(WITHOUT_ADNS) && exists(${LOCALBASE}/lib/adns.so))
LIB_DEPENDS+=	adns.1:${PORTSDIR}/dns/adns
CONFIGURE_ARGS+=	--with-adns=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-adns
.endif

MAN1+=		editcap.1 idl2eth.1 mergecap.1 tethereal.1 text2pcap.1
MAN4+=		ethereal-filter.4

.include <bsd.port.mk>
