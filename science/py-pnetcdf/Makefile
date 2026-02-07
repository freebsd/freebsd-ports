PORTNAME=	pnetcdf
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Object-oriented python interface to the PnetCDF library
WWW=		https://github.com/Parallel-NetCDF/PnetCDF-Python

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpi4py-mpich>=3.1.4:net/py-mpi4py-mpich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.1:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libpnetcdf.so:science/pnetcdf@mpich
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpi4py-mpich>=3.1.4:net/py-mpi4py-mpich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=0,1:math/py-numpy@${PY_FLAVOR}

USES=		localbase mpi:mpich python
USE_PYTHON=	autoplist concurrent cython cython_run pep517

CFLAGS+=	-I${MPI_HOME}/include

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
