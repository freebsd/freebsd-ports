PORTNAME=	aiohttp-cors
PORTVERSION=	0.8.1
CATEGORIES=	www python
MASTER_SITES=	PYPI \
		https://github.com/aio-libs/aiohttp-cors/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	aiohttp_cors-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CORS support for aiohttp
WWW=		https://github.com/aio-libs/aiohttp-cors

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.9:www/py-aiohttp@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
