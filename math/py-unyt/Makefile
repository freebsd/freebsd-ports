PORTNAME=	unyt
DISTVERSION=	3.1.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for handling numpy arrays with units
WWW=		https://github.com/yt-project/unyt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.11,<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.21.3:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.9:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sympy>=1.9.0:math/py-sympy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-doctestplus>=1.4.0:devel/py-pytest-doctestplus@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		PYTEST_DISABLE_PLUGIN_AUTOLOAD=1 \
		PYTEST_ADDOPTS="--rootdir=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} -p pytest_doctestplus"
TEST_WRKSRC=	${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/unyt/tests

# tests as of 3.1.0: 846 passed, 3 skipped, 2 xfailed, 2 failed. The 2 failures
# are in test_astropy/test_astropy_dimensionless and are caused by the installed
# astro/py-astropy package referencing np.in1d, which was removed in NumPy 2.x.

.include <bsd.port.mk>
