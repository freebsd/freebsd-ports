PORTNAME=	bagel
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2-132
PORTREVISION=	17
DISTVERSIONSUFFIX=	-g2955e4d1a
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Brilliantly Advanced General Electronic-structure Library
WWW=		https://nubakery.org/ \
		https://github.com/qsimulate-open/bagel

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_armv7=	error: static_assert failed "size_t is assumed to be the same size as unsigned long long"
BROKEN_i386=	error: static_assert failed "size_t is assumed to be the same size as unsigned long long"

LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs
TEST_DEPENDS=	cblas>0:math/cblas

USES=		autoreconf blaslapack:openblas compiler:c++11-lang fortran gmake libtool localbase python:build
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	qsimulate-open

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datarootdir=${DATADIR}

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=			MPI LIBXC SCALAPACK SMITH # SLATER (needs a separate lib)
OPTIONS_DEFAULT=		MPI LIBXC SCALAPACK SMITH

MPI_CONFIGURE_ON=		--with-mpi=openmpi
MPI_CONFIGURE_OFF=		--with-mpi=no
MPI_LIB_DEPENDS=		libmpicxx.so:net/mpich # openmpi option erroneously links to mpich (due to a name clash)

LIBXC_DESC=			Build DFT with libxc
LIBXC_CONFIGURE_WITH=		libxc
LIBXC_LIB_DEPENDS=		libxc.so:science/libxc

SCALAPACK_DESC=			Use ScaLapack library for parallelized linear algebra
SCALAPACK_CONFIGURE_ENABLE=	scalapack
SCALAPACK_VARS=			LDFLAGS+="-lscalapack"
SCALAPACK_VARS_OFF=		LDFLAGS+="${BLASLIB} ${LAPACKLIB}" # -llapack -lblas are a replacement of libscalapack
SCALAPACK_LIB_DEPENDS=		libscalapack.so:math/scalapack
SCALAPACK_IMPLIES=		MPI

SMITH_DESC=			Compile SMITH generated code
SMITH_CONFIGURE_ENABLE=		smith
SMITH_IMPLIES=			MPI

TEST_TARGET=			check
TEST_ARGS=			LDFLAGS+="-lcblas -lblas" ${TEST_TARGET}

post-test: # tests fail, see https://github.com/qsimulate-open/bagel/issues/248
	@cd ${WRKSRC}/src && ./TestSuite --log_level=all

.include <bsd.port.mk>
