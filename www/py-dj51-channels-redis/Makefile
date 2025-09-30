PORTNAME=	channels-redis
PORTVERSION=	4.3.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}dj51-
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Redis-backed asgi channel layer implementation
WWW=		http://github.com/django/channels_redis/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Extended support of Django 5.1 ends December 2025, upgrade to the Django 5.2+ version of this port. See https://www.djangoproject.com/download/
EXPIRATION_DATE=2025-12-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}redis>=5.0.1:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=1:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asgiref>=3.7.2:www/py-asgiref@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-channels>=4:www/py-dj51-channels@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
