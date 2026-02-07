PORTNAME=	pulsar-client
DISTVERSIONPREFIX=	v
DISTVERSION=	3.8.0
CATEGORIES=	net-p2p python # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Apache Pulsar Python client library
WWW=		https://pulsar.apache.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	pybind11>0:devel/pybind11 \
		gmake:devel/gmake
LIB_DEPENDS=	libpulsar.so:net-p2p/pulsar-client-cpp
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>0:security/py-certifi@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fastavro>=1.9.2:textproc/py-fastavro@${PY_FLAVOR}

USES=		cmake:indirect python
USE_PYTHON=	flavors
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	apache
GH_PROJECT=	pulsar-client-python

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

pre-build: # build lib_pulse.so using cmake/gmake
	@cd ${CONFIGURE_WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ${CMAKE_SOURCE_PATH} && \
		${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${GMAKE}

post-install: # strip binary
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_pulsar${PYTHON_TAG}.so

# tests: many tests fail with Pulsar error: TimeOut, Connection refused because Pulsar needs to be running
# tests: 107 failed, 52 passed, 1 warning in 2947.08s (0:49:07)

.include <bsd.port.mk>
