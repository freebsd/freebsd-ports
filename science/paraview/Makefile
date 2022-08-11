PORTNAME=	paraview
DISTVERSION=	5.10.1
PORTREVISION=	2
CATEGORIES=	science graphics
MASTER_SITES=	http://www.paraview.org/files/v${VERMAJORMINOR}/
DISTNAME=	ParaView-v${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Powerful scientific data visualization application

LICENSE=	ParaView_License_1.2
LICENSE_NAME=	ParaView_License
LICENSE_FILE=	${WRKSRC}/License_v1.2.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BROKEN_aarch64=	fails to link: undefined reference to `sbrk'

BUILD_DEPENDS=	${PYNUMPY}	\
		cli11>0:devel/cli11	\
		utf8cpp>0:devel/utf8cpp	\
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
		liblas.so:devel/liblas \
		libtbb.so:devel/onetbb \
		libogg.so:audio/libogg \
		libgl2ps.so:print/gl2ps \
		libOT.so:math/openturns \
		libgdal.so:graphics/gdal \
		libgeos.so:graphics/geos \
		libhpdf.so:print/libharu \
		libpdal_base.so:math/pdal \
		libdrm.so:graphics/libdrm \
		libcgns.so:science/cgnslib \
		liblz4.so:archivers/liblz4 \
		libnetcdf.so:science/netcdf \
		libjsoncpp.so:devel/jsoncpp \
		libprotobuf.so:devel/protobuf \
		libpugixml.so:textproc/pugixml \
		libavutil.so:multimedia/ffmpeg \
		libcgraph.so:graphics/graphviz \
		libtheora.so:multimedia/libtheora \
		libgeotiff.so:graphics/libgeotiff \
		libboost_thread.so:devel/boost-libs \
		libfontconfig.so:x11-fonts/fontconfig \
		libdouble-conversion.so:devel/double-conversion
RUN_DEPENDS=	${PYNUMPY}	\
		bash:shells/bash	\
		vtk9>0:math/vtk9	\
		${PYTHON_SITELIBDIR}/matplotlib/pyplot.py:math/py-matplotlib@${PY_FLAVOR}

USES=		alias cmake compiler:c11 eigen:3 fortran gl gnome jpeg localbase	\
		pkgconfig python qt:5 shebangfix tar:xz xorg
USE_GL=		gl glew glu glut
USE_GNOME=	libxml2
USE_QT=		buildtools_build core gui help network opengl qmake_build sql svg	\
		widgets x11extras xmlpatterns
USE_XORG=	ice sm x11 xau xcb xcursor xdamage xdmcp xext xfixes xorgproto xrender	\
		xxf86vm
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DPARAVIEW_BUILD_SHARED_LIBS=ON \
		-DPARAVIEW_BUILD_WITH_EXTERNAL=ON \
		-DVTK_HAVE_GETSOCKNAME_WITH_SOCKLEN_T=1 \
		-DPARAVIEW_USE_PYTHON:BOOL=ON \
		-DPARAVIEW_ENABLE_FFMPEG:BOOL=ON \
		-DPARAVIEW_ENABLE_LAS:BOOL=ON \
		-DPARAVIEW_ENABLE_WEB:BOOL=ON \
		-DPARAVIEW_ENABLE_GDAL:BOOL=ON \
		-DPARAVIEW_ENABLE_PDAL:BOOL=ON \
		-DPARAVIEW_ENABLE_OPENTURNS:BOOL=ON \
		-DPARAVIEW_ENABLE_OPENTURNS:BOOL=ON \
		-DPARAVIEW_ENABLE_MOTIONFX:BOOL=ON \
		-DPARAVIEW_ENABLE_XDMF2:BOOL=ON \
		-DPARAVIEW_ENABLE_XDMF3:BOOL=ON \
		-DVTK_MODULE_USE_EXTERNAL_VTK_fmt:BOOL=OFF \
		-DVTK_MODULE_USE_EXTERNAL_VTK_ioss:BOOL=OFF \
		-DVTK_MODULE_USE_EXTERNAL_VTK_pegtl=OFF \
		-DVTK_MODULE_USE_EXTERNAL_ParaView_vtkcatalyst:BOOL=OFF \
		-DExternalData_OBJECT_STORES="${WRKDIR}/VTK/ExternalData/MD5" \
		-DFREETYPE_INCLUDE_DIRS="${LOCALBASE}/include/freetype2"
.if !defined(MAINTAINER_MODE)
CMAKE_ARGS+=	-DVTK_FORBID_DOWNLOADS:BOOL=ON
.endif
MAKE_ENV=	XDG_CONFIG_HOME=${WRKDIR}

SHEBANG_GLOB=	*.py
SHEBANG_FILES=	VTK/Examples/SearchScript.sh	\
		VTK/Utilities/Maintenance/*.sh	\
		Clients/CommandLineExecutables/paraview-config.in

VERMAJORMINOR=	${PORTVERSION:R}

OPTIONS_DEFINE=	DOCS EXAMPLES MPI OSMESA
OPTIONS_SUB=	yes
OSMESA_DESC=	Use Mesa for off-screen rendering

# mpi4py and other programs must be compiled against the same MPI provider
MPI_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpi4py>0:net/py-mpi4py@${PY_FLAVOR}
MPI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpi4py>0:net/py-mpi4py@${PY_FLAVOR}
MPI_USES=		mpi # mpich is set by default, use mpi:openmpi if needed
MPI_CMAKE_ON=		-DPARAVIEW_USE_MPI:BOOL=ON
MPI_CMAKE_OFF=		-DPARAVIEW_USE_MPI:BOOL=OFF

OSMESA_LIB_DEPENDS=	libOSMesa.so:graphics/libosmesa
OSMESA_USES_OFF=	desktop-file-utils
OSMESA_CMAKE_BOOL=	VTK_OPENGL_HAS_OSMESA
OSMESA_CMAKE_ON=	-DVTK_USE_X:BOOL="OFF" \
			-DOSMESA_INCLUDE_DIR:PATH=${LOCALBASE}/include/Mesa \
			-DOSMESA_LIBRARY:FILEPATH=${LOCALBASE}/lib/libOSMesa.so
OSMESA_CMAKE_OFF=	-DVTK_USE_X:BOOL="ON"

EXAMPLES_CMAKE_BOOL=	PARAVIEW_BUILD_EXAMPLES
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

PLIST_SUB+=	VERMAJORMINOR=${VERMAJORMINOR}

VTK9_CONFLICTS=	vtk.py vtkmodules/__init__.py vtkmodules/all.py	\
		vtkmodules/gtk vtkmodules/numpy_interface	\
		vtkmodules/qt vtkmodules/test vtkmodules/tk	\
		vtkmodules/util vtkmodules/wx

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

.include <bsd.port.mk>
