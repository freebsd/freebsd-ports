PORTNAME=	langchain
DISTVERSION=	1.3.10
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LangChain: Building applications with LLMs through composability
WWW=		https://python.langchain.com/docs/introduction/ \
		https://github.com/langchain-ai/langchain

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}langchain-core>=1.4.7:misc/py-langchain-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langgraph>=1.2.5:misc/py-langgraph@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.7.4:devel/py-pydantic2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# tests as of 1.3.9: 59 failed, 962 passed, 39 skipped, 9 warnings in 16.54s

.include <bsd.port.mk>
