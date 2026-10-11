PORTNAME=	pymatreader
DISTVERSION=	1.3.2
CATEGORIES=	misc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Convenient reader for Matlab mat files
WWW=		https://gitlab.com/obob/pymatreader

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatch-regex-commit>0:devel/py-hatch-regex-commit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}h5py>=3.7:science/py-h5py@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.21.3:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=1.11:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.13:devel/py-xmltodict@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} PYTEST_DISABLE_PLUGIN_AUTOLOAD=1
TEST_ARGS=	--disable-plugin-autoload

# tests as of 1.3.2: 39 passed, 630 warnings in 11.10s

.include <bsd.port.mk>
