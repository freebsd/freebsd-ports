PORTNAME=	timm
DISTVERSION=	1.0.28
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
		${PYTHON_PKGNAMEPREFIX}torchvision>0:misc/py-torchvision@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}safetensors>0:misc/py-safetensors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>0:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}expecttest>0:devel/py-expecttest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-forked>0:devel/py-pytest-forked@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

TEST_ARGS=	-p no:black -p no:mypy -p no:cov -p no:benchmark \
		tests/test_checkpoint_loading.py tests/test_dataset_info.py \
		tests/test_layers.py tests/test_layers_drop.py \
		tests/test_layers_pool.py tests/test_optim.py \
		tests/test_scheduler.py tests/test_task.py tests/test_utils.py
PYTEST_IGNORED_TESTS=	test_kron

# tests as of 1.0.28: 356 passed in 30.79s
# test_models.py is excluded because it downloads large pretrained model
# weights and consumes gigabytes of disk space.
# test_kron is ignored because torch.compile/inductor fails on FreeBSD.

.include <bsd.port.mk>
