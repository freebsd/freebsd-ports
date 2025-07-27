PORTNAME=	mcp
DISTVERSION=	1.12.2
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python implementation of the Model Context Protocol (MCP)
WWW=		https://pypi.python.org/pypi/mcp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.27.0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv-dynamic-versioning>=0.8.2:devel/py-uv-dynamic-versioning@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=4.5:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx-sse>=0.4:www/py-httpx-sse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4.20.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multipart>=0.0.9:devel/py-multipart@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.6.0:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.10.6_2:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sse-starlette>=2.2.0:www/py-sse-starlette@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>=0.45.3:www/py-starlette@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0.34.0:www/py-uvicorn@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
