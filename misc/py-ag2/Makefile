PORTNAME=	ag2
DISTVERSION=	1.0.0
CATEGORIES=	misc python # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Programming framework for agentic AI
WWW=		https://ag2.ai/ \
		https://docs.ag2.ai \
		https://github.com/ag2ai/ag2

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>0:devel/py-uv-build@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anyio>=4.0.0:devel/py-anyio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fast-depends>=3.0.8:devel/py-fast-depends@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx>=0.28.1:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.6.1:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>0:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.2:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>0:devel/py-termcolor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tiktoken>0:textproc/py-tiktoken@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dirty-equals>=0.11:devel/py-dirty-equals@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=1.5.5:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=1.4.0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=2.4.0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}respx>=0.23.0:www/py-respx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=14.0:devel/py-websockets@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	ag2ai
GH_PROJECT=	ag2
GH_TAGNAME=	v${DISTVERSION}

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PATH=${WRKDIR}/.bin:${PATH} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}:${WRKSRC}

# The upstream test suite requires many optional providers and network access.
# Run only the core tests for now that pass without optional extras.
TEST_ARGS=	-p no:relaxed \
		--ignore=test/mcp \
		test/test_import_utils.py \
		test/test_json_utils.py \
		test/test_llm_config.py \
		test/test_import.py \
		test/test_graph_utils.py \
		test/test_logger_redaction.py \
		test/test_token_count.py \
		test/test_browser_utils.py \
		test/test_conftest.py \
		test/io \
		test/fast_depends \
		test/messages/test_base_message.py \
		test/messages/test_client_messages.py \
		test/messages/test_print_message.py \
		test/a2a \
		test/ag_ui \
		test/beta \
		test/logger

pre-test:
	@${MKDIR} ${WRKDIR}/.bin
	@${LN} -sf ${PYTHON_CMD} ${WRKDIR}/.bin/python

# tests as of 0.14.0: 3602 passed, 356 skipped, 2 xfailed, 36 warnings in 46.84s

.include <bsd.port.mk>
