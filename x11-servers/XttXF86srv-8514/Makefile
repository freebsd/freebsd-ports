# New ports collection makefile for:	Xserver for I8514 with X True Type
# Version required:	1.2.1
# Date created:		15 April 1998
# Whom:			Taguchi Takeshi <taguchi@tohoku.iij.ad.jp>
#
# $Id: Makefile,v 1.7 1999/04/02 08:27:59 taoka Exp $
#

DISTNAME=	xc
PKGNAME=	xtt-8514-${VERSION}.${PATCHLEVEL}
CATEGORIES=	x11

MAINTAINER=	taguchi@tohoku.iij.ad.jp

LIB_DEPENDS=	font.1:${.CURDIR}/../XttXF86srv-common

ONLY_FOR_ARCHS=	i386

SERVER=		XF86_8514

MASTERDIR=	${.CURDIR}/../XttXF86srv-common
PKGDIR=		${.CURDIR}/pkg

.include	"${MASTERDIR}/Makefile"
