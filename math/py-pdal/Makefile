PORTNAME=	pdal
DISTVERSION=	3.4.5
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	PDAL Python bindings
WWW=		https://pypi.python.org/pypi/pdal

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0.2.0:devel/py-scikit-build-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		pybind11>0:devel/pybind11 \
		cmake:devel/cmake-core
LIB_DEPENDS=	libpdalcpp.so:math/pdal
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		compiler:c++11-lang ninja:build python
USE_PYTHON=	autoplist cython pep517

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/libpdalpython*.so
	${PYTHON_CMD} -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${PYTHON_CMD} -O -m compileall -d ${PYTHON_SITELIBDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}

do-test:
	@cd ${WRKSRC} && py.test -v test

.include <bsd.port.mk>
