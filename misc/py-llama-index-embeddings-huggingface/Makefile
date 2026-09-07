PORTNAME=	llama-index-embeddings-huggingface
DISTVERSION=	0.8.0
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LlamaIndex embeddings HuggingFace integration
WWW=		https://github.com/run-llama/llama_index # maybe? No URL is listed on PYPI for this project

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}huggingface-hub>=0.19.0:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}llama-index-core>=0.14.24:misc/py-llama-index-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentence-transformers>=2.6.1:misc/py-sentence-transformers@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-extract:
	@${REINPLACE_CMD} -e 's/^license = "\([^"]*\)"/license = {text = "\1"}/' -e '/^license-files/d' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
