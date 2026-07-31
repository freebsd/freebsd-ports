PORTNAME=	trx-python # this project is planned to be merged into DIPY (science/py-dipy)
DISTVERSION=	0.4.0
CATEGORIES=	science python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Experiments with new file format for tractography
WWW=		https://tee-ar-ex.github.io/trx-python/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=7:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}deepdiff>0:devel/py-deepdiff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nibabel>=5:science/py-nibabel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.22:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.9:devel/py-typer@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=7:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-console-scripts>=0:devel/py-pytest-console-scripts@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 cython autoplist pytest # few tests fail due to missing files

#USE_GITHUB=	yes
#GH_ACCOUNT=	tee-ar-ex

NO_ARCH=	yes
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	-p no:relaxed

# tests as of 0.4.0: 138 passed, 25 skipped, 2 xfailed in 6.53s

.include <bsd.port.mk>
