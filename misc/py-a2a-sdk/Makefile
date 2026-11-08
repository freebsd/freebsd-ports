PORTNAME=	a2a-sdk
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.0
CATEGORIES=	misc python # machine-learning
#MASTER_SITES=	PYPI # no tests
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python SDK for the Agent2Agent (A2A) protocol
WWW=		https://a2a-protocol.org/ \
		https://github.com/a2aproject/a2a-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uv-dynamic-versioning>0:devel/py-uv-dynamic-versioning@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}culsans>=0.11.0:devel/py-culsans@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-api-core>=1.26.0:www/py-google-api-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}googleapis-common-protos>=1.70.0:devel/py-googleapis-common-protos@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}json-rpc>=1.15.0:devel/py-json-rpc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=24.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=5.29.5:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.11.3:devel/py-pydantic2@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=4:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.26.0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=3.14.0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=2.4.0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.6.1:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}respx>=0.20.2:www/py-respx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc8785>=0.1.4:devel/py-rfc8785@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trio>0:net/py-trio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0.35.0:www/py-uvicorn@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	a2aproject
GH_PROJECT=	a2a-python

OPTIONS_DEFINE=			DB_CLI ENCRYPTION FASTAPI GRPC SIGNING SQLITE TELEMETRY
OPTIONS_DEFAULT=		${OPTIONS_DEFINE}

DB_CLI_DESC=			Alembic database CLI support
ENCRYPTION_DESC=		Encryption support via cryptography
FASTAPI_DESC=			FastAPI server support
GRPC_DESC=			gRPC transport support
SIGNING_DESC=			JWT signing support
SQLITE_DESC=			SQLite persistence support
TELEMETRY_DESC=			OpenTelemetry telemetry support

DB_CLI_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}alembic>=1.14.0:databases/py-alembic@${PY_FLAVOR}
ENCRYPTION_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}cryptography>=43.0.0:security/py-cryptography@${PY_FLAVOR}
FASTAPI_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}fastapi>=0.115.2:www/py-fastapi@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}sse-starlette>0:www/py-sse-starlette@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}starlette>0:www/py-starlette@${PY_FLAVOR}
GRPC_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}grpcio>=1.60:devel/py-grpcio@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}grpcio-tools>=1.60:devel/py-grpcio-tools@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}grpcio-reflection>=1.7.0:devel/py-grpcio-reflection@${PY_FLAVOR}
SIGNING_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.0.0:www/py-pyjwt@${PY_FLAVOR}
SQLITE_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=2.0.0:databases/py-sqlalchemy20@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}aiosqlite>0:databases/py-aiosqlite@${PY_FLAVOR}
TELEMETRY_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.33.0:devel/py-opentelemetry-api@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}opentelemetry-sdk>=1.33.0:devel/py-opentelemetry-sdk@${PY_FLAVOR}

MAKE_ENV+=	UV_DYNAMIC_VERSIONING_BYPASS=${PORTVERSION}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload \
		-p asyncio -p anyio -p pytest_mock -p timeout -p xdist \
		--ignore=tests/integration/cross_version

NO_ARCH=	yes

# tests as of 1.3.0: 2371 passed, 199 skipped, 4 xfailed, 1 xpassed, 204 warnings

.include <bsd.port.mk>
