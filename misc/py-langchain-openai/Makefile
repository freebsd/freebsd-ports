PORTNAME=	langchain-openai
DISTVERSION=	0.3.33
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

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>0:devel/py-pdm-backend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}langchain-core>=0.3.76:misc/py-langchain-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openai>=1.104.2:misc/py-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tiktoken>=0.7:textproc/py-tiktoken@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# tests as of 0.3.28: 233 failed, 262 passed, 11 skipped, 2 xfailed, 5 xpassed, 52 warnings, 131 errors, 8 rerun in 217.53s (0:03:37)

.include <bsd.port.mk>
