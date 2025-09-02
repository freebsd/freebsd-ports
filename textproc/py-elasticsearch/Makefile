PORTNAME=	elasticsearch
PORTVERSION=	8.19.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official Python low-level client for Elasticsearch
WWW=		https://www.elastic.co/guide/en/elasticsearch/client/python-api/current/index.html \
		https://github.com/elastic/elasticsearch-py

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}elastic-transport>=8.15.1<9:textproc/py-elastic-transport@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.0<3.0.0:www/py-requests@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

CPE_VENDOR=	elastic

OPTIONS_DEFINE=	ASYNC REQUESTS
OPTIONS_DEFAULT=REQUESTS
ASYNC_DESC=	Asynchronous support
REQUESTS_DESC=	Enable requests support

ASYNC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3<4:www/py-aiohttp@${PY_FLAVOR}
REQUESTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.4.0<3.0.0:www/py-requests@${PY_FLAVOR}

.include <bsd.port.mk>
