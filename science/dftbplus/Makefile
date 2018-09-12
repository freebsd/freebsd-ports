# $FreeBSD$

PORTNAME=	dftbplus
DISTVERSION=	18.2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for performing fast atomistic simulations

LICENSE=	GPLv3+

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack
RUN_DEPENDS=	${PYNUMPY}

USES=		fortran gmake python shebangfix
SHEBANG_FILES=	tools/dptools/bin/* tools/misc/* utils/srcmanip/* utils/build/* external/fypp/bin/* utils/get_opt_externals \
		external/fypp/bin/fypp utils/test/testlist_to_fypp test/prog/dftb+/bin/tagdiff
SHEBANG_GLOB=	*.py
USE_GITHUB=	yes
GH_TUPLE=	dftbplus:mpifx:099ff75:mpifx/external/mpifx/origin \
		dftbplus:scalapackfx:86cd6e4:scalapackfx/external/scalapackfx/origin \
		dftbplus:dftd3-lib:00504a9:dftd3/external/dftd3/origin
MAKEFILE=	makefile

LDFLAGS+=	-llapack -lblas

MAKE_ARGS=	PYTHON=${PYTHON_CMD} INSTALLDIR=${STAGEDIR}${PREFIX} FREEBSD_PYDISTUTILS_INSTALLARGS="${PYDISTUTILS_INSTALLARGS} --root=${STAGEDIR}"

OPTIONS_DEFINE=		ARPACK DFTD3 MPI SOCKETS
OPTIONS_DEFAULT=	ARPACK DFTD3 MPI SOCKETS

ARPACK_DESC=		Build with ARPACK for large eigenvalue problems
ARPACK_MAKE_ENV=	WITH_ARPACK=1
ARPACK_MAKE_ENV_OFF=	WITH_ARPACK=0
LIB_LIB_DEPENDS=	libarpack.so:math/arpack

DFTD3_DESC=		Build with libdft3
DFTD3_MAKE_ENV=		WITH_DFTD3=1
DFTD3_MAKE_ENV_OFF=	WITH_DFTD3=0

MPI_MAKE_ENV=		WITH_MPI=1
MPI_MAKE_ENV_OFF=	WITH_MPI=0
MPI_LIB_DEPENDS=	libmpich.so:net/mpich2 \
			libscalapack.so:math/scalapack

SOCKETS_DESC=		Build with sockets library
SOCKETS_MAKE_ENV=	WITH_SOCKETS=1
SOCKETS_MAKE_ENV_OFF=	WITH_SOCKETS=0
SOCKETS_BINARY_ALIAS=	gcc=${CC}

MAKE_JOBS_UNSAFE=	yes # race conditions when some options are ON

post-patch:
	@cd ${WRKSRC} && ${LN} -s sys/make.x86_64-linux-gnu make.arch

post-install:
	@cd ${STAGEDIR}${PREFIX}/bin && ${STRIP_CMD} dftb+ modes waveplot

.include <bsd.port.mk>
