PORTNAME=	latte
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum chemistry: Density functional tight binding molecular dynamics

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE_GPL-2.0

USES=		blaslapack:openblas cmake:noninja fortran shebangfix
SHEBANG_FILES=	tests/run_test.sh
USE_GITHUB=	yes
GH_ACCOUNT=	lanl
GH_PROJECT=	${PORTNAME:tu}
USE_LDCONFIG=	yes

CMAKE_SOURCE_PATH=	${WRKSRC}/cmake
CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_ARGS=	-DBLA_VENDOR:STRING="OpenBLAS"

OPTIONS_DEFINE=		DBCSR OPENMP MPI # TODO PROGRESS needs to be ported
OPTIONS_DEFAULT=	OPENMP MPI

DBCSR_DESC=		Use distributed block compressed sparse row matrix library
DBCSR_CMAKE_BOOL=	DBCSR_OPT
DBCSR_LIB_DEPENDS=	libdbcsr.so:math/dbcsr
DBCSR_BROKEN=		see https://github.com/lanl/LATTE/issues/92

OPENMP_CMAKE_BOOL=	OPENMP

MPI_CMAKE_BOOL=		DO_MPI
MPI_LIB_DEPENDS=	libmpi.so:net/openmpi
MPI_LDFLAGS=		${LOCALBASE}/mpi/openmpi/lib/libmpi_mpifh.so
MPI_PLIST_FILES=	bin/LATTE_MPI_DOUBLE
MPI_PLIST_FILES_OFF=	bin/LATTE_DOUBLE

CONFLICTS_INSTALL=	latte-integrale

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for Type mismatch between actual argument at (1) and actual argument at (2) (COMPLEX(8)/REAL(8)).
# in theory, this should set FCFLAGS, but the port does not conform
FFLAGS+=	-fallow-argument-mismatch
.endif

.include <bsd.port.post.mk>
