PORTNAME=	langchain-huggingface
DISTVERSION=	1.2.3
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LangChain: Integration package connecting Hugging Face and LangChain
WWW=		https://docs.langchain.com/oss/python/integrations/providers/huggingface \
		https://github.com/langchain-ai/langchain

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}huggingface-hub>=0.33.4:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langchain-core>=1.6.6:misc/py-langchain-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tokenizers>=0.19.1:textproc/py-tokenizers@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=1.3.0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-socket>=0.7.0:devel/py-pytest-socket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-watcher>=0.3.4:devel/py-pytest-watcher@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transformers>=5.0.0:misc/py-transformers@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests/unit_tests
# test_from_model_id_uses_torch_accelerator_device_count fails with accelerate
# because the accelerated model cannot be moved to a specific device in the
# test environment.
TEST_ARGS=	--deselect=test_huggingface_pipeline.py::test_from_model_id_uses_torch_accelerator_device_count

# tests as of 1.2.3: 43 passed, 1 deselected, 19 warnings

.include <bsd.port.mk>
