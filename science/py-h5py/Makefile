PORTNAME=	h5py
PORTVERSION=	3.15.1
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	General-purpose Python interface to the HDF5 library
WWW=		https://www.h5py.org/ \
		https://github.com/h5py/h5py

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/licenses/license.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.25.0,1<3,1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pkgconfig>=1.5.5,1:devel/py-pkgconfig@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libhdf5.so:science/hdf5
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.21.2,1:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mpi4py>=3.1.2:net/py-mpi4py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tables>=3.4.4:devel/py-tables@${PY_FLAVOR}

USES=		localbase pkgconfig python
USE_PYTHON=	autoplist concurrent cython3 pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}
TEST_WRKSRC=	${STAGEDIR}${PYTHON_SITELIBDIR}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.py ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
