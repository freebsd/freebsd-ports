# New ports collection makefile for:    paraview
# Date created:         		25 May, 2005
# Whom:					anholt@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	paraview
PORTVERSION=	2.4.4
PORTREVISION=	6
CATEGORIES=	science graphics
MASTER_SITES=	http://www.paraview.org/files/v2.4/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ParaView is a powerful scientific data visualization application

LIB_DEPENDS=	hdf5.0:${PORTSDIR}/science/hdf5 \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2 \
		expat.6:${PORTSDIR}/textproc/expat2

USE_GL=		yes
USE_XORG=	x11 xt
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_CMAKE=	yes
CMAKE_ARGS+=	-DPARAVIEW_USE_SYSTEM_HDF5=1 \
		-DBUILD_SHARED_LIBS="ON" \
		-DVTK_USE_SYSTEM_PNG="ON" \
		-DVTK_USE_SYSTEM_JPEG="ON" \
		-DVTK_USE_SYSTEM_TIFF="ON" \
		-DVTK_USE_SYSTEM_ZLIB="ON" \
		-DVTK_USE_SYSTEM_FREETYPE="ON" \
		-DVTK_USE_SYSTEM_EXPAT="ON" \
		-DVTK_USE_X="ON" \
		-DVTK_HAVE_GETSOCKNAME_WITH_SOCKLEN_T=1

PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}/build
CMAKE_SOURCE_PATH=	..

PLIST_SUB+=	VERMAJORMINOR=2.4
CMAKE2INST=	Utilities/ParaViewConfig.cmake ParaViewConfig.cmake \
		ParaViewLibraryDepends.cmake cmake_install.cmake
LIB_INSTDIR=	${PREFIX}/lib/${PORTNAME}-${PORTVERSION:R}

post-extract:
	${MKDIR} ${WRKSRC}

pre-patch:
	@${REINPLACE_CMD} -e 's|vtkpng|png|g' \
		${WRKDIR}/paraview-${PORTVERSION}/GUI/Widgets/CMakeLists.txt

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' \
		${WRKDIR}/paraview-${PORTVERSION}/Utilities/TclTk/tk*/unix/configure

post-install:
.for c2f in ${CMAKE2INST}
	${SED} -e 's|${WRKSRC}|${LIB_INSTDIR}|g' \
		-e 's|${PATCH_WRKSRC}|${LIB_INSTDIR}|g' \
		${WRKSRC}/${c2f} > ${LIB_INSTDIR}/`${BASENAME} ${c2f}`
.endfor
	${INSTALL_DATA} ${PATCH_WRKSRC}/ParaViewUse.cmake \
		${PREFIX}/lib/${PORTNAME}-${PORTVERSION:R}

.include <bsd.port.mk>
