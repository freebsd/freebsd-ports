# New ports collection makefile for:	mgv
# Version required:	mgv-3.1.2
# Date created:		4 Mar 1998
# Whom:			handy@physics.montana.edu
#
# $Id: Makefile,v 1.10 1998/10/12 15:24:14 jseger Exp $
#

DISTNAME=	mgv-3.1.5
CATEGORIES=	print
MASTER_SITES=	http://www.trends.net/~mu/srcs/

MAINTAINER=	handy@physics.montana.edu

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
REQUIRES_MOTIF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	X11BASE=${X11BASE}
CONFIGURE_ARGS=	--enable-optimize \
		--disable-debug
PLIST_SUB=	MGV_VERSION=3.1.5

post-install:
		@ ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
