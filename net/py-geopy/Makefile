# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	geopy
PORTVERSION=	2.1.0
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python Geocoding Toolbox

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	geographiclib>=1.49<2:astro/geographiclib
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}async_generator>=0:devel/py-async_generator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=3.10:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-aiohttp>=0:devel/py-pytest-aiohttp@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	AIOHTTP REQUESTS TIMEZONE
AIOHTTP_DESC=	Async HTTP adapter support
REQUESTS_DESC=	Requests adapter support
TIMEZONE_DESC=	Locate timezones

AIOHTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=0:www/py-aiohttp@${PY_FLAVOR}
REQUESTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.16.2:www/py-requests@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}urllib3>=1.24.2,1:net/py-urllib3@${PY_FLAVOR}
TIMEZONE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR}

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
