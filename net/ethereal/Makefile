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

.if defined(WITH_SNMP)
LIB_DEPENDS=	snmp.4:${PORTSDIR}/net/net-snmp
.endif

USE_X_PREFIX=	yes
USE_GTK=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure epan/configure wiretap/configure
.if defined(WITH_SNMP)
CONFIGURE_ARGS+=	--enable-snmp=yes
.if exists(/usr/include/openssl/crypto.h)
CONFIGURE_ARGS+=	--with-ssl=/usr
.endif
.else
CONFIGURE_ARGS+=	--enable-snmp=no
.endif
PLIST_SUB=	PORTVERSION=${PORTVERSION}

MAN1=		editcap.1 ethereal.1 idl2eth.1 mergecap.1 tethereal.1 \
		text2pcap.1

pre-install:
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${i} ${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
