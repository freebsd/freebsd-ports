PORTNAME=	langchain-groq
DISTVERSION=	1.2.0
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LangChain: Integration package connecting Groq and LangChain
WWW=		https://docs.langchain.com/oss/python/integrations/providers/groq \
		https://github.com/langchain-ai/langchain

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}groq>=0.30.0:misc/py-groq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langchain-core>=1.4.0:misc/py-langchain-core@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}langchain-tests>=1.1.9:misc/py-langchain-tests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=1.3.0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=3.10.0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-retry>=1.7.0:devel/py-pytest-retry@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-socket>=0.7.0:devel/py-pytest-socket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-watcher>=0.3.4:devel/py-pytest-watcher@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.6.1:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests/unit_tests

PYTEST_IGNORED_TESTS=	test_serdes

# tests as of 1.2.0: 73 passed, 1 skipped, 1 deselected in 11.95s

.include <bsd.port.mk>
