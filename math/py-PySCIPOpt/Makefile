PORTNAME=	PySCIPOpt
DISTVERSIONPREFIX=	v
DISTVERSION=	6.3.0
CATEGORIES=	math python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface and modeling environment for SCIP
WWW=		https://github.com/SCIP-Interfaces/PySCIPOpt

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
LIB_DEPENDS=	libscip.so:math/SCIP
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	autoplist cython distutils pytest # 1 test fails, see https://github.com/scipopt/PySCIPOpt/issues/840

USE_GITHUB=	yes
GH_ACCOUNT=	scipopt

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyscipopt/scip*.so

# tests as of 6.3.0: 464 passed, 108 skipped, 11 xfailed in 77.57s (0:01:17)

.include <bsd.port.mk>
