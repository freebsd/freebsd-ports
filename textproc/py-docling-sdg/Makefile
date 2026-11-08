PORTNAME=	docling-sdg
DISTVERSION=	0.4.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Docling for Synthetic Data Generation (SDG)
WWW=		https://github.com/docling-project/docling-sdg

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		incompatible with the docling-core in the tree, requires Python < 3.13, see https://github.com/docling-project/docling-sdg/issues/47

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}docling>=2.26.0:textproc/py-docling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docling-core>=2.23.0:textproc/py-docling-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}llama-index-core>=0.12.25:misc/py-llama-index-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}llama-index-embeddings-huggingface>=0.5.5:misc/py-llama-index-embeddings-huggingface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}llama-index-llms-ibm>=0.3.3:misc/py-llama-index-llms-ibm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}llama-index-llms-openai-like>=0.3.4:misc/py-llama-index-llms-openai-like@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semchunk>=2.2.2:textproc/py-semchunk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transformers>=4.42.4:misc/py-transformers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typer>=0.12.5:devel/py-typer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.12.2:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
