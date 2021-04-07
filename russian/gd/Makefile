MASTERDIR=	${.CURDIR}/../../graphics/gd
CATEGORIES=	russian

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Graphics library for fast image creation with KOI8-U support

FETCH_DEPENDS=  ${NONEXISTENT}:x11-fonts/geminifonts:fetch
BUILD_DEPENDS=  ${NONEXISTENT}:x11-fonts/geminifonts:fetch
GD_FONTS=	${DISTDIR}/x-koi8u.tgz koi6x10.bdf koi6x13.bdf \
		koi10x16b.bdf koi9x15.bdf koi10x20.bdf

.include "${MASTERDIR}/Makefile"
