PORTNAME=	torchvision
DISTVERSIONPREFIX=	v
DISTVERSION=	0.29.0
CATEGORIES=	misc # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	PyTorch: Datasets, transforms and models specific to computer vision
WWW=		https://pytorch.org/vision/stable/index.html \
		https://github.com/pytorch/vision

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpng16.so:graphics/png \
		libwebp.so:graphics/webp
PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytorch>0:misc/py-pytorch@${PY_FLAVOR}
PY_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pillow>=5.3.0:graphics/py-pillow@${PY_FLAVOR} # image backend
BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}fsspec>0:filesystems/py-fsspec@${PY_FLAVOR} \
		pybind11>0:devel/pybind11 \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
BUILD_DEPENDS+=	ninja:devel/ninja # build uses the C compiler for C++ files w/out ninja, and fails
RUN_DEPENDS=	${PY_DEPENDS}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}onnxruntime>0:misc/py-onnxruntime@${PY_FLAVOR}

USES=		compiler:c++17-lang jpeg python
USE_PYTHON=	pep517 autoplist pytest # tests run in a very high memory ; in 0.17.1 tests fail to run, see https://github.com/pytorch/vision/issues/8278

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_WRKSRC=	${WRKSRC}
TEST_ARGS=	--disable-plugin-autoload \
		--ignore=test/test_transforms_tensor.py \
		--ignore=test/test_transforms_v2.py \
		--ignore=test/test_functional_tensor.py \
		--ignore=test/test_transforms.py \
		--ignore=test/test_ops.py \
		--ignore=test/test_backbone_utils.py \
		--ignore=test/test_utils.py \
		--ignore=test/test_tv_tensors.py \
		--ignore=test/test_datasets_download.py \
		--ignore=test/test_onnx.py \
		--ignore=test/test_datasets_utils.py \
		--ignore=test/test_image.py \
		--ignore=test/test_datasets.py
PYTEST_BROKEN_TESTS=	test_download_url_dispatch_download_from_google_drive \
			test_detection_model_trainable_backbone_layers

USE_GITHUB=	yes
GH_ACCOUNT=	pytorch
GH_PROJECT=	vision

MAKE_ENV=	TORCHVISION_INCLUDE=${LOCALBASE}/include \
		OPENBLAS_CORETYPE=SKYLAKEX # workaround for OpenBLAS Zen5/Zen6 crash in py-pytorch

.include <bsd.port.pre.mk>

.if ${ARCH} == "aarch64"
MAKE_ENV=	LD_STATIC_TLS_EXTRA=4096 # see pkg-message in misc/py-pytorch
.endif

pre-test:
	@${CP} ${STAGEDIR}${PYTHON_SITELIBDIR}/torchvision/_C_stable.so ${WRKSRC}/torchvision/
	@${CP} ${STAGEDIR}${PYTHON_SITELIBDIR}/torchvision/image_stable.so ${WRKSRC}/torchvision/

post-install: # strip binaries
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/torchvision/_C_stable.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/torchvision/image_stable.so

# tests as of 0.29.0: 522 passed, 501 skipped, 14 deselected, 255 warnings in 275.53s

.include <bsd.port.post.mk>
