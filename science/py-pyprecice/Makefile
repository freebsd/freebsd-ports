PORTNAME=	pyprecice
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.0.0
CATEGORIES=	science # physics
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Coupling library for partitioned multi-physics simulations

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}mpi4py>0:net/py-mpi4py@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
LIB_DEPENDS=	libprecice.so:science/precice
RUN_DEPENDS=	${PY_DEPENDS}

USES=		localbase python:3.6+
USE_PYTHON=	distutils cython autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	precice
GH_PROJECT=	python-bindings

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cyprecice.cpython-${PYTHON_SUFFIX}.so

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
