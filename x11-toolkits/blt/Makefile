# New ports collection makefile for:	blt
# Version required:	2.4c
# Date created:		9 July 1998
# Whom:			Kenjiro Cho <kjc@csl.sony.co.jp>
#
# $Id: Makefile,v 1.17 1998/07/12 17:40:31 kjc Exp $
#

DISTNAME=	BLT2.4c
PKGNAME=	blt-2.4c
CATEGORIES=	x11-toolkits tk80
MASTER_SITES=	ftp://ftp.tcltk.com/pub/blt/

MAINTAINER=	kjc@csl.sony.co.jp

LIB_DEPENDS=	tk80\\.1:${PORTSDIR}/x11/tk80

WRKSRC=		${WRKDIR}/blt2.4c
GNU_CONFIGURE=	yes
MANN=		BLT.n barchart.n bgexec.n bitmap.n bltdebug.n busy.n \
		dragdrop.n eps.n graph.n htext.n hierbox.n spline.n \
		stripchart.n table.n tabset.n tile.n vector.n watch.n winop.n \
		beep.n cutbuffer.n

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
