# New ports collection makefile for:   astime
# Date created:        21 Nov 1998
# Whom:                Brian Handy <handy@physics.montana.edu>
#
# $FreeBSD$
#

PORTNAME=	astime
PORTVERSION=	2.6
CATEGORIES=	x11-clocks afterstep
MASTER_SITES=	ftp://ftp.afterstep.org/apps/astime/ \
		http://www.tigr.net/afterstep/as-apps/download/astime/ \
		ftp://ftp.tux.org/pub/x/afterstep/apps/astime/

MAINTAINER=	kris@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install install.man

MAN1=		astime.1

.include <bsd.port.mk>
