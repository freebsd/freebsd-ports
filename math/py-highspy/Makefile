PORTNAME=	highspy
DISTVERSION=	1.11.0
CATEGORIES=	math
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings for the extensible C++ library for random forests
WWW=		https://github.com/automl/random_forest_run

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.3.3:devel/py-scikit-build-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}

USES=		cmake:indirect compiler:c++11-lang python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 1.11.0: 58 passed in 2.98s

.include <bsd.port.mk>
