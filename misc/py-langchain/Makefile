PORTNAME=	langchain
DISTVERSION=	0.3.26
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LangChain: Building applications with LLMs through composability
WWW=		https://python.langchain.com/docs/introduction/ \
		https://github.com/langchain-ai/langchain

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>0:devel/py-pdm-backend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=1.4:databases/py-sqlalchemy20@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}async_timeout>=4.0.0:devel/py-async_timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langchain-core>=0.3.66:misc/py-langchain-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langchain-text-splitters>=0.3.8:misc/py-langchain-text-splitters@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langsmith>=0.1.17:misc/py-langsmith@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.7.4:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.3:devel/py-pyyaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>
