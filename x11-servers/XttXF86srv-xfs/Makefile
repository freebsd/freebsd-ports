# New ports collection makefile for:	X Font Server with X True Type
# Date created:		15 April 1998
# Whom:			Taguchi Takeshi <taguchi@tohoku.iij.ad.jp>
#
# $FreeBSD$
#

PORTNAME=	xtt-xfs
PORTVERSION=	${VERSION}.${PATCHLEVEL}
CATEGORIES=	x11-servers

MAINTAINER=	taguchi@tohoku.iij.ad.jp
COMMENT=	A X True Type Font Server

RUN_DEPENDS=	mkfontdir.pl:${.CURDIR}/../XttXF86srv-common

PLIST_FILES=	bin/xfs.xtt
SERVER=		xfs

MASTERDIR=	${.CURDIR}/../XttXF86srv-common
PKGDIR=		${.CURDIR}

.include	"${MASTERDIR}/Makefile"
