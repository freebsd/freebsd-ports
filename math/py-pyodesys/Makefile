PORTNAME=	pyodesys
DISTVERSION=	0.14.4
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Straightforward numerical integration of ODE systems from Python
WWW=		https://github.com/bjodah/pyodesys

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=2.2.5:math/py-matplotlib@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}notebook>=5.7.8:www/py-notebook@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.2.3:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sym>=0.3.4:math/py-sym@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.5.1:math/py-sympy@${PY_FLAVOR}
TEST_DEPENDS=	${LOCALBASE}/include/boost/numeric/ublas/matrix.hpp:devel/boost-libs \
		${LOCALBASE}/include/gsl/gsl_errno.h:math/gsl

USES=		display:test localbase:ldflags python shebangfix
USE_PYTHON=	distutils autoplist pytest

SHEBANG_GLOB=	*.py

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=		EXTRAS
OPTIONS_DEFAULT=	EXTRAS

EXTRAS_DESC=		Install optional dependencies for additional functionality
EXTRAS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>0:devel/py-appdirs@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pycodeexport>=0.1.2:devel/py-pycodeexport@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pycompilation>=0.4.9:devel/py-pycompilation@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pygslodeiv2>=0.9.1:math/py-pygslodeiv2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pyodeint>=0.10.1:math/py-pyodeint@${PY_FLAVOR}
			# TODO pycvodes>=0.13.1 - doesn't build with sundials

.include <bsd.port.mk>
