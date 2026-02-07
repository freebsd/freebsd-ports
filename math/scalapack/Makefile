PORTNAME=	scalapack
PORTVERSION=	2.2.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	math

MAINTAINER=	fortran@FreeBSD.org
COMMENT=	ScaLAPACK Scalable LAPACK library
WWW=		https://www.netlib.org/scalapack/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS=	elmer-mathlibs-1*

USE_GITHUB=	yes
GH_ACCOUNT=	Reference-ScaLAPACK

USES=		cmake fortran pathfix

USE_LDCONFIG=	yes
CMAKE_ARGS=	-DBUILD_STATIC_LIBS:BOOL=ON

ARCH2FIX=	PBLAS/SRC PBLAS/SRC/PBBLAS PBLAS/SRC/PTOOLS PBLAS/SRC/PTZBLAS \
		REDIST/SRC SRC TOOLS TOOLS/LAPACK

DATADIR=	${PREFIX}/share/${PORTNAME:tu}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME:tu}
SUB_FILES=	pkg-message
PLIST_SUB=	SVERSION=${SVERSION} PORTVERSION=2.2.1 VER=${PORTVERSION:R}

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_RADIO=		LA MPI
OPTIONS_RADIO_LA=	ATLAS BLAS
LA_DESC=		Linear Algebra library support
BLAS_DESC=		LAPACK blass implementation
OPTIONS_RADIO_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	BLAS EXAMPLES MPICH

ATLAS_USES=	blaslapack:atlas
BLAS_USES=	blaslapack:openblas

MPICH_USES=	mpi:mpich
MPICH_CMAKE_ON=	-DMPI_BASE_DIR=${LOCALBASE}
OPENMPI_USES=	mpi:openmpi
OPENMPI_CMAKE_ON=-DMPI_BASE_DIR=${LOCALBASE}/mpi/openmpi

.include <bsd.port.pre.mk>

BLAS=		${BLASLIB}
LAPACK=		${LAPACKLIB}

.if ${ARCH} == "amd64"
FPIC=	-fPIC
.else
FPIC=	-fpic
.endif

CFLAGS+=	${FPIC} ${MPI_CFLAGS}
FFLAGS+=	${FPIC}
LDFLAGS+=	${MPI_LIBS}
SVERSION=	${PORTVERSION:R:R}

.if ${FORTRAN_DEFAULT} == gfortran && ${GCC_DEFAULT} >= 10
# workaround for Rank mismatch between actual argument at (1) and actual argument at (2) (scalar and rank-1)
FFLAGS+=	-fallow-argument-mismatch
.endif

# USES=fortran already forces FC to a supported fortran compiler;
# assume mpicc points to a compatible compiler and force that, too.
CC=	${MPICC}

post-build:
	${RM} -r ${WRKSRC}/CMakeFiles ${WRKSRC}/CMakeCache.txt
	(cd ${WRKSRC} &&	\
	${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS:C|BUILD_STATIC_LIBS|BUILD_SHARED_LIBS|} ${CMAKE_SOURCE_PATH})
	(cd ${WRKSRC} && ${DO_MAKE_BUILD} ${ALL_TARGET})

post-install:
	${INSTALL_LIB} ${WRKSRC}/lib/libscalapack.so ${STAGEDIR}${PREFIX}/lib/libscalapack.so.${PORTVERSION:R}
	${LN} -sf libscalapack.so.${PORTVERSION:R} ${STAGEDIR}${PREFIX}/lib/libscalapack.so
	${LN} -sf libscalapack.so.${PORTVERSION:R} ${STAGEDIR}${PREFIX}/lib/libscalapack.so.${SVERSION}
	${MKDIR} ${STAGEDIR}${PREFIX}/share/SCALAPACK/TESTING
	(cd ${BUILD_WRKSRC}/TESTING/ ;\
	${INSTALL_PROGRAM} x* ${STAGEDIR}${PREFIX}/share/SCALAPACK/TESTING ;\
	${INSTALL_DATA} *.dat ${STAGEDIR}${PREFIX}/share/SCALAPACK/TESTING)
	${INSTALL_DATA} ${FILESDIR}/scalapack.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/PBLAS/SRC/*.h ${STAGEDIR}${PREFIX}/include

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/SCALAPACK
	${INSTALL_DATA} ${FILESDIR}/Makefile    ${STAGEDIR}${PREFIX}/share/examples/SCALAPACK
	${INSTALL_DATA} ${FILESDIR}/example1.cc ${STAGEDIR}${PREFIX}/share/examples/SCALAPACK
	${INSTALL_DATA} ${FILESDIR}/example1.f  ${STAGEDIR}${PREFIX}/share/examples/SCALAPACK

do-test:
	(cd ${BUILD_WRKSRC}/TESTING && ${MAKE_CMD} test)

.include <bsd.port.post.mk>
