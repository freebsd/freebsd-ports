# New ports collection makefile for:	mgv
# Version required:	mgv-3.1.0
# Date created:		4 Mar 1998
# Whom:			handy@physics.montana.edu
#
# $Id: Makefile,v 1.6 1998/09/15 05:39:20 asami Exp $
#

DISTNAME=	mgv-3.1.0
CATEGORIES=	print
MASTER_SITES=	http://www.trends.net/~mu/srcs/

MAINTAINER=	handy@physics.montana.edu

LIB_DEPENDS=	Xpm.5:${PORTSDIR}/graphics/xpm

BROKEN=		fetch

USE_X_PREFIX=	yes
REQUIRES_MOTIF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	X11BASE=${X11BASE}
CONFIGURE_ARGS=	--enable-optimize \
		--disable-debug

post-install:
		@ ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
