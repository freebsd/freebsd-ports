PORTNAME=	lmfit
DISTVERSION=	1.3.3
CATEGORIES=	math
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Least-squares Minimization with bounds and constraints
WWW=		https://lmfit.github.io/lmfit-py/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PY_DEPENDS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asteval>=1.0:devel/py-asteval@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dill>=0.3.4:devel/py-dill@${PY_FLAVOR} \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.10.0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uncertainties>=3.2.2:math/py-uncertainties@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flaky>0:devel/py-flaky@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# tests as of 1.3.3: 5 failed, 654 passed, 12 skipped, 16 warnings in 153.81s (0:02:33) # _tkinter.TclError: no display name and no $DISPLAY environment variable

.include <bsd.port.mk>
