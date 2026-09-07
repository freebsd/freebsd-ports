PORTNAME=	langgraph-checkpoint-sqlite
DISTVERSION=	3.1.1
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
MASTER_SITE_SUBDIR=	source/l/langgraph-checkpoint-sqlite
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SQLite implementation of LangGraph checkpoint saver
WWW=		https://github.com/langchain-ai/langgraph/tree/main/libs/checkpoint-sqlite

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiosqlite>=0.20:databases/py-aiosqlite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langgraph-checkpoint>=4.1.0:misc/py-langgraph-checkpoint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite-vec>=0.1.6:databases/py-sqlite-vec@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-retry>=1.7.0:devel/py-pytest-retry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-watcher>0:devel/py-pytest-watcher@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# FreeBSD's sqlite3 module is built without loadable extension support, so
# vector-store tests that require sqlite-vec extensions cannot run.
TEST_ARGS=	--ignore=${WRKSRC}/tests/test_async_store.py \
		--ignore=${WRKSRC}/tests/test_store.py \
		--ignore=${WRKSRC}/tests/test_ttl.py

# tests as of 3.1.1: 27 passed, 1 skipped, 1 warning in 60.77s

.include <bsd.port.mk>
