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

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		glib12.3:${PORTSDIR}/devel/glib12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-snmp=no
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}"
PLIST_SUB=	PORTVERSION=${PORTVERSION}

MAN1=		ethereal.1 tethereal.1 editcap.1

.include <bsd.port.mk>
