# New ports collection makefile for:	gv
# Version required:	gv_2_3_b1
# Date created:		16 Apr 1996
# Whom:			thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id$
#

DISTNAME=	gv_2_3_b1
PKGNAME=	gv-2.3b1
CATEGORIES+=	print
MASTER_SITES=	ftp://iphthf.physik.uni-mainz.de/pub/vms/linux/

MAINTAINER=	thomas@ghpc8.ihf.rwth-aachen.de

LIB_DEPENDS=	Xaw3d\\.6\\.:${PORTSDIR}/x11/Xaw3d

PATCH_STRIP=	-p1
WRKSRC=		${WRKDIR}/gv
USE_IMAKE=	yes

pre-configure:
	cp ${FILESDIR}/config.freebsd ${WRKSRC}

.include <bsd.port.mk>

