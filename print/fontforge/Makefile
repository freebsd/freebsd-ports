PORTNAME=	fontforge
DISTVERSION=	20230101
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Type 1/TrueType/OpenType/bitmap font editor
WWW=		https://fontforge.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		compiler:c++11-lang cmake cpe desktop-file-utils gettext gnome \
		iconv:wchar_t pkgconfig shared-mime-info tar:xz
USE_GNOME=	cairo glib20 libxml2
USE_LDCONFIG=	yes

PORTDOCS=	*

CMAKE_ARGS=	-DIconv_INCLUDE_DIR=${ICONV_INCLUDE_PATH} \
		-DIconv_LIBRARY=${ICONV_LIB_PATH}

OPTIONS_DEFINE=	DOCS FREETYPE GIF JPEG PNG PYTHON READLINE SPIRO TIFF \
		TILEPATH UNINAMESLIST WOFF2 WRITEPFM
OPTIONS_RADIO=	GUI
OPTIONS_RADIO_GUI=	GTK3 X11
OPTIONS_SINGLE=	THEME
OPTIONS_SINGLE_THEME=	TANGO 2012
OPTIONS_DEFAULT=GIF GTK3 JPEG PNG PYTHON READLINE SPIRO TANGO TIFF \
		TILEPATH UNINAMESLIST WOFF2
OPTIONS_SUB=	yes

2012_DESC=	Old theme that was used until 2012
2012_CMAKE_ON=	-DTHEME:ENUM=2012

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR}
DOCS_CMAKE_BOOL=ENABLE_DOCS

FREETYPE_DESC=	Include freetype's internal debugger
FREETYPE_PATCH_DEPENDS=	${NONEXISTENT}:print/freetype2:extract
FREETYPE_CMAKE_ON=	-DENABLE_FREETYPE_DEBUGGER:PATH=${WRKSRC}/freetype

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CMAKE_BOOL=	ENABLE_LIBGIF

GTK3_LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
GTK3_USE=	gnome=gdkpixbuf,gtk30

JPEG_USES=	jpeg
JPEG_CMAKE_BOOL=ENABLE_LIBJPEG

PNG_LIB_DEPENDS=libpng.so:graphics/png
PNG_CMAKE_BOOL=	ENABLE_LIBPNG

PYTHON_USES=	python
PYTHON_USES_OFF=python:build
PYTHON_CMAKE_BOOL=	ENABLE_PYTHON_SCRIPTING ENABLE_PYTHON_EXTENSION

READLINE_USES=	readline
READLINE_CMAKE_BOOL=	ENABLE_LIBREADLINE

SPIRO_DESC=	Use libspiro to edit with clothoid splines
SPIRO_LIB_DEPENDS=	libspiro.so:graphics/libspiro
SPIRO_CMAKE_BOOL=	ENABLE_LIBSPIRO

TANGO_DESC=	Default theme based on the Tango Desktop Project
TANGO_CMAKE_ON=	-DTHEME:ENUM=tango

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CMAKE_BOOL=ENABLE_LIBTIFF

# This is disabled by default in fontforge's CMakeLists.txt, but it was
# previously enabled in this port when it was using GNU configure, so I've
# defaulted it to enabled
TILEPATH_DESC=	Enable a 'tile path' command (a variant of 'expand stroke')
TILEPATH_CMAKE_BOOL=	ENABLE_TILE_PATH

UNINAMESLIST_DESC=	Use libuninameslist for Unicode attribute data
UNINAMESLIST_LIB_DEPENDS=	libuninameslist.so:textproc/libuninameslist
UNINAMESLIST_CMAKE_BOOL=	ENABLE_LIBUNINAMESLIST

WOFF2_DESC=	WOFF2 web font support
WOFF2_LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
			libwoff2dec.so:devel/woff2
WOFF2_CMAKE_BOOL=	ENABLE_WOFF2

WRITEPFM_DESC=	Add ability to save PFM file w/o creating associated font file
WRITEPFM_CMAKE_BOOL=	ENABLE_WRITE_PFM

X11_USES=	xorg
X11_USE=	gnome=pango xorg=ice,sm,x11,xext,xft,xi
X11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
			libharfbuzz.so:print/harfbuzz
X11_RUN_DEPENDS=	${LOCALBASE}/share/fonts/gnu-unifont/unifont.pcf.gz:x11-fonts/gnu-unifont
X11_CMAKE_BOOL=	ENABLE_X11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK3} || ${PORT_OPTIONS:MX11}
CMAKE_ARGS+=	-DENABLE_GUI:BOOL=true
.else
CMAKE_ARGS+=	-DENABLE_GUI:BOOL=false
.endif

post-patch:
# https://github.com/fontforge/fontforge/issues/5251
	@${REINPLACE_CMD} 's/\(%[^%[:space:]]*\)hs/\1s/g' \
		${WRKSRC}/fontforgeexe/searchview.c \
		${WRKSRC}/po/de.po ${WRKSRC}/po/ca.po ${WRKSRC}/po/hr.po \
		${WRKSRC}/po/it.po ${WRKSRC}/po/pl.po ${WRKSRC}/po/uk.po \
		${WRKSRC}/po/en_GB.po ${WRKSRC}/po/fr.po ${WRKSRC}/po/vi.po \
		${WRKSRC}/po/ko.po ${WRKSRC}/po/ja.po

post-patch-FREETYPE-on:
	@${LN} -s $$(${MAKE} -C ${PORTSDIR}/print/freetype2 -V WRKSRC) \
		${WRKSRC}/freetype

post-stage-DOCS-on:
	@${RM} ${STAGEDIR}${DOCSDIR}/.buildinfo \
		${STAGEDIR}${DOCSDIR}/.nojekyll

.include <bsd.port.mk>
