PORTNAME=	langgraph-sdk
DISTVERSION=	0.2.9
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LangGraph: SDK for interacting with LangGraph API
WWW=		https://github.com/langchain-ai/langgraph/tree/main/libs/sdk-py

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httpx>=0.25.2:www/py-httpx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}orjson>=3.10.1:devel/py-orjson@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# tests as of 0.2.9: 6 failed, 8 passed, 3 warnings in 0.64s (the file api/openapi.json is missing)

.include <bsd.port.mk>
