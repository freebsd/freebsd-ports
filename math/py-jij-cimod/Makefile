PORTNAME=	jij-cimod
DISTVERSION=	1.7.3
CATEGORIES=	math
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for the C++ library for a binary quadratic model
WWW=		https://www.openjij.org/ \
		https://github.com/Jij-Inc/cimod

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.10:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		nlohmann-json>0:devel/nlohmann-json \
		pybind11-json>0:devel/pybind11-json
LIB_DEPENDS=	libcblas.so:math/cblas \
		liblapack.so:math/lapack \
		libopenblas.so:math/openblas

USES=		cmake:indirect compiler:c++17-lang eigen:3 localbase:ldflags python
USE_PYTHON=	pep517 cython autoplist pytest

TEST_WRKSRC=	${WRKSRC}/tests
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 1.7.3: 49 passed, 10 warnings in 19.01s

.include <bsd.port.mk>
