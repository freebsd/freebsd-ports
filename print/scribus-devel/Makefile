# Ports collection makefile for:	scribus
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	scribus
PORTVERSION=	1.3.9
CATEGORIES=	print editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/${PORTVERSION} \
		http://www.scribus.net/downloads/${PORTVERSION}/
PKGNAMESUFFIX=	-devel

MAINTAINER=	coder@tuxfamily.org
COMMENT=	A comprehensive desktop publishing program

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		lcms.1:${PORTSDIR}/graphics/lcms \
		png.6:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		cups.2:${PORTSDIR}/print/cups-base \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		podofo.0:${PORTSDIR}/graphics/podofo \
		boost_thread.4:${PORTSDIR}/devel/boost-libs \
		aspell.16:${PORTSDIR}/textproc/aspell \
		cairo.2:${PORTSDIR}/graphics/cairo \
		execinfo:${PORTSDIR}/devel/libexecinfo
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging \
		update-mime-database:${PORTSDIR}/misc/shared-mime-info

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui linguist_build moc_build qmake_build rcc_build uic_build xml network
USE_GNOME=	desktopfileutils gnometarget libartlgpl2 libxml2 pkgconfig
USE_GHOSTSCRIPT_RUN=	yes
USE_PYTHON=	yes
USE_CMAKE=	yes
CMAKE_USE_PTHREAD=	yes
MAKE_JOBS_SAFE=	yes

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

MAN1=		scribus.1
MANLANG=	"" pl de
MANCOMPRESSED=	no

post-install:
	${LN} ${DATADIR}/icons/scribus.png ${PREFIX}/share/pixmaps/
	-update-desktop-database
	-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
