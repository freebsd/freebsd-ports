# New ports collection makefile for:   ethereal
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	ethereal
PORTVERSION=	0.8.14
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.ethereal.com/pub/ethereal/ \
		ftp://gd.tuwien.ac.at/infosys/security/ethereal/ \
		ftp://ftp.sunet.se/pub/network/monitoring/ethereal/ \
		ftp://the.wiretapped.net/pub/security/packet-sniffing/ethereal/

MAINTAINER=	billf@FreeBSD.org

USE_X_PREFIX=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-snmp=no
PLIST_SUB=	PORTVERSION=${PORTVERSION}

MAN1=		ethereal.1 tethereal.1 editcap.1

.include <bsd.port.mk>
