# New ports collection makefile for:   astime
# Version required:    1.2
# Date created:        21 Nov 1998
# Whom:                Brian Handy <handy@physics.montana.edu>
#
# $Id: Makefile,v 1.2 1998/12/08 18:59:26 vanilla Exp $
#

DISTNAME=	astime-1.2
CATEGORIES=	x11-clocks
MASTER_SITES=	http://bewoner.dma.be/Albert/linux/software/ \
		ftp://ftp.tux.org/pub/x/afterstep/apps/astime/ \
		ftp://ftp.digex.net/.2/wm/AfterStep/apps/astime/ \
		ftp://ftp.bse.bg/pub/Unix/X11/wm/afterstep/apps/astime/

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install install.man

MAN1=		astime.1

.include <bsd.port.mk>
