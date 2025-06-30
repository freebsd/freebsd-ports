PORTNAME=	paraview
DISTVERSION=	${PARAVIEW_VER}.3
PORTREVISION=	4
CATEGORIES=	science graphics
MASTER_SITES=	http://www.paraview.org/files/v${PARAVIEW_VER}/
DISTNAME=	ParaView-v${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Powerful scientific data visualization application
WWW=		https://www.paraview.org/

# See https://www.paraview.org/license/
LICENSE=	BSD3CLAUSE

#BROKEN_i386=	no matching member function for call to 'getArrayType'

BUILD_DEPENDS=	${PYNUMPY}	\
		cli11>0:devel/cli11	\
		utf8cpp>0:devel/utf8cpp	\
		fast_float>0:math/fast_float \
		nlohmann-json>0:devel/nlohmann-json	\
		vulkan-headers>0:graphics/vulkan-headers	\
		${LOCALBASE}/include/exprtk.hpp:math/exprtk	\
		${PYTHON_SITELIBDIR}/matplotlib/pyplot.py:math/py-matplotlib@${PY_FLAVOR}
LIB_DEPENDS=	libhdf5.so:science/hdf5 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libfreetype.so:print/freetype2 \
		libexpat.so:textproc/expat2 \
		libjbig.so:graphics/jbigkit \
		liborc-0.4.so:devel/orc \
		libpcre.so:devel/pcre \
		libicuuc.so:devel/icu \
		libffi.so:devel/libffi \
		libtbb.so:devel/onetbb \
		libogg.so:audio/libogg \
		libgl2ps.so:print/gl2ps \
		libOT.so:math/openturns \
		libgdal.so:graphics/gdal \
		libgeos.so:graphics/geos \
		libhpdf.so:print/libharu \
		libproj.so:graphics/proj \
		libpdalcpp.so:math/pdal \
		libdrm.so:graphics/libdrm \
		libcgns.so:science/cgnslib \
		liblz4.so:archivers/liblz4 \
		libverdict.so:math/verdict \
		libnetcdf.so:science/netcdf \
		libjsoncpp.so:devel/jsoncpp \
		libprotobuf.so:devel/protobuf \
		libpugixml.so:textproc/pugixml \
		libavutil.so:multimedia/ffmpeg \
		libcgraph.so:graphics/graphviz \
		libxkbcommon.so:x11/libxkbcommon \
		libtheora.so:multimedia/libtheora \
		libgeotiff.so:graphics/libgeotiff \
		libboost_thread.so:devel/boost-libs \
		libfontconfig.so:x11-fonts/fontconfig \
		libdouble-conversion.so:devel/double-conversion
RUN_DEPENDS=	${PYNUMPY}	\
		bash:shells/bash	\
		vtk${VTK_VER:R}>0:math/vtk${VTK_VER:R} \
		${PYTHON_SITELIBDIR}/matplotlib/pyplot.py:math/py-matplotlib@${PY_FLAVOR}

USES=		alias cmake compiler:c++17-lang desktop-file-utils eigen:3 fortran gl gnome	\
		jpeg localbase llvm:min=19 pkgconfig python qt:6 shebangfix sqlite tar:xz xorg
USE_GL=		glew opengl
USE_GNOME=	libxml2
USE_QT=		5compat base svg tools webengine
#buildtools:build core gui help network opengl qmake:build sql svg	\
#		webengine widgets x11extras glew xmlpatterns
USE_XORG=	ice sm x11 xau xcb xcursor xdamage xdmcp xext xfixes xorgproto xrender	\
		xxf86vm
USE_LDCONFIG=	yes

CFLAGS+=	-Wno-missing-template-arg-list-after-template-kw	\
		-I${WRKSRC}/Clients/ParaView/Documentation
CMAKE_ARGS+=	-DPARAVIEW_BUILD_SHARED_LIBS=ON \
		-DPARAVIEW_BUILD_WITH_EXTERNAL=ON \
		-DCMAKE_CXX_STANDARD=17 \
		-DPARAVIEW_USE_PYTHON:BOOL=ON \
		-DPARAVIEW_ENABLE_FFMPEG:BOOL=ON \
		-DPARAVIEW_ENABLE_LAS:BOOL=OFF \
		-DPARAVIEW_ENABLE_WEB:BOOL=ON \
		-DPARAVIEW_ENABLE_GDAL:BOOL=ON \
		-DPARAVIEW_ENABLE_PDAL:BOOL=ON \
		-DPARAVIEW_ENABLE_OPENTURNS:BOOL=ON \
		-DPARAVIEW_ENABLE_OPENTURNS:BOOL=ON \
		-DPARAVIEW_ENABLE_MOTIONFX:BOOL=ON \
		-DPARAVIEW_ENABLE_XDMF2:BOOL=ON \
		-DPARAVIEW_ENABLE_XDMF3:BOOL=ON \
		-DPARAVIEW_USE_QT:BOOL=ON \
		-DPARAVIEW_BUILD_DEVELOPER_DOCUMENTATION:BOOL=OFF \
		-DPARAVIEW_ENABLE_EMBEDDED_DOCUMENTATION:BOOL=OFF \
		-DVTK_FORBID_DOWNLOADS:BOOL=OFF \
		-DVTK_HAVE_GETSOCKNAME_WITH_SOCKLEN_T=1 \
		-DVTK_MODULE_USE_EXTERNAL_VTK_fmt:BOOL=OFF \
		-DVTK_MODULE_USE_EXTERNAL_VTK_ioss:BOOL=OFF \
		-DVTK_MODULE_USE_EXTERNAL_VTK_pegtl:BOOL=OFF \
		-DVTK_MODULE_USE_EXTERNAL_VTK_token:BOOL=OFF \
		-DExternalData_OBJECT_STORES="${WRKDIR}/VTK/ExternalData/MD5" \
		-DFREETYPE_INCLUDE_DIRS="${LOCALBASE}/include/freetype2"
# VTKm is BROKEN ATM: https://gitlab.kitware.com/paraview/paraview/-/issues/22876
CMAKE_ARGS+=	-DPARAVIEW_USE_VTKM:BOOL=OFF
.if !defined(MAINTAINER_MODE)
CMAKE_ARGS+=	-DVTK_FORBID_DOWNLOADS:BOOL=ON
.endif
MAKE_ENV=	XDG_CONFIG_HOME=${WRKDIR}
USE_CXXSTD=	c++17

SHEBANG_GLOB=	*.py
SHEBANG_FILES=	VTK/Examples/SearchScript.sh	\
		VTK/Utilities/Maintenance/*.sh	\
		Clients/CommandLineExecutables/paraview-config.in

OPTIONS_DEFINE=	DOCS EXAMPLES MPICH OSMESA
OPTIONS_SUB=	yes
OSMESA_DESC=	Use Mesa for off-screen rendering

# mpi4py and other programs must be compiled against the same MPI provider
MPICH_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpi4py-mpich>=0:net/py-mpi4py-mpich@${PY_FLAVOR}
MPICH_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpi4py-mpich>=0:net/py-mpi4py-mpich@${PY_FLAVOR}
MPICH_USES=		mpi # mpich is set by default, use mpi:openmpi if needed
MPICH_CMAKE_ON=		-DPARAVIEW_USE_MPI:BOOL=ON
MPICH_CMAKE_OFF=		-DPARAVIEW_USE_MPI:BOOL=OFF

OSMESA_LIB_DEPENDS=	libOSMesa.so:graphics/libosmesa
OSMESA_USES_OFF=	desktop-file-utils
OSMESA_CMAKE_BOOL=	VTK_OPENGL_HAS_OSMESA
OSMESA_CMAKE_ON=	-DVTK_USE_X:BOOL="OFF" \
			-DOSMESA_INCLUDE_DIR:PATH=${LOCALBASE}/include/Mesa \
			-DOSMESA_LIBRARY:FILEPATH=${LOCALBASE}/lib/libOSMesa.so
OSMESA_CMAKE_OFF=	-DVTK_USE_X:BOOL="ON"

EXAMPLES_CMAKE_BOOL=	PARAVIEW_ENABLE_EXAMPLES
PORTEXAMPLES=		*

#TEST_CMAKE_ON=		-DPARAVIEW_BUILD_TESTING=WANT	\
			-DPARAVIEW_BUILD_VTK_TESTING=WANT

# Error with ADIOS2
#LIB_DEPENDS+=	libadios2_c.so:misc/adios2
#CMAKE_ARGS+=	-DPARAVIEW_ENABLE_ADIOS2:BOOL=ON
# Missing GenericIO for CosmoTools
#CMAKE_ARGS+=	-DPARAVIEW_ENABLE_COSMOTOOLS:BOOL=ON
# Errors with VisItBridge / VisItLib
#CMAKE_ARGS+=	-DPARAVIEW_ENABLE_VISITBRIDGE:BOOL=ON
# MomentInvariants needs to download a module
#CMAKE_ARGS+=	-DPARAVIEW_ENABLE_MOMENTINVARIANTS:BOOL=ON
# No package for graphics/ospray
#LIB_DEPENDS+=	libospray.so:graphics/ospray
#CMAKE_ARGS+=	-DPARAVIEW_ENABLE_RAYTRACING

PLIST_SUB+=	VERMAJORMINOR=${PARAVIEW_VER}

VTK9_CONFLICTS=	vtk.py vtkmodules/__init__.py vtkmodules/all.py	\
		vtkmodules/gtk vtkmodules/numpy_interface	\
		vtkmodules/qt vtkmodules/test vtkmodules/tk	\
		vtkmodules/util vtkmodules/wx vtkmodules/generate_pyi.py	\
		vtkmodules/web/errors.py

pre-configure:
	${REINPLACE_CMD} -e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${PATCH_WRKSRC}/VTK/IO/Image/vtkPNGReader.cxx
	${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|'	\
		${PATCH_WRKSRC}/VTK/Utilities/Maintenance/vtk_site_history.py

post-install:
	# vtk9 is not a real run dependency, but it installs several common files
.for py in ${VTK9_CONFLICTS}
	${RM} -r ${STAGEDIR}${PYTHON_SITELIBDIR}/${py}
.endfor

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/Examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <./Makefile.version>
.include <../../math/vtk9/Makefile.version>
.include <bsd.port.mk>
