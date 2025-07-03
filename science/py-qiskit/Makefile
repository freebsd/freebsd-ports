PORTNAME=	qiskit
DISTVERSION=	2.0.0
PORTREVISION=	2
CATEGORIES=	science python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open-source SDK for working with quantum computers
WWW=		https://github.com/Qiskit/qiskit

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools-rust>0:devel/py-setuptools-rust@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}symengine>0.11:math/py-symengine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rustworkx>=0.15.0:math/py-rustworkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dill>=0.3:devel/py-dill@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=0:devel/py-stevedore@${PY_FLAVOR}

USES=		cargo python
USE_PYTHON=	autoplist distutils pytest

USE_GITHUB=	yes
GH_ACCOUNT=	Qiskit

BINARY_ALIAS=	python3=${PYTHON_CMD}

PLIST_FILES+=	${PYTHON_SITELIBDIR}/qiskit/_accelerate.cpython-${PYTHON_SUFFIX}.so

CARGO_BUILD=	no
CARGO_INSTALL=	no

.include <bsd.port.mk>
