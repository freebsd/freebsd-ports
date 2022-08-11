PORTNAME=	ft2demos
PORTVERSION=	2.11.1
CATEGORIES=	print

MASTER_SITES=	https://gitlab.freedesktop.org

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Demo programs for FreeType2

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	${NONEXISTENT}:print/freetype2:build
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png

USES=		meson tar:xz xorg
USE_XORG=	x11

USE_GITLAB=	yes
GL_PROJECT=	freetype-demos
GL_ACCOUNT=	freetype
GL_COMMIT=	07027905d9a47664251b3ee362c5cfad1cddf86f

PLIST_FILES=	${FT_PROGRAMS:S,^,bin/,}

FT_PROGRAMS=	ftbench ftchkwd ftdiff ftdump ftgamma ftgrid ftlint ftmemchk \
		ftmulti ftpatchk ftstring fttimer ftvalid ftview

post-extract:
	${LN} -sf `${MAKE} -C ${.CURDIR}/../../print/freetype2 -V WRKSRC` \
	${WRKDIR}/${GL_PROJECT}-${GL_COMMIT}/subprojects/freetype2

do-install:
	@(cd ${WRKSRC}/_build && \
		${INSTALL_PROGRAM} ${FT_PROGRAMS} ${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.mk>
