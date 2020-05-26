# $FreeBSD$

PORTNAME=	dftbplus
DISTVERSION=	19.1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DFTB+: Package for performing fast atomistic simulations

LICENSE=	GPLv3 # main code is under LGPL3+, the bundled dftd3-lib is under GPLv1+, this makes the result GPLv3 (based on https://www.gnu.org/licenses/gpl-faq.html#AllCompatibility)

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15
BROKEN_powerpc64=	fails to compile: lbfgs.f90:18:19: Cannot find an intrinsic module named 'ieee_arithmetic' at (1)

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack
RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:gcc-c++11-lib fortran gmake python:2.7 shebangfix
SHEBANG_FILES=	tools/dptools/bin/* tools/misc/* utils/srcmanip/* utils/build/* external/fypp/bin/* utils/get_opt_externals \
		external/fypp/bin/fypp utils/test/testlist_to_fypp test/prog/dftb+/bin/tagdiff
SHEBANG_GLOB=	*.py
USE_GITHUB=	yes
GH_TUPLE=	dftbplus:mpifx:099ff75:mpifx/external/mpifx/origin \
		dftbplus:scalapackfx:86cd6e4:scalapackfx/external/scalapackfx/origin \
		dftbplus:dftd3-lib:00504a9:dftd3/external/dftd3/origin \
		dftbplus:testparams:1601609:testparams/external/slakos/origin
MAKEFILE=	makefile
TEST_TARGET=	test

FFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-llapack -lblas -lgfortran -lm

MAKE_ARGS=	PYTHON=${PYTHON_CMD} FC=${FC} FXX=${FC} LN=${CC} \
		INSTALLDIR=${STAGEDIR}${PREFIX} FREEBSD_PYDISTUTILS_INSTALLARGS="${PYDISTUTILS_INSTALLARGS} --root=${STAGEDIR}"

OPTIONS_DEFINE=		DFTD3 MPI SOCKETS ARPACK
OPTIONS_DEFAULT=	DFTD3 MPI SOCKETS

DFTD3_DESC=		Build with libdft3
DFTD3_MAKE_ARGS=	WITH_DFTD3=1
DFTD3_MAKE_ARGS_OFF=	WITH_DFTD3=0

MPI_MAKE_ARGS=		WITH_MPI=1
MPI_MAKE_ARGS_OFF=	WITH_MPI=0
MPI_LIB_DEPENDS=	libmpich.so:net/mpich \
			libscalapack.so:math/scalapack
MPI_LDFLAGS=		${LOCALBASE}/lib/libmpich.so ${LOCALBASE}/lib/libmpifort.so ${LOCALBASE}/lib/libmpi.so

SOCKETS_DESC=		Build with sockets library
SOCKETS_MAKE_ARGS=	WITH_SOCKETS=1
SOCKETS_MAKE_ARGS_OFF=	WITH_SOCKETS=0
SOCKETS_BINARY_ALIAS=	gcc=${CC}

ARPACK_DESC=		Build with ARPACK for large eigenvalue problems
ARPACK_MAKE_ARGS=	WITH_ARPACK=1
ARPACK_MAKE_ARGS_OFF=	WITH_ARPACK=0
ARPACK_LIB_DEPENDS=	libarpack.so:math/arpack-ng
ARPACK_PREVENTS=	MPI # ARPACK is only used in a single-core application

MAKE_JOBS_UNSAFE=	yes # race conditions when some options are ON

post-extract:
	@${RM} ${WRKSRC}/external/scalapackfx/origin/test/psyr_result.dat.orig
	@cd ${WRKSRC} && ${CP} sys/make.x86_64-linux-gnu make.arch

post-install:
	@cd ${STAGEDIR}${PREFIX}/bin && ${STRIP_CMD} dftb+ modes waveplot

.include <bsd.port.mk>
