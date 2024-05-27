PORTNAME=	fenics-basix
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.0
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	FEniCS finite element basis evaluation library
WWW=		https://github.com/FEniCS/basix

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

BUILD_DEPENDS=	pybind11>=2.6.4:devel/pybind11 \
		cmake-core>=3.16:devel/cmake-core \
		xtensor>0:math/xtensor \
		xtl-quant-stack>0:devel/xtl-quant-stack \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>=0.12:devel/py-scikit-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.2.0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nanobind>0:devel/py-nanobind@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libbasix.so:math/fenics-basix
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numba>0:devel/py-numba@${PY_FLAVOR} \
		${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fenics-ufl>0:math/py-fenics-ufl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	pep517 autoplist pytest # 36 tests are known to fail likely because of broken numba, see https://github.com/FEniCS/basix/issues/594

USE_GITHUB=	yes
GH_ACCOUNT=	FEniCS
GH_PROJECT=	basix

WRKSRC_SUBDIR=	python

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/../test

.include <bsd.port.mk>
