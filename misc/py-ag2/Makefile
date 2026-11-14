PORTNAME=	ag2
DISTVERSIONPREFIX=	v.
DISTVERSION=	1.3.1
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
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.6.1:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.2:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anthropic>=1.15.0:misc/py-anthropic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dirty-equals>=0.11:devel/py-dirty-equals@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=1.5:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx2>=2.10.0:www/py-httpx2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openai>=3.45.0:misc/py-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=1.4.0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=2.4.0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>0:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}respx>=0.23.0:www/py-respx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=14.0:devel/py-websockets@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	ag2ai
GH_PROJECT=	ag2

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PATH=${WRKDIR}/.bin:${PATH} \
		PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}:${WRKSRC}
# The upstream test suite requires many optional providers and network access.
# Ignore directories that import un-packaged optional providers (mcp, a2a, mcp_ui),
# tests needing google-genai features that the packaged SDK lacks
# (gemini/test_continuation.py), and torch tests (mi4afa; importing torch fails
# with a TLS error when pytest loads it late). Run the rest of the tree.  anthropic is added to TEST_DEPENDS because some
# tests construct an AnthropicConfig as a representative model config.
TEST_ARGS=	--disable-plugin-autoload \
		-p pytest_asyncio.plugin \
		-p pytest_timeout \
		--ignore=test/mcp \
		--ignore=test/a2a \
		--ignore=test/config/gemini/test_continuation.py \
		--ignore=test/extensions/mi4afa \
		--ignore=test/mcp_ui \
		test

pre-test:
	@${MKDIR} ${WRKDIR}/.bin
	@${LN} -sf ${PYTHON_CMD} ${WRKDIR}/.bin/python

# tests as of 1.3.1: 5064 passed, 468 skipped, 2 xfailed, 7 warnings in 86.09s

.include <bsd.port.mk>
