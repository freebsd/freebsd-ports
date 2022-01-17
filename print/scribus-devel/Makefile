# Created by: Piotr Kubaj <pkubaj@anongoth.pl>

PORTNAME=	scribus
PORTVERSION=	1.5.7
PORTREVISION=	11
CATEGORIES=	print editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}${PKGNAMESUFFIX}/${PORTVERSION}/ \
		http://www.scribus.net/downloads/${PORTVERSION}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Comprehensive desktop publishing program (development version)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libboost_thread.so:devel/boost-libs \
		libhunspell-1.7.so:textproc/hunspell \
		libcairo.so:graphics/cairo \
		librevenge-0.0.so:textproc/librevenge \
		libcups.so:print/cups \
		libwpg-0.3.so:graphics/libwpg03 \
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
		libpodofo.so:graphics/podofo \
		libharfbuzz.so:print/harfbuzz \
		libpng.so:graphics/png \
		libicuuc.so:devel/icu \
		libqxp-0.0.so:textproc/libqxp \
		libzmf-0.0.so:graphics/libzmf

USES=		cmake compiler:c++17-lang desktop-file-utils dos2unix gnome \
		jpeg pkgconfig python:3.6+ qt:5 shared-mime-info tar:xz
USE_QT=		buildtools_build core declarative gui linguisttools_build \
		network opengl printsupport qmake_build widgets xml
DOS2UNIX_REGEX=	.*\.(cpp|h|txt)
USE_GNOME=	libxml2

CMAKE_ARGS+=	-DWANT_HUNSPELL=YES \
		-DWANT_CPP17=YES \
		-DCMAKE_COLOR_MAKEFILE:BOOL=ON 

OPTIONS_DEFINE=	DOCS

post-install:
		${LN} -sf ../share/icons/1_5_1/scribus.png \
			${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
