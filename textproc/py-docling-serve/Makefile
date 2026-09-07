PORTNAME=	docling-serve
DISTVERSION=	1.32.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Running Docling as a service
WWW=		https://github.com/docling-project/docling-serve

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docling-core>=2.95.0:textproc/py-docling-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling-jobkit>=3.5.0:textproc/py-docling-jobkit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling-mcp>=3.2.0:textproc/py-docling-mcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling-slim>=2.126.0:textproc/py-docling-slim@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>=0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.36.0:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-exporter-otlp>=1.15.0:devel/py-opentelemetry-exporter-otlp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-exporter-prometheus>=0.57b0:devel/py-opentelemetry-exporter-prometheus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-instrumentation-fastapi>=0.57b0:devel/py-opentelemetry-instrumentation-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-sdk>=1.36.0:devel/py-opentelemetry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.21.0:net-mgmt/py-prometheus-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.10:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.4:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-multipart>=0.0.14:www/py-python-multipart@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rq>=2.4:devel/py-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scalar-fastapi>=1.0.3:www/py-scalar-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.12:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0.29.0:www/py-uvicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=14.0:devel/py-websockets@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}docling-ibm-models>0:textproc/py-docling-ibm-models@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling-parse>=7.17.0:textproc/py-docling-parse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tree-sitter>=0:devel/py-tree-sitter@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asgi-lifespan>=2.0:devel/py-asgi-lifespan@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=1.2:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-check>=2.8:devel/py-pytest-check@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.1:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKDIR=	${WRKSRC}/tests

# tests as of 1.28.0: test_ray_metrics_collector.py is ignored because the
# devel/py-ray port only ships a cp311 manylinux wheel and is not usable with
# the default python3.12 flavor.
# Several other test files are ignored because they require network access,
# local PDF files, machine-learning models, or a pytest-asyncio version newer
# than the one currently available in the Ports tree.
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_asyncio.plugin \
		-p pytest_check.plugin \
		--asyncio-mode=auto \
		--ignore=${WRKSRC}/tests/test_1-file-all-outputs.py \
		--ignore=${WRKSRC}/tests/test_1-file-async.py \
		--ignore=${WRKSRC}/tests/test_1-url-all-outputs.py \
		--ignore=${WRKSRC}/tests/test_1-url-async-ws.py \
		--ignore=${WRKSRC}/tests/test_1-url-async.py \
		--ignore=${WRKSRC}/tests/test_2-files-all-outputs.py \
		--ignore=${WRKSRC}/tests/test_2-urls-all-outputs.py \
		--ignore=${WRKSRC}/tests/test_2-urls-async-all-outputs.py \
		--ignore=${WRKSRC}/tests/test_batch_endpoint.py \
		--ignore=${WRKSRC}/tests/test_config_file_loading.py \
		--ignore=${WRKSRC}/tests/test_fastapi_endpoints.py \
		--ignore=${WRKSRC}/tests/test_file_opts.py \
		--ignore=${WRKSRC}/tests/test_health_probes.py \
		--ignore=${WRKSRC}/tests/test_orchestrator_factory_slice_parallelism.py \
		--ignore=${WRKSRC}/tests/test_otel_filtering.py \
		--ignore=${WRKSRC}/tests/test_ray_metrics_collector.py \
		--ignore=${WRKSRC}/tests/test_results_clear.py

# tests as of 1.32.0: 107 passed, 344 warnings in 14.84s

.include <bsd.port.mk>
