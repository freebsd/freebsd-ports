PORTNAME=	PySCIPOpt
DISTVERSIONPREFIX=	v
DISTVERSION=	5.3.0
CATEGORIES=	math python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python interface and modeling environment for SCIP
WWW=		https://github.com/SCIP-Interfaces/PySCIPOpt

LICENSE=	MIT

LIB_DEPENDS=	libscip.so:math/SCIP

USES=		localbase python
USE_PYTHON=	distutils cython autoplist pytest # 1 test fails, see https://github.com/scipopt/PySCIPOpt/issues/840

USE_GITHUB=	yes
GH_ACCOUNT=	scipopt

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pyscipopt/scip*.so

# tests as of 5.3.0: 2 failed, 299 passed, 105 skipped, 11 xfailed, 308 warnings in 58.95s, see https://github.com/scipopt/PySCIPOpt/issues/951

.include <bsd.port.mk>
