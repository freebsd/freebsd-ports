# New ports collection makefile for:	Xserver for SVGA with X True Type
# Version required:	1.1
# Date created:		15 April 1998
# Whom:			Taguchi Takeshi <taguchi@tohoku.iij.ad.jp>
#
# $Id: Makefile,v 1.6 1999/01/02 19:11:09 sada Exp $
#

DISTNAME=	xc
PKGNAME=	xtt-SVGA-1.1
CATEGORIES=	x11

MAINTAINER=	taguchi@tohoku.iij.ad.jp

LIB_DEPENDS=	font.1:${.CURDIR}/../XttXF86srv-common

SERVER=		XF86_SVGA

MASTERDIR=	${.CURDIR}/../XttXF86srv-common
PKGDIR=		${.CURDIR}/pkg

.include	"${MASTERDIR}/Makefile"
