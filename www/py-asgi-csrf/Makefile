PORTNAME=	asgi-csrf
DISTVERSION=	0.11
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ASGI middleware for protecting against CSRF attacks
WWW=		https://github.com/simonw/asgi-csrf

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}itsdangerous>0:security/py-itsdangerous@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-multipart>=0.0.13:www/py-python-multipart@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asgi-lifespan>0:devel/py-asgi-lifespan@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>0:www/py-starlette@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest # setup.py has test dependencies, but there are no tests in the repository, see https://github.com/simonw/asgi-csrf/issues/23

NO_ARCH=	yes

# tests as of 0.11: 48 passed, 1 warning in 0.59s

.include <bsd.port.mk>
