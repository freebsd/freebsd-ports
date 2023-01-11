PORTNAME=	qiskit-optimization
DISTVERSION=	0.4.0-3
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g750c2c8
CATEGORIES=	science python # quantum-computing
#MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Optimization submodule of the Quiskit framework for quantum computing
WWW=		https://qiskit.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docplex>=2.21.207:math/py-docplex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>=2.2:math/py-networkx@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.4:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-terra>=0.20.0:science/py-qiskit-terra@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cvxpy>0:math/py-cvxpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qiskit-aer>0:science/py-qiskit-aer@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
