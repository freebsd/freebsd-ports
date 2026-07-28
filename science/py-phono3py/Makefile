PORTNAME=	phono3py
DISTVERSION=	4.4.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software to calculate phonon-phonon interaction and related properties
WWW=		https://phonopy.github.io/phono3py/ \
		https://github.com/phonopy/phono3py

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake-core \
		${PYTHON_PKGNAMEPREFIX}nanobind>0:devel/py-nanobind@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}phonopy>=4.4.0:science/py-phonopy@${PY_FLAVOR}

USES=		blaslapack:openblas fortran localbase python
USE_PYTHON=	pep517 cython autoplist pytest

CFLAGS+=	-fPIC

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/test
PYTEST_BROKEN_TESTS=	test_reciprocal_to_normal_vs_c

# tests as of 4.4.0: 469 passed, 11 skipped, 1 deselected in 306.60s

.include <bsd.port.mk>
