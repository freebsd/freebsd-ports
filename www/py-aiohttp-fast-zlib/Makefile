PORTNAME=	aiohttp-fast-zlib
DISTVERSION=	0.3.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	aiohttp_fast_zlib-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast zlib compatibility layer for aiohttp
WWW=		https://github.com/bluetooth-devices/aiohttp-fast-zlib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=2.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.9.0:www/py-aiohttp@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
