# New ports collection makefile for:    paraview
# Date created:         		25 May, 2005
# Whom:					anholt@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	paraview
PORTVERSION=	2.4.3
CATEGORIES=	science graphics
MASTER_SITES=	http://www.paraview.org/files/v2.4/

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	ParaView is a powerful scientific data visualization application

BUILD_DEPENDS=	cmake:${PORTSDIR}/devel/cmake
LIB_DEPENDS=	hdf5.0:${PORTSDIR}/science/hdf5 \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2 \
		expat.6:${PORTSDIR}/textproc/expat2

USE_GL=		yes
WRKSRC=		${WRKDIR}/${DISTNAME}-build
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
PLIST_SUB+=	VERMAJORMINOR=2.4
CMAKE2INST=	Utilities/ParaViewConfig.cmake ParaViewConfig.cmake \
		ParaViewLibraryDepends.cmake cmake_install.cmake
MAKE_ENV=	CC="${CC}" \
		CXX="${CXX}"
LIB_INSTDIR=	${PREFIX}/lib/${PORTNAME}-${PORTVERSION:R}

BROKEN=		Does not build with new cmake

pre-patch:
	${REINPLACE_CMD} -e 's|vtkpng|png|g' \
		${WRKDIR}/paraview-${PORTVERSION}/GUI/Widgets/CMakeLists.txt

do-configure:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && \
	${LOCALBASE}/bin/cmake ../${DISTNAME} \
		-DCMAKE_INSTALL_PREFIX:PATH=${PREFIX} \
		-DCMAKE_C_FLAGS="${CFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include" \
		-DCMAKE_CXX_FLAGS="${CXXFLAGS} -I${X11BASE}/include -I${LOCALBASE}/include" \
		-DPARAVIEW_USE_SYSTEM_HDF5=1 \
		-DBUILD_SHARED_LIBS="ON" \
		-DVTK_USE_SYSTEM_PNG="ON" \
		-DVTK_USE_SYSTEM_JPEG="ON" \
		-DVTK_USE_SYSTEM_TIFF="ON" \
		-DVTK_USE_SYSTEM_ZLIB="ON" \
		-DVTK_USE_SYSTEM_FREETYPE="ON" \
		-DVTK_USE_SYSTEM_EXPAT="ON" \
		-DVTK_HAVE_GETSOCKNAME_WITH_SOCKLEN_T=1

post-install:
.for c2f in ${CMAKE2INST}
	${SED} -e 's|${PATCH_WRKSRC}|${LIB_INSTDIR}|g' \
		-e 's|${WRKSRC}|${LIB_INSTDIR}|g' \
		${WRKSRC}/${c2f} > ${LIB_INSTDIR}/`${BASENAME} ${c2f}`
.endfor
	${INSTALL_DATA} ${PATCH_WRKSRC}/ParaViewUse.cmake \
		${PREFIX}/lib/${PORTNAME}-${PORTVERSION:R}

.include <bsd.port.mk>
