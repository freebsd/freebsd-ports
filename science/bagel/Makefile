PORTNAME=	bagel
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
PORTREVISION=	6
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Brilliantly Advanced General Electronic-structure Library

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=	error: static_assert failed "size_t is assumed to be the same size as unsigned long long"

LIB_DEPENDS=	libboost_serialization.so:devel/boost-libs

USES=		autoreconf blaslapack:openblas compiler:c++11-lang fortran gmake libtool localbase python:build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datarootdir=${DATADIR}
USE_GITHUB=	yes
GH_ACCOUNT=	nubakery
USE_CXXSTD=	c++11
USE_LDCONFIG=	yes

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

TEST_TARGET=			check # tests fail to build: https://github.com/nubakery/bagel/issues/145
#TEST_ENV=			${MAKE_ARGS}
#TEST_ARGS=			${MAKE_ARGS}

.include <bsd.port.mk>
