PORTNAME=	qdldl
DISTVERSION=	0.1.9.post1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	QDLDL free LDL factorization routine for linear systems: Ax = b
WWW=		https://github.com/oxfordcontrol/qdldl-python/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	error: no matching function for call to 'amd_l_order', see https://github.com/oxfordcontrol/qdldl-python/issues/15
BROKEN_i386=	error: no matching function for call to 'amd_l_order', see https://github.com/oxfordcontrol/qdldl-python/issues/15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2.0.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=49.5.0:devel/py-setuptools@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.7:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.13.2:science/py-scipy@${PY_FLAVOR}

USES=		cmake:indirect compiler:c++11-lang python
USE_PYTHON=	distutils autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/qdldl.cpython-*.so

do-test: install # this is required for some reason, and TEST_ENV doesn't work
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest ${TEST_ARGS}

# tests as of 0.1.9.post1: 9 passed in 2.98s

.include <bsd.port.mk>
