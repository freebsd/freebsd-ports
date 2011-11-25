# New ports collection makefile for:	ft2demos
# Date created:		12 April 2001
# Whom:			KANOU Hiroki <kanou@khdd.net>
#
# $FreeBSD$
#

PORTNAME=	ft2demos
PORTVERSION=	2.4.7
CATEGORIES=	print
MASTER_SITES=	SF/freetype/freetype-demos/${PORTVERSION} \
		RINGSERVER/graphics/freetype/freetype2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Demo programs for FreeType2

BUILD_DEPENDS+=	${FREETYPE_WRKSRC}/config.mk:${PORTSDIR}/print/freetype2:build
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

USE_BZIP2=	yes
USE_XORG=	xext
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:env
MAKE_ENV=	TOP_DIR="${FREETYPE_WRKSRC}"
MAKE_ARGS=	EXES="${FT_PROGRAMS}" X11_PATH="${LOCALBASE}"

PLIST_FILES=	${FT_PROGRAMS:S,^,bin/,}

FT_PROGRAMS=	ftbench ftchkwd ftdiff ftdump ftgamma ftgrid ftlint ftmemchk \
		ftmulti ftpatchk ftstring fttimer ftvalid ftview

.include <bsd.port.pre.mk>

FREETYPE_WRKSRC!=	cd ${PORTSDIR}/print/freetype2; ${MAKE} -V WRKSRC

do-install:
	@(cd ${WRKSRC}/bin/.libs/; ${INSTALL_PROGRAM} ${FT_PROGRAMS} ${PREFIX}/bin)

.include <bsd.port.post.mk>
