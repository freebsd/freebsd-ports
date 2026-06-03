PORTNAME=	vllm
DISTVERSION=	0.20.2
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI \
		https://github.com/uxlfoundation/oneDNN/archive/refs/tags/:onednn_src
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		v3.10${EXTRACT_SUFX}:onednn_src

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	High-throughput and memory-efficient LLM inference engine
WWW=		https://vllm.ai/ \
		https://github.com/vllm-project/vllm

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/llvm19/bin/clang:devel/llvm19 \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.6:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ninja>=1.13:devel/py-ninja@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=24.2:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.11.0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=63.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8.0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libabsl_status.so:devel/abseil \
		libprotobuf.so:devel/protobuf
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.13.3:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}anthropic>=0.71.0:misc/py-anthropic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blake3>0:security/py-blake3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachetools>0:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cbor2>0:devel/py-cbor2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cloudpickle>0:devel/py-cloudpickle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}compressed-tensors>=0.15.0.1:misc/py-compressed-tensors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}depyf>=0.20.0:devel/py-depyf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}diskcache>=5.6.3:devel/py-diskcache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}einops>0:misc/py-einops@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>=0.115.0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>=3.16.1:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gguf>=0.17.0:misc/py-gguf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ijson>0:devel/py-ijson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.6:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lark>=1.2.2:devel/py-lark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}llguidance>=1.3.0:textproc/py-llguidance@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lm-format-enforcer>=0.11.3:misc/py-lm-format-enforcer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mcp>0:misc/py-mcp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mistral-common>=1.11.0:misc/py-mistral-common@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}model-hosting-container-standards>=0.1.13:misc/py-model-hosting-container-standards@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgspec>0:devel/py-msgspec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ninja>=1.13:devel/py-ninja@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numba>=0.65.0:devel/py-numba@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.25:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openai>=2.0.0:misc/py-openai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openai-harmony>=0.0.3:misc/py-openai-harmony@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-api>=1.27.0:devel/py-opentelemetry-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-exporter-otlp>=1.27.0:devel/py-opentelemetry-exporter-otlp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-sdk>=1.27.0:devel/py-opentelemetry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opentelemetry-semantic-conventions-ai>=0.4.1:devel/py-opentelemetry-semantic-conventions-ai@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}opencv-python-headless>=4.13.0:graphics/py-opencv-python-headless@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}outlines-core>=0.2.14:textproc/py-outlines-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}partial-json-parser>0:textproc/py-partial-json-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.18.0:net-mgmt/py-prometheus-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-fastapi-instrumentator>=7.0.0:www/py-prometheus-fastapi-instrumentator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=5.29.6:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.9.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py-cpuinfo>0:sysutils/py-py-cpuinfo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pybase64>0:devel/py-pybase64@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic2>=2.12.0:devel/py-pydantic2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-json-logger>0:devel/py-python-json-logger@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.11.0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>=25.0.0:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>0:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.26.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentencepiece>0:textproc/py-sentencepiece@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>0:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=63.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.16.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tiktoken>=0.6.0:textproc/py-tiktoken@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tokenizers>=0.21.1:textproc/py-tokenizers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchaudio>=0:audio/py-torchaudio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchvision>=0:misc/py-torchvision@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>=4.0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transformers>=4.56.0:misc/py-transformers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.10:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvloop>=0.20.0:devel/py-uvloop@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchfiles>0:devel/py-watchfiles@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xgrammar>=0.1.32:misc/py-xgrammar@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}datasets>=4.8.2:misc/py-datasets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}evaluate>=0.4.6:misc/py-evaluate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multiprocess>=0.70.19:devel/py-multiprocess@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=1.3.0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tblib>=3.2.2:devel/py-tblib@${PY_FLAVOR}

USES=		cmake:indirect python
USE_PYTHON=	pep517 autoplist pytest

# Build the CPU extension using clang (same ABI as PyTorch on FreeBSD).
# VLLM_TARGET_DEVICE=cpu builds the vllm._C CPU extension.
# oneDNN (fetched as a distfile) provides optimised GEMM kernels.
MAKE_ENV+=	VLLM_TARGET_DEVICE=cpu \
		CMAKE_ARGS="-DCMAKE_C_COMPILER=${LOCALBASE}/llvm19/bin/clang -DCMAKE_CXX_COMPILER=${LOCALBASE}/llvm19/bin/clang++ -DCMAKE_INSTALL_RPATH_USE_LINK_PATH=TRUE" \
		FETCHCONTENT_SOURCE_DIR_ONEDNN=${WRKDIR}/oneDNN-3.10

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}:${WRKSRC}/tests/vllm_test_utils:${WRKSRC}/tests/plugins/vllm_add_dummy_stat_logger
TEST_WRKDIR=	${WRKSRC}/tests

# tests don't run because:
# * imagehash, lm_eval, mteb, pqdm, ray, runai_model_streamer, schemathesis which are not in FreeBSD ports yet
# * vllm._C and vllm.v1.worker.gpu.mm.encoder_cudagraph require CUDA/GPU hardware.

.include <bsd.port.mk>
