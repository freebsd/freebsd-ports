# New ports collection makefile for:	ru-webalizer
# Date created:		04 Jan 2008
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../../graphics/gd
CATEGORIES=	russian

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A graphics library for fast image creation with KOI8-U support

BUILD_DEPENDS=  ${NONEXISTENT}:${PORTSDIR}/x11-fonts/geminifonts:fetch
GD_FONTS=	${DISTDIR}/x-koi8u.tgz koi6x10.bdf koi6x13.bdf \
		koi10x16b.bdf koi9x15.bdf koi10x20.bdf

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
