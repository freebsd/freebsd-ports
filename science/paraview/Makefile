# New ports collection makefile for:    paraview
# Date created:         		25 May, 2005
# Whom:					anholt@FreeBSD.ORG
#
# $FreeBSD$
#

PORTNAME=	paraview
PORTVERSION=	3.8.0
CATEGORIES=	science graphics
MASTER_SITES=	http://www.paraview.org/files/v3.8/
DISTNAME=	ParaView-${PORTVERSION}

MAINTAINER=	devel@stasyan.com
COMMENT=	ParaView is a powerful scientific data visualization application

LIB_DEPENDS=	hdf5.0:${PORTSDIR}/science/hdf5 \
		png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2 \
		expat.6:${PORTSDIR}/textproc/expat2

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build \
		linguist_build assistant_run qt3support \
		dbus designer gui help-tools network script \
		sql svg xml webkit assistantclient
USE_GL=		yes
USE_XORG=	x11 xt
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_CMAKE=	yes
CONFLICTS=	vtk-5.*
CMAKE_ARGS+=	-DPARAVIEW_USE_SYSTEM_HDF5=1 \
		-DBUILD_SHARED_LIBS="ON" \
		-DVTK_USE_SYSTEM_PNG="ON" \
		-DVTK_USE_SYSTEM_JPEG="ON" \
		-DVTK_USE_SYSTEM_TIFF="ON" \
		-DVTK_USE_SYSTEM_ZLIB="ON" \
		-DVTK_USE_SYSTEM_FREETYPE="ON" \
		-DVTK_USE_SYSTEM_EXPAT="ON" \
		-DVTK_USE_X="ON" \
		-DVTK_HAVE_GETSOCKNAME_WITH_SOCKLEN_T=1 \
		-DQT_ASSISTANT_EXECUTABLE="${LOCALBASE}/bin/assistant-qt4" \
		-DVTK_INSTALL_QT_PLUGIN_DIR="${PREFIX}/${QT_PLUGINDIR_REL}/designer" \
		-DPARAVIEW_INSTALL_DEVELOPMENT="ON" \
		-DPV_INSTALL_DOC_DIR=${DOCSDIR}
#		-DVTK_PYTHON_INCLUDE_PATH=${PYTHON_INCLUDEDIR} \
#		-DPYTHON_INCLUDE_PATH:FILEPATH=${PYTHON_INCLUDEDIR} \
#		-DVTK_WRAP_PYTHON:BOOL=ON \
#		-DPARAVIEW_ENABLE_PYTHON:BOOL=ON
#		-DVTK_PYTHON_SETUP_ARGS:STRING='--prefix="${PREFIX}"' \

OPTIONS=	MANGLEDMESA	"Use off-screen (Mangled) Mesa" Off
#		VTKMPEG2	"Install patented MPEG2 encoder module" Off \
#		GL2PS           "Install support conversion OpenGL to PostScript" On

.if defined(WITH_MANGLEDMESA)
LIB_DEPENDS+=	MesaGL.14:${PORTSDIR}/graphics/mesagl
CMAKE_ARGS+=	-DVTK_OPENGL_HAS_OSMESA:BOOL=OFF	\
		-DVTK_USE_MANGLED_MESA:BOOL=ON \
		-DMANGLED_MESA_INCLUDE_DIR:PATH=${LOCALBASE}/include/Mesa \
		-DMANGLED_MESA_LIBRARY:FILEPATH=${LOCALBASE}/lib/libMesaGL.so \
		-DMANGLED_OSMESA_INCLUDE_DIR:PATH=${LOCALBASE}/include/Mesa \
		-DMANGLED_OSMESA_LIBRARY:FILEPATH=${LOCALBASE}/lib/libMesaOSMesa.so
.else
LIB_DEPENDS+=	OSMesa.7:${PORTSDIR}/graphics/libosmesa
CMAKE_ARGS+=	-DVTK_OPENGL_HAS_OSMESA:BOOL=ON \
		-DOSMESA_LIBRARY:FILEPATH=${LOCALBASE}/lib/libOSMesa.so
.endif

MAKE_JOBS_SAFE=	yes
CMAKE_OUTSOURCE=	yes

PLIST_SUB+=	VERMAJORMINOR=3.8
CMAKE2INST=	ParaViewConfig.cmake \
		ParaViewLibraryDepends.cmake cmake_install.cmake
LIB_INSTDIR=	${PREFIX}/lib/${PORTNAME}-${PORTVERSION:R}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not build on 6.x
.endif

post-patch:
	${REINPLACE_CMD} -e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${PATCH_WRKSRC}/VTK/IO/vtkPNGReader.cxx

post-install:
.for c2f in ${CMAKE2INST}
	${SED} -e 's|${BUILD_WRKSRC}|${LIB_INSTDIR}|g' \
		-e 's|${PATCH_WRKSRC}|${LIB_INSTDIR}|g' \
		${BUILD_WRKSRC}/${c2f} > ${LIB_INSTDIR}/`${BASENAME} ${c2f}`
.endfor
	${INSTALL_DATA} ${PATCH_WRKSRC}/ParaViewUse.cmake \
		${PREFIX}/lib/${PORTNAME}-${PORTVERSION:R}

.include <bsd.port.post.mk>
