# New ports collection makefile for:   ethereal
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	ethereal
PORTVERSION=	0.8.10
CATEGORIES=	net ipv6
MASTER_SITES=	http://alpha1.linuxberg.com/files/x11/network/ \
		http://www.linuxberg.com/files/x11/network/ \
		http://jefnet.linuxberg.com/files/x11/network/ \
		http://ethereal.zing.org/distribution/ \
		http://ethereal.boehm.org/distribution/

MAINTAINER=	billf@FreeBSD.org

USE_X_PREFIX=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-snmp=no
PLIST_SUB=	PORTVERSION=${PORTVERSION}

MAN1=		ethereal.1 tethereal.1 editcap.1

.include <bsd.port.mk>
