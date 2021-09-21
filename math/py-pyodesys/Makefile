PORTNAME=	pyodesys
DISTVERSION=	0.14.1
CATEGORIES=	math python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Straightforward numerical integration of ODE systems from Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=2.2.5:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}notebook>=5.7.8:www/py-notebook@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.2.3:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sym>=0.3.4:math/py-sym@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.5.1:math/py-sympy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${LOCALBASE}/include/boost/numeric/ublas/matrix.hpp:devel/boost-libs \
		${LOCALBASE}/include/gsl/gsl_errno.h:math/gsl

USES=		localbase:ldflags python:3.7+ shebangfix
USE_PYTHON=	distutils autoplist

SHEBANG_GLOB=	*.py

NO_ARCH=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=		EXTRAS
OPTIONS_DEFAULT=	EXTRAS

EXTRAS_DESC=		Install optional dependencies for additional functionality
EXTRAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>0:devel/py-appdirs@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pycodeexport>=0.1.2:devel/py-pycodeexport@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pycompilation>=0.4.3:devel/py-pycompilation@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pygslodeiv2>=0.9.1:math/py-pygslodeiv2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyodeint>=0.10.1:math/py-pyodeint@${PY_FLAVOR}

do-test: install # Tests fail because extra-dependencies are erroneously required: https://github.com/bjodah/pyodesys/issues/97
	@cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
