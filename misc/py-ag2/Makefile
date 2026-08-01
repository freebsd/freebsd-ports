PORTNAME=	ag2
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
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
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anthropic>0:misc/py-anthropic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dirty-equals>=0.11:devel/py-dirty-equals@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=1.5.5:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=1.4.0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>=2.4.0:devel/py-pytest-timeout@${PY_FLAVOR} \
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
# Ignore directories that import un-packaged optional providers (mcp, a2a, mcp_ui)
# and run the rest of the tree.  anthropic is added to TEST_DEPENDS because some
# tests construct an AnthropicConfig as a representative model config.
TEST_ARGS=	-p no:relaxed \
		-p no:cov \
		--ignore=test/mcp \
		--ignore=test/a2a \
		--ignore=test/mcp_ui \
		test

pre-test:
	@${MKDIR} ${WRKDIR}/.bin
	@${LN} -sf ${PYTHON_CMD} ${WRKDIR}/.bin/python

# tests as of 1.0.1: 2384 passed, 355 skipped, 1 xfailed, 3 warnings in 23.48s

.include <bsd.port.mk>
