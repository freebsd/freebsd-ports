# New ports collection makefile for:	gv
# Version required:	gv-2.9.4
# Date created:		16 Apr 1996
# Whom:			tg@freebsd.org
#
# $Id: Makefile,v 1.6 1997/03/27 07:43:04 tg Exp $
#

DISTNAME=	gv-2.9.4
CATEGORIES=	print
MASTER_SITES=	ftp://thep.physik.uni-mainz.de/pub/gv/unix/

MAINTAINER=	tg@freebsd.org

LIB_DEPENDS=	Xaw3d\\.6\\.:${PORTSDIR}/x11/Xaw3d

PATCH_STRIP=	-p1
USE_IMAKE=	yes

post-install:
	@/bin/sh ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
