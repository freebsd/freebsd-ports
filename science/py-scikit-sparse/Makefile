PORTNAME=	scikit-sparse
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
CATEGORIES=	science python
#MASTER_SITES=	PYPI # missing files under tests/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Sparse matrix package
WWW=		https://github.com/scikit-sparse/scikit-sparse

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=2.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libamd.so:math/suitesparse-amd \
		libbtf.so:math/suitesparse-btf \
		libcamd.so:math/suitesparse-camd \
		libccolamd.so:math/suitesparse-ccolamd \
		libcholmod.so:math/suitesparse-cholmod \
		libcolamd.so:math/suitesparse-colamd \
		libklu.so:math/suitesparse-klu \
		libspqr.so:math/suitesparse-spqr \
		libumfpack.so:math/suitesparse-umfpack
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>2.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.14:science/py-scipy@${PY_FLAVOR}

USES=		fortran python
USE_PYTHON=	pep517 cython autoplist pytest
USE_GITHUB=	yes

MAKE_ENV=	SUITESPARSE_INCLUDE_DIR=${LOCALBASE}/include/suitesparse \
		SUITESPARSE_LIBRARY_DIR=${LOCALBASE}/lib

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}
TEST_ARGS=	-p no:cov -p no:xdist

post-install:
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sksparse -name "*.so" | ${XARGS} ${STRIP_CMD}

# tests as of 0.5.0: 9285 passed, 3 xfailed in 24.82s

.include <bsd.port.mk>
