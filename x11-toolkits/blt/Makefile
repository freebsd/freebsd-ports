# New ports collection makefile for:	blt
# Date created:		22 September 1998
# Whom:			Kenjiro Cho <kjc@csl.sony.co.jp>
#
# $FreeBSD$
#

PORTNAME=	blt
PORTVERSION=	2.4u
CATEGORIES=	x11-toolkits tk83
MASTER_SITES=	ftp://tcltk.sourceforge.net/pub/tcltk/blt/ \
		ftp://ftp.csl.sony.co.jp/pub/kjc/ttt-libs/
DISTNAME=	BLT${PORTVERSION}

MAINTAINER=	kjc@csl.sony.co.jp

LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83

WRKSRC=		${WRKDIR}/blt2.4u
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-tcl=${PREFIX}/lib/tcl8.3 --with-tk=${PREFIX}/lib/tk8.3
INSTALLS_SHLIB=	yes

MANN=		BLT.n barchart.n beep.n bgexec.n bitmap.n \
		bltdebug.n busy.n cutbuffer.n dragdrop.n eps.n \
		graph.n hierbox.n hiertable.n htext.n spline.n \
		stripchart.n table.n tabset.n tile.n vector.n \
		watch.n winop.n

.include <bsd.port.pre.mk>

post-install:
	${LN} -sf libBLT24.so.2 ${PREFIX}/lib/libBLT24.so
	${LN} -sf libBLTlite24.so.2 ${PREFIX}/lib/libBLTlite24.so

.include <bsd.port.post.mk>
