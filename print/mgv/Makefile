# New ports collection makefile for:	mgv
# Version required:	mgv-2.3.1
# Date created:		4 Mar 1998
# Whom:			handy@physics.montana.edu
#
# $Id$
#

DISTNAME=	mgv-2.3.1
CATEGORIES=	print
MASTER_SITES=	http://home.echo-on.net/~mu/srcs/

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
USE_X11=	yes
REQUIRES_MOTIF=	yes
MAKEFILE=	GNUmakefile
MAN1=		mgv.1

pre-build:
		@ ${CP} -f ${WRKSRC}/make/sys.freebsd3.mk ${WRKSRC}/make/sys.mk

post-install:
		@ ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
