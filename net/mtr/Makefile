# New ports collection makefile for:   mtr
# Version required:    0.21
# Date created:        12 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.2 1998/08/25 00:04:05 steve Exp $
#

DISTNAME=	mtr-0.21
CATEGORIES=	net
MASTER_SITES=	http://www.mkimball.org/

MAINTAINER=	billf@chc-chimes.com

LIB_DEPENDS=    gtk.1:${PORTSDIR}/x11-toolkits/gtk

FETCH_BEFORE_ARGS= -b
USE_AUTOCONF=	yes
USE_XLIB=	yes

MAN8=	mtr.8

post-install:
	@chown root ${PREFIX}/sbin/mtr

.include <bsd.port.mk>
