# New ports collection makefile for:	blt
# Version required:	2.4f
# Date created:		22 September 1998
# Whom:			Kenjiro Cho <kjc@csl.sony.co.jp>
#
# $Id: Makefile,v 1.21 1998/09/25 10:05:13 asami Exp $
#

DISTNAME=	BLT2.4f
PKGNAME=	blt-2.4f
CATEGORIES=	x11-toolkits tk80
MASTER_SITES=	ftp://ftp.tcltk.com/pub/blt/

MAINTAINER=	kjc@csl.sony.co.jp

BROKEN_ELF=	library version numbers

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80

WRKSRC=		${WRKDIR}/blt2.4f
GNU_CONFIGURE=	yes
MANN=		BLT.n barchart.n bgexec.n bitmap.n bltdebug.n busy.n \
		dragdrop.n eps.n graph.n htext.n hierbox.n spline.n \
		stripchart.n table.n tabset.n tile.n vector.n watch.n winop.n \
		beep.n cutbuffer.n

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
