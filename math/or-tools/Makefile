PORTNAME=	or-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	9.12-20250219 # tag from the 'main' branch
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Google's Operations Research tools
WWW=		https://github.com/google/or-tools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PATCH_DEPENDS=	gsed:textproc/gsed
xBUILD_DEPENDS=	benchmark>0:devel/benchmark \
		googletest>0:devel/googletest
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libcoinasl.so:math/asl \
		libcoinmumps.so:math/coin-or-mumps \
		libCoinUtils.so:math/coinutils \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libhighs.so:math/highs \
		libnauty.so:math/nauty \
		libopenblas.so:math/openblas \
		libOsi.so:math/osi \
		libOsiClp.so:math/clp \
		libprotobuf.so:devel/protobuf \
		libre2.so:devel/re2 \
		libscip.so:math/SCIP
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		blaslapack cmake:testing compiler:c++17-lang eigen:3 pkgconfig
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	e0f2787c5050c7cf6bc3e5f902fdb8fc11bd3f38 # tag from the 'main' branch (as opposedto 'stable' branch) that includes the fix for https://github.com/google/or-tools/issues/4548

CMAKE_OFF=	BUILD_PYTHON BUILD_DEPS INSTALL_BUILD_DEPS \
		BUILD_TESTING BUILD_EXAMPLES BUILD_SAMPLES
CMAKE_ON=	BUILD_CXX \
		USE_PDLP \
		USE_SCIP
CMAKE_TESTING_ON=	BUILD_TESTING BUILD_EXAMPLES BUILD_CXX_EXAMPLES

CONFIGURE_ENV=	UNIX_CBC_DIR=${LOCALBASE} UNIX_CLP_DIR=${LOCALBASE}

OPTIONS_DEFINE=		DOCS FLATZINC SCIP
OPTIONS_DEFAULT=	FLATZINC # SCIP
OPTIONS_SUB=		yes

FLATZINC_DESC=		Build FlatZinc - MiniZinc interface
FLATZINC_CMAKE_BOOL=	BUILD_FLATZINC

SCIP_DESC=		Use the SCIP solver # SCIP package isn't built because of licensing restrictions
SCIP_CMAKE_BOOL=	USE_SCIP
SCIP_LIB_DEPENDS=	libscip.so:math/SCIP

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/-//}
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e '17,19d' ${WRKSRC}/ortools/base/logging.h

post-install:
	@${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete

# tests as of 9.12-20250219: 97% tests passed, 5 tests failed out of 163:
# Tests cxx_cpp_linear_programming and cxx_cpp_integer_programming abort: https://github.com/google/or-tools/issues/4555
# 13 tests fail whuke running the math_opt_solvers_cp_sat_solver_test test executable: https://github.com/google/or-tools/issues/4556
# The test SimpleMaxFlowTest.ProblematicProblemWithMaxCapacity (graph_max_flow_test) fails to find test data when it is built outsource: https://github.com/google/or-tools/issues/4557

.include <bsd.port.mk>
