PORTNAME=	elemental
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Dense and sparse linear algebra, conic optimization, lattice reduction
WWW=		https://github.com/LLNL/Elemental

LICENSE=	BSD2CLAUSE

BROKEN_FreeBSD_12_powerpc64=	fails to compile: include/El/blas_like/level1/Copy.hpp:522:27: ambiguous template specialization 'Copy<>' for 'void El::Copy(const El::Matrix<int>&, El::Matrix<int>&)'
BROKEN_i386=	clang crashes: https://bugs.llvm.org/show_bug.cgi?id=46026

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmetis.so:math/metis \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr \
		libmpi_cxx.so:net/openmpi \
		libopenblas.so:math/openblas \
		libqd.so:math/qd
TEST_DEPENDS=	catch>0:devel/catch

USES=		cmake compiler:c++14-lang fortran
USE_GITHUB=	yes
GH_ACCOUNT=	LLNL
GH_PROJECT=	Elemental
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS EL_DISABLE_PARMETIS
CMAKE_OFF=	Hydrogen_ENABLE_TESTING
CMAKE_ARGS=	-DGFORTRAN_LIB:STRING=${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgfortran.so \
		-DFREEBSD_GCC_LIB:STRING=${LOCALBASE}/lib/gcc${GCC_DEFAULT}/libgcc_s.so

DOCSDIR=	${PREFIX}/share/doc/Elemental

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

do-test: # 4 tests fail, see https://github.com/LLNL/Elemental/issues/157
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DHydrogen_ENABLE_TESTING:BOOL=ON -DHydrogen_ENABLE_UNIT_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
