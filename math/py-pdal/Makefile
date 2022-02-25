PORTNAME=	pdal
DISTVERSION=	3.0.2
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	lbartoletti@FreeBSD.org
COMMENT=	PDAL Python bindings

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scikit-build>0:devel/py-scikit-build@${PY_FLAVOR} \
		${PREFIX}/share/cmake/pybind11/pybind11Config.cmake:devel/pybind11 \
		cmake:devel/cmake
LIB_DEPENDS=	libpdal_base.so:math/pdal
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYNUMPY}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		compiler:c++11-lang ninja:build python:3.6+
USE_PYTHON=	autoplist cython distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/libpdalpython*.so

do-test:
	@cd ${WRKSRC} && py.test -v test

.include <bsd.port.mk>
