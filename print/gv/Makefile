# New ports collection makefile for:	gv
# Version required:	gv_2_7_6
# Date created:		16 Apr 1996
# Whom:			thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.3 1996/08/27 07:25:43 tg Exp $
#

DISTNAME=	gv_2_7_6
PKGNAME=	gv-2.7.6
CATEGORIES=	print
MASTER_SITES=	ftp://iphthf.physik.uni-mainz.de/pub/gv/unix/

MAINTAINER=	tg@freebsd.org

LIB_DEPENDS=	Xaw3d\\.6\\.:${PORTSDIR}/x11/Xaw3d
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript4

PATCH_STRIP=	-p1
WRKSRC=		${WRKDIR}/gv
USE_IMAKE=	yes

.include <bsd.port.mk>

