# New ports collection makefile for:	Xserver for SVGA with X True Type
# Version required:	1.1
# Date created:		15 April 1998
# Whom:			Taguchi Takeshi <taguchi@tohoku.iij.ad.jp>
#
# $Id: Makefile,v 1.5 1998/12/05 06:16:22 kuriyama Exp $
#

DISTNAME=	xc
PKGNAME=	xtt-SVGA-1.1
CATEGORIES=	x11

MAINTAINER=	taguchi@tohoku.iij.ad.jp

RUN_DEPENDS=	mkfontdir.pl:${.CURDIR}/../XttXF86srv-common

SERVER=		XF86_SVGA

MASTERDIR=	${.CURDIR}/../XttXF86srv-common
PKGDIR=		${.CURDIR}/pkg

.include	"${MASTERDIR}/Makefile"
