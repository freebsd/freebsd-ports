PORTNAME=	fastmcp
DISTVERSION=	2.12.0
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI # no tarball
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast, Pythonic way to build MCP servers and clients
WWW=		https://gofastmcp.com/getting-started/welcome \
		https://github.com/jlowin/fastmcp

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv-dynamic-versioning>=0.7.0:devel/py-uv-dynamic-versioning@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}authlib>=1.5.2:security/py-authlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cyclopts>=3.0.0:devel/py-cyclopts@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}exceptiongroup>=1.2.2:devel/py-exceptiongroup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mcp>0:misc/py-mcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openai>=1.95.1:misc/py-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openapi-core>=0.19.5:devel/py-openapi-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openapi-pydantic>=0.5.1:devel/py-openapi-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyperclip>0:devel/py-pyperclip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=1.1.0:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.9.4:textproc/py-rich@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}websockets>=15.0.1:devel/py-websockets@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dirty-equals>=0.9.0:devel/py-dirty-equals@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>=0.115.12:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipython>=8.12.3:devel/ipython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.23.5:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-env>0:devel/py-pytest-env@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-httpx>0:devel/py-pytest-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.6.1:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=8.3.3:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruff>0:devel/py-ruff@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ty>0:devel/py-ty@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

BINARY_ALIAS=	python=${PYTHON_CMD}

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

# tests as of 2.12.0: 54 failed, 2580 passed, 14 xfailed, 1 xpassed, 8 warnings, 1 error in 298.28s (0:04:58), see https://github.com/jlowin/fastmcp/issues/1690

.include <bsd.port.mk>
