# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	scribus
PORTVERSION=	1.5.5
PORTREVISION=	13
CATEGORIES=	print editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}${PKGNAMESUFFIX}/${PORTVERSION}/ \
		http://www.scribus.net/downloads/${PORTVERSION}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Comprehensive desktop publishing program (development version)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

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
		libicuuc.so:devel/icu

USES=		cmake compiler:c++11-lang desktop-file-utils dos2unix gnome \
		jpeg pkgconfig python:2.7 qt:5 shared-mime-info ssl tar:xz
USE_QT=		buildtools_build core declarative gui linguisttools_build \
		network opengl printsupport qmake_build widgets xml
USE_GNOME=	libxml2
INSTALLS_ICONS=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DWANT_HUNSPELL=YES -Wno-ferror-limit -DCMAKE_COLOR_MAKEFILE:BOOL=ON

OPTIONS_DEFINE=	DOCS

post-install:
		${LN} -sf ../share/icons/1_5_1/scribus.png \
			${STAGEDIR}${PREFIX}/share/pixmaps/
		${MKDIR} ${STAGEDIR}${PREFIX}/man/de/man1 \
			${STAGEDIR}${PREFIX}/man/pl/man1
		${MV} ${STAGEDIR}${PREFIX}/share/man/de/man1/scribus.1 \
			${STAGEDIR}${PREFIX}/man/de/man1/
		${MV} ${STAGEDIR}${PREFIX}/share/man/man1/scribus.1 \
			${STAGEDIR}${PREFIX}/man/man1/
		${MV} ${STAGEDIR}${PREFIX}/share/man/pl/man1/scribus.1 \
			${STAGEDIR}${PREFIX}/man/pl/man1/

.include <bsd.port.mk>
