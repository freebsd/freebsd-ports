PORTNAME=	OpenFermion
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.1
PORTREVISION=	1
CATEGORIES=	science python # quantum-computing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Electronic structure package for quantum computers
WWW=		https://github.com/quantumlib/OpenFermion

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cirq-core>=1.0:science/py-cirq-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cirq-google>=0.15.0:science/py-cirq-google@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}deprecation>0:devel/py-deprecation@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h5py>=2.8:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}PubChemPy>0:science/py-PubChemPy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.18:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.1.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nbformat>0:devel/py-nbformat@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest # 1 tests fails, see https://github.com/quantumlib/OpenFermion/issues/879

USE_GITHUB=	yes
GH_ACCOUNT=	quantumlib

NO_ARCH=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD} # only for tests

# tests as of 1.7.1: 2 failed, 2157 passed, 60 skipped, 218 warnings in 3296.13s (0:54:56)

.include <bsd.port.mk>
