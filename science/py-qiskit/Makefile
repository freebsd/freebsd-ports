PORTNAME=	qiskit
DISTVERSION=	2.5.1
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Open-source SDK for working with quantum computers
WWW=		https://www.ibm.com/quantum/qiskit \
		https://github.com/Qiskit/qiskit

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	compilation fails: error[E0277]: the trait bound `u64: Index` is not satisfied, see https://codeberg.org/sarah-quinones/faer/issues/283

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-rust>=1.13.0:devel/py-setuptools-rust@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}symengine>0.11:math/py-symengine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rustworkx>=0.15.0:math/py-rustworkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dill>=0.3:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=0:devel/py-stevedore@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

BINARY_ALIAS=	python3=${PYTHON_CMD}

CARGO_BUILD=	no
CARGO_INSTALL=	no

pre-build:
	@${ECHO_CMD} "===> Unified hashbrown version to resolve pyo3 conflict"
	@cd ${WRKSRC} && ${CARGO} update -p hashbrown@0.12.3 --precise 0.15.5
	@cd ${WRKSRC} && ${CARGO} update -p hashbrown@0.14.5 --precise 0.15.5
	@cd ${WRKSRC} && ${CARGO} update -p hashbrown@0.17.1 --precise 0.15.5

.include <bsd.port.mk>
