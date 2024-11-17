PORTNAME=	phono3py
DISTVERSION=	3.7.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Software to calculate phonon-phonon interaction and related properties
WWW=		https://phonopy.github.io/phono3py/ \
		https://github.com/phonopy/phono3py

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}h5py>=3.0:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.2.2:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}phonopy>=2.30:science/py-phonopy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}spglib>=2.3:science/py-spglib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.3:devel/py-pyyaml@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}scikit-build-core>0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nanobind>0:devel/py-nanobind@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		cmake:devel/cmake-core \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

CFLAGS+=	-fPIC

USES=		blaslapack:openblas fortran localbase python
USE_PYTHON=	pep517 cython autoplist pytest

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 3.7.0: 141 failed, 12 passed, 5 skipped, 1 warning, 39 errors in 433.87s (0:07:13)
# - tests fail to find mubmodules that are installed and import fine when run standalone

.include <bsd.port.mk>
