PORTNAME=	sse-starlette
DISTVERSIONPREFIX=	v
DISTVERSION=	3.5.0
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
		${PYTHON_PKGNAMEPREFIX}httpx2>=2.12.0:www/py-httpx2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}portend>0:net/py-portend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=7.0.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.25.0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=9.0.0:devel/py-tenacity@${PY_FLAVOR}
# testcontainers>=4.9.0 is not yet ported

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	sysid

NO_ARCH=	yes

TEST_ARGS=	-p no:pytest-qt -p no:aiomisc -p no:flask -p no:flaky --ignore=tests/integration --ignore=tests/experimentation

# tests as of 3.5.0: 92 passed in 29.69s

.include <bsd.port.mk>
