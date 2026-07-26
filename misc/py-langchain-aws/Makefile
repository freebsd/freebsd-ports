PORTNAME=	langchain-aws
DISTVERSION=	1.6.3
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LangChain: Integration package connecting AWS and LangChain
WWW=		https://docs.langchain.com/oss/python/integrations/providers/aws \
		https://github.com/langchain-ai/langchain-aws

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto3>=1.43.32:www/py-boto3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langchain-core>=1.4.7:misc/py-langchain-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.0.0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.10.6:devel/py-pydantic2@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}anthropic>0:misc/py-anthropic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langchain>=1.0.0:misc/py-langchain@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langchain-anthropic>0:misc/py-langchain-anthropic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langchain-tests>=1.1.3:misc/py-langchain-tests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langgraph-checkpoint>=4.1.0:misc/py-langgraph-checkpoint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0.20:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-watcher>=0.4.3:devel/py-pytest-watcher@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.8.0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}syrupy>=4.9.1:devel/py-syrupy@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/tests/unit_tests

# tests as of 1.6.3: 890 passed, 3 skipped, 1 xfailed, 3 warnings in 11.34s

.include <bsd.port.mk>
