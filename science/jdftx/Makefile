# $FreeBSD$

PORTNAME=	jdftx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.2-73
DISTVERSIONSUFFIX=	-g73b17437
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software for joint density functional theory in chemistry

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libblas.so:math/blas \
		libcblas.so:math/cblas \
		libfftw3.so:math/fftw3 \
		libgsl.so:math/gsl \
		liblapack.so:math/lapack
TEST_DEPENDS=	bash:shells/bash

USES=		cmake:outsource fortran localbase:ldflags shebangfix
SHEBANG_GLOB=	*.sh
USE_GITHUB=	yes
GH_ACCOUNT=	shankar1729
USE_LDCONFIG=	yes

TEST_TARGET=	test

WRKSRC_SUBDIR=	${PORTNAME}

CMAKE_ARGS=	-DLAPACK_LIBRARIES:STRING="-llapack -lblas"

OPTIONS_DEFINE=		MPI LIBXC HDF5 SCALAPACK
OPTIONS_DEFAULT=	MPI LIBXC

MPI_CMAKE_BOOL=		EnableMPI
MPI_LIB_DEPENDS=	libmpich.so:net/mpich2

LIBXC_DESC=		Use LibXC for additional exchange-correlation functionals
LIBXC_CMAKE_BOOL=	EnableLibXC
LIBXC_LIB_DEPENDS=	libxc.so:science/libxc

HDF5_CMAKE_BOOL=	EnableHDF5
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
HDF5_BROKEN=		use of undeclared identifier 'H5Pset_dxpl_mpio' # https://github.com/shankar1729/jdftx/issues/37

SCALAPACK_DESC=		Enable ScaLAPACK support
SCALAPACK_CMAKE_BOOL=	EnableScaLAPACK
SCALAPACK_LIB_DEPENDS=	libscalapack.so:math/scalapack

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/phonon ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/wannier ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/libjdftx.so ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${DATADIR}/pseudopotentials
.for pp in GBRV-2017  GBRV SG15-pulay SG15
	cd ${STAGEDIR}${DATADIR}/pseudopotentials && ${TAR} xzf ${WRKSRC}/pseudopotentials/${pp}.tgz
.endfor

.include <bsd.port.mk>
