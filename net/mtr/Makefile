# New ports collection makefile for:   mtr
# Version required:    0.28
# Date created:        12 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.6 1999/01/22 22:15:39 nectar Exp $
#

DISTNAME=	mtr-0.28
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/ \
		http://www.FreeBSD.org/~billf/distfiles/

MAINTAINER=	billf@FreeBSD.org

LIB_DEPENDS=    gtk10.1:${PORTSDIR}/x11-toolkits/gtk10

USE_AUTOCONF=	yes
USE_XLIB=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk10-config"

MAN8=	mtr.8

post-install:
	@chown root ${PREFIX}/sbin/mtr

.include <bsd.port.mk>
