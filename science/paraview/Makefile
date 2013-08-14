# Created by: anholt@FreeBSD.ORG
# $FreeBSD$

PORTNAME=	paraview
PORTVERSION=	3.10.1
PORTREVISION=	1
CATEGORIES=	science graphics
MASTER_SITES=	http://www.paraview.org/files/v${VERMAJORMINOR}/
DISTNAME=	ParaView-${PORTVERSION}

MAINTAINER=	devel@stasyan.com
COMMENT=	Powerful scientific data visualization application

LIB_DEPENDS=	hdf5.7:${PORTSDIR}/science/hdf5-18 \
		png15:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		freetype.9:${PORTSDIR}/print/freetype2 \
		expat.6:${PORTSDIR}/textproc/expat2

USE_QT4=	qmake_build moc_build rcc_build uic_build \
		linguist_build assistant_run qt3support \
		dbus designer gui help-tools network script \
		sql svg xml webkit assistantclient
USE_GL=		yes
USE_XORG=	x11 xt
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USES=		cmake:outsource
USE_GCC=	any
#CONFLICTS=	vtk-5.*
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
		-DPARAVIEW_INSTALL_THIRD_PARTY_LIBRARIES="OFF" \
		-DPARAVIEW_ENABLE_PYTHON:BOOL="ON"
#		-DVTK_PYTHON_INCLUDE_PATH=${PYTHON_INCLUDEDIR} \
#		-DPYTHON_INCLUDE_PATH:FILEPATH=${PYTHON_INCLUDEDIR} \
#		-DVTK_WRAP_PYTHON:BOOL=ON \
#		-DPARAVIEW_ENABLE_PYTHON:BOOL=ON
#		-DVTK_PYTHON_SETUP_ARGS:STRING='--prefix="${PREFIX}"' \

OPTIONS_DEFINE=	OSMESA GL2PS DOCS
OSMESA_DESC=	Use Mesa for off-screen rendering
GL2PS_DESC=	Install support conversion OpenGL to PostScript
#		VTKMPEG2	"Install patented MPEG2 encoder module" Off \

VERMAJORMINOR=	${PORTVERSION:R}

.include <bsd.port.options.mk>

# Simple solution to avoid lots of patching to support NOPORTDOCS
.if ${PORT_OPTIONS:MDOCS}
CMAKE_ARGS+=	-DPV_INSTALL_DOC_DIR=${DOCSDIR}
.else
CMAKE_ARGS+=	-DPV_INSTALL_DOC_DIR=${WRKDIR}
.endif

.if ${PORT_OPTIONS:MOSMESA}
LIB_DEPENDS+=	OSMesa32.7:${PORTSDIR}/graphics/libosmesa
CMAKE_ARGS+=	-DVTK_OPENGL_HAS_OSMESA:BOOL=ON \
		-DOSMESA_INCLUDE_DIR:PATH=${LOCALBASE}/include/Mesa \
		-DOSMESA_LIBRARY:FILEPATH=${LOCALBASE}/lib/libOSMesa32.so
.endif

.if ${PORT_OPTIONS:MGL2PS}
LIB_DEPENDS+=	gl2ps.1:${PORTSDIR}/print/gl2ps
CMAKE_ARGS+=	-DVTK_USE_GL2PS:BOOL=ON
PLIST_SUB+=	GL2PS=""
.else
PLIST_SUB+=	GL2PS="@comment "
.endif


PLIST_SUB+=	VERMAJORMINOR=${VERMAJORMINOR}
CMAKE2INST=	ParaViewConfig.cmake \
		cmake_install.cmake
LIB_INSTDIR=	${PREFIX}/lib/${PORTNAME}-${VERMAJORMINOR}

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
		${PREFIX}/lib/${PORTNAME}-${VERMAJORMINOR}

.include <bsd.port.mk>
