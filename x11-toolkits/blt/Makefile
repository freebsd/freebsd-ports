# New ports collection makefile for:	blt
# Version required:	2.1
# Date created:		3 August 1996
# Whom:			lukin <lukin@okbmei.msk.su>
#
# $Id: Makefile,v 1.10 1996/11/13 12:41:36 asami Exp $
#

DISTNAME=	blt-2.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/NEW/
DISTFILES=	BLT2.1.tar.gz

MAINTAINER=	lukin@okbmei.msk.su

LIB_DEPENDS=	tk41\\.1:${PORTSDIR}/x11/tk41

WRKSRC=		${WRKDIR}/blt2.1
GNU_CONFIGURE=	yes
MANN=		BLT.n barchart.n bgexec.n bitmap.n bltdebug.n busy.n \
		dragdrop.n graph.n htext.n spline.n table.n tile.n \
		vector.n watch.n winop.n

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
