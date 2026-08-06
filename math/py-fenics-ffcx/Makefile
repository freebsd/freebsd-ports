PORTNAME=	fenics-ffcx
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	FEniCS Form Compiler for finite element forms
WWW=		https://github.com/FEniCS/ffcx

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fenics-basix>=0.11.0:math/py-fenics-basix@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fenics-ufl>=2026.1.0:math/py-fenics-ufl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.21:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numba>0:devel/py-numba@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>0:math/py-sympy@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	pep517 autoplist pytest

TEST_ENV=	${MAKE_ENV} PATH=${STAGEDIR}${PREFIX}/bin:${PATH} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	-p no:cov -p no:black -p no:mypy -p no:xdist -p no:randomly

# tests as of 0.11.0: 220 passed in 285.65s (0:04:45)

USE_GITHUB=	yes
GH_ACCOUNT=	FEniCS
GH_PROJECT=	ffcx

NO_ARCH=	yes

.include <bsd.port.mk>
