# Created by: ijliao
# $FreeBSD$

PORTNAME=	scribus
PORTVERSION=	1.4.3
CATEGORIES=	print editors
MASTER_SITES=	SF \
		http://www.scribus.net/downloads/${PORTVERSION}/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Comprehensive desktop publishing program

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		lcms:${PORTSDIR}/graphics/lcms \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		cups:${PORTSDIR}/print/cups-client \
		freetype:${PORTSDIR}/print/freetype2 \
		podofo:${PORTSDIR}/graphics/podofo \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		hunspell:${PORTSDIR}/textproc/hunspell \
		cairo:${PORTSDIR}/graphics/cairo \
		hyphen:${PORTSDIR}/textproc/hyphen \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging

USE_XZ=		yes
USE_QT4=	gui linguist_build moc_build qmake_build rcc_build uic_build xml network
USE_GNOME=	libartlgpl2 libxml2
USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=	yes
USES=		cmake desktop-file-utils pkgconfig shared-mime-info
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DWANT_HUNSPELL=YES -Wno-ferror-limit

MAN1=		scribus.1
MANLANG=	"" pl de
MANCOMPRESSED=	no

post-install:
	${LN} ${DATADIR}/icons/scribus.png ${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
