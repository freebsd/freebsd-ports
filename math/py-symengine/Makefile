PORTNAME=	symengine
DISTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python library providing wrappers to SymEngine
WWW=		https://symengine.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsymengine.so:math/symengine
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR} # see https://github.com/symengine/symengine.py/issues/416

USES=		cmake compiler:c++11-lang python:3.7+
USE_PYTHON=	cython flavors pytest

BINARY_ALIAS=	python=${PYTHON_CMD} # cmake scripts expect python executable

# cmake scripts copy build type and flags from math/symengine, and ignore all local variables of that kind

.include <bsd.port.mk>
