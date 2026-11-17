PORTNAME=	docling-ibm-models
DISTVERSION=	4.0.4
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/g}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	AI models used by the Docling PDF conversion package
WWW=		https://github.com/docling-project/docling-ibm-models

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# there are also 2 opencv optional dependencies
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}huggingface-hub>=0.23:misc/py-huggingface-hub@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.24.4:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>=2.2.2:misc/py-pytorch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}safetensors>=0.4.3:misc/py-safetensors@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}torchvision>0:misc/py-torchvision@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transformers>=4.42.0:misc/py-transformers@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-dependency>=0.6:devel/py-pytest-dependency@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

# importing torch fails with 'No space available for static Thread Local Storage' unless libc10 is preloaded
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} \
		LD_PRELOAD=${PYTHON_SITELIBDIR}/torch/lib/libc10.so
# sdist lacks tests/test_data samples; some tests download models from Hugging Face
TEST_ARGS=	--disable-plugin-autoload -p dependency \
		--deselect tests/test_tableformer_v2.py::test_tableformer_v2_batch_inference \
		--deselect tests/test_tableformer_v2.py::test_tableformer_v2_forward_pass \
		--deselect tests/test_tableformer_v2.py::test_tableformer_v2_image_encoding \
		--deselect tests/test_tableformer_v2.py::test_tableformer_v2_numpy_input \
		--deselect tests/test_tableformer_v2.py::test_tableformer_v2_predict \
		--deselect tests/test_tf_predictor.py::test_tf_predictor

# tests as of 4.0.4: 25 passed, 6 deselected, 1 warning in 3.06s

.include <bsd.port.mk>
