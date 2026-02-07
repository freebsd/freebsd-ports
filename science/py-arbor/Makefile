PORTNAME=	arbor
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
CATEGORIES=	science
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-compartment neural network simulation library
WWW=		https://arbor-sim.org/ \
		https://github.com/arbor-sim/arbor/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	gmake:devel/gmake \
		pybind11>0:devel/pybind11 \
		nlohmann-json>0:devel/nlohmann-json
LIB_DEPENDS=	libarbor.so:science/arbor
RUN_DEPENDS=	${PYNUMPY}

USES=		cmake compiler:c++17-lang localbase:ldflags python
USE_PYTHON=	flavors unittest # tests fail to run, see https://github.com/arbor-sim/arbor/issues/2395

USE_GITHUB=	yes
GH_ACCOUNT=	arbor-sim

WRKSRC_SUBDIR=	python

CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD} \
		-DARB_PYTHON_LIB_PATH=${PYTHONPREFIX_SITELIBDIR}

CXXFLAGS+=	-fPIC
CXXFLAGS+=	-D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_NONE # prevent hardening issues with libc++, see https://github.com/arbor-sim/arbor/issues/2484

TEST_WRKSRC=	${WRKSRC}/test/unit_distributed
TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

BINARY_ALIAS=	make=${GMAKE}

post-patch:
	@${ECHO} ${DISTVERSION} > ${WRKSRC}/VERSION

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/arbor/_arbor${PYTHON_TAG}.so

do-test: # tests fail to run due to a bug with nadling complex CXXFLAGS in the test runner, see https://github.com/arbor-sim/arbor/issues/2395
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} -munittest discover -v -s ${WRKSRC}

.include <bsd.port.mk>
