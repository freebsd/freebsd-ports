PORTNAME=	langchain-core
DISTVERSION=	1.6.2
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LangChain: Building applications with LLMs through composability
WWW=		https://python.langchain.com/docs/introduction/ \
		https://github.com/langchain-ai/langchain

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonpatch>=1.33.0:devel/py-jsonpatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langchain-protocol>=0.0.19:misc/py-langchain-protocol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langsmith>=0.3.45:misc/py-langsmith@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.2.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.7.4:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.3.0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tenacity>=8.1.0:devel/py-tenacity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.7.0:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uuid-utils>=0.12.0:misc/py-uuid-utils@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}blockbuster>=1.5.18:devel/py-blockbuster@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=1.2.2:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grandalf>=0.8.0:math/py-grandalf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langchain-tests>=1.1.9:misc/py-langchain-tests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.26.4:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=9.0.3:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=1.3.0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-benchmark>0:devel/py-pytest-benchmark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-codspeed>0:devel/py-pytest-codspeed@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=3.10.0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-socket>=0.7.0:devel/py-pytest-socket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-watcher>=0.3.4:devel/py-pytest-watcher@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.6.1:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>=0.25.0:devel/py-responses@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}syrupy>=5.0.0:devel/py-syrupy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# tests fail with: INTERNALERROR> ValueError: no option named 'only_extended'
# Deselect tests that require network access, DNS resolution, blocking calls,
# or specific upstream dependencies not available in the FreeBSD test environment.
# the TEST_ARGS_part args should be added but they cause failures "blockbuster.blockbuster.BlockingError: Blocking call to os.read"
# for some obscure reason.
TEST_ARGS_part=	--disable-plugin-autoload \
                -p blockbuster \
                -p freezegun \
                -p langchain_tests \
                -p pytest_asyncio.plugin \
                -p pytest_benchmark.plugin \
                -p pytest_codspeed.plugin \
                -p pytest_mock \
                -p pytest_socket \
                -p responses \
                -p xdist \
                -p syrupy \
                --asyncio-mode=auto
TEST_ARGS=	--deselect=tests/unit_tests/language_models/chat_models/test_base.py::test_invocation_params_passed_to_tracer_metadata \
		--deselect=tests/unit_tests/language_models/chat_models/test_base.py::test_astream_events_v3_invocation_params_passed_to_tracer_metadata \
		--deselect=tests/unit_tests/language_models/chat_models/test_base.py::test_user_lc_versions_metadata_survives_merge_astream \
		--deselect=tests/unit_tests/runnables/test_fallbacks.py::test_fallbacks[chain] \
		--deselect=tests/unit_tests/runnables/test_fallbacks.py::test_fallbacks[llm_multi] \
		--deselect=tests/unit_tests/runnables/test_fallbacks.py::test_fallbacks[llm] \
		--deselect=tests/unit_tests/test_ssrf_protection.py::TestValidateSafeUrl::test_dns_resolution_failure \
		--deselect=tests/unit_tests/runnables/test_runnable.py::test_prompt_with_chat_model_and_parser \
		--deselect=tests/unit_tests/runnables/test_runnable.py::test_prompt_with_llm_parser \
		--deselect=tests/unit_tests/runnables/test_runnable.py::test_prompt_with_llm_and_async_lambda \
		--deselect=tests/unit_tests/runnables/test_runnable.py::test_seq_dict_prompt_llm \
		--deselect=tests/unit_tests/runnables/test_runnable.py::test_prompt_with_chat_model \
		--deselect=tests/unit_tests/runnables/test_runnable.py::test_prompt_with_chat_model_async \
		--deselect=tests/unit_tests/runnables/test_runnable.py::test_seq_prompt_map \
		--deselect=tests/unit_tests/runnables/test_runnable.py::test_combining_sequences \
		--deselect=tests/unit_tests/runnables/test_runnable.py::test_prompt_with_llm \
		--deselect=tests/unit_tests/runnables/test_runnable.py::test_router_runnable \
		--deselect=tests/unit_tests/runnables/test_runnable.py::test_each \
		--deselect=tests/unit_tests/runnables/test_runnable.py::test_seq_prompt_dict \
		--deselect=tests/unit_tests/utils/test_function_calling.py::test_convert_to_openai_function_nested_v2

# tests as of 1.6.2: 2276 passed, 1 skipped, 9 xfailed, 5 warnings in 25.55s

.include <bsd.port.mk>
