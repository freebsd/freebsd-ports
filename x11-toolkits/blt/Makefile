# New ports collection makefile for:	blt
# Version required:	2.1
# Date created:		3 August 1996
# Whom:			lukin
#
# $Id: Makefile,v 1.1 1996/07/07 00:21:03 lukin Exp $
#

DISTNAME=	blt-2.1
CATEGORIES+=	x11
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/NEW/
DISTFILES=	BLT2.1.tar.gz
WRKSRC=		${WRKDIR}/blt2.1

MAINTAINER=	lukin@okbmei.msk.su

LIB_DEPENDS=	tcl75\\.:${PORTSDIR}/lang/tcl75 \
		tk41\\.:${PORTSDIR}/x11/tk41

GNU_CONFIGURE=	yes
ALL_TARGET=	all

post-install:
	ldconfig -m ${PREFIX}/lib
	gzip -9nf ${PREFIX}/man/mann/BLT.n ${PREFIX}/man/mann/barchart.n ${PREFIX}/man/mann/bgexec.n ${PREFIX}/man/mann/bitmap.n ${PREFIX}/man/mann/bltdebug.n ${PREFIX}/man/mann/busy.n ${PREFIX}/man/mann/dragdrop.n ${PREFIX}/man/mann/graph.n ${PREFIX}/man/mann/htext.n ${PREFIX}/man/mann/spline.n ${PREFIX}/man/mann/table.n ${PREFIX}/man/mann/tile.n ${PREFIX}/man/mann/vector.n ${PREFIX}/man/mann/watch.n ${PREFIX}/man/mann/winop.n

.include <bsd.port.mk>
