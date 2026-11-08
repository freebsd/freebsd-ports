PORTNAME=	pyprecice
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.0
CATEGORIES=	science # physics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Coupling library for partitioned multi-physics simulations
WWW=		https://precice.org/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mpi4py>0:net/py-mpi4py@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}pkgconfig>0:devel/py-pkgconfig@${PY_FLAVOR}
LIB_DEPENDS=	libprecice.so:science/precice
RUN_DEPENDS=	${PY_DEPENDS}

USES=		localbase pkgconfig python
USE_PYTHON=	distutils cython autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	precice
GH_PROJECT=	python-bindings

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cyprecice.cpython-${PYTHON_SUFFIX}.so

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		PYPRECICE_MOCKED=1 \
		PYTEST_ADDOPTS="-p no:black -p no:ruff -p no:mypy -p no:flake8 -p no:cov -p no:benchmark -p no:inline-snapshot -p no:xdist -p no:randomly"

do-test:
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${PYSETUP} build_ext --inplace --force && \
		${SETENV} ${TEST_ENV} pytest ${WRKSRC}/test

# tests as of 3.4.0: 65 passed in 0.74s (using PYPRECICE_MOCKED=1)

.include <bsd.port.mk>
