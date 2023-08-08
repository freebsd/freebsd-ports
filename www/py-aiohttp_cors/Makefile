PORTNAME=	aiohttp_cors
PORTVERSION=	0.7.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	aiohttp-cors-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	CORS support for aiohttp
WWW=		https://github.com/aio-libs/aiohttp-cors

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=1.1:www/py-aiohttp@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
