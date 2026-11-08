PORTNAME=	or-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	9.14
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Google's Operations Research tools (Python binding)
WWW=		https://github.com/google/or-tools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	SWIG wrapped code invalid in 32 bit architecture, regenerate code using -DSWIGWORDSIZE32
BROKEN_i386=	SWIG wrapped code invalid in 32 bit architecture, regenerate code using -DSWIGWORDSIZE32 # see https://github.com/google/or-tools/issues/2130

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}absl-py>=2.0.0:devel/py-absl-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}immutabledict>=3.0.0:devel/py-immutabledict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.13.3:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=2.0.0:math/py-pandas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=6.31.1:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.12:devel/py-typing-extensions@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		${PY_SETUPTOOLS} \
		protoc-gen-mypy:devel/py-mypy-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
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
		libhighs.so:math/highs \
		libprotobuf.so:devel/protobuf \
		libre2.so:devel/re2
RUN_DEPENDS=	${PY_DEPENDS}

USES=		blaslapack cmake:insource compiler:c++17-lang eigen:3 pkgconfig python
USE_PYTHON=	flavors pytest # tests fail, see https://github.com/google/or-tools/issues/3464

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TUPLE=	pybind:pybind11:v2.13.6:pybind11 \
		pybind:pybind11_abseil:v202402.0:pybind11_abseil \
		pybind:pybind11_protobuf:f02a2b7653bc50eb5119d125842a3870db95d251:pybind11_protobuf # pybind11 3.x is incompatible, pybind11_abseil and pybind11_protobuf ports don't install cmake configs

CMAKE_OFF=	BUILD_DEPS INSTALL_BUILD_DEPS BUILD_TESTING BUILD_EXAMPLES
CMAKE_ON=	BUILD_PYTHON BUILD_pybind11 BUILD_pybind11_abseil BUILD_pybind11_protobuf
CMAKE_ARGS=	-DSWIG_EXECUTABLE=${LOCALBASE}/bin/swig -DFREEBSD_PYTHON_VER=${PYTHON_VER} \
		-DFETCHCONTENT_SOURCE_DIR_PYBIND11=${WRKSRC_pybind11} \
		-DFETCHCONTENT_SOURCE_DIR_PYBIND11_ABSEIL=${WRKSRC_pybind11_abseil} \
		-DFETCHCONTENT_SOURCE_DIR_PYBIND11_PROTOBUF=${WRKSRC_pybind11_protobuf}
CONFIGURE_ENV=	UNIX_CBC_DIR=${LOCALBASE} UNIX_CLP_DIR=${LOCALBASE}
BUILD_ENV=	UNIX_CBC_DIR=${LOCALBASE} UNIX_CLP_DIR=${LOCALBASE}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

OPTIONS_DEFINE=		SCIP

SCIP_DESC=		Use the SCIP solver # SCIP package isn't built because of licensing restrictions
SCIP_CMAKE_BOOL=	USE_SCIP
SCIP_LIB_DEPENDS=	libscip.so:math/SCIP

post-patch: # the patch is normally applied by FetchContent
	@cd ${WRKSRC_pybind11} && ${PATCH} -s -p1 < ${WRKSRC}/patches/pybind11-v2.13.6.patch
	@cd ${WRKSRC_pybind11_abseil} && ${PATCH} -s -p1 < ${WRKSRC}/patches/pybind11_abseil.patch

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

# tests as of 9.14: make test collects no tests; running the upstream cp_model, model_builder, lp, pywraplp and cp_model_helper tests manually against the stage: 10558 passed, 2 failed (they need data files absent in the copied test dir)

.include <bsd.port.mk>
