PORTNAME=	PySCIPOpt
DISTVERSIONPREFIX=	v
DISTVERSION=	5.2.1
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

# tests as of 5.2.1: 292 passed, 107 skipped, 11 xfailed, 3 warnings in 106.41s (0:01:46)

.include <bsd.port.mk>
