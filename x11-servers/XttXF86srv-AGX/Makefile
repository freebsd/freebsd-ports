# New ports collection makefile for:	Xserver for AGX with X True Type
# Version required:	1.2.1
# Date created:		15 April 1998
# Whom:			Taguchi Takeshi <taguchi@tohoku.iij.ad.jp>
#
# $Id: Makefile,v 1.6 1999/01/15 09:49:27 asami Exp $
#

DISTNAME=	xc
PKGNAME=	xtt-AGX-${VERSION}.${PATCHLEVEL}
CATEGORIES=	x11

MAINTAINER=	taguchi@tohoku.iij.ad.jp

LIB_DEPENDS=	font.1:${.CURDIR}/../XttXF86srv-common

SERVER=		XF86_AGX

MASTERDIR=	${.CURDIR}/../XttXF86srv-common
PKGDIR=		${.CURDIR}/pkg

.include	"${MASTERDIR}/Makefile"
