PORTNAME=	skops
DISTVERSION=	0.16.0
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of tools related to machine learning in production
WWW=		https://skops.readthedocs.io/en/stable \
		https://github.com/skops-dev/skops

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-vcs>0:devel/py-hatch-vcs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=9:devel/py-setuptools-scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.25.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=17.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>=3.9:devel/py-prettytable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.2:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.10.0:science/py-scipy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist concurrent

MAKE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION=${DISTVERSION}

NO_ARCH=	yes

.include <bsd.port.mk>
