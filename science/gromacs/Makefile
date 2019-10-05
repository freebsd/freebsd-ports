# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	gromacs
DISTVERSION=	2019.4
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.gromacs.org/pub/gromacs/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Compute molecular dynamics

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=	undefined reference to `__atomic_load' and `__atomic_compare_exchange'

BUILD_DEPENDS=	boost-libs>=1.44:devel/boost-libs
LIB_DEPENDS=	libhwloc.so:devel/hwloc

USES=		cmake compiler:c++11-lang fortran gnome perl5 pkgconfig shebangfix xorg
SHEBANG_FILES=	admin/*.sh scripts/*.pl scripts/*.sh src/gromacs/selection/*.sh
bash_CMD=	${SH}
USE_GNOME=	libxml2
CMAKE_OFF=	GMX_USE_RDTSCP \
		USE_PYTHON_SCRIPTS
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		ATLAS FLOAT OPENCL OPENMP SIMD X11
OPTIONS_SINGLE=		MP
OPTIONS_SINGLE_MP=	NOMP MPICH OPENMPI THREAD_MPI
OPTIONS_DEFAULT=	FLOAT OPENMP THREAD_MPI X11
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

OPENCL_CMAKE_BOOL=	GMX_USE_OPENCL GMX_GPU
OPENCL_LIB_DEPENDS=	libOpenCL.so:devel/ocl-icd

OPENMP_USES=		compiler:openmp
OPENMP_CMAKE_ON=	-DGMX_CXX11:BOOL=OFF
OPENMP_CMAKE_OFF=	-DGMX_OPENMP:BOOL=OFF
OPENMP_LIB_DEPENDS=	libomp.so:devel/openmp

SIMD_CMAKE_OFF=		-DGMX_SIMD:STRING="None"

X11_USE=		XORG=ice,sm,xext,x11
X11_CMAKE_BOOL=		GMX_X11

MP_DESC=		Multiprocessing

NOMP_DESC=		No multiprocessing support
NOMP_PLIST_SUB=		SUFFIX_MPI=""

MPICH_DESC=		Parallel processing support via MPICH
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

post-patch:
	@${FIND} ${WRKSRC} -name "CMakeLists.txt" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|share/man|man| ; \
		 /pkgconfig/s|LIB_INSTALL_DIR}|CMAKE_INSTALL_PREFIX}/libdata|'
	@${FIND} ${WRKSRC} -name "GMXRC.*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|LDLIB/pkgconfig|LDLIB/../libdata/pkgconfig| ; \
		 s|LDLIB}/pkgconfig|LDLIB}/../libdata/pkgconfig|'
	@${REINPLACE_CMD} -e '/CMAKE_REQUIRED_LIBRARIES/d' \
		${WRKSRC}/cmake/gmxTestdlopen.cmake

.include <bsd.port.mk>
