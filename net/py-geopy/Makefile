PORTNAME=	geopy
PORTVERSION=	2.4.1
CATEGORIES=	net python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Geocoding Toolbox
WWW=		https://github.com/geopy/geopy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	geographiclib>=1.52<3:astro/geographiclib
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}async_generator>=0:devel/py-async_generator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0,1:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-aiohttp>=0:devel/py-pytest-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0,1:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.16.2:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>=1.24.2,1:net/py-urllib3@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils pytest

NO_ARCH=	yes

OPTIONS_DEFINE=	AIOHTTP REQUESTS TIMEZONE
AIOHTTP_DESC=	Async HTTP adapter support
REQUESTS_DESC=	Requests adapter support
TIMEZONE_DESC=	Locate timezones

AIOHTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=0:www/py-aiohttp@${PY_FLAVOR}
REQUESTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.16.2:www/py-requests@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}urllib3>=1.24.2,1:net/py-urllib3@${PY_FLAVOR}
TIMEZONE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>=0,1:devel/py-pytz@${PY_FLAVOR}

.include <bsd.port.mk>
