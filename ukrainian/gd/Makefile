# Created by: mike@LITech.lviv.ua
# $FreeBSD$

MASTERDIR=	${.CURDIR:H:H}/graphics/gd
CATEGORIES=	ukrainian

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Graphics library for fast image creation with KOI8-U support

BUILD_DEPENDS=  ${NONEXISTENT}:x11-fonts/geminifonts:fetch
GD_FONTS=	${DISTDIR}/x-koi8u.tgz koi6x10.bdf koi6x13.bdf \
		koi10x16b.bdf koi9x15.bdf koi10x20.bdf

.include "${MASTERDIR}/Makefile"
