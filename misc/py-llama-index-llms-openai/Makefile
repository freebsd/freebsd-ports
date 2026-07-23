PORTNAME=	llama-index-llms-openai
PORTVERSION=	0.7.10
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LlamaIndex LLMs OpenAI integration
WWW=		https://pypi.org/project/llama-index-llms-openai/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}llama-index-core>=0.14.5:misc/py-llama-index-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openai>=1.108.1:misc/py-openai@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-extract:
	@${REINPLACE_CMD} -e 's/^license = "\([^"]*\)"/license = {text = "\1"}/' -e '/^license-files/d' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
