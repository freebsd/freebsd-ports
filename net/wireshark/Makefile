# New ports collection makefile for:   ethereal
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	ethereal
PORTVERSION=	0.9.0
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.ethereal.com/pub/ethereal/%SUBDIR%/ \
		ftp://gd.tuwien.ac.at/infosys/security/ethereal/%SUBDIR%/ \
		ftp://ftp.sunet.se/pub/network/monitoring/ethereal/%SUBDIR%/ \
		ftp://the.wiretapped.net/pub/security/packet-sniffing/ethereal/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old-versions

MAINTAINER=	billf@FreeBSD.org

.if !defined(WITHOUT_SNMP)
LIB_DEPENDS=	snmp.4:${PORTSDIR}/net/net-snmp
.endif

.if !defined(WITHOUT_X11)
USE_X_PREFIX=	yes
USE_GTK=	yes
MAN1+=		ethereal.1
PLIST_SUB+=	ETHEREAL=bin/ethereal
.else
PLIST_SUB+=	ETHEREAL="@comment ethereal not built"
LIB_DEPENDS+=	glib12.3:${PORTSDIR}/devel/glib12
CONFIGURE_ARGS+=	--enable-ethereal=no \
			--disable-gtktest
CONFIGURE_ENV+=	GLIB_CONFIG=${LOCALBASE}/bin/glib12-config
.endif

USE_LIBTOOL=	yes
LIBTOOLFILES=	configure epan/configure wiretap/configure
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.if !defined(WITHOUT_SNMP)
CONFIGURE_ARGS+=	--enable-snmp=yes \
			--with-ucdsnmp=${LOCALBASE}/lib
.if exists(/usr/include/openssl/crypto.h)
CONFIGURE_ARGS+=	--with-ssl=/usr
.endif
.else
CONFIGURE_ARGS+=	--enable-snmp=no
.endif

MAN1+=		editcap.1 idl2eth.1 mergecap.1 tethereal.1 text2pcap.1

pre-install:
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${i} ${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
