PORTNAME=	elmerfem
DISTVERSIONPREFIX=	release-
DISTVERSION=	9.0
PORTREVISION=	22
CATEGORIES=	science

PATCH_SITES=	https://github.com/ElmerCSC/${PORTNAME}/commit/
PATCHFILES=	48e9430c.patch:-p1 # https://github.com/ElmerCSC/elmerfem/pull/294

MAINTAINER=	henrik@gulbra.net
COMMENT=	Multiphysical simulation software
WWW=		https://www.elmerfem.org/blog/

LICENSE=	GPLv2

BROKEN=		fails to build with vtk-9.5.0, see https://github.com/ElmerCSC/elmerfem/issues/677

LIB_DEPENDS=	libblas.so:math/blas \
		libhdf5.so:science/hdf5 \
		libmetis.so:math/metis \
		libmpich.so:net/mpich \
		libnetcdf.so:science/netcdf \
		libopenblas.so:math/openblas \
		libparpack.so:math/arpack-ng

USES=		cmake compiler:c++11-lang fortran
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	ElmerCSC
USE_LDCONFIG=	${PREFIX}/lib/elmersolver

CMAKE_ARGS=	-DELMER_FEM_REVISION:STRING=${GH_TAGNAME}

ALL_TARGET=	# empty

LDFLAGS+=	-L${LOCALBASE}/lib

PORTSCOUT=	limit:^release-[1-9]

CMAKE_ARGS+=	-DHAVE_INTTYPES_H=ON
.if !defined(MAINTAINER_MODE)
CMAKE_ARGS+=	-Wno-dev
.endif

OPTIONS_DEFINE=		GUI OCC
OPTIONS_DEFAULT=	GUI OCC
OPTIONS_SUB=		yes

GUI_DESC=		Build with ElmerGUI (Graphical User Interface)
OCC_DESC=		Use OpenCASCADE for CAD import in ElmerGUI

GUI_LIB_DEPENDS=	libqwt.so:x11-toolkits/qwt6@qt5
GUI_USES=		gl jpeg qt:5 xorg
GUI_USE=		gl=gl,glu xorg=ice,sm,x11,xext,xt qt=${_QT5_LIBS:ts,}
GUI_CMAKE_BOOL=		WITH_ELMERGUI WITH_PARAVIEW
GUI_CMAKE_ON=		-DQWT_LIBRARY=${QT_LIBDIR}/libqwt.so \
			-DQWT_INCLUDE_DIR=${QT_INCDIR}/qwt6 \
			-DDESIRED_QT_VERSION=5 \
			-DWITH_QT5:BOOL=TRUE \
			-DQT_FOUND:BOOL=TRUE

OCC_IMPLIES=		GUI
OCC_LIB_DEPENDS=	libexpat.so:textproc/expat2 \
			libfreetype.so:print/freetype2 \
			libpng.so:graphics/png \
			libpython${_PYVERSION}.so:lang/python${PYTHON_SUFFIX} \
			libtiff.so:graphics/tiff \
			libTKernel.so:cad/opencascade \
			libvtksys-${VTK_VER}.so:math/vtk${VTK_VER:R}
OCC_USES=		python
OCC_CMAKE_BOOL=		WITH_OCC
OCC_CMAKE_ON=		-DVTK_DIR=${LOCALBASE}/lib/cmake/vtk-9.0 \
			-DPython3_EXECUTABLE=${PYTHON_CMD}

_LIBSTAGEDIR=	${STAGEDIR}/${PREFIX}/lib/elmersolver
_PYVERSION=	${PYTHON_VER}${PYTHON_ABIVER}
_QT5_LIBS=	buildtools:build core declarative gui network opengl \
		printsupport qmake:build script sql svg widgets xml

.include <../../math/vtk9/Makefile.version>
.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS_${ARCH}=	-fPIC
CXXFLAGS_${ARCH}= -fPIC
FCFLAGS+=	-fPIC
FFLAGS+=	-fPIC
.endif

.if ${GCC_DEFAULT} >= 10
# workaround for Type mismatch between actual argument at (1) and actual argument at (2) (REAL(8)/COMPLEX(8)).
# in theory, this should set FCFLAGS, but the port does not conform
FFLAGS+=	-fallow-argument-mismatch
.endif

post-patch:
	@${RM} ${WRKSRC}/cmake/Modules/CMakeParseArguments.cmake
	@${RM} -r ${WRKSRC}/elmergrid/src/metis-5.1.0
	@${REINPLACE_CMD} -e 's,"metis.*/metis\.h",<metis.h>,' \
		${WRKSRC}/elmergrid/src/egparallel.c

pre-configure-OCC-on:
	${REINPLACE_CMD} -e "s|\$${VERSION}|`${PKG_QUERY} '%v' opencascade`|" \
		"${WRKSRC}/cmake/Modules/FindOCE.cmake"
	${REINPLACE_CMD} -e 's|$${INCLUDE}|${LOCALBASE}/include/OpenCASCADE|' \
		"${WRKSRC}/cmake/Modules/FindOCE.cmake"

post-configure:
	# workaround for https://github.com/ElmerCSC/elmerfem/issues/334
	@${REINPLACE_CMD} -e 's| -lMPI::MPI_C | |' ${BUILD_WRKSRC}/ElmerGUI/Application/CMakeFiles/ElmerGUI.dir/link.txt

post-install:
	${LN} -sf ElmerSolver_mpi ${STAGEDIR}${PREFIX}/bin/ElmerSolver
	${LN} -sf libelmersolver.so ${_LIBSTAGEDIR}/libelmersolver.so.0
	${LN} -sf libfhuti.so ${_LIBSTAGEDIR}/libfhuti.so.0
	${LN} -sf libmatc.so ${_LIBSTAGEDIR}/libmatc.so.0
	${LN} -sf libmpi_stubs.so ${_LIBSTAGEDIR}/libmpi_stubs.so.0
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/ElmerGrid

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.post.mk>
