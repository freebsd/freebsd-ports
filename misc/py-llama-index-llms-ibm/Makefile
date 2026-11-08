PORTNAME=	llama-index-llms-ibm
DISTVERSION=	0.8.0
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	llama_index_llms_ibm-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LlamaIndex LLMs IBM watsonx.ai integration
WWW=		https://pypi.org/project/llama-index-llms-ibm/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ibm-watsonx-ai>=1.5.0:misc/py-ibm-watsonx-ai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}llama-index-core>=0.14.24:misc/py-llama-index-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyarrow>0:databases/py-pyarrow@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-extract:
	@${REINPLACE_CMD} -e 's/^license = "\([^"]*\)"/license = {text = "\1"}/' -e '/^license-files/d' ${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
