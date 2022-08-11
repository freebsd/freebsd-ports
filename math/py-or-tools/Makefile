PORTNAME=	or-tools
DISTVERSIONPREFIX=	v
DISTVERSION=	9.2
PORTREVISION=	5
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Google's Operations Research tools (Python binding)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE-2.0.txt

BROKEN_armv7=	SWIG wrapped code invalid in 32 bit architecture, regenerate code using -DSWIGWORDSIZE32
BROKEN_i386=	SWIG wrapped code invalid in 32 bit architecture, regenerate code using -DSWIGWORDSIZE32 # see https://github.com/google/or-tools/issues/2130

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}absl-py>0:devel/py-absl-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		protoc-gen-mypy:devel/py-mypy-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}virtualenv>0:devel/py-virtualenv@${PY_FLAVOR} \
		swig:devel/swig
LIB_DEPENDS=	libabsl_base.so:devel/abseil \
		libCbc.so:math/cbc \
		libCgl.so:math/cgl \
		libcoinasl.so:math/asl \
		libcoinmumps.so:math/ipopt \
		libCoinUtils.so:math/coinutils \
		libnauty.so:math/nauty \
		libopenblas.so:math/openblas \
		libOsi.so:math/osi \
		libOsiClp.so:math/clp \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libprotobuf.so:devel/protobuf
RUN_DEPENDS=	${PY_DEPENDS}

USES=		blaslapack cmake:insource compiler:c++17-lang pkgconfig python:3.6+
USE_PYTHON=	flavors

USE_GITHUB=	yes
GH_ACCOUNT=	google

CMAKE_OFF=	BUILD_DEPS INSTALL_BUILD_DEPS BUILD_TESTING BUILD_EXAMPLES
CMAKE_ON=	BUILD_PYTHON
CMAKE_ARGS=	-DSWIG_EXECUTABLE=${LOCALBASE}/bin/swig -DFREEBSD_PYTHON_VER=${PYTHON_VER}
CONFIGURE_ENV=	UNIX_CBC_DIR=${LOCALBASE} UNIX_CLP_DIR=${LOCALBASE}
BUILD_ENV=	UNIX_CBC_DIR=${LOCALBASE} UNIX_CLP_DIR=${LOCALBASE}

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

do-install: # by default cmake installs the whole or-tools project without the python part, so extract the wheel and install python files manually here
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} && \
		unzip ${BUILD_WRKSRC}/python/dist/ortools-${DISTVERSION}*.whl && \
		${RM} -rf ortools-*.dist-info
	${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -name "*.so" -o -name "*.so.*" | ${XARGS} ${STRIP_CMD}

do-test: install
.for e in arc_flow_cutting_stock_sat.py bus_driver_scheduling_sat.py cover_rectangle_sat.py cvrptw_plot.py qubo_sat.py # list is from examples/python/CMakeLists.txt
	@cd ${WRKSRC}/examples/python && \
		${ECHO} "==> Running ${PORTNAME} test ${e} ..." && \
		${PYTHON_CMD} ${e} && \
		${ECHO} "... test ${e} succeeded"
.endfor

.include <bsd.port.mk>
