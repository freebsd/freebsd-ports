PORTNAME=	Pyomo
DISTVERSION=	6.10.1
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python Optimization Modeling Objects
WWW=		https://github.com/Pyomo/pyomo \
		https://www.pyomo.org/

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
USE_PYTHON=	distutils cython concurrent autoplist pytest # tests fail to run, see https://github.com/Pyomo/pyomo/issues/3424

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
# disable failing tests, see https://github.com/Pyomo/pyomo/issues/3999
TEST_ARGS=	--ignore=pyomo/contrib/sensitivity_toolbox/tests/test_sens.py \
		--ignore=pyomo/contrib/doe/tests \
		--ignore=examples/pyomobook/test_book_examples.py \
		--ignore=pyomo/contrib/parmest/tests \
		--ignore=doc/OnlineDocs/tests/test_examples.py \
		--ignore=pyomo/contrib/pyros/tests/test_grcs.py \
		--ignore=pyomo/environ/tests/test_environ.py \
		--ignore=pyomo/common/tests/test_tee.py \
		--ignore=pyomo/common/tests/test_log.py \
		--ignore=pyomo/common/tests/test_deprecated.py \
		--ignore=pyomo/core/tests/examples/test_pyomo.py \
		--ignore=pyomo/contrib/cspline_external/test/test_parameter_calculation.py \
		--ignore=pyomo/contrib/solver/tests/solvers/test_ipopt.py \
		-ignore=pyomo/dae/tests/test_colloc.py \
		--ignore=pyomo/contrib/multistart/tests/test_multi.py

USE_GITHUB=	yes
GH_PROJECT=	pyomo

NO_ARCH=	yes

BINARY_ALIAS=	python=${PYTHON_CMD} # for tests

# tests as of 6.10.1: 9321 passed, 7031 skipped, 1743 deselected, 25 xfailed, 15 warnings in 1355.67s (0:22:35) (with failing tests disabled)
# tests as of 6.10.1: 94 failed, 9857 passed, 7170 skipped, 1749 deselected, 25 xfailed, 15 warnings in 571.45s (0:09:31) (with failig tests enabled)

.include <bsd.port.mk>
