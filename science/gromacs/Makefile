PORTNAME=	gromacs
DISTVERSION=	2023.2
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	https://ftp.gromacs.org/pub/gromacs/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} # only for googletest

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Compute molecular dynamics
WWW=		https://www.gromacs.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=	undefined reference to `__atomic_load' and `__atomic_compare_exchange' #`

BUILD_DEPENDS=	boost-libs>=1.44:devel/boost-libs

USES=		cmake compiler:c++17-lang gnome pathfix perl5 pkgconfig \
		python:build shebangfix
USE_GCC=	yes # clang fails: https://gitlab.com/gromacs/gromacs/-/issues/4909
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	nodefault
GH_TUPLE=	google:googletest:v1.13.0:googletest

SHEBANG_FILES=	admin/*.sh scripts/*.pl scripts/*.sh src/gromacs/selection/*.sh
bash_CMD=	${SH}

CMAKE_OFF=	GMX_USE_RDTSCP \
		USE_PYTHON_SCRIPTS
CMAKE_ARGS=	-DPython_EXECUTABLE=${PYTHON_CMD} \
		-DPython3_EXECUTABLE=${PYTHON_CMD}

TEST_TARGET=	check

OPTIONS_DEFINE=		ATLAS FLOAT HWLOC LEGACY OPENMP SIMD
OPTIONS_SINGLE=		MP OPENCL
OPTIONS_SINGLE_MP=	NOMP MPICH OPENMPI THREAD_MPI
OPTIONS_SINGLE_OPENCL=	OPENCL_NONE OPENCL_ICD OPENCL_SYCL
OPTIONS_DEFAULT=	HWLOC LEGACY OPENCL_NONE OPENMP THREAD_MPI # FLOAT should not be a default because science/votca needs double precision. This is likely the same for many other uses.
OPTIONS_SUB=		yes

ATLAS_DESC=		Use ATLAS for BLAS and LAPACK
ATLAS_USES=		blaslapack:atlas
ATLAS_USES_OFF=		blaslapack
ATLAS_CMAKE_ON=		-DBLAS_LIBRARIES:FILEPATH="${LOCALBASE}/lib/libcblas.so;${LOCALBASE}/lib/libf77blas.so" \
			-DLAPACK_LIBRARIES:FILEPATH="${LOCALBASE}/lib/libalapack.so"
ATLAS_CMAKE_OFF=	-DBLAS_LIBRARIES:FILEPATH="${LOCALBASE}/lib/libblas.so" \
			-DLAPACK_LIBRARIES:FILEPATH="${LOCALBASE}/lib/liblapack.so"

FLOAT_DESC=		Use single instead of double precision
FLOAT_BUILD_DEPENDS=	fftw3>0:math/fftw3
FLOAT_LIB_DEPENDS=	libfftw3f.so:math/fftw3-float
FLOAT_LIB_DEPENDS_OFF=	libfftw3.so:math/fftw3
FLOAT_CMAKE_ON=		-DGMX_DOUBLE:BOOL=OFF
FLOAT_CMAKE_OFF=	-DGMX_DOUBLE:BOOL=ON
FLOAT_PLIST_SUB=	SUFFIX_D=""
FLOAT_PLIST_SUB_OFF=	SUFFIX_D="_d"

HWLOC_DESC=		Build with HWLOC2, portable hardware locality package
HWLOC_CMAKE_BOOL=	GMX_HWLOC
HWLOC_LIB_DEPENDS=	libhwloc.so:devel/hwloc2

LEGACY_DESC=		Install legacy API # expected by science/votca
LEGACY_CMAKE_BOOL=	GMX_INSTALL_LEGACY_API

OPENCL_NONE_DESC=	No OpenCL
OPENCL_NONE_CMAKE_ON=	-DGMX_GPU:STRING=OFF # one of: OFF, CUDA, OpenCL, SYCL

OPENCL_ICD_DESC=	OpenCL via Installable Client Driver
OPENCL_ICD_CMAKE_ON=	-DGMX_GPU:STRING=OpenCL -DGMX_GPU:STRING=OpenCL
OPENCL_ICD_LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd \
			libclFFT.so:math/clfft
OPENCL_ICD_IMPLIES=	FLOAT

OPENCL_SYCL_DESC=	OpenCL via the OpenSYCL implementation of SYCL
OPENCL_SYCL_USES=	localbase
OPENCL_SYCL_CMAKE_ON=	-DGMX_GPU:STRING=OpenCL -DGMX_GPU:STRING=SYCL -DGMX_SYCL_HIPSYCL=ON
OPENCL_SYCL_LIB_DEPENDS=	libhipSYCL-rt.so:lang/opensycl
OPENCL_SYCL_IMPLIES=	FLOAT
OPENCL_SYCL_BROKEN=	configure uses a wrong namespace to find CYCL, see https://gitlab.com/gromacs/gromacs/-/issues/4838

OPENMP_CMAKE_BOOL=	GMX_OPENMP

SIMD_CMAKE_OFF=		-DGMX_SIMD:STRING="None"
SIMD_CMAKE_ON=		-DGMX_SIMD:STRING="AUTO"

MP_DESC=		Multiprocessing

NOMP_DESC=		No multiprocessing support
NOMP_PLIST_SUB=		SUFFIX_MPI=""

MPICH_LIB_DEPENDS=	libmpich.so:net/mpich
MPICH_CMAKE_ON=		-DGMX_MPI:BOOL=ON \
			-DMPI_C_COMPILER:FILEPATH="${LOCALBASE}/bin/mpicc"
MPICH_PLIST_SUB=	SUFFIX_MPI="_mpi"

OPENMPI_BUILD_DEPENDS=	openmpi>0:net/openmpi
OPENMPI_RUN_DEPENDS=	openmpi>0:net/openmpi
OPENMPI_CMAKE_ON=	-DGMX_MPI:BOOL=ON \
			-DMPI_C_COMPILER:FILEPATH="${LOCALBASE}/mpi/openmpi/bin/mpicc"
OPENMPI_PLIST_SUB=	SUFFIX_MPI="_mpi"

THREAD_MPI_DESC=	Build a thread-MPI-based multithreaded version of GROMACS
THREAD_MPI_CMAKE_BOOL=	GMX_THREAD_MPI
THREAD_MPI_PLIST_SUB=	SUFFIX_MPI=""

post-extract: # replace outdated bundled googletest with a newer version to fix tests build, see https://gitlab.com/gromacs/gromacs/-/issues/4825
	@${RM} -r ${WRKSRC}/src/external/googletest
	@${RLN} ${WRKSRC_googletest} ${WRKSRC}/src/external/googletest

post-patch:
	@${FIND} ${WRKSRC} -name "GMXRC.*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|LDLIB/pkgconfig|LDLIB/../libdata/pkgconfig| ; \
		 s|LDLIB}/pkgconfig|LDLIB}/../libdata/pkgconfig|'
	@${REINPLACE_CMD} -e '/CMAKE_REQUIRED_LIBRARIES/d' \
		${WRKSRC}/cmake/gmxTestdlopen.cmake

# tests fail to compile, see https://gitlab.com/gromacs/gromacs/-/issues/4825

.include <bsd.port.mk>
