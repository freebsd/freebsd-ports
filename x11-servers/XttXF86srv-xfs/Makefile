# New ports collection makefile for:	X Font Server with X True Type
# Version required:	1.2.1
# Date created:		15 April 1998
# Whom:			Taguchi Takeshi <taguchi@tohoku.iij.ad.jp>
#
# $Id: Makefile,v 1.7 1999/04/02 08:28:31 taoka Exp $
#

DISTNAME=	xc
PKGNAME=	xtt-xfs-${VERSION}.${PATCHLEVEL}
CATEGORIES=	x11-servers

MAINTAINER=	taguchi@tohoku.iij.ad.jp

LIB_DEPENDS=	font.1:${.CURDIR}/../XttXF86srv-common

SERVER=		xfs

MASTERDIR=	${.CURDIR}/../XttXF86srv-common
PKGDIR=		${.CURDIR}/pkg

.include	"${MASTERDIR}/Makefile"
