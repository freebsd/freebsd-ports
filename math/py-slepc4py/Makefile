PORTNAME=	slepc4py
DISTVERSION=	3.25.1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SLEPc for Python
WWW=		https://bitbucket.org/slepc/slepc4py

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} ${PYTHON_PKGNAMEPREFIX}petsc4py>0:math/py-petsc4py@${PY_FLAVOR}
LIB_DEPENDS=	libmpich.so:net/mpich libpetsc.so:science/PETSc libslepc.so:math/slepc
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} ${PYTHON_PKGNAMEPREFIX}petsc4py>0:math/py-petsc4py@${PY_FLAVOR}

USES=		fortran python
USE_PYTHON=	autoplist cython distutils pytest

MAKE_ENV=	PETSC_DIR=${LOCALBASE} SLEPC_DIR=${LOCALBASE}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/slepc4py/lib/SLEPc${PYTHON_TAG}.so

# tests as of 3.25.1: 112 passed in 0.86s

.include <bsd.port.mk>
