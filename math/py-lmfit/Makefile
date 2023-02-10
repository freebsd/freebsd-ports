PORTNAME=	lmfit
DISTVERSION=	1.0.3
CATEGORIES=	math
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Least-squares Minimization with bounds and constraints
WWW=		https://lmfit.github.io/lmfit-py/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asteval>=0.9.22:devel/py-asteval@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.4:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uncertainties>=3.0.1:math/py-uncertainties@${PY_FLAVOR}
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numdifftools>0:math/py-numdifftools@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist pytest # 3 tests fail, upstream says that that's ok, see https://github.com/lmfit/lmfit-py/issues/802

NO_ARCH=	yes

.include <bsd.port.mk>
