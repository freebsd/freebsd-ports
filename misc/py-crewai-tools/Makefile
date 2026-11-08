PORTNAME=	crewai-tools
DISTVERSION=	1.15.34
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of tools for the CrewAI framework
WWW=		https://crewai.com \
		https://docs.crewai.com \
		https://github.com/crewAIInc/crewAI

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=4.13.4:www/py-beautifulsoup4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}crewai==1.15.34:misc/py-crewai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymupdf>=1.26.6:print/py-PyMuPDF@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-docx>=1.2.0:textproc/py-python-docx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytube>=15.0.0:multimedia/py-pytube@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.33.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tiktoken>=0.8.0:textproc/py-tiktoken@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}youtube-transcript-api>=1.2.2:www/py-youtube-transcript-api@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PyGithub>0:devel/py-PyGithub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oracledb>=2.2.0:databases/py-oracledb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} OPENAI_API_KEY=dummy
TEST_WRKSRC=	${WRKSRC}/tests
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_asyncio.plugin
TEST_ARGS+=	--ignore=adapters/mcp_adapter_test.py # requires a running MCP server
TEST_ARGS+=	--ignore=base_tool_test.py # tool schema assertions fail with current pydantic/crewai versions
TEST_ARGS+=	--ignore=tools/brave_search_tool_test.py # requires Brave Search API key
TEST_ARGS+=	--ignore=tools/couchbase_tool_test.py # requires couchbase extra
TEST_ARGS+=	--ignore=tools/files_compressor_tool_test.py # depends on optional compression utilities
TEST_ARGS+=	--ignore=tools/firecrawl_crawl_website_tool_test.py # requires firecrawl-py extra
TEST_ARGS+=	--ignore=tools/firecrawl_scrape_website_tool_test.py # requires firecrawl-py extra
TEST_ARGS+=	--ignore=tools/firecrawl_search_tool_test.py # requires firecrawl-py extra
TEST_ARGS+=	--ignore=tools/rag/rag_tool_test.py # requires optional RAG extras
TEST_ARGS+=	--ignore=tools/rag/test_rag_tool_add_data_type.py # requires optional RAG extras
TEST_ARGS+=	--ignore=tools/rag/test_rag_tool_path_validation.py # requires optional RAG extras
TEST_ARGS+=	--ignore=tools/serper_dev_tool_test.py # requires Serper API key
TEST_ARGS+=	--ignore=tools/selenium_scraping_tool_test.py # requires Selenium and a browser
TEST_ARGS+=	--ignore=tools/singlestore_search_tool_test.py # requires singlestore extra
TEST_ARGS+=	--ignore=tools/snowflake_search_tool_test.py # requires snowflake extra
TEST_ARGS+=	--ignore=tools/stagehand_tool_test.py # requires stagehand extra
TEST_ARGS+=	--ignore=tools/test_mongodb_vector_search_tool.py # requires pymongo extra
TEST_ARGS+=	--ignore=tools/test_mysql_search_tool.py # requires pymysql extra
TEST_ARGS+=	--ignore=tools/test_oxylabs_tools.py # requires oxylabs extra
TEST_ARGS+=	--ignore=tools/test_search_tools.py # requires external search APIs
TEST_ARGS+=	--ignore=utilities/test_safe_path.py # URL resolution behavior differs in this environment

# tests as of 1.15.34: 1045 passed, 9 skipped, 20 warnings

.include <bsd.port.mk>
