PORTNAME=	unyt
DISTVERSION=	3.2.0
CATEGORIES=	math python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package for handling numpy arrays with units
WWW=		https://github.com/yt-project/unyt

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.11,<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.23.2:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=22.0:devel/py-packaging@${PY_FLAVOR} \
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
TEST_ARGS=	--disable-plugin-autoload

# tests as of 3.2.0: 823 passed, 6 skipped, 2 xfailed in 3.13s

.include <bsd.port.mk>
