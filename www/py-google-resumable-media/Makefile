PORTNAME=	google-resumable-media
PORTVERSION=	1.3.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utilities for Google Media Downloads and Resumable Uploads

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-crc32c>=1.0<2.0:devel/py-google-crc32c@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	AIOHTTP REQUESTS
OPTIONS_DEFAULT=AIOHTTP REQUESTS
AIOHTTP_DESC=	Use aiohttp
REQUESTS_DESC=	Use requests

AIOHTTP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.6.2<4.0.0:www/py-aiohttp@${PY_FLAVOR}
REQUESTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.18.0:www/py-requests@${PY_FLAVOR}

.include <bsd.port.mk>
