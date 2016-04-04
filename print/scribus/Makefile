# Created by: ijliao
# $FreeBSD$

PORTNAME=	scribus
PORTVERSION=	1.4.6
PORTREVISION=	2
CATEGORIES=	print editors
MASTER_SITES=	SF \
		http://www.scribus.net/downloads/${PORTVERSION}/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Comprehensive desktop publishing program

LIB_DEPENDS=	liblcms.so:graphics/lcms \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libcups.so:print/cups \
		libfreetype.so:print/freetype2 \
		libpodofo.so:graphics/podofo \
		libboost_thread.so:devel/boost-libs \
		libhunspell-1.3.so:textproc/hunspell \
		libcairo.so:graphics/cairo \
		libhyphen.so:textproc/hyphen \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL/_imaging.so:graphics/py-pillow

USE_QT4=	gui linguist_build moc_build qmake_build rcc_build uic_build xml network
USE_GNOME=	libartlgpl2 libxml2
USES=		cmake:outsource desktop-file-utils execinfo ghostscript:run jpeg \
		pkgconfig python shared-mime-info tar:xz
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DWANT_HUNSPELL=YES -Wno-ferror-limit

OPTIONS_DEFINE=	DOCS

post-install:
	${LN} -sf ${DATADIR}/icons/scribus.png ${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
