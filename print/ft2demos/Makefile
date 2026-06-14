PORTNAME=	ft2demos
DISTVERSION=	2.14.3
CATEGORIES=	print

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Demo programs for FreeType2
WWW=		https://gitlab.com/freetype/freetype-demos/

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	${NONEXISTENT}:print/freetype2:build
LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

USES=		gnome meson tar:bz2 xorg
USE_GITLAB=	yes
GL_ACCOUNT=	freetype
GL_PROJECT=	freetype-demos
GL_TAGNAME=	VER-${DISTVERSION:S|.|-|g}
USE_GNOME=	librsvg2
USE_XORG=	x11
MESON_ARGS=	-Dfreetype2:harfbuzz=disabled

PLIST_FILES=	${FT_PROGRAMS:S,^,bin/,}

FT_PROGRAMS=	ftbench ftchkwd ftdiff ftdump ftgamma ftgrid ftlint ftmemchk \
		ftmulti ftpatchk ftsdf ftstring fttimer ftvalid ftview ttdebug

post-extract:
	${LN} -sf `${MAKE} -C ${.CURDIR}/../../print/freetype2 -V WRKSRC` \
		${WRKSRC}/subprojects/freetype2

do-install:
	@(cd ${WRKSRC}/_build && \
		${INSTALL_PROGRAM} ${FT_PROGRAMS} ${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.mk>
