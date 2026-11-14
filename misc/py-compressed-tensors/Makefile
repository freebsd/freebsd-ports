PORTNAME=	compressed-tensors
DISTVERSION=	0.20.1
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for storing and loading compressed PyTorch models
WWW=		https://docs.vllm.ai/projects/compressed-tensors/en/latest/ \
		https://github.com/vllm-project/compressed-tensors

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8.0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}loguru>0:devel/py-loguru@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.10.0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transformers>=4.45.0:misc/py-transformers@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# broken tests: need CUDA, network access (HuggingFace models) or newer transformers
PYTEST_BROKEN_TESTS=	test_compress_decompress_embedding \
			test_compress_decompress_module \
			test_disk_load_context \
			test_load_no_missing_keys \
			test_mmap_cap_reduces_shared_memory \
			test_apply_attention \
			test_apply_kv_cache \
			test_apply_model \
			test_apply_quantization_config \
			test_apply_tinyllama_dynamic_activations \
			test_expand_targets_with_llama_stories \
			test_from_pretrained \
			test_map_to_checkpoint_names \
			test_multi_apply_quantization_config \
			test_serialization \
			test_serialize_config_tinyllama \
			test_target_prioritization

TEST_ARGS=	--disable-plugin-autoload
TEST_ENV=	${MAKE_ENV} HF_HUB_OFFLINE=1 PYTEST_DISABLE_PLUGIN_AUTOLOAD=1 PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}/tests

# tests require accelerators for some cases, see https://github.com/vllm-project/compressed-tensors/issues/939
# tests as of 0.20.1: 1040 passed, 424 skipped, 129 deselected, 8 warnings in 52.88s

.include <bsd.port.mk>
