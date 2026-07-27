PORTNAME=	crewai
PORTVERSION=	1.15.7
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework for orchestrating role-playing, autonomous AI agents
WWW=		https://crewai.com \
		https://docs.crewai.com \
		https://github.com/crewAIInc/crewAI

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiofiles>0:devel/py-aiofiles@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiosqlite>0:databases/py-aiosqlite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}appdirs>=1.4.4:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cel-python>=0.5.0:devel/py-cel-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chromadb>=1.1.0:databases/py-chromadb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8.1.7:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}crewai-cli>=1.15.7:misc/py-crewai-cli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}crewai-core>=1.15.7:misc/py-crewai-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}instructor>=1.3.3:misc/py-instructor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}json-repair>=0.60.1:textproc/py-json-repair@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}json5>=0.10.0:devel/py-json5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonref>=1.1.0:devel/py-jsonref@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lancedb>=0.29.2:databases/py-lancedb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mcp>0:misc/py-mcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openai>=2.30.0:misc/py-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.1.5:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.42.0:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-exporter-otlp-proto-http>=1.42.0:devel/py-opentelemetry-exporter-otlp-proto-http@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-sdk>=1.42.0:devel/py-opentelemetry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdfplumber>=0.11.4:graphics/py-pdfplumber@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}portalocker>=2.7.0:devel/py-portalocker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>=2.14.2:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.11.9:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.13.0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=1.2.2:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>=2026.1.15:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tokenizers>=0.21:textproc/py-tokenizers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli-w>=1.1.0:textproc/py-tomli-w@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>=2.0.2:textproc/py-tomli@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-recording>=0:devel/py-pytest-recording@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vcrpy>=0:devel/py-vcrpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

# CLI templates ship Jinja-like placeholders in .py files and cannot be
# byte-compiled during staging.
PEP517_INSTALL_CMD=	${PYTHON_CMD} -m installer --no-compile-bytecode \
			--destdir ${STAGEDIR} --prefix ${PREFIX} \
			${BUILD_WRKSRC}/dist/${PORTNAME:C|[-_]+|_|g}-${DISTVERSION}*.whl

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} CREWAI_TESTING=true
TEST_WRKSRC=	${WRKSRC}/tests
TEST_ARGS=	-m 'not vcr' \
		--ignore=a2a \
		--ignore=agents/test_agent_a2a_wrapping.py \
		--ignore=agents/test_agent_executor.py \
		--ignore=agents/test_crew_agent_parser.py \
		--ignore=agents/test_native_tool_calling.py \
		--ignore=cli/test_plus_api.py \
		--ignore=crew/test_async_crew.py \
		--ignore=events/test_event_context.py \
		--ignore=events/test_llm_finish_reason_response_id.py \
		--ignore=llms/anthropic \
		--ignore=llms/azure \
		--ignore=llms/google \
		--ignore=llms/hooks \
		--ignore=llms/openai \
		--ignore=llms/test_multimodal.py \
		--ignore=llms/test_multimodal_integration.py \
		--ignore=llms/test_prompt_cache.py \
		--ignore=memory \
		--ignore=mcp \
		--ignore=rag/chromadb \
		--ignore=rag/qdrant/test_client.py \
		--ignore=tracing/test_tracing.py \
		--ignore=test_agent_multimodal.py \
		--ignore=test_crew.py \
		--ignore=test_crew_multimodal.py \
		--ignore=test_flow_multimodal.py \
		--ignore=test_llm.py \
		--ignore=test_llm_streaming_finish_reason.py \
		--ignore=test_project.py \
		--ignore=tools/agent_tools/test_read_file_tool.py \
		--ignore=utilities/test_converter.py \
		--ignore=utilities/test_file_store.py \
		--ignore=utilities/test_files.py \
		--deselect=tests/agents/test_agent.py::test_agent_from_repository \
		--deselect=tests/agents/test_agent.py::test_agent_from_repository_override_attributes \
		--deselect=tests/agents/test_agent.py::test_agent_from_repository_with_invalid_tools \
		--deselect=tests/agents/test_agent.py::test_agent_with_callbacks \
		--deselect=tests/agents/test_agent.py::test_crew_agent_executor_litellm_auth_error \
		--deselect=tests/agents/test_agent.py::test_litellm_anthropic_error_handling \
		--deselect=tests/agents/test_lite_agent.py::test_agent_kickoff_with_files_parameter \
		--deselect=tests/agents/test_lite_agent.py::test_prepare_kickoff_extracts_files_from_messages \
		--deselect=tests/agents/test_lite_agent.py::test_prepare_kickoff_merges_files_from_messages_and_parameter \
		--deselect=tests/agents/test_lite_agent.py::test_prepare_kickoff_param_files_override_message_files \
		--deselect=tests/llms/bedrock/test_bedrock.py::test_bedrock_raises_error_when_model_not_found \
		--deselect=tests/test_flow_conversation.py::TestDeferredFlowLifecycleEvents::test_finalize_batch_is_idempotent \
		--deselect=tests/test_flow_from_definition.py::test_crew_action_repository_fetch_does_not_block_event_loop \
		--deselect=tests/utilities/events/test_shutdown.py::test_concurrent_access_during_shutdown_flag \
		--deselect=tests/utilities/events/test_shutdown.py::test_mixed_sync_async_handler_execution \
		--deselect=tests/utilities/events/test_thread_safety.py::test_concurrent_emit_and_registration

# tests as of 1.15.7: 2477 passed, 27 skipped, 254 deselected, 1661 warnings in 40.00s

.include <bsd.port.mk>
