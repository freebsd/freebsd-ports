PORTNAME=	torchao
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.0
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/pytorch/ao/commit/
PATCHFILES=	cf7d0b178f989bf43fff27a4246cf2cab9175ac9.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTorch: Package for applying ao techniques to GPU models
WWW=		https://docs.pytorch.org/ao/stable/index.html \
		https://github.com/pytorch/ao

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fire>0:devel/py-fire@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}safetensors>0:misc/py-safetensors@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	pytorch
GH_PROJECT=	ao
GH_TUPLE=	NVIDIA:cutlass:e51efbf:cutlass/third_party/cutlass

TEST_WRKSRC=	${WRKSRC}/test
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
# module_swap_quantization, quant_logger and test_parq require devel/py-transformers,
# which pulls in an excessive dependency tree not otherwise needed by torchao
# prototype/pat spawns multiprocess distributed workers that call an internal
# API (torch._C._set_print_stack_traces_on_fatal_signal) not present in this
# platform's misc/py-pytorch build
# TestOptim uses torch.compile()-generated OpenMP kernels (torchao/optim/adam.py)
# which deadlock on this platform (worker threads stuck in libomp's
# __kmp_invoke_microtask while the main thread waits in the compiled kernel)
# test_bf16_stochastic_round_dtensor uses the gloo distributed backend, which
# is not supported by this platform's misc/py-pytorch build (fails with
# "makeDeviceForInterface(): unsupported gloo device")
# On amd64 a number of tests crash in OpenBLAS/oneDNN-less torch (segfault/bus
# error) or fail because MKLDNN ops are unavailable; skip them on x86.
TEST_ARGS=	--disable-plugin-autoload \
		--ignore=prototype/module_swap_quantization \
		--ignore=prototype/quant_logger \
		--ignore=prototype/test_parq.py \
		--ignore=prototype/pat

_TEST_SKIP_EXPR=	not TestOptim and not test_bf16_stochastic_round_dtensor

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
# The bundled torch on FreeBSD/amd64 lacks oneDNN/MKLDNN, so x86 inductor
# quantization pattern-match tests fail (missing torch.ops.mkldnn ops).
# Several other amd64 tests also crash in OpenBLAS (groupwise quant, conv2d
# pruning) or in torch.compile-generated kernels (mobilenet/resnet QAT).
TEST_ARGS+=	--ignore=quantization/pt2e/test_x86inductor_fusion.py \
		--ignore=quantization/pt2e/test_x86inductor_quantizer.py
_TEST_SKIP_EXPR+=	and not test_dynamic_quant_gpu_unified_api_eager_mode_impl \
			and not test_weight_only_groupwise_quant \
			and not test_prepare_conv2d \
			and not test_prune_conv2d_pool_conv2d \
			and not test_step_conv2d \
			and not test_qat_mobilenet_v2 \
			and not test_qat_resnet18 \
			and not test_quantize_api_prepare \
			and not (TestPatternMatcher or TestDynamicPatternMatcher) \
			and not (test_bf16_stochastic_round_dtensor and device_cpu)
.endif

TEST_ARGS+=	-k "${_TEST_SKIP_EXPR}"

.if ${ARCH} == "aarch64"
MAKE_ENV=	LD_STATIC_TLS_EXTRA=4096 # see pkg-message in misc/py-pytorch
.endif

# tests as of 0.18.0: 959 passed, 6709 skipped, 46 deselected in 644.97s (on amd64)
# tests as of 0.18.0: 1034 passed, 6718 skipped, 38 deselected in 647.35s (on aarch64)

.include <bsd.port.post.mk>
