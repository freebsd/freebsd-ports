PORTNAME=	dftbplus
DISTVERSION=	21.2
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DFTB+: Package for performing fast atomistic simulations

LICENSE=	GPLv3 # main code is under LGPL3+, the bundled dftd3-lib is under GPLv1+, this makes the result GPLv3 (based on https://www.gnu.org/licenses/gpl-faq.html#AllCompatibility)

.for arch in aarch64 powerpc powerpc64 powerpc64le
BROKEN_${arch}=	Lack of IEEE754 support in gcc causes "Cannot find an intrinsic module named 'ieee_arithmetic'", see bug\#255890
.endfor

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack \
		libopenblas.so:math/openblas
RUN_DEPENDS=	${PYNUMPY}
TEST_DEPENDS=	bash:shells/bash

USES=		cmake compiler:gcc-c++11-lib fortran python:build shebangfix
USE_LDCONFIG=	yes

SHEBANG_FILES=	tools/dptools/bin/* tools/misc/* utils/srcmanip/* utils/build/* external/fypp/bin/* utils/get_opt_externals \
		external/fypp/bin/fypp utils/test/testlist_to_fypp \
		test/app/phonons/bin/tagdiff test/app/dftb+/bin/tagdiff test/app/dftb+/bin/tagdiff
SHEBANG_GLOB=	*.py *.sh

USE_GITHUB=	yes
GH_TUPLE=	\
		aradi:fytest:94e05ac:aradi_fytest/external/fytest/origin \
		awvwgk:simple-dftd3:c2f03fe:awvwgk_simple_dftd3/external/s-dftd3/origin \
		awvwgk:tblite:dfc761d:awvwgk_tblite/external/tblite/origin \
		dftbplus:mpifx:8200a5e:mpifx/external/mpifx/origin \
		dftbplus:scalapackfx:0d5750d:scalapackfx/external/scalapackfx/origin \
		dftbplus:testparams:cd7536f:testparams/external/slakos/origin \
		dftd4:dftd4:1189af7:dftd4_dftd4/external/dftd4/origin \
		grimme-lab:gbsa-parameters:6836c4d:grimme_lab_gbsa/external/gbsa/origin \
		grimme-lab:mctc-lib:a2f70b0:grimme_lab_mctc_lib/external/mctc-lib/origin \
		grimme-lab:mstore:974fb59:grimme_lab_mstore/external/mstore/origin \
		grimme-lab:multicharge:dde0d67:grimme_lab_multicharge/external/multicharge/origin \
		libmbd:libmbd:95c95b5:libmbd_libmbd/external/mbd/origin \
		libnegf:libnegf:c8ed2ca:libnegf_libnegf/external/libnegf/origin \
		rk-lindsey:chimes_calculator:98e3653:rk_lindsey_chimes_calculator/external/chimes/origin \
		toml-f:toml-f:f066ec6:toml_f_toml_f/external/toml-f/origin

TEST_TARGET=	test

CMAKE_ON=	BLAS_DETECTION BUILD_SHARED_LIBS WITH_API ENABLE_DYNAMIC_LOADING
CMAKE_ARGS=	-DLAPACK_LIBRARY=lapack -DSCALAPACK_LIBRARY=scalapack

BINARY_ALIAS=		python=${PYTHON_CMD} python3=${PYTHON_CMD}

OPTIONS_DEFINE=		ARPACK CHIMES DFTD3 MPI PYTHON SOCKETS
OPTIONS_DEFAULT=	CHIMES DFTD3 MPI SOCKETS # PYTHON
OPTIONS_SUB=		yes

ARPACK_DESC=		Build with ARPACK for large eigenvalue problems
ARPACK_CMAKE_BOOL=	WITH_ARPACK
ARPACK_LIB_DEPENDS=	libarpack.so:math/arpack-ng
ARPACK_PREVENTS=	MPI # ARPACK is only used in a single-core application

CHIMES_DESC=		Build with ChIMES
CHIMES_CMAKE_BOOL=	WITH_CHIMES

DFTD3_DESC=		Build with libdft3
DFTD3_CMAKE_BOOL=	WITH_SDFTD3

MPI_CMAKE_BOOL=		WITH_MPI
MPI_LIB_DEPENDS=	libmpich.so:net/mpich \
			libscalapack.so:math/scalapack
MPI_LDFLAGS=		${LOCALBASE}/lib/libmpich.so ${LOCALBASE}/lib/libmpifort.so ${LOCALBASE}/lib/libmpi.so

PYTHON_USES=		python
PYTHON_CMAKE_BOOL=	WITH_PYTHON
PYTHON_BROKEN=		fails to install into stage directory: https://github.com/dftbplus/dftbplus/issues/931

SOCKETS_DESC=		Build with sockets library
SOCKETS_CMAKE_BOOL=	WITH_SOCKETS
SOCKETS_BINARY_ALIAS=	gcc=${CC}

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Type mismatch between actual argument at (1) and actual argument at (2) (COMPLEX(8)/CHARACTER(*)).
# in theory, this should set FCFLAGS, but the port does not conform
FFLAGS+=	-fallow-argument-mismatch
.endif

.include <bsd.port.post.mk>
