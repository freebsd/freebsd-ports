PORTNAME=	sse-starlette
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.11
CATEGORIES=	www python
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Starlette: SSE plugin
WWW=		https://github.com/sysid/sse-starlette

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=4.7.0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>=0.49.1:www/py-starlette@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0.34.0:www/py-uvicorn@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asgi-lifespan>=2.1.0:devel/py-asgi-lifespan@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}portend>0:net/py-portend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=7.0.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.25.0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=9.0.0:devel/py-tenacity@${PY_FLAVOR}
		# testcontainers>=4.9.0

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	sysid

NO_ARCH=	yes

TEST_ARGS=	--ignore=tests/integration

# tests as of 3.4.6: 82 passed, 2 warnings in 42.35s

.include <bsd.port.mk>
