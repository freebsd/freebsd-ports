# New ports collection makefile for:	mgv
# Version required:	mgv-2.4.3
# Date created:		4 Mar 1998
# Whom:			handy@physics.montana.edu
#
# $Id: Makefile,v 1.3 1998/05/29 07:19:01 tg Exp $
#

DISTNAME=	mgv-2.4.3
CATEGORIES=	print
MASTER_SITES=	http://www.trends.net/~mu/srcs/

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
USE_X_PREFIX=	yes
REQUIRES_MOTIF=	yes
MAKEFILE=	GNUmakefile
MAN1=		mgv.1

pre-build:
		@ ${CP} -f ${WRKSRC}/make/sys.freebsd.mk ${WRKSRC}/make/sys.mk

post-install:
		@ ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
