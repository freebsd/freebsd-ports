# New ports collection makefile for:   ethereal
# Version required:    0.5.1
# Date created:        10 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.8 1999/01/05 13:49:59 vanilla Exp $
#

DISTNAME=	ethereal-0.5.1
CATEGORIES=	net
MASTER_SITES=	http://ethereal.zing.org/distribution/ \
		http://ethereal.boehm.org/distribution/

MAINTAINER=	billf@FreeBSD.ORG

LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config" \
		GLIB_CONFIG="${LOCALBASE}/bin/glib12-config"

MAN1=		ethereal.1

.include <bsd.port.mk>
