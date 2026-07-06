PORTNAME=	langsmith
DISTVERSION=	0.9.3
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to connect to the LangSmith LLM Tracing & Evaluation Platform
WWW=		https://smith.langchain.com/ \
		https://github.com/langchain-ai/langsmith-sdk/tree/main/python

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=3.5.0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}distro>=1.7.0:sysutils/py-distro@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.23.0:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>=3.9.14:devel/py-orjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.2:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-toolbelt>=1.0.0:www/py-requests-toolbelt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sniffio>=1.1:devel/py-sniffio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.0.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uuid-utils>=0.12.0:misc/py-uuid-utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=15.0:devel/py-websockets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xxhash>=3.0.0:devel/py-xxhash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zstandard>=0.23.0:archivers/py-zstandard@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.30.0:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-exporter-otlp-proto-http>=1.30.0:devel/py-opentelemetry-exporter-otlp-proto-http@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-sdk>=1.30.0:devel/py-opentelemetry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vcrpy>0:devel/py-vcrpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dataclasses-json>=0.6.4:devel/py-dataclasses-json@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.21.0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-dotenv>=0.5.2:devel/py-pytest-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-httpx>=0.30.0:devel/py-pytest-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-rerunfailures>=14.0:devel/py-pytest-rerunfailures@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-retry>0:devel/py-pytest-retry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-socket>=0.7.0:devel/py-pytest-socket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-subtests>=0.11.0:devel/py-pytest-subtests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=2.3.1:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.5.0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# Disable the flaky plugin (conflicts with pytest-rerunfailures/pytest-retry
# which both use the @pytest.mark.flaky marker with different kwargs).
# Ignore integration/evaluation/external tests (require API keys/network).
# Ignore google_adk and strands_agents wrapper tests (packages not available as FreeBSD ports).
TEST_ARGS=	-p no:flaky \
		--ignore=tests/evaluation \
		--ignore=tests/external \
		--ignore=tests/integration_tests \
		--ignore=tests/unit_tests/wrappers/test_google_adk.py \
		--ignore=tests/unit_tests/wrappers/test_strands_agents.py

# Skip flaky performance test that depends on timing/background thread throughput
PYTEST_IGNORED_TESTS=	test_client_gc_after_autoscale

# tests as of 0.9.3: 221 failed, 1396 passed, 84 skipped, 3 xfailed, 690 warnings, 10 errors in 554.00s (0:09:13) # failures due to missing api_key

.include <bsd.port.mk>
