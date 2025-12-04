PORTNAME=	scribus
DISTVERSION=	1.6.4
PORTREVISION=	1
CATEGORIES=	print editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}${PKGNAMESUFFIX}/${PORTVERSION}/ \
		http://www.scribus.net/downloads/${PORTVERSION}/

PATCH_SITES=	https://github.com/scribusproject/scribus/commit/
PATCHFILES=		\
							ae78d676dab57b0cbf0007fcf91994f3598cfab5.patch:-p1 \
							57160b8d9501899b46adc140064ae7f53d85fb13.patch:-p1 \
							c2b3f3f93e1d32e6ae5e0abce01579e37fcc7d18.patch:-p1 \
							19e208523c09d3ce5deb2bb0193cd9eb6ddee5f6.patch:-p1 \
							54a725b24d173dc251da0b9638b230f4bf408cc6.patch:-p1

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Comprehensive desktop publishing program
WWW=		https://www.scribus.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		librevenge-0.0.so:textproc/librevenge \
		libcups.so:print/cups \
		libcdr-0.1.so:graphics/libcdr01 \
		libfreehand-0.1.so:graphics/libfreehand \
		libpagemaker-0.0.so:print/libpagemaker \
		libmspub-0.1.so:print/libmspub01 \
		libvisio-0.1.so:textproc/libvisio01 \
		libfreetype.so:print/freetype2 \
		libtiff.so:graphics/tiff \
		libpoppler.so:graphics/poppler \
		libharfbuzz-icu.so:print/harfbuzz-icu \
		libfontconfig.so:x11-fonts/fontconfig \
		libharfbuzz.so:print/harfbuzz \
		libpng.so:graphics/png \
		libicuuc.so:devel/icu \
		libqxp-0.0.so:textproc/libqxp \
		libzmf-0.0.so:graphics/libzmf

USES=		cmake compiler:c++17-lang desktop-file-utils gnome jpeg \
		pkgconfig python qt:5 shared-mime-info tar:xz
USE_QT=		buildtools:build core gui linguisttools:build network opengl \
		printsupport qmake:build widgets xml
USE_GNOME=	cairo libxml2

CMAKE_ARGS=	-DWANT_CPP17=YES

CONFLICTS_INSTALL=	scribus-devel

OPTIONS_DEFINE=	BOOST DOCS GRAPHICSMAGICK HUNSPELL OSG PDF
OPTIONS_DEFAULT=BOOST GRAPHICSMAGICK HUNSPELL OSG PDF

BOOST_DESC=	Enable support for Boost-based enhancement
GRAPHICSMAGICK_DESC=	Use GraphicsMagick for image import support
HUNSPELL_DESC=	Enable spellchecking via hunspell
OSG_DESC=	Enable 3D rendering via osg
PDF_DESC=	Enable PDF export via podofo

BOOST_BUILD_DEPENDS=	boost-libs>0:devel/boost-libs
BOOST_CMAKE_BOOL=	WITH_BOOST

GRAPHICSMAGICK_LIB_DEPENDS=	libGraphicsMagick.so:graphics/GraphicsMagick
GRAPHICSMAGICK_CMAKE_BOOL=	WANT_GRAPHICSMAGICK

HUNSPELL_LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell
HUNSPELL_CMAKE_BOOL=	WANT_HUNSPELL

OSG_LIB_DEPENDS=	libosg.so:graphics/osg
OSG_CMAKE_BOOL_OFF=	WANT_NOOSG

PDF_LIB_DEPENDS=	libpodofo.so:graphics/podofo
PDF_CMAKE_BOOL=	WITH_PODOFO

post-install:
		${LN} -sf ../scribus/icons/1_5_1/scribus.png \
			${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
