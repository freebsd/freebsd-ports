# New ports collection makefile for:   astime
# Version required:    2.1
# Date created:        21 Nov 1998
# Whom:                Brian Handy <handy@physics.montana.edu>
#
# $FreeBSD$
#

DISTNAME=	astime-2.1
CATEGORIES=	x11-clocks afterstep
MASTER_SITES=	http://bewoner.dma.be/Albert/software/ \
		http://www.tigr.net/afterstep/as-apps/download/astime/ \
		ftp://ftp.tux.org/pub/x/afterstep/apps/astime/ \
		ftp://ftp.digex.net/.2/wm/AfterStep/apps/astime/

MAINTAINER=	kris@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install install.man

MAN1=		astime.1

.include <bsd.port.mk>
