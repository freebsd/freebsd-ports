PORTNAME=	openai
DISTVERSION=	3.50.0
CATEGORIES=	misc # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python client library for the OpenAI API
WWW=		https://github.com/openai/openai-python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=4.10.0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx2>=2.12.0:www/py-httpx2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jiter>=0.16.0:textproc/py-jiter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=1.10.13:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sniffio>0:devel/py-sniffio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.14:devel/py-typing-extensions@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}numpy>=1:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>=1.2.3:math/py-pandas@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}azure-identity>0:devel/py-azure-identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}griffe>=1:textproc/py-griffe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inline-snapshot>=0.28.0:devel/py-inline-snapshot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=1.4.0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.6.1:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=13.7.1:textproc/py-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trio>=0.22.2:net/py-trio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest # tests fail because api_key needs to be set

TEST_ENV=	${MAKE_ENV} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		OPENAI_API_KEY=sk-test
# websocket tests that do not work with websockets 17 (upstream requires websockets<16)
_WEBSOCKET_TESTS=	tests/lib/live/test_delegation_transport.py \
		tests/lib/live/test_sideband_events.py \
		tests/lib/live/test_websocket_roles.py \
		tests/lib/responses/test_azure_responses_policy_regression.py \
		tests/lib/responses/test_parsed_output_replay_profile.py \
		tests/lib/responses/test_refusal_normal_lifecycle.py \
		tests/lib/responses/test_websocket_accumulator.py \
		tests/lib/responses/test_websocket_accumulator_details.py \
		tests/lib/responses/test_websocket_auth.py \
		tests/lib/responses/test_websocket_contract.py \
		tests/lib/responses/test_websocket_preconnect.py \
		tests/lib/responses/test_websocket_session.py \
		tests/lib/responses/test_websocket_session_overflow.py \
		tests/lib/test_azure_request_credentials.py \
		tests/lib/test_azure_websocket_redirects.py \
		tests/lib/test_beta_realtime_auth_policy.py \
		tests/lib/test_beta_realtime_headers.py \
		tests/lib/test_beta_realtime_websocket_options.py \
		tests/lib/test_generated_websocket_compression.py \
		tests/lib/test_realtime_reference_inputs.py \
		tests/lib/test_realtime_translation.py \
		tests/lib/test_realtime_translation_close.py \
		tests/lib/test_realtime_websocket_contract.py \
		tests/lib/test_realtime_websocket_recovery.py \
		tests/lib/test_request_credentials.py \
		tests/lib/test_websocket_query_serialization.py \
		tests/lib/test_websocket_redirects.py \
		tests/lib/test_websocket_urls.py \
		tests/test_websocket_raw_reconnect_wire.py
TEST_ARGS=	--disable-plugin-autoload \
		-p inline_snapshot \
		-p pytest_asyncio.plugin \
		-p xdist.plugin \
		-p anyio \
		--ignore=tests/api_resources \
		--ignore=tests/test_uv_workflows.py \
		--ignore=tests/lib/test_fine_tuning_positional_arguments.py \
		--ignore=tests/lib/chat/test_completions_streaming.py \
		--ignore=tests/test_tls_hostname.py \
		${_WEBSOCKET_TESTS:C/^/--ignore=/}

NO_ARCH=	yes

# tests as of 3.50.0: 9665 passed, 59 skipped in 89.70s
# (ignored tests require a live OpenAI API endpoint, uv-specific CI fixtures, or websockets<16)

.include <bsd.port.mk>
