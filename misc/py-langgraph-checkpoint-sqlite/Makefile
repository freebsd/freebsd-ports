PORTNAME=	langgraph-checkpoint-sqlite
DISTVERSION=	3.1.2
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
		${PYTHON_PKGNAMEPREFIX}langgraph-checkpoint>=4.3.0:misc/py-langgraph-checkpoint@${PY_FLAVOR} \
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

TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_asyncio.plugin \
		-p pytest_mock \
		-p pytest_retry \
		--ignore=${WRKSRC}/tests/test_conformance_delta.py # see https://github.com/langchain-ai/langgraph/issues/9404

# tests as of 3.1.2: 192 passed, 25 warnings in 43.84s

.include <bsd.port.mk>
