PORTNAME=	spglib
DISTVERSIONPREFIX=	v
DISTVERSION=	2.8.0
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for finding and handling crystal symmetries (python binding)
WWW=		https://spglib.readthedocs.io/en/stable/ \
		https://github.com/spglib/spglib

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject-metadata>0:devel/py-pyproject-metadata@${PY_FLAVOR} \
		cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PY_SETUPTOOLS}
LIB_DEPENDS=	libsymspg.so:science/spglib
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.9.0:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-benchmark>0:devel/py-pytest-benchmark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest
USE_GITHUB=	yes

MAKE_ENV=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}

TEST_WRKSRC=	${WRKSRC}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_benchmark \
		-p benchmark

# tests as of 2.8.0: 3052 passed in 22.22s

.include <bsd.port.mk>
