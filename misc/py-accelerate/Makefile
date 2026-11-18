PORTNAME=	accelerate
DISTVERSION=	1.16.0
CATEGORIES=	misc # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTorch: simple way to launch, train, use PyTorch models on any device
WWW=		https://huggingface.co/docs/accelerate/index \
		https://github.com/huggingface/accelerate

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}huggingface-hub>=0.21.0:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.17:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.0.0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}safetensors>=0.4.3:misc/py-safetensors@${PY_FLAVOR} # optional deepspeed dependency is missing
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bitsandbytes>=0:misc/py-bitsandbytes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}datasets>=0:misc/py-datasets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}diffusers>=0:misc/py-diffusers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}evaluate>=0:misc/py-evaluate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parameterized>0:devel/py-parameterized@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}peft>=0:misc/py-peft@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-order>=0:devel/py-pytest-order@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-subtests>=0:devel/py-pytest-subtests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}timm>=0:misc/py-timm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchdata>=0.8.0:misc/py-torchdata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchvision>0:misc/py-torchvision@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tqdm>0:misc/py-tqdm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transformers>=0:misc/py-transformers@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes
TEST_ENV=	${MAKE_ENV} MLFLOW_ALLOW_FILE_STORE=true MPLBACKEND=Agg
TEST_ARGS=	--disable-plugin-autoload -p pytest_order \
		--deselect tests/test_utils.py::UtilsTester::test_patch_environment_key_exists \
		--deselect tests/test_utils.py::ExecuteSubprocessAsyncTester::test_timeout_stops_torchrun_workers \
		--ignore tests/test_memory_utils.py \
		-k 'not stateful_dataloader and not StatefulDataLoader and not MLflowTrackingTest' \
		--ignore src/accelerate/test_utils/scripts \
		--ignore tests/test_cli.py \
		--ignore tests/test_cpu.py \
		--ignore tests/test_examples.py \
		--ignore tests/test_grad_sync.py \
		--ignore tests/test_scheduler.py \
		--ignore src/accelerate/test_utils/scripts/external_deps

# tests as of 1.16.0: 251 passed, 155 skipped, 39 deselected, 198 warnings, 4 subtests passed in 748.40s

.include <bsd.port.mk>
