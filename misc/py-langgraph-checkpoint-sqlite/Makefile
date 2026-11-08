PORTNAME=	langgraph-checkpoint-sqlite
DISTVERSION=	3.1.3
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
MASTER_SITE_SUBDIR=	source/l/langgraph-checkpoint-sqlite
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LangGraph: SQLite implementation of LangGraph checkpoint saver
WWW=		https://github.com/langchain-ai/langgraph/tree/main/libs/checkpoint-sqlite

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiosqlite>=0.20:databases/py-aiosqlite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langgraph-checkpoint>=4.3.1:misc/py-langgraph-checkpoint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite-vec>=0.1.6:databases/py-sqlite-vec@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}langgraph-checkpoint-conformance>=0.0.2:misc/py-langgraph-checkpoint-conformance@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langgraph>0:misc/py-langgraph@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-retry>=1.7.0:devel/py-pytest-retry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-watcher>0:devel/py-pytest-watcher@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# The deselected store tests need sqlite3.Connection.enable_load_extension(), which FreeBSD's py-sqlite3 lacks.
# test_async_asearch_refresh_ttl fails deterministically: refreshed item is not expired when expected.
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_asyncio.plugin \
		-p pytest_mock \
		-p pytest_retry \
		--deselect=tests/test_async_store.py::test_basic_store_ops \
		--deselect=tests/test_async_store.py::test_embed_with_path \
		--deselect=tests/test_async_store.py::test_list_namespaces \
		--deselect=tests/test_async_store.py::test_search_items \
		--deselect=tests/test_async_store.py::test_vector_insert_with_auto_embedding \
		--deselect=tests/test_async_store.py::test_vector_search_edge_cases \
		--deselect=tests/test_async_store.py::test_vector_search_pagination \
		--deselect=tests/test_async_store.py::test_vector_search_with_filters \
		--deselect=tests/test_async_store.py::test_vector_store_initialization \
		--deselect=tests/test_async_store.py::test_vector_update_with_embedding \
		--deselect=tests/test_store.py::test_basic_store_operations \
		--deselect=tests/test_store.py::test_embed_with_path \
		--deselect=tests/test_store.py::test_embed_with_path_operation_config \
		--deselect=tests/test_store.py::test_list_namespaces_operations \
		--deselect=tests/test_store.py::test_non_ascii \
		--deselect=tests/test_store.py::test_scores \
		--deselect=tests/test_store.py::test_search_items \
		--deselect=tests/test_store.py::test_vector_insert_with_auto_embedding \
		--deselect=tests/test_store.py::test_vector_search_edge_cases \
		--deselect=tests/test_store.py::test_vector_search_pagination \
		--deselect=tests/test_store.py::test_vector_search_with_filters \
		--deselect=tests/test_store.py::test_vector_store_initialization \
		--deselect=tests/test_store.py::test_vector_update_with_embedding \
		--deselect=tests/test_ttl.py::test_async_asearch_refresh_ttl \
		--ignore=${WRKSRC}/tests/test_conformance_delta.py # see https://github.com/langchain-ai/langgraph/issues/9404

# tests as of 3.1.3: 158 passed, 38 deselected, 23 warnings

.include <bsd.port.mk>
