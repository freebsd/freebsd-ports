# Created by: KANOU Hiroki <kanou@khdd.net>
# $FreeBSD$

PORTNAME=	fontforge
PORTVERSION=	20190801
PORTREVISION=	2
CATEGORIES=	print

MAINTAINER=	cyberbotx@cyberbotx.com
COMMENT=	Type 1/TrueType/OpenType/bitmap font editor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2

USES=		autoreconf compiler:c++11-lang gettext gmake gnome iconv:wchar_t libtool \
		localbase pkgconfig
USE_GITHUB=	yes
USE_GNOME=	glib20 libxml2

# It seems that iconv is required regardless of this setting, so forcing it on
CONFIGURE_ARGS=	--with-iconv

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
INSTALLS_ICONS=	yes

PORTDOCS=	* .htaccess

OPTIONS_DEFINE=	CAIRO DOCS FREETYPE GIF JPEG PNG PYTHON READLINE SPIRO TIFF \
		TILEPATH UNINAMESLIST WOFF2 WRITEPFM
OPTIONS_GROUP=	GUI
OPTIONS_GROUP_GUI=	GTK3 X11
OPTIONS_SINGLE=	THEME
OPTIONS_SINGLE_THEME=	TANGO 2012
OPTIONS_DEFAULT=CAIRO GIF GTK3 JPEG PNG PYTHON READLINE SPIRO TANGO TIFF \
		TILEPATH UNINAMESLIST WOFF2
OPTIONS_SUB=	yes

2012_DESC=	Old theme that was used until 2012
2012_CONFIGURE_ENABLE=	theme-2012

CAIRO_USE=	gnome=cairo,pango
CAIRO_CONFIGURE_WITH=	cairo
CAIRO_IMPLIES=	PNG

FREETYPE_DESC=	Include freetype's internal debugger
FREETYPE_PATCH_DEPENDS=	${NONEXISTENT}:print/freetype2:extract
FREETYPE_CONFIGURE_ENABLE=	freetype-debugger=${WRKSRC}/freetype

GIF_LIB_DEPENDS=	libgif.so:graphics/giflib
GIF_CONFIGURE_WITH=	giflib

GTK3_USE=	gnome=gtk30
GTK3_CONFIGURE_ENABLE=	gdk
GTK3_IMPLIES=	CAIRO X11

JPEG_USES=	jpeg
JPEG_CONFIGURE_WITH=	libjpeg

PNG_LIB_DEPENDS=libpng.so:graphics/png
PNG_CONFIGURE_WITH=	libpng

PYTHON_USES=	python:3.5-3.7
PYTHON_USES_OFF=python:3.5-3.7,build
PYTHON_CONFIGURE_ENABLE=	python-scripting python-extension

READLINE_USES=	readline:port
READLINE_CONFIGURE_WITH=	libreadline

SPIRO_DESC=	Use libspiro to edit with clothoid splines
SPIRO_LIB_DEPENDS=	libspiro.so:graphics/libspiro
SPIRO_CONFIGURE_WITH=	libspiro

TANGO_DESC=	Default theme based on the Tango Desktop Project

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CONFIGURE_WITH=	libtiff

TILEPATH_DESC=	Enable a 'tile path' command (a variant of 'expand stroke')
TILEPATH_CONFIGURE_ENABLE=	tile-path

UNINAMESLIST_DESC=	Use libuninameslist for Unicode attribute data
UNINAMESLIST_LIB_DEPENDS=	libuninameslist.so:textproc/libuninameslist
UNINAMESLIST_CONFIGURE_WITH=	libuninameslist

WOFF2_DESC=	WOFF2 web font support
WOFF2_LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
			libwoff2dec.so:devel/woff2
WOFF2_CONFIGURE_ENABLE=	woff2

WRITEPFM_DESC=	Add ability to save PFM file w/o creating associated font file
WRITEPFM_CONFIGURE_ENABLE=	write-pfm

X11_USES=	desktop-file-utils shared-mime-info xorg
X11_USE=	gnome=pango xorg=ice,sm,x11,xft,xi
X11_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
X11_RUN_DEPENDS=	${LOCALBASE}/share/fonts/gnu-unifont/unifont.pcf.gz:x11-fonts/gnu-unifont
X11_CONFIGURE_WITH=	x

post-patch-FREETYPE-on:
	@${LN} -s $$(${MAKE} -C ${PORTSDIR}/print/freetype2 -V WRKSRC) ${WRKSRC}/freetype

.include <bsd.port.mk>
