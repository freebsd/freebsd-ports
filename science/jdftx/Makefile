# $FreeBSD$

PORTNAME=	jdftx
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software for joint density functional theory in chemistry

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libblas.so:math/blas \
		libcblas.so:math/cblas \
		libfftw3.so:math/fftw3 \
		libgsl.so:math/gsl \
		liblapack.so:math/lapack
RUN_DEPENDS=	bash:shells/bash
TEST_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang cmake fortran localbase:ldflags shebangfix
SHEBANG_GLOB=	*.sh
SHEBANG_FILES=	scripts/*
SHEBANG_LANG=	octave
USE_GITHUB=	yes
GH_ACCOUNT=	shankar1729
USE_LDCONFIG=	yes

TEST_TARGET=	test

WRKSRC_SUBDIR=	${PORTNAME}

CMAKE_ARGS=	-DLAPACK_LIBRARIES:STRING="-llapack -lblas"

OPTIONS_DEFINE=		MPI LIBXC HDF5 SCALAPACK OCTAVE
OPTIONS_DEFAULT=	MPI LIBXC

MPI_CMAKE_BOOL=		EnableMPI
MPI_LIB_DEPENDS=	libmpich.so:net/mpich

LIBXC_DESC=		Use LibXC for additional exchange-correlation functionals
LIBXC_CMAKE_BOOL=	EnableLibXC
LIBXC_LIB_DEPENDS=	libxc.so:science/libxc

HDF5_CMAKE_BOOL=	EnableHDF5
HDF5_LIB_DEPENDS=	libhdf5.so:science/hdf5
HDF5_BROKEN=		use of undeclared identifier 'H5Pset_dxpl_mpio' # https://github.com/shankar1729/jdftx/issues/37

SCALAPACK_DESC=		Enable ScaLAPACK support
SCALAPACK_CMAKE_BOOL=	EnableScaLAPACK
SCALAPACK_LIB_DEPENDS=	libscalapack.so:math/scalapack

OCTAVE_DESC=		With Octave support (only for one script: dryRunToPDB)
OCTAVE_RUN_DEPENDS=	octave:math/octave

.include <bsd.port.mk>
