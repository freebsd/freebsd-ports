# New ports collection makefile for:	X98server for SVGA with X True Type
# Version required:	1.1
# Date created:		25 October 1998
# Whom:			NAKAJI Hiroyuki <nakaji@zeisei.dpri.kyoto-u.ac.jp>
#
# $Id: Makefile,v 1.2 1999/01/02 19:11:12 sada Exp $
#

DISTNAME=	xc
PKGNAME=	xtt-98SVGA-1.1
CATEGORIES=	x11

MAINTAINER=	nakaji@zeisei.dpri.kyoto-u.ac.jp

LIB_DEPENDS=	font.1:${.CURDIR}/../XttXF86srv-common

SERVER=		XF98_SVGA

MASTERDIR=	${.CURDIR}/../XttXF86srv-common
PKGDIR=		${.CURDIR}/pkg

X98SERVER=	yes

.include	"${MASTERDIR}/Makefile"
