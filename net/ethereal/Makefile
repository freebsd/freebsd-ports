# New ports collection makefile for:   ethereal
# Version required:    0.7.8
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

DISTNAME=	ethereal-0.7.8
CATEGORIES=	net
MASTER_SITES=	http://alpha1.linuxberg.com/files/x11/network/ \
		http://www.linuxberg.com/files/x11/network/ \
		http://jefnet.linuxberg.com/files/x11/network/ \
		http://ethereal.zing.org/distribution/ \
		http://ethereal.boehm.org/distribution/
		
MAINTAINER=	billf@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

MAN1=		ethereal.1

.include <bsd.port.mk>
