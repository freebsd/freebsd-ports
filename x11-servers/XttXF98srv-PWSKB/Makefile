# New ports collection makefile for:	X98server for PWSKB with X True Type
# Date created:		25 October 1998
# Whom:			NAKAJI Hiroyuki <nakaji@tutrp.tut.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xtt-98PWSKB
PORTVERSION=	${VERSION}.${PATCHLEVEL}
CATEGORIES=	x11-servers

MAINTAINER=	nakaji@tutrp.tut.ac.jp

RUN_DEPENDS=	mkfontdir.pl:${.CURDIR}/../XttXF86srv-common

ONLY_FOR_ARCHS=	i386

SERVER=		XF98_PWSKB

MASTERDIR=	${.CURDIR}/../XttXF86srv-common
PKGDIR=		${.CURDIR}

X98SERVER=	yes

.include	"${MASTERDIR}/Makefile"
