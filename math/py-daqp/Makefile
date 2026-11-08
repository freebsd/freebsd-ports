PORTNAME=	daqp
DISTVERSION=	0.10.3
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	DAQP: A dual active-set QP solver
WWW=		https://github.com/darnstrom/daqp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils cython autoplist

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/daqp${PYTHON_TAG}.so

do-test:
	@${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/test.py

# tests as of 0.10.3: solution: xstar=[-1. -1.] fval=-1.0 exitflag=1 info={'solve_time': 4e-08, 'setup_time': 0.000244963, 'iterations': 1, 'nodes': 1, 'lam': array([0., 0., 0., 0.])}

.include <bsd.port.mk>
