# New ports collection makefile for:   mtr
# Version required:    0.28
# Date created:        12 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.4 1998/11/04 03:47:08 jkoshy Exp $
#

DISTNAME=	mtr-0.28
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.bitwizard.nl/mtr/

MAINTAINER=	billf@FreeBSD.org

LIB_DEPENDS=    gtk.1:${PORTSDIR}/x11-toolkits/gtk

USE_AUTOCONF=	yes
USE_XLIB=	yes

MAN8=	mtr.8

post-install:
	@chown root ${PREFIX}/sbin/mtr

.include <bsd.port.mk>
