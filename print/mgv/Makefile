# New ports collection makefile for:	mgv
# Date created:		4 Mar 1998
# Whom:			handy@physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	mgv
PORTVERSION=	3.1.5
CATEGORIES=	print
MASTER_SITES=	http://www.trends.net/~mu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A PostScript and PDF previewer

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_MOTIF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	X11BASE=${X11BASE}
CONFIGURE_ARGS=	--enable-optimize \
		--disable-debug
PLIST_SUB=	MGV_VERSION=3.1.5

MAN1=		mgv.1

post-install:
		@ ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
