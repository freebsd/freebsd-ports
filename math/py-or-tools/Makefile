PORTNAME=	or-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	9.6
PORTREVISION=	11
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Google's Operations Research tools (Python binding)
WWW=		https://github.com/google/or-tools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	SWIG wrapped code invalid in 32 bit architecture, regenerate code using -DSWIGWORDSIZE32
BROKEN_i386=	SWIG wrapped code invalid in 32 bit architecture, regenerate code using -DSWIGWORDSIZE32 # see https://github.com/google/or-tools/issues/2130

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}absl-py>0:devel/py-absl-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		${PY_SETUPTOOLS} \
		pybind11>0:devel/pybind11 \
		protoc-gen-mypy:devel/py-mypy-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>0:devel/py-virtualenv@${PY_FLAVOR} \
		swig:devel/swig
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libcoinasl.so:math/asl \
		libcoinmumps.so:math/coin-or-mumps \
		libCoinUtils.so:math/coinutils \
		libnauty.so:math/nauty \
		libopenblas.so:math/openblas \
		libOsi.so:math/osi \
		libOsiClp.so:math/clp \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libprotobuf.so:devel/protobuf \
		libre2.so:devel/re2
RUN_DEPENDS=	${PY_DEPENDS}

USES=		blaslapack cmake:insource compiler:c++17-lang eigen:3 pkgconfig python
USE_PYTHON=	flavors pytest # tests fail, see https://github.com/google/or-tools/issues/3464

USE_GITHUB=	yes
GH_ACCOUNT=	google

CMAKE_OFF=	BUILD_DEPS BUILD_pybind11 INSTALL_BUILD_DEPS BUILD_TESTING BUILD_EXAMPLES
CMAKE_ON=	BUILD_PYTHON
CMAKE_ARGS=	-DSWIG_EXECUTABLE=${LOCALBASE}/bin/swig -DFREEBSD_PYTHON_VER=${PYTHON_VER}
CONFIGURE_ENV=	UNIX_CBC_DIR=${LOCALBASE} UNIX_CLP_DIR=${LOCALBASE}
BUILD_ENV=	UNIX_CBC_DIR=${LOCALBASE} UNIX_CLP_DIR=${LOCALBASE}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

OPTIONS_DEFINE=		SCIP

SCIP_DESC=		Use the SCIP solver # SCIP package isn't built because of licensing restrictions
SCIP_CMAKE_BOOL=	USE_SCIP
SCIP_LIB_DEPENDS=	libscip.so:math/SCIP

post-patch:
	@${REINPLACE_CMD} -e '/absl::container/s,^,#,' \
		${WRKSRC}/ortools/constraint_solver/CMakeLists.txt \
		${WRKSRC}/ortools/glop/CMakeLists.txt \
		${WRKSRC}/ortools/linear_solver/CMakeLists.txt \
		${WRKSRC}/ortools/sat/CMakeLists.txt
	@${REINPLACE_CMD} -e '17,19d ; /AbslStringify/,+10d' \
		${WRKSRC}/ortools/base/logging.h

do-install: # by default cmake installs the whole or-tools project without the python part, so extract the wheel and install python files manually here
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} && \
		unzip ${BUILD_WRKSRC}/python/dist/ortools-${DISTVERSION}*.whl && \
		${RM} -rf ortools-*.dist-info
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name "*.so" -o -name "*.so.*" | ${XARGS} ${STRIP_CMD}

run-examples: # one of the examples fail: https://github.com/google/or-tools/issues/3463
.for e in arc_flow_cutting_stock_sat.py bus_driver_scheduling_sat.py cover_rectangle_sat.py cvrptw_plot.py qubo_sat.py # list is from examples/python/CMakeLists.txt
	@cd ${WRKSRC}/examples/python && \
		${ECHO} "==> Running ${PORTNAME} test ${e} ..." && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${e} && \
		${ECHO} "... test ${e} succeeded"
.endfor

.include <bsd.port.mk>
