# New ports collection makefile for:	gv
# Version required:	gv-3.4.3
# Date created:		16 Apr 1996
# Whom:			tg@freebsd.org
#
# $Id: Makefile,v 1.10 1997/04/18 10:09:56 asami Exp $
#

DISTNAME=	gv-3.4.3
CATEGORIES=	print
MASTER_SITES=	ftp://thep.physik.uni-mainz.de/pub/gv/unix/

MAINTAINER=	tg@freebsd.org

LIB_DEPENDS=	Xaw3d\\.6\\.:${PORTSDIR}/x11/Xaw3d

USE_IMAKE=	yes

post-install:
	@/bin/sh ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
