# New ports collection makefile for:	X98server for NKVNEC with X True Type
# Version required:	1.2.1
# Date created:		25 October 1998
# Whom:			NAKAJI Hiroyuki <nakaji@tutrp.tut.ac.jp>
#
# $Id: Makefile,v 1.5 1999/04/13 03:16:03 simokawa Exp $
#

DISTNAME=	xc
PKGNAME=	xtt-98NKVNEC-${VERSION}.${PATCHLEVEL}
CATEGORIES=	x11

MAINTAINER=	nakaji@tutrp.tut.ac.jp

LIB_DEPENDS=	font.1:${.CURDIR}/../XttXF86srv-common

ONLY_FOR_ARCHS=	i386

SERVER=		XF98_NKVNEC

MASTERDIR=	${.CURDIR}/../XttXF86srv-common
PKGDIR=		${.CURDIR}/pkg

X98SERVER=	yes

.include	"${MASTERDIR}/Makefile"
