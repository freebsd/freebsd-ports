PORTNAME=	dftbplus
DISTVERSION=	22.1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DFTB+: Package for performing fast atomistic simulations

LICENSE=	GPLv3 # main code is under LGPL3+, the bundled dftd3-lib is under GPLv1+, this makes the result GPLv3 (based on https://www.gnu.org/licenses/gpl-faq.html#AllCompatibility)

BROKEN_aarch64=	Lack of IEEE754 support in gcc causes "Cannot find an intrinsic module named 'ieee_arithmetic'", see bug\#255890
BROKEN_FreeBSD_12_powerpc=	Lack of IEEE754 support in gcc causes "Cannot find an intrinsic module named 'ieee_arithmetic'", see bug\#255890
BROKEN_FreeBSD_12_powerpc64=	Lack of IEEE754 support in gcc causes "Cannot find an intrinsic module named 'ieee_arithmetic'", see bug\#255890
BROKEN_FreeBSD_13_powerpc=	Lack of IEEE754 support in gcc causes "Cannot find an intrinsic module named 'ieee_arithmetic'", see bug\#255890
BROKEN_FreeBSD_13_powerpc64=	Lack of IEEE754 support in gcc causes "Cannot find an intrinsic module named 'ieee_arithmetic'", see bug\#255890
BROKEN_FreeBSD_13_powerpc64le=	Lack of IEEE754 support in gcc causes "Cannot find an intrinsic module named 'ieee_arithmetic'", see bug\#255890

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack \
		libopenblas.so:math/openblas
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	bash:shells/bash

USES=		cmake compiler:gcc-c++11-lib fortran pkgconfig python:build shebangfix
USE_LDCONFIG=	yes

SHEBANG_FILES=	tools/dptools/bin/* tools/misc/* utils/srcmanip/* utils/build/* external/fypp/bin/* utils/get_opt_externals \
		external/fypp/bin/fypp utils/test/testlist_to_fypp
SHEBANG_GLOB=	*.py *.sh

USE_GITHUB=	yes
GH_TUPLE=	\
		aradi:fytest:94e05ac:aradi_fytest/external/fytest/origin \
		dftbplus:testparams:cd7536f:testparams/external/slakos/origin \
		dftd4:dftd4:1189af7:dftd4_dftd4/external/dftd4/origin \
		grimme-lab:gbsa-parameters:6836c4d:grimme_lab_gbsa/external/gbsa/origin

TEST_TARGET=	test

BINARY_ALIAS=	git=false

CMAKE_ON=	BLAS_DETECTION BUILD_SHARED_LIBS WITH_API ENABLE_DYNAMIC_LOADING
CMAKE_ARGS=	-DLAPACK_LIBRARY=lapack -DSCALAPACK_LIBRARY=scalapack

BINARY_ALIAS=		python=${PYTHON_CMD} python3=${PYTHON_CMD}

OPTIONS_DEFINE=		ARPACK CHIMES DFTD3 MBD MPI PLUMED POISSON PYTHON SOCKETS TBLITE TRANSPORT # see config.cmake for a complete list
OPTIONS_DEFAULT=	CHIMES DFTD3 MBD MPI PLUMED POISSON TRANSPORT SOCKETS # PYTHON TBLITE
OPTIONS_SUB=		yes

ARPACK_DESC=		Build with ARPACK for large eigenvalue problems
ARPACK_CMAKE_BOOL=	WITH_ARPACK
ARPACK_LIB_DEPENDS=	libarpack.so:math/arpack-ng
ARPACK_PREVENTS=	MPI # ARPACK is only used in a single-core application

CHIMES_DESC=		Build with ChIMES
CHIMES_CMAKE_BOOL=	WITH_CHIMES
CHIMES_LIB_DEPENDS=	libchimescalc.so:science/chimes-calculator

DFTD3_DESC=		Build with s-dft3
DFTD3_CMAKE_BOOL=	WITH_SDFTD3
DFTD3_LIB_DEPENDS=	libs-dftd3.so:science/simple-dftd3 \
			libmctc-lib.so:science/mctc-lib \
			libmstore.so:science/mstore \
			libtoml-f.so:textproc/toml-f # binaries not linked with libtoml-f.so, see https://github.com/dftbplus/dftbplus/issues/1040

MBD_DESC=		Build with many-body-dispersion support
MBD_CMAKE_BOOL=		WITH_MBD
MBD_LIB_DEPENDS=	libmbd.so:science/libmbd

MPI_CMAKE_BOOL=		WITH_MPI
MPI_LIB_DEPENDS=	libmpich.so:net/mpich \
			libmpifx.so:net/mpifx \
			libscalapack.so:math/scalapack \
			libscalapackfx.so:math/scalapackfx
MPI_LDFLAGS=		${LOCALBASE}/lib/libmpich.so ${LOCALBASE}/lib/libmpifort.so ${LOCALBASE}/lib/libmpi.so

PLUMED_DESC=		Do metadynamics via the PLUMED2 library
PLUMED_CMAKE_BOOL=	WITH_PLUMED
PLUMED_LIB_DEPENDS=	libplumed.so:science/plumed

POISSON_DESC=		Include Poisson-solver
POISSON_CMAKE_BOOL=	WITH_POISSON

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	WITH_PYTHON
PYTHON_BROKEN=		fails to install into stage directory: https://github.com/dftbplus/dftbplus/issues/931

SOCKETS_DESC=		Build with sockets library
SOCKETS_CMAKE_BOOL=	WITH_SOCKETS
SOCKETS_BINARY_ALIAS=	gcc=${CC}

TBLITE_DESC=		Include xTB support via tblite
TBLITE_CMAKE_BOOL=	WITH_TBLITE
TBLITE_BROKEN=		Fails to build, see https://github.com/dftbplus/dftbplus/issues/1041

TRANSPORT_DESC=		Transport via libNEGF
TRANSPORT_CMAKE_BOOL=	WITH_TRANSPORT
TRANSPORT_LIB_DEPENDS=	libnegf.so:science/libnegf \
			libmpi.so:net/mpich \
			libmpifx.so:net/mpifx

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Type mismatch between actual argument at (1) and actual argument at (2) (COMPLEX(8)/CHARACTER(*)).
# in theory, this should set FCFLAGS, but the port does not conform
FFLAGS+=	-fallow-argument-mismatch
.endif

.include <bsd.port.post.mk>
