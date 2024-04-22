PORTNAME=	channels-redis
PORTVERSION=	4.2.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj42-
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Redis-backed asgi channel layer implementation
WWW=		http://github.com/django/channels_redis/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=5.0.1:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=1:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asgiref>=3.7.2:www/py-asgiref@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-channels>=4:www/py-dj42-channels@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
