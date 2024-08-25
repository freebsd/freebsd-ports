PORTNAME=	Pyomo
DISTVERSION=	6.8.0
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python Optimization Modeling Objects
WWW=		https://github.com/Pyomo/pyomo

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libCbc.so:math/cbc # this library is loaded dynamically
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ply>0:devel/py-ply@${PY_FLAVOR} \
		glpsol:math/glpk
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybind11>0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-parallel>0:devel/py-pytest-parallel@${PY_FLAVOR}
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}docplex>0:math/py-docplex@${PY_FLAVOR} \
		casadi>0:math/casadi \
		ipopt:math/ipopt

USES=		python
USE_PYTHON=	distutils cython concurrent autoplist pytest # 29 tests fail, see https://github.com/Pyomo/pyomo/issues/3294

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

USE_GITHUB=	yes
GH_PROJECT=	pyomo

NO_ARCH=	yes

BINARY_ALIAS=	python=${PYTHON_CMD} # for tests

.include <bsd.port.mk>
