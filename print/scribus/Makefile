# Created by: ijliao
# $FreeBSD$

PORTNAME=	scribus
PORTVERSION=	1.4.3
CATEGORIES=	print editors
MASTER_SITES=	SF \
		http://www.scribus.net/downloads/${PORTVERSION}/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Comprehensive desktop publishing program

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		liblcms.so:${PORTSDIR}/graphics/lcms \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libcups.so:${PORTSDIR}/print/cups-client \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libpodofo.so:${PORTSDIR}/graphics/podofo \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libhunspell-1.3.so:${PORTSDIR}/textproc/hunspell \
		libcairo.so:${PORTSDIR}/graphics/cairo \
		libhyphen.so:${PORTSDIR}/textproc/hyphen \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig
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

NO_STAGE=	yes
post-install:
	${LN} ${DATADIR}/icons/scribus.png ${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
