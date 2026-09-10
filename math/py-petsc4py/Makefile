PORTNAME=	petsc4py
DISTVERSION=	3.25.5
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PETSc for Python
WWW=		https://gitlab.com/petsc/petsc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BROKEN_armv7=	compilation fails: LLVM ERROR: out of memory

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	libpetsc.so:science/PETSc
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cython distutils pytest

MAKE_ENV=	PETSC_DIR=${LOCALBASE}

TEST_ARGS=	--ignore=demo -k 'not (testStdoutRedirect or testCompatMPI4PY)'

OPTIONS_SINGLE=		MPI
OPTIONS_SINGLE_MPI=	MPICH OPENMPI
OPTIONS_DEFAULT=	MPICH

MPICH_USES=		mpi:mpich

OPENMPI_USES=		mpi:openmpi

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/petsc4py/lib/PETSc${PYTHON_SOABI}.so

# tests as of 3.25.5: 6454 passed 2 deselected

.include <bsd.port.mk>
