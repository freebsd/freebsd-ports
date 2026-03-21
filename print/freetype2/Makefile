PORTNAME=	freetype2
DISTVERSION=	2.14.2
CATEGORIES=	print
MASTER_SITES=	SAVANNAH/${PORTNAME:S/2//} \
		SF/freetype/${PORTNAME}/${DISTVERSION:C/^([0-9]+\.[0-9]+\.[0-9]+).*/\1/}/
DISTNAME=	${PORTNAME:S/2//}-${DISTVERSION}

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Free and portable TrueType font rendering engine
WWW=		https://www.freetype.org/

LICENSE=	FTL GPLv2+
LICENSE_COMB=	dual
LICENSE_NAME_FTL=	The FreeType Project license
LICENSE_FILE_FTL=	${WRKSRC}/docs/FTL.TXT
LICENSE_FILE_GPLv2+ =	${WRKSRC}/docs/GPLv2.TXT
LICENSE_PERMS_FTL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake cpe localbase:ldflags pathfix pkgconfig tar:xz
CPE_PRODUCT=	freetype
CPE_VENDOR=	freetype
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS \
		DISABLE_FORCE_DEBUG_POSTFIX \
		FT_REQUIRE_BZIP2 \
		FT_REQUIRE_ZLIB \
		FT_DISABLE_HARFBUZZ

SUB_FILES=	pkg-message

PORTDOCS=	CHANGES FTL.TXT formats.txt raster.txt reference

OPTIONS_DEFINE=		BROTLI DEBUG DOCS SUBPIXEL_RENDERING LONG_PCF_NAMES PNG \
			TABLE_VALIDATION
OPTIONS_DEFAULT=	BROTLI LONG_PCF_NAMES PNG
OPTIONS_SUB=		yes

SUBPIXEL_RENDERING_DESC=	Enable LCD rendering similar to ClearType
LONG_PCF_NAMES_DESC=		Enable long PCF family names
TABLE_VALIDATION_DESC=		TrueType GX/AAT and OpenType table validation

BROTLI_LIB_DEPENDS=	libbrotlidec.so:archivers/brotli
BROTLI_CMAKE_BOOL=	FT_REQUIRE_BROTLI
BROTLI_CMAKE_BOOL_OFF=	FT_DISABLE_BROTLI

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CMAKE_BOOL=		FT_REQUIRE_PNG
PNG_CMAKE_BOOL_OFF=	FT_DISABLE_PNG

post-patch-DEBUG-on:
	@${SED} -i '.debug.bak' \
		-e 's|.*\(#define FT_DEBUG_LEVEL_TRACE\).*|\1|' \
		-e 's|.*\(#define FT_DEBUG_MEMORY\).*|\1|' \
		${WRKSRC}/include/freetype/config/ftoption.h

post-patch-SUBPIXEL_RENDERING-on:
	@${SED} -i '.rendering.bak' \
		-e 's|.*\(#define FT_CONFIG_OPTION_SUBPIXEL_RENDERING\).*|\1|' \
		${WRKSRC}/include/freetype/config/ftoption.h

post-patch-LONG_PCF_NAMES-on:
	@${SED} -i '.names.bak' \
		-e 's|.*\(#define PCF_CONFIG_OPTION_LONG_FAMILY_NAMES\).*|\1|' \
		${WRKSRC}/include/freetype/config/ftoption.h

post-patch-TABLE_VALIDATION-on:
	@${REINPLACE_CMD} -e '/valid$$/s|#.*\(AUX_MODULES\)|\1|' \
		${WRKSRC}/modules.cfg

post-install-DOCS-on:
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
