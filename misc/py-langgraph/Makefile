PORTNAME=	langgraph
DISTVERSION=	1.0.5
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LangGraph: Building stateful, multi-actor applications with LLMs
WWW=		https://docs.langchain.com/oss/python/langgraph/overview \
		https://github.com/langchain-ai/langgraph

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}langchain-core>=0.1:misc/py-langchain-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langgraph-checkpoint>=2.1.0<4.0.0:misc/py-langgraph-checkpoint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langgraph-prebuilt>=1.0.2<1.1.0:misc/py-langgraph-prebuilt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langgraph-sdk>=0.3.0<0.4.0:misc/py-langgraph-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.7.4:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xxhash>=3.5.0:devel/py-xxhash@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>
