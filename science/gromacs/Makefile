# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	gromacs
PORTVERSION=	5.0.6
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.gromacs.org/pub/gromacs/ \
		http://www.skysmurf.nl/comp/FreeBSD/distfiles/

MAINTAINER=	freebsd@skysmurf.nl
COMMENT=	Compute molecular dynamics

LICENSE=	LGPL21

BUILD_DEPENDS=	boost-libs>=1.44:devel/boost-libs

USES=		cmake fortran perl5 pkgconfig shebangfix
SHEBANG_FILES=	admin/*.sh scripts/*.pl scripts/*.sh src/gromacs/selection/*.sh
bash_CMD=	${SH}
USE_GNOME=	libxml2
CMAKE_ARGS=	-DGMX_USE_RDTSCP:BOOL=OFF \
		-DUSE_PYTHON_SCRIPTS:BOOL=OFF
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		ATLAS FLOAT OPENMP SIMD X11
OPTIONS_RADIO=		MPI
OPTIONS_RADIO_MPI=	MPICH2 OPENMPI
OPTIONS_DEFAULT=	FLOAT OPENMP X11
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
MPICH2_LIB_DEPENDS=	libmpich.so:net/mpich2
MPICH2_CMAKE_ON=	-DMPI_C_COMPILER:FILEPATH="${LOCALBASE}/bin/mpicc"
OPENMP_USES=		compiler:openmp
OPENMP_CMAKE_ON=	-DGMX_CXX11:BOOL=OFF
OPENMP_CMAKE_OFF=	-DGMX_OPENMP:BOOL=OFF
OPENMPI_BUILD_DEPENDS=	openmpi>0:net/openmpi
OPENMPI_RUN_DEPENDS=	openmpi>0:net/openmpi
OPENMPI_CMAKE_ON=	-DMPI_C_COMPILER:FILEPATH="${LOCALBASE}/mpi/openmpi/bin/mpicc"
SIMD_CMAKE_OFF=		-DGMX_SIMD:STRING="None"
X11_USE=		XORG=xext,x11
X11_CMAKE_ON=		-DGMX_X11:BOOL=ON
X11_CMAKE_OFF=		-DGMX_X11:BOOL=OFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFLOAT}
PLIST_SUB+=	SUFFIX_D=""
.else
PLIST_SUB+=	SUFFIX_D="_d"
.endif

.if ${PORT_OPTIONS:MMPICH2} || ${PORT_OPTIONS:MOPENMPI}
CMAKE_ARGS+=	-DGMX_MPI:BOOL=ON
PLIST_SUB+=	SUFFIX_MPI="_mpi"
.else
CMAKE_ARGS+=	-DGMX_MPI:BOOL=OFF
PLIST_SUB+=	SUFFIX_MPI=""
.endif

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
