# New ports collection makefile for:	X98server for PWLB with X True Type
# Version required:	1.2.1
# Date created:		25 October 1998
# Whom:			NAKAJI Hiroyuki <nakaji@zeisei.dpri.kyoto-u.ac.jp>
#
# $Id: Makefile,v 1.4 1999/04/02 08:28:47 taoka Exp $
#

DISTNAME=	xc
PKGNAME=	xtt-98PWLB-${VERSION}.${PATCHLEVEL}
CATEGORIES=	x11

MAINTAINER=	nakaji@zeisei.dpri.kyoto-u.ac.jp

LIB_DEPENDS=	font.1:${.CURDIR}/../XttXF86srv-common

ONLY_FOR_ARCHS=	i386

SERVER=		XF98_PWLB

MASTERDIR=	${.CURDIR}/../XttXF86srv-common
PKGDIR=		${.CURDIR}/pkg

X98SERVER=	yes

.include	"${MASTERDIR}/Makefile"
