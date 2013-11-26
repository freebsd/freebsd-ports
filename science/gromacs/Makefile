# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	gromacs
PORTVERSION=	4.6.4
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.gromacs.org/pub/gromacs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compute molecular dynamics

LICENSE=	LGPL21

OPTIONS_DEFINE=	ATLAS FLOAT GSL SIMD X11
OPTIONS_DEFAULT=	FLOAT GSL X11
OPTIONS_RADIO=	MPI
OPTIONS_RADIO_MPI=	MPICH OMPI

ATLAS_DESC=	Use ATLAS for BLAS and LAPACK
FLOAT_DESC=	Use single instead of double precision
GSL_DESC=	Extra analysis using math/gsl
MPICH_DESC=	MPI support using net/mpich2
OMPI_DESC=	MPI support using net/openmpi

USES=		cmake pkgconfig shebangfix perl5
SHEBANG_FILES=	admin/*.pl scripts/*.pl scripts/*.sh src/gmxlib/selection/*.sh
bash_CMD=	${SH}
USE_FORTRAN=	yes
CMAKE_ARGS=	-DBLAS_LIBRARIES:FILEPATH="${BLAS_LIBS}" \
		-DLAPACK_LIBRARIES:FILEPATH="${LAPACK_LIBS}"
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MATLAS}
LIB_DEPENDS+=	libalapack.so:${PORTSDIR}/math/atlas
BLAS_LIBS=	${LOCALBASE}/lib/libcblas.so;${LOCALBASE}/lib/libf77blas.so
LAPACK_LIBS=	${LOCALBASE}/lib/libalapack.so
.else
LIB_DEPENDS+=	libblas.so:${PORTSDIR}/math/blas \
		liblapack.so:${PORTSDIR}/math/lapack
BLAS_LIBS=	${LOCALBASE}/lib/libblas.so
LAPACK_LIBS=	${LOCALBASE}/lib/liblapack.so
.endif

.if ${PORT_OPTIONS:MFLOAT}
BUILD_DEPENDS+=	fftw3>0:${PORTSDIR}/math/fftw3
LIB_DEPENDS+=	libfftw3f.so:${PORTSDIR}/math/fftw3-float
CMAKE_ARGS+=	-DGMX_DOUBLE:BOOL=OFF
PLIST_SUB+=	SUFFIX_D=""
.else
LIB_DEPENDS+=	libfftw3.so:${PORTSDIR}/math/fftw3
CMAKE_ARGS+=	-DGMX_DOUBLE:BOOL=ON
PLIST_SUB+=	SUFFIX_D="_d"
.endif

.if ${PORT_OPTIONS:MGSL}
LIB_DEPENDS+=	libgsl.so:${PORTSDIR}/math/gsl
CMAKE_ARGS+=	-DGMX_GSL:BOOL=ON
.else
CMAKE_ARGS+=	-DGMX_GSL:BOOL=OFF
.endif

.if empty(PORT_OPTIONS:MSIMD)
CMAKE_ARGS+=	-DGMX_CPU_ACCELERATION:STRING="None"
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	xext x11
CMAKE_ARGS+=	-DGMX_X11:BOOL=ON
PLIST_SUB+=	X11=""
.else
CMAKE_ARGS+=	-DGMX_X11:BOOL=OFF
PLIST_SUB+=	X11="@comment "
.endif

.if ${PORT_OPTIONS:MMPICH} || ${PORT_OPTIONS:MOMPI}
CMAKE_ARGS+=	-DGMX_MPI:BOOL=ON \
		-DMPI_C_COMPILER:FILEPATH="${MPICC}"
PLIST_SUB+=	SUFFIX_MPI="_mpi"
.else
CMAKE_ARGS+=	-DGMX_MPI:BOOL=OFF
PLIST_SUB+=	SUFFIX_MPI=""
.endif

.if ${PORT_OPTIONS:MMPICH}
BUILD_DEPENDS+=	${LOCALBASE}/bin/mpicc:${PORTSDIR}/net/mpich2
RUN_DEPENDS+=	${LOCALBASE}/bin/mpicc:${PORTSDIR}/net/mpich2
MPICC=		${LOCALBASE}/bin/mpicc
.endif

.if ${PORT_OPTIONS:MOMPI}
BUILD_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpicc:${PORTSDIR}/net/openmpi
RUN_DEPENDS+=	${LOCALBASE}/mpi/openmpi/bin/mpicc:${PORTSDIR}/net/openmpi
MPICC=		${LOCALBASE}/mpi/openmpi/bin/mpicc
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "CMakeLists.txt" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|share/man|man| ; \
		 s|-lpthread|-pthread| ; \
		 /pkgconfig/s|LIB_INSTALL_DIR}|CMAKE_INSTALL_PREFIX}/libdata|'
	@${FIND} ${WRKSRC} -name "GMXRC.*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|LDLIB/pkgconfig|LDLIB/../libdata/pkgconfig| ; \
		 s|LDLIB}/pkgconfig|LDLIB}/../libdata/pkgconfig|'

.include <bsd.port.mk>
