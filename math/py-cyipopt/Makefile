PORTNAME=	cyipopt
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.0
CATEGORIES=	math python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Cython interface for the interior point optimizer IPOPT
WWW=		https://github.com/mechmotum/cyipopt

LICENSE=	EPL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.26.4:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	libblas.so:math/blas \
		libipopt.so:math/ipopt \
		liblapack.so:math/lapack
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.26.4:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>0:science/py-scipy@${PY_FLAVOR}

USES=		fortran python pkgconfig # fortran because ipopt's pkg-config returns gcc libs
USE_PYTHON=	distutils cython autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	mechmotum

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		PYTEST_ADDOPTS="-p no:black -p no:ruff -p no:mypy -p no:flake8 -p no:cov -p no:benchmark -p no:inline-snapshot -p no:xdist -p no:randomly"

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/cyipopt/ipopt_wrapper${PYTHON_TAG}.so

do-test:
	@cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/cyipopt/tests && \
		${SETENV} ${TEST_ENV} pytest .

# tests as of 1.7.0: 104 passed, 3 skipped, 1 xpassed in 3.71s

.include <bsd.port.mk>
