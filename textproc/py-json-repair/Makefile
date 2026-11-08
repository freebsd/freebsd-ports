PORTNAME=	json-repair
DISTVERSIONPREFIX=	v
DISTVERSION=	0.64.0
CATEGORIES=	textproc python
#MASTER_SITES=	PYPI # missing file for tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package to repair broken json strings
WWW=		https://github.com/mangiucugna/json_repair/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.44.0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask-cors>0:www/py-flask-cors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-benchmark>0:devel/py-pytest-benchmark@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	mangiucugna
GH_PROJECT=	${PORTNAME:S/-/_/}

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} CI=1
TEST_ARGS=	--disable-plugin-autoload -p benchmark

# tests as of 0.64.0: 398 passed, 16 skipped (performance/timing tests skipped in CI mode)

.include <bsd.port.mk>
