PORTNAME=	primme
DISTVERSION=	3.2.3
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PRIMME wrapper for Python
WWW=		https://www.cs.wm.edu/~andreas/software/ \
		https://github.com/primme/primme

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libprimme.so:math/primme \
		libblas.so:math/blas \
		liblapack.so:math/lapack
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}future>0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

USES=		fortran gmake localbase:ldflags python shebangfix
USE_PYTHON=	autoplist cython pep517

TEST_TARGET=	test

BINARY_ALIAS=	python2=${PYTHON_CMD}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/primme${PYTHON_TAG}.so

.include <bsd.port.mk>
