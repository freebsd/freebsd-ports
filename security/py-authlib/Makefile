PORTNAME=	authlib
PORTVERSION=	1.6.3
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ultimate Python library in building OAuth and OpenID Connect servers
WWW=		https://authlib.org/ \
		https://github.com/authlib/authlib

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cryptography pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	CLIENTS DJANGO FLASK JOSE
CLIENTS_DESC=	Clients support
DJANGO_DESC=	Django support
FLASK_DESC=	Flask support
JOSE_DESC=	Jose support

CLIENTS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=0:devel/py-anyio@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}cachelib>=0:www/py-cachelib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}django42>=0:www/py-django42@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}flask>=0:www/py-flask@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}httpx>=0:www/py-httpx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}starlette>=0:www/py-starlette@${PY_FLAVOR}
DJANGO_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=0:www/py-django42@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pytest-django>=0:devel/py-pytest-django@${PY_FLAVOR}
FLASK_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flask>=0:www/py-flask@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}flask-sqlalchemy>=0:databases/py-flask-sqlalchemy@${PY_FLAVOR} \
JOSE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycryptodomex>=3.10<4:security/py-pycryptodomex@${PY_FLAVOR}

.include <bsd.port.mk>
