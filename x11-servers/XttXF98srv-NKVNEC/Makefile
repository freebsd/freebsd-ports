# New ports collection makefile for:	X98server for NKVNEC with X True Type
# Date created:		25 October 1998
# Whom:			NAKAJI Hiroyuki <nakaji@tutrp.tut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xtt-98NKVNEC
PORTVERSION=	${VERSION}.${PATCHLEVEL}
CATEGORIES=	x11-servers

MAINTAINER=	nakaji@tutrp.tut.ac.jp

RUN_DEPENDS=	mkfontdir.pl:${.CURDIR}/../XttXF86srv-common

ONLY_FOR_ARCHS=	i386

SERVER=		XF98_NKVNEC

MASTERDIR=	${.CURDIR}/../XttXF86srv-common
PKGDIR=		${.CURDIR}

X98SERVER=	yes

.include	"${MASTERDIR}/Makefile"
