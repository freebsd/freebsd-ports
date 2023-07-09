PORTNAME=	httpx-cache
PORTVERSION=	0.11.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	httpx_cache-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple caching transport for httpx
WWW=		https://obendidi.github.io/httpx-cache/ \
		https://github.com/obendidi/httpx-cache

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiorwlock>=1.2<2:devel/py-aiorwlock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}anyio>=3.0<4:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=21.4:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fasteners>=0.16.3:devel/py-fasteners@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.23:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=1.0<2:devel/py-msgpack@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	REDIS

REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=4.5<5:databases/py-redis@${PY_FLAVOR}

.include <bsd.port.mk>
