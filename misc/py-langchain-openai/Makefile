PORTNAME=	langchain-openai
DISTVERSION=	1.6.2
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LangChain: Integration package connecting OpenAI and LangChain
WWW=		https://python.langchain.com/docs/introduction/ \
		https://github.com/langchain-ai/langchain

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=2024.6.2:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langchain-core>=1.6.2:misc/py-langchain-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openai>=2.45.0:misc/py-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tiktoken>=0.7.0:textproc/py-tiktoken@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}freezegun>=1.2.2:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langchain>=1.4.0:misc/py-langchain@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langchain-tests>=1.1.9:misc/py-langchain-tests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.26.4:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=1.3.0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=4.1.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=3.10.0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-retry>=1.7.0:devel/py-pytest-retry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-socket>=0.6.0:devel/py-pytest-socket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-watcher>=0.3.4:devel/py-pytest-watcher@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.6.1:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}syrupy>=5.0.0:devel/py-syrupy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vcrpy>=8.0.0:devel/py-vcrpy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# Integration tests need an OpenAI API key and network access.
TEST_ARGS=	--ignore=${WRKSRC}/tests/integration_tests

# tests as of 1.6.0: 592 passed, 1 skipped, 5 xpassed, 37 warnings in 19.88s

.include <bsd.port.mk>
