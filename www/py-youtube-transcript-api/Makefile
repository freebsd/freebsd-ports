PORTNAME=	youtube-transcript-api
DISTVERSION=	1.2.5
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSIONFULL}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python module for YouTube Transcript/Subtitle API
WWW=		https://github.com/jdepoix/youtube-transcript-api

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.9.1:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0.7.1:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.3:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=7.16.0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>=0.26.3:devel/py-responses@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

# tests: 78 passed, 5 skipped
TEST_ENV=	PYTEST_DISABLE_PLUGIN_AUTOLOAD=1 \
		PYTHONPATH="${STAGEDIR}${PYTHON_SITELIBDIR}"

NO_ARCH=	yes

.include <bsd.port.mk>
