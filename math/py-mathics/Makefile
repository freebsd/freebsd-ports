# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	Mathics
PORTVERSION=	1.1.0
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	General-purpose computer algebra system (CAS)

LICENSE=	GPLv3

BUILD_DEPENDS=	${PYNUMPY}	\
		${PYTHON_PKGNAMEPREFIX}cython>0:lang/cython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}	\
		${PYTHON_PKGNAMEPREFIX}py>0:devel/py-py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cython>0:lang/cython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pint>0:devel/py-pint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mpmath>0:math/py-mpmath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>0:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nltk>0:textproc/py-nltk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydot>0:graphics/py-pydot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django31>0:www/py-django31@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langid>0:textproc/py-langid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}llvmlite>0:devel/py-llvmlite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>0:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enchant>0:textproc/py-enchant@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}palettable>0:misc/py-palettable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipykernel5>0:devel/py-ipykernel5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipywidgets>0:devel/py-ipywidgets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycountry>0:textproc/py-pycountry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-image>0:graphics/py-scikit-image@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>0:devel/py-pluggy@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME:tl}

USES=		python:3.6+ shebangfix
USE_PYTHON=	distutils
SHEBANG_GLOB=	*.py

MAKE_ENV+=	PYTHON=${PYTHON_CMD}
TEST_TARGET=	djangotest check
TEST_ENV=	${MAKE_ENV}

do-test: install
	(cd ${TEST_WRKSRC} &&	\
	${SETENV} ${TEST_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${TEST_TARGET})

.include <bsd.port.mk>
