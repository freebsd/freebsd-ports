PORTNAME=	timm
DISTVERSION=	1.0.31
CATEGORIES=	misc python # machine-learning
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTorch Image Models
WWW=		https://huggingface.co/docs/timm/index \
		https://github.com/huggingface/pytorch-image-models

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pdm-backend>0:devel/py-pdm-backend@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}huggingface-hub>0:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}safetensors>0:misc/py-safetensors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchvision>0:misc/py-torchvision@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}expecttest>0:devel/py-expecttest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-forked>0:devel/py-pytest-forked@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# importing torch fails with 'No space available for static Thread Local Storage' unless libc10 is preloaded
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		LD_PRELOAD=${PYTHON_SITELIBDIR}/torch/lib/libc10.so OMP_NUM_THREADS=1
# the model sweep tests (test_models.py, test_sweep*.py) take many hours and are skipped;
# sdist lacks train.py/validate.py scripts needed by the tests that are deselected;
# gloo distributed tests fail here
TEST_ARGS=	--disable-plugin-autoload -p pytest_forked -p timeout -p xdist -n 8 --timeout=600 \
		--ignore=tests/test_models.py \
		--ignore=tests/test_sweep.py \
		--ignore=tests/test_sweep_fuzz.py \
		--ignore=tests/test_train_resume.py \
		-k 'not test_class_weights_script and not test_distributed_metrics_exclude_padding and not test_multilabel_train_and_validate_cli and not test_multilabel_train_cli_multihot and not test_train_cli_loss_flags and not test_train_cli_rejects_metric_the_evaluator_does_not_produce and not test_train_pretrained_cfg_overlay'

# tests as of 1.0.31: 3364 passed, 560 skipped, 30 warnings in 43.18s

.include <bsd.port.mk>
