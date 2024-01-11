PORTNAME=	thewalrus
DISTVERSIONPREFIX=	v
DISTVERSION=	0.21.0
CATEGORIES=	science python
#MASTER_SITES=	PYPI # doesn't contain tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open source library for hafnian calculation
WWW=		https://the-walrus.readthedocs.io/en/latest/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dask>0:devel/py-dask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numba>0:devel/py-numba@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	gmake:devel/gmake \
		${PYTHON_PKGNAMEPREFIX}flaky>=3.7.0:devel/py-flaky@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-randomly>0:devel/py-pytest-randomly@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	XanaduAI

NO_ARCH=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}

do-test: # testsuite fails to run: https://github.com/XanaduAI/thewalrus/issues/344
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} test

.include <bsd.port.mk>
