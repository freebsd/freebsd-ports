PORTNAME=	llama-index-llms-openai-like
PORTVERSION=	0.8.0
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LlamaIndex LLMs OpenAI-like integration
WWW=		https://pypi.org/project/llama-index-llms-openai-like/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}llama-index-core>=0.14.24:misc/py-llama-index-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}llama-index-llms-openai>=0.8.1:misc/py-llama-index-llms-openai@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-extract:
	@${REINPLACE_CMD} -e 's/^license = "\([^"]*\)"/license = {text = "\1"}/' -e '/^license-files/d' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
