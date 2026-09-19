PORTNAME=	arbor
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.2
CATEGORIES=	science
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Multi-compartment neural network simulation library
WWW=		https://arbor-sim.org/ \
		https://github.com/arbor-sim/arbor/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	nlohmann-json>=3.12.0:devel/nlohmann-json \
		pybind11>=3.0.0:devel/pybind11 \
		${PYTHON_PKGNAMEPREFIX}pybind11-stubgen>0:devel/py-pybind11-stubgen@${PY_FLAVOR}
LIB_DEPENDS=	libarbor.so:science/arbor
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}

USES=		cmake compiler:c++17-lang localbase:ldflags python
USE_PYTHON=	flavors unittest

USE_GITHUB=	yes
GH_ACCOUNT=	arbor-sim

WRKSRC_SUBDIR=	python

CMAKE_ARGS=	-DPython3_EXECUTABLE=${PYTHON_CMD} \
		-DARB_BUILD_PYTHON_STUBS=OFF \
		-DARB_PYTHON_LIB_PATH=${PYTHONPREFIX_SITELIBDIR}

CXXFLAGS+=	-fPIC
CXXFLAGS+=	-D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_NONE # prevent hardening issues with libc++, see https://github.com/arbor-sim/arbor/issues/2484

TEST_WRKSRC=	${WRKSRC}/test/unit_distributed
TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-patch:
	@${ECHO} ${DISTVERSION} > ${WRKSRC}/VERSION

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/arbor/_arbor${PYTHON_TAG}.so

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} -munittest discover -v -s ${WRKSRC}

# tests as of 0.12.2: Ran 78 tests in 11.215s, OK (skipped=3)

.include <bsd.port.mk>
