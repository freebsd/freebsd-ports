# New ports collection makefile for:	blt
# Version required:	2.4f
# Date created:		22 September 1998
# Whom:			Kenjiro Cho <kjc@csl.sony.co.jp>
#
# $FreeBSD$
#

DISTNAME=	BLT2.4h
PKGNAME=	blt-2.4h
CATEGORIES=	x11-toolkits tk80
MASTER_SITES=	ftp://ftp.tcltk.com/pub/blt/

MAINTAINER=	kjc@csl.sony.co.jp

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80

WRKSRC=		${WRKDIR}/blt2.4h
GNU_CONFIGURE=	yes
MANN=		BLT.n barchart.n bgexec.n bitmap.n bltdebug.n busy.n \
		dragdrop.n eps.n graph.n htext.n hierbox.n spline.n \
		stripchart.n table.n tabset.n tile.n vector.n watch.n winop.n \
		beep.n cutbuffer.n

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
SO_VERSION=	2
.else
SO_VERSION=	2.4
.endif

post-install:
	${LN} -sf libBLT24.so.${SO_VERSION} ${PREFIX}/lib/libBLT24.so
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
