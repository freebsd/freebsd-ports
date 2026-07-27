PORTNAME=	crewai-tools
DISTVERSION=	1.15.7
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
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.13.4:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}crewai>=1.15.7:misc/py-crewai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymupdf>=1.26.6:print/py-PyMuPDF@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-docx>=1.2.0:textproc/py-python-docx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytube>=15.0.0:multimedia/py-pytube@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.33.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tiktoken>=0.8.0:textproc/py-tiktoken@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}youtube-transcript-api>=1.2.2:www/py-youtube-transcript-api@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests
TEST_ARGS=	--ignore=adapters/mcp_adapter_test.py \
		--ignore=base_tool_test.py \
		--ignore=tools/brave_search_tool_test.py \
		--ignore=tools/couchbase_tool_test.py \
		--ignore=tools/files_compressor_tool_test.py \
		--ignore=tools/firecrawl_crawl_website_tool_test.py \
		--ignore=tools/firecrawl_scrape_website_tool_test.py \
		--ignore=tools/firecrawl_search_tool_test.py \
		--ignore=tools/rag/rag_tool_test.py \
		--ignore=tools/rag/test_rag_tool_add_data_type.py \
		--ignore=tools/rag/test_rag_tool_path_validation.py \
		--ignore=tools/serper_dev_tool_test.py \
		--ignore=tools/selenium_scraping_tool_test.py \
		--ignore=tools/singlestore_search_tool_test.py \
		--ignore=tools/snowflake_search_tool_test.py \
		--ignore=tools/stagehand_tool_test.py \
		--ignore=tools/test_mongodb_vector_search_tool.py \
		--ignore=tools/test_oxylabs_tools.py \
		--ignore=tools/test_search_tools.py \
		--ignore=utilities/test_safe_path.py

# tests as of 1.15.7: 348 passed, 1 skipped, 10 warnings in 22.38s

.include <bsd.port.mk>
